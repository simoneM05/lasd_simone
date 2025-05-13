
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Vector : virtual public ResizableContainer,
                 virtual public MutableLinearContainer<Data>
  {

  private:
  protected:
    using Container::size;
    Data *Elements = nullptr; // Pointer to the array of elements
  public:
    // Default constructor
    Vector() = default;

    /* ************************************************************************ */

    // Specific constructors
    Vector(const unsigned long); // A vector with a given initial dimension

    Vector(const TraversableContainer<Data> &); // A vector obtained from a TraversableContainer
    Vector(MappableContainer<Data> &&);         // A vector obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    Vector(const Vector &);

    // Move constructor
    Vector(Vector &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~Vector(); // Override ~Container() specifiers;

    /* ************************************************************************ */

    // Copy assignment
    Vector &operator=(const Vector &);

    // Move assignment
    Vector &operator=(Vector &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Vector &) const noexcept;
    inline bool operator!=(const Vector &) const noexcept;

    /* ************************************************************************ */
    // Specific member functions (inherited from LinearContainer)
    const Data &operator[](const unsigned long) const override;
    const Data &Back() const override;
    const Data &Front() const override;

    /* ************************************************************************ */
    // Specific member functions (inherited from MutableLinearContainer)
    Data &operator[](const unsigned long) override;
    Data &Front() override;
    Data &Back() override;

    /* ************************************************************************ */
    // Specific member function (inherited from ClearableContainer)

    void Clear() override;

    /* ************************************************************************ */

    // Specific member function (inherited from ResizableContainer)

    void Resize(const unsigned long) override;

  protected:
  };

  /* ************************************************************************** */

  template <typename Data>
  class SortableVector : virtual public Vector<Data>,
                         virtual public SortableLinearContainer<Data>
  {

  private:
    // ...

  protected:
    using Container::size;

    // ...

  public:
    // Default constructor
    SortableVector() = default; // SortableVector() specifiers;

    /* ************************************************************************ */

    // Specific constructors

    SortableVector(const unsigned long);

    SortableVector(const TraversableContainer<Data> &);
    SortableVector(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    SortableVector(const SortableVector &);

    // Move constructor
    SortableVector(SortableVector &&) noexcept;

    // Destructor
    virtual ~SortableVector() = default;

    /* ************************************************************************ */

    // Copy assignment
    SortableVector &operator=(const SortableVector &);

    // Move assignment
    SortableVector &operator=(SortableVector &&) noexcept;

  protected:
  };

  /* ************************************************************************** */

}

#include "vector.cpp"

#endif
