#include <iostream>
#include "heap.h"

int main() {
  // Create a 3-ary heap using default comparator (std::less -> min-heap)
  Heap<int> h(3);

  std::cout << "Pushing elements...\n";
  h.push(10);
  std::cout << "just pushed back 10" << std::endl;
  h.print_heap();
  h.push(4);
  std::cout << "just pushed back 4" << std::endl;
  h.print_heap();
  h.push(15);
  std::cout << "just pushed back 15" << std::endl;
  h.print_heap();
  h.push(7);
  std::cout << "just pushed back 7" << std::endl;
  h.print_heap();
  h.push(2);
  std::cout << "just pushed back 2" << std::endl;
  h.print_heap();
  h.push(20);
  std::cout << "just pushed back 20" << std::endl;
  h.print_heap();

  std::cout << "Heap size after pushes: " << h.size() << std::endl;

  std::cout << "Top element: " << h.top() << std::endl;

  

  std::cout << "Popping elements...\n";
  while(!h.empty()) {
    std::cout << "Top = " << h.top() << std::endl;
    h.pop();
    h.print_heap();
  }

  std::cout << "Heap empty? " << (h.empty() ? "yes" : "no") << std::endl;

  // Try with a custom comparator for max-heap
  std::cout << "\nTesting max-heap behavior...\n";
  Heap<int, std::greater<int>> maxHeap(3);
  maxHeap.push(10);
  maxHeap.push(4);
  maxHeap.push(15);
  maxHeap.push(7);
  maxHeap.push(2);
  maxHeap.push(20);

  std::cout << "Top element (should be largest): " << maxHeap.top() << std::endl;

  while(!maxHeap.empty()) {
    std::cout << "Top = " << maxHeap.top() << std::endl;
    maxHeap.pop();
  }

  return 0;
}