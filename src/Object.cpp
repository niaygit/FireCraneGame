#include "Object.h"
#include "Crane.h"

//オブジェクトの位置やサイズを設定
void Object::set(string name, int hide, int x, int y, ofImage image, ofImage Mini) {
	this->color = 255;
	this->name = name;
	this->hide = hide;
	this->x = x;
	this->y = y;
	this->image = image;
	this->width = image.getWidth();
	this->height = image.getHeight();
	this->Mini = Mini;
}

//オブジェクトを表示
void Object::show(int index, int craneX, int craneY, int craneWidth, int craneHeight, int craneArmY, int boxX, int boxY, int boxWidth, int boxHeight, Crane crane) {
	
	if (hide == 0) {//点滅など
		colorChange(craneX, craneY, craneWidth, craneHeight);
	}
	else if (hide == 1) {//ゲットしたものを持ち上げ
		carry(craneX, craneY, craneWidth, craneHeight);
	}
	else if (hide == 2) {//箱に入れる
		putIn(index, boxX, boxY, boxWidth, boxHeight, Mini);
	}
}
//点滅など
void Object::colorChange(int craneX, int craneY, int craneWidth, int craneHeight) {
	
	color -= 3;//点滅
	if (color < 0) {
		color = 255;
	}
	if (((craneX <= x + width + hover && craneX >= x - hover) || (craneX + craneWidth <= x + width + hover && craneX + craneWidth >= x - hover)) && (craneY + craneHeight >= y - hover && craneY + craneHeight <= y + height + hover)) {
		ofSetColor(255, color, color);//クレーンが乗ると光る
	}
	image.draw(x, y);
	ofSetColor(255, 255, 255);
}
//箱に入れる
void Object::putIn(int index, int boxX, int boxY, int boxWidth, int boxHeight, ofImage Mini) {
	x = boxX + boxWidth / 7 * index;
	y = boxY + boxHeight / 3;
	Mini.draw(x, y);
}//クレーンで持ち運ぶ
void Object::carry(int craneX, int craneY, int craneWidth, int craneHeight) {
	x = craneX + craneWidth / 2 - this->width / 2;
	y = craneY + craneHeight - this->height / 2;
	image.draw(x, y);
}


//ボタンを押したとき
void Object::stock(int craneX, int craneY, int craneWidth, int craneHeight, int boxY, int rotateSwitch, int& point, ofSoundPlayer click) {
	//持ち上げ
	if (hide == 0) {
		if (((craneX <= x + width + hover && craneX >= x - hover) || (craneX + craneWidth <= x + width + hover && craneX + craneWidth >= x - hover)) && (craneY + craneHeight >= y - hover && craneY + craneHeight <= y + height + hover)) {
			lift(click);
		}
	}
	//箱に入れる
	else if (hide == 1 && y + height >= boxY) {
		inputSwitchOn(click);
		point++;
	}
}
//持ち上げ
void Object::lift(ofSoundPlayer click) {
	hide = 1;
}
//箱に入れるスイッチ
void Object::inputSwitchOn(ofSoundPlayer click) {
	hide = 2;
}

