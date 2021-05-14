/**************************************************/
/*             HW#9 : ��ü�������� ����ó�����α׷�#2 �ۼ�  */
/*  �ۼ��� : ��μ�   ��¥ : 2021�� 5�� 14��              */
/*                                                       */
/* ���� ���� :
Subject Class�� Student Class�� Modify() ����Լ� �߰�
Subject Class�� ������, �Ҹ��� �����
Student Class�� ������, ���������, �Ҹ��� �����
������ Initialize �Լ��� �����ǰ� Inititalize �Լ��� �ִ�
������ ������ ������ �̵� ��
�����ڴ� �ϳ��� ���� ���ҽ� �⺻���� default �����Ϸ��� �����
�ϳ��� �����ҽ� ����ȭ�ؼ� �ؾ���
�Ҹ��ڴ� �����Ҵ� ���� �� ������ �����������
Modify�� ���� ��ȭ�� ���� �� �������ִ� �Լ���.

�׸��� �����ڷ��� Test�� Main�Լ��� �����Ͽ� ������ ���� Ȯ���Ͽ����ϴ�*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

#include "student.h"      //student ������� �߰�  
#include "subject.h"      //subject ������� �߰�

void ShowData(const Student&);   //ShowData�Լ� ����

void main() {
	cout.precision(3);   //����ϰ� ����ϱ� ���� ���

	//Student st;  //Student�� st����

	////Subject Class �׽�Ʈ


	//Subject sub1, sub2, sub3[2], * sub4;  //Subject�� ������ ����(�پ��ϰ�)
	//int i;
	//sub1.Initialize();  //sub1�ʱ�ȭ (subject Ŭ������ �Լ����)
	//sub2.Initialize("������", 3, "A+");   //sub2�ʱ�ȭ (subject Ŭ������ �Լ����)

	//for (i = 0; i < 2; i++)  
	//	sub3[i].Initialize("��ǻ��", 3, "C");  //sub[3]�ʱ�ȭ

	//sub4 = new Subject[2];      //sub4 ���� (�����Ҵ�)
	//sub1.InputData(); // ȭ�鿡�� �Է�
	//cout << "\n" << "sub1 ����" << "\n";
	//sub1.PrintTitle();   
	//sub1.PrintData();  //sub1 ���� ���
	//cout << "\n" << "sub2 ����" << "\n";
	//sub2.PrintTitle();
	//sub2.PrintData();  //sub2 ���� ���
	//cout << "\n" << "sub3 ����" << "\n";
	//sub3[0].PrintTitle();  

	//for (i = 0; i < 2; i++)    //���� ���
	//	sub3[i].PrintData();

	//for (i = 0; i < 2; i++)
	//	(sub4 + i)->InputData();   //���� �Է�

	//cout << "\n" << "sub4 ����" << "\n";
	//sub4->PrintTitle();
	//for (i = 0; i < 2; i++)
	//	(sub4 + i)->PrintData();

	//cout << "Subject Class�� ����Լ��� ������ �Լ� �׽�Ʈ\n";
	//cout << sub1.GetName();  //sub1�̸� ���
	//cout << "\n";
	//cout << sub2.GetHakjum();  //sub2 ���� ���
	//cout << "\n";
	//cout << sub1.GetGrade();   //sub1 grade���
	//cout << "\n";
	//cout << sub2.GetGPA();    //sub2 GPA���
	//cout << "\n";

	//delete[] sub4;  //�޸� ����


	////Student Class �׽�Ʈ

	//Subject sub[2];   //Subject�� sub[2]����
	//sub[0].Initialize("��ǻ��", 3, "C");  //�ʱ�ȭ(Subject�� �Լ� ����ؼ�)
	//sub[1].Initialize("���빫��", 2, "A");  //�ʱ�ȭ(Subject�� �Լ� ����ؼ�)
	//Student st1, st2;  //Student st1, st2 ����
	//st1.Initialize();   //�ʱ�ȭ
	//st2.Initialize("ȫ�浿", 2013909845, 2, sub);  //�ʱ�ȭ
	//st1.InputData();   //st1�� ���� �Է�
	//cout << "\n" << "st1 ����" << "\n";
	//st1.PrintData();
	//cout << "\n" << "st2 ����" << "\n";
	//st2.PrintData();
	//ShowData(st1);  //ShowData �Լ��� �̿��ؼ� st1�� ���� �� ������
	//st1.Remove();

	//cout << "\n";

	Subject sub1("��ǻ��", 3, "C");  //sub1 �����ִ� �����ڷ� ����
	Subject sub2(sub1);   //sub2 ��������ڷ� ����
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle();  //����ϰ� ���Ϸ��� �߰�������
	sub1.PrintData();   //sub1 ���� ���
	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintTitle();  //����ϰ� ���Ϸ��� �߰�������
	sub2.PrintData();   //sub2���� ���
	sub2.Modify();   //sub2 ���� ����
	Student st2("ȫ�浿", 2013909845, 1, &sub1);    //st2 �����ִ� �����ڷ� ����
	Student st1(st2);   //�������� Student::Student(const Student& std)������ �̿�
	Student st3("�輺��", 2015909845, 1, &sub2);  //st3 �����ִ� �����ڷ� ����
	//st1 = st2;   ���� �����Դϴ�. �� �Ʒ��� st2.Modify�� ���Ͽ� ���� �ٲٸ� st1, st2 ���� ������ �ٲ�ϴ� 
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();   //st1 ���� ���
	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData();  //st2 ���� ���
	st2.Modify();     //st2 ���� ����
	cout << "\n" << "������ st2 ����" << "\n";
	st2.PrintData();   //������ st2 ���� ���
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();    //st1 ���� ���
	cout << "\n" << "st3 ����" << "\n";
	st3.PrintData();   //st3 ���� ���

}

void ShowData(const Student& s) {  //ShowData �Լ� 
	cout << s.m_name << "�� ������ ������ �� " << s.m_subnum << "���� ";   //�Է¹��� �л��� �� ���� ������� �������
	cout << "������ ������ ��������� " << s.m_aveGPA << "�Դϴ�.\n";
}