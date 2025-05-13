
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class SetLst : virtual public Set<Data>, // Must extend Set<Data>
                 virtual public List<Data> // Must extend List<Data>

  {

  private:
  protected:
    using Container::size;
    using List<Data>::Node;
    using List<Data>::head;
    using List<Data>::tail;

  public:
    // Default constructor
    SetLst() = default;

    /* ************************************************************************ */

    // Specific constructors
    SetLst(const TraversableContainer<Data> &); // A set obtained from a TraversableContainer
    SetLst(MappableContainer<Data> &&);         // A set obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    SetLst(const SetLst &);

    // Move constructor
    SetLst(SetLst &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~SetLst();

    /* ************************************************************************ */

    // Copy assignment
    SetLst &operator=(const SetLst &);

    // Move assignment
    SetLst &operator=(SetLst &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const SetLst &) const noexcept;
    inline bool operator!=(const SetLst &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    Data Min() const override;  // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    Data MinNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    void RemoveMin() override;  // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    virtual Data Max() const override;  // Must throw std::length_error when empty
    virtual Data MaxNRemove() override; // Must throw std::length_error when empty
    virtual void RemoveMax() override;  // Must throw std::length_error when empty

    virtual Data Predecessor(const Data &) const override;  // Must throw std::length_error when not found
    virtual Data PredecessorNRemove(const Data &) override; // Must throw std::length_error when not found
    virtual void RemovePredecessor(const Data &) override;  // Must throw std::length_error when not found

    virtual Data Successor(const Data &) const override;  // Must throw std::length_error when not found
    virtual Data SuccessorNRemove(const Data &) override; // Must throw std::length_error when not found
    virtual void RemoveSuccessor(const Data &) override;  // Must throw std::length_error when not found

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &) override; // Override DictionaryContainer member (copy of the value)
    bool Insert(Data &&) override;      // Override DictionaryContainer member (move of the value)
    bool Remove(const Data &) override; // Override DictionaryContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    const Data &operator[](unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    bool Exists(const Data &) const noexcept override; // Override TestableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() override; // Override ClearableContainer member

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */
}

#include "setlst.cpp"

#endif
