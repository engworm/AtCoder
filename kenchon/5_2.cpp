#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

bool success(int w, std::vector<int> num_list) {
  int n = num_list.size();
  if (n == 1) {
    if (w == num_list[0]) return true;
    else return false;
  }

  int del = num_list.back();
  num_list.pop_back();

  if (success(w, num_list)) return true;
  if (success(w-del, num_list)) return true;

  return false;

}

int main() {
  return 0;
}