/**************************************************/
/*             HW#9 : 객체지향방식의 성적처리프로그램#2 작성  */
/*  작성자 : 노민성   날짜 : 2021년 5월 14일              */
/*                                                       */
/* 문제 정의 :
Subject Class와 Student Class에 Modify() 멤버함수 추가
Subject Class에 생성자, 소멸자 만들기
Student Class에 생성자, 복사생성자, 소멸자 만들기
기존의 Initialize 함수가 삭제되고 Inititalize 함수에 있던
내용이 생성자 쪽으로 이동 됨
생성자는 하나도 정의 안할시 기본으로 default 컴파일러가 만들고
하나라도 지정할시 세분화해서 해야함
소멸자는 동적할당 받은 게 있으면 해제해줘야함
Modify는 값에 변화가 있을 때 수정해주는 함수임.

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

	//Student st;  //Student형 st선언

	////Subject Class 테스트


	//Subject sub1, sub2, sub3[2], * sub4;  //Subject형 변수들 선언(다양하게)
	//int i;
	//sub1.Initialize();  //sub1초기화 (subject 클래스의 함수사용)
	//sub2.Initialize("사진학", 3, "A+");   //sub2초기화 (subject 클래스의 함수사용)

	//for (i = 0; i < 2; i++)  
	//	sub3[i].Initialize("컴퓨터", 3, "C");  //sub[3]초기화

	//sub4 = new Subject[2];      //sub4 선언 (동적할당)
	//sub1.InputData(); // 화면에서 입력
	//cout << "\n" << "sub1 정보" << "\n";
	//sub1.PrintTitle();   
	//sub1.PrintData();  //sub1 정보 출력
	//cout << "\n" << "sub2 정보" << "\n";
	//sub2.PrintTitle();
	//sub2.PrintData();  //sub2 정보 출력
	//cout << "\n" << "sub3 정보" << "\n";
	//sub3[0].PrintTitle();  

	//for (i = 0; i < 2; i++)    //정보 출력
	//	sub3[i].PrintData();

	//for (i = 0; i < 2; i++)
	//	(sub4 + i)->InputData();   //정보 입력

	//cout << "\n" << "sub4 정보" << "\n";
	//sub4->PrintTitle();
	//for (i = 0; i < 2; i++)
	//	(sub4 + i)->PrintData();

	//cout << "Subject Class에 멤버함수로 접근자 함수 테스트\n";
	//cout << sub1.GetName();  //sub1이름 출력
	//cout << "\n";
	//cout << sub2.GetHakjum();  //sub2 학점 출력
	//cout << "\n";
	//cout << sub1.GetGrade();   //sub1 grade출력
	//cout << "\n";
	//cout << sub2.GetGPA();    //sub2 GPA출력
	//cout << "\n";

	//delete[] sub4;  //메모리 해제


	////Student Class 테스트

	//Subject sub[2];   //Subject형 sub[2]선언
	//sub[0].Initialize("컴퓨터", 3, "C");  //초기화(Subject형 함수 사용해서)
	//sub[1].Initialize("현대무용", 2, "A");  //초기화(Subject형 함수 사용해서)
	//Student st1, st2;  //Student st1, st2 선언
	//st1.Initialize();   //초기화
	//st2.Initialize("홍길동", 2013909845, 2, sub);  //초기화
	//st1.InputData();   //st1에 정보 입력
	//cout << "\n" << "st1 정보" << "\n";
	//st1.PrintData();
	//cout << "\n" << "st2 정보" << "\n";
	//st2.PrintData();
	//ShowData(st1);  //ShowData 함수를 이용해서 st1에 관한 것 보여줌
	//st1.Remove();

	//cout << "\n";

	Subject sub1("컴퓨터", 3, "C");  //sub1 인자있는 생성자로 생성
	Subject sub2(sub1);   //sub2 복사생성자로 생성
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle();  //깔끔하게 보일려고 추가해줬음
	sub1.PrintData();   //sub1 정보 출력
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle();  //깔끔하게 보일려고 추가해줬음
	sub2.PrintData();   //sub2정보 출력
	sub2.Modify();   //sub2 정보 수정
	Student st2("홍길동", 2013909845, 1, &sub1);    //st2 인자있는 생성자로 생성
	Student st1(st2);   //깊은복사 Student::Student(const Student& std)생성자 이용
	Student st3("김성령", 2015909845, 1, &sub2);  //st3 인자있는 생성자로 생성
	//st1 = st2;   얕은 복사입니다. 즉 아래에 st2.Modify를 통하여 값을 바꾸면 st1, st2 같은 값으로 바뀝니다 
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();   //st1 정보 출력
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();  //st2 정보 출력
	st2.Modify();     //st2 정보 수정
	cout << "\n" << "수정된 st2 정보" << "\n";
	st2.PrintData();   //수정된 st2 정보 출력
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();    //st1 정보 출력
	cout << "\n" << "st3 정보" << "\n";
	st3.PrintData();   //st3 정보 출력

}

void ShowData(const Student& s) {  //ShowData 함수 
	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";   //입력받은 학생의 총 과목 평균평점 출력해줌
	cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다.\n";
}