/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : abstract_factory.h
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-21:16:48:10
 * Description:
 *
 */

#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

#include <iostream>

namespace abstract_factory
{
	class A
	{
	public :
		A()
		{
			std::cout<<"A Creat"<<std::endl;	
		}
	};

	class B
	{
	public :
		B()
		{
			std::cout<<"B Creat"<<std::endl;
		}
	};


	class PA : public A
	{
	public:
		PA()
		{
			std::cout<<"PA Creat"<<std::endl;
		}
	};

	class PB : public B
	{
	public:
		PB()
		{
			std::cout<<"PB Creat"<<std::endl;
		}	
	};


	class QA : public A
	{
	public:
		QA()
		{
			std::cout<<"QA Creat"<<std::endl;
		}	
	};

	class QB : public B
	{
	public:
		QB()
		{
			std::cout<<"QB Creat"<<std::endl;
		}	
	};


	class Factory
	{
	public:
		Factory()
		{
			std::cout<<"Factory Creat"<<std::endl;
		}
		
		virtual A* CreatA() = 0;
		virtual B* CreatB() = 0;

		virtual ~Factory(){}
	};
		
	class PFactory : public Factory
	{
	public:
		PFactory()
		{
			std::cout<<"PFactory Creat"<<std::endl;
		}
		
		virtual A* CreatA() override
		{
			std::cout<<"PFactory CreatA"<<std::endl;
			return new PA();
		}
		
		virtual B* CreatB() override
		{
			std::cout<<"PFactory CreatB"<<std::endl;
			return new PB();
		}
		
	};
	
	class QFactory : public Factory
	{
	public:
		QFactory()
		{
			std::cout<<"QFactory Creat"<<std::endl;
		}
		
		virtual A* CreatA() override
		{
			std::cout<<"QFactory CreatA"<<std::endl;
			return new QA();
		}
		
		virtual B* CreatB() override
		{
			std::cout<<"QFactory CreatB"<<std::endl;
			return new QB();
		}
		
	};

	class Product
	{
	protected:
		Factory* factory;
	public:
	    Product(Factory* f) : factory(f)
		{
			std::cout<<"Product creat"<<std::endl;
		}
		
		void creatproduct()
		{
			factory->CreatA();
			factory->CreatB();
		}
	};
	
	void test_abstract_factory();
	
}

#endif /* __ABSTRACT_FACTORY_H__ */

