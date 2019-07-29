/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : decorator.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-20:21:20:37
 * Description:
 * 
 */

#include "decorator.h"

void decorator::test_decorator()
{
	decorator::FileStream* fs = new decorator::FileStream();

	decorator::CryptoStream* cs = new decorator::CryptoStream(fs);

	decorator::BufferedStream* bs = new decorator::BufferedStream(fs);

	decorator::BufferedStream* bcs = new decorator::BufferedStream(cs);

	delete bcs;
	delete bs;
	delete cs;
	delete fs;
}
