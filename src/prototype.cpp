/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : prototype.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-22:21:21:28
 * Description:
 * 
 */

#include "prototype.h"

void prototype::test_prototype()
{
	prototype::Product* pa = new prototype::PA();
	prototype::Client* ca = new prototype::Client(pa);

	prototype::Product* pb = new prototype::PB();
	prototype::Client* cb = new prototype::Client(pb);

	ca->use_product();
	cb->use_product();
	
	delete pa;
	delete ca;
	delete pb;
	delete cb;
}
