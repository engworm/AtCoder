#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

int main() {

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> do_list(3, std::vector<int>(N+1, 0));
  for (int day = 1; day <= N; ++day) {
    for (int event = 0; event < 3; ++event) {
      std::cin >> do_list[event][day];
    }
  }

  std::vector<std::vector<int>> happy_table(3, std::vector<int>(N+1, 0));

  for (int event = 0; event < 3; ++event) {
    happy_table[event][1] = do_list[event][1];
  }

  for (int day = 2; day <= N; ++day) {
    for (int event = 0; event < 3; ++event) {
      [&] () {
        if (happy_table[event][day] < happy_table[(event+1)%3][day-1]+do_list[event][day])
          happy_table[event][day] = happy_table[(event+1)%3][day-1]+do_list[event][day];

        if (happy_table[event][day] < happy_table[(event+2)%3][day-1]+do_list[event][day])
          happy_table[event][day] = happy_table[(event+2)%3][day-1]+do_list[event][day];

      }();
    }
  }

  int max_happy = 0;
  for (int event = 0; event < 3; ++event) {
    if (max_happy < happy_table[event][N]) max_happy = happy_table[event][N];
  }

  std::cout << max_happy << std::endl;

  return 0;
}