#include "pch.h"
#include "dice.h"

dice::dice()
{
}

dice::~dice()
{
}

HRESULT dice::init(const char* imageName, int x, int y)
{
	_fireCount = false;
	_image = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

	_rc = RectMake(_x, _y, _image->getWidth() , _image->getHeight());
	
	
	return S_OK;
}

void dice::release()
{
}

void dice::update()
{
	
}

void dice::render()
{
	
	_image->render(getMemDC(), _rc.left, _rc.top);
	
	
}

bool dice::fbulletCountFire()
{
 	_fireCount++;

	if (_fireCount == 40)
	{
		_fireCount = 0;
		return true;
	}
	return false;
}
