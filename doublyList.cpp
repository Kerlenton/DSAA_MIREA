#include "doublyList.h"

Node::Node(int id, int group, int grade, Node* next = nullptr, Node* prev = nullptr) {
    this->id = id;
    this->group = group;
    this->grade = grade;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(const Node& node): Node(node.id, node.group, node.grade, node.next, node.prev) {}
Node::~Node() {}

void Node::print() {
    std::cout << "(" << id << ", " << group << ", " << grade << ")\n";
}

doublyList::doublyList() {
    head = nullptr;
    tail = nullptr;
}

doublyList::~doublyList() {
    Node* ptr = head;

    while (ptr) {
        Node* tmp = ptr;
        ptr = ptr->next;

        delete tmp;
    }
}

void doublyList::pushBack(Node node) {
    Node* tmp = new Node(node);
    
    if (tail == nullptr) {
        head = tmp;
        tail = tmp;
    }

   else {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

void doublyList::pushFront(Node node) {
    Node* tmp = new Node(node);

    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    }

    else {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}

void doublyList::push(Node node)
{
    Node* tmp = new Node(node);

    if (head == nullptr) {
        pushFront(node);
        return;
    }
    
    Node* ptr = head;
    
    if (tmp->id <= ptr->id) {
        pushFront(node);
        return;
    }

    if (tmp->id > tail->id) {
        pushBack(node);
        return;
    }

    while (ptr && tmp->id > ptr->id) {
        ptr = ptr->next;
    }
    
    
    tmp->next = ptr;
    tmp->prev = ptr->prev;
    ptr->prev = tmp;
    ptr->prev->next = tmp;
}

void doublyList::delBack() {
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    else {
        tail->prev->next = nullptr;
        Node* tmp = tail;
        tail = tail->prev;
        delete tmp;
    }
}

void doublyList::delFront() {
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    else {
        head->next->prev = nullptr;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void doublyList::del(int group) {
    while (head != nullptr && head->group == group)
        this->delFront();

    while (tail != nullptr && tail->group == group)
        this->delBack();

    Node* tmp = head;

    while (tmp) {
        Node* ptr = tmp->next;

        if (tmp->group == group) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }

        tmp = ptr;
    }
    
}

doublyList doublyList::newList() {
    doublyList lst;

    while (head != nullptr && head->grade == 3) {
        lst.push(Node(head->id, head->group, head->grade));
        this->delFront();
    }

    while (tail != nullptr && tail->grade == 3) {
        lst.push(Node(tail->id, tail->group, tail->grade));
        this->delBack();
    }

    Node* tmp = head;

    while (tmp) {
        Node* ptr = tmp->next;

        if (tmp->grade == 3) {
            lst.push(Node(tmp->id, tmp->group, tmp->grade));
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }

        tmp = ptr;
    }

    return lst;
}

void doublyList::printRight() {
    std::cout << nullptr << " <-> ";

    Node* ptr = head;
    while (ptr) {
        std::cout << "(" << ptr->id << ", " << ptr->group << ", " << ptr->grade << ") <-> ";
        ptr = ptr->next;
    }

    std::cout << nullptr << '\n';
}

void doublyList::printLeft() {
    std::cout << nullptr << " <-> ";

    Node* ptr = tail;
    while (ptr) {
        std::cout << "(" << ptr->id << ", " << ptr->group << ", " << ptr->grade << ") <-> ";
        ptr = ptr->prev;
    }

    std::cout << nullptr << '\n';
}

int main() {
    doublyList lst;

    while (true) {
        std::cout << "1 - add node\n";
        std::cout << "2 - delete group\n";
        std::cout << "3 - create new\n";
        std::cout << "4 - print\n";
        int x; std::cin >> x;

        if (x == 1) {
            int id, group, grade;
            std::cout << "id -> ";
            std::cin >> id;
            std::cout << "group -> ";
            std::cin >> group;
            std::cout << "grade -> ";
            std::cin >> grade;

            lst.push(Node(id, group, grade));
        }

        else if (x == 2) {
            std::cout << "group -> ";
            int num; std::cin >> num;
            lst.del(num);
        }

        else if (x == 3) {
            doublyList lst2 = lst.newList();
            lst2.printRight();
        }

        else if (x == 4)
            lst.printRight();

        else
            break;
    }

    return 0;
}
