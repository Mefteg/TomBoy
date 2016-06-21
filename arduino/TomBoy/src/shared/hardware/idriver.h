#ifndef __TB_IDRIVER__
#define __TB_IDRIVER__

class IDriver
{
public:
    virtual ~IDriver() {}

    virtual bool init() = 0;
};

#endif //__TB_IDRIVER__