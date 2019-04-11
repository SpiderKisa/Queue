#include <iostream>
#include "queue.h"


Queue::Queue(int size) {
    if (size < 2){
        this->size = 11;
    } else {
        this->size = size + 1;
    }
    head = 0;
    tail = 0;
    queue = new unsigned int [this->size];
}


Queue::Queue(const Queue &q): size(q.size), head(q.head), tail(q.tail) {
    queue = new unsigned int [size];
    int  current(head);
    while (current != tail){
        queue[current] = q.queue[current];
        current = (current + 1) % size;
    }
}


Queue::~Queue() {
    delete [] queue;
}


Queue& Queue::operator=(const Queue &q) {
    if (this == &q){
        return *this;
    }
    int i(0), current;
    if (size > q.size){
        current = q.head;
        while (current != q.tail){
            queue[i] = q.queue[current];
            i++;
            current = (current + 1) % q.size;
        }
        head = 0;
        tail = i;
        return *this;
    }
    if (size < q.size){
        current = q.head;
        while (i < size - 1 && current != q.tail){
            queue[i] = q.queue[current];
            i++;
            current = (current + 1) % q.size;
        }
        head = 0;
        tail = i;
        return *this;
    }
    if (size == q.size){
        for (i = 0; i < size; queue[i] = q.queue[i], i++);
        head = q.head;
        tail = q.tail;
        return *this;
    }

}


int Queue::push (unsigned int element){
    if ((tail + 1) % size == head){
        return -1;
    }
    queue[tail] = element;
    tail = (tail + 1) % size;
    return 0;
}


int Queue::pop() {
    if (head == tail){
        return -1;
    }
    int element = queue[head];
    head = (head + 1) % size;
    return element;
}


int Queue::length() {
    if (head == tail){
        return 0;
    }
    if (head < tail){
        return (tail - head);
    }
    if (head > tail){
        return (tail + size - head);
    }
}

int Queue::read() {
    if (head == tail){
        return -1;
    }
    return queue[head];
}

void Queue::print() {
    int  current(head);
    while (current != tail){
        printf("%d ", queue[current]);
        current = (current + 1) % size;
    }
    printf("\n");
}