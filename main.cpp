#include <iostream>
#include "src/queue.h"

using namespace std;

int main() {
    Queue q1(14);
    //cout << "q1: "<< q1.length();
    Queue q2(9);
    Queue q3 (4);
  //  Queue q4 (14);
    Queue q(q1);
    for (int i = 0; i < 16; i++){
        q1.push(i);
        q2.push(i%2);

    }
    cout << "q1: "<< q1.length()<<endl;
    q1.print();

    cout << "q2: "<< q2.length()<<endl;
    q2.print();

    q3=q2=q1=q1;

    cout << "q1: "<< q1.length()<<endl;
    q1.print();

    cout << "q2: "<< q2.length()<<endl;
    q2.print();
    cout << "q3: "<< q3.length()<<endl;
    q3.print();




    for (int i = 0; i < 10; i++){
       // cout <<  q1.read() << " ";
        q1.pop();
        q2.pop();
    }

    cout << "q1: "<< q1.length()<<endl;
    q1.print();

    cout << "q2: "<< q2.length()<<endl;
    q2.print();

    q3=q2=q1=q1;

    cout << "q1: "<< q1.length()<<endl;
    q1.print();

    cout << "q2: "<< q2.length()<<endl;
    q2.print();
    cout << "q3: "<< q3.length()<<endl;
    q3.print();
    Queue q4 (q3);
    cout << "q3: "<< q3.length()<<endl;
    q3.print();
    return 0;
}