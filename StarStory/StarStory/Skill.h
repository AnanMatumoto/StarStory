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
	void SetSkillID(Skill skill) {

		m_skill = skill;
	}

	// ゲッター
	Skill GetSkillID() {

		return m_skill;
	}

private:

	// スキルID保管用
	Skill m_skill;

	// コンストラクタ
	Skill_ID() : m_skill(NORMAL) {};

};


