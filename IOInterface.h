#ifndef IOINTERFACE_H   //헤더의 중복을 막기 위해 씀
#define IOINTERFACE_H
#include "InputUtil.h"

class IOInterface : public InputUtil {

protected:
	string m_name;
	int m_data;

public:
	IOInterface() {
		cout << "IOInterface의 디폴트 생성자 호출됨.\n";
		this->m_name = "";
		this->m_data = 0;

	}

	IOInterface(string m_name) {
		cout << "IOInterface의 인자있는 생성자 호출됨.\n";
		this->m_name = m_name;
	}


	~IOInterface() {
		cout << "IOInterface의 소멸자 호출됨.\n";
	}

	void InputData() {
		cout << "이름을 입력해주세요.\n";
		InputUtil::InputValue(m_name);
		cout << "데이터를 입력해주세요.\n";
		InputUtil::InputValue(m_data);
	}

	void PrintData() const {
		cout << "이름은 : " << m_name << "입니다.\n";
		cout << "데이터는 : " << m_data << "입니다.\n";
	}

	void Modify() {
		this->m_name = m_name;
		this->m_name = m_data;
	}

	string GetName() const {
		return m_name;
	}

	int GetData() const {
		return m_data;
	}

};

#endif // !IOINTERFACE_H