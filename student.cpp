#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "subject.h"   //subject ������� �߰�
#include "student.h"  //student ������� �߰�

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
	cout << "                          �������" << "     " << this->m_aveGPA << "\n";

}

void Student::CalcAveGPA() { // ��� ���� ���

	int totalHakjum = 0;  //int�� ���� totalHakjum ����
	int totalGPA = 0;

	for (int i = 0; i < m_subnum; i++) {  //����� ��ŭ ���鼭
		totalGPA += m_sub[i].GetGPA();   //GPA�� ���ϰ�
		totalHakjum += m_sub[i].GetHakjum();  //��� ������ �������� ����
	}
	m_aveGPA = totalGPA / totalHakjum;  //GPA�� �� �������� ������ ������� ����
}

void Student::Modify() {
	string Type = "0";  //�л����� �������� �������� �������� �Է¹��� string�� Type����

	cout << "\n";
	cout << "����(�л�����/��������/���) : ";

	InputValue(Type);  //Type�Է¹���

	if (Type == "�л�����") {
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(this->m_name);  //�̸��ٲ���
		cout << "�й� : ";
		InputValue(this->m_hakbun);  //�й��ٲ���
	}

	else if (Type == "��������") {
		for (int i = 0; i < this->m_subnum; i++) {
		     m_sub[i].Modify();
		}
		CalcAveGPA();
	}

	else if (Type == "���") {
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(this->m_name);  //�̸��ٲ���
		cout << "�й� : ";
		InputValue(this->m_hakbun);  //�й��ٲ���
		this->m_sub->Modify();
		CalcAveGPA();
	}

	else {
		cout << "����� �Է����ּ���.\n";
	}

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

Student::Student() {  //student default ������
	cout << "Student() ȣ��\n";   //ȣ�� Ȯ��
	m_name = "";  //�̸��� null�� �ʱ�ȭ
	m_hakbun = 0;  //�й��� 0���� �ʱ�ȭ
	m_subnum = 0;   //����� 0���� �ʱ�ȭ
	m_sub = NULL;   //���� NULL�� �ʱ�ȭ
	m_aveGPA = 0;  //������� 0���� �ʱ�ȭ
}

Student::Student(string name, int hakbun, int subnum, Subject* sub) {  //student �����ִ� ������
	cout << "Student ������ ȣ��(string name, int hakbun, int subnum, Subject* sub)\n";  //ȣ�� Ȯ��
	m_name = name;    //�Է¹��� �̸��� �̸��� �ǵ��� ��
	m_hakbun = hakbun;  //�Է¹��� �й��� �й��� �ǵ��� ��
	m_subnum = subnum;  //�Է¹��� ������� ������� �ǵ��� ��
	m_sub = new Subject[subnum];  //������ �������ŭ �����Ҵ�����
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i] = sub[i];   //���� �ű�
	}
	CalcAveGPA();  //������� ���
}

Student::Student(const Student& std) {   //Student ���� ������
	cout << "Student ������ ȣ��(const Student& std)\n";  //ȣ�� Ȯ��
	m_name = std.m_name;   //std.m_name�� ������ ���� �̸��� �ǵ�����
	m_hakbun = std.m_hakbun;   //std.m_hakbun�� ������ ���� �й��� �ǵ�����
	m_subnum = std.m_subnum;   //std.m_subnum�� ������ ���� ������� �ǵ�����
	m_sub = new Subject[std.m_subnum];   //�������ŭ �����Ҵ�
	for (int i = 0; i < m_subnum; i++) {//���� �ű�
		m_sub[i] = std.m_sub[i];
	}
	CalcAveGPA(); //������� ���
}

Student::~Student() {  //Student �Ҹ���
	if (m_sub) {  //���� ������ �ֵ���(�����Ҵ� ����)
		cout << "Student �Ҹ���\n";
		delete[] m_sub;   //�޸� ����
	} 
}