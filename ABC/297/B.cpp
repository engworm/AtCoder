#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::vector<int> B;
  for (int i = 0; i < 8; ++i) {
    if (S[i] == 'B') B.push_back(i);
  }

  bool test1 = false;
  if ((B[0]%2==0 && B[1]%2==1) || (B[0]%2==1 && B[1]%2==0)) test1 = true;

  bool test2 = false;
  int count = 0;
  for (int i = 0; i < 8; ++i) {
    if (S[i] == 'R') count++;
    else if (S[i] == 'K' && count == 1) test2 = true;
  }

  if (test1 && test2) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}