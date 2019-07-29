/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : test.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-06-27:10:27:27
 * Description:
 * 
 */

#include <iostream>
#include <bitset>
#include <cmath>
#include "test.h"

using namespace std;

#define ALIMAX(x, y) ((x) > (y) ? (x) : (y))
#define ALIMIN(x, y) ((x) < (y) ? (x) : (y))

float get_max_value(const float* src, size_t dataSize)
{
	float maxValue = src[0];
	for(uint i = 1; i < dataSize; ++i)
	{
		if(maxValue < src[i])
			maxValue = src[i];
	}
	return maxValue;
}

void preprocess_src(float* src, size_t dataSize)
{
	float maxValue = get_max_value(src,dataSize);
	for(uint i = 0; i < dataSize; ++i)
	{
		src[i] = -src[i] + maxValue;
	}
}

void tensor_exp(float* dst, const float* src, size_t dataSize)
{	

	float xLimit = 87;
	auto param = log(2.0f);
	cout<<"param="<<param<<endl;

	cout<<"print start:"<<endl;
	for (uint i = 0; i < dataSize; ++i)
	{
        auto x         = -src[i];//x <= 0
        x = ALIMAX(x, -xLimit);//x -> [-87 , 87]
        x = ALIMIN(x, xLimit);

        int div        = (x / param);//[-125,125] + 127 = [2,252]
        int div2       = (div + 127) << 23;
        auto xReamin   = x - div * param;
        float expBasic = *(float*)(&div2);

		bitset<8*sizeof(int)> b1(div2);

		cout<<"b1=";
		int tmp = 0;
		for(int j = 31; j >= 0; --j)
		{	
			if(tmp % 8 == 0 && tmp != 0)
				cout<<",";
			cout<<b1[j];
			++tmp;
		}
		cout<<endl;
		
		cout<<"&div2="<<&div2<<", (float*)(&div2)="<<(float*)(&div2)<<", *(float*)(&div2)="<<(*(float*)(&div2))<<endl;
		//cout<<"x="<<x<<", div="<<div<<", div2="<<div2<<", xReamin="<<xReamin<<", expBasic="<<expBasic<<endl;
        auto t         = xReamin;
        auto expRemain = ((((1.0f / 120 * t + 1.0f / 24) * t + 1.0f / 6) * t + 0.5f) * t + 1.0f) * t + 1.0f;
        dst[i]  = expBasic * expRemain;
    }
	cout<<"print end:"<<endl;
}

void softmax_process(float* dst, float* src, size_t dataSize)
{
	preprocess_src(src, dataSize);

	// cout<<"src:";
	// for(uint i = 0; i < dataSize; ++i)
	// {
	// 	cout<<src[i]<<",";
	// }
	// cout<<endl;
	
	tensor_exp(dst, src, dataSize);
}

int main()
{
	size_t dataSize = 10;
	float dst[dataSize]{0};
	float src[dataSize]{0};

	for(uint i = 0; i < dataSize; ++i)
	{
		src[i] = src[i] - 100 + i;
	}
	
	softmax_process(dst, src, dataSize);

	cout<<"dst:"<<endl;
	for(uint i = 0; i < dataSize; ++i)
	{
		cout<<dst[i]<<",";
	}
	cout<<endl;
	
	return 0;
}
