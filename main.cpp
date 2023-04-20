#include "DataStructure.h"
#include "Demo.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    Demo demo = Demo();
    demo.array_demo();
    demo.hash_demo();
    demo.linked_list_demo();
    demo.queue_demo();
    demo.stack_demo();
    demo.tree_demo();
    return 0;
}
