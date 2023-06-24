#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>


int main() {
  int N;
  std::cin >> N;

  std::vector<std::string> W(N);
  for (auto &w : W) {
    std::cin >> w;
  }

  std::vector<std::string> check_list{"and", "not", "that", "the", "you"};


  bool check = false;
  for (auto &c : check_list) {
    auto loc = std::find(W.begin(), W.end(), c);
    if (loc != W.end()) {
      check = true;
      break;
    }
  }

  if (check) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}