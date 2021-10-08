# Time Tracker MiniProject
Complete the following program with the given declarations.
All user input and output must occur in your main function.
You are permitted to create other functions if you feel they would help you complete the task.

Call your C++ file `TimeTracker`. This is to be submitted to Classroom by the date on the assignment. You are
only completing one C++ file for this mini-project.

## Input
In your main function, display a menu to ask the user for their desired task.
They are to first choose their operation and then enter the values required.
Their options are listed below. When the process is complete, ask the user if they want to do it again.

## Program
When displaying a Time object, you must display it in proper HH:MM:SS form,
using exactly 2 digits for the minutes and seconds and at least 2 for the hours (in other words, 01 instead of 1).
The value for MM and SS can be no larger than 59. In addition, the values must be separated by a single colon.

## Specs
Create a class called `Time` inside of your program. Your class must contain private attributes for the hours,
minutes, and seconds for a given Time object. You must also create constructors that take seconds only and
take hours, minutes, and seconds to create your objects.

Your class must also contain the following methods, as well as any relevant accessor and mutator methods.

```text
Time add(Time other)
    This method adds two Time objects and returns a new object.

Time subtract(Time other)
    This method subtracts two Time objects and returns a new object.

Time increaseBy(int h, int m, int s)
    This method increases the Time object by the given arguments and returns a new object.

Time increaseBy(int s)
    This method increases the Time object by the given argument and returns a new object.
```

This project will be graded on:

1. Documentation (4 points): Your code must be fully commented and employ standard C++-style conventions.
2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
3. Class (24 points): Each function has the proper declaration and works as expected.

TOTAL: 32 points
