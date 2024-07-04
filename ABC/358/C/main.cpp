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

int main() {
  int N, M;
  std::cin >> N >> M;

  std::string *S = new std::string[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }


  int result_count = N;

  for (int bit = 1; bit < (1 << N); ++bit) {

    int count = 0; // 最大訪問店舗数
    std::vector<bool> popcorn(M, false);

    for (int i = 0; i < N; ++i) {

      if (bit & (1 << i)) {
        count++;   // 訪問
        for (int j = 0; j < M; ++j) {
          if (S[i][j] == 'o') {
            popcorn.at(j) = true;
          }
        }
      }

      if (std::all_of(popcorn.begin(), popcorn.end(), [] (bool b) {return b;})) {
        // 最小値の更新　
        result_count = (result_count > count) ? count : result_count;
        break;
      }
    }

  }

  std::cout << result_count << std::endl;
  return 0;
}