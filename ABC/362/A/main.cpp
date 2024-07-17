#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <map>

int main() {
  int R, G, B;
  std::cin >> R >> G >> B;

  std::string Color;
  std::cin >> Color;

  if (Color == "Blue") {
    std::cout << std::min(R, G) << std::endl;
  }
  else if (Color == "Green") {
    std::cout << std::min(R, B) << std::endl;
  }
  else {
    std::cout << std::min(G, B) << std::endl;
  }
  return 0;
}