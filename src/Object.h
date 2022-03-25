#ifndef _OF_OBJECT 
#define _OF_OBJECT

#include "ofMain.h"
#include "Crane.h"

class Object
{
public:
	string name;//オブジェクト名
	float color;//点滅色
	int hide;//オブジェクトの状態
	int x;//位置
	int y;//位置
	int stockX;//箱に入れた時の位置
	int stockY;//箱に入れた時の位置
	int width;//サイズ
	int height;//サイズ

	int hover = 50;

	ofImage image;//画像
	ofImage Mini;//箱に入れた時の縮小画像

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
