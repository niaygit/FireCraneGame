#include "Crane.h"

//�N���[���̈ʒu��T�C�Y��ݒ�
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

//�N���[����`��
void Crane::drawCrane(ofImage main, ofImage leftArm, ofImage rightArm, int width, int height) {
	armY = y + height / 10 * 8;
	
	//�N���[���A�[����]
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

	//�N���[���{��
	main.draw(x, y);
}
//�N���[���ړ�
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
//�{�^�����������Ƃ�
void Crane::catchRelease() {
	if (catchCheck == 0) {//�L���b�`
		catchObject();
	}
	else if (catchCheck == 1) {//����
		releaseObject();
	}
}
//�L���b�`
void Crane::catchObject() {
		rotateSwitch = 1;
		catchCheck = 1;
}
//����
void Crane::releaseObject() {
	rotateCrane = 0;
	rotateSwitch = 0;
	catchCheck = 0;
}
//�A�[���̊p�x
void Crane::rotateArm() {
	if (rotateSwitch == 1) {
		rotateCrane += 1;
		if (rotateCrane > 5) {
			rotateSwitch = 2;//�񂵏I��������~
		}
	}
}

