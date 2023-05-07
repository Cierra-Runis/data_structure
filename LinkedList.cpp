#include "DataStructure.h"

#include <string>
#include <iostream>
using namespace std;

LinkedListItem::LinkedListItem()
{
    this->data = 0;
}

LinkedListItem::LinkedListItem(int data)
{
    this->data = data;
}

string LinkedListItem::getLinkedListItemJson()
{
    return "{\"data\": " + to_string(this->data) + "}";
}

LinkedList::LinkedList()
{
    this->next = nullptr;
}

LinkedList::LinkedList(LinkedListItem *linkedListItem)
{
    LinkedList *newLinkedList = new LinkedList();
    newLinkedList->linkedListItem = linkedListItem;
    this->next = newLinkedList;
}

void LinkedList::addLinkedListItem(LinkedListItem *linkedListItem)
{
    LinkedList *newLinkedList = new LinkedList();
    newLinkedList->linkedListItem = linkedListItem;

    LinkedList *p = this;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = newLinkedList;
}

void LinkedList::insertLinkedListItemByIndex(LinkedListItem *linkedListItem, int index)
{
    // insert 进来的东西到达第 index 个位置
    // this->getLength() 为 0 时 index 属于 {1}
    // this->getLength() 为 1 时 index 属于 {1, 2}
    // 故 index 属于 [1, getLength() + 1]
    if (index >= 1 && index <= this->getLength() + 1)
    {
        LinkedList *p = this;
        LinkedList *newLinkedList = new LinkedList();
        newLinkedList->linkedListItem = linkedListItem;
        int i = 0;
        while (p != nullptr && (i < index - 1))
        {
            p = p->next;
            i++;
        }
        newLinkedList->next = p->next;
        p->next = newLinkedList;
    }
    else
    {
        cout << "输入的 index 越界\n";
        return;
    }
}

void LinkedList::addLinkedListItemsInHead(int n)
{
    for (int i = 0; i < n; i++)
    {
        int data = 0;
        cout << "请输入第 " + to_string(i + 1) + "/" + to_string(n) + " 个前插数据：";
        cin >> data;
        LinkedListItem *linkedListItem = new LinkedListItem(data);
        LinkedList::insertLinkedListItemByIndex(linkedListItem, 1);
    }
}

void LinkedList::addLinkedListItemsInEnd(int n)
{
    for (int i = 0; i < n; i++)
    {
        int data = 0;
        cout << "请输入第 " + to_string(i + 1) + "/" + to_string(n) + " 个后插数据：";
        cin >> data;
        LinkedListItem *linkedListItem = new LinkedListItem(data);
        LinkedList::insertLinkedListItemByIndex(linkedListItem, this->getLength() + 1);
    }
}

void LinkedList::replaceLinkedListItemByIndex(LinkedListItem *linkedListItem, int index)
{
    // replace 第 index 个位置
    // this->getLength() 为 0 时 index 属于 {}
    // this->getLength() 为 1 时 index 属于 {1}
    // 故 index 属于 [1, getLength()]
    if (index >= 1 && index <= this->getLength())
    {
        LinkedList *p = this;
        int i = 0;
        while ((p->next != nullptr) && (i < index - 1))
        {
            p = p->next;
            i++;
        }
        p->next->linkedListItem = linkedListItem;
    }
    else
    {
        cout << "输入的 index 越界\n";
        return;
    }
}

int LinkedList::searchLinkedListItemGetIndex(LinkedListItem *inkedListItem)
{
    LinkedList *p = this;
    int i = 1;
    while (p->next != nullptr)
    {
        if (p->next->linkedListItem->getLinkedListItemJson() == linkedListItem->getLinkedListItemJson())
        {
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}

void LinkedList::deleteLinkedListItemByIndex(int index)
{
    // delete 第 index 个位置
    // this->getLength() 为 0 时 index 属于 {}
    // this->getLength() 为 1 时 index 属于 {1}
    // 故 index 属于 [1, getLength()]
    if (index >= 1 && index <= this->getLength())
    {
        LinkedList *p = this;
        int i = 0;
        while ((p->next != nullptr) && (i < index - 1))
        {
            p = p->next;
            i++;
        }
        LinkedList *q = p->next;
        p->next = q->next;
        delete q;
    }
    else
    {
        cout << "输入的 index 越界\n";
        return;
    }
}

int LinkedList::getLength()
{
    int length = 0;
    LinkedList *p = this;
    while (p->next != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}

string LinkedList::getLinkedListJson()
{
    string str = "[";
    LinkedList *p = this->next;
    if (p != nullptr)
    {
        str += p->linkedListItem->getLinkedListItemJson();
        while (p->next != nullptr)
        {
            str += ", " + p->next->linkedListItem->getLinkedListItemJson();
            p = p->next;
        }
    }
    return str + "]";
}
