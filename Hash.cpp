#include "DataStructure.h"

#include <iostream>
using namespace std;
/*
以除留余数法构建哈希函数
哈希函数为H（key）=key%13
*/

// 哈希函数
int HashTable::HashFunction(int key)
{
    return key % 13;
}

// 哈希表初始化
void HashTable::HashInit()
{
    if (0 == m_length)
    {
        return;
    }
    else
    {
        for (int i = 0; i < m_length; i++)
        {
            Array[i].head = nullptr; // 每个哈希地址中的head域为空，表示暂无存放关键字
        }
    }
}

// 创建哈希表
void HashTable::CreateHashTable()
{
    int key;
    int address; // 经过哈希函数变换得到的哈希地址
    HashNode *head = nullptr;
    for (int i = 0; i < m_length - 1; i++)
    {
        cin >> key;
        address = HashFunction(key);
        head = Array[address].head; // 定义临时HashNode指针,保存哈希地址中的头结点
        if (!head)                  // 经由哈希函数得到的哈希地址暂未存放任何关键字
        {
            Array[address].head = new HashNode;  // 分配一个新的哈希链表结点
            Array[address].head->key = key;      // 当前结点数据域赋值为此关键字
            Array[address].head->node = nullptr; // 当前结点指针域赋值为空
        }
        else // 经由哈希函数得到的哈希地址已存放关键字，则当前关键字存放到当前地址中的哈希链表中
        {
            if (head->key > key)
            {
                HashNode *pnew = new HashNode; // 开辟一段空间
                pnew->key = key;               // 赋值
                pnew->node = head;             // 当前结点指向第一个结点
                Array[address].head = pnew;    // 头指针指向当前结点
            }
            else
            {
                // 比较下一个关键字
                while (head->node && head->node->key < key)
                {
                    head = head->node;
                }
                // 退出循环，如果head的下一个结点不为空，说明head->node->key>key，key插在head之前
                if (head->node)
                {
                    HashNode *pnew = new HashNode;
                    pnew->key = key;
                    pnew->node = head->node;
                    head->node = pnew;
                }
                else // head的下一个结点为空，key直接插在head之后
                {
                    head->node = new HashNode;
                    head->node->key = key;
                    head->node->node = nullptr;
                }
            }
        }
    }
}

// 打印哈希表
void HashTable::PrintHashTable()
{
    // 循环遍历哈希表
    for (int i = 0; i < m_length; i++)
    {
        // 当前哈希地址为空，输出NULL
        if (!Array[i].head)
        {
            cout << "Array[" << i << "]"
                 << "->"
                 << "NULL" << endl;
        }
        else
        {
            HashNode *p = Array[i].head; // 定义临时指针保存哈希地址中的头节点
            cout << "Array[" << i << "]"
                 << "->";
            while (p)
            {
                cout << p->key << "->";
                p = p->node; // 指向下一个关键字结点
            }
            cout << "NULL" << endl;
        }
    }
}
