namespace lasd
{

    /* ************************************************************************** */

    // Specific constructors

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &container)
    {
        container.Traverse([this](const Data &data)
                           {
                               this->Insert(data); // Usa Insert per garantire l'unicità degli elementi
                           });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&container)
    {
        container.Map([this](Data &data)
                      {
                          this->Insert(std::move(data)); // Usa Insert con move per garantire l'unicità
                      });
    }

    /* ************************************************************************** */

    // Copy constructor
    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &set) : elements(set.elements) {}

    // Move constructor
    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&set) noexcept : elements(std::move(set.elements)) {}

    /* ************************************************************************** */

    // Destructor
    template <typename Data>
    SetVec<Data>::~SetVec()
    {
        Clear();
    }

    /* ************************************************************************** */

    // Copy assignment
    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &set)
    {
        if (this != &set)
        {
            elements = set.elements;
        }
        return *this;
    }

    // Move assignment
    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&set) noexcept
    {
        if (this != &set)
        {
            elements = std::move(set.elements);
        }
        return *this;
    }

    /* ************************************************************************** */

    // Comparison operators
    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &set) const noexcept
    {
        if (size != set.size)
            return false;

        for (unsigned long i = 0; i < size; i++)
        {
            if (!set.Exists(elements[i]))
                return false;
        }
        return true;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator!=(const SetVec<Data> &set) const noexcept
    {
        return !(*this == set);
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    template <typename Data>
    Data SetVec<Data>::Min() const
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data min = elements[0];
        for (unsigned long i = 1; i < size; i++)
        {
            if (elements[i] < min)
            {
                min = elements[i];
            }
        }
        return min;
    }

    template <typename Data>
    Data SetVec<Data>::MinNRemove()
    {
        Data min = Min();
        RemoveMin();
        return min;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data min = Min();
        Remove(min);
    }

    template <typename Data>
    Data SetVec<Data>::Max() const
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data max = elements[0];
        for (unsigned long i = 1; i < size; i++)
        {
            if (elements[i] > max)
            {
                max = elements[i];
            }
        }
        return max;
    }

    template <typename Data>
    Data SetVec<Data>::MaxNRemove()
    {
        Data max = Max();
        RemoveMax();
        return max;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data max = Max();
        Remove(max);
    }

    template <typename Data>
    Data SetVec<Data>::Predecessor(const Data &data) const
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        bool found = false;
        Data pred = data;

        for (unsigned long i = 0; i < size; i++)
        {
            if (elements[i] < data && (!found || elements[i] > pred))
            {
                pred = elements[i];
                found = true;
            }
        }

        if (!found)
            throw std::length_error("Predecessor not found!");
        return pred;
    }

    template <typename Data>
    Data SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        Data pred = Predecessor(data);
        RemovePredecessor(data);
        return pred;
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data pred = Predecessor(data);
        Remove(pred);
    }

    template <typename Data>
    Data SetVec<Data>::Successor(const Data &data) const
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        bool found = false;
        Data succ = data;

        for (unsigned long i = 0; i < size; i++)
        {
            if (elements[i] > data && (!found || elements[i] < succ))
            {
                succ = elements[i];
                found = true;
            }
        }

        if (!found)
            throw std::length_error("Successor not found!");
        return succ;
    }

    template <typename Data>
    Data SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        Data succ = Successor(data);
        RemoveSuccessor(data);
        return succ;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        if (size == 0)
            throw std::length_error("Set is empty!");

        Data succ = Successor(data);
        Remove(succ);
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from DictionaryContainer)

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        if (!Exists(data))
        {
            elements.Resize(size + 1);
            elements[size - 1] = data;
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        if (!Exists(data))
        {
            elements.Resize(size + 1);
            elements[size - 1] = std::move(data);
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
        for (unsigned long i = 0; i < size; i++)
        {
            if (elements[i] == data)
            {
                // Replace current element with last element and resize
                if (i < size - 1)
                {
                    elements[i] = std::move(elements[size - 1]);
                }
                elements.Resize(size - 1);
                return true;
            }
        }
        return false;
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from LinearContainer)

    template <typename Data>
    const Data &SetVec<Data>::operator[](unsigned long index) const
    {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return elements[index];
    }

    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        for (unsigned long i = 0; i < size; i++)
        {
            if (elements[i] == data)
            {
                return true;
            }
        }
        return false;
    }

    /* ************************************************************************** */

    // Specific member function (inherited from ClearableContainer)

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        elements.Clear();
    }

    /* ************************************************************************** */

    // Specific member function (inherited from ResizableContainer)

    template <typename Data>
    void SetVec<Data>::Resize(unsigned long newSize)
    {
        if (newSize < size)
        {
            elements.Resize(newSize);
        }
        // Se newSize >= size, non facciamo nulla poiché un set non può avere elementi vuoti
    }

    /* ************************************************************************** */

} // namespace lasd