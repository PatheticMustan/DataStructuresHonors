#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * IT'S BACK!
 * Write a program called DuckDuckGoose that first prompts the user for the name of a file and then performs
 * the DuckDuckGoose algorithm from Intro to Programming. The txt file will contain a series of runs of the program.
 * The first line for each run is the number of participants and the second line is the cycle.
 * The cycle number does not need to be less than the number of participants, but both will be positive values.
 * 
 * Your program must output the trial number followed by a colon and a single space and then the position of the
 * trial winner, one trial per line, in a new text file called "result.txt" that is created by your program.
 * Your program MUST use a circular linked list to run each trial.
 * 
 * Standard rules apply for formatting and usability.
 *      4 points for documentation,
 *      4 points for user-friendliness,
 *      24 points for the required functionality (file read, linked list, file write, correct result for each trial).
 * (For those of you that don't know what I'm talking about, look up the Josephus problem)
 **/

int main() {
    ListNode* head;

    string fileName;
    cout << "Input the filename: ";
    cin >> fileName;

    ifstream input(fileName);
    
    // The first line for each run is the number of participants and the second line is the cycle.
    // The cycle number does not need to be less than the number of participants, but both will be positive values.
    int runs = -1,
        cycle = -1;

    input >> runs;
    if (input.is_open()) {
        cout << "natsumi" << runs;

    } else {
        cout << "unable to open " << fileName << endl;
    }
    while (input >> runs) {
        input >> cycle;

        // create cycle, 
        for (int i=0; i<cycle; i++) {
            if (i == 0) {
                head = new ListNode(to_string(i), NULL);
            } else {
                head->add(new ListNode(to_string(i), NULL));
            }
        }
        head = head->getNext();

        // Your program must output the trial number followed by a colon and a single space and then the position of the
        // trial winner, one trial per line, in a new text file called "result.txt" that is created by your program.
        cout << head;
    }
    input.close();



    ofstream result("result.txt");
    if (result.is_open()) {
        result << "poopoo";
        result.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}