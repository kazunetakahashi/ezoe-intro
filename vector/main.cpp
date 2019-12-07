#include "../all.h"
#include "vector.h"

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
}
