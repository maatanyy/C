#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "subject.h"  //subject헤더파일 추가해줌

void Subject::Initialize() {   //초기화 하는 함수 특별히 들어오는 인자가 없으면 아래처럼 초기화
	m_name = "";  //이름은 ""
	m_hakjum = 0;  //학점은 0
	m_grade = "";   //grade는 ""
	m_GPA = 0.0;   //GPA 는 0.0으로 
}

void Subject::Initialize(string m_name, int m_hakjum, string m_grade) {  //정보가 들어오면 그걸로 초기화 시켜줌
	this->m_name = m_name;     //입력받은 이름을 this->m_name에 넣어줌
	this->m_hakjum = m_hakjum;  //입력받은 학점을 this->m_hakjum에 넣어줌
	this->m_grade = m_grade;   //입력받은 등급을 this->m_grade에 넣어줌
	CalcGPA(this->m_grade, this->m_hakjum);   //CalcGPA함수 호출
}

void Subject::InputValue(int& i) {  //int 입력받는 함수
	cin >> i;
	cin.ignore();   //cin으로 입력받은 후에는 cin.ignore써서 버퍼 제거해줌
}

void Subject::InputValue(string& str) {  //string 입력 받는 함수
	getline(cin, str);  //getline을 통해 string str 입력받음
}

void Subject::InputData() {  //InputData 함수

	cout << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

	cout << "교과목명 : ";
	InputValue(this->m_name);     //교과목명 받음
	cout << "과목학점수(숫자) : ";
	InputValue(this->m_hakjum);   //과목 학점수 받음

	cout << "과목등급<A+ ~ F> : ";
	InputValue(this->m_grade);    //과목 등급 받음
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

string Subject::GetName() {  //이름 리턴해주는 함수
	return m_name;
}

int Subject::GetHakjum() {  //학점 리턴해주는 함수
	return m_hakjum;
}

string Subject::GetGrade() {  //등급 리턴해주는 함수
	return m_grade;
}

float Subject::GetGPA() {  //GPA 리턴해주는 함수
	return m_GPA;
}