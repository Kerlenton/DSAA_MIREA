#ifndef __DOUBLY_LIST__
#define __DOUBLY_LIST__
#include <iostream>

class Node {
private:
    int id;
    int group;
    int grade;
    Node* next;
    Node* prev;
    friend class doublyList;

public:
    Node(int id, int group, int grade, Node* next, Node* prev);
    Node(const Node& node);
    ~Node();
    void print();
};

class doublyList {
private:
    Node* head;
    Node* tail;
    
public:
    doublyList();
    ~doublyList();
    void pushBack(Node node);
    void pushFront(Node node);
    void push(Node node);
    void delBack();
    void delFront();
    void del(int group);
    doublyList newList();
    void printRight();
    void printLeft();;
};

#endif
