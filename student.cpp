#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "subject.h"   //subject ������� �߰�
#include "student.h"  //student ������� �߰�
#include "InputUtil.h"

void Student::InputData() {     // ������� �� �Է�

	cout << "�̸��� �Է��ϼ��� : ";
	InputUtil::InputValue(this->m_name);  //�̸� �Է� ����

	cout << "�й��� �Է��ϼ��� : ";
	InputUtil::InputValue(this->m_hakbun);  //�й� �Է� ����

	cout << "������ ������� �Է��ϼ��� : ";
	InputUtil::InputValue(this->m_subnum);   //����� �Է� ����

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

Subject* Student :: SubSearch(string subname) {   // ���� ã�� �Լ�
	for (int i = 0; i < m_subnum; i++) {    // �л��� �������ŭ �ݺ����� ���Ͽ� ����
		if (m_sub[i].GetName() == subname)   // �Է¹��� ������ �ֳ� Ȯ���ؼ�
			return &m_sub[i];   // ������ �ּҸ� �������ش�
	}
	cout << "ã���ô� �������� �����ϴ�.\n";  // ������ ã�� ������ ���ٰ� �˷��ְ�
	return NULL;  // NULL ����
}

void Student::CalcAveGPA() { // ��� ���� ���

	float totalHakjum = 0;  //int�� ���� totalHakjum ����
	float totalGPA = 0;

	for (int i = 0; i < m_subnum; i++) {  //����� ��ŭ ���鼭
		totalGPA += m_sub[i].GetGPA();   //GPA�� ���ϰ�
		totalHakjum += m_sub[i].GetHakjum();  //��� ������ �������� ����
	}
	this->m_aveGPA = totalGPA / totalHakjum;  //GPA�� �� �������� ������ ������� ����
}

void Student::Modify() {
	string Type = "0";  //�л����� �������� �������� �������� �Է¹��� string�� Type����

	cout << "\n";
	cout << "����(�л�����/��������/���) : ";

	InputUtil::InputValue(Type);  //Type�Է¹���

	if (Type == "�л�����") {
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputUtil::InputValue(this->m_name);  //�̸��ٲ���
		cout << "�й� : ";
		InputUtil::InputValue(this->m_hakbun);  //�й��ٲ���
	}

	else if (Type == "��������") {
		string searchname = "0";  //ã������ �ϴ� ���� �̸� ���� ���� ����
		Subject* findsub = NULL;  //ã�� ���� ��ġ ������ ������ ����

		cout << "ã���ô� ������ �Է����ּ���. : ";   //���� �Է� ����
		InputUtil::InputValue(searchname);  //�Է�
		findsub = SubSearch(searchname);  //findsub�� ã�� ���� ��ġ�� ��� ����
		if (findsub) {  //���� ã�� ������ �ִٸ�
			findsub->Modify();  //subject class�� modify�� �̿��Ͽ� �� ����
		}		
		CalcAveGPA();  //���ο� ���� �ٽ� ���
	}

	else if (Type == "���") {  // ��� �Է½� �л��� �̸�, �й�, ��� ������ ���� �������, ����, ��� ��� ����
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputUtil::InputValue(this->m_name);  //�̸��ٲ���
		cout << "�й� : ";
		InputUtil::InputValue(this->m_hakbun);  //�й��ٲ���

		for (int i = 0; i < m_subnum; i++) {  //��ü ����� ��ŭ �ݺ��ϸ�
			m_sub[i].Modify();          //���� ���� ���� ����
		}
		CalcAveGPA();  //������	������� ���
	}

	else {
		cout << "����� �Է����ּ���.\n";
	}

}

string Student::GetName() const{  //�̸� �������ִ� �Լ�, const�� �� ���� x
	return m_name;
}

int Student::GetHakbun() const{  //�й� �������ִ� �Լ�, const�� �� ���� x
	return m_hakbun;
}

int Student::GetSubNum() const{  //����� �������ִ� �Լ�, const�� �� ���� x
	return m_subnum;
}

float Student::GetAveGPA() const{  //��� GPA �������ִ� �Լ�, const�� �� ���� x
	return m_aveGPA;
}

Student::Student() {  //student default ������
	cout << "Student�� ����Ʈ ������ ȣ���\n";   //ȣ�� Ȯ��
	m_name = "";  //�̸��� null�� �ʱ�ȭ
	m_hakbun = 0;  //�й��� 0���� �ʱ�ȭ
	m_subnum = 0;   //����� 0���� �ʱ�ȭ
	m_sub = NULL;   //���� NULL�� �ʱ�ȭ
	m_aveGPA = 0;  //������� 0���� �ʱ�ȭ
}

Student::Student(string name, int hakbun, int subnum, Subject* sub) :IOInterface(name) {  //student �����ִ� ������
	cout << "Student�� �����ִ� ������ ȣ���\n"; 
	m_name = name;    //�Է¹��� �̸��� �̸��� �ǵ��� ��
	m_hakbun = hakbun;  //�Է¹��� �й��� �й��� �ǵ��� ��
	m_subnum = subnum;  //�Է¹��� ������� ������� �ǵ��� ��
	m_sub = new Subject[subnum];  //������ �������ŭ �����Ҵ�����
	m_data = 300;
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i] = sub[i];   //���� �ű�
	}
	CalcAveGPA();  //������� ���
}

Student::Student(const Student& std) {   //Student ���� ������
	//cout << "Student ������ ȣ��(const Student& std)\n";  //ȣ�� Ȯ��
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
		cout << "Student�� �Ҹ��� ȣ���.\n";
		delete[] m_sub;   //�޸� ����
	} 
}