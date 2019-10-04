#include "../all.h"

auto output_all = [](auto b, auto e, auto out) {
  for (auto it = b; it != e; ++it, ++out)
  {
    *out = *it;
  }
};

auto output_all_2 = [](auto b, auto e) {
  for (auto it = b; it != e; ++it)
  {
    std::cout << *it << std::endl;
  }
};

int main()
{
  std::ostream_iterator<int> out{std::cout};
  std::vector<int> v{0, 12, 3, 4, 5};
  output_all(v.begin(), v.end(), out);
  std::istream_iterator<int> first{std::cin}, last;
  output_all(first, last, out);
  std::filesystem::directory_iterator b{"./"s}, e;
  output_all_2(b, e);
  std::vector<int> w(5);
  output_all(v.rbegin(), v.rend(), w.begin());
  output_all(w.begin(), w.end(), out);
}