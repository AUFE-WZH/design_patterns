#include "decorator.h"

void decorator::test_decorator()
{
	decorator::FileStream* fs = new decorator::FileStream();

	decorator::CryptoStream* cs = new decorator::CryptoStream(fs);

	decorator::BufferedStream* bs = new decorator::BufferedStream(fs);

	decorator::BufferedStream* bcs = new decorator::BufferedStream(cs);

	delete bcs;
	delete bs;
	delete cs;
	delete fs;
}
