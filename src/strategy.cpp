/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : strategy.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-15:20:31:44
 * Description:
 * 
 */
#include "strategy.h"

void strategy::test_strategy()
{
	strategy::StrategyFactory* sf = new strategy::CNTaxFactory();
	strategy::SalesOrder so(sf);
	so.CalculateTax();
	delete sf;
}
