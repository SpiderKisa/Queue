#include <iostream>
#include "src/queue.h"

using namespace std;

int main() {
    Queue q(10);
    for (int i = 0; i < 5; i++){
        q.push(i);
    }
    for (int i = 0; i < 5; i++){
        cout << q.length()<<endl;
        q.pop();
        q.push(i);
        q.push(i);
    }
    q.read();
    q.pop();
    return 0;
}