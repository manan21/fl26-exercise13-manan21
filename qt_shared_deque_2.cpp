// qt_shared_deque_2.cpp
#include <iostream>
#include <cassert>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;

  constexpr std::size_t bufferCapacity = 100;
  buffer.create(bufferCapacity);

  while (buffer.getCount() < bufferCapacity) {
    int value;
    std::cout << "$> ";
    if (!(std::cin >> value)) {
      if (!std::cin.eof()) {
        std::cerr << "Invalid input; expected an integer." << std::endl;
      }
      break;
    }

    if (!buffer.enqueue(value)) {
      std::cout << "Buffer is full." << std::endl;
      break;
    }
    std::cout << "Enqueued: " << value << std::endl;
  }

  return 0;
}
