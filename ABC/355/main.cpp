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
  int N, T;
  std::cin >> N >> T;

  std::vector<int> A(T, -1);
  for (int i = 0; i < T; ++i) {
    int tmp;
    std::cin >> tmp; 

    A.at(i) = tmp - 1;
  }


  int ans = -1;
  int naname1 = 0;
  int naname2 = 0;
  std::vector<int> yoko(N, 0);
  std::vector<int> tate(N, 0);

  for (int i = 0; i < T; ++i) {
    int row = A.at(i) / N;
    int col = A.at(i) % N; 

    if (row == col) {
      naname1 += 1;
    }

    if ((N - row - 1) == col) {
      naname2 += 1;
    }


    yoko[col] += 1;
    tate[row] += 1;

    if ((naname1 == N) || (naname2 == N) || (yoko[col] == N) || (tate[row] == N)) {
      ans = i + 1;
      break;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}