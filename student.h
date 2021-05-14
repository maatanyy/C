#ifndef STUDENT_H  //����� �ߺ��� ���� ���� ��
#define STUDENT_H
#include "subject.h"  //subject ��� ���� �߰�����, subject��� ���Ͽ� �ִ� ������ ���� ����

class Student {  //Student Ŭ���� 
protected:   //protected (Ŭ���� �ȿ����� �� �� ����)
	string m_name;   //�л���
	int m_hakbun;    //�й�
	int m_subnum;    //������ ���� ��
	Subject* m_sub;   //������ �����
	float m_aveGPA;   //������ ������� ��� ����

public:    //public�� 
	Student();     //Student default ������
	Student(string name, int hakbun, int subnum, Subject* sub);   //Student �����ִ� ������
	Student(const Student& std);    //Student ���� ������
	~Student();   //Student �Ҹ���

	void InputValue(int&);    //��Ʈ�� �Է¹޴� �Լ�
	void InputValue(string&);   //string�� �Է� �޴� �Լ�
	void InputData();   // ������� �� �Է�
	void PrintData();   // ������� �� ���
	void CalcAveGPA();   // ��� ���� ���

	void Modify();

	string GetName();  //�̸� �������ִ� �Լ�
	int GetHakbun();  //�й� �������ִ� �Լ�
	int GetSubNum();  //����� �������ִ� �Լ�
	float GetAveGPA();   //������� �������ִ� �Լ�
	friend void ShowData(const Student& s);  //friend�� ShowData ����. Ŭ���� ����� �ƴϾ ����� ������ �� �� ����
};

#endif // !STUDENT_H
