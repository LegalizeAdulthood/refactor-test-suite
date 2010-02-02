// Print out test results
var fso = new ActiveXObject("Scripting.FileSystemObject");

var infile = fso.OpenTextFile("RefactorProResults.txt");
var refactoring;
var passes;
var failures;

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
			WScript.Echo(refactoring + ": " + passes + " passed, " + failures + " failed: " + Math.ceil(100*100*passes/(passes + failures))/100 + "%");
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
	else if (line.indexOf("=") == 0)
	{
		refactoring = line;
	}
}

WScript.Echo("");
WScript.Echo(passedAllTests.length + " Passed all tests:");
WScript.Echo(passedAllTests.join("\n"));
