#ifndef _OF_CRANE 
#define _OF_CRANE 

#include "ofMain.h"

class Crane
{
public:

	//�ʒu
	int x;
	int y;
	int armY;
	//�T�C�Y
	int width;
	int height;
	int armWidth;
	int armHeight;

	//��]����
	int rotateSwitch;//��]�X�^�[�g�E�X�g�b�v
	int rotateCrane;//��]�̊p�x

	//�N���[�������̂������Ă��邩
	int catchCheck;

	void set(int windowWidth, int windowHeight, ofImage main, ofImage arm);
	void drawCrane(ofImage main, ofImage leftArm, ofImage rightArm, int width, int height);
	void move(int key, int hiritsuX, int hiritsuY, int width, int height);
	void catchObject();
	void releaseObject();
	void catchRelease();
	void rotateArm();
};

#endif 