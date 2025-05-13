
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data> &cont) : List<Data>(cont)
    {
    }

    template <typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data> &&cont) : List<Data>(cont)
    {
    }

    template <typename Data>
    SetLst<Data>::~SetLst()
    {
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &set)
    {
        List<Data>::operator=(set);
        return *this;
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(SetLst<Data> &&set) noexcept
    {
        List<Data>::operator=(std::move(set));
        return *this;
    }

    template <typename Data>
    inline bool SetLst<Data>::operator==(const SetLst<Data> &set) const noexcept
    {
        return List<Data>::operator==(set);
    }

    template <typename Data>
    inline bool SetLst<Data>::operator!=(const SetLst<Data> &set) const noexcept
    {
        return List<Data>::operator!=(set);
    }
    /* ************************************************************************** */
    // Specific member functions (inherited from OrderedDictionaryContainer)
    template <typename Data>
    Data SetLst<Data>::Max() const
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        return List<Data>::Back();
    }
    template <typename Data>
    Data SetLst<Data>::MaxNRemove()
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        Data max = List<Data>::BackNRemove();
        this->size--;
        return max;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        List<Data>::RemoveFromBack();
        this->size--;
    }

    /* ************************************************************************** */
    // Min

    template <typename Data>
    Data SetLst<Data>::Min() const
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        return List<Data>::Front();
    }

    template <typename Data>
    Data SetLst<Data>::MinNRemove()
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        Data min = List<Data>::FrontNRemove();
        this->size--;
        return min;
    }
    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        List<Data>::RemoveFromFront();
        this->size--;
    }

    /* ************************************************************************** */

    // Predecessor
    template <typename Data>
    Data SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Front() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->next->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        return temp->element;
    }
    template <typename Data>
    Data SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Front() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->next->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        Data pred = temp->element;
        List<Data>::RemoveFromFront();
        this->size--;
        return pred;
    }
    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Front() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->next->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        List<Data>::RemoveFromFront();
        this->size--;
    }
    /* ************************************************************************** */
    // Successor
    template <typename Data>
    Data SetLst<Data>::Successor(const Data &dat) const
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Back() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        return temp->next->element;
    }
    template <typename Data>
    Data SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Back() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        Data succ = temp->next->element;
        List<Data>::RemoveFromFront();
        this->size--;
        return succ;
    }
    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Back() == dat)
            throw std::length_error("Element not found");
        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            throw std::length_error("Element not found");
        List<Data>::RemoveFromFront();
        this->size--;
    }
    /* ************************************************************************** */
    // Insert
    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        for (typename List<Data>::Node *cur = this->head; cur != nullptr; cur = cur->next)
        {
            if (cur->element == dat)
                return false;
        }
        List<Data>::InsertAtBack(dat);
        return true;
    }
    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        for (typename List<Data>::Node *cur = this->head; cur != nullptr; cur = cur->next)
        {
            if (cur->element == dat)
                return false;
        }
        List<Data>::InsertAtBack(std::move(dat));
        return true;
    }
    /* ************************************************************************** */
    // Remove
    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        if (this->size == 0)
            throw std::length_error("Set is empty");
        if (List<Data>::Front() == dat)
        {
            List<Data>::RemoveFromFront();
            this->size--;
            return true;
        }

        typename List<Data>::Node *temp = List<Data>::head;
        while (temp->next != nullptr && temp->next->element != dat)
            temp = temp->next;
        if (temp->next == nullptr)
            return false;
        temp->next = temp->next->next;
        this->size--;
        return true;
    }
    /* ************************************************************************** */
    // Speecific member functions (inherited from LinearContainer)
    template <typename Data>
    const Data &SetLst<Data>::operator[](unsigned long index) const
    {
        if (index >= this->size)
            throw std::length_error("Index out of range");
        typename List<Data>::Node *temp = List<Data>::head;
        for (unsigned long i = 0; i < index; i++)
            temp = temp->next;
        return temp->element;
    }

    /* ***************************************************************************/
    // Specific member functions (inherited from TestableContainer)
    template <typename Data>
    bool SetLst<Data>::Exists(const Data &dat) const noexcept
    {
        for (typename List<Data>::Node *cur = this->head; cur != nullptr; cur = cur->next)
        {
            if (cur->element == dat)
                return true;
        }
        return false;
    }
    /* ************************************************************************** */
    // Specific member function (inherited from ClearableContainer)
    template <typename Data>
    void SetLst<Data>::Clear()
    {
        List<Data>::Clear();
        this->size = 0;
    }
    /* ************************************************************************** */
}
