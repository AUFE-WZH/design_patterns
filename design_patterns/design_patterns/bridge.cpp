#include "bridge.h"

void bridge::test_bridge()
{
	//����ʱװ��
	//ƽ̨ʵ��
	bridge::MessagerImp* mImp = new bridge::PCMessagerImp();
	//ҵ����
	bridge::Messager* m = new bridge::MessagerLite(mImp);

	delete mImp;
	delete m;
}
