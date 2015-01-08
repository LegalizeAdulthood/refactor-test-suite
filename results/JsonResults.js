// Print out test results as JSON
var refactoring;
var passes;
var failures;
var passedAllTests = [];
var testResults = [];

var fs = require('fs');
var split = require('split');

function Percentage(passed, total)
{
    var pct = String(Math.ceil(100*100*passed/total)/100) + "%";
    return (pct + "      ".substr(0, 6 - pct.length)).trim();
}

function StartTest()
{
    refactoring = "";
    passes = [];
    failures = [];
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

function ProcessLine(line)
{
    var matches,
        comment,
        id;

    if (line.length == 0)
    {
        if (passes.length + failures.length > 0)
        {
            if (failures.length == 0)
            {
                passedAllTests.push(refactoring);
            }
            testResults.push({
                name: refactoring,
                percent: Percentage(passes.length, passes.length + failures.length),
                passes: passes,
                failures: failures
            });
        }
        StartTest();
    }
    else if (matches = line.match(/^([A-Z][A-Z]*[0-9][0-9]*)\s\s*Pass(.*)$/))
    {
        testResult(passes, matches);
    }
    else if (matches = line.match(/^([A-Z][A-Z]*[0-9][0-9]*)\s\s*Failure(.*)$/))
    {
        testResult(failures, matches);
    }
    else if (line.indexOf("= ") == 0)
    {
        refactoring = line.substr(2);
    }
}

function EmitReport()
{
    var results = {
        file: resultsFile,
        date: (new Date()).toString(),
        tests: testResults
    };
    console.log(JSON.stringify(results, null, 4));
}

function main(resultsFile)
{
    StartTest();

    fs.createReadStream(resultsFile)
        .pipe(split())
        .on('data', ProcessLine)
        .on('end', EmitReport);
}

var resultsFile = "RefactorProResults.txt";
if (process.argv.length > 2)
{
    resultsFile = process.argv[2];
}
console.log("Results file: " + resultsFile);
main(resultsFile);
