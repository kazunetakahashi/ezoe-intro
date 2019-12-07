#include "../all.h"
#include "vector.h"

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

template <typename T, typename Allocator>
vector<T, Allocator>::vector(typename vector<T, Allocator>::size_type size, typename vector<T, Allocator>::allocator_type const &alloc) : vector<T, Allocator>(alloc)
{
  resize(size);
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(typename vector<T, Allocator>::size_type size, typename vector<T, Allocator>::const_reference value, typename vector<T, Allocator>::allocator_type const &alloc) : vector<T, Allocator>(alloc)
{
  resize(size, value);
}

template <typename T, typename Allocator>
template <typename InputIter, typename E>
vector<T, Allocator>::vector(InputIter first, InputIter last, typename vector<T, Allocator>::allocator_type const &alloc) : vector<T, Allocator>(alloc)
{
  reserve(std::distance(first, last));
  for (auto it = first; it != last; ++it)
  {
    push_back(*it);
  }
}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{
  clear();
  deallocate();
}

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(typename vector<T, Allocator>::size_type sz)
{
  if (sz <= capacity())
  {
    return;
  }
  auto ptr{allocate(sz)};
  auto old_first{first};
  auto old_last{last};
  auto old_capacity{capacity()};
  first = ptr;
  last = first;
  reserved_last = first + sz;
  for (auto old_iter = old_first; old_iter != old_last; ++old_iter, ++last)
  {
    construct(last, std::move(*old_iter));
  }
  for (auto it = reverse_iterator(old_last), rend = reverse_iterator(old_first); it != rend; ++it)
  {
    destroy(&*it);
  }
  traits::deallocate(alloc, old_first, old_capacity);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(typename vector<T, Allocator>::size_type sz)
{
  if (sz < size())
  {
    auto diff{size() - sz};
    destroy_until(rbegin() + diff);
    last = first + sz;
  }
  else if (sz > size())
  {
    reserve(sz);
    for (; last != reserved_last; ++last)
    {
      construct(last);
    }
  }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(typename vector<T, Allocator>::size_type sz, typename vector<T, Allocator>::const_reference value)
{
  if (sz < size())
  {
    auto diff{size() - sz};
    destroy_until(rbegin() + diff);
    last = first + sz;
  }
  else if (sz > size())
  {
    reserve(sz);
    for (; last != reserved_last; ++last)
    {
      construct(last, value);
    }
  }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(typename vector<T, Allocator>::const_reference value)
{
  if (size() + 1 > capacity())
  {
    auto c{std::max(size_type{8}, 2 * size())};
    reserve(c);
  }
  construct(last, value);
  ++last;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::shrink_to_fit()
{
  if (size() == capacity())
  {
    return;
  }
  auto ptr{allocate(size())};
  auto current_size{size()};
  for (auto raw_ptr = ptr, iter = begin(), iter_end = end(); iter != iter_end; ++iter, ++raw_ptr)
  {
    construct(raw_ptr, *iter);
  }
  clear();
  deallocate();
  first = ptr;
  last = ptr + current_size;
  reserved_last = last;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::destroy_until(typename vector<T, Allocator>::reverse_iterator rend)
{
  for (auto it = rbegin(); it != rend; ++it, --last)
  {
    destroy(&*it);
  }
}
