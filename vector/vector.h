#include "../all.h"
#ifndef vector_HEADER
#define vector_HEADER

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
  reverse_iterator rend() noexcept { return reverse_iterator{last}; }
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

  // constructor
  vector(allocator_type const &alloc) noexcept : first{nullptr}, last{nullptr}, reserved_last{nullptr}, alloc{alloc} {}
  vector() : vector(allocator_type{}) {}
  vector(size_type size, allocator_type const &alloc = allocator_type{});
  vector(size_type size, const_reference value, allocator_type const &alloc = allocator_type{});
  template <typename InputIter, typename E = typename std::enable_if_t<std::is_pointer_v<InputIter>>>
  vector(InputIter first, InputIter last, allocator_type const &alloc = allocator_type{});
  vector(std::initializer_list<value_type> init, allocator_type const &alloc = allocator_type{}) : vector(std::begin(init), std::end(init), alloc) {}
  // destructor
  ~vector();

  // memory
  void clear() noexcept { destroy_until(rend()); }
  void reserve(size_type sz);
  void resize(size_type sz);
  void resize(size_type sz, const_reference value);
  void push_back(const_reference value);
  void shrink_to_fit();

private:
  // helper functions for allocator_traits
  using traits = std::allocator_traits<allocator_type>;
  pointer allocate(size_type n) { return traits::allocate(alloc, n); }
  void deallocate() { traits::deallocate(alloc, first, capacity()); }
  void construct(pointer ptr) { traits::construct(alloc, ptr); }
  void construct(pointer ptr, const_reference value) { traits::construct(alloc, ptr, value); }
  void construct(pointer ptr, value_type &&value) { traits::construct(alloc, ptr, std::move(value)); }
  void destroy(pointer ptr) { traits::destroy(alloc, ptr); }
  void destroy_until(reverse_iterator rend);
};

#include "vector_impl.h"

#endif // vector_HEADER
