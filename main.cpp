/**************************************************/
/*             HW#8 : 객체지향방식의 성적처리프로그램#1 작성  */
/*  작성자 : 노민성   날짜 : 2021년 5월 7일              */
/*                                                       */
/* 문제 정의 :    
Subject 구조체를 class로 변경
Subject Class에 멤버함수 접근자 함수 추가
Student Class의 멤버함수로 접근자 함수 추가
Student Class에 friend 함수 ShowData() 지정  
분할 컴파일            
student.cpp subject.cpp와 각 헤더파일을 만들었습니다
그리고 강의자료의 Test를 Main함수에 구현하여 오류가 없나 확인하였습니다*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "student.h"      //student 헤더파일 추가  
#include "subject.h"      //subject 헤더파일 추가

void ShowData(const Student&);   //ShowData함수 선언

void main() {
	cout.precision(3);   //깔끔하게 출력하기 위해 사용
	
	Student st;  //Student형 st선언


	//Subject Class 테스트


	Subject sub1, sub2, sub3[2], * sub4;  //Subject형 변수들 선언(다양하게)
	int i;
	sub1.Initialize();  //sub1초기화 (subject 클래스의 함수사용)
	sub2.Initialize("사진학", 3, "A+");   //sub2초기화 (subject 클래스의 함수사용)

	for (i = 0; i < 2; i++)  
		sub3[i].Initialize("컴퓨터", 3, "C");  //sub[3]초기화

	sub4 = new Subject[2];      //sub4 선언 (동적할당)
	sub1.InputData(); // 화면에서 입력
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle();   
	sub1.PrintData();  //sub1 정보 출력
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle();
	sub2.PrintData();  //sub2 정보 출력
	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].PrintTitle();  

	for (i = 0; i < 2; i++)    //정보 출력
		sub3[i].PrintData();

	for (i = 0; i < 2; i++)
		(sub4 + i)->InputData();   //정보 입력

	cout << "\n" << "sub4 정보" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++)
		(sub4 + i)->PrintData();

	cout << "Subject Class에 멤버함수로 접근자 함수 테스트\n";
	cout << sub1.GetName();  //sub1이름 출력
	cout << "\n";
	cout << sub2.GetHakjum();  //sub2 학점 출력
	cout << "\n";
	cout << sub1.GetGrade();   //sub1 grade출력
	cout << "\n";
	cout << sub2.GetGPA();    //sub2 GPA출력
	cout << "\n";

	delete[] sub4;  //메모리 해제


	//Student Class 테스트

	Subject sub[2];   //Subject형 sub[2]선언
	sub[0].Initialize("컴퓨터", 3, "C");  //초기화(Subject형 함수 사용해서)
	sub[1].Initialize("현대무용", 2, "A");  //초기화(Subject형 함수 사용해서)
	Student st1, st2;  //Student st1, st2 선언
	st1.Initialize();   //초기화
	st2.Initialize("홍길동", 2013909845, 2, sub);  //초기화
	st1.InputData();   //st1에 정보 입력
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();
	ShowData(st1);  //ShowData 함수를 이용해서 st1에 관한 것 보여줌
	st1.Remove();

	cout << "\n";
}

void ShowData(const Student& s) {  //ShowData 함수 
	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";   //입력받은 학생의 총 과목 평균평점 출력해줌
	cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다.\n";
}