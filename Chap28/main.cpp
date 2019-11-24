#include "../all.h"

struct cout_iterator
{
  using difference_type = void;
  using value_type = void;
  using reference = void;
  using pointer = void;
  using iterator_category = std::output_iterator_tag;

  cout_iterator &operator*() { return *this; }
  cout_iterator &operator++() { return *this; }
  cout_iterator &operator++(int) { return *this; }

  template <typename T>
  cout_iterator &operator=(T const &x)
  {
    std::cout << x << std::endl;
    return *this;
  }
};

template <typename T>
struct iota_iterator
{
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using const_reference = T const &;
  using reference = T &;
  using pointer = T *;
  using iterator_category = std::random_access_iterator_tag;

  T value;

  iota_iterator(T value = 0) : value{value} {}

  reference operator*() noexcept { return value; }
  const_reference operator*() const noexcept { return value; }
  iota_iterator &operator++() noexcept
  {
    ++value;
    return *this;
  }
  iota_iterator &operator++(int) noexcept
  {
    auto copy{*this};
    ++*this;
    return copy;
  }
  iota_iterator &operator--() noexcept
  {
    --value;
    return *this;
  }
  iota_iterator &operator--(int) noexcept
  {
    auto copy{*this};
    --*this;
    return copy;
  }
  bool operator==(iota_iterator const &it) const noexcept
  {
    return value == it.value;
  }
  bool operator!=(iota_iterator const &it) const noexcept
  {
    return !(*this == it);
  }
  bool operator<=(iota_iterator const &it) const noexcept
  {
    return value <= it.value;
  }
  bool operator<(iota_iterator const &it) const noexcept
  {
    return value < it.value;
  }
  bool operator>=(iota_iterator const &it) const noexcept
  {
    return value >= it.value;
  }
  bool operator>(iota_iterator const &it) const noexcept
  {
    return value > it.value;
  }
  iota_iterator &operator+=(difference_type n)
  {
    value += n;
    return *this;
  }
  iota_iterator &operator+(difference_type n) const
  {
    auto copy{*this};
    copy += n;
    return copy;
  }
  iota_iterator &operator-=(difference_type n)
  {
    value -= n;
    return *this;
  }
  iota_iterator &operator-(difference_type n) const
  {
    auto copy{*this};
    copy -= n;
    return copy;
  }
  difference_type operator-(iota_iterator const &i)
  {
    return value - i.value;
  }
};

template <typename T>
iota_iterator<T> operator+(typename iota_iterator<T>::difference_type n, iota_iterator<T> const &i)
{
  return i + n;
}

int main()
{
  std::vector<int> V = {0, 1, 2, 4, 7};
  cout_iterator out;
  std::copy(V.begin(), V.end(), out);
  std::ostream_iterator<int> out2{std::cout};
  std::copy(V.begin(), V.end(), out2);

  iota_iterator<int> it;
  iota_iterator first(0), last(10);
  it = last;

  iota_iterator non_const(0);
  int value{*non_const};
  *non_const = 1;
  iota_iterator const immutable(0);
  int const_value{*immutable};
}
