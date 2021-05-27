#ifndef SUBJECT_H   //헤더의 중복을 막기 위해 씀
#define SUBJECT_H
#include "IOInterface.h"
class Subject : public IOInterface {  //Subject 클래스

protected:    //protected (클래스 안에서만 쓸 수 있음)
	string m_name;   // 과목이름 string형 사용
	int m_hakjum;   // 과목학점
	string m_grade;   // 과목등급 string형 사용
	float m_GPA;   // 과목 평점

public:   //public형 
	Subject();   //Subject  default 생성자
	Subject(string name, int hakjum, string grade);  //Subject 인자있는 생성자
	Subject(const Subject& sub);   //Subject 복사생성자
	~Subject();   //Subject 소멸자

	void InputData();   //데이터 넣는 함수
	static void PrintTitle();  // 제목 출력해주는 함수 static을 이용하여 공용으로 만듬
	void PrintData();  //데이터 출력해주는 함수
	void CalcGPA(string, int);  //GPA계산해주는 함수

	void Modify();  //Subject class 멤버변수 수정하는 함수

	string GetName() const;   //이름 리턴해주는 함수
	int GetHakjum() const;  //학점 리턴해주는 함수
	string GetGrade() const;  //등급 리턴해주는 함수
	float GetGPA() const;   //GPA 리턴해주는 함수
};

#endif // !SUBJECT_H

