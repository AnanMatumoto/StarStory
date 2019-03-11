#include "Common.h"

//=========================================
// 2ŽŸŒ³ƒwƒ‹ƒp[ŒQ
//=========================================
t_Float2::t_Float2(float x_, float y_) {

	this->m_x = x_;
	this->m_y = y_;
}

t_Float2  t_Float2:: operator + (const t_Float2& r) {
	t_Float2 tf;
	tf.m_x = m_x + r.m_x;
	tf.m_y = m_y + r.m_y;
	return tf;
}

t_Float2 t_Float2::operator - (const t_Float2& r) {
	t_Float2 tf;
	tf.m_x = r.m_x - m_x;
	tf.m_y = r.m_y - m_y;
	return tf;
}

t_Float2 t_Float2::operator * (const t_Float2& r) {
	t_Float2 tf;
	tf.m_x = m_x * r.m_x;
	tf.m_y = m_y * r.m_y;
	return tf;
}

t_Float2 t_Float2::operator * (float r)const {
	t_Float2 tf;
	tf.m_x = m_x * r;
	tf.m_y = m_y * r;
	return tf;
}

t_Float2 t_Float2::operator / (const t_Float2& r) {
	t_Float2 tf;
	tf.m_x = r.m_x / m_x;
	tf.m_y = r.m_x / m_y;
	return tf;
}

t_Float2 t_Float2::operator / (float r) const {
	t_Float2 tf;
	tf.m_x = r / m_x;
	tf.m_y = r / m_y;
	return tf;
}

Vec2 Vec2::operator = (const t_Float2& r) {
	Vec2 vec2;
	vec2.m_x = r.m_x;
	vec2.m_y = r.m_y;

	return vec2;
}