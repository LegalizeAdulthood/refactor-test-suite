// Print out test results
var refactoring;
var passes;
var failures;
var passedAllTests = [];
var totalPasses = 0;
var totalFailures = 0;

var fs = require('fs');
var split = require('split');

function Percentage(passed, total)
{
    var pct = String(Math.ceil(100*100*passed/total)/100) + "%";
    return pct + "      ".substr(0, 6 - pct.length);
}

function StartTest()
{
    refactoring = "";
    passes = 0;
    failures = 0;
}

function ProcessLine(line)
{
    if (line.length == 0)
    {
        if (passes + failures > 0)
        {
            if (failures == 0)
            {
                passedAllTests.push(refactoring);
            }
            console.log(Percentage(passes, passes + failures) + " " + refactoring + ": " + passes + " passed, " + failures + " failed");
            totalPasses += passes;
            totalFailures += failures;
        }
        StartTest();
    }
    else if (line.indexOf("Pass") > 0)
    {
        passes++;
    }
    else if (line.indexOf("Failure") > 0)
    {
        failures++;
    }
    else if (line.indexOf("= ") == 0)
    {
        refactoring = line.substr(2);
    }
}

function EmitReport()
{
    console.log("");
    console.log(passedAllTests.length + " Passed all tests:");
    console.log(passedAllTests.join("\n"));
    console.log("");
    var numTests = totalPasses + totalFailures;
    console.log("Total: " + Percentage(totalPasses, numTests) + " (" + totalPasses + " passed + " + totalFailures + " failed = " + numTests + " total)");
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
