#pragma once
#include "gameNode.h"
#include "progressBar.h"

class enemyDice : public gameNode
{
protected:
	image* _eDice;  // 이미지
	RECT _rc;		// 렉트
	float _x, _y;   // 중점좌표
	bool _isCheck;
		
	progressBar* _hpBar;
	float _currentHP, _maxHP;
	

public:
	enemyDice();
	~enemyDice();

	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void hitfDamage(float damage);
	

	image* getEnemyDiceImage() { return _eDice; }	
	float getHPbar() { return _currentHP; }
	RECT getRect() { return _rc; }
	
	
};

