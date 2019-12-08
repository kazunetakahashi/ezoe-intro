#include "../all.h"

template <typename T>
class own
{
private:
  T *ptr;

public:
  own() : ptr{new T} {}
  ~own() { delete ptr; }
  own(own const &r) : ptr{new T{*r.ptr}} {}
  template <typename U>
  own(own<U> const &r) : ptr{new T{*r.get()}} {}
  own &operator=(own const &r)
  {
    if (this != &r)
    {
      *ptr = *r.ptr;
    }
    return *this;
  }

  T *get() const
  {
    return ptr;
  }
};

struct I_hate_int
{
  I_hate_int() = default;
  I_hate_int(int) = delete;
};

template <typename T>
class dynamic_array
{
private:
  T *first;
  T *last;

public:
  dynamic_array(std::size_t size = 0) : first(new T[size]), last(first + size) {}
  ~dynamic_array() { delete[] first; }
  dynamic_array(dynamic_array const &r) : first(new T[r.size()]), last(first + r.size()) { std::copy(r.begin(), r.end(), begin()); }
  dynamic_array &operator=(dynamic_array const &r)
  {
    if (size() != r.size())
    {
      delete first;
      first = new T[r.size()];
      last = first + r.size();
      std::copy(r.begin(), r.end(), begin());
    }
    return *this;
  }

  T &operator[](std::size_t i) const noexcept { return first[i]; }
  std::size_t size() const noexcept { return last - first; }
  T *begin() const noexcept { return first; }
  T *end() const noexcept { return last; }
};

int main()
{
  dynamic_array<int> a(10);
  a[0] = 1;
  a[1] = 2;
  auto b{a};
  dynamic_array<int> c(5);
  c = b;
  for (auto i = 0; i < 10; i++)
  {
    std::cout << "c[" << i << "] = " << c[i] << std::endl;
  }
}
