#ifndef _OF_CRANE 
#define _OF_CRANE 

#include "ofMain.h"

class Crane
{
public:

	//位置
	int x;
	int y;
	int armY;
	//サイズ
	int width;
	int height;
	int armWidth;
	int armHeight;

	//回転処理
	int rotateSwitch;//回転スタート・ストップ
	int rotateCrane;//回転の角度

	//クレーンがものを持っているか
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