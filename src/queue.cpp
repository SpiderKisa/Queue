#include <iostream>
#include "queue.h"
#define FULL 1



Queue::Queue(int size) {
    if (size < 2){
        this->size = 11;
    } else {
        this->size = size + 1;
    }
    head = 0;
    tail = 0;
    queue = new int [this->size];
}


Queue::Queue(const Queue &q): size(q.size), head(q.head), tail(q.tail) {
    queue = new int [size];
}


Queue::~Queue() {
    delete [] queue;
}


Queue& Queue::operator=(const Queue &q) {
    if (this == &q){
        return *this;
    }
    int i, current;
    if (size > q.size){
        i = 0;
        current = q.head;
        while (current != q.tail){
            queue[i] = q.queue[current];
            i++;
            current++;
            if (current == q.size - 1){
                current = 0;
            }
        }
        head = 0;
        tail = i + 1;
    }
    if (size < q.size){
        i = 0;
        current = q.head;
        while (i < size - 1 && current != q.tail){
            queue[i] = q.queue[current];
            i++;
            current++;
            if (current == q.size - 1){
                current = 0;
            }
        }
        head = 0;
        tail = i + 1;
    }
    if (size == q.size){
        for (i = 0; i < size; queue[i] = q.queue[i], i++);
        head = q.head;
        tail = q.tail;
    }
    return *this;
}


int Queue::push (int element){
    if ((head == size - 1 && tail == 1) || (head == tail + 2) || (head == size - 2 && tail == 0)){
        return FULL;
    }
    queue[tail] = element;
    if (tail < size - 1){
        tail++;
    }
    if (tail == size - 1){
        tail = 0;
    }
}


int Queue::pop() { // ЧТО ВОЗВРАЩАТЬ, КОГДА ОЧЕРЕДЬ ПУСТА?

}


int Queue::length() {
    if (head == tail){
        return 0;
    }
    if (head < tail){
        return (tail - head + 1);
    }
    if (head > tail){
        return (tail + (size - head - 1));
    }
}

int Queue::read() { // ЧТО ВОЗВРАЩАТЬ, КОГДА ОЧЕРЕДЬ ПУСТА?
}

void Queue::print() {
    int current = head;
    while (current != tail){
        printf("%d ", queue[current]);
        current++;
        if (current == size - 1){
            current = 0;
        }
    }
    printf("\n");
}