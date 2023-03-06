#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap()
{
    numItems=0;
}

void Heap::enqueue ( PrintJob* newjob)
{
    arr[numItems] = newjob;
    numItems++;

    trickleUp(numItems-1);
    

}

void Heap::trickleUp(int root)
{
    if(root<0) return;
    int parent_index = (root-1)/2;
    if(arr[root]->getPriority()<=arr[parent_index]->getPriority()) return;
    else
    {
        PrintJob *temp_ptr = arr[root];
        arr[root] = arr[parent_index];
        arr[parent_index] = temp_ptr;

        trickleUp(parent_index);
        return;
        
    }
}

void Heap::trickleDown(int root)
{
    if(root*2+1>numItems-1 || root*2+2>numItems-1) return;
    int max_index = root;
    PrintJob *temp_ptr;
    for(int i=1;i<=2;i++)
    {
        if(arr[max_index]->getPriority()<arr[2*root+i]->getPriority())
        {
            max_index = 2*root+i;
        }

    }

    if(max_index==root) return;
    else
    {
        temp_ptr = arr[root];
        arr[root] = arr[max_index];
        arr[max_index] = temp_ptr;
        trickleDown(max_index);
        return;
    }


}

void Heap::dequeue()
{
    arr[0] = arr[numItems-1];
    numItems--;

    trickleDown(0);

}

void Heap::print()
{
    PrintJob *top = arr[0];
    cout<<"priority:"<<top->getPriority()<<", job number:"<<top->getJobNumber()
    <<", number of pages:"<<top->getPages()<<endl;

 
}

PrintJob* Heap::highest()
{
    if(numItems==0) return 0;
    return arr[0];
}