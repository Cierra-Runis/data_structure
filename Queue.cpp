#include "DataStructure.h"

#include <queue>
using namespace std;

QueueItem::QueueItem()
{
    this->data = 0;
}

QueueItem::QueueItem(int data)
{
    this->data = data;
};

void QueueItem::setData(int data)
{
    this->data = data;
}

string QueueItem::getQueueItemJson()
{
    return "{\"data\": " + to_string(this->data) + "}";
}

string QueueItem::getQueueJsonFromFrontToBack(queue<QueueItem> myQueue)
{
    string result = "[";
    while (!myQueue.empty())
    {
        result += myQueue.front().getQueueItemJson();
        myQueue.pop();
        if (!myQueue.empty())
            result += ", ";
    }
    return result + "]";
}
