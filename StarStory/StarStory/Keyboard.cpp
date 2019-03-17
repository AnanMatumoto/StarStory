#include "Lib.h"

//=====================================
//　キーボード関連
//=====================================

namespace {

	const int INPUT_FRAME = 2;
	const int KEYNUM = 256;

	enum FLAME {

		KB_CUR = 0,
		KB_PRE,
	};
}

namespace Lib {

	BYTE key[INPUT_FRAME][KEYNUM];

	bool KeyTest(const BYTE k) {
		return ((k & 0x80) != 0);
	}
	//------------------------------------------
	// 毎フレーム処理
	void KeyUpdate() {
		memcpy(key[KB_PRE], key[KB_CUR], sizeof(*key));
		GetKeyboardState(key[KB_CUR]);
	}
	//------------------------------------------
	//　キー押下処理
	bool KeyOn(int nVirtKey) {
		return KeyTest(key[KB_CUR][nVirtKey]);
	}
	//------------------------------------------
	//　キーを押した瞬間の処理
	bool KeyPress(int nVirtKey) {
		return KeyTest(key[KB_CUR][nVirtKey]) && !KeyTest(key[1][nVirtKey]);
	}
	//-----------------------------------------
	// キー解放処理
	bool KeyOff(int nVirtKey) {
		return !KeyTest(key[KB_CUR][nVirtKey]) && KeyTest(key[1][nVirtKey]);
	}

}

