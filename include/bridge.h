/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : bridge.h
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-21:15:04:02
 * Description:
 *
 */

#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <iostream>

namespace bridge
{
	class Image{};

	//平台实现
	class MessagerImp
	{
	public:
		MessagerImp()
		{
			std::cout<<"MessagerImp creat"<<std::endl;
		}
		
		virtual void PlaySound() = 0;
		virtual void DrawShape() = 0;
		virtual void WriteText() = 0;
		virtual void Connet() = 0;

		virtual ~MessagerImp(){}
	};

	//业务功能
	class Messager
	{
	protected:
		MessagerImp* messagerImp;
	public:

	    Messager(MessagerImp* mImp) : messagerImp(mImp)
		{
			std::cout<<"Messager creat"<<std::endl;
		}
		
		virtual void Login(std::string name,std::string password) = 0;
		virtual void SendMessage(std::string message) = 0;
		virtual void SendPicture(Image image) = 0;

		virtual ~Messager(){}
	};

	class PCMessagerImp : public MessagerImp
	{
	public:
		PCMessagerImp()
		{
			std::cout<<"PCMessagerImp creat"<<std::endl;
		}
		
		virtual void PlaySound() override
		{
			std::cout<<"PCMessagerImp PlaySound"<<std::endl;
		}

		virtual void DrawShape() override
		{
			std::cout<<"PCMessagerImp DrawShape"<<std::endl;
		}
		
		virtual void WriteText() override
		{
			std::cout<<"PCMessagerImp WriteText"<<std::endl;
		}
		
		virtual void Connet() override
		{
			std::cout<<"PCMessagerImp Connet"<<std::endl;
		}

	};

	class MobileMessagerImp : public MessagerImp
	{
	public:
		MobileMessagerImp()
		{
			std::cout<<"MobileMessagerImp creat"<<std::endl;
		}
		
		virtual void PlaySound() override
		{
			std::cout<<"MobileMessagerImp PlaySound"<<std::endl;
		}

		virtual void DrawShape() override
		{
			std::cout<<"MobileMessagerImp DrawShape"<<std::endl;
		}
		
		virtual void WriteText() override
		{
			std::cout<<"MobileMessagerImp WriteText"<<std::endl;
		}
		
		virtual void Connet() override
		{
			std::cout<<"MobileMessagerImp Connet"<<std::endl;
		}

	};

	class MessagerLite : public Messager
	{
	public:
	    MessagerLite(MessagerImp* mImp) : Messager(mImp)
		{
			std::cout<<"MessagerLite creat"<<std::endl;
		}
		
		virtual void Login(std::string name,std::string password) override
		{
			messagerImp->Connet();
			std::cout<<"MessagerLite Login"<<std::endl;
		}

		virtual void SendMessage(std::string message) override
		{
			messagerImp->WriteText();
			std::cout<<"MessagerLite SendMessage"<<std::endl;
		}

		virtual void SendPicture(Image image) override
		{
			messagerImp->DrawShape();
			std::cout<<"MessagerLite SendPicture"<<std::endl;
		}
	};

	class MessagerPerfect : public Messager
	{
	public:
		MessagerPerfect(MessagerImp* mImp) : Messager(mImp)
		{
			std::cout<<"MessagerPerfect creat"<<std::endl;
		}
		
		virtual void Login(std::string name,std::string password) override
		{
			messagerImp->Connet();
			std::cout<<"MessagerPerfect Login"<<std::endl;
		}

		virtual void SendMessage(std::string message) override
		{
			messagerImp->WriteText();
			std::cout<<"MessagerPerfect SendMessage"<<std::endl;
		}

		virtual void SendPicture(Image image) override
		{
			messagerImp->DrawShape();
			std::cout<<"MessagerPerfect SendPicture"<<std::endl;
		}
	};

	void test_bridge();

}

#endif /* __BRIDGE_H__ */

