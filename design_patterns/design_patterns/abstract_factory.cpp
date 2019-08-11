#include "abstract_factory.h"

void abstract_factory::test_abstract_factory()
{
	abstract_factory::Factory* fp = new abstract_factory::PFactory();
	abstract_factory::Factory* fq = new abstract_factory::QFactory();
	abstract_factory::Product p(fp);
	abstract_factory::Product q(fq);
	p.creatproduct();
	q.creatproduct();

	delete fp;
	delete fq;
}