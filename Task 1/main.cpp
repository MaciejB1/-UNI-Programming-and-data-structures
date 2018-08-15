#include "train.h"

int main()
{
    Train test;     //Example from task

    test.add(7);
    test.add(6);
    test.add(6);

    test.add(3);
    test.add(3);
    test.add(3);

    test.add(2);
    test.add(1);
    test.add(1);

    test.add(1);
    test.add(1);

    test.writeObj();

    test.deleteTrio(3);

    test.writeObj();

    return 0;
}