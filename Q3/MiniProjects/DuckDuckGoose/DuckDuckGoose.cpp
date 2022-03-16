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
    ofstream result("result.txt");
    
    // The first line for each run is the number of participants and the second line is the cycle.
    // The cycle number does not need to be less than the number of participants, but both will be positive values.
    int participants = -1,
        cycle = -1;

    int runs = 0;
    if (input.is_open() && result.is_open()) {
        while (input >> participants) {
            input >> cycle;

            // create cycle, 
            for (int i=0; i<participants; i++) {
                if (i == 0) {
                    head = new ListNode(to_string(i), NULL);
                } else {
                    head->add(new ListNode(to_string(i), NULL));
                }
            }

            int currentCycle = 0;
            while (head != head->getNext()) {
                currentCycle++;
                if (currentCycle == cycle) {
                    //cout << head->getValue();
                    head = head->remove();
                    currentCycle = 0;
                } else {
                    head = head->getNext();
                }
            }

            // Your program must output the trial number followed by a colon and a single space and then the position of the
            // trial winner, one trial per line, in a new text file called "result.txt" that is created by your program.
            //cout << " - " << participants << " " << cycle << " --> " << (stoi(head->getValue()) + 1) << endl;
            result << runs << ": " << (stoi(head->getValue())+1) << endl;
            runs++;
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    return 0;
}