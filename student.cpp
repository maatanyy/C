#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "subject.h"   //subject 헤더파일 추가
#include "student.h"  //student 헤더파일 추가

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
	cout << "                          평균평점" << "     " << this->m_aveGPA << "\n";

}

void Student::CalcAveGPA() { // 평균 평점 계산

	int totalHakjum = 0;  //int형 변수 totalHakjum 선언
	int totalGPA = 0;

	for (int i = 0; i < m_subnum; i++) {  //과목수 만큼 돌면서
		totalGPA += m_sub[i].GetGPA();   //GPA를 더하고
		totalHakjum += m_sub[i].GetHakjum();  //모든 과목의 학점수를 더함
	}
	m_aveGPA = totalGPA / totalHakjum;  //GPA를 총 학점수로 나눠서 평균학점 구함
}

void Student::Modify() {
	string Type = "0";  //학생정보 수정할지 과목정보 수정할지 입력받을 string형 Type선언

	cout << "\n";
	cout << "수정(학생정보/과목정보/모두) : ";

	InputValue(Type);  //Type입력받음

	if (Type == "학생정보") {
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(this->m_name);  //이름바꿔줌
		cout << "학번 : ";
		InputValue(this->m_hakbun);  //학번바꿔줌
	}

	else if (Type == "과목정보") {
		for (int i = 0; i < this->m_subnum; i++) {
		     m_sub[i].Modify();
		}
		CalcAveGPA();
	}

	else if (Type == "모두") {
		cout << "*<" << this->m_name << ", " << this->m_hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(this->m_name);  //이름바꿔줌
		cout << "학번 : ";
		InputValue(this->m_hakbun);  //학번바꿔줌
		this->m_sub->Modify();
		CalcAveGPA();
	}

	else {
		cout << "제대로 입력해주세요.\n";
	}

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

Student::Student() {  //student default 생성자
	cout << "Student() 호출\n";   //호출 확인
	m_name = "";  //이름을 null로 초기화
	m_hakbun = 0;  //학번은 0으로 초기화
	m_subnum = 0;   //과목수 0으로 초기화
	m_sub = NULL;   //과목 NULL로 초기화
	m_aveGPA = 0;  //평균평점 0으로 초기화
}

Student::Student(string name, int hakbun, int subnum, Subject* sub) {  //student 인자있는 생성자
	cout << "Student 생성자 호출(string name, int hakbun, int subnum, Subject* sub)\n";  //호출 확인
	m_name = name;    //입력받은 이름이 이름이 되도록 함
	m_hakbun = hakbun;  //입력받은 학번이 학번이 되도록 함
	m_subnum = subnum;  //입력받은 과목수가 과목수가 되도록 함
	m_sub = new Subject[subnum];  //과목을 과목수만큼 동적할당해줌
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i] = sub[i];   //과목 옮김
	}
	CalcAveGPA();  //평균평점 계산
}

Student::Student(const Student& std) {   //Student 복사 생성자
	cout << "Student 생성자 호출(const Student& std)\n";  //호출 확인
	m_name = std.m_name;   //std.m_name이 복사할 것의 이름이 되도록함
	m_hakbun = std.m_hakbun;   //std.m_hakbun이 복사할 것의 학번이 되도록함
	m_subnum = std.m_subnum;   //std.m_subnum이 복사할 것의 과목수가 되도록함
	m_sub = new Subject[std.m_subnum];   //과목수만큼 동적할당
	for (int i = 0; i < m_subnum; i++) {//과목 옮김
		m_sub[i] = std.m_sub[i];
	}
	CalcAveGPA(); //평균평점 계산
}

Student::~Student() {  //Student 소멸자
	if (m_sub) {  //만약 과목이 있따면(동적할당 받음)
		cout << "Student 소멸자\n";
		delete[] m_sub;   //메모리 해제
	} 
}