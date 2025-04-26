#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <exception>
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
public:
    /* Orthodox Canonical Form (OCF) */
    Span();
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    /* getter & setter */

    /* additional methods */
    void    addNumber();
    void    addNumbers();
    unsigned int  shortestSpan();
    unsigned int  longestSpan();
    /* exception classes */
};

/* operators */
#endif