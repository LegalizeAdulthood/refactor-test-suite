// Print out test results
var fso = new ActiveXObject("Scripting.FileSystemObject");

var infile = fso.OpenTextFile("RefactorProResults.txt");
var refactoring;
var passes;
var failures;
var totalPasses = 0;
var totalFailures = 0;

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

StartTest();

var passedAllTests = new Array();

while (!infile.AtEndOfStream)
{
	var line = infile.ReadLine();
	if (line.length == 0)
	{
		if (passes + failures > 0)
		{
			if (failures == 0)
			{
				passedAllTests.push(refactoring);
			}
			WScript.Echo(Percentage(passes, passes + failures) + refactoring + ": " + passes + " passed, " + failures + " failed");
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
		refactoring = line.substr(line.indexOf("= ") + 1);
	}
}

WScript.Echo("");
WScript.Echo(passedAllTests.length + " Passed all tests:");
WScript.Echo(passedAllTests.join("\n"));
WScript.Echo("");
var numTests = totalPasses + totalFailures;
WScript.Echo("Total: " + Percentage(totalPasses, numTests) + " (" + totalPasses + " passed + " + totalFailures + " failed = " + numTests + " total)");
