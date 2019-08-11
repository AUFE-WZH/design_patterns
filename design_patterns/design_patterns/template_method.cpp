#include <iostream>
#include "template_method.h"

using namespace std;

void template_method::test_template_method()
{
	template_method::Library* lib = new template_method::Application();
	lib->Run();
	delete lib;
}
