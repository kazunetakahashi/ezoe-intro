#include "../all.h"
#include "vector.h"

struct I_hate_int
{
  I_hate_int() = default;
  I_hate_int(int) = delete;
};

int main()
{
  vector<int> v(10, 1);
  for (auto i = 0; i < 10; i++)
  {
    std::cout << "v[" << i << "] = " << v[i] << std::endl;
  }
  v[2] = 99;
  v.resize(5);
  v.push_back(2019);
  for (auto x : v)
  {
    std::cout << x << std::endl;
  }
  v.reserve(100);
  std::cout << "v.capacity() = " << v.capacity() << std::endl;
  v.shrink_to_fit();
  std::cout << "v.capacity() = " << v.capacity() << std::endl;
  for (auto x : v)
  {
    std::cout << x << std::endl;
  }
  vector<int> w(v.begin(), v.end());
  w.push_back(2020);
  v.push_back(2021);
  for (auto x : w)
  {
    std::cout << x << std::endl;
  }
  vector<std::string> stv = {"Sunaemon"s, "Dr. Tanimura"s, "Mr. Damepo"s};
  stv.push_back("Manohito-kun");
  for (auto const &x : stv)
  {
    std::cout << x << std::endl;
  }
  auto copy{stv};
  stv.push_back("Maeta-kun");
  copy.push_back("Prof. Yoshino");
  for (auto const &x : copy)
  {
    std::cout << x << std::endl;
  }
  std::cout << "test start:" << std::endl;
  auto A = stv, B = copy;
  std::cout << "first case:" << std::endl;
  A = A;
  for (auto const &x : A)
  {
    std::cout << x << std::endl;
  }
  std::cout << "second case:" << std::endl;
  A = B;
  for (auto const &x : A)
  {
    std::cout << x << std::endl;
  }
  std::cout << "third case:" << std::endl;
  B.resize(3);
  B.shrink_to_fit();
  std::cout << "B.capacity() = " << B.capacity() << std::endl;
  A = B;
  for (auto const &x : A)
  {
    std::cout << x << std::endl;
  }
  std::cout << "fourth case:" << std::endl;
  B.resize(3);
  B.shrink_to_fit();
  std::cout << "B.capacity() = " << B.capacity() << std::endl;
  A.resize(2);
  std::cout << "A.capacity() = " << A.capacity() << std::endl;
  A = B;
  for (auto const &x : A)
  {
    std::cout << x << std::endl;
  }
  std::cout << "fifth case:" << std::endl;
  A = stv, B = copy;
  A.clear();
  std::cout << "A.size() = " << A.size() << std::endl;
  std::cout << "A.capacity() = " << A.capacity() << std::endl;
  A.resize(2);
  std::cout << "A.size() = " << A.size() << std::endl;
  std::cout << "A.capacity() = " << A.capacity() << std::endl;
  A.shrink_to_fit();
  std::cout << "A.size() = " << A.size() << std::endl;
  std::cout << "A.capacity() = " << A.capacity() << std::endl;
  std::cout << "B.capacity() = " << B.capacity() << std::endl;
  A = B;
  for (auto const &x : A)
  {
    std::cout << x << std::endl;
  }
}
