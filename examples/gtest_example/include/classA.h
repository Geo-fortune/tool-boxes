

#include <string>

class A
{
public:
    A() ;
    // ~A() = default;
    ~A() ;

public:
    template <typename T>
    T add(T &a, T &b)
    {
        return a+b;
    }

    template <typename T>
    T multiply(T &a, T &b)
    {
        return a*b;
    }

};
