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

bool tyokkaku(std::pair<int, int> vec1, std::pair<int, int> vec2) {
  bool b = false;
  if ((vec1.first*vec2.first) + (vec1.second*vec2.second) == 0) {
    b = true;
  }
  return b;
}

int main() {
  std::pair<int, int> a, b, c;
  std::cin >> a.first >> a.second;
  std::cin >> b.first >> b.second;
  std::cin >> c.first >> c.second;

  std::pair<int, int> ab, ac, bc;
  ab.first = b.first - a.first;
  ab.second = b.second - a.second;

  ac.first = c.first - a.first;
  ac.second = c.second - a.second;

  bc.first = c.first - b.first;
  bc.second = c.second - b.second;

  if (tyokkaku(ab, ac) || tyokkaku(ac, bc) || tyokkaku(bc, ab)) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }


  return 0;
}