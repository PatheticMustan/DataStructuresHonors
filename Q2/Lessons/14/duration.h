/** Duration.cpp, by Kevin Wang
 * 
 * Complete the following program with the given declarations. All user input and output must occur in your
 * main function. You are permitted to create other functions if you feel they would help you complete the task.
 * Call your C++ file Duration. This is to be submitted to Classroom by the date on the assignment. You are only
 * completing one C++ file for this mini-project.
 * 
 * In your main function, display a menu to ask the user for their desired task. They are to first choose their
 * operation and then enter the values required. Their options are listed below. When the process is complete, ask
 * the user if they want to do it again. When displaying a Duration object, you must display it in proper HH:MM:SS form,
 * using exactly 2 digits for the minutes and seconds and at least 2 for the hours (in other words, 01 instead of 1).
 * The value for MM and SS can be no larger than 59. In addition, the values must be separated by a single colon.
 * 
 * Create a class called Duration inside of your program. Your class must contain private attributes for the
 * hours, minutes, and seconds for a given Duration object. You must also create a constructor that takes hours,
 * minutes, and seconds to create your objects. If no values or less than 3 values are passed in, the default of 0
 * must be set. You cannot specify minutes without hours or seconds without minutes or hours. Your class must
 * also contain the following methods, as well as any relevant accessor and mutator methods.
 * 
 * Adding two Duration objects together returns a Duration representing the sum.
 * Subtracting two Duration objects returns a Duration representing the difference.
 *      If the difference is negative, the result should be 00:00:00.
 * Multiplying a Duration by a constant returns a Duration representing the product.
 * Dividing a Duration by a constant returns a Duration representing the quotient, rounded down to the nearest second.
 * 
 * Dividing a Duration by another returns a double representing the ratio of the first Duration to the second.
 * Printing a Duration operator using cout << should display in proper HH:MM:SS form.
 * The class must also include a method called randomize that sets the value of the object to a randomly
 * generated Duration less than one day.
 * 
 * This project will be graded on:
 *      1. Documentation (4 points): Your code must be fully commented and employ standard C++-style conventions.
 *      2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 *      3. Methods (8 points): Each method has the proper declaration and works as expected.
 *      4. Overloaded operators (14 points): Each operator works as expected.
 * TOTAL: 30 points
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long schlong;

class Duration {
    private:
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        schlong realSeconds = -1;

    public:
        // constructors
        Duration(schlong t) {
            setRealTime(t);
        }
        Duration() : Duration(0, 0, 0) {}
        Duration(int h) : Duration(h, 0, 0) {}
        Duration(int h, int m) : Duration(h, m, 0) {}
        Duration(int h, int m, int s) {
            hours = h, minutes = m, seconds = s;
            updateRealTimeFromHMS();
        }


        // accessor/mutators
        schlong getRealTime() { return realSeconds; }
        void setRealTime(schlong t) {
            realSeconds = t;
            // If the difference is negative, the result should be 00:00:00.
            if (realSeconds < 0) realSeconds = 0;

            // update hms
            hours =   ( (realSeconds/60)/60 );
            minutes = ( (realSeconds/60)%60 );
            seconds = ( (realSeconds   )%60 );
        }

        int getHours() { return hours; }
        void setHours(int h) { hours = h; updateRealTimeFromHMS(); }

        int getMinutes() { return minutes; }
        void setMinutes(int m) { minutes = m; updateRealTimeFromHMS(); }

        int getSeconds() { return seconds; }
        void setSeconds(int s) { seconds = s; updateRealTimeFromHMS(); }

        void updateRealTimeFromHMS() {
            setRealTime(
                ((schlong)(hours)   * 60 * 60) +
                ((schlong)(minutes) * 60     ) +
                ((schlong)(seconds)          ));
        }

        // functionality
        // all my ugly boilerplate has allowed me to create super ezpz things
        Duration operator+ (Duration other) {
            return Duration(getRealTime() + other.getRealTime());
        };
        Duration operator- (Duration other) {
            cout << getRealTime() << ", " << other.getRealTime() << endl;
            return Duration(getRealTime() - other.getRealTime());
        };
        Duration operator* (Duration other) {
            return Duration(getRealTime() * other.getRealTime());
        };
        Duration operator/ (Duration other) {
            return Duration(getRealTime() / other.getRealTime());
        };
        Duration operator/ (double div) {
            return Duration((schlong)(getRealTime() / div));
        };

        // randomize???
        void randomize() {
            // The class must also include a method called randomize that sets the value of the object
            // to a randomly generated Duration less than one day.

            // https://stackoverflow.com/a/28656020/12894940
            // apparently just rand() isn't good enough, it keeps returning 23:29:43
            // the seed changes every second so as long as you don't try it super quickly it'll be different every time
            srand(time(NULL));
            setRealTime(rand() % (24*60*60));
        }

        // util
        operator string() {
            return toString();
        }
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
};
ostream& operator<< (ostream& stream, Duration d) {
    return stream << d.toString();
}

Duration getDurationFromInput() {
    cout << "Please enter the hours, minutes, and seconds for a duration\n";
    int hours, minutes, seconds;
    cin >> hours >> minutes >> seconds;

    return Duration(hours, minutes, seconds);
}