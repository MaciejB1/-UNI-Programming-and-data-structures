#include "train.h"

Train::Train()
{

}

Train::~Train()
{

}

void Train::add(int number)
{
    Box *newBox;
    newBox = new Box(number);
    if (head == nullptr)
        head = newBox;
    else
        tail->next = newBox;
    tail = newBox;
    listCount++;
}

void Train::writeObj()
{
    Box *runner = head;
    while (runner != nullptr)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
    cout << endl;
}

void Train::deleteTrio(int K)     // K is parameter from task
{
    int average;
    Box *runner = head;
    Box *killer;
    Box *assistant = head;          //assistant is for changing pointer from previous trio
    for (int j = 0; j < listCount/3; ++j)
    {
        {
            average = 0;
            killer = runner;
            for (int i = 0; i < 3; ++i)
            {
                average = average + runner->data;
                runner = runner->next;
            }

            average = average/3;

            if (average < K)                            // remove the first element in trio
            {
                if (killer == head) head = killer->next;
                if (j > 0) assistant->next = killer->next;
                assistant = killer->next->next;
                delete killer;
            } else                                      // remove the second and the third element in trio
            {
                assistant->next = killer;
                assistant = killer;
                killer = assistant->next->next;
                delete killer;
                killer = assistant->next;
                delete killer;
            }
        }
    }
}







