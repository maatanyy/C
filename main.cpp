/**************************************************/
/*             HW#11 : ��ü�������� ����ó�����α׷�#4 �ۼ�  */
/*  �ۼ��� : ��μ�   ��¥ : 2021�� 5�� 28��              */
/*                                                       */
/* ���� ���� :
#11-1. �⺻Ŭ���� �ۼ� : IOInterface Class �ۼ�
#11-2. �Ļ�Ŭ���� �ۼ�
? IOInterface Class�� ��ӹ޴� Subject �� Student Class �ۼ� �� �׽�Ʈ
#11-3. �⺻Ŭ������ �Ļ�Ŭ������ ����
? �����ִ� ������, ��� : ��ӵ� ���, �߰��� ���, �����ǵ� ����Լ�
#11-4. Student Class�� Modify() �Լ� ����
? ���������� ������ �� �����ϰ��� �ϴ� ������ �˻��� ��, �˻��� ���� ������ �� �ֵ��� ����

IOInterface class �ۼ�. 
Subject �� Student class �� IOInterface Class�� ��ӹ޽��ϴ�.
IOInterface Class�� default �����ڸ� �߰��Ͽ����ϴ�(1�� ���� �����ذ��� ���ؼ�)
�׸��� m_data�� �� ������ student,subject Ŭ������ ������ �κп� m_data�� �߰��Ͽ����ϴ�.
Modify�κ��� �����Ͽ��� ���ô� ������ �ϳ��̱淡 ������ �������� ��쵵 �׽�Ʈ�غý��ϴ�.
�׸��� �����ڷ��� Test�� Main�Լ��� �����Ͽ� ������ ���� Ȯ���Ͽ����ϴ�*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "student.h"      //student ������� �߰�  
#include "subject.h"      //subject ������� �߰�
#include "InputUtil.h"
#include "IOInterface.h"

void ShowData(const Student&);   //ShowData�Լ� ����

void Data(const Student& s) { // �������α׷��� �ִ� �����Լ�
	cout << s.GetName() << "�� ������ ������ ��" << s.GetSubNum() << "����";
	cout << "������ ������ ���������" << s.GetAveGPA() << "�Դϴ�.\n";
}

void main() {
	cout.precision(3);   //����ϰ� ����ϱ� ���� ���

	//Student std;
	//cout << std.GetData() << "\n";   //IOInterface ���� ����� �� �ִ� ������ �⺻ �����ڰ� ��� ���� ��

	/*Subject sub("��ǻ��", 3, "C");
	cout << "-----------------------------\n";
	cout << "m_data : " << sub.GetData()<<"\n";
	cout << "������ �̸� : "<< sub.Subject::GetName() << "\n";
	cout << "�θ�Ŭ������ �̸� : " << sub.IOInterface::GetName() << "\n";	
	cout << "-----------------------------\n\n";

	Student std("ȫ�浿", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	cout << "m_data : " << std.GetData() << "\n";
	cout << "�л� �̸� : " << std.Student::GetName() << "\n";
	cout << "�θ�Ŭ������ �̸� : " << std.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";*/

	
	//11-4 ���� �������϶� �׽�Ʈ
	// 
	//Subject sub1[2] = { Subject("��ǻ��", 3, "C"), Subject("���빫��", 2, "A") };
	//Student std("ȫ�浿", 20138342, 2, sub1);
	//std.PrintData();
	//std.Modify(); // Student Class�� ������� �� ����
	//std.PrintData();

	Subject sub("��ǻ��", 3,"C");   //���� ����
	Student std("ȫ�浿", 20138342, 1,&sub);   //�л� ����
	std.PrintData();   //�л����� ���
	std.Modify();   // Student Class�� ������� �� ����
	std.PrintData();   //std���� ���

}

//void ShowData(const Student& s) {  //ShowData �Լ� 
//	cout << s.m_name << "�� ������ ������ �� " << s.m_subnum << "���� ";   //�Է¹��� �л��� �� ���� ������� �������
//	cout << "������ ������ ��������� " << s.m_aveGPA << "�Դϴ�.\n";
//}