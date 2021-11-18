#pragma once
#include "gameNode.h"
#include "dice.h"
#include <vector>
#include "bullets.h"

class enemyDiceManager;

enum tagDice
{
	fireDice,
	iceDice,
	electronicDice
};

struct tagDicePlate
{
	RECT rc;
	bool isCheck;
};




class diceManager : public gameNode
{
private:
	vector<dice*>			 _vDice;
	vector<dice*>::iterator  _viDice;
	
	int _rnd;
	dice* _dice;
	bool _isCheck;
	fireBullet* _fBullet;

	//에너미 다이스 매니저 포인터 선언
	enemyDiceManager* _eDice;
	
	tagDicePlate _dicePlate[15];

	int _diceMax;
	int rnd;
	int _score;
	
	vector<int> _vNum;
	vector<int>::iterator _viNum;

public:
	diceManager();
	~diceManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void diceBulletFire();
	
	virtual void collision();


	vector<dice*> getVDice() { return _vDice; }
	vector<dice*>::iterator getVIDice() { return _viDice; }

	void setEDiceMemoryLink(enemyDiceManager* edm) { _eDice = edm; }
};

