#include "../all.h"

int main()
{
  auto print = [](auto x) {
    std::cout << x << std::endl;
  };
  print(123);
  print(3.14);
  print("hello"s);
}