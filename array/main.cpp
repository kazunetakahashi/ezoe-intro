#include "../all.h"

template <typename Array>
class array_iterator
{
  Array &a;
  typename Array::size_type i;

public:
  array_iterator(Array &a, typename Array::size_type i) : a{a}, i{i} {}
  typename Array::reference operator*() { return a[i]; }
  typename Array::reference operator[](typename Array::size_type i) const { return *(*this + i); }
  array_iterator &operator++();
  array_iterator &operator++(int);
  array_iterator &operator--();
  array_iterator &operator--(int);
  array_iterator &operator+=(typename Array::size_type n);
  array_iterator operator+(typename Array::size_type n) const;
  array_iterator &operator-=(typename Array::size_type n);
  array_iterator operator-(typename Array::size_type n) const;
  bool operator==(array_iterator const &right) const;
  bool operator!=(array_iterator const &right) const;
  bool operator<(array_iterator const &right) const;
  bool operator<=(array_iterator const &right) const;
  bool operator>(array_iterator const &right) const;
  bool operator>=(array_iterator const &right) const;
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
template <typename Array>
bool array_iterator<Array>::operator==(array_iterator const &right) const
{
  return i == right.i;
}
template <typename Array>
bool array_iterator<Array>::operator!=(array_iterator const &right) const
{
  return i != right.i;
}
template <typename Array>
bool array_iterator<Array>::operator<(array_iterator const &right) const
{
  return i < right.i;
}
template <typename Array>
bool array_iterator<Array>::operator<=(array_iterator const &right) const
{
  return i <= right.i;
}
template <typename Array>
bool array_iterator<Array>::operator>(array_iterator const &right) const
{
  return i > right.i;
}
template <typename Array>
bool array_iterator<Array>::operator>=(array_iterator const &right) const
{
  return i >= right.i;
}

template <typename Array>
class array_const_iterator
{
  Array &a;
  typename Array::size_type i;

public:
  array_const_iterator(Array &a, typename Array::size_type i) : a{a}, i{i} {}
  array_const_iterator(typename array_iterator<Array>::iterator const &it) : a{it.a}, i{it.i} {}
  typename Array::const_reference operator*() const { return a[i]; }
  typename Array::const_reference operator[](typename Array::size_type i) const { return *(*this + i); }
  array_const_iterator &operator++();
  array_const_iterator &operator++(int);
  array_const_iterator &operator--();
  array_const_iterator &operator--(int);
  array_const_iterator &operator+=(typename Array::size_type n);
  array_const_iterator operator+(typename Array::size_type n) const;
  array_const_iterator &operator-=(typename Array::size_type n);
  array_const_iterator operator-(typename Array::size_type n) const;
  bool operator==(array_const_iterator const &right) const;
  bool operator!=(array_const_iterator const &right) const;
  bool operator<(array_const_iterator const &right) const;
  bool operator<=(array_const_iterator const &right) const;
  bool operator>(array_const_iterator const &right) const;
  bool operator>=(array_const_iterator const &right) const;
};

template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator++()
{
  ++i;
}
template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator++(int)
{
  array_const_iterator copy{*this};
  ++*this;
  return copy;
}
template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator--()
{
  --i;
}
template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator--(int)
{
  array_const_iterator copy{*this};
  --*this;
  return copy;
}
template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator+=(typename Array::size_type n)
{
  i += n;
  return *this;
}
template <typename Array>
array_const_iterator<Array> array_const_iterator<Array>::operator+(typename Array::size_type n) const
{
  array_const_iterator copy{*this};
  copy += n;
  return copy;
}
template <typename Array>
array_const_iterator<Array> &array_const_iterator<Array>::operator-=(typename Array::size_type n)
{
  i -= n;
  return *this;
}
template <typename Array>
array_const_iterator<Array> array_const_iterator<Array>::operator-(typename Array::size_type n) const
{
  array_const_iterator copy{*this};
  copy -= n;
  return copy;
}
template <typename Array>
bool array_const_iterator<Array>::operator==(array_const_iterator const &right) const
{
  return i == right.i;
}
template <typename Array>
bool array_const_iterator<Array>::operator!=(array_const_iterator const &right) const
{
  return i != right.i;
}
template <typename Array>
bool array_const_iterator<Array>::operator<(array_const_iterator const &right) const
{
  return i < right.i;
}
template <typename Array>
bool array_const_iterator<Array>::operator<=(array_const_iterator const &right) const
{
  return i <= right.i;
}
template <typename Array>
bool array_const_iterator<Array>::operator>(array_const_iterator const &right) const
{
  return i > right.i;
}
template <typename Array>
bool array_const_iterator<Array>::operator>=(array_const_iterator const &right) const
{
  return i >= right.i;
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
  using const_iterator = array_const_iterator<array>;

  value_type storage[N];

  reference operator[](size_type i) { return storage[i]; }
  const_reference operator[](size_type i) const { return storage[i]; }
  reference at(size_type i);
  const_reference at(size_type i) const;
  size_type size() const;
  reference front() { return storage[0]; }
  const_reference front() const { return storage[0]; }
  reference back() { return back[N - 1]; }
  const_reference back() const { return back[N - 1]; }
  iterator begin() { return iterator{*this, 0}; }
  iterator end() { return iterator{*this, N}; }
  const_iterator begin() const { return const_iterator{*this, 0}; }
  const_iterator end() const { return const_iterator{*this, N}; }
  const_iterator cbegin() const { return const_iterator{*this, 0}; }
  const_iterator cend() const { return const_iterator{*this, N}; }
};

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(typename array<T, N>::size_type i)
{
  if (i >= size())
  {
    throw std::out_of_range("Error: Out of Range");
  }
  return storage[i];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::at(typename array<T, N>::size_type i) const
{
  if (i >= this->size())
  {
    throw std::out_of_range("Error: Out of Range");
  }
  return storage[i];
}

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
