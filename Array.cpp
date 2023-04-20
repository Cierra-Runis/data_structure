#include "DataStructure.h"

#include <iostream>
#include <string>
using namespace std;

ArrayItem::ArrayItem()
{
    this->id = 0;
}

ArrayItem::ArrayItem(int id)
{
    this->id = id;
}

string ArrayItem::getStr()
{
    string str = "[";
    str += "{\"id\": " + to_string(id) + "}";
    str += "]";
    return str;
}

Array::Array()
{
    this->length = 0;
}

void Array::addArrayItem(ArrayItem *ArrayItem)
{
    if (length + 1 > MAX_LENGTH)
    {
        cout << "线性表已达最大长度，不能再添加元素\n";
        return;
    }
    else
    {
        this->arrayItems[length++].id = ArrayItem->id;
    }
}

void Array::insertArrayItem(ArrayItem *ArrayItem, int index)
{
    index--;
    if (index < 0 || index > this->length || length + 1 > MAX_LENGTH)
    {
        cout << "输入的 index 越界或线性表已达最大长度，不能再添加元素\n";
        return;
    }
    else
    {
        for (int i = length; i > index; i--)
        {
            this->arrayItems[i].id = this->arrayItems[i - 1].id;
        }
        this->arrayItems[index].id = ArrayItem->id;
        length++;
    }
}

void Array::deleteArrayItem(int index)
{
    index--;
    if (index < 0 || index > this->length - 1)
    {
        cout << "输入的 index 越界\n";
        return;
    }
    else
    {
        for (int i = index; i < length - 1; i++)
        {
            this->arrayItems[i].id = this->arrayItems[i + 1].id;
        }
        length--;
    }
}

int Array::searchArrayItem(int id)
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->arrayItems[i].id == id)
        {
            return i + 1;
        }
    }
    return -1;
}

string Array::getStr()
{
    string str = "[";
    for (int i = 0; i < this->length; i++)
    {
        str += this->arrayItems[i].getStr() + ((i != this->length - 1) ? ", " : "");
    }
    str += "]";
    return str;
}
