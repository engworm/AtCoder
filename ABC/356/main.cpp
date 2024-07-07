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
  int N, M, K;
  std::cin >> N >> M >> K;

  std::vector<int> test_number(M, -1);
  std::vector<std::bitset<15>> test_key(M, std::bitset<15>(0));
  std::vector<char> test_result(M, 0);

  for (int i = 0; i < M; ++i) {

    std::cin >> test_number[i];

    for (int j = 0; j < test_number[i]; ++j) {
      int key;
      std::cin >> key;
      test_key[i][key-1] = '1';
    }

    std::cin >> test_result[i];

  }


  int count = 0;

  for (int i = 0; i < (1 << N); ++i) {

    std::bitset<15> ans_key = std::bitset<15>(i);
    std::vector<bool> not_contradiction(M, false);

    // std::cout << "ans key : " << ans_key << std::endl;

    for (int j = 0; j < M; ++j) {
      // std::cout << "test key: " << test_key[j] << std::endl;

      std::bitset<15> accept_num = (ans_key & test_key[j]);
      // std::cout << "accept num: " << accept_num.count() << std::endl;

      char open = 'x';
      if (accept_num.count() >= K) {
        open = 'o';
      }
      // std::cout << "open: " << open << std::endl;

      if (open == test_result[j]) {
        not_contradiction.at(j) = true;
      }
    }

    bool result = std::all_of(not_contradiction.begin(), not_contradiction.end(), [] (bool b) {
      return b == true;
    });

    if (result) {
      count++;
    }

  }

  std::cout << count << std::endl;

  return 0;
}