#include "DataStructure.h"

#include <iostream>
using namespace std;

StackItem::StackItem()
{
    this->data = 0;
};

StackItem::StackItem(int data)
{
    this->data = data;
};

void StackItem::setData(int data)
{
    this->data = data;
}

string StackItem::getStackItemJson()
{
    return "{\"data\": " + to_string(this->data) + "}";
}

string StackItem::getStackJsonFromTopToBottom(stack<StackItem> myStack)
{
    string result = "[";
    while (!myStack.empty())
    {
        result += myStack.top().getStackItemJson();
        myStack.pop();
        if (!myStack.empty())
            result += ", ";
    }
    return result + "]";
}
