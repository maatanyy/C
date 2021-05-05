#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;


class Subject {
protected:
	string m_name;   // 과목이름 string형 사용
	int m_hakjum;   // 과목학점
	string m_grade;   // 과목등급 string형 사용
	float m_GPA;   // 과목 평점

public:
	void Initialize();
	void Initialize(string, int, string);
	void InputValue(int&);
	void InputValue(string&);
	void InputData();
	void PrintTitle();
	void PrintData();
	void CalcGPA(string,int);
};

void Subject::Initialize() {
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
}

void Subject::Initialize(string m_name, int m_hakjum, string m_grade) {
	this->m_name = m_name;
	this->m_hakjum = m_hakjum;
	this->m_grade = m_grade;
	CalcGPA(this->m_grade, this->m_hakjum);
}

void Subject::InputValue(int& i) {
	cin >> i;
	cin.ignore();   //cin으로 입력받은 후에는 cin.ignore써서 버퍼 제거해줌
}

void Subject::InputValue(string& str) {
	getline(cin, str);  //getline을 통해 string str 입력받음
}

void Subject::InputData() {

			cout <<"수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

				cout << "교과목명 : ";
				InputValue(this->m_name);     //교과목명 받음
				cout << "과목학점수(숫자) : ";
				InputValue(this->m_hakjum);   //과목 학점수 받음

				cout << "과목등급<A+ ~ F> : ";
				InputValue(this->m_grade);    //과목 등급 받음
				cout << '\n';		

				CalcGPA(this->m_grade, this->m_hakjum);
}

void Subject::PrintTitle() {
	cout << "------------------------------------------\n";
	cout << "    교과목명    학점수    등급    평점    \n";
	cout << "------------------------------------------\n";
}

void Subject::PrintData() {
	cout << "------------------------------------------\n";
	cout << "    " <<this->m_name<<"       "<<this->m_hakjum<< "       " <<this->m_grade << "       "<<this->m_GPA<<"\n";
	cout << "------------------------------------------\n";
}

void Subject::CalcGPA(string,int) {  // 평점 계산 함수

	if (m_grade == "A+") {         //A+->4.5로 변환
		m_GPA= m_hakjum * 4.5;
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


void main() {
	Subject sub1, sub2, sub3[2], * sub4;
	int i;
	sub1.Initialize();
	sub2.Initialize("사진학", 3, "A+");

	for (i = 0; i < 2; i++)
		sub3[i].Initialize("컴퓨터", 3, "C");

	sub4 = new Subject[2];
	sub1.InputData(); // 화면에서 입력
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle(); 
	sub1.PrintData();
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle(); 
	sub2.PrintData();
	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].PrintTitle();

	for (i = 0; i < 2; i++) 
		sub3[i].PrintData();

	for (i = 0; i < 2; i++) 
		(sub4 + i)->InputData();

	cout << "\n" << "sub4 정보" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++) 
		(sub4 + i)->PrintData();

	delete[] sub4;
}