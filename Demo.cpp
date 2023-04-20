#include "DataStructure.h"
#include "Demo.h"

#include <iostream>
using namespace std;

void Demo::array_demo()
{
    Array *arr = new Array();
    arr->addArrayItem(new ArrayItem(5));
    arr->addArrayItem(new ArrayItem(15));
    arr->addArrayItem(new ArrayItem(20));
    arr->addArrayItem(new ArrayItem(25));

    cout << to_string(arr->searchArrayItem(15)) + "\n"; // 查找 id 为 15 的元素位置
    arr->insertArrayItem(new ArrayItem(10), 2);         // 将 id 为 10 的元素插至第二位
    arr->deleteArrayItem(arr->length);                  // 删除最后一个元素
    cout << arr->getStr() + "\n";                       // 显示所有元素
}

void Demo::hash_demo()
{
    HashTable Hash(13);     // 创建哈希表对象Hash，哈希表长为13
    Hash.HashInit();        // 哈希表初始化
    Hash.CreateHashTable(); // 创建哈希表
    Hash.PrintHashTable();  // 打印哈希表
}

void Demo::linked_list_demo()
{
    LinkedList *linkedList = new LinkedList(new LinkedListItem(114514));                // 有参构造 114514
    linkedList->addLinkedListItem(new LinkedListItem(1919));                            // 后接 114514
    linkedList->insertLinkedListItemByIndex(new LinkedListItem(12), 3);                 // 在 1919 后插入 810
    cout << "The json of linkedList is " + linkedList->getLinkedListJson() + "\n";      // 输出 linkedList 数据
    cout << "The length of linkedList is " + to_string(linkedList->getLength()) + "\n"; // 输出 linkedList 长度
    linkedList->deleteLinkedListItemByIndex(1);                                         // 删除第一个数据
    cout << "The json of linkedList is " + linkedList->getLinkedListJson() + "\n";      // 输出 linkedList 数据
}

void Demo::queue_demo()
{
    queue<QueueItem> myQueue;
    myQueue.push(QueueItem(5));
    myQueue.push(QueueItem(15));
    myQueue.push(QueueItem(25));
    myQueue.push(QueueItem(35));
    myQueue.push(QueueItem(45));
    cout << QueueItem().getQueueJsonFromFrontToBack(myQueue);
    cout << myQueue.size();
}

void Demo::stack_demo()
{
    stack<StackItem> myStack;
    myStack.push(StackItem(5));
    myStack.push(StackItem(10));
    myStack.push(StackItem(15));
    myStack.push(StackItem(20));
    myStack.push(StackItem(25));
    myStack.push(StackItem(30));
    cout << StackItem().getStackJsonFromTopToBottom(myStack);
}

void Demo::tree_demo()
{

    // 初始化
    Tree *tree = new Tree(new TreeItem(5));
    tree->leftTree = new Tree(new TreeItem(8));
    tree->rightTree = new Tree(new TreeItem(4));
    tree->leftTree->leftTree = new Tree(new TreeItem(6));
    tree->leftTree->leftTree->leftTree = new Tree(new TreeItem(7));
    tree->leftTree->leftTree->rightTree = new Tree(new TreeItem(2));
    tree->rightTree->leftTree = new Tree(new TreeItem(3));
    tree->rightTree->rightTree = new Tree(new TreeItem(1));
    /*
             5
          8--|--4
        6-|   3-|-1
     7--|--2
    */

    // 先序
    tree->firstPrint();
    cout << '\n';
    // 中序
    tree->middlePrint();
    cout << '\n';
    // 后序
    tree->endPrint();
    cout << '\n';

    // 左右交换
    tree->swapLeftRight();
    /*
             5
          4--|--8
        1-|-3   |-6
               2--|--7
    */

    // 先序
    tree->firstPrint();
    cout << '\n';
    // 中序
    tree->middlePrint();
    cout << '\n';
    // 后序
    tree->endPrint();
    cout << '\n';
}