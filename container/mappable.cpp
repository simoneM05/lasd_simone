
namespace lasd
{

    /* ************************************************************************** */

    // Specific member functions (PreOrderMappableContainer)

    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun);
    }

    /* ************************************************************************** */

    // Specific member functions (PostOrderMappableContainer)

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun fun)
    {
        PostOrderMap(fun);
    }

    /* ************************************************************************** */
}
