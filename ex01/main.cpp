// // main.cpp
// #include "Span.hpp"
// #include <vector>
// #include <iostream>

// int main() {
//     // capacity = 10
//     Span sp(10);

//     // 1) single-value 삽입
//     sp.addNumber(42);
//     sp.addNumber(7);

//     // 2) 벡터에 담긴 값들을 한꺼번에 삽입
//     std::vector<int> v;
//     v.push_back(15);
//     v.push_back(23);
//     v.push_back(9);

//     // iterator 범위로 삽입
//     sp.addNumber(v.begin(), v.end());

//     // 현재 저장된 값들: {42, 7, 15, 23, 9}
//     // 정렬하면              {7, 9, 15, 23, 42}

//     std::cout << "shortestSpan = "
//               << sp.shortestSpan() << std::endl;
//     // 9-7 = 2

//     std::cout << "longestSpan = "
//               << sp.longestSpan() << std::endl;
//     // 42-7 = 35

//     return 0;
// }


// main.cpp
#include <iostream>
#include <vector>
#include <ctime>       // clock(), CLOCKS_PER_SEC
#include <cstdlib>     // rand(), srand()
#include "Span.hpp"

int main() {
    const unsigned int N = 10000;
    Span sp(N);

    // 1) 테스트용 숫자 준비: 0 ~ RAND_MAX 사이 난수 10_000개
    std::vector<int> v;
    v.reserve(N);
    std::srand(static_cast<unsigned>(std::time(0)));
    for (unsigned int i = 0; i < N; ++i) {
        v.push_back(std::rand());
    }

    // 2) 범위 삽입 시간 측정
    std::clock_t t1 = std::clock();
    sp.addNumber(v.begin(), v.end());
    std::clock_t t2 = std::clock();
    std::cout << "Insertion time: "
              << double(t2 - t1) / CLOCKS_PER_SEC << " sec\n";

    // 3) shortestSpan() 측정
    t1 = std::clock();
    unsigned int s = sp.shortestSpan();
    t2 = std::clock();
    std::cout << "shortestSpan: " << s
              << " (calc time: " << double(t2 - t1) / CLOCKS_PER_SEC
              << " sec)\n";

    // 4) longestSpan() 측정
    t1 = std::clock();
    unsigned int l = sp.longestSpan();
    t2 = std::clock();
    std::cout << "longestSpan: " << l
              << " (calc time: " << double(t2 - t1) / CLOCKS_PER_SEC
              << " sec)\n";

    return 0;
}
