#include <iostream>

class Base
{
public :
    virtual ~Base() {} ;
    virtual void f( Base& b ) = 0 ;
} ;

 
// Project-specific header file
class A ; 
class B ;
class Target
{
public :
    virtual void f_impl( A& ) = 0 ;
    virtual void f_impl( B& ) = 0 ;
} ;

class Middle : public Target, public Base
{
} ;

template< class T > class F : virtual public Middle
{
protected :
    void f( Base& b )
        {
        static_cast< Middle& >( b )
        .f_impl( static_cast< T& >(*this) ) ;
        }
} ;

 
// Project-specific implementation file
using namespace std ;

class A : public F< A >
{
public :
    void f_impl( A& ) 
        { cout << "A-A" << endl ; }
    void f_impl( B& ) 
        { cout << "A-B" << endl ; }
} ;

class B : public F< B >
{
public :
    void f_impl( A& ) 
        { cout << "B-A" << endl ; }
    void f_impl( B& ) 
        { cout << "B-B" << endl ; }
} ;

// main函数
int main() {
    // 创建A和B的实例
    A a;
    B b;

    // 使用Base指针调用f
    Base* baseA = &a;
    Base* baseB = &b;

    // 调用A的f_impl(A&)（通过Base的f实现）
    baseA->f(*baseA);  // 输出: A-A

    // 调用A的f_impl(B&)（通过Base的f实现）
    baseA->f(*baseB);  // 输出: A-B

    // 调用B的f_impl(A&)（通过Base的f实现）
    baseB->f(*baseA);  // 输出: B-A

    // 调用B的f_impl(B&)（通过Base的f实现）
    baseB->f(*baseB);  // 输出: B-B

    return 0;
}