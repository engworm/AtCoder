#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <set>
#include <deque>

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> Q(N);
  for (int i = 0; i < N; ++i) {
    int p;
    std::cin >> p;
    p -= 1;

    Q[p] = i;
  }

  std::set<int> st;
  for (int i = 0; i < K; ++i) st.insert(Q[i]);

  int ans = *st.rbegin() - *st.begin();
  for (int i = K; i < N; ++i) {
    st.erase(Q[i-K]);
    st.insert(Q[i]);
    ans = std::min(ans, *st.rbegin() - *st.begin());
  }

  std::cout << ans << std::endl;


  return 0;

}