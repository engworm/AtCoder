#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  if (n%2 == 0) {
    std::cout << n-1 << std::endl;
  }
  else {
    std::cout << n+1 << std::endl;
  }

  return 0;
}