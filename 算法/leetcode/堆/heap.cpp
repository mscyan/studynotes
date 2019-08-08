#include <iostream>
#include "treeheap.h"
#include "arrayheap.h"
using namespace std;
int main()
{
    // treeheap *heap = new treeheap(2);

    arrayheap *heap = new arrayheap(10);
    // heap->insert(5);
    // heap->insert(3);
    // heap->insert(8);
    // heap->insert(1);
    // heap->insert(12);

    cout<<heap->pop();
    return 0;
}
