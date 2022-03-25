#include "Crane.h"

//クレーンの位置やサイズを設定
void Crane::set(int windowWidth, int windowHeight, ofImage main, ofImage arm) {
	rotateSwitch = 0;
	rotateCrane = 0;
	width = main.getWidth();
	height = main.getHeight();
	armWidth = arm.getWidth();
	armHeight = arm.getHeight();
	x = windowWidth / 2;
	y = windowHeight / 2 - height;
	catchCheck = 0;
}

//クレーンを描画
void Crane::drawCrane(ofImage main, ofImage leftArm, ofImage rightArm, int width, int height) {
	armY = y + height / 10 * 8;
	
	//クレーンアーム回転
	ofPushMatrix();
	ofTranslate(x + this->width / 4, armY + armHeight * 3);
	ofRotateZDeg(-rotateCrane);
	leftArm.draw(-armWidth / 2, -armHeight);
	ofPopMatrix();


	ofPushMatrix();
	ofTranslate(x + this->width / 4 * 3, armY + armHeight * 3);
	ofRotateZDeg(rotateCrane);
	rightArm.draw(-armWidth / 2, -armHeight);
	ofPopMatrix();

	//クレーン本体
	main.draw(x, y);
}
//クレーン移動
void Crane::move(int key, int hiritsuX, int hiritsuY, int width, int height) {
	if (key == 'w' || key == 3) {
		y -= width / hiritsuX;
	}
	else if (key == 's' || key == 4) {
		y += width / hiritsuX;
	}
	else if (key == 'a' || key == 2) {
		x -= height / hiritsuY;
	}
	else if (key == 'd' || key == 1) {
		x += height / hiritsuY;
	}
}
//ボタンを押したとき
void Crane::catchRelease() {
	if (catchCheck == 0) {//キャッチ
		catchObject();
	}
	else if (catchCheck == 1) {//離す
		releaseObject();
	}
}
//キャッチ
void Crane::catchObject() {
		rotateSwitch = 1;
		catchCheck = 1;
}
//離す
void Crane::releaseObject() {
	rotateCrane = 0;
	rotateSwitch = 0;
	catchCheck = 0;
}
//アームの角度
void Crane::rotateArm() {
	if (rotateSwitch == 1) {
		rotateCrane += 1;
		if (rotateCrane > 5) {
			rotateSwitch = 2;//回し終わったら停止
		}
	}
}

