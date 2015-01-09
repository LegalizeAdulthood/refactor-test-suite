// Print out test results as JSON

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
    else if (matches = line.match(/^Name: *([^ ].*)$/i))
    {
        context.name = matches[1];
    }
    else if (matches = line.match(/^([A-Z][A-Z]*[0-9][0-9]*)\s\s*Pass(.*)$/))
    {
        testResult(ctx.passes, matches);
    }
    else if (matches = line.match(/^([A-Z][A-Z]*[0-9][0-9]*)\s\s*Failure(.*)$/))
    {
        testResult(ctx.failures, matches);
    }
    else if (line.indexOf("= ") == 0)
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

function ProcessResults(dir, next)
{
    var results = [];
    fs.readdir(dir, function(err, files) {
    async.eachSeries(files,
        function(file, nextFile) {
            if (file.match(/^[A-Z].*Results\.txt$/)) {
                ProcessResultsFile(file, function(err, fileResults) {
                    results.push(fileResults);
                    nextFile(null);
                });
            } else {
                nextFile(null);
            }
        },
        function(err) {
            next(err, results);
        });
    });
}

function Summarize(err, results)
{
    console.log(JSON.stringify(results, null, 4));
}

function main(argv) {
    var resultsFile = "RefactorProResults.txt";
    if (argv.length > 2)
    {
        resultsFile = argv[2];
    }
    ProcessResults(".", Summarize);
}

main(process.argv);
