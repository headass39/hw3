#include "stack.h"
#include <iostream>

using namespace std;

int main(){
  Stack<int> s;
  std::cout << "acabé de crear mi objeto 'stack' de integeres" << std:: endl;
  s.push(5);
  s.push(8);
  s.push(100);
  std::cout << "just pushed back some shi: 5, 8, 100 (in that order)" << std::endl;
  int x = s.top();
  std::cout << "top = " << x << std::endl;
  s.pop();
  s.pop();
  std::cout << "popped twice: s.size()=" << s.size() << " s.empty()=" << s.empty() <<std::endl;
  std::cout << "s.top=" << s.top() << std::endl;
  
  return 0;
}