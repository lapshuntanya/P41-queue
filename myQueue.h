//
// Created by Lapshun Tetiana on 17.06.2025.
//

#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
using std::cout;
using std::endl;

namespace myQueue {
    template <typename T>
    class Node {
    public:
        T info;
        Node* next;
        Node* prev;

        Node(T value) {
            info = value;
            next = prev = nullptr;
        }
    };

    //Queue - FIFO = first in, first out
    template <typename U>
    class Queue {
    protected:
        Node<U>* head;
        Node<U>* current;
    public:
        Queue() {
            head = current = nullptr;
        }
        ~Queue() {
            while (!isEmpty()) {
                pop_front();
            }
        }//реалізація

        bool isEmpty()const {
            return ( head == nullptr || current == nullptr );
        }//реалізація
        U first()const {
            if (isEmpty()) {throw "Queue is empty";}
            return head->info;
        }//реалізація

        void push_back(U value) {
            Node<U>* el = new Node<U>(value);

            if (isEmpty()) { head = current = el;}
            else {
                current->next = el;
                el->prev = current;
                current = el;
            }
        }//реалізація
        void pop_front() {
            if (isEmpty()) { throw "Queue is empty";}

            if (head == current) {//залишився один вузол
                delete head;
                head = nullptr;
                current = nullptr;
            }else {
                head = head->next;
                delete  head->prev;
                head->prev = nullptr;
            }
        }//реалізація

        void show()const {
            if (isEmpty()) {
                cout << "Queue is empty!\n";
            }
            int i = 0;
            Node<U>* p = head;
            while (p != nullptr) {
                cout << ++i << ". " << p->info << "\n";
                p = p->next;
            }
        }//реалізація
    };
}

#endif //MYQUEUE_H
