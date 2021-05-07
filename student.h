#ifndef STUDENT_H  //헤더의 중복을 막기 위해 씀
#define STUDENT_H
#include "subject.h"  //subject 헤더 파일 추가해줌, subject헤더 파일에 있는 내용을 쓰기 때문

class Student {  //Student 클래스 
protected:   //protected (클래스 안에서만 쓸 수 있음)
	string m_name;   //학생명
	int m_hakbun;    //학번
	int m_subnum;    //수강한 과목 수
	Subject* m_sub;   //수강한 과목들
	float m_aveGPA;   //수강한 과목들의 평균 평점

public:    //public형 
	void Initialize();   //초기설정하는 함수
	void Initialize(string, int, int, Subject*);  //주어진 정보로 초기설정하는 함수
	void Remove();  //메모리 해제해주는 함수
	void InputValue(int&);  //인트형 입력받는 함수
	void InputValue(string&);  //string형 입력 받는 함수
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(); // 평균 평점 계산
	string GetName();  //이름 리턴해주는 함수
	int GetHakbun();  //학번 리턴해주는 함수
	int GetSubNum();  //과목수 리턴해주는 함수
	float GetAveGPA();   //평균학점 리턴해주는 함수
	friend void ShowData(const Student& s);  //friend형 ShowData 선언. 클래스 멤버가 아니어도 멤버에 접근을 할 수 있음
};

#endif // !STUDENT_H