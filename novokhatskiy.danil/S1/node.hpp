#ifndef NODE_HPP
#define NODE_HPP

#include <utility>

namespace novokhatskiy
{
  namespace detail
  {
    template <typename T>
    struct Node
    {
      T value_;
      Node *next_;
      Node(const T &value = 0, Node *next = nullptr) : value_(value),
                                                       next_(next)
      {
      }
      Node(T &&value) : value_(std::move(value)),
                        next_(nullptr)
      {
      }
      template <class... Args>
      explicit Node(Node *next, Args &&...args) : value_(std::forward<Args>(args)...),
                                                  next_(next)
      {
      }
      void freeNode(Node *other) noexcept
      {
        while (other)
        {
          Node *tmp = other->next_;
          delete other;
          other = tmp;
        }
      }
    };
  }
}
#endif
