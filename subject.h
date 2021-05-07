#ifndef SUBJECT_H   //����� �ߺ��� ���� ���� ��
#define SUBJECT_H

class Subject {  //Subject Ŭ����
protected:    //protected (Ŭ���� �ȿ����� �� �� ����)
	string m_name;   // �����̸� string�� ���
	int m_hakjum;   // ��������
	string m_grade;   // ������ string�� ���
	float m_GPA;   // ���� ����

public:   //public�� 
	void Initialize();  //�ʱ⼳���ϴ� �Լ�
	void Initialize(string, int, string);  //�־��� ������ �ʱ⼳���ϴ� �Լ�
	void InputValue(int&);   //��Ʈ�� �Է��ϴ� �Լ�
	void InputValue(string&);  //string�� �Է��ϴ� �Լ�
	void InputData();   //������ �ִ� �Լ�
	void PrintTitle();  //���� ������ִ� �Լ�
	void PrintData();  //������ ������ִ� �Լ�
	void CalcGPA(string, int);  //GPA������ִ� �Լ�
	string GetName();   //�̸� �������ִ� �Լ�
	int GetHakjum();  //���� �������ִ� �Լ�
	string GetGrade();  //��� �������ִ� �Լ�
	float GetGPA();   //GPA �������ִ� �Լ�
};

#endif // !SUBJECT_H
