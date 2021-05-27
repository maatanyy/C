#ifndef IOINTERFACE_H   //����� �ߺ��� ���� ���� ��
#define IOINTERFACE_H
#include "InputUtil.h"

class IOInterface : public InputUtil {

protected:
	string m_name;
	int m_data;

public:
	IOInterface() {
		cout << "IOInterface�� ����Ʈ ������ ȣ���.\n";
		this->m_name = "";
		this->m_data = 0;

	}

	IOInterface(string m_name) {
		cout << "IOInterface�� �����ִ� ������ ȣ���.\n";
		this->m_name = m_name;
	}


	~IOInterface() {
		cout << "IOInterface�� �Ҹ��� ȣ���.\n";
	}

	void InputData() {
		cout << "�̸��� �Է����ּ���.\n";
		InputUtil::InputValue(m_name);
		cout << "�����͸� �Է����ּ���.\n";
		InputUtil::InputValue(m_data);
	}

	void PrintData() const {
		cout << "�̸��� : " << m_name << "�Դϴ�.\n";
		cout << "�����ʹ� : " << m_data << "�Դϴ�.\n";
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