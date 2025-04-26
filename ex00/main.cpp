#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

// Test functions for each container type
void testVector(std::vector<int>& v, int x) {
    std::cout << "Vector: searching " << x << " ... ";
    try {
        std::vector<int>::iterator it = easyfind(v, x);
        int index = it - v.begin();
        std::cout << "found at index " << index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "not found (" << e.what() << ")" << std::endl;
    }
}

void testList(std::list<int>& l, int x) {
    std::cout << "List:   searching " << x << " ... ";
    try {
        std::list<int>::iterator it = easyfind(l, x);
        int index = 0;
        for (std::list<int>::iterator jt = l.begin(); jt != it; ++jt)
            ++index;
        std::cout << "found at position " << index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "not found (" << e.what() << ")" << std::endl;
    }
}

void testDeque(std::deque<int>& d, int x) {
    std::cout << "Deque:  searching " << x << " ... ";
    try {
        std::deque<int>::iterator it = easyfind(d, x);
        int index = it - d.begin();
        std::cout << "found at index " << index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "not found (" << e.what() << ")" << std::endl;
    }
}

int main() {
    std::vector<int> v;
    std::list<int>   l;
    std::deque<int>  d;

    // populate containers
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i * 10);
        l.push_back(i * 100);
        d.push_back(i * 1000);
    }

    // run tests
    std::cout << GREEN << std::endl;
    testVector(v, 30);
    testVector(v, 99);
    std::cout << YELLOW << std::endl;
    testList(l, 300);
    testList(l, 1234);
    std::cout << BLUE << std::endl;
    testDeque(d, 3000);
    testDeque(d, -1);
    std::cout << RESET << std::endl;
    return 0;
}