#include <iostream>
#include "Pyramid.h"
#include "IntQueue.h"
#include "QueueQueue.h"
using namespace std;

/**
 * The AssemblyLine program must include 3 separate classes (AssemblyLine, Pyramid, Disk).
 * In order to help you to understand the different aspects of this assignment, I've broken down the 3 methods of
 * the AssemblyLine class for you in the word document.
 * 
 * You must submit the three classes to submit your program, but they do not need to be separate files. Standard rules apply.
 * 
 * Please make sure that all three of your classes have a way of displaying the information they are storing.
 * 
 * enqueue: add to queue
 * dequeue: remove from queue
 **/

class AssemblyLine {
    private:
        IntQueue* assemblyLineIn = NULL;
        QueueQueue* assemblyLineOut = NULL;
        Pyramid* robotArm = NULL;
    public:
        /**
         * initializes this object so the assemblyLineIn contains nDisks with random radii;
         * assemblyLineOut is initialized to an empty Queue;
         * robotArm is initialized to an empty Pyramid.
         **/
        AssemblyLine(int n) {
            assemblyLineIn = new IntQueue();
            assemblyLineOut = new QueueQueue();
            robotArm = new Pyramid();

            // queue a random number 1-10, n times
            for (int i=0; i<n; i++) {
                assemblyLineIn->enqueue(rand() % 10 + 1);
            }
        }

        /**
         * "flips over" the pyramid in the robotArm and adds it to the assemblyLineOut queue.
         * Precondition: robotArm is not empty and holds an inverted pyramid of disks
         **/
        void unloadRobot(Pyramid* p) {
            assemblyLineOut->enqueue(p);
        }

        /**
         * processes all disks from assemblyLineIn; a disk is processed as follows:
         * if robotArm is not empty and the next disk does not fit on top
         * of robotArm (which must be an inverted pyramid)
         * then robotArm is unloaded first; the disk from assemblyLineIn is added to robotArm;
         * when all the disks have been retrieved from assemblyLineIn, robotArm is unloaded.
         * Precondition: robotArm is empty; assemblyLineOut is empty
         **/
        //process

};

int main() {
    srand (time(NULL));

    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    AssemblyLine* ass = new AssemblyLine(n);


    return 0;
}