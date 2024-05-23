#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int a, b, c;
  std::string s;

  std::cin >> a >> b >> c;
  std::cin >> s;

  std::cout << a + b + c << ' ' << s << std::endl;

  return 0;
}