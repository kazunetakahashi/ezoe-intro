#include "../all.h"

template <typename Array>
class array_iterator
{
  Array &a;
  typename Array::size_type i;

public:
  array_iterator(Array &a, typename Array::size_type i) : a{a}, i{i} {}
  typename Array::reference operator*() { a[i]; }
  array_iterator &operator++();
  array_iterator &operator++(int);
  array_iterator &operator--();
  array_iterator &operator--(int);
  array_iterator &operator+=(typename Array::size_type n);
  array_iterator operator+(typename Array::size_type n) const;
  array_iterator &operator-=(typename Array::size_type n);
  array_iterator operator-(typename Array::size_type n) const;
};

template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator++()
{
  ++i;
}
template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator++(int)
{
  array_iterator copy{*this};
  ++*this;
  return copy;
}
template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator--()
{
  --i;
}
template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator--(int)
{
  array_iterator copy{*this};
  --*this;
  return copy;
}
template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator+=(typename Array::size_type n)
{
  i += n;
  return *this;
}
template <typename Array>
array_iterator<Array> array_iterator<Array>::operator+(typename Array::size_type n) const
{
  array_iterator copy{*this};
  copy += n;
  return copy;
}
template <typename Array>
array_iterator<Array> &array_iterator<Array>::operator-=(typename Array::size_type n)
{
  i -= n;
  return *this;
}
template <typename Array>
array_iterator<Array> array_iterator<Array>::operator-(typename Array::size_type n) const
{
  array_iterator copy{*this};
  copy -= n;
  return copy;
}

template <typename T, std::size_t N>
class array
{
public:
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;
  using iterator = array_iterator<array>;

  value_type storage[N];

  reference operator[](size_type i)
  {
    return storage[i];
  }
  const_reference operator[](size_type i) const
  {
    return storage[i];
  }
  size_type size() const;
  reference front() { return storage[0]; }
  const_reference front() const { return storage[0]; }
  reference back() { return back[N - 1]; }
  const_reference back() const { return back[N - 1]; }
  iterator begin() { return array_iterator{*this, 0}; }
  iterator end() { return array_iterator{*this, N}; }
};

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const
{
  return N;
}

template <typename Container, typename Out>
void print_all(Container const &c, Out &stream)
{
  for (typename Container::size_type i = 0u; i < c.size(); i++)
  {
    stream << c[i] << "\n"s;
  }
}

int main()
{
  array<int, 10> ary;
  for (auto i = 0; i < 10; i++)
  {
    ary[i] = i;
  }
  std::cout << "ary.size() = "s << ary.size() << std::endl;
  print_all(ary, std::cout);
  std::cout << "ary.front() = "s << ary.front() << std::endl;
  ary.front() = 1;
  std::cout << "ary.front() = "s << ary.front() << std::endl;
}