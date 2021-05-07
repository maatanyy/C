#ifndef SUBJECT_H   //헤더의 중복을 막기 위해 씀
#define SUBJECT_H

class Subject {  //Subject 클래스
protected:    //protected (클래스 안에서만 쓸 수 있음)
	string m_name;   // 과목이름 string형 사용
	int m_hakjum;   // 과목학점
	string m_grade;   // 과목등급 string형 사용
	float m_GPA;   // 과목 평점

public:   //public형 
	void Initialize();  //초기설정하는 함수
	void Initialize(string, int, string);  //주어진 정보로 초기설정하는 함수
	void InputValue(int&);   //인트형 입력하는 함수
	void InputValue(string&);  //string형 입력하는 함수
	void InputData();   //데이터 넣는 함수
	void PrintTitle();  //제목 출력해주는 함수
	void PrintData();  //데이터 출력해주는 함수
	void CalcGPA(string, int);  //GPA계산해주는 함수
	string GetName();   //이름 리턴해주는 함수
	int GetHakjum();  //학점 리턴해주는 함수
	string GetGrade();  //등급 리턴해주는 함수
	float GetGPA();   //GPA 리턴해주는 함수
};

#endif // !SUBJECT_H
