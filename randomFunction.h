#pragma once
#include "singletonBase.h"
#include <time.h>
#include <vector>

class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}

	inline int getInt(int num) { return rand() % num; }


	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum) + fromNum;
	}


	/*vector<int> _vNum;
	vector<int>::iterator _viNum;
	inline int getInt2(int num)
	{  
		int num1 = rand() % num;

		if (_vNum.empty()) _vNum.push_back(num1);

		for (int i = 0; i < _vNum.size(); i++) {
			if (_viNum[i] == num1) {
				//_vNum.push_back(num1);
				return num1;
			}
			else i++;

		}
	}*/

	//float 형 랜덤 값 생성하기 해봅시다
	float getFloat() { return (float)rand() / (float)RAND_MAX; }
	float getFloat(float num) { return ((float)rand() / (float)RAND_MAX) * num; }
	float getFromFloatTo(float fromFloat, float toFloat)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toFloat - fromFloat) + fromFloat);
	}
};

