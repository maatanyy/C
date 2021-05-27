#ifndef STUDENT_H  //����� �ߺ��� ���� ���� ��
#define STUDENT_H
#include "subject.h"  //subject ��� ���� �߰�����, subject��� ���Ͽ� �ִ� ������ ���� ����
#include "IOInterface.h"
class Student : public IOInterface {  //Student Ŭ���� 

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

	void InputData();   // ������� �� �Է�
	void PrintData();   // ������� �� ���
	void CalcAveGPA();   // ��� ���� ���
	Subject* SubSearch(string subname);  //���� ã�� �Լ�

	void Modify();

	string GetName() const;  //�̸� �������ִ� �Լ�
	int GetHakbun() const;  //�й� �������ִ� �Լ�
	int GetSubNum() const;  //����� �������ִ� �Լ�
	float GetAveGPA() const;   //������� �������ִ� �Լ�
	friend void ShowData(const Student& s);  //friend�� ShowData ����. Ŭ���� ����� �ƴϾ ����� ������ �� �� ����
};

#endif // !STUDENT_H
