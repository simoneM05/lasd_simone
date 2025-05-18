#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class
      LinearContainer : virtual public PreOrderTraversableContainer<Data>,
                        virtual public PostOrderTraversableContainer<Data>
  {

  private:
  protected:
    using Container::size;

  public:
    // Destructor
    virtual ~LinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    LinearContainer &operator=(const LinearContainer &) = delete;

    // Move assignment
    LinearContainer &operator=(LinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const LinearContainer &) const noexcept;
    inline bool operator!=(const LinearContainer &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &operator[](unsigned long) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)

    inline virtual const Data &Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)

    inline virtual const Data &Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    inline void Traverse(TraverseFun) const override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    inline void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class MutableLinearContainer : virtual public LinearContainer<Data>,
                                 virtual public PreOrderMappableContainer<Data>,
                                 virtual public PostOrderMappableContainer<Data>
  {

  private:
  protected:
  public:
    // Destructor
    virtual ~MutableLinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MutableLinearContainer &operator=(const MutableLinearContainer &) = delete;

    // Move assignment
    MutableLinearContainer &operator=(MutableLinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    // Importa l'operatore della classe base
    using LinearContainer<Data>::operator[];

    virtual Data &operator[](unsigned long) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

    // Importa le funzioni della classe base
    using LinearContainer<Data>::Front;
    using LinearContainer<Data>::Back;

    inline virtual Data &Front(); // (mutable version; concrete function must throw std::length_error when empty)

    inline virtual Data &Back(); // (mutable version; concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    inline void Map(MapFun) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member
  };

  template <typename Data>
  class SortableLinearContainer : virtual public MutableLinearContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~SortableLinearContainer() = default; // Destructor of abstract types is not be possible.

    /* ************************************************************************ */
    // Copy assignment
    SortableLinearContainer &operator=(const SortableLinearContainer &) = delete;

    // Move assignment
    SortableLinearContainer &operator=(SortableLinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    virtual void Sort() noexcept;

  protected:
    void QuickSort(unsigned long, unsigned long) noexcept;          // Auxiliary member function for sorting
    unsigned long Partition(unsigned long, unsigned long) noexcept; // Auxiliary member function for sorting
  };

  /* ************************************************************************** */

}

#include "linear.cpp"

#endif