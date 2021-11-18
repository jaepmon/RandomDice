#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);
	
	_isGameOver = false;

	IMAGEMANAGER->addImage("backGround", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255)); //배경

	IMAGEMANAGER->addImage("fireDice", "fireDice.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("iceDice", "iceDice.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("electronicDice", "electronicDice.bmp", 80, 80, true, RGB(255, 0, 255));
	_gameOver = IMAGEMANAGER->addImage("gameOver", "gameOver.bmp", 250, 135, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("enemyDice", "enemyDice.bmp", 80, 79, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fireBullet", "fireBullet.bmp", 17, 17, true, RGB(255, 0, 255));

	_dm = new diceManager;
	_dm->init();

	_edm = new enemyDiceManager;
	_edm->init();

	_dm->setEDiceMemoryLink(_edm);

	_edm->setDiceMemoryLink(_dm);

	

	rc = RectMakeCenter(WINSIZEX - 10, WINSIZEY - 60, 100, 10);

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();

	if (!_edm->getGameOver())
	{
		_dm->update();

		_edm->update();
	}
	
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============
	IMAGEMANAGER->findImage("backGround")->render(getMemDC());
	if (_edm->getGameOver())
	{
		_gameOver->render(getMemDC(), (WINSIZEX / 2)-130, (WINSIZEY / 2) -130);
		//IMAGEMANAGER->findImage("gameOver")->render(getMemDC());
	}
	_dm->render();
	_edm->render();

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

