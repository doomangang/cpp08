#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <stdexcept>
#include <iterator>
#include <limits>

/* Color Sets */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;250m"

class Span {
private:
    /* member attributes */
    unsigned int _maxSize;
    std::multiset<int> _data;

    Span();

public:
    /* Orthodox Canonical Form (OCF) */
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    /* getter & setter */

    /* additional methods */
    void    addNumber(int x);

    template <typename InputIter>
    void    addNumber(InputIter first, InputIter last) {
        typename std::iterator_traits<InputIter>::difference_type cnt = std::distance(first, last);
        if (cnt < 0)
            throw std::invalid_argument("Invalid range");

        if (_data.size() + static_cast<size_t>(cnt) > _maxSize)
            throw std::out_of_range("Span capacity exceeded");

        _data.insert(first, last);
    }

    unsigned int  shortestSpan() const;
    unsigned int  longestSpan() const;
    /* exception classes */
};

/* operators */
#endif