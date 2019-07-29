/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : strategy.h
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-15:20:13:29
 * Description:
 *
 */

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>

//减少代码中if和else语句

namespace strategy
{

	
	class TaxStrategy
	{
	public:
		virtual double Calculate() = 0;
		virtual ~TaxStrategy(){}
	};

	class CNTax : public TaxStrategy
	{
	public:
		virtual double Calculate() override
		{
			std::cout<<"CNTax Calculate"<<std::endl;
			return 0.1;
		}
	};

	class USTax : public TaxStrategy
	{
	public:
		virtual double Calculate() override
		{
			std::cout<<"USTax Calculate"<<std::endl;
			return 0.2;
		}
	};

	class DETax : public TaxStrategy
	{
	public:
		virtual double Calculate() override
		{
			std::cout<<"DETax Calculate"<<std::endl;
			return 0.3;
		}
	};


	class StrategyFactory
	{
	public:
		virtual TaxStrategy* NewStrategy() = 0;
		virtual ~StrategyFactory(){}
		
	};

	class CNTaxFactory : public StrategyFactory
	{
	public:
		virtual TaxStrategy* NewStrategy() override
		{
			std::cout<<"CNTaxFactory"<<std::endl;
			return new CNTax();
		}
	};

	class USTaxFactory : public StrategyFactory
	{
	public:
		virtual TaxStrategy* NewStrategy() override
		{
			std::cout<<"USTaxFactory"<<std::endl;
			return new USTax();
		}
	};
	
	class DETaxFactory : public StrategyFactory
	{
	public:
		virtual TaxStrategy* NewStrategy() override
		{
			std::cout<<"DETaxFactory"<<std::endl;
			return new DETax();
		}
	};
	
	class SalesOrder
	{
	private:
		TaxStrategy* strategy;
		
	public:
		SalesOrder(StrategyFactory* strategyFactory)
		{
			this->strategy = strategyFactory->NewStrategy();
		}

		~SalesOrder()
		{
			delete this->strategy;
		}

		double CalculateTax()
		{
			double val = this->strategy->Calculate();
			return val;
		}
	};


	void test_strategy();
	
}

#endif /* __STRATEGY_H__ */

