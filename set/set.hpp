
#ifndef SET_HPP
#define SET_HPP

/* ************************************************************************** */

#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Set : virtual public OrderedDictionaryContainer<Data>, // Must extend OrderedDictionaryContainer<Data>
              virtual public LinearContainer<Data>,            // Must extend LinearContainer<Data>
              virtual public ClearableContainer
  {
    // Must extend ClearableContainer

  private:
  protected:
  public:
    virtual ~Set() = default; // ~Set() specifiers

    /* ************************************************************************ */

    // Copy assignment
    Set &operator=(const Set &) = delete; // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    Set &operator=(Set &&) noexcept = delete; // type operator=(argument); // Move assignment of abstract types is not possible.
  };

  /* ************************************************************************** */
}

#endif
