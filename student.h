#ifndef STUDENT_H  //헤더의 중복을 막기 위해 씀
#define STUDENT_H
#include "subject.h"  //subject 헤더 파일 추가해줌, subject헤더 파일에 있는 내용을 쓰기 때문
#include "IOInterface.h"
class Student : public IOInterface {  //Student 클래스 

protected:   //protected (클래스 안에서만 쓸 수 있음)
	string m_name;   //학생명
	int m_hakbun;    //학번
	int m_subnum;    //수강한 과목 수
	Subject* m_sub;   //수강한 과목들
	float m_aveGPA;   //수강한 과목들의 평균 평점

public:    //public형 
	Student();     //Student default 생성자
	Student(string name, int hakbun, int subnum, Subject* sub);   //Student 인자있는 생성자
	Student(const Student& std);    //Student 복사 생성자
	~Student();   //Student 소멸자

	void InputData();   // 멤버변수 값 입력
	void PrintData();   // 멤버변수 값 출력
	void CalcAveGPA();   // 평균 평점 계산
	Subject* SubSearch(string subname);  //과목 찾는 함수

	void Modify();

	string GetName() const;  //이름 리턴해주는 함수
	int GetHakbun() const;  //학번 리턴해주는 함수
	int GetSubNum() const;  //과목수 리턴해주는 함수
	float GetAveGPA() const;   //평균학점 리턴해주는 함수
	friend void ShowData(const Student& s);  //friend형 ShowData 선언. 클래스 멤버가 아니어도 멤버에 접근을 할 수 있음
};

#endif // !STUDENT_H
