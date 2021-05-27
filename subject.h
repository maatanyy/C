#ifndef SUBJECT_H   //����� �ߺ��� ���� ���� ��
#define SUBJECT_H
#include "IOInterface.h"
class Subject : public IOInterface {  //Subject Ŭ����

protected:    //protected (Ŭ���� �ȿ����� �� �� ����)
	string m_name;   // �����̸� string�� ���
	int m_hakjum;   // ��������
	string m_grade;   // ������ string�� ���
	float m_GPA;   // ���� ����

public:   //public�� 
	Subject();   //Subject  default ������
	Subject(string name, int hakjum, string grade);  //Subject �����ִ� ������
	Subject(const Subject& sub);   //Subject ���������
	~Subject();   //Subject �Ҹ���

	void InputData();   //������ �ִ� �Լ�
	static void PrintTitle();  // ���� ������ִ� �Լ� static�� �̿��Ͽ� �������� ����
	void PrintData();  //������ ������ִ� �Լ�
	void CalcGPA(string, int);  //GPA������ִ� �Լ�

	void Modify();  //Subject class ������� �����ϴ� �Լ�

	string GetName() const;   //�̸� �������ִ� �Լ�
	int GetHakjum() const;  //���� �������ִ� �Լ�
	string GetGrade() const;  //��� �������ִ� �Լ�
	float GetGPA() const;   //GPA �������ִ� �Լ�
};

#endif // !SUBJECT_H

