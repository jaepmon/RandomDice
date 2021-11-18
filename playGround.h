#pragma once
#include "gameNode.h"
#include "diceManager.h"
#include "enemyDiceManager.h"

class playGround : public gameNode
{
private:
	diceManager* _dm;
	enemyDiceManager* _edm;
	image* _gameOver;
	bool _isGameOver;
	

	RECT rc;
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	
};

