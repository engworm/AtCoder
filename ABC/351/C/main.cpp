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

int main() {
  int N;
  std::cin >> N;
  std::deque<int> choice;
  for (int i = 0; i < N; ++i) {
    int tmp;
    std::cin >> tmp;

    choice.push_back(tmp);
  }

  std::stack<int> box;

  int x = choice.front();
  choice.pop_front();

  box.push(x);

  while(!choice.empty()) {
    x = choice.front();
    choice.pop_front();

    if (box.empty()) {
        box.push(x);
    }
    else {
      if (box.top() == x) {
        box.pop();
        choice.push_front(x+1);
      }
      else {
        box.push(x);
      }
    }
  }

  std::cout << box.size() << std::endl;

  return 0;
}