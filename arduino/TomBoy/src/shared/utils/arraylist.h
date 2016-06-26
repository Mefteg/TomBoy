#ifndef __TB_ARRAYLIST__
#define __TB_ARRAYLIST__

#define ARRAYLIST_GROW_FACTOR 2

#include "iarraylist.h"

#include <string.h>

template <typename T>
class ArrayList : public IArrayList<T>
{
public:
    ArrayList();
    ArrayList(unsigned int size);
    virtual ~ArrayList();

    virtual void    push_back(T element) override;
    virtual T       pop_back() override;

    virtual T       at(unsigned int index) override;

    virtual unsigned int getSize() const override { return m_size; }

protected:
    T*              m_elements;
    unsigned int    m_size;
    unsigned int    m_capacity;
};

template<typename T>
inline ArrayList<T>::ArrayList()
    : m_elements(0)
    , m_size(0)
    , m_capacity(0)
{
}

template<typename T>
inline ArrayList<T>::ArrayList(unsigned int size)
    : m_elements(0)
    , m_size(size)
    , m_capacity(size)
{
    m_elements = new T[m_capacity];
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
    delete[] m_elements;
}

template<typename T>
inline void ArrayList<T>::push_back(T element)
{
    // increase size
    ++m_size;

    // if the size is bigger than the capacity
    if (m_size > m_capacity)
    {
        // store capacity
        unsigned int oldCapacity = m_capacity;
        // increase capacity
        m_capacity = m_capacity > 0 ? (m_capacity * ARRAYLIST_GROW_FACTOR) : 1;

        // allocate bigger storage
        T* elements = new T[m_capacity];
        // copy elements to the new storage
        memcpy(elements, m_elements, sizeof(T) * (oldCapacity));
        // delete old storage
        delete[] m_elements;
        // store the new storage location
        m_elements = elements;
    }

    // store the new elements
    m_elements[m_size-1] = element;
}

template<typename T>
inline T ArrayList<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
    else
    {
        return T();
    }

    return m_elements[m_size + 1];
}

template<typename T>
inline T ArrayList<T>::at(unsigned int index)
{
    if (index < m_size)
    {
        return m_elements[index];
    }
    else
    {
        return T();
    }
}

#endif //__TB_ARRAYLIST__