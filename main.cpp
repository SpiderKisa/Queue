#include <iostream>
#include "src/queue.h"

using namespace std;

int main() {
    Queue q(5);
    for (int i = 0; i < 5; i++){
        q.push(i);
    } for (int i = 0; i < 5; i++){
        cout << q.read() << endl;
        q.pop();
    }
    q.read();
    q.pop();
    return 0;
}