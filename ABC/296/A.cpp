#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<char> S(N);

  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }

  std::vector<char> v1;
  std::vector<char> v2;
  for (int i = 0; i < N; ++i) {
    if (i%2 == 0) {
      v1.push_back(S[i]);
    }
    else {
      v2.push_back(S[i]);
    }
  }


  bool b1 = false; 
  bool b2 = false;
  b1 = std::all_of(v1.begin(), v1.end(), [](char s){ return s == 'M'; });
  b2 = std::all_of(v2.begin(), v2.end(), [](char s){ return s == 'F'; });

  bool b3 = false; 
  bool b4 = false;
  b3 = std::all_of(v1.begin(), v1.end(), [](char s){ return s == 'F'; });
  b4 = std::all_of(v2.begin(), v2.end(), [](char s){ return s == 'M'; });

  if ((b1 && b2) || (b3 && b4)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}