#ifndef __STACK__
#define __STACK__
#include <vector>
#include <list>

class Stack1 {
private:
    std::vector< std::pair<int, int> > stack;
    
public:
    void push(std::pair<int, int> x);
    void pop();
    std::pair<int, int> top();
    bool empty();
};

class Stack2 {
private:
    std::list< std::pair<int, int> > stack;
    
public:
    void push(std::pair<int, int> x);
    void pop();
    std::pair<int, int> top();
    bool empty();
};

#endif
