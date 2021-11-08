/** Lesson12.cpp, by Kevin Wang
 * Modify the Date class so that it updates properly.
 * Program a conversion operator for the Date class so that it
 * converts the date it holds into a unique integer.
 **/

#include <bits/stdc++.h>
using namespace std;

// NOTE: originally copied from classwork files, modified for assignment
// also contains postfix increment and decrement
class Date {
    private:
        int day, month, year;

        int daysInMonth(int month, int year) {
            if (month == 2) {
                if (year % 100 == 0) return 28;
                return (year % 4 == 0)? 29 : 28;
            }

            int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            return days[month-1]; // stupid one-indexing
        }
        // go backwards one day
        void blastFromThePast() {
            day--;
            if (day < 1) {
                month--;
                if (month < 1) {
                    month = 12;
                    year--;
                    day = daysInMonth(month, year-1);
                } else {
                    day = daysInMonth(month, year);
                }
            }
        }
        void backToTheFuture() {
            day++;
            if (day > daysInMonth(month, year)) {
                day = 1;
                month++;

                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }

    public:
        Date (int inMonth, int inDay, int inYear)
            : month (inMonth), day(inDay), year (inYear) {};

        Date& operator ++ () { // prefix increment
            backToTheFuture();
            return *this;
        }

        Date& operator -- () { // prefix decrement
            blastFromThePast();
            return *this;
        }

        Date operator ++ (int) { // postfix increment
            Date copy(month, day, year);
            backToTheFuture();
            return copy;
        }

        Date operator -- (int) { // postfix decrement
            Date copy(month, day, year);
            blastFromThePast();
            return copy;
        }

        operator int() {
            // only requirement is "uniqueness"
            // assumes year has 5 digits or less, which I think is pretty safe to assume
            return year + day*100000 + month*100000*100;
        }

        void DisplayDate() {
            cout << month << " / " << day << " / " << year << endl;
        }
};

int main () {
    Date jday(12, 25, 2015); // Dec 25, 2016

    /*
    for (int i=0; i<450; i++) {
        jday++;
        jday.DisplayDate();
    }

    for (int i=0; i<450; i++) {
        jday--;
        jday.DisplayDate();
    }
    */

    cout << (int)jday << endl;

    return 0;
}