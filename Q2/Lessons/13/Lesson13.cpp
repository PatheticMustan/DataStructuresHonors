/** Lesson13.cpp, by Kevin Wang
 * Write a program that simulates rolling a pair of 6-sided dice using static_cast.
 * The numeric distribution should be standard. Then, loop it 10,000 times
 * and display the percentage of each result.
 **/

#include <bits/stdc++.h>
using namespace std;

int iUsedToRollTheDice() {
    // feel the fear in my enemies' eyes
    // listen as the crowd would sing!
    // now the old king is dead, long live the king
    return (rand() % 6) + 1;
}

int main() {
    // randomize rand with current time
    srand(time(NULL));

    // make array and init to 0
    int results[12] = {};

    // and they're off!
    for (int i=0; i<10000; i++) results[(iUsedToRollTheDice() + iUsedToRollTheDice()) - 1]++;

    for (int i=0; i<12; i++) {
        cout << results[i]
             << " pairs of dice resulted in " << i
             << "(" << (static_cast<double>(results[i]) / 100) << "%)" // n/10000*100 = n/100
             << "\n";
    }

    return 0;
}