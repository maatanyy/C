/**************************************************/
/*             HW#9 : ��ü�������� ����ó�����α׷�#3 �ۼ�  */
/*  �ۼ��� : ��μ�   ��¥ : 2021�� 5�� 20��              */
/*                                                       */
/* ���� ���� :
#10-1. Student Class�� SubSearch() ����Լ� �߰� : ����Ž��
#10-2. Subject Class�� Student Class�� ��������Լ�, const ����Լ� �ۼ�
#10-3. InputUtil Class �ۼ� : �����͸� �Է��� ���� ���ο� Class
#10-4. Subject Class�� Student Class�� ����� �������� ��ü ����

�л��� ��� ���� �߿� ã������ ����� ��ġ�ϴ� �Լ��� Student Class�� �����Ͽ����ϴ�.
PrintTitle�� static���� �����Ͽ� Ŭ�������� ���������� ����� �� �ְ� �Ͽ����ϴ�.
������ InputValue�� :InputUtil.h�� �����Ͽ��� �ٸ� ���ĵ� �߰��Ͽ����ϴ�.
Subject Class�� Student Class�� ����� �������� ��ü�� ������ �� ������ �ֳ� �����߽��ϴ�.

������ �������� ���� ������,�Ҹ��� ����� ������ִ� �κ��� �����ںκ��� �ּ� ó���߽��ϴ�. (��� ��� Ȯ�ν� �ʹ� �����ؼ�)
�׸��� �����ڷ��� Test�� Main�Լ��� �����Ͽ� ������ ���� Ȯ���Ͽ����ϴ�*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "student.h"      //student ������� �߰�  
#include "subject.h"      //subject ������� �߰�
#include "InputUtil.h"

void ShowData(const Student&);   //ShowData�Լ� ����

void Data(const Student& s) { // �������α׷��� �ִ� �����Լ�
	cout << s.GetName() << "�� ������ ������ ��" << s.GetSubNum() << "����";
	cout << "������ ������ ���������" << s.GetAveGPA() << "�Դϴ�.\n";
}

void main() {
	cout.precision(3);   //����ϰ� ����ϱ� ���� ���

	//Subject* Student::SubSearch() ����Լ� �׽�Ʈ
	 
	//Student std;    
	//std.InputData();
	//std.PrintData();
	//Subject* sub = std.SubSearch("������");
	//// ������� ���������� Ž���� ���
	//// �ش� ���������� �ִ� �޸� �ּҸ� ����
	//if (sub != NULL) {
	//	sub->PrintTitle();
	//	sub->PrintData();
	//}

	//Subject sub1("��ǻ��", 3, "C");    //sub1 �־��� ������ ����
	//Subject sub2("����", 2, "A");    //sub2 �־��� ������ ����
	//Subject::PrintTitle();             //Subject::PrintTitle �Լ� ȣ��
	//sub1.PrintData();                  //sub1���� ���
	//sub2.PrintData();                   //sub2���� ��� 
	//Student st1("ȫ�浿", 2013909845, 1, &sub1);     //st1 �־��� ������ ����
	//st1.PrintData();                           //st1 ���� ���
	//Data(st1);                  

	Subject sub1[2] = { Subject("��ǻ��", 3, "C"), Subject("���빫��", 2, "A") };      // Subject�迭�� ���� 2�� sub1�� ����
	Subject* sub2[2] = { new Subject(), new Subject("����", 3, "C") };                // Subject�� �����ͷ� ���� 2�� sub2[2]�� ����
	Student st1;                                    // �л� st1 ����
	Student st2("ȫ�浿", 2013909845, 2, sub1);         // st�� �ش� ������ �ʱ�ȭ�ؼ� ����
	Student* st3 = new Student[2];             // Student�� ������ st3�� �����Ҵ�
	cout << "\n" << "sub2[0] �Է�" << "\n";      
		sub2[0]->InputData();              //sub2[0] �Է¹���
	cout << "\n" << "st1 �Է�" << "\n";
	st1.InputData();                   //st1 �Է� ����
	cout << "\n" << "st3 �Է�" << "\n";
	for (int i = 0; i < 2; i++)             //�ݺ����� �����ϸ� �л��� ���� �Է� ����
		(st3 + i)->InputData();    
	cout << "\n" << "sub1 ���� ���" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)          //�ݺ����� �����ϸ� ���� ���� ���
		sub1[i].PrintData();
	cout << "\n" << "sub2 ���� ���" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)          //�ݺ����� �����ϸ� ���� ���
		sub2[i]->PrintData();       
	cout << "\n" << "st1 ���� ���" << "\n";
	st1.PrintData();                             //st1 ���� ���
	cout << "\n" << "st2 ���� ���" << "\n";
	st2.PrintData();                           //st2 ���� ���
	cout << "\n" << "st3 ���� ���" << "\n";
	for (int i = 0; i < 2; i++)             //�ݺ����� �����ϸ� �л����� ���
		(st3 + i)->PrintData();
}

//void ShowData(const Student& s) {  //ShowData �Լ� 
//	cout << s.m_name << "�� ������ ������ �� " << s.m_subnum << "���� ";   //�Է¹��� �л��� �� ���� ������� �������
//	cout << "������ ������ ��������� " << s.m_aveGPA << "�Դϴ�.\n";
//}