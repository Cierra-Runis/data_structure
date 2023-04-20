#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#define MAX_LENGTH 100

#include <queue>
#include <stack>
#include <string>
using namespace std;

class ArrayItem
{
private:
public:
    int id;

    ArrayItem();
    ArrayItem(int id);
    string getStr();
};

class Array
{
private:
    ArrayItem arrayItems[MAX_LENGTH];

public:
    int length;

    Array();
    void addArrayItem(ArrayItem *ArrayItem);
    void insertArrayItem(ArrayItem *ArrayItem, int index);
    void deleteArrayItem(int index);
    int searchArrayItem(int id);
    string getStr();
};

class HashNode // 哈希链表结点
{
public:
    int key;        // 关键字域
    HashNode *node; // 下一个关键字结点
};

class HashList // 哈希链表
{
public:
    HashNode *head; // 头节点指针域
};

class HashTable // 哈希表
{
public:
    // 构造函数
    HashTable(int size)
    {
        m_length = size;
        Array = new HashList[size];
    }
    int HashFunction(int key); // 哈希函数
    void HashInit();           // 初始化哈希表
    void CreateHashTable();    // 创建哈希表
    void PrintHashTable();     // 打印哈希表
private:
    HashList *Array; // 哈希数组
    int m_length;    // 哈希表长
};

class LinkedListItem
{
private:
    int data;

public:
    LinkedListItem();
    LinkedListItem(int data);
    string getLinkedListItemJson();
};

class LinkedList
{
private:
    LinkedListItem linkedListItem;
    LinkedList *next;

public:
    LinkedList();
    LinkedList(LinkedListItem *linkedListItem);
    void addLinkedListItem(LinkedListItem *linkedListItem);
    void insertLinkedListItemByIndex(LinkedListItem *linkedListItem, int index);
    void deleteLinkedListItemByIndex(int index);
    int getLength();
    string getLinkedListJson();
};

class QueueItem
{
private:
public:
    int data = 0;

    QueueItem();
    QueueItem(int data);
    void setData(int data);
    string getQueueItemJson();
    string getQueueJsonFromFrontToBack(queue<QueueItem> myQueue);
};

class StackItem
{
private:
    /* data */
public:
    int data;

    StackItem();
    StackItem(int data);

    void setData(int data);
    string getStackItemJson();
    string getStackJsonFromTopToBottom(stack<StackItem> myStack);
};

class TreeItem
{
private:
public:
    int data;

    TreeItem();
    TreeItem(int data);
    void setData(int data);
    string getTreeItemJson();
};

class Tree
{
private:
public:
    TreeItem *treeItem;
    Tree *leftTree;
    Tree *rightTree;

    Tree(TreeItem *treeItem);
    void firstPrint();
    void middlePrint();
    void endPrint();
    void swapLeftRight();
};

#endif
