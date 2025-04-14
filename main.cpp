#include "Bin_heap.h"
#include "Parser.h"
#include <iostream>
#include <print>


int main()
{
    Parser p{"../big.txt"};
    auto forty = p.get_forty_longest();

    for (const auto& x : forty) std::println("{}: {}", x.first, x.second);

    return 0;
}

