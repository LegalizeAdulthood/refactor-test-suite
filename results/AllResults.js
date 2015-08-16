// Print out test results as JSON
// execute this script with node.js

var _ = require('underscore');
var async = require('async');
var fs = require('fs');
var split = require('split');

function Percentage(passed, total)
{
    var pct = String(Math.ceil(100*100*passed/total)/100) + "%";
    return (pct + "      ".substr(0, 6 - pct.length)).trim();
}

function StartTest()
{
    return {
        refactoring: "",
        passes: [],
        failures: []
    };
}

function testResult(list, matches)
{
    id = matches[1];
    comment = matches[2].trim();
    if (comment.length > 0)
    {
        list.push([ id, comment ]);
    }
    else
    {
        list.push(id);
    }
}

function ProcessLine(context, line)
{
    var matches,
        comment,
        id,
        ctx = context.testResult;

    if (line.length == 0)
    {
        if (ctx.passes.length + ctx.failures.length > 0)
        {
            if (ctx.failures.length == 0)
            {
                context.passedAllTests.push(ctx.refactoring);
            }
            context.tests.push({
                name: ctx.refactoring,
                percent: Percentage(ctx.passes.length, ctx.passes.length + ctx.failures.length),
                passes: ctx.passes,
                failures: ctx.failures
            });
        }
        context.testResult = StartTest();
    }
    else if (matches = line.match(/^Version: *([^ ].*)$/i))
    {
        context.version = matches[1];
    }
    else if (matches = line.match(/^Home: *\[([^\]]*)\]/i))
    {
        context.name = matches[1];
    }
    else if (matches = line.match(/^([A-Z][A-Z0-9]*)[^0-9]*Pass(.*)$/))
    {
        testResult(ctx.passes, matches);
    }
    else if (matches = line.match(/^([A-Z][A-Z0-9]*)[^0-9]*Failure(.*)$/))
    {
        testResult(ctx.failures, matches);
    }
    else if (matches = line.match(/\#\# ([^([]*).*$/))
    {
        ctx.refactoring = matches[1].trim();
    }
}

function ProcessResultsFile(resultsFile, next)
{
    var context = {
        name: "",
        version: "",
        date: (new Date()).toString(),
        tests: [],
        passedAllTests: [],
        testResult: StartTest(),
        file: resultsFile
    };

    fs.createReadStream(resultsFile)
        .pipe(split())
        .on('data', function(line) { ProcessLine(context, line); })
        .on('end', function() {
            delete context.testResult;
            next(null, context);
        });
}

function Summarize(err, results)
{
    var summary = {},
        products = [];
    _.map(results, function(product) {
        products.push([ product.name, product.file ]);
        _.map(product.tests, function(test) {
            summary[test.name] = [];
        });
    });
    _.map(Object.keys(summary), function(testName) {
        _.map(results, function(product) {
            var percent = "n/a";
            _.map(product.tests, function(test) {
                if (test.name === testName) {
                    percent = test.percent;
                }
            });
            summary[testName].push(percent);
        });
    });
    console.log("# Summary Results");
    console.log("");
    var line = "Refactoring";
    _.map(products, function(product) {
        line += " | [" + product[0] + "](results/" + product[1] + ")";
        first = false;
    });
    console.log(line);
    var line = "-----";
    _.map(products, function(product) {
        line += " | -----";
    });
    console.log(line);
    _.map(Object.keys(summary).sort(), function(testName) {
        line = testName;
        _.map(summary[testName], function(pct) {
            line +=  " | " + pct;
        });
        console.log(line);
    });
}

function ProcessFiles(files, next)
{
    var results = [];
    async.eachSeries(files,
        function(file, nextFile) {
            ProcessResultsFile(file, function(err, fileResults) {
                results.push(fileResults);
                nextFile(null);
            });
        },
        function(err) {
            next(err, results);
        });
}

function ProcessResults(dir, next)
{
    fs.readdir(dir, function(err, files) {
        if (err) {
            next(err);
        } else {
            ProcessFiles(_.filter(files, function(file) {
                    return file.match(/^[A-Z].*Results\.md$/);
                }), next);
        }
    });
}

function main(argv) {
    ProcessResults(".", Summarize);
}

main(process.argv);
