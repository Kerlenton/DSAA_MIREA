#include "singleList.h"

singleList::singleList() {
    head = nullptr;
}

singleList::~singleList() {
    Node* ptr = head;

    while (ptr) {
        Node* tmp = ptr;
        ptr = ptr->next;

        delete tmp;
    }
}

void singleList::push(int num) {
    Node* node = new Node;
    node->data = num;
    node->next = head;
    head = node;
}

void singleList::print() {
    Node* ptr = head;

    while (ptr) {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    std::cout << nullptr << '\n';
}

void singleList::mark(std::map<int, bool>& table) {
    Node* ptr = head;

    while (ptr) {
        table[ptr->data] = true;
        ptr = ptr->next;
    }
}

singleList makeNew(singleList& first, singleList& second) {
    std::map<int, bool> table;
    singleList list;

    first.mark(table);
    second.mark(table);
    
    for (std::map<int, bool>::iterator itr = table.begin(); itr != table.end(); itr++) {
        list.push(itr->first);    
    }

    return list;
}

int main() {
    singleList lst1, lst2;
    lst1.push(5);
    lst1.push(4);
    lst1.push(1);

    lst2.push(5);
    lst2.push(1);
    
    singleList lst = makeNew(lst1, lst2);
    lst.print();

    return 0;
}
