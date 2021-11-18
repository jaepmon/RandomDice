#include "pch.h"
#include "enemyDice.h"

enemyDice::enemyDice()
{
}

enemyDice::~enemyDice()
{
}

HRESULT enemyDice::init(const char * imageName, int x, int y)
{
	_eDice = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, _eDice->getWidth(), _eDice->getHeight());

	_currentHP = _maxHP = 100;
	_hpBar = new progressBar;
	_hpBar->init(_x-25,_y, 52, 10);
	_hpBar->setGauge(_currentHP, _maxHP); 

	return S_OK;
}

void enemyDice::release()
{
}

void enemyDice::update()
{
	_y -= 3;
	if (_rc.top < 20)
	{
		_isCheck = true;
		if (_isCheck == true)
		{
			_y += 3;
			_x += 3;
		}
	}
	if (_rc.right > 687)
	{
		_isCheck = false;
		if (_isCheck == false)
			{
				_y += 6;
			}
	}
	_rc = RectMakeCenter(_x, _y, _eDice->getWidth(), _eDice->getHeight());	

	
	_hpBar->setX(_x - 25);
	_hpBar->setY(_y - 60);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();

}

void enemyDice::render()
{
	//Rectangle(getMemDC(), rc);
	
	_eDice->render(getMemDC(), _rc.left, _rc.top);
 	_hpBar->render();
}

void enemyDice::hitfDamage(float damage)
{
	_currentHP -= damage;
}

