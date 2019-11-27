#include "../all.h"

int main()
{
  int N{10};
  std::allocator<std::string> a;
  using traits = std::allocator_traits<decltype(a)>;
  std::string *p{traits::allocate(a, N)};
  int k{0};
  for (auto it{p}, last{p + N}; it != last; ++it)
  {
    traits::construct(a, it, "hello"s + std::to_string(k++));
  }
  for (auto it{p}, last{p + N}; it != last; ++it)
  {
    std::cout << *(p + --k) << std::endl;
  }
  for (auto it{p + N}, first{p}; it != first; --it)
  {
    traits::destroy(a, it);
  }
  traits::deallocate(a, p, N);
}
