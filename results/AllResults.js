// Print out test results as JSON

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
    else if (line.indexOf("## ") == 0)
    {
        ctx.refactoring = line.substr(2);
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
        testResult: StartTest()
    };

    fs.createReadStream(resultsFile)
        .pipe(split())
        .on('data', function(line) { ProcessLine(context, line); })
        .on('end', function() {
            delete context.testResult;
            next(null, context);
        });
}

function testData(tests, id) {
    var key = (typeof(id) === "string") ? id : id[0];

    if (!tests[key]) {
        tests[key] = { passes: [], failures: [] };
    }
    return tests[key];
}

function CompareIds(id1, id2)
{
    var parts1 = id1.match(/^(.*[A-Z])([0-9]+)$/),
        parts2 = id2.match(/^(.*[A-Z])([0-9]+)$/),
        label1 = parts1[1],
        label2 = parts2[1],
        num1 = Number(parts1[2]),
        num2 = Number(parts2[2]);

    if (label1 === label2)
    {
        return (num1 < num2) ? -1 : ((num1 === num2) ? 0 : 1);
    }
    return (label1 < label2) ? -1 : 1;
}

function ResultsMarkdown(tests)
{
    //console.log(JSON.stringify(tests, null, 4));
    console.log("# Overall Results");
    console.log("");
    console.log("Case | Passed | Failed");
    console.log("---- | ------ | ------");
    _.each(Object.keys(tests).sort(CompareIds), function(caseId) {
        console.log(caseId + " | " + tests[caseId].passes.join(", ") + " | " + tests[caseId].failures.join(", "));
    });
}

function Summarize(err, results)
{
    var tests = {};
    _.map(results, function(product) {
        _.map(product.tests, function(test) {
            _.map(test.passes, function(id) {
                testData(tests, id).passes.push(product.name + " " + product.version);
            });
            _.map(test.failures, function(id) {
                testData(tests, id).failures.push(product.name + " " + product.version);
            });
        });
    });
    ResultsMarkdown(tests);
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
    var resultsFile = "RefactorProResults.md";
    if (argv.length > 2)
    {
        ProcessFiles(argv.slice(2), Summarize);
    }
    else
    {
        ProcessResults(".", Summarize);
    }
}

main(process.argv);
