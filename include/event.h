/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : event.h
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-16:20:02:22
 * Description:
 *
 */

#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <list>
#include <string>

using namespace std;

namespace event{

	class Subject;

	class Observer
	{
		
	public:
		string name;
		Subject *sub;
		
	public:
		Observer(string name, Subject *sub)
		{
			this->name = name;
			this->sub = sub;
		}
		virtual void update() = 0;
		virtual ~Observer(){}
	};

	class Subject
	{
	protected:
		list<Observer*> oblist;
	public:
	    Subject(string n):name(n)
		{
			std::cout<<name<<std::endl;
		}
		virtual ~Subject(){}
		
		virtual void attach(Observer*) = 0;
		virtual void detach(Observer*) = 0;
		virtual void notify() = 0;
		string name;
	};
	
	class AObserver : public Observer
	{
	public:
	    AObserver(string name,Subject * sub) : Observer(name ,sub){}
		virtual void update() override
		{
			std::cout<<name<<":"<<sub->name<<std::endl;
		}

		virtual ~AObserver()
		{
			std::cout<<"delete AObserver!"<<std::endl;
		}
	};

	class BObserver : public Observer
	{
	public:
	    BObserver(string name,Subject * sub) : Observer(name ,sub){}
		virtual void update() override
		{
			std::cout<<name<<":"<<sub->name<<std::endl;
		}

		virtual ~BObserver()
		{
			std::cout<<"delete BObserver!"<<std::endl;
		}
	};

	

	class ChinaSubject : public Subject
	{
	public:
	    ChinaSubject(string name):Subject(name){}

		virtual void attach(Observer* ob) override
		{
			oblist.push_back(ob);
		}

		virtual void detach(Observer* ob) override
		{
			auto iter = oblist.begin();
			while(iter != oblist.end())
			{
				if ((*iter) == ob)
					iter = oblist.erase(iter);
				else
					++iter;
			}
		}

		virtual void notify() override
		{
			auto iter = oblist.begin();
			while(iter != oblist.end())
			{
				(*iter)->update();
				++iter;
			}
		}

		virtual ~ChinaSubject()
		{
			oblist.clear();
			std::cout<<"delete ChinaSubject!"<<std::endl;
		}
	};

	void test_event();
}

#endif /* __EVENT_H__ */

