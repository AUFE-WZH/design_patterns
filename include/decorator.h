/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : decorator.h
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-20:20:52:05
 * Description:
 *
 */

#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>

namespace decorator{

	class Stream
	{
	public:
		Stream()
		{
			std::cout<<"Stream creat"<<std::endl;
		}
		
		virtual void Read(int number) = 0;
		virtual void Seek(int position) = 0;
		virtual void Write(char data) = 0;

		virtual ~Stream(){}
	};

	class FileStream : public Stream
	{
	public:
		FileStream()
		{
			std::cout<<"FileStream creat"<<std::endl;
		}
		
		virtual void Read(int number) override
		{
			std::cout<<"FileStream Read"<<std::endl;
		}
		
		virtual void Seek(int position) override
		{
			std::cout<<"FileStream Seek"<<std::endl;
		}
		
		virtual void Write(char data) override
		{
			std::cout<<"FileStream Write"<<std::endl;
		}
	};
	
	class NetworkStream : public Stream
	{
	public:
		NetworkStream()
		{
			std::cout<<"NetworkStream creat"<<std::endl;
		}
		
		virtual void Read(int number) override
		{
			std::cout<<"NetworkStream Read"<<std::endl;
		}
		
		virtual void Seek(int position) override
		{
			std::cout<<"NetworkStream Seek"<<std::endl;
		}
		
		virtual void Write(char data) override
		{
			std::cout<<"NetworkStream Write"<<std::endl;
		}
	};

	class MemoryStream : public Stream
	{
	public:
		MemoryStream()
		{
			std::cout<<"MemoryStream creat"<<std::endl;
		}
		
		virtual void Read(int number) override
		{
			std::cout<<"MemoryStream Read"<<std::endl;
		}
		
		virtual void Seek(int position) override
		{
			std::cout<<"MemoryStream Seek"<<std::endl;
		}
		
		virtual void Write(char data) override
		{
			std::cout<<"MemoryStream Write"<<std::endl;
		}
	};
	
	class DecoratorStream : public Stream
	{
	protected:
		Stream* stream;

	    DecoratorStream(Stream* stm) : stream(stm)
		{
			std::cout<<"DecoratorStream creat"<<std::endl;
		}
		
	};

	class CryptoStream : public DecoratorStream
	{
	public:
	    CryptoStream(Stream* stm) : DecoratorStream(stm)
		{
			std::cout<<"CryptoStream creat"<<std::endl;
		}

		virtual void Read(int number) override
		{
			//do something
			std::cout<<"CryptoStream Read"<<std::endl;
			stream->Read(number);
		}

		virtual void Seek(int position) override
		{
			//do something
			std::cout<<"CryptoStream Seek"<<std::endl;
			stream->Seek(position);
		}
		virtual void Write(char data) override
		{
			//do something
			std::cout<<"CryptoStream Write"<<std::endl;
			stream->Write(data);
		}
	};

	class BufferedStream : public DecoratorStream
	{
	public:
	    BufferedStream(Stream* stm) : DecoratorStream(stm)
		{
			std::cout<<"BufferedStream creat"<<std::endl;
		}

		virtual void Read(int number) override
		{
			//do something
			std::cout<<"BufferedStream Read"<<std::endl;
			stream->Read(number);
		}

		virtual void Seek(int position) override
		{
			//do something
			std::cout<<"BufferedStream Seek"<<std::endl;
			stream->Seek(position);
		}
		virtual void Write(char data) override
		{
			//do something
			std::cout<<"BufferedStream Write"<<std::endl;
			stream->Write(data);
		}
	};
	
	void test_decorator();
}

#endif /* __DECORATOR_H__ */

