#include <cstring>

#include "MyString.h"

MyString::MyString(const char *str) {
	m_data = new char[strlen(str) + 1];
	strcpy(m_data, str);
}

MyString::MyString(const MyString &other) {
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}

MyString::~MyString(void) {
	delete(m_data);
}

MyString & MyString::operator =(const MyString &other) {
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}

MyString MyString::operator +(const MyString &other) {
	MyString *tmp = new MyString;
	tmp->m_data = new char[strlen(other.m_data) + strlen(m_data) + 1];
	strcpy(tmp->m_data, this->m_data);
	strcat(tmp->m_data, other.m_data);
	return *tmp;
}

char & MyString::operator [](int i) {
	if (i >= strlen(m_data)) {
		cout << "The index out of range!" << endl;
	} else {
		return *(m_data + i);
	}
}

ostream & operator <<(ostream & out, const MyString &other) {
	return out << other.m_data << endl;
}