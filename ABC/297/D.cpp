#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  long long A, B;
  std::cin >> A >> B;

  long long tmp;
  if (A < B) {
    tmp = B;
    B = A;
    A = tmp;
  }

  long long count = 0;
  long long q, r;
  // std::cout << "(" << A << "," << B << ")" << std::endl;
  while (B != 0) {
    q = A/B; 
    r = A%B;

    count += q;

    A = B;
    B = r;
    // std::cout << "(" << A << "," << B << ")" << std::endl;
  }

  std::cout << count-1 << std::endl;

  return 0;
}