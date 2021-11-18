#pragma once
#include "gameNode.h"
#include "enemyDice.h"
#include <vector>
#include "bullets.h"
#include "effect.h"
#define ENEMYMAX 18

class diceManager;

enum tagEnemyDice
{
	enemyDice1,
	bossDice1
};

class enemyDiceManager : public gameNode
{
private:

	vector<enemyDice*>					_vEDice;
	vector<enemyDice*>::iterator		_viEDice;
	
	fireBullet* _fBullet;
	diceManager* _dice;
	enemyDice* _ed;
	bool _isCheck, _isRespawn, _isFire, _isGameOver;
	int _respawnCount;
	RECT rc;
	effect* _effect;
	int _score;

public:
	enemyDiceManager();
	~enemyDiceManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void move();
	
	void removeDice();

	vector<enemyDice*> getVEDice() { return _vEDice; }
	vector<enemyDice*>::iterator getVIEDice() { return _viEDice; }
	int getScore() { return _score; }
	void setScore(int score) { _score = score; }
	
	bool getGameOver() { return _isGameOver; }
	
	void setDiceMemoryLink(diceManager* dm) { _dice = dm; }
};

