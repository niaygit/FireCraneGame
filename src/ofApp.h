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

	//初期化
	void reset();

	int width, height;//ウィンドウサイズ
	int boxX, boxY, boxWidth, boxHeight;//箱の位置とサイズ
	int keyCheck;//クリック確認
	bool key_flag = false;
	int point;//点数
	int scene;//モード
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
	//操作説明
	ofVideoPlayer intro;

	//効果音
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

	int bgmCheck, kaisetsuBgmCheck, opBgmCheck, playBgmCheck, resultBgmCheck;//効果音スイッチ
	float playTime;//経過時間格納
	int playLimit = 90;//ゲーム制限時間
	int playLimitNowInt;//残り時間整数
	float playLimitNow;//残り時間
	float playLimitPer;//残り時間割合
	int resultTime = 20;//リザルト参照時間
	int wait;
	int scaleSize;//フォント拡大

	int itemList[8] = {0,1,2,3,4,5,6,7};//アイテムシャッフル用リスト
	int showItemList[4];//5つ選んでランダムで表示

	//置き場の位置
	int stock[5][2];

	//ストーブ
	ofImage stoveImage;
	ofImage stoveMini;

	//こたつ
	ofImage kotatsuImage;
	ofImage kotatsuMini;

	//ガス
	ofImage gasImage;
	ofImage gasMini;

	//報知器
	ofImage houtikiImage;
	ofImage houtikiMini;


	//寝たばこ
	ofImage netabakoImage;
	ofImage netabakoMini;

	//洗濯物
	ofImage sentakuImage;
	ofImage sentakuMini;

	//天ぷら
	ofImage tenpuraImage;
	ofImage tenpuraMini;

	//放火犯
	ofImage houkaImage;
	ofImage houkaMini;

	//たき火
	ofImage takibiImage;
	ofImage takibiMini;

	//オブジェクト
	Object stove, kotatsu, gas, houtiki, konsent, netabako, sentaku, tenpura, curtain, cableAna, soto;

	//外あるか
	float sotoRandom;
	int outdoorCheck;
	int outdoorIndex;
	
	Object activeObjects[itemMax];

	Crane crane;

	//シリアル通信
	ofSerial serial;
	bool card_emi = false;
	int hiritsuX = 200;
	int hiritsuY = 100;
	int font_x, font_y, font_w, font_h, logo_x, logo_y, logo_w, logo_h;
	ofImage yokudekimashita, mousukoshi, manten, resultBack;

	ofImage leftTimeBack;
};
