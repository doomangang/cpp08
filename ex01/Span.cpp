#include "Span.hpp"

//ocf

Span::Span() : _maxSize(0), _data() {}

Span::Span(unsigned int N) : _maxSize(N), _data() {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

// methods

void Span::addNumber(int x) {
    if (_data.size() >= _maxSize)
        throw std::out_of_range("Span is already full");
    _data.insert(x);
}

unsigned int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Data too small for a span");
    
    std::multiset<int>::const_iterator it = _data.begin();
    std::multiset<int>::const_iterator prev = it++;

    unsigned int shortest = std::numeric_limits<unsigned int>::max();

    for (; it != _data.end() ; ++it, ++prev) {
        unsigned int diff = static_cast<unsigned int>(*it - *prev);
        if (diff < shortest) shortest = diff;
    }
    return shortest;
}

unsigned int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Data too small for a span");
    return static_cast<unsigned int>(*(_data.rbegin()) - *(_data.begin()));
}