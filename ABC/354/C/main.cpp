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
  std::vector<std::pair<int, int>> card_pairs(N, std::pair<int, int>{0, 0});
  for (int i = 0; i < N; ++i) {
    std::cin >> card_pairs[i].first >> card_pairs[i].second;
  }

  std::vector<std::pair<int, int>> sorted_card_pairs(N, std::pair<int, int>{0, 0});
  std::partial_sort_copy(card_pairs.rbegin(), card_pairs.rend(), sorted_card_pairs.rbegin(), sorted_card_pairs.rend());

  std::pair<int, int> p = sorted_card_pairs[0]; // 現時点で最弱のカードだが，必ず生き残る

  std::vector<int> survived_card_list;
  for (int i = 0; i < N; ++i) {
    survived_card_list.push_back(i);
  }

  std::pair<int, int> target_p;
  for (int i = 1; i < N; ++i) {
    target_p = sorted_card_pairs[i];


    if (target_p.second > p.second) { // 破棄するカード
      auto itr = std::find(card_pairs.begin(), card_pairs.end(), target_p);
      int idx = std::distance(card_pairs.begin(), itr);

      survived_card_list.erase(survived_card_list.begin()+idx);
    }
    else {
      p = target_p;  // 比較対象を更新
    }
  }

  int m = survived_card_list.size();
  std::cout << m << std::endl;
  for (int i = 0; i < m; ++i) {
    std::cout << survived_card_list[i]+1 << ' ';
  }
  std::cout << std::endl;

  return 0;
}