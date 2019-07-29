/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : bridge.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-21:15:41:08
 * Description:
 * 
 */

#include "bridge.h"

void bridge::test_bridge()
{
	//运行时装配
	//平台实现
	bridge::MessagerImp* mImp = new bridge::PCMessagerImp();
	//业务功能
	bridge::Messager* m = new bridge::MessagerLite(mImp);

	delete mImp;
	delete m;
}
