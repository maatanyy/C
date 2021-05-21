/**************************************************/
/*             HW#9 : 객체지향방식의 성적처리프로그램#3 작성  */
/*  작성자 : 노민성   날짜 : 2021년 5월 20일              */
/*                                                       */
/* 문제 정의 :
#10-1. Student Class에 SubSearch() 멤버함수 추가 : 과목탐색
#10-2. Subject Class와 Student Class에 정적멤버함수, const 멤버함수 작성
#10-3. InputUtil Class 작성 : 데이터를 입력을 위한 새로운 Class
#10-4. Subject Class와 Student Class를 사용한 여러가지 객체 생성

학생이 듣는 과목 중에 찾으려는 과목과 일치하는 함수를 Student Class에 구현하였습니다.
PrintTitle을 static으로 구현하여 클래스에서 공통적으로 사용할 수 있게 하였습니다.
기존에 InputValue를 :InputUtil.h에 구현하였고 다른 형식도 추가하였습니다.
Subject Class와 Student Class를 사용한 여러가지 객체를 생성한 걸 오류가 있나 실행했습니다.

기존의 과제에서 만든 생성자,소멸자 실행시 출력해주는 부분은 생성자부분은 주석 처리했습니다. (출력 결과 확인시 너무 복잡해서)
그리고 강의자료의 Test를 Main함수에 구현하여 오류가 없나 확인하였습니다*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "student.h"      //student 헤더파일 추가  
#include "subject.h"      //subject 헤더파일 추가
#include "InputUtil.h"

void ShowData(const Student&);   //ShowData함수 선언

void Data(const Student& s) { // 응용프로그램에 있는 전역함수
	cout << s.GetName() << "이 수강한 과목은 총" << s.GetSubNum() << "개로";
	cout << "수강한 과목의 평균평점은" << s.GetAveGPA() << "입니다.\n";
}

void main() {
	cout.precision(3);   //깔끔하게 출력하기 위해 사용

	//Subject* Student::SubSearch() 멤버함수 테스트
	 
	//Student std;    
	//std.InputData();
	//std.PrintData();
	//Subject* sub = std.SubSearch("사진학");
	//// 과목명이 성공적으로 탐색된 경우
	//// 해당 과목정보가 있는 메모리 주소를 리턴
	//if (sub != NULL) {
	//	sub->PrintTitle();
	//	sub->PrintData();
	//}

	//Subject sub1("컴퓨터", 3, "C");    //sub1 주어진 정보로 선언
	//Subject sub2("계산기", 2, "A");    //sub2 주어진 정보로 선언
	//Subject::PrintTitle();             //Subject::PrintTitle 함수 호출
	//sub1.PrintData();                  //sub1정보 출력
	//sub2.PrintData();                   //sub2정보 출력 
	//Student st1("홍길동", 2013909845, 1, &sub1);     //st1 주어진 정보로 선언
	//st1.PrintData();                           //st1 정보 출력
	//Data(st1);                  

	Subject sub1[2] = { Subject("컴퓨터", 3, "C"), Subject("현대무용", 2, "A") };      // Subject배열로 과목 2개 sub1에 선언
	Subject* sub2[2] = { new Subject(), new Subject("수학", 3, "C") };                // Subject형 포인터로 과목 2개 sub2[2]에 선언
	Student st1;                                    // 학생 st1 선언
	Student st2("홍길동", 2013909845, 2, sub1);         // st를 해당 정보로 초기화해서 선언
	Student* st3 = new Student[2];             // Student형 포인터 st3을 동적할당
	cout << "\n" << "sub2[0] 입력" << "\n";      
		sub2[0]->InputData();              //sub2[0] 입력받음
	cout << "\n" << "st1 입력" << "\n";
	st1.InputData();                   //st1 입력 받음
	cout << "\n" << "st3 입력" << "\n";
	for (int i = 0; i < 2; i++)             //반복문을 수행하며 학생들 정보 입력 받음
		(st3 + i)->InputData();    
	cout << "\n" << "sub1 정보 출력" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)          //반복문을 수행하며 과목 정보 출력
		sub1[i].PrintData();
	cout << "\n" << "sub2 정보 출력" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)          //반복문을 수행하며 정보 출력
		sub2[i]->PrintData();       
	cout << "\n" << "st1 정보 출력" << "\n";
	st1.PrintData();                             //st1 정보 출력
	cout << "\n" << "st2 정보 출력" << "\n";
	st2.PrintData();                           //st2 정보 출력
	cout << "\n" << "st3 정보 출력" << "\n";
	for (int i = 0; i < 2; i++)             //반복문을 수행하며 학생정보 출력
		(st3 + i)->PrintData();
}

//void ShowData(const Student& s) {  //ShowData 함수 
//	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";   //입력받은 학생의 총 과목 평균평점 출력해줌
//	cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다.\n";
//}