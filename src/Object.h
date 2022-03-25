#ifndef _OF_OBJECT 
#define _OF_OBJECT

#include "ofMain.h"
#include "Crane.h"

class Object
{
public:
	string name;//�I�u�W�F�N�g��
	float color;//�_�ŐF
	int hide;//�I�u�W�F�N�g�̏��
	int x;//�ʒu
	int y;//�ʒu
	int stockX;//���ɓ��ꂽ���̈ʒu
	int stockY;//���ɓ��ꂽ���̈ʒu
	int width;//�T�C�Y
	int height;//�T�C�Y

	int hover = 50;

	ofImage image;//�摜
	ofImage Mini;//���ɓ��ꂽ���̏k���摜

	void set(string name, int hide, int x, int y, ofImage image, ofImage Mini);
	void show(int index, int craneX, int craneY, int craneWidth, int craneHeight, int craneArmY, int boxX, int boxY, int boxWidth, int boxHeight, Crane crane);
	void colorChange(int craneX, int craneY, int craneWidth, int craneHeight);
	void putIn(int index, int boxX, int boxY, int boxWidth, int boxHeigh, ofImage Mini);
	void carry(int craneX, int craneY, int craneWidth, int craneHeight);
	void stock(int craneX, int craneY, int craneWidth, int craneHeight, int boxY, int rotateSwitch, int& point, ofSoundPlayer click);
	void lift(ofSoundPlayer click);
	void inputSwitchOn(ofSoundPlayer click);
};

#endif 
