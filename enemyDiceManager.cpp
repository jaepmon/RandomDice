#include "pch.h"
#include "enemyDiceManager.h"
#include "diceManager.h"

enemyDiceManager::enemyDiceManager()
{
}

enemyDiceManager::~enemyDiceManager()
{
}

HRESULT enemyDiceManager::init()
{
	_score = 6;
	_isGameOver = false;
	_isCheck = false;
	
	rc = RectMakeCenter(WINSIZEX - 10, WINSIZEY - 60, 100, 10);
	
	_isRespawn = _respawnCount = 0;
	return S_OK;
}

void enemyDiceManager::release()
{
}

void enemyDiceManager::update()
{
	if (_isGameOver == false)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_isCheck = true;
		}
		if (_isCheck == true)
		{
			if (!_isRespawn)
			{
				if (_vEDice.size() > 18) _isRespawn = true;

				_respawnCount++;

				if (_respawnCount % 120 == 0)
				{
					enemyDice* enemy;
					ZeroMemory(&enemy, sizeof(enemy));

					enemy = new enemyDice;
					enemy->init("enemyDice", 47, 400);
					_isFire = false;

					_vEDice.push_back(enemy);

					_respawnCount = 0;				
				}

				
			}
			for (_viEDice = _vEDice.begin(); _viEDice != _vEDice.end(); ++_viEDice)
			{			
				RECT temp;
				RECT rc1 = _viEDice[0]->getRect();
				if (IntersectRect(&temp, &rc1, &rc))
				{
					_isGameOver = true;
				}
			}
		}
	}
	removeDice();
	move();
}


void enemyDiceManager::move()
{
	for (_viEDice = _vEDice.begin(); _viEDice != _vEDice.end(); ++_viEDice)
	{
		(*_viEDice)->update();
	}
}

void enemyDiceManager::removeDice()
{
	for (int i = 0; i < _vEDice.size(); i++)
	{
		if (_vEDice[i]->getHPbar() <= 0)
		{
			
			_vEDice.erase(_vEDice.begin() + i);
			_score++;
		}
	}
	
	
}

void enemyDiceManager::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), rc);
	}
	for (_viEDice = _vEDice.begin(); _viEDice != _vEDice.end(); ++_viEDice)
	{
		(*_viEDice)->render();	
	}
	char str[128];
	sprintf_s(str, " : %d ", _score);
	TextOut(getMemDC(), 110, 555, str, strlen(str));
	TextOut(getMemDC(), 305, 440, "SPACE BAR!", strlen("SPACE BAR!"));
	TextOut(getMemDC(), 350, 547, "2", strlen("2"));
}





