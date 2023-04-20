#include "DataStructure.h"

#include <iostream>
#include <string>
using namespace std;

TreeItem::TreeItem()
{
    this->data = 0;
};

TreeItem::TreeItem(int data)
{
    this->data = data;
};

void TreeItem::setData(int data)
{
    this->data = data;
}

string TreeItem::getTreeItemJson()
{
    return "{\"data\": " + to_string(this->data) + "}";
}

Tree::Tree(TreeItem *treeItem)
{
    this->leftTree = nullptr;
    this->rightTree = nullptr;
    this->treeItem = treeItem;
}

void Tree::firstPrint()
{
    cout << (this->treeItem)->getTreeItemJson();
    if (this->leftTree != nullptr)
    {
        leftTree->firstPrint();
    }
    if (this->rightTree != nullptr)
    {
        rightTree->firstPrint();
    }
}

void Tree::middlePrint()
{

    if (this->leftTree != nullptr)
    {
        leftTree->middlePrint();
    }
    cout << (this->treeItem)->getTreeItemJson();
    if (this->rightTree != nullptr)
    {
        rightTree->middlePrint();
    }
}

void Tree::endPrint()
{
    if (this->leftTree != nullptr)
    {
        leftTree->endPrint();
    }

    if (this->rightTree != nullptr)
    {
        rightTree->endPrint();
    }
    cout << (this->treeItem)->getTreeItemJson();
}

void Tree::swapLeftRight()
{
    Tree *temp = this->rightTree;
    this->rightTree = this->leftTree;
    this->leftTree = temp;
    if (this->leftTree != nullptr)
    {
        this->leftTree->swapLeftRight();
    }
    if (this->rightTree != nullptr)
    {
        this->rightTree->swapLeftRight();
    }
}
