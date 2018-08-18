#ifndef TASK_1_TRAIN_H
#define TASK_1_TRAIN_H

#include <iostream>
using namespace std;

struct Train
{
private:
    struct Box
    {
        int data;
        Box *next;
        Box (int d, Box *n = nullptr)
        {
            data = d;
            next = n;
        }
    };
    Box *head = nullptr;    //of list
    Box *tail = nullptr;

public:
    int listCount = 0;
    Train();
    ~Train();
    void add(int number);
    void deleteTrio(int K);
    void writeObj();
    void move();
};



#endif //TASK_1_TRAIN_H
