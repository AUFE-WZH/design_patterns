#ifndef __FACTORY_MOTHOD_H__
#define __FACTORY_MOTHOD_H__

#include <iostream>

namespace factory_method
{

	class ISplitter
	{
	public:
		virtual void split() = 0;
		virtual ~ISplitter(){}
	};

	class SplitterFactory
	{
	public:
		virtual ISplitter* CreateSplitter() = 0;
		virtual ~SplitterFactory(){}
	};




	//具体类
	class BinarySplitter : public ISplitter
	{
	public:
		virtual void split() override
		{
			std::cout << "BinarySplitter" << std::endl;
		}
	};

	class TxtSplitter : public ISplitter
	{
	public:
		virtual void split() override
		{
			std::cout << "TxtSplitter" << std::endl;
		}
	};

	class PictureSplitter : public ISplitter
	{
	public:
		virtual void split() override
		{
			std::cout << "PictureSplitter" << std::endl;
		}
	};

	class VideoSplitter : public ISplitter
	{
	public:
		virtual void split() override
		{
			std::cout << "VideoSplitter" << std::endl;
		}
	};

	//具体工厂类
	class BinarySplitterFactory : public SplitterFactory
	{
	public:
		virtual ISplitter* CreateSplitter()
		{
			std::cout << "BinarySplitterFactory" << std::endl;
			return new BinarySplitter();
		}
	};

	class TxtSplitterFactory : public SplitterFactory
	{
	public:
		virtual ISplitter* CreateSplitter()
		{
			std::cout << "TxtSplitterFactory" << std::endl;
			return new TxtSplitter();
		}
	};

	class PictureSplitterFactory : public SplitterFactory
	{
	public:
		virtual ISplitter* CreateSplitter()
		{
			std::cout << "PictureSplitterFactory" << std::endl;
			return new PictureSplitter();
		}
	};

	class VideoSplitterFactory : public SplitterFactory
	{
	public:
		virtual ISplitter* CreateSplitter()
		{
			std::cout << "VideoSplitterFactory" << std::endl;
			return new VideoSplitter();
		}
	};

	class MainForm
	{
	private:
		SplitterFactory* factory;
	public:
		MainForm(SplitterFactory* sf)
		{
			this->factory = sf;
		}

		void click()
		{
			//两个抽象基类ISplitter,SplitterFactory
			ISplitter* splitter = factory->CreateSplitter();
			splitter->split();
		}
	};

	void test_factory_method();

}

#endif /* __FACTORY_MOTHOD_H__ */

