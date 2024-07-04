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

class Record {
  public:
    Record(int n, int m) : vec(std::vector(n, std::vector<bool>(m, false))) {};
    void push(std::pair<int ,int> &p);
    bool at(std::pair<int, int> &p);
  
  private:
    std::vector<std::vector<bool>> vec;
};

void Record::push(std::pair<int, int> &p) {
  vec.at(p.first).at(p.second) = true;
};

bool Record::at(std::pair<int, int> &p) {
  return vec.at(p.first).at(p.second);
};


int main() {

  const std::vector<std::pair<int, int>> walk{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  // input
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char>> town(H, std::vector<char>(W, 0));

  // initialize
  std::pair<int, int> start;
  std::pair<int, int> goal;
  
  for (int i = 0; i < H; ++i) {
     for (int j = 0; j < W; ++j) {
      char c;
      std::cin >> c;

      town.at(i).at(j) = c;

      if (c == 's') {
        start = std::pair(i, j);
      }
      else if (c == 'g') {
        goal = std::pair(i, j);
      }
    }
  }


  std::stack <std::pair<int, int>> arrive;

  Record record(H, W);

  // search start
  arrive.push(start);
  record.push(start);

  bool result = false;
  while (!arrive.empty()) {
    if (record.at(goal)) {
      result = true; 
      break;
    }

    std::pair<int, int> tmp = arrive.top();
    arrive.pop();

    std::stack<std::pair<int, int>> nbh_tmp = [&town, &walk, &H, &W] (std::pair<int, int> &t) {
      std::stack<std::pair<int, int>> v;
      for (int i = 0; i < 4; ++i) {
        int x = t.first + walk[i].first;
        int y = t.second + walk[i].second;

        if (0 <= x && x < H && 0 <= y && y < W) {
          if (town.at(x).at(y) == '.' || town.at(x).at(y) == 'g') {
            v.push(std::pair<int, int>{x, y});
            // std::cout << "(x, y) = " << x << ' ' << y << std::endl;
          }
        }
      }
      return v;
    }(tmp);

    // std::cout << "nbh size: " << nbh_tmp.size() << std::endl;

    while (!nbh_tmp.empty()) {
      if (!record.at(nbh_tmp.top())) {
        arrive.push(nbh_tmp.top());
        record.push(nbh_tmp.top());
      }
      nbh_tmp.pop();
    }

  }

  if (result) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}