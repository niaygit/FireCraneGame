#include "ofApp.h"

//�A�C�e���V���b�t���p
#include <random>
#include <algorithm>
#include <vector>
//

//--------------------------------------------------------------

void ofApp::reset() {
	
	//������
	stove.set("stove", 0, width / 9, height / 3, stoveImage, stoveMini);
	kotatsu.set("kotatsu", 0, width / 10 * 3, height / 2, kotatsuImage, kotatsuMini);
	gas.set("gas", 0, width / 3, height / 5 * 2, gasImage, gasMini);
	houtiki.set("houtiki", 0, width / 12 * 9, height / 20, houtikiImage, houtikiMini);
	netabako.set("netabako", 0, width / 5 - netabakoImage.getWidth() / 2, height / 3 * 2, netabakoImage, netabakoMini);
	sentaku.set("sentaku", 0, width / 50, height / 25 * 2, sentakuImage, sentakuMini);
	tenpura.set("tenpura", 0, width / 100 * 90, height / 5 * 3, tenpuraImage, tenpuraMini);
	crane.set(width, height, craneLeg, craneLeft);

	//���̊O�ɒu������
	sotoRandom = ofRandom(0, 1);
	cout << sotoRandom << "random\n";
	soto.set("houka", 0, width / 100 * 67, height / 100 * 17, houkaImage, houkaMini);
	if (sotoRandom > 0.4) {
		soto.set("takibi", 0, width / 100 * 66, height / 100 * 23, takibiImage, takibiMini);
	}

	//�I�u�W�F�N�g
	Object objects[itemAll] = {stove, kotatsu, gas, houtiki, netabako, sentaku, tenpura, soto};
	
	outdoorCheck = 0;
	//5�I��ŕ\��
	mt19937 mel(ofRandom(1, 100));
	shuffle(begin(itemList), end(itemList), mel);
	for (int i = 0; i < itemMax; i++) {
		cout << "[" << i << "]" << itemList[i] << endl;
		if (objects[itemList[i]].name == "takibi" || objects[itemList[i]].name == "houka") {
			outdoorCheck = 1;
			outdoorIndex = i;
		}
		activeObjects[i] = objects[itemList[i]];
		cout << activeObjects[i].name << "\n";
	}

	point = 0;
	wait = 0;
}

void ofApp::setup() {
	scene = 0;
	serial.setup("COM3", 9600);//com��usb�̃|�[�g���ĕύX
	width = ofGetWidth();
	height = ofGetHeight();
	ofSetFrameRate(30);
	ofSetBackgroundColor(0, 0, 0);

	//�t�H���g
	ofTrueTypeFontSettings nomalFontsettings("font/HGRGE.TTC", 40);
	nomalFontsettings.addRanges(ofAlphabet::Latin);
	nomalFontsettings.addRanges(ofAlphabet::Japanese);
	font.load(nomalFontsettings);
	

	ofTrueTypeFontSettings bigFontSetting("font/NitalagoRuikaSeikyo-06.TTF", 50);
	bigFontSetting.addRanges(ofAlphabet::Latin);
	bigFontSetting.addRanges(ofAlphabet::Japanese);
	bigFont.load(bigFontSetting);

	ofTrueTypeFontSettings resultFontSetting("font/NitalagoRuikaSeikyo-06.TTF", 50);
	resultFontSetting.addRanges(ofAlphabet::Latin);
	resultFontSetting.addRanges(ofAlphabet::Japanese);
	resultFont.load(resultFontSetting);
	


	//�I�[�v�j���O
	opening.load("movies/opening.mov");
	opening.setLoopState(OF_LOOP_NORMAL);
	opening.play();
	
	//�������
	intro.load("movies/intro.mov");
	intro.setLoopState(OF_LOOP_NORMAL);

	//�摜
	logo.load("img/RescueCrane_logo.png");
	back.load("img/wakunasihaikei.png");
	windowFlame.load("img/windowFlane.png");
	outdoor.load("img/outdoor.png");

	box.load("img/box.png");
	boxWidth = box.getWidth();
	boxHeight = box.getHeight();

	craneAll.load("img/craneAll.png");
	craneLeg.load("img/craneLeg.png");
	craneRight.load("img/craneRight.png");
	craneLeft.load("img/craneLeft.png");

	cardDeck.load("img/cardDeck.png");

	stoveImage.load("img/stove.png");
	gasImage.load("img/gas.png");
	houtikiImage.load("img/houtiki.png");
	kotatsuImage.load("img/kotatsu.png");
	netabakoImage.load("img/netabako.png");
	sentakuImage.load("img/sentaku.png");
	tenpuraImage.load("img/tenpura.png");
	houkaImage.load("img/houkaImage.png");
	takibiImage.load("img/takibiImage.png");

	stoveMini.load("img/stoveMini.png");
	kotatsuMini.load("img/kotatsuMini.png");
	gasMini.load("img/gasMini.png");
	houtikiMini.load("img/houtikiMini.png");
	konsentMini.load("img/konsentMini.png");
	kotatsuMini.load("img/kotatsuMini.png");
	netabakoMini.load("img/netabakoMini.png");
	sentakuMini.load("img/sentakuMini.png");
	tenpuraMini.load("img/tenpuraMini.png");
	curtainMini.load("img/curtainMini.png");
	cableAnaMini.load("img/cableAnaMini.png");
	takibiMini.load("img/takibiMini.png");
	houkaMini.load("img/houkaMini.png");
	yokudekimashita.load("img/goodJob.png");
	mousukoshi.load("img/mousukoshi.png");
	manten.load("img/5.png");
	resultBack.load("img/resultBack.png");


	//���ʉ�
	click.load("sound/click.mp3");
	craneSound.load("sound/craneSound.mp3");

	opBgm.load("sound/opBgm.mp3");//�X�^�[�g���
	kaisetsuBgm.load("sound/kaisetsuBgm.mp3");//�Q�[���O����
	playBgm.load("sound/playBgm.mp3");//�Q�[����
	resultBgm.load("sound/resultBgm.mp3");//���ʉ��
	gameEndSound.load("sound/gameEndSound.mp3");//�Q�[���I��
	countDownSound.load("sound/countDown.mp3");//�J�E���g�_�E��

	opBgm.setLoop(true);
	opBgm.play();
	kaisetsuBgm.setLoop(true);
	playBgm.setLoop(true);
	resultBgm.setLoop(true);

	//�X�^�[�g��ʂ�BGM�Đ�

	reset();
}





//--------------------------------------------------------------
void ofApp::update() {
	if (serial.available() > 0) { //����ꂽdata�̒l�ŏ㉺���E������
		int data = serial.readByte();
		cout << data <<"key"<< "\n";
		if (data == 5) {
			buttonChange();
		}
		else {
			crane.move(data, hiritsuX, hiritsuY, width, height);
		}
	}

	if (scene == 0) {
		opening.update();
	}
	else if (scene == 1) {
		intro.update();
	}
	else if (scene == 2) {
		//���Ԍv��
		playTime = ofGetElapsedTimeMillis() / 1000;
		if (wait == 0 && playTime > 2) {
			wait = 1;
			ofResetElapsedTimeCounter();
		}
		playLimitNow = playLimit - playTime;
		playLimitPer = playLimitNow / playLimit;
		if (playLimitNow <= 0 || point == 5) {
			playBgm.stop();
			gameEndSound.play();
			resultBgm.play();
			card_emi = true;
			if (card_emi == true) {	//�r�o�J�n�̒ʐM���s��
				unsigned char num = 1;
				serial.writeByte(num);
				card_emi = false;	//�ʐM�̉񐔂����Ɍ���
				cout << num;
				cout << "pressed\n";
			}
			ofResetElapsedTimeCounter();
			scene++;
		}
	}
	//�c�莞��
	if (scene == 3) {
		if (ofGetElapsedTimeMillis() / 1000 > resultTime) {
			ofResetElapsedTimeCounter();
			click.play();
			resultBgm.stop();
			opBgm.play();
			serial.writeByte('1');
			reset();
			opening.firstFrame();
			opening.play();
			scene++;
		}
	}
	//�Q�[���I��
	if (scene > 3) {
		scene = 0;
	}
	
}

//--------------------------------------------------------------
void ofApp::draw() {
ofSetColor(255, 255, 255);
	if (scene == 0) {	//�^�C�g�����
		opening.draw(0, 0, width, height);
	}
	else if (scene == 1) {	//�Q�[���������
		intro.draw(0, 0, width, height);
	}
	else if (scene == 2) {	//�Q�[���v���C���
		boxX = width / 2 - boxWidth / 2;
		boxY = height - boxHeight;
		back.draw(0, 0, ofGetWidth(), ofGetHeight());
		

		
		

		ofFill();
		//�I�u�W�F�N�g�`��
		for (int i = 0; i < itemMax;i++)
		{
			activeObjects[i].show(i+1, crane.x, crane.y, crane.width, crane.height, crane.armY, boxX, boxY, boxWidth, boxHeight, crane);
		}
		ofSetColor(255, 255, 255);

		//�N���[���`��
		crane.rotateArm();
		crane.drawCrane(craneLeg, craneLeft, craneRight, width, height);

		if (wait == 0) {
			if (playTime < 4) {
				ofSetColor(0, 0, 0, 150);
				ofDrawRectangle(0, 0, width, height);
				ofSetColor(255, 215, 0);
			}
			if (playTime < 3) {
				countDown = to_string(3 - (int)playTime);
				font_w = font.stringWidth(countDown);
				font_h = font.stringHeight(countDown);
				font_x = ofGetWidth() / 2 - font_w / 2;
				font_y = ofGetHeight() / 2 - font_h / 2;
				font.drawString(countDown, font_x, font_y);
			}
		}
		else if (wait == 1) {
			font_x = ofGetWidth() / 15 * 14;
			font_y = ofGetHeight() / 20 * 19;
			playLimitNowInt = playLimitNow;
			string timeString = to_string(playLimitNowInt);
			font.drawString(timeString, font_x, font_y);
		}
		
		

		if (wait == 1) {
			if (playTime < 1) {
				countDown = u8"�X�^�[�g";
				font_w = font.stringWidth(countDown);
				font_h = font.stringHeight(countDown);
				font_x = ofGetWidth() / 2 - font_w / 2;
				font_y = ofGetHeight() / 2 - font_h / 2;
				font.drawString(countDown, font_x, font_y);
			}
		}
	}
	else if (scene == 3) {	//���U���g���
		ofSetColor(255, 255, 255);
		resultBack.draw(0, 0);

		string pointShow = to_string(point);
		font_w = font.stringWidth(pointShow);
		font_h = font.stringHeight(pointShow);
		font_x = ofGetWidth() / 2 - font_w / 2;
		font_y = ofGetHeight() / 2 - font_h / 2;
		ofPushMatrix();
		ofSetColor(0, 0, 0);
		scaleSize = 5;
		ofScale(scaleSize, scaleSize);
		bigFont.drawString(pointShow, (width / 4 - 70)/scaleSize, (height / 2 - 30) / scaleSize);
		ofPopMatrix();
		ofPushMatrix();
		scaleSize = 3;
		ofScale(scaleSize, scaleSize);
		resultFont.drawString("/5", (width / 4  + 100) / scaleSize, (height / 2 + 50) / scaleSize);
		ofPopMatrix();
		if (point <= 3) {
			mousukoshi.draw(width / 5, height / 9 * 5);
		}
		else {
			yokudekimashita.draw(width / 5 + width / 60, height / 9 * 5);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//z�L�[���������Ƃ��ɏ�ʕύX
	if (key == OF_KEY_SHIFT && key_flag == false) {
		buttonChange();
		key_flag = true;//���������h�~
	}
	else if (scene == 2) { //�Q�[���v���C���݈̂ړ�
		if (keyCheck == 0) {
			craneSound.play();
		}
		keyCheck = 1;//������
		hiritsuX = 400;
		hiritsuY = 200;
		crane.move(key, hiritsuX, hiritsuY, width, height);
	}
	if (key == OF_KEY_SHIFT) {
		for (int i = 0; i < itemMax; i++) {

			activeObjects[i].stock(crane.x, crane.y, crane.width, crane.height, boxY, crane.rotateSwitch, point, click);
			cout << activeObjects[i].name << ":" << activeObjects[i].x << "\n";
		}
		cout << crane.x << "crane.x" << "\n";
		cout << point << "point" << "\n";
		crane.catchRelease();
	}
	if (key == 'p') {//���U���g��ʃV���[�g�J�b�g
		scene = 3;
	}

	//�J�[�h�r�o�V���[�g�J�b�g
	if (key == 'c') {
		unsigned char num = 1;
		serial.writeByte(num);
		card_emi = false;	//�ʐM�̉񐔂����Ɍ���
		cout << num;
		cout << "pressed\n";
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	keyCheck = 0;

	if (key_flag == true) {
		key_flag = false;
	}

	else if (key == 'f') {
		point = 0;
		
		reset();
	}
}

//����{�^���������̓���
void ofApp::buttonChange() {
	
	//�V�[���؂�ւ�
	switch (scene) {
	case 0:
		click.play();
		opBgm.stop();
		opening.stop();
		kaisetsuBgm.play();
		intro.firstFrame();
		intro.play();
		ofResetElapsedTimeCounter();
		scene++;
		break;
	case 1:
		if (ofGetElapsedTimeMillis() / 1000 > 3) {
			click.play();
			kaisetsuBgm.stop();
			intro.stop();
			countDownSound.play();
			playBgm.play();
			ofResetElapsedTimeCounter();
			scene++;
			break;
		}
	case 2:
		click.play();
		if (wait == 1) {
			//�A�C�e���E��
			for (int i = 0; i < itemMax; i++) {

				activeObjects[i].stock(crane.x, crane.y, crane.width, crane.height, boxY, crane.rotateSwitch, point, click);
			}
			cout << crane.x << "crane.x" << "\n";
			cout << point << "point" << "\n";
			crane.catchRelease();
		}
		break;

	case 3:
		click.play();
		resultBgm.stop();
		opBgm.play();
		serial.writeByte('1');
		reset();
		opening.firstFrame();
		opening.play();
		scene++;
		break;
	}
	
}


