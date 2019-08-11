#include "design_patterns.h"

int main(int argc, char** argv)
{
	std::cout << "=================================" << std::endl;
	std::cout << "template_method:" << std::endl;
	template_method::test_template_method();
	std::cout << "=================================" << std::endl;
	std::cout << "test_factory_method:" << std::endl;
	factory_method::test_factory_method();
	std::cout << "=================================" << std::endl;
	std::cout << "test_strategy:" << std::endl;
	strategy::test_strategy();
	std::cout << "=================================" << std::endl;
	std::cout << "test_event:" << std::endl;
	event::test_event();
	std::cout << "=================================" << std::endl;
	std::cout << "test_decorator:" << std::endl;
	decorator::test_decorator();
	std::cout << "=================================" << std::endl;
	std::cout << "test_bridge:" << std::endl;
	bridge::test_bridge();
	std::cout << "=================================" << std::endl;
	std::cout << "test_abstract_factory:" << std::endl;
	abstract_factory::test_abstract_factory();
	std::cout << "=================================" << std::endl;
	std::cout << "test_prototype:" << std::endl;
	prototype::test_prototype();
	std::cout << "=================================" << std::endl;
	return 0;
}
