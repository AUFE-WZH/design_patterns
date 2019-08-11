#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <iostream>

namespace prototype
{
	class Product
	{
	public:
		virtual Product* clone() = 0;
		virtual ~Product(){}
	};

	class PA : public Product
	{
	public:
		PA()
		{
			std::cout << "PA creat" << std::endl;
		}

		virtual Product* clone() override
		{
			std::cout << "PA clone" << std::endl;
			return new PA(*this);
		}

	};

	class PB : public Product
	{
	public:
		PB()
		{
			std::cout << "PB creat" << std::endl;
		}

		virtual Product* clone() override
		{
			std::cout << "PB clone" << std::endl;
			return new PB(*this);
		}

	};

	class Client
	{
	protected:
		Product* product;
	public:
		Client(Product* p) : product(p){}

		void use_product()
		{
			Product* clone_product = product->clone();

			delete clone_product;
		}
	};

	void test_prototype();
}
#endif /* __PROTOTYPE_H__ */

