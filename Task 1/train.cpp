#include "train.h"

Train::Train()
{

}

Train::~Train()
{

}

void Train::add(int number)
{
    Box *runner;
    Box *assistant;
    Box *newBox = new Box (number);
    if(listCount == 0)
    {
        head = newBox;
        listCount++;
        return;
    }
    if (listCount == 1)
    {
        tail = newBox;
        if (head->data < tail->data)
        {
            runner = head;
            head = tail;
            tail = runner;
            head->next = tail;
            tail->next = nullptr;
        }
        head->next = tail;
        listCount++;
        return;
    }

    runner = head->next;
    assistant = head;

    while (runner != nullptr && listCount > 1)
    {
        if (number > head->data)
        {
            newBox->next = head;
            head = newBox;
            listCount++;
            break;
        } else if (number < tail->data || number == tail->data)
        {
            tail->next = newBox;
            tail = newBox;
            listCount++;
            break;
        } else if (runner->data <= number)
        {
            assistant->next = newBox;
            newBox->next = runner;
            listCount++;
            break;
        }
        runner = runner->next;
        assistant = assistant->next;
    }
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

void Train::move()   // it's not working well...
{
    Box *runner = head;
    Box *backRunner = head->next;
    Box *assistant1 = head->next;
    Box *assistant2;
    Box *assistant3 = tail;
    Box *assistant4;
    Box *lastMove = nullptr;

    for (int i = 0; i < listCount/2; ++i)
    {
        if (runner->data == runner->next->data)
        {
            if (i == 0) runner = runner->next->next;
            else
            {
                assistant2 = assistant1->next;
                assistant1->next = runner;
                assistant1 = runner->next;
                assistant1->next = assistant2;
                runner = runner->next->next;
                backRunner->next = runner;
            }
        } else
        {
            if (assistant3 == tail)
            {
                tail = runner->next;
                assistant4 = runner->next;
                assistant4->next = nullptr;
                lastMove = assistant4;
            }
            assistant4 = runner->next;
            if (lastMove != assistant4) assistant4->next = lastMove;
            lastMove = runner->next;
            assistant3->next = runner->next;
            backRunner = runner;
            runner->next = runner->next->next;
            runner = runner->next;
        }

    }
}









