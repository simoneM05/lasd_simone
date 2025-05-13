
namespace lasd
{

    /* ************************************************************************** */

    // Comparison operators (LinearContainer)

    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data> &con) const noexcept
    {
        if (this->size == con.size)
        {
            for (unsigned long index = 0; index < this->size; ++index)
            {
                if (operator[](index) != con.operator[](index))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    /* ************************************************************************** */

    // Specific member functions

    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const
    {
        return operator[](0);
    }

    template <typename Data>
    inline const Data &LinearContainer<Data>::Back() const
    {
        return operator[](this->size - 1);
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        for (unsigned long index = 0; index < this->size; ++index)
        {
            fun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        unsigned long index = this->size;
        while (index > 0)
        {
            fun(operator[](--index));
        }
    }

    /* ************************************************************************** */
    // Specific member functions (MutableLinearContainer)
    // (mutable version; concrete function must throw std::length_error when empty)
    template <typename Data>
    inline Data &MutableLinearContainer<Data>::Back()
    {
        return operator[](this->size - 1);
    }
    template <typename Data>
    inline Data &MutableLinearContainer<Data>::Front()
    {
        return operator[](0);
    }

    // MutableLinearContainer<Data>::Map(MapFun fun)
    template <typename Data>
    inline void MutableLinearContainer<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun);
    }

    // MutableLinearContainer<Data>::PreOrderMap(MapFun fun)
    template <typename Data>
    inline void MutableLinearContainer<Data>::PreOrderMap(MapFun fun)
    {
        for (unsigned long index = 0; index < this->size; ++index)
        {
            fun(operator[](index));
        }
    }

    // MutableLinearContainer<Data>::PostOrderMap(MapFun fun)
    template <typename Data>
    inline void MutableLinearContainer<Data>::PostOrderMap(MapFun fun)
    {
        unsigned long index = this->size;
        while (index > 0)
        {
            fun(operator[](--index));
        }
    }

    /* ************************************************************************** */

    // Specific member functions (SortableLinearContainer)

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept
    {
        QuickSort(0, this->size - 1);
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(unsigned long p, unsigned long r) noexcept
    {
        if (p < r)
        {
            unsigned long q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q + 1, r);
        }
    }

    template <typename Data>
    unsigned long SortableLinearContainer<Data>::Partition(unsigned long p, unsigned long r) noexcept
    {
        Data x = this->operator[](p);
        unsigned long i = p - 1;
        unsigned long j = r + 1;
        do
        {
            do
            {
                j--;
            } while (x < this->operator[](j));
            do
            {
                i++;
            } while (x > this->operator[](i));
            if (i < j)
            {
                std::swap(this->operator[](i), this->operator[](j));
            }
        } while (i < j);
        return j;
    }

    /* ************************************************************************** */

}
