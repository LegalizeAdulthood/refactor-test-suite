# Visual AssistX

Home: [Visual AssistX](http://www.wholetomato.com/)

Version: 10.5.1738.0, 10.8.2043.0

Notes:

Visual AssistX performs Create Method Stub with
Create Implementation From Usage.

Version 10.8.2043.0 was used for Move Implementation to Source File
testing.

<hr/>

## Change Signature
Case | Result
---- | ------
CS1     | Failure (doesn't update usage) [case=2164](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11911)

## Extract Function
Case | Result
---- | ------
EXF1 | Failure
EXF2 | Failure
EXF3 | Failure
EXF4 | Failure
EXF5 | Failure
EXF6 | Failure
EXF7 | Failure
EXF8 | Failure
EXF9 | Failure
EXF10 | Failure
EXF11 | Failure
EXF12 | Failure
EXF13 | Failure
EXF14 | Failure
EXF15 | Failure
EXF16 | Failure
EXF17 | Failure
EXF18 | Failure
EXF19 | Failure [case=4369](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11916)
EXF20 | Failure [case=4369](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11916)

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Failure [case=82956](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11883)
EM3 | Failure [case=82956](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11883)
EM4 | Pass
EM5 | Failure
EM6 | Pass
EM7 | Pass
EM8 | Failure
EM9 | Failure
EM10 | Pass
EM11 | Failure
EM12 | Pass
EM13 | Pass
EM14 | Failure
EM15 | Failure
EM16 | Pass
EM17 | Failure
EM18 | Pass
EM19 | Failure [case=2063](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11884)
EM20 | Failure [case=83005](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11885)

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass
MISF2  | Failure (invalid syntax)
MISF3  | Pass
MISF4  | Pass
MISF5  | Pass
MISF6  | Pass
MISF7  | Pass
MISF8  | Pass
MISF9  | Pass
MISF10 | Pass
MISF11 | Pass
MISF12 | Pass
MISF13 | Pass
MISF14 | Pass
MISF15 | Pass
MISF16 | Failure (not available)
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure (not available)

## Rename
Case | Result
---- | ------
R1      | Failure (doesn't select all instances of identifier) [case=58805](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11900)
R2      | Failure (doesn't select all instances of identifier)
R3      | Failure (doesn't select all instances of identifier)
R4      | Failure (doesn't select all instances of identifier) [case=1384](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11901)
R5      | Pass
R6      | Pass
R7      | Pass
R8      | Pass [case=34692](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11904)
R9      | Pass
R10     | Pass
R11     | Pass
R12     | Pass
R13     | Pass
R14     | Failure (doesn't select all instances of identifier)
R15     | Pass
R16     | Pass
R17     | Pass
R18     | Pass
R19     | Failure (doesn't select all instances of identifier)
R20     | Failure (doesn't select all instances of identifier)
R21     | Pass
R22     | Pass
R23     | Pass
R24     | Pass
R25     | Failure (not available) [case=83603](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11905)
R26     | Pass
R27     | Failure (doesn't select all instances of identifier)
R28     | Pass
R29     | Failure (doesn't select all instances of identifier) [~~~case=83847~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11906)
R30     | Pass
R31     | Pass
R32     | Failure (suggested identifier contains ~ and is allowed)
R33     | Failure (doesn't select all instances of identifier)
R34     | Failure (doesn't select all instances of identifier)
R35     | Failure (not available)
R36     | Failure (doesn't select all instances of identifier) [~~~case=83847~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11907)
R37     | Pass
R38     | Pass
R39     | Pass
R40     | Pass
R41     | Failure (not available) [case=83848](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11908)
R42     | Pass
R43     | Pass
R44     | Pass
R45     | Failure (not available)
R46     | Pass
R47     | Pass
R48     | Pass
R49     | Pass
R50     | Pass
R51     | Pass
R52     | Pass
R53     | Pass
R54     | Pass
R55     | Pass
R56     | Pass
R57     | Pass
R58     | Pass
R59     | Pass
R60     | Pass
R61     | Pass
R62     | Pass
R63     | Pass
R64     | Pass
R65     | Pass
R66     | Pass
R67     | Pass
R68     | Pass
R69     | Pass
R70     | Pass
R71     | Failure (doesn't select all instances of identifier)
R72     | Failure (doesn't select all instances of identifier)
R73     | Failure (doesn't select all instances of identifier)
R74     | Pass [case=83856](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11909), [case=58805](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11909)
R75     | Pass
R76     | Pass
R77     | Failure (not available) [case=83858](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11910)
R78     | Pass
R79     | Pass
R80     | Pass
R81     | Failure (not available) [case=83858](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11910)
R82     | Failure (doesn't select all instances of identifier)
R83     | Failure (doesn't select all instances of identifier)
R84     | Pass
R85     | Pass
R86     | Pass
R87     | Pass
R88     | Pass
R89     | Pass
R90     | Pass
R91     | n/a
R92     | n/a
R93     | Pass
R94     | Pass
R95     | Pass
R96     | Pass
R97     | Pass
R98     | Pass

<hr/>

Other issues:

* when double clicking a list item in the Rename selection dialog,
  it should put the selected line at the center of the editor window
  if it repositions the scroll bar
* Extract Method gives no feedback on names [case=83040](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11890)
* File should not be selected when no items selected [case=83859](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11902)
* Change Signature doesn't adjust ptr to member [case=83184](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11913), [case=83185](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11913)
* VAX colors raw string literal as a type [case=65734](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11975)
* Create From Declaration unavailable for operator== [case=84291](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11981)
* Move Implementation to Source File fails with C11 [~~~case=79737~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=12074)
