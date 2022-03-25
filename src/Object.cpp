#include "Object.h"
#include "Crane.h"

//�I�u�W�F�N�g�̈ʒu��T�C�Y��ݒ�
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

//�I�u�W�F�N�g��\��
void Object::show(int index, int craneX, int craneY, int craneWidth, int craneHeight, int craneArmY, int boxX, int boxY, int boxWidth, int boxHeight, Crane crane) {
	
	if (hide == 0) {//�_�łȂ�
		colorChange(craneX, craneY, craneWidth, craneHeight);
	}
	else if (hide == 1) {//�Q�b�g�������̂������グ
		carry(craneX, craneY, craneWidth, craneHeight);
	}
	else if (hide == 2) {//���ɓ����
		putIn(index, boxX, boxY, boxWidth, boxHeight, Mini);
	}
}
//�_�łȂ�
void Object::colorChange(int craneX, int craneY, int craneWidth, int craneHeight) {
	
	color -= 3;//�_��
	if (color < 0) {
		color = 255;
	}
	if (((craneX <= x + width + hover && craneX >= x - hover) || (craneX + craneWidth <= x + width + hover && craneX + craneWidth >= x - hover)) && (craneY + craneHeight >= y - hover && craneY + craneHeight <= y + height + hover)) {
		ofSetColor(255, color, color);//�N���[�������ƌ���
	}
	image.draw(x, y);
	ofSetColor(255, 255, 255);
}
//���ɓ����
void Object::putIn(int index, int boxX, int boxY, int boxWidth, int boxHeight, ofImage Mini) {
	x = boxX + boxWidth / 7 * index;
	y = boxY + boxHeight / 3;
	Mini.draw(x, y);
}//�N���[���Ŏ����^��
void Object::carry(int craneX, int craneY, int craneWidth, int craneHeight) {
	x = craneX + craneWidth / 2 - this->width / 2;
	y = craneY + craneHeight - this->height / 2;
	image.draw(x, y);
}


//�{�^�����������Ƃ�
void Object::stock(int craneX, int craneY, int craneWidth, int craneHeight, int boxY, int rotateSwitch, int& point, ofSoundPlayer click) {
	//�����グ
	if (hide == 0) {
		if (((craneX <= x + width + hover && craneX >= x - hover) || (craneX + craneWidth <= x + width + hover && craneX + craneWidth >= x - hover)) && (craneY + craneHeight >= y - hover && craneY + craneHeight <= y + height + hover)) {
			lift(click);
		}
	}
	//���ɓ����
	else if (hide == 1 && y + height >= boxY) {
		inputSwitchOn(click);
		point++;
	}
}
//�����グ
void Object::lift(ofSoundPlayer click) {
	hide = 1;
}
//���ɓ����X�C�b�`
void Object::inputSwitchOn(ofSoundPlayer click) {
	hide = 2;
}

