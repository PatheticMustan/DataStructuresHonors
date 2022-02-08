/** WordCounts.cpp, by Kevin Wang
 * Write a program called WordCount that first prompts the user for the name
 * of a file and then performs a count of the number of times a word appears in the file.
 * There will be no punctuation, but there can be numbers.
 * 
 * Assume words are not case-sensitive here (in other words, "HeLlO" and "hello" are the same word).
 * At the end of the program, display the list of words in alphabetical order,
 * one word and its count per line (separated by a single space),
 * in a new text file that is named "result.txt" (and is created by your program).
 * 
 * Your program MUST use Linked Lists to store the words. Standard rules apply for formatting and usability.
 * 4 points for documentation,
 * 4 points for user-friendliness,
 * 22 points for the required functionality
 *      (file read,
 *      linked list,
 *      file write,
 *      words properly sorted and counted).
 **/

#include <bits/stdc++.h>
using namespace std;
#include "ListLab.h"

void printMe(ListNode* head) {
	cout << "[";
	while(head != NULL) {
		 cout << head->getWord();
		 head = head->getNext();
		 if(head != NULL)
			 cout << ", ";
	}
	cout << "]" << endl;
}

int main() {
    string fileName;
    cout << "Input the filename: ";
    cin >> fileName;

    string word;
    ifstream iLoveCopterRoyale(fileName);

    ListNode* wordlist = NULL;
    int c = 0;

    while (iLoveCopterRoyale >> word) {
        cout << 1 << endl;
        if (c++ == 0) {
            wordlist = new ListNode(word, NULL);
            continue;
        } else {
            cout << word << endl;

            ListNode* h = wordlist;
            while (h->getWord().compare(word) < 0) {
                cout << h->getWord() << ": " << word << endl;
                h = h->getNext();
            }
        }
        
    }
    printMe(wordlist);
    iLoveCopterRoyale.close();


    /*
    ofstream result("result.txt");
    if (result.is_open()) {
        result << "This is a line.\n";
        result << "This is another line.\n";
        result.close();
    } else {
        cout << "Unable to open file";
    }
    */

    return 0;
}