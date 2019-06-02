#include "Lib.h"

namespace Lib {

	//------------------------------------
	// キーの生成
	void Animation::CreateKey(int num_key) {

		if (m_num_key < num_key) {
			//前回のデータが残っている場合は削除する	
			if (m_keys != 0) {
				delete[] m_keys;
			}
			if (m_values != 0) {
				delete[] m_values;
			}

			m_keys = new float[m_num_key];
			m_values = new float[m_num_key];
		}
	}

	//-----------------------------------
	//　キーの値を設定
	void Animation::SetKeyValue(
		int index,
		float key,
		float value,
		bool is_loop
	) {

		if ((index < 0) || (index > m_num_key)) {
			//配列の範囲を超える場合は何もしない
			return;
		}

		m_keys[index]   = key;
		m_values[index] = value;
		m_is_loop       = is_loop;
	}

	//-------------------------------------
	// アニメーション継続時間の設定
	void Animation::SetDuration(DWORD duration) {

		m_duration = duration;
	}

	//-------------------------------------
	// アニメーションの開始時間を設定
	void Animation::SetStartTime(DWORD start_time) {

		m_start_time = start_time;
	}


	//-------------------------------------
	//　キーの値を取得する
	bool Animation::GetValue(
		DWORD time,
		float* p_value,
		bool* p_is_end
	) {
		//値が設定されていない場合はfalseを返す
		if (p_value == 0) {
			return false;
		}
		if (p_is_end == 0) {
			return false;
		}
		if (m_num_key <= 0) {
			return false;
		}

		DWORD end_time = m_start_time + m_duration;
		if (m_is_loop == false) {
			//ループなし
			if (time < m_start_time) {
				//時刻が開始時刻よりも小さい場合は最小の値を返す
				*p_value = m_values[0];
				*p_is_end = true;
				return true;//アニメーション終了の通知
			}
			else if (time > end_time) {
				//時刻が終了時刻よりも大きければ最後の値を返す
				*p_value = m_values[m_num_key - 1];
				*p_is_end = true;
				return true;
			}
		}

		int   begin_index;
		int   end_index;
		float fraction;

		fraction    = GetFraction(time);		//現在のアニメーションの割合
		begin_index = GetBeginIndex(fraction);  //割合から直前のキーフレームを取得
		end_index   = begin_index + 1;			//直後のキーフレームを取得
	
		if (begin_index < 0) {//アニメーション開始前

			*p_value = m_values[0];
			//最初のキーフレームの値をセットする
		}
		else if (begin_index >= m_num_key - 1) {//アニメーション終了
			*p_value = m_values[m_num_key - 1];
			//最後のキーフレームの値をセットする
		}
		else {
			*p_value = m_values[begin_index];
			//現在の時刻から直前のキーフレームの値をセットする
		}

		*p_is_end = false;
		return true;
	}
	
	//---------------------------------------
	//時刻から割合を求める
	float Animation::GetFraction(DWORD time) {

		DWORD diff_time;
		float fraction;

		if (m_duration == 0) {
			fraction = 1.0f;
		}
		else {
			if (time > m_start_time) {
				// 差分を求める
				diff_time = time - m_start_time;
				// アニメーション時間に対する割合を求める
				diff_time = diff_time % m_duration;
				fraction = (float)diff_time / (float)m_duration;
				fraction = fraction - (int)fraction;
			}
			else {
				//開始時刻よりも小さい（一周した）場合
				diff_time = m_start_time - time;
				diff_time = diff_time % m_duration;
				fraction = (float)diff_time / (float)m_duration;
				fraction = 1.f - (fraction - (int)fraction);
			}
		}
		return fraction;
	}

	//-------------------------------------------
	//現在のアニメーションから値を比較して直前のキーフレームを取得
	int Animation::GetBeginIndex(float fraction) {
		
		if (fraction < m_keys[0]) {
			return -1;
		}

		int index = 0;
		for (int i = 0; i < m_num_key; i++)
		{
			if (m_keys[i] <= fraction) {
				index = i;
			}
			else {
				break;
			}
		}
		return index;
	}
}

