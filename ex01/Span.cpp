#include "Span.hpp"

Span::Span() {
    std::cout << GREEN << "Span default constructor called\n" << RESET << std::endl;
}

Span::Span(const Span& other) {
    *this = other;
    std::cout << GREEN << "Span copy constructor called\n" << RESET << std::endl;
}

Span::~Span() {
    std::cout << RED << "Span destructor called\n" << RESET << std::endl;
}

Span& Span::operator=(const Span& other) {
    std::cout << YELLOW << "Span assignment operator called\n" << RESET << std::endl;
    if (this != &other) {
        // assignment code here
    }
    return *this;
}