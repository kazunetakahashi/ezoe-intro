#include "../all.h"

template <typename T, typename Allocator = std::allocator<T>>
class vector
{
public:
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using refernce = value_type &;
  using const_reference = const value_type &;
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
};

int main()
{
}
