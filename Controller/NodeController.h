/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: bkon4208
 */

#ifndef NODECONTROLLER_H_
#define NODECONTROLLER_H_


#include <string>

#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"

using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
    void sortData();
    void testLists();
    void searchTest();
    void doBogo();
    
    void swap(int first, int second);
    void quicksort(int first, int size);
    int partition(int first, int last);
    void doQuick();
    
    int  * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* NODECONTROLLER_H_ */
