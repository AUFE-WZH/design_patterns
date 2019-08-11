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
