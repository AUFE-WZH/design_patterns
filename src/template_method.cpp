/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : template_mothod.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-15:19:50:04
 * Description:
 * 
 */

#include <iostream>
#include "template_method.h"

using namespace std;

void template_method::test_template_method()
{
	template_method::Library* lib = new template_method::Application();
	lib->Run();
	delete lib;
}
