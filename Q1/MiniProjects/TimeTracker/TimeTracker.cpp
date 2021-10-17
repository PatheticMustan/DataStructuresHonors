/** TimeTracker.cpp, by Kevin Wang
 * Complete the following program with the given declarations.
 * All user input and output must occur in your main function.
 * You are permitted to create other functions if you feel they would help you complete the task.
 * Call your C++ file `TimeTracker`. This is to be submitted to Classroom by the date on the assignment. You are
 * only completing one C++ file for this mini-project.
 * 
 * In your main function, display a menu to ask the user for their desired task.
 * They are to first choose their operation and then enter the values required.
 * Their options are listed below. When the process is complete, ask the user if they want to do it again.
 * 
 * When displaying a Time object, you must display it in proper HH:MM:SS form,
 * using exactly 2 digits for the minutes and seconds and at least 2 for the hours (in other words, 01 instead of 1).
 * The value for MM and SS can be no larger than 59. In addition, the values must be separated by a single colon.
 * 
 * Create a class called `Time` inside of your program. Your class must contain private attributes for the hours,
 * minutes, and seconds for a given Time object. You must also create constructors that take seconds only and
 * take hours, minutes, and seconds to create your objects.
 * Your class must also contain the following methods, as well as any relevant accessor and mutator methods.
 * 
 * Time add(Time other)
 *      This method adds two Time objects and returns a new object.
 * Time subtract(Time other)
 *      This method subtracts two Time objects and returns a new object.
 * Time increaseBy(int h, int m, int s)
 *      This method increases the Time object by the given arguments and returns a new object.
 * Time increaseBy(int s)
 *      This method increases the Time object by the given argument and returns a new object.
 * 
 * This project will be graded on:
 *      1. Documentation (4 points): Your code must be fully commented and employ standard C++-style conventions.
 *      2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 *      3. Class (24 points): Each function has the proper declaration and works as expected.
 * TOTAL: 32 points
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long schlong;

class Time {
    public:
        // constructors
        Time(int s) : Time(0, 0, s) {}
        Time(schlong t) {
            setRealTime(t);
            recalculateHMS();
        }
        Time(int h, int m, int s) {
            setRealTime(
                ((schlong)(h) * 60 * 60) +
                ((schlong)(m) * 60     ) +
                ((schlong)(s)          ));
            recalculateHMS();
        }


        // accessor/mutators
        schlong getRealTime() { return realSeconds; }
        void setRealTime(schlong t) { realSeconds = t; }

        int getHours() { return hours; }
        void setHours(int h) { hours = h; }

        int getMinutes() { return minutes; }
        void setMinutes(int m) { minutes = m; }

        int getSeconds() { return seconds; }
        void setSeconds(int s) { seconds = s; }


        // functionality
        // all my ugly boilerplate has allowed me to create super ezpz things
        Time add(Time other) {
            return Time(getRealTime() + other.getRealTime());
        }
        Time subtract(Time other) {
            return Time(getRealTime() - other.getRealTime());
        }
        Time increaseBy(int h, int m, int s) {
            setRealTime(getRealTime() + Time(h, m, s).getRealTime());
            recalculateHMS();

            return Time(getRealTime());
        }
        Time increaseBy(int s) {
            setRealTime(getRealTime() + Time(s).getRealTime());
            recalculateHMS();

            return Time(getRealTime());
        }


        // util
        string toString() {
            int ah = abs(hours),
                am = abs(minutes),
                as = abs(seconds);

            // determine negative sign from realSeconds
            // hours/minutes/seconds doesn't need negative signs
            // if it's a single digit, leftpad it with a 0
            // ??? for some reason I need to typecase the negative sign to a string
            return
                (string)((realSeconds < 0)? "-" : "") +
                ((ah < 10)? "0" : "") + to_string(ah) + ":" + 
                ((am < 10)? "0" : "") + to_string(am) + ":" + 
                ((as < 10)? "0" : "") + to_string(as);
        }

        void recalculateHMS() {
            setHours  ( (realSeconds/60)/60 );
            setMinutes( (realSeconds/60)%60 );
            setSeconds( (realSeconds   )%60 );
        }





    private:
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        // ultra mega scuffed method, I think I might get points off for this
        schlong realSeconds = -1;
};

int main() {
    cout <<
        "Time Tracker!" << "\n" <<
        "[1] Add two times together" << "\n" <<
        "[2] Subtract two times" << "\n" <<
        "[3] Add hours/minutes/seconds to a time" << "\n" <<
        "[4] Add seconds to a time" << "\n" <<
        "[5] Exit" << "\n\n";
    
    int input;
    cin >> input;
    cout << "\n";

    switch (input) {
        case 1: {
            int h, m, s;

            cout << "Create the first time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time first(h, m, s);
            cout << "Create the second time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time second(h, m, s);

            cout <<
                first.toString() << " + " <<
                second.toString() << " = " <<
                first.add(second).toString() << "\n";
            break;
        }
        case 2: {
            int h, m, s;

            cout << "Create the first time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time first(h, m, s);
            cout << "Create the second time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time second(h, m, s);

            cout <<
                first.toString() << " - " <<
                second.toString() << " = " <<
                first.subtract(second).toString() << "\n";
            break;
        }
        case 3: {
            int h, m, s;

            cout << "Create the first time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time first(h, m, s);
            cout << "Let's add (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;

            cout <<
                first.toString() << " + " <<
                h << " hours, " <<
                m << " minutes, " <<
                s << " seconds = " <<
                first.increaseBy(h, m, s).toString() << "\n";
            break;
        }
        case 4: {
            int h, m, s;

            cout << "Create the first time: (hours minutes seconds)!" << "\n";
            cin >> h >> m >> s;
            Time first(h, m, s);
            cout << "Let's add (seconds)!" << "\n";
            cin >> s;

            cout <<
                first.toString() << " + " <<
                s << " seconds = " <<
                first.increaseBy(s).toString() << "\n";
            break;
        }
        case 5: {
            return 1;
        }
        default: {
            cout << "Hey! That's not a valid option..." << "\n";
        }
    }

    cout << "\n\n";
    main();

    // should never hit -1, but hey, ya never know
    return -1;
}