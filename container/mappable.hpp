
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class MappableContainer : virtual public TraversableContainer<Data>
  {
  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~MappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MappableContainer &operator=(const MappableContainer &) = delete;

    // Move assignment
    MappableContainer &operator=(MappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const MappableContainer &) const noexcept = delete;
    bool operator!=(const MappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using MapFun = std::function<void(Data &)>;

    virtual void Map(MapFun) = 0; // type Map(argument) specifiers;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderMappableContainer : virtual public MappableContainer<Data>,
                                    virtual public PreOrderTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             PreOrderTraversableContainer<Data>

  private:
  protected:
  public:
    // Destructor
    virtual ~PreOrderMappableContainer() = default; // ~PreOrderMappableContainer() specifiers

    /* ************************************************************************ */
    // Copy assignment
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

    // Move assignment
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;
    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PreOrderMap(MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    inline void Map(MapFun) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderMappableContainer : virtual public MappableContainer<Data>,
                                     virtual public PostOrderTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             PostOrderTraversableContainer<Data>

  private:
  protected:
  public:
    // Destructor
    virtual ~PostOrderMappableContainer() = default; // ~PostOrderMappableContainer() specifiers

    /* ************************************************************************ */

    // Copy assignment
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

    // Move assignment
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;
    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PostOrderMap(MapFun) = 0; // type PostOrderMap(argument) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    inline void Map(MapFun) override; // type Map(argument) specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

}

#include "mappable.cpp"

#endif
