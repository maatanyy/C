#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "subject.h"  //subject헤더파일 추가해줌
#include "InputUtil.h"

void Subject::InputData() {  //InputData 함수

	cout << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

	cout << "교과목명 : ";
	InputUtil::InputValue(this->m_name);     //교과목명 받음
	cout << "과목학점수(숫자) : ";
	InputUtil::InputValue(this->m_hakjum);   //과목 학점수 받음

	cout << "과목등급<A+ ~ F> : ";
	InputUtil::InputValue(this->m_grade);    //과목 등급 받음
	cout << '\n';

	CalcGPA(this->m_grade, this->m_hakjum);  //CalcGPA 함수 호출
}

void Subject::PrintTitle() {  //Title 출력해주는 함수
	cout << "-----------------------------------------------------\n";
	cout << "    교과목명     학점수     등급     평점    \n";
	cout << "-----------------------------------------------------\n";
}

void Subject::PrintData() {  // 데이터 출력해주는 함수
	cout << "-----------------------------------------------------\n";
	cout << "      " << this->m_name << "         " << this->m_hakjum << "        " << this->m_grade << "        " << this->m_GPA << "\n";
	cout << "-----------------------------------------------------\n";
}

void Subject::CalcGPA(string, int) {  // 평점 계산 함수

	if (m_grade == "A+") {         //A+->4.5로 변환
		m_GPA = m_hakjum * 4.5;
	}
	else if (m_grade == "A") {        //A0->4.0로 변환
		m_GPA = m_hakjum * 4.0;
	}
	else if (m_grade == "B+") {         //B+->3.5로 변환
		m_GPA = m_hakjum * 3.5;
	}
	else if (m_grade == "B") {         //B0->3.0로 변환
		m_GPA = m_hakjum * 3.0;
	}
	else if (m_grade == "C+") {           //C+->2.5로 변환
		m_GPA = m_hakjum * 2.5;
	}
	else if (m_grade == "C") {             //C0->2.0로 변환
		m_GPA = m_hakjum * 2.0;
	}
	else if (m_grade == "D+") {              //D+->1.5로 변환
		m_GPA = m_hakjum * 1.5;
	}
	else if (m_grade == "D") {             //D0->1.0로 변환
		m_GPA = m_hakjum * 1.0;
	}
	else if (m_grade == "F") {             //F->0로 변환
		m_GPA = m_hakjum * 0.0;
	}
	else if (m_grade == "a+") {
		m_GPA = m_hakjum * 4.5;
	}
	else if (m_grade == "a") {            //대문자와 같은 방식
		m_GPA = m_hakjum * 4.0;
	}
	else if (m_grade == "b+") {
		m_GPA = m_hakjum * 3.5;
	}
	else if (m_grade == "b") {
		m_GPA = m_hakjum * 3.0;
	}
	else if (m_grade == "c+") {
		m_GPA = m_hakjum * 2.5;
	}
	else if (m_grade == "c") {
		m_GPA = m_hakjum * 2.0;
	}
	else if (m_grade == "d+") {
		m_GPA = m_hakjum * 1.5;
	}
	else if (m_grade == "d") {
		m_GPA = m_hakjum * 1.0;
	}
	else if (m_grade == "f") {
		m_GPA = m_hakjum * 0.0;
	}
};

void Subject::Modify() {    //Subject class 멤버변수 수정하는 함수

	cout << "*< " << this->m_name << ", 학점 : " << this->m_hakjum << ", 등급 : " << this->m_grade << ">의 정보를 수정하세요\n";    //과목 정보 출력해주고
	cout << "교과목명 : ";      
	InputUtil::InputValue(this->m_name);   //이름 바꿔줌
	cout << "과목학점 : ";
	InputUtil::InputValue(this->m_hakjum);  //학점바꿔줌
	cout << "과목등급 : ";
	InputUtil::InputValue(this->m_grade);  //등급 바꿔줌
	CalcGPA(this->m_grade, this->m_hakjum);  //CalcGPA 함수 호출

}

string Subject::GetName() const {  //이름 리턴해주는 함수, const형 값 수정 x
	return IOInterface::m_name;
}

int Subject::GetHakjum() const {  //학점 리턴해주는 함수, const형 값 수정 x
	return m_hakjum;
}

string Subject::GetGrade() const {  //등급 리턴해주는 함수, const형 값 수정 x 
	return m_grade;
}

float Subject::GetGPA() const {  //GPA 리턴해주는 함수, const형 값 수정 x
	return m_GPA;
}

Subject::Subject() {    //Subject  default 생성자
	cout << "Subject의 디폴트 생성자 호출됨.\n";   //생성 확인
	m_name = "";  //이름은 ""
	m_hakjum = 0;  //학점은 0
	m_grade = "";   //grade는 ""
	m_GPA = 0.0;   //GPA 는 0.0으로 
}

Subject::Subject(string name, int hakjum, string grade):IOInterface(name) {    //Subject 인자있는 생성자
	cout << "Subject의 인자있는 생성자 호출됨.\n";     //생성 확인
	this->m_name = name;     //입력받은 이름을 this->m_name에 넣어줌
	this->m_hakjum = hakjum;  //입력받은 학점을 this->m_hakjum에 넣어줌
	this->m_grade = grade;   //입력받은 등급을 this->m_grade에 넣어줌
	m_data = 100;
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA함수 호출
}

Subject::Subject(const Subject& sub) { //Subject 복사 생성자
	cout << "Subject의 디폴트 생성자 호출됨.\n";    //생성 확인
	this->m_name = sub.m_name;     //sub.m_name 생성하는 m_name 에 넣어줌
	this->m_hakjum = sub.m_hakjum;    //sub.m_hakjum 생성하는 m_hakjum에 넣어줌
	this->m_grade = sub.m_grade;   //sub.m_grade 생성하는 m_grade에 넣어줌
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA함수 호출
}
 
Subject::~Subject() {   //과목 소멸자
	cout << "Subject의 소멸자 호출됨.\n";  //호출 확인
	                 //동적할당을 하지 않아서 내용이 필요없음
}

