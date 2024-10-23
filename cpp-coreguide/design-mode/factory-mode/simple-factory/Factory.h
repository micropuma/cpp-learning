#pragma once
#include "Product.h"  

// 总厂
class Factory
{
public:
    virtual Shoe *CreateShoes() = 0;
	virtual Clothe *CreateClothe() = 0;
    virtual ~Factory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public Factory
{
public:
    Shoe *CreateShoes()
    {
        return new NikeShoe();
    }
	
	Clothe *CreateClothe()
    {
        return new NikeClothe();
    }
};