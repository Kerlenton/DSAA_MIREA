#include <iostream>
#include "stack.h"
void Stack1::push(std::pair<int, int> x) {
    stack.push_back(x);
}

void Stack1::pop() {
    stack.pop_back();
}

std::pair<int, int> Stack1::top() {
    return stack.back();
}

bool Stack1::empty() {
    return stack.empty();
}

void Stack2::push(std::pair<int, int> x) {
    stack.push_back(x);
}

void Stack2::pop() {
    stack.pop_back();
}

std::pair<int, int> Stack2::top() {
    return stack.back();
}

bool Stack2::empty() {
    return stack.empty();
}

int main() {
    int n; std::cin >> n;
    Stack1 st;
    int i = 0;
    std::vector<int> ans(n, n);

    while (n--) {
        int x; std::cin >> x;

        while (!st.empty() && st.top().first < x) {
            //std::cout << "aaa";
            ans[st.top().second] = i;
            st.pop();
        }

        st.push(std::make_pair(x, i));
        ++i;
    }

    int k = 0;
    int c = 0;

    while (k < ans.size()) {
        c += 1;
        k = ans[k];    
    }

    std::cout << c << std::endl;

    return 0;
}
