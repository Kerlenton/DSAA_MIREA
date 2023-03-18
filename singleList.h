#ifndef __SINGLE_LIST__
#define __SINGLE_LIST__
#include <iostream>
#include <map>

class singleList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    singleList();
    ~singleList();
    void push(int num);
    void print();
    void mark(std::map<int, bool>& table);
};

singleList makeNew(singleList& first, singleList& second);

#endif
