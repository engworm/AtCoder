#include <iostream>

template <typename T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

struct Person {
  std::string name;
  int age;
  bool operator>(const Person &rhs) const {
    return this->age > rhs.age;
  }
};

int main() {

  Person p1 {"morita", 24};
  Person p2 {"abe", 30};
  Person p3 = max(p1, p2);

  std::cout << p3.name << std::endl;
  
  return 0;
}