#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class SetVec : virtual public Set<Data>, virtual public ResizableContainer
  {

  private:
    Vector<Data> elements; // Aggiungiamo un vettore per memorizzare gli elementi

  protected:
    using Container::size;

  public:
    SetVec() = default; // Default constructor

    /* ************************************************************************ */

    // Specific constructors
    SetVec(const TraversableContainer<Data> &); // SetVec(argument) specifiers; // A set obtained from a TraversableContainer
    SetVec(MappableContainer<Data> &&);         // A set obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    SetVec(const SetVec &);

    // Move constructor
    SetVec(SetVec &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~SetVec();

    /* ************************************************************************ */
    // Copy assignment
    SetVec &operator=(const SetVec &);

    // Move assignment
    SetVec &operator=(SetVec &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const SetVec &) const noexcept;
    inline bool operator!=(const SetVec &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    virtual Data Min() const override;  // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    virtual Data MinNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    virtual void RemoveMin() override;  // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

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

    /* ************************************************************************ */

    // Specific member function (inherited from ResizableContainer)

    // Implementiamo il metodo mancante Resize
    virtual void Resize(unsigned long) override; // Override ResizableContainer member

    /* ************************************************************************ */
  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "setvec.cpp"

#endif