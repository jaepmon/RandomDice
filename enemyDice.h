#pragma once
#include "gameNode.h"
#include "progressBar.h"

class enemyDice : public gameNode
{
protected:
	image* _eDice;  // �̹���
	RECT _rc;		// ��Ʈ
	float _x, _y;   // ������ǥ
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

