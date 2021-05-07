#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "subject.h"   //subject 헤더파일 추가
#include "student.h"  //student 헤더파일 추가

void Student::Initialize() {    //초기화 하는 함수 아래 값처럼 기본 초기화
	string m_name = "";
	int m_hakbun = 0;
	int m_subnum = 0;
	Subject* m_sub = NULL;
	float m_aveGPA = 0;
}

void Student::Initialize(string name, int hakbun, int subnum, Subject* sub) {  //만약 정보가 입력되면 그 정보로 초기화 해줌
	this->m_name = name;    //입력받은 이름이 이름이 되도록 함
	this->m_hakbun = hakbun;  //입력받은 학번이 학번이 되도록 함
	this->m_subnum = subnum;  //입력받은 과목수가 과목수가 되도록 함
	m_sub = new Subject[subnum];  //과목을 과목수만큼 동적할당해줌
	this->m_sub = sub;  
	CalcAveGPA();
}

void Student::Remove() {  //동적할당 한 것 해제하는 함수
	delete[] m_sub;
}

void Student::InputValue(int& i) {  //int 입력받는 함수
	cin >> i;
	cin.ignore();   //cin으로 입력받은 후에는 cin.ignore써서 버퍼 제거해줌
}

void Student::InputValue(string& str) {  //string 입력받는 함수
	getline(cin, str);  //getline을 통해 string str 입력받음
}

void Student::InputData() {     // 멤버변수 값 입력

	cout << "이름을 입력하세요 : ";
	InputValue(this->m_name);  //이름 입력 받음

	cout << "학번을 입력하세요 : ";
	InputValue(this->m_hakbun);  //학번 입력 받음

	cout << "수강한 과목수를 입력하세요 : ";
	InputValue(this->m_subnum);   //과목수 입력 받음

	m_sub = new Subject[m_subnum];  //과목 과목수만큼 동적할당

	for (int i = 0; i < this->m_subnum; i++) {
		m_sub[i].InputData();   //과목에 대한 정보 입력받음
	}

	CalcAveGPA();  //GPA구함
}


void Student::PrintData() {  // 멤버변수 값 출력
	cout << "-----------------------------------------------------\n";
	cout << "      " << "이름 : " << "    " << this->m_name << "       " << "학번 :    " << this->m_hakbun << "      " << "\n";
	cout << "-----------------------------------------------------\n";

	this->m_sub->PrintTitle();  
	for (int i = 0; i < this->m_subnum; i++) {
		this->m_sub[i].PrintData();  //과목수만큼 돌며 정보 출력
	}

	cout << "-----------------------------------------------------\n";
	cout << "                          평균평점" << "     " << this->m_aveGPA<<"\n";

}

void Student::CalcAveGPA() { // 평균 평점 계산

	int totalHakjum = 0;  //int형 변수 totalHakjum 선언

	for (int i = 0; i < m_subnum; i++) {  //과목수 만큼 돌면서
		m_aveGPA += m_sub[i].GetGPA();   //GPA를 더하고
		totalHakjum += m_sub[i].GetHakjum();  //모든 과목의 학점수를 더함
	}

	this->m_aveGPA = m_aveGPA / totalHakjum;  //GPA를 총 학점수로 나눠서 평균학점 구함
}

string Student::GetName() {  //이름 리턴해주는 함수
	return m_name;
}

int Student::GetHakbun() {  //학번 리턴해주는 함수
	return m_hakbun;
}

int Student::GetSubNum() {  //과목수 리턴해주는 함수
	return m_subnum;
}

float Student::GetAveGPA() {  //평균 GPA 리턴해주는 함수
	return m_aveGPA;
}