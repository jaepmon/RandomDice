#pragma once
#include "gameNode.h"


class dice : public gameNode
{
protected:
	image* _image;  // 이미지
	RECT _rc;		// 렉트
	float _x, _y;   // 중점좌표
	int _fireCount;
	
	dice* _dice;

public:
	dice();
	~dice();

	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();

	bool fbulletCountFire();

	RECT getfRect() { return _rc; }
};

