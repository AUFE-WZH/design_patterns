/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : factory_mothod.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-15:21:39:22
 * Description:
 * 
 */
#include "factory_method.h"

void factory_method::test_factory_method()
{
	factory_method::SplitterFactory* sf = new factory_method::BinarySplitterFactory();
	factory_method::MainForm mainform(sf);
	mainform.click();

	delete sf;
}

