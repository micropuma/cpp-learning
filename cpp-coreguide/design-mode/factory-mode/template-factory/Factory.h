#pragma once  

// 抽象模版工厂类
template <class AbstractProduct_t>
class AbstractFactory {
public:
    virtual AbstractProduct_t *CreateProduct() = 0;
    virtual ~AbstractFactory() {}
};

// 具体模版工厂类  
template <class AbstractProduct_t, class ConcreteProduct_t> 
class ConcreteFactory : public AbstractFactory<AbstractProduct_t> {
public:
    AbstractProduct_t *CreateProduct()
    {
        return new ConcreteProduct_t();
    }
};



