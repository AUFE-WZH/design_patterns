#include "strategy.h"

void strategy::test_strategy()
{
	strategy::StrategyFactory* sf = new strategy::CNTaxFactory();
	strategy::SalesOrder so(sf);
	so.CalculateTax();
	delete sf;
}
