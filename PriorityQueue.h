//
// Created by Lapshun Tetiana on 17.06.2025.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "myQueue.h"

namespace myQueue {

    template<typename U>
    class PriorityQueue: public Queue<U>
    {
    public:
        void push_back(U value) {
            Node<U>* el = new Node<U>(value);

            if (Queue<U>::isEmpty()) {
                Queue<U>::head = Queue<U>::current = el;
            }
            else {
                Node<U>*p = Queue<U>::head;
                while (p != nullptr && value < p->info) {
                    p = p->next;
                }

                if (p == Queue<U>::head) {
                    el->next = Queue<U>::head;
                    Queue<U>::head->prev = el;
                    Queue<U>::head = el;
                }
                else if (p == nullptr) {
                    Queue<U>::current->next = el;
                    el->prev = Queue<U>::current;
                    Queue<U>::current = el;
                }
                else {
                    (p->prev)->next = el;
                    el->prev =  (p->prev);

                    el->next = p;
                    p->prev = el;
                }
            }
        }
    };


    // ?? 100 95 60 44 11          200
    // 200 100 95 60 44 11  ??        5
    // 100 95 60  ?? 44 11  5        57

}

#endif //PRIORITYQUEUE_H
