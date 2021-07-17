///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ARGOAI_SHARED_PTR_H
#define ARGOAI_SHARED_PTR_H

#include <cstdint>

namespace problem_statement
{

template <typename T>
class shared_ptr
{
  public:
    shared_ptr() : raw_pointer_{nullptr} {}
    explicit shared_ptr(const T* raw_pointer) : raw_pointer_{raw_pointer} {}
    ~shared_ptr() {}

    shared_ptr(const shared_ptr& other) = default;
    shared_ptr& operator=(const shared_ptr& other) = default;
    shared_ptr(shared_ptr&& other) = default;
    shared_ptr& operator=(shared_ptr&& other) = default;

  private:
    T* raw_pointer_;
};
}  // namespace problem_statement

#endif  /// ARGOAI_SHARED_PTR_H
