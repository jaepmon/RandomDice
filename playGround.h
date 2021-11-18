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

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

