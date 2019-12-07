#include "../all.h"

template <typename T, typename Allocator = std::allocator<T>>
class vector
{
public:
  using value_type = T;
  using pointer = T *;
  using const_pointer = T const *;
  using reference = value_type &;
  using const_reference = value_type const &;
  using allocator_type = Allocator;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using iterator = pointer;
  using const_iterator = const_pointer;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using reverse_const_iterator = std::reverse_iterator<const_iterator>;

private:
  pointer first;
  pointer last;
  pointer reserved_last;
  allocator_type alloc;

public:
  // iterators
  iterator begin() noexcept { return first; }
  iterator end() noexcept { return last; }
  iterator begin() const noexcept { return first; }
  iterator end() const noexcept { return last; }
  const_iterator cbegin() const noexcept { return first; }
  const_iterator cend() const noexcept { return last; }
  reverse_iterator rbegin() noexcept { return reverse_iterator{last}; }
  reverse_iterator rend() noexcept { return reverse_iterator{first}; }
  reverse_const_iterator crbegin() const noexcept { return reverse_iterator{last}; }
  reverse_const_iterator crend() const noexcept { return reverse_iterator{first}; }
  // size
  size_type size() const noexcept { return std::distance(begin(), end()); }
  bool empty() const noexcept { return begin() == end(); }
  size_type capacity() const noexcept { return reserved_last - first; }
  // access to the elements
  reference operator[](size_type i) { return first[i]; }
  const_reference operator[](size_type i) const { return first[i]; }
  reference at(size_type i);
  const_reference at(size_type i) const;
  reference front() { return *first; }
  const_reference front() const { return *first; }
  reference back() { return *(last - 1); }
  const_reference back() const { return *(last - 1); }
  pointer data() { return first; }
  const_pointer data() const { return first; }
};

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type i)
{
  if (i >= size())
  {
    throw std::out_of_range("index is out of range.");
  }
  return this[i];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type i) const
{
  if (i >= size())
  {
    throw std::out_of_range("index is out of range.");
  }
  return this[i];
}

int main()
{
  vector<int> V;
  int x = V[0];
}
