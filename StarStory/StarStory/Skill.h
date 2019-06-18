#pragma once

// 各スキルの識別群
enum Skill {

	NORMAL,
	SPEED,
	JUMP,
	STOP,
	LIGHT
};

// スキルIDクラス
// シングルトン
class Skill_ID {
public:
	// インスタンス取得
	static Skill_ID &GetInstance() {

		static Skill_ID skill_id;
		return skill_id;
	}

	// セッター
	void SetSkillID(Skill skill_id, int diamond_part) {
		m_diamond_skill_list[diamond_part] = skill_id;
	}

	// ゲッター
	Skill GetSkillID(int diamond_part) {
		return m_diamond_skill_list[diamond_part];
	}

// 変数
private:
	// 各ひし形のスキル保管用
	Skill m_diamond_skill_list[5];

// 関数
private:
	// コンストラクタ
	Skill_ID()  {
		for (int i = 0; i < 5; ++i) {
			m_diamond_skill_list[i] = NORMAL;
		}
	};
};


