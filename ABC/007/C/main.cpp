#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <deque>
#include <set>
#include <list>


const std::array<int, 4> dx {1, 0, -1, 0};
const std::array<int, 4> dy {0, 1, 0, -1};


int main() {
  int R, C;
  std::cin >> R >> C;

  int sy, sx, gy, gx;
  std::cin >> sy >> sx >> gy >> gx;

  std::vector<std::vector<char>> meiro(R, std::vector<char>(C, 0));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      std::cin >> meiro[i][j];
    }
  }

  std::deque <std::pair<int, int>> encounter;
  std::vector<std::vector<bool>> pre_encounter(R, std::vector<bool>(C, false));
  std::vector<std::vector<int>> score(R, std::vector<int>(C, 0));

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      score[i][j] = R*C+1;
    }
  }

  // 0-indexed
  sx -= 1;
  sy -= 1;
  gx -= 1;
  gy -= 1;

  score[sy][sx] = 0;

  encounter.push_back(std::pair(sx, sy));
  pre_encounter[sy][sx] = true;
  

  while (!encounter.empty()) {

    // std::for_each(encounter.begin(), encounter.end(), [&](auto x) {
      // std::cout << "(" << x.first << ' ' << x.second << ")"; 
    // });
    // std::cout << std::endl;

    auto tmp = encounter.front();
    encounter.pop_front();

    for (int i = 0; i < 4; ++i) {
      auto search = tmp;
      search.first += dy[i];
      search.second += dx[i];

      if (meiro[search.first][search.second] == '.' && pre_encounter[search.first][search.second] == false) {
        score[search.first][search.second] = std::min(score[search.first][search.second], score[tmp.first][tmp.second]+1);
        encounter.push_back(search);
        pre_encounter[search.first][search.second] = true;
      }

    }

  }

  // for (int i = 0; i < R; ++i) {
    // for (int j = 0; j < C; ++j) {
      // std::cout << score[i][j] << ' '; 
    // }
    // std::cout << std::endl;

  // }

  std::cout << score[gy][gx] << std::endl;



  return 0;
}