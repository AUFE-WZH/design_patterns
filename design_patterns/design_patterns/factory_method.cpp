#include "factory_method.h"

void factory_method::test_factory_method()
{
	factory_method::SplitterFactory* sf = new factory_method::BinarySplitterFactory();
	factory_method::MainForm mainform(sf);
	mainform.click();

	delete sf;
}

