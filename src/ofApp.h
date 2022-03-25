#pragma once
#include "ofMain.h"
#include "Object.h"
#include "Crane.h"

const int itemMax = 5;
const int itemAll = 10;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void buttonChange();

	//������
	void reset();

	int width, height;//�E�B���h�E�T�C�Y
	int boxX, boxY, boxWidth, boxHeight;//���̈ʒu�ƃT�C�Y
	int keyCheck;//�N���b�N�m�F
	bool key_flag = false;
	int point;//�_��
	int scene;//���[�h
	string countDown = "0";
	
	ofImage logo;
	ofImage back;
	ofImage windowFlame;
	ofImage outdoor;

	ofImage craneAll;
	ofImage craneLeg;
	ofImage craneRight;
	ofImage craneLeft;

	ofImage box;

	ofImage cardDeck;

	//OP
	ofVideoPlayer opening;
	//�������
	ofVideoPlayer intro;

	//���ʉ�
	ofSoundPlayer click;
	ofSoundPlayer clickSuper;
	ofSoundPlayer craneSound;
	ofSoundPlayer bgm;
	ofSoundPlayer gameEndSound;
	ofSoundPlayer kaisetsuBgm;
	ofSoundPlayer opBgm;
	ofSoundPlayer playBgm;
	ofSoundPlayer resultBgm;
	ofSoundPlayer countDownSound;
	ofTrueTypeFont font, bigFont, resultFont;

	int bgmCheck, kaisetsuBgmCheck, opBgmCheck, playBgmCheck, resultBgmCheck;//���ʉ��X�C�b�`
	float playTime;//�o�ߎ��Ԋi�[
	int playLimit = 90;//�Q�[����������
	int playLimitNowInt;//�c�莞�Ԑ���
	float playLimitNow;//�c�莞��
	float playLimitPer;//�c�莞�Ԋ���
	int resultTime = 20;//���U���g�Q�Ǝ���
	int wait;
	int scaleSize;//�t�H���g�g��

	int itemList[8] = {0,1,2,3,4,5,6,7};//�A�C�e���V���b�t���p���X�g
	int showItemList[4];//5�I��Ń����_���ŕ\��

	//�u����̈ʒu
	int stock[5][2];

	//�X�g�[�u
	ofImage stoveImage;
	ofImage stoveMini;

	//������
	ofImage kotatsuImage;
	ofImage kotatsuMini;

	//�K�X
	ofImage gasImage;
	ofImage gasMini;

	//��m��
	ofImage houtikiImage;
	ofImage houtikiMini;


	//�Q���΂�
	ofImage netabakoImage;
	ofImage netabakoMini;

	//����
	ofImage sentakuImage;
	ofImage sentakuMini;

	//�V�Ղ�
	ofImage tenpuraImage;
	ofImage tenpuraMini;

	//���Δ�
	ofImage houkaImage;
	ofImage houkaMini;

	//������
	ofImage takibiImage;
	ofImage takibiMini;

	//�I�u�W�F�N�g
	Object stove, kotatsu, gas, houtiki, konsent, netabako, sentaku, tenpura, curtain, cableAna, soto;

	//�O���邩
	float sotoRandom;
	int outdoorCheck;
	int outdoorIndex;
	
	Object activeObjects[itemMax];

	Crane crane;

	//�V���A���ʐM
	ofSerial serial;
	bool card_emi = false;
	int hiritsuX = 200;
	int hiritsuY = 100;
	int font_x, font_y, font_w, font_h, logo_x, logo_y, logo_w, logo_h;
	ofImage yokudekimashita, mousukoshi, manten, resultBack;

	ofImage leftTimeBack;
};
