#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "subject.h"  //subject������� �߰�����
#include "InputUtil.h"

void Subject::InputData() {  //InputData �Լ�

	cout << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";

	cout << "������� : ";
	InputUtil::InputValue(this->m_name);     //������� ����
	cout << "����������(����) : ";
	InputUtil::InputValue(this->m_hakjum);   //���� ������ ����

	cout << "������<A+ ~ F> : ";
	InputUtil::InputValue(this->m_grade);    //���� ��� ����
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

void Subject::Modify() {    //Subject class ������� �����ϴ� �Լ�

	cout << "*< " << this->m_name << ", ���� : " << this->m_hakjum << ", ��� : " << this->m_grade << ">�� ������ �����ϼ���\n";    //���� ���� ������ְ�
	cout << "������� : ";      
	InputUtil::InputValue(this->m_name);   //�̸� �ٲ���
	cout << "�������� : ";
	InputUtil::InputValue(this->m_hakjum);  //�����ٲ���
	cout << "������ : ";
	InputUtil::InputValue(this->m_grade);  //��� �ٲ���
	CalcGPA(this->m_grade, this->m_hakjum);  //CalcGPA �Լ� ȣ��

}

string Subject::GetName() const {  //�̸� �������ִ� �Լ�, const�� �� ���� x
	return IOInterface::m_name;
}

int Subject::GetHakjum() const {  //���� �������ִ� �Լ�, const�� �� ���� x
	return m_hakjum;
}

string Subject::GetGrade() const {  //��� �������ִ� �Լ�, const�� �� ���� x 
	return m_grade;
}

float Subject::GetGPA() const {  //GPA �������ִ� �Լ�, const�� �� ���� x
	return m_GPA;
}

Subject::Subject() {    //Subject  default ������
	cout << "Subject�� ����Ʈ ������ ȣ���.\n";   //���� Ȯ��
	m_name = "";  //�̸��� ""
	m_hakjum = 0;  //������ 0
	m_grade = "";   //grade�� ""
	m_GPA = 0.0;   //GPA �� 0.0���� 
}

Subject::Subject(string name, int hakjum, string grade):IOInterface(name) {    //Subject �����ִ� ������
	cout << "Subject�� �����ִ� ������ ȣ���.\n";     //���� Ȯ��
	this->m_name = name;     //�Է¹��� �̸��� this->m_name�� �־���
	this->m_hakjum = hakjum;  //�Է¹��� ������ this->m_hakjum�� �־���
	this->m_grade = grade;   //�Է¹��� ����� this->m_grade�� �־���
	m_data = 100;
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA�Լ� ȣ��
}

Subject::Subject(const Subject& sub) { //Subject ���� ������
	cout << "Subject�� ����Ʈ ������ ȣ���.\n";    //���� Ȯ��
	this->m_name = sub.m_name;     //sub.m_name �����ϴ� m_name �� �־���
	this->m_hakjum = sub.m_hakjum;    //sub.m_hakjum �����ϴ� m_hakjum�� �־���
	this->m_grade = sub.m_grade;   //sub.m_grade �����ϴ� m_grade�� �־���
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA�Լ� ȣ��
}
 
Subject::~Subject() {   //���� �Ҹ���
	cout << "Subject�� �Ҹ��� ȣ���.\n";  //ȣ�� Ȯ��
	                 //�����Ҵ��� ���� �ʾƼ� ������ �ʿ����
}

