#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;		//�Ѿ��� �̹���
	RECT rc;				//�Ѿ��� ��Ʈ
	float x, y;				//�Ѿ��� ����
	float angle;			//�Ѿ��� ����
	float radius;			//�Ѿ��� ������
	float speed;			//�Ѿ��� ���ǵ�
	float fireX, fireY;		//�Ѿ��� �߻���ġ
	bool isFire;			//�Ѿ��� �߻�����
	int count;
};

//fireDice �Ѿ�
class fireBullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
	
	
public:
	fireBullet() {};
	~fireBullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update(RECT rc);
	void render();

	void fire(float x, float y, float speed);

	void move(RECT rc);

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet()			 { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

	

};


