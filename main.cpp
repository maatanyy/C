/**************************************************/
/*             HW#11 : 객체지향방식의 성적처리프로그램#4 작성  */
/*  작성자 : 노민성   날짜 : 2021년 5월 28일              */
/*                                                       */
/* 문제 정의 :
#11-1. 기본클래스 작성 : IOInterface Class 작성
#11-2. 파생클래스 작성
? IOInterface Class를 상속받는 Subject 및 Student Class 작성 후 테스트
#11-3. 기본클래스와 파생클래스의 관계
? 인자있는 생성자, 멤버 : 상속된 멤버, 추가된 멤버, 재정의된 멤버함수
#11-4. Student Class의 Modify() 함수 변경
? 과목정보를 변경할 때 수정하고자 하는 과목을 검색한 후, 검색된 과목만 수정할 수 있도록 변경

IOInterface class 작성. 
Subject 및 Student class 는 IOInterface Class를 상속받습니다.
IOInterface Class의 default 생성자를 추가하였습니다(1번 문제 오류해결을 위해서)
그리고 m_data의 값 때문에 student,subject 클래스의 생성자 부분에 m_data를 추가하였습니다.
Modify부분을 수정하였고 예시는 과목이 하나이길래 과목이 여러개인 경우도 테스트해봤습니다.
그리고 강의자료의 Test를 Main함수에 구현하여 오류가 없나 확인하였습니다*/
/*************************************************/


#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

#include "student.h"      //student 헤더파일 추가  
#include "subject.h"      //subject 헤더파일 추가
#include "InputUtil.h"
#include "IOInterface.h"

void ShowData(const Student&);   //ShowData함수 선언

void Data(const Student& s) { // 응용프로그램에 있는 전역함수
	cout << s.GetName() << "이 수강한 과목은 총" << s.GetSubNum() << "개로";
	cout << "수강한 과목의 평균평점은" << s.GetAveGPA() << "입니다.\n";
}

void main() {
	cout.precision(3);   //깔끔하게 출력하기 위해 사용

	//Student std;
	//cout << std.GetData() << "\n";   //IOInterface 에서 사용할 수 있는 적절한 기본 생성자가 없어서 오류 남

	/*Subject sub("컴퓨터", 3, "C");
	cout << "-----------------------------\n";
	cout << "m_data : " << sub.GetData()<<"\n";
	cout << "교과목 이름 : "<< sub.Subject::GetName() << "\n";
	cout << "부모클래스의 이름 : " << sub.IOInterface::GetName() << "\n";	
	cout << "-----------------------------\n\n";

	Student std("홍길동", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	cout << "m_data : " << std.GetData() << "\n";
	cout << "학생 이름 : " << std.Student::GetName() << "\n";
	cout << "부모클래스의 이름 : " << std.IOInterface::GetName() << "\n";
	cout << "-----------------------------\n\n";*/

	
	//11-4 과목 여러개일때 테스트
	// 
	//Subject sub1[2] = { Subject("컴퓨터", 3, "C"), Subject("현대무용", 2, "A") };
	//Student std("홍길동", 20138342, 2, sub1);
	//std.PrintData();
	//std.Modify(); // Student Class의 멤버변수 값 수정
	//std.PrintData();

	Subject sub("컴퓨터", 3,"C");   //과목 정보
	Student std("홍길동", 20138342, 1,&sub);   //학생 선언
	std.PrintData();   //학생정보 출력
	std.Modify();   // Student Class의 멤버변수 값 수정
	std.PrintData();   //std정보 출력

}

//void ShowData(const Student& s) {  //ShowData 함수 
//	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";   //입력받은 학생의 총 과목 평균평점 출력해줌
//	cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다.\n";
//}