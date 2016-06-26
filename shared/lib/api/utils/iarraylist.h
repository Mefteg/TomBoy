#ifndef __TB_IARRAYLIST__
#define __TB_IARRAYLIST__

#define ARRAYLIST_GROW_FACTOR 2

#include <string.h>

template <typename T>
class IArrayList
{
public:
    virtual ~IArrayList() {}

    virtual void    push_back(T element) = 0;
    virtual T       pop_back() = 0;

    virtual T       at(unsigned int index) = 0;

    virtual unsigned int getSize() const = 0;
};

#endif //__TB_IARRAYLIST__