#include "../all.h"

int main()
{
  std::vector<int> V = {1, 2, 3, 4, 5};
  std::for_each(V.begin(), V.end(), [](auto &v) { v *= 2; });
  std::for_each(V.begin(), V.end(), [](auto x) { std::cout << x << std::endl; });
}