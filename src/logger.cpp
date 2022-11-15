#include "levels.hpp"
#include "threading.hpp"
#include <iostream>

int main() {
  #if CXX_VERSION == 17
  std::cout << "17" <<std::endl;
  #endif
  return 0;
}