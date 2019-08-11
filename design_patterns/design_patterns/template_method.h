#ifndef __TEMPLATE_MOTHOD_H__
#define __TEMPLATE_MOTHOD_H__

#include <iostream>

//Library�б����ȶ���Run()���̣�Application�д�ű仯

namespace template_method{

	class Library{

	public:
		void Run(){

			step1();

			if (step2())
			{
				step3();
			}

			step4();
			step5();
		}

		virtual ~Library(){}

	protected:

		void step1()   //����
		{
			std::cout << "Library step1" << std::endl;
		}
		void step3()    //����
		{
			std::cout << "Library step3" << std::endl;
		}
		void step5()   //����
		{
			std::cout << "Library step5" << std::endl;
		}

		//��
		virtual bool step2() = 0;
		virtual void step4() = 0;
	};


	class Application : public Library{
	protected:

		virtual bool step2() override
		{
			std::cout << "Application step2" << std::endl;
			return true;
		}
		virtual void step4()
		{
			std::cout << "Application step4" << std::endl;
		}
	};

	void test_template_method();

}

#endif /* __TEMPLATE_MOTHOD_H__ */

