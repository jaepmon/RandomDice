#include "pch.h"
#include "diceManager.h"
#include "enemyDiceManager.h"



diceManager::diceManager()
{
}

diceManager::~diceManager()
{
}

HRESULT diceManager::init()
{
	_fBullet = new fireBullet;
	_fBullet->init("fireBullet", 300,800);
	_isCheck = false;
	_diceMax = 30;

	for (int i = 0; i < 5; i++)
	{
		_dicePlate[i].rc = RectMakeCenter(84 * i + 180, 185, 80, 80);
		_dicePlate[i].isCheck = false;
	}
	for (int i = 5; i < 10; i++)
	{
		_dicePlate[i].rc = RectMakeCenter(84 * i - 240, 275, 80, 80);
		_dicePlate[i].isCheck = false;
	}
	for (int i = 10; i < 15; i++)
	{
		_dicePlate[i].rc = RectMakeCenter(84 * i - 660, 365, 80, 80);
		_dicePlate[i].isCheck = false;
	}
	
	return S_OK;
}

void diceManager::release()
{
}

void diceManager::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_eDice->setScore(_eDice->getScore()-2);
		if (_diceMax < _vDice.size()) return;

		for (int i = 0; i < 15; i++)
		{
			rnd = RND->getFromIntTo(0, 15);

			if (_dicePlate[rnd].isCheck == true) continue;

			_dicePlate[rnd].isCheck = true;

			_rnd = RND->getFromIntTo(0, 3);

			switch (_rnd)
			{
			case 0:
			{
				dice* _dice;
				_dice = new dice;
				_dice->init("fireDice", _dicePlate[rnd].rc.left, _dicePlate[rnd].rc.top);
				_vDice.push_back(_dice);
				
			}
			break;
			case 1:
			{
				dice* _dice;
				_dice = new dice;
				_dice->init("iceDice", _dicePlate[rnd].rc.left, _dicePlate[rnd].rc.top);
				_vDice.push_back(_dice);
				
			}
			break;
			case 2:
				{
					dice* _dice;
					_dice = new dice;
					_dice->init("electronicDice", _dicePlate[rnd].rc.left, _dicePlate[rnd].rc.top);
					_vDice.push_back(_dice);
					_score - 2;
				}
			break;
			}
			break;
		}
	}

	if (_vDice.size() > 0)
	diceBulletFire();

	for (int i = 0; i < _eDice->getVEDice().size(); ++i)
	{
		_fBullet->update(_eDice->getVEDice()[0]->getRect());
	}
	collision();
}

void diceManager::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < 15; i++)
		{
			Rectangle(getMemDC(), _dicePlate[i].rc);
		}
	}
	for (_viDice = _vDice.begin(); _viDice != _vDice.end(); ++_viDice)
	{
		(*_viDice)->render();
	}	
	_fBullet->render();
}

void diceManager::diceBulletFire()
{
	for (_viDice = _vDice.begin(); _viDice != _vDice.end(); ++_viDice)
	{
		if((*_viDice)->fbulletCountFire())
		{
			RECT rc = (*_viDice)->getfRect();

			_fBullet->fire((rc.left + rc.right) / 2, rc.top - 5, 5.0f);
		}
	}
}

void diceManager::collision()
{
	
	for (int i = 0; i < _fBullet->getVBullet().size(); i++)
	{
		for (int j = 0; j < _eDice->getVEDice().size(); j++)
		{
			RECT temp;
			RECT rc1 = _fBullet->getVBullet()[i].rc;
			RECT rc2 = 	_eDice->getVEDice()[j]->getRect();
			if (IntersectRect(&temp, &rc1, &rc2))
			{
				_fBullet->removeBullet(i);
				_eDice->getVEDice()[j]->hitfDamage(8.0f);
				break;
			}		
		}
	}
}



