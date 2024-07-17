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

int main() {
  const std::string ABC = "abcdefghijklmnopqrstuvwxyz";

  std::string S;
  std::cin >> S;

  std::map<char, long long> mp;
  for (int i = 0; i < S.length(); ++i) {
    if (mp.contains(S[i])) {
      mp.at(S[i]) += 1;
    }
    else {
      mp.emplace(S[i], 1);
    }
  }

  // 違う文字を交換する
  long long r = 0;
  for (int i = 0; i < ABC.length(); ++i) {
    long long x = S.length() - mp[ABC.at(i)];
    long long y = mp[ABC.at(i)];
    r += x*y;

  }

  r /= 2;

  // 同じ文字を交換する
  for (int i = 0; i < ABC.length(); ++i) {
    long long y = mp[ABC.at(i)];
    if (y > 1) {
      r++;
      break;
    }
  }

  std::cout << r << std::endl;

  return 0;
}