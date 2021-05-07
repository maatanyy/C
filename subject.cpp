#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "subject.h"  //subject������� �߰�����

void Subject::Initialize() {   //�ʱ�ȭ �ϴ� �Լ� Ư���� ������ ���ڰ� ������ �Ʒ�ó�� �ʱ�ȭ
	m_name = "";  //�̸��� ""
	m_hakjum = 0;  //������ 0
	m_grade = "";   //grade�� ""
	m_GPA = 0.0;   //GPA �� 0.0���� 
}

void Subject::Initialize(string m_name, int m_hakjum, string m_grade) {  //������ ������ �װɷ� �ʱ�ȭ ������
	this->m_name = m_name;     //�Է¹��� �̸��� this->m_name�� �־���
	this->m_hakjum = m_hakjum;  //�Է¹��� ������ this->m_hakjum�� �־���
	this->m_grade = m_grade;   //�Է¹��� ����� this->m_grade�� �־���
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA�Լ� ȣ��
}

void Subject::InputValue(int& i) {  //int �Է¹޴� �Լ�
	cin >> i;
	cin.ignore();   //cin���� �Է¹��� �Ŀ��� cin.ignore�Ἥ ���� ��������
}

void Subject::InputValue(string& str) {  //string �Է� �޴� �Լ�
	getline(cin, str);  //getline�� ���� string str �Է¹���
}

void Subject::InputData() {  //InputData �Լ�

	cout << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";

	cout << "������� : ";
	InputValue(this->m_name);     //������� ����
	cout << "����������(����) : ";
	InputValue(this->m_hakjum);   //���� ������ ����

	cout << "������<A+ ~ F> : ";
	InputValue(this->m_grade);    //���� ��� ����
	cout << '\n';

	CalcGPA(this->m_grade, this->m_hakjum);  //CalcGPA �Լ� ȣ��
}

void Subject::PrintTitle() {  //Title ������ִ� �Լ�
	cout << "-----------------------------------------------------\n";
	cout << "    �������     ������     ���     ����    \n";
	cout << "-----------------------------------------------------\n";
}

void Subject::PrintData() {  // ������ ������ִ� �Լ�
	cout << "-----------------------------------------------------\n";
	cout << "      " << this->m_name << "         " << this->m_hakjum << "        " << this->m_grade << "        " << this->m_GPA << "\n";
	cout << "-----------------------------------------------------\n";
}

void Subject::CalcGPA(string, int) {  // ���� ��� �Լ�

	if (m_grade == "A+") {         //A+->4.5�� ��ȯ
		m_GPA = m_hakjum * 4.5;
	}
	else if (m_grade == "A") {        //A0->4.0�� ��ȯ
		m_GPA = m_hakjum * 4.0;
	}
	else if (m_grade == "B+") {         //B+->3.5�� ��ȯ
		m_GPA = m_hakjum * 3.5;
	}
	else if (m_grade == "B") {         //B0->3.0�� ��ȯ
		m_GPA = m_hakjum * 3.0;
	}
	else if (m_grade == "C+") {           //C+->2.5�� ��ȯ
		m_GPA = m_hakjum * 2.5;
	}
	else if (m_grade == "C") {             //C0->2.0�� ��ȯ
		m_GPA = m_hakjum * 2.0;
	}
	else if (m_grade == "D+") {              //D+->1.5�� ��ȯ
		m_GPA = m_hakjum * 1.5;
	}
	else if (m_grade == "D") {             //D0->1.0�� ��ȯ
		m_GPA = m_hakjum * 1.0;
	}
	else if (m_grade == "F") {             //F->0�� ��ȯ
		m_GPA = m_hakjum * 0.0;
	}
	else if (m_grade == "a+") {
		m_GPA = m_hakjum * 4.5;
	}
	else if (m_grade == "a") {            //�빮�ڿ� ���� ���
		m_GPA = m_hakjum * 4.0;
	}
	else if (m_grade == "b+") {
		m_GPA = m_hakjum * 3.5;
	}
	else if (m_grade == "b") {
		m_GPA = m_hakjum * 3.0;
	}
	else if (m_grade == "c+") {
		m_GPA = m_hakjum * 2.5;
	}
	else if (m_grade == "c") {
		m_GPA = m_hakjum * 2.0;
	}
	else if (m_grade == "d+") {
		m_GPA = m_hakjum * 1.5;
	}
	else if (m_grade == "d") {
		m_GPA = m_hakjum * 1.0;
	}
	else if (m_grade == "f") {
		m_GPA = m_hakjum * 0.0;
	}
};

string Subject::GetName() {  //�̸� �������ִ� �Լ�
	return m_name;
}

int Subject::GetHakjum() {  //���� �������ִ� �Լ�
	return m_hakjum;
}

string Subject::GetGrade() {  //��� �������ִ� �Լ�
	return m_grade;
}

float Subject::GetGPA() {  //GPA �������ִ� �Լ�
	return m_GPA;
}