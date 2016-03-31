/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: bkon4208
 */

#include "NodeController.h"
#include <stdlib.h>

NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}

NodeController::~NodeController()
{

}

void NodeController :: testLists()
{
	numbers -> addToFront(3);
	numbers -> addToEnd(8);
	cout << "Front should be 3 and is:  " << numbers->getFront() << endl;
	cout << "End should be 8 and is:  " << numbers->getEnd() << endl;
}

void NodeController :: sortData()
{
    /*
     Create an array and list
     Fill each with random data
     sort and time
     repeat with ordered data
     print results
     */
    
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numbersInList;
    int cPlusPlusArray[5000];
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    sortTimer.startTimer();

}

void NodeController::start()
{
    testLists();

	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterInts -> getSize(); index++)
	{
		notHipsterInts -> set(index, (23 * index));
	}

	for(int index = 0; index < notHipsterInts -> getSize(); index++)
	{
		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts -> get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();

}

void NodeController::doMergesort()
{
    mergeData = new int[5000];
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    mergesort(mergeData, 5000);
}

void NodeController::mergesort(int data [], int size)
{
    
}

void NodeController::merge(int data [], int sizeOne, int sizeTwo)
{
    
}


