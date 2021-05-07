#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "subject.h"   //subject ������� �߰�
#include "student.h"  //student ������� �߰�

void Student::Initialize() {    //�ʱ�ȭ �ϴ� �Լ� �Ʒ� ��ó�� �⺻ �ʱ�ȭ
	string m_name = "";
	int m_hakbun = 0;
	int m_subnum = 0;
	Subject* m_sub = NULL;
	float m_aveGPA = 0;
}

void Student::Initialize(string name, int hakbun, int subnum, Subject* sub) {  //���� ������ �ԷµǸ� �� ������ �ʱ�ȭ ����
	this->m_name = name;    //�Է¹��� �̸��� �̸��� �ǵ��� ��
	this->m_hakbun = hakbun;  //�Է¹��� �й��� �й��� �ǵ��� ��
	this->m_subnum = subnum;  //�Է¹��� ������� ������� �ǵ��� ��
	m_sub = new Subject[subnum];  //������ �������ŭ �����Ҵ�����
	this->m_sub = sub;  
	CalcAveGPA();
}

void Student::Remove() {  //�����Ҵ� �� �� �����ϴ� �Լ�
	delete[] m_sub;
}

void Student::InputValue(int& i) {  //int �Է¹޴� �Լ�
	cin >> i;
	cin.ignore();   //cin���� �Է¹��� �Ŀ��� cin.ignore�Ἥ ���� ��������
}

void Student::InputValue(string& str) {  //string �Է¹޴� �Լ�
	getline(cin, str);  //getline�� ���� string str �Է¹���
}

void Student::InputData() {     // ������� �� �Է�

	cout << "�̸��� �Է��ϼ��� : ";
	InputValue(this->m_name);  //�̸� �Է� ����

	cout << "�й��� �Է��ϼ��� : ";
	InputValue(this->m_hakbun);  //�й� �Է� ����

	cout << "������ ������� �Է��ϼ��� : ";
	InputValue(this->m_subnum);   //����� �Է� ����

	m_sub = new Subject[m_subnum];  //���� �������ŭ �����Ҵ�

	for (int i = 0; i < this->m_subnum; i++) {
		m_sub[i].InputData();   //���� ���� ���� �Է¹���
	}

	CalcAveGPA();  //GPA����
}


void Student::PrintData() {  // ������� �� ���
	cout << "-----------------------------------------------------\n";
	cout << "      " << "�̸� : " << "    " << this->m_name << "       " << "�й� :    " << this->m_hakbun << "      " << "\n";
	cout << "-----------------------------------------------------\n";

	this->m_sub->PrintTitle();  
	for (int i = 0; i < this->m_subnum; i++) {
		this->m_sub[i].PrintData();  //�������ŭ ���� ���� ���
	}

	cout << "-----------------------------------------------------\n";
	cout << "                          �������" << "     " << this->m_aveGPA<<"\n";

}

void Student::CalcAveGPA() { // ��� ���� ���

	int totalHakjum = 0;  //int�� ���� totalHakjum ����

	for (int i = 0; i < m_subnum; i++) {  //����� ��ŭ ���鼭
		m_aveGPA += m_sub[i].GetGPA();   //GPA�� ���ϰ�
		totalHakjum += m_sub[i].GetHakjum();  //��� ������ �������� ����
	}

	this->m_aveGPA = m_aveGPA / totalHakjum;  //GPA�� �� �������� ������ ������� ����
}

string Student::GetName() {  //�̸� �������ִ� �Լ�
	return m_name;
}

int Student::GetHakbun() {  //�й� �������ִ� �Լ�
	return m_hakbun;
}

int Student::GetSubNum() {  //����� �������ִ� �Լ�
	return m_subnum;
}

float Student::GetAveGPA() {  //��� GPA �������ִ� �Լ�
	return m_aveGPA;
}