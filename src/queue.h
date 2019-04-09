#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


class Queue {
    unsigned int *queue;
    int head;
    int tail;
    int size;

public:
    Queue (int size);

    Queue (const Queue &q);

    ~Queue ();

    Queue& operator=(const Queue &q);

    int push (int element);

    int pop();

    int read();

    int length();

    void print();
};


#endif //QUEUE_QUEUE_H
