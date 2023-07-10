#include <iostream>
#include "../lib/CCircularBuffer.h"

int main() {
    CCircularBuffer<int> buffer = {1, 2, 3, 4, 5, 6};
    std::cout << buffer.max_size();
    return 0;
}
