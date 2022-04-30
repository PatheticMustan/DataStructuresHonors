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
    public:
        IntQueue* assemblyLineIn = NULL;       // a queue of int's
        QueueQueue* assemblyLineOut = NULL;    // a queue of *Pyramid's
        Pyramid* robotArm = NULL;              // a stack of int's

        /**
         * initializes this object so the assemblyLineIn contains nDisks with random radii;
         * assemblyLineOut is initialized to an empty Queue;
         * robotArm is initialized to an empty Pyramid.
         **/
        AssemblyLine(int n) {
            assemblyLineIn = new IntQueue();
            assemblyLineOut = new QueueQueue();
            robotArm = new Pyramid();

            // queue a random number 1-69, n times
            for (int i=0; i<n; i++) {
                assemblyLineIn->enqueue(rand()%69 + 1);
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
        void process() {
            // shake it out! process disks until assembly line is empty
            while (assemblyLineIn->peek() != -1) {
                int disk = assemblyLineIn->dequeue();
                if (robotArm->peek() <= disk) {
                    robotArm->push(disk);
                } else {
                    unloadRobot(robotArm);
                    robotArm = new Pyramid();
                    robotArm->push(disk);
                }
            }
            // unload any leftover pyramids
            if (robotArm->peek() != -1) {
                unloadRobot(robotArm);
                robotArm = new Pyramid();
            }
        }

};

int main() {
    // randomize based on time
    srand (time(NULL));

    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    // this is pretty self explanatory
    // hehehehe ass
    AssemblyLine* ass = new AssemblyLine(n);

    cout << ass->assemblyLineIn << endl;
    ass->process();
    cout << ass->assemblyLineOut << endl;

    return 0;
}