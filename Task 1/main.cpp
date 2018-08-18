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


    cout << endl << "------------------------ TEST 2 ----------------------------" << endl << endl;

    Train test2;

    test2.add(9);
    test2.add(9);
    test2.add(9);
    test2.add(8);
    test2.add(8);
    test2.add(6);
    test2.add(6);
    test2.add(6);
    test2.add(6);
    test2.add(5);
    test2.add(5);
    test2.add(5);
    test2.add(5);
    test2.add(2);
    test2.add(2);
    test2.add(1);
    test2.add(1);

    test2.writeObj();
    test2.move();
    test2.writeObj();


    return 0;
}