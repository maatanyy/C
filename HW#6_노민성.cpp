#include <iostream>
#include <string.h>   //strcmp 쓰기 위해 추가함
#include <string>     //string 관련 함수 쓰기 위해 추가함
using namespace std;

/**************************************************/
/*             HW#6 : string을 사용하여 성적처리프로그램 개선  */
/*  작성자 : 노민성   날짜 : 2021년 4월 16일  */
/*                                                       */
/* 문제 정의 :     함수를 사용하여 성적처리 프로그램 만들기*/
/*                  - - - - - - -
*
	#HW3   21. 3. 25
			학점을 점수로 변환할 때 strcmp 이용해서 변환
			각 함수마다 매개변수 인자를 문제의 조건에 따라서 설정함
			CalcGPA()함수는 매개 변수 인자를 구조체 레퍼런스로
			CalcAveGPA()함수는 매개 변수 인자를 구조체 포인터로
			PrintAllData()함수는 매개 변수 인자를 포인터로
			PrintOneData()함수는 매개 변수 인자를 레퍼런스로
			StdSearch()함수는 함수 인자 및 리턴타입을 포인터로

	#HW4    21. 4. 1
			메뉴 출력 함수 인라인 함수로 구현
			학생수배열 (2명)에서 동적할당으로 할당
			자주 입력되는 개별 데이터 부분 인라인 함수화(inline void InputValue(char *str),inline void InputValue(int &i))
			전체 학생 목록 보기 함수 추가(이름, 학번만)
			학생 정보 수정 (이름, 학번) 기능 추가

	#HW5   21. 4. 8
			동적 메모리를 사용하여 성적처리 프로그램 개선
			학생신상 정보 및 성적 정보 입력 받는 부분 함수로 모듈화
			학생수와 과목수는 사용자로부터 입력 받아서 동적할당을 이용
			사용자로 부터 값을 입력받고 new,delete를 이용한 동적할당으로 함수 재구성
			동적할당을 이용하였으므로 마지막에 delete를 이용해서 메모리 해제를 해줘야함.

	#HW6   21. 4. 16
			문자 배열로 입력 받았던 내용을 string으로 변경
			문자열 입력함수 geline을 통해 입력을 받음
			cin을 이용할 시 그다음에 cin.ignore()를 통해 버퍼 제거
			학점수, 과목명, 등급도 수정할 수 있도록 개선
			특정 과목을 검색하는 함수 추가

/*************************************************/

struct Subject {   // 과목 정보
	string SubName;   // 과목이름 string형 사용
	int Hakjum;   // 과목학점
	string Grade;   // 과목등급 string형 사용
	float GPA;   // 과목 평점
};

struct Student {   // 학생 정보
	string StdName;    // 학생이름 string형 사용
	int Hakbun;    // 학번
	Subject* Sub = NULL;  // 과목
	float AveGPA;   // 교과목 평균 평점
	int SubNum;   //과목수 추가해줌
};

inline void PrintMenu();  // 메뉴 출력함수 인라인 함수로 선언
inline void InputValue(string &str); //문자열 관련 입력 받을 때 사용하는 함수
inline void InputValue(int& i);  //정수형 관련 입력 받을 때 사용하는 함수

void CalcGPA(Subject& Sub);   // 평점 계산 함수
float CalcAveGPA(Subject* Sub, int SubNum);  // 교과목 평점 계산 함수
void PrintAllData(const Student* pSt, int StudentNum); // 전체 학생 정보 출력 함수
void PrintOneData(const Student& rSt);  // 개인 학생 정보 출력 함수
void PrintAllStdList(Student* pSt, int StudentNum);  //전체 학생의 학번 이름 출력
void ModifyStdInfo(Student* pSt);  //학생 정보 수정
void InputData(Student* pSt, int StudentNum);  //학생의 신상 정보 및 성적을 입력하는 함수
Student* StdSearch(Student* pSt);  // 학생 이름 검색 함수
Subject* SubSearch(const Student* pSt);  //특정 과목이 있나 검색하는 함수


int num = 0;  //변수 num선언 메뉴항목 이동할 때 사용
int StdNum;  //학생수는 한번 입력받으면 바뀌지 않아서 전역변수로 선언했다.

int main(void) {

	Student* SearchStudent = NULL;  //학생있나 찾을 때 쓸 Student형 포인터 초기화
	cout.precision(2);
	cout << fixed;


	cout << "전체 학생 수를 입력해주세요 : ";    //학생수를 입력받음
	InputValue(StdNum);                            //학생수 입력
	cout << "\n";

	struct Student* stu = NULL;
	stu = new Student[StdNum]; // 입력받은 수 만큼 학생 수 동적 할당


	while (1) {  //무한 반복문,4번 입력할 때 까지 반복

		PrintMenu();  //메뉴 출력,인라인 함수로 수정

		if (num == 1) {
			InputData(stu, StdNum);  //InputData를 통해 각 학생의 정보를 받는다
		}

		else if (num == 2) {           //2번 입력했으면
			PrintAllData(stu, StdNum);   //모든 학생정보 출력
		}

		else if (num == 3) {     //3번 입력했으면
			//string search_StdName;
			//cout << "검색 할 학생 이름 : ";        //검색할 학생 이름 입력받아서
			//InputValue(search_StdName);                   //search.StdName에 넣음

			SearchStudent = StdSearch(stu);        //StdSearch함수 써서 리턴값을 SearchSudent가 가르키게함

			if (SearchStudent != NULL) {    //SearchSudent가 가르키는곳이 비어있지 않으면
				cout << "\n";
				PrintOneData(*SearchStudent);   //SearchSudent가 가르키는곳에 있는 값을 PrintOneData함수에 보내줌
			}
			else {                            //SearchSudent가 가르키는곳이 비어있으면
				cout << "해당 학생이 없습니다.\n\n";    //해당 학생 없다고 출력
			}
		}

		else if (num == 4) {    //4번 입력시
			PrintAllStdList(stu, StdNum);   //학생들의 이름 학번 간단히 출력하는 함수 호출
		}


		else if (num == 5) {

			//SearchStudent = StdSearch(stu);       
			ModifyStdInfo(stu);   //원하는 정보를 입력받아 수정하는 함수 호출
		
		}

		else {  //다른 번호 입력시 아마 6번
			for (int i = 0; i < StdNum; i++) {   //학생수 만큼 반복문 반보
				if (stu[i].Sub != NULL) {   //학생의 동적받은 과목이 비어있지 않으면
					delete[] stu[i].Sub;   //해제 해준다
				}
			}
			if (stu != NULL) {  //학생수 만큼 입력받은 학생을 해제하지 않은 상태라면
				delete[] stu;   //해제해준다.
			}
			break;
		}
	};
}

inline void PrintMenu() {              //메뉴 출력함수, 메뉴보여주고 원하는 기능 입력 받음, 인라인 함수임
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
	InputValue(num);      //몇번 진행할지 입력받음
};

inline void InputValue(string &str) {     //인라인함수
	getline(cin, str);  //getline을 통해 string str 입력받음
};


inline void InputValue(int& i) {          //인라인함수, 정수형 입력받을때사용
	cin >> i;
	cin.ignore();   //cin으로 입력받은 후에는 cin.ignore써서 버퍼 제거해줌
};

void CalcGPA(Subject& Sub) {  // 평점 계산 함수


	if (Sub.Grade=="A+") {         //A+->4.5로 변환
		Sub.GPA = Sub.Hakjum * 4.5;
	}
	else if (Sub.Grade=="A0") {        //A0->4.0로 변환
		Sub.GPA = Sub.Hakjum * 4.0;
	}
	else if (Sub.Grade=="B+") {         //B+->3.5로 변환
		Sub.GPA = Sub.Hakjum * 3.5;
	}
	else if (Sub.Grade=="B0") {         //B0->3.0로 변환
		Sub.GPA = Sub.Hakjum * 3.0;
	}
	else if (Sub.Grade=="C+") {           //C+->2.5로 변환
		Sub.GPA = Sub.Hakjum * 2.5;
	}
	else if (Sub.Grade=="C0") {             //C0->2.0로 변환
		Sub.GPA = Sub.Hakjum * 2.0;
	}
	else if (Sub.Grade=="D+") {              //D+->1.5로 변환
		Sub.GPA = Sub.Hakjum * 1.5;
	}
	else if (Sub.Grade=="D0") {             //D0->1.0로 변환
		Sub.GPA = Sub.Hakjum * 1.0;
	}
	else if (Sub.Grade=="F") {             //F->0로 변환
		Sub.GPA = Sub.Hakjum * 0.0;
	}
	else if (Sub.Grade=="a+") {
		Sub.GPA = Sub.Hakjum * 4.5;
	}
	else if (Sub.Grade=="a0") {            //대문자와 같은 방식
		Sub.GPA = Sub.Hakjum * 4.0;
	}
	else if (Sub.Grade=="b+") {
		Sub.GPA = Sub.Hakjum * 3.5;
	}
	else if (Sub.Grade=="b0") {
		Sub.GPA = Sub.Hakjum * 3.0;
	}
	else if (Sub.Grade=="c+") {
		Sub.GPA = Sub.Hakjum * 2.5;
	}
	else if (Sub.Grade=="c0") {
		Sub.GPA = Sub.Hakjum * 2.0;
	}
	else if (Sub.Grade=="d+") {
		Sub.GPA = Sub.Hakjum * 1.5;
	}
	else if (Sub.Grade=="d0") {
		Sub.GPA = Sub.Hakjum * 1.0;
	}
	else if (Sub.Grade=="f") {
		Sub.GPA = Sub.Hakjum * 0.0;
	}

};

float CalcAveGPA(Subject* Sub, int SubNum) {      // 교과목 평점 계산 함수 과목
	float c = 0;   //변수 선언
	float d = 0;
	float e = 0;
	for (int i = 0; i < SubNum; i++) {  //과목수만큼 GPA합을 더한다음 d에 저장
		d += Sub[i].GPA;
	}
	for (int j = 0; j < SubNum; j++) {  //과목학점수를 다더해서 e에 저장
		e += Sub[j].Hakjum;
	}

	c = d / e;   //GPA합/학점수 = 전체 평점이고 이걸 c에 저장한다.
	return c;
};

void PrintAllData(const Student* pSt, int StudentNum) {  // 전체 학생 정보 출력 함수
	cout << "\n";
	cout << "         전체 학생 성적 보기\n";               //전체 학생 성적 보기 출력
	cout.width(70); cout.fill('=');  cout << "\n";

	for (int i = 0; i < StudentNum; i++) {     //전체 학생 수 만큼 정보 출력
		PrintOneData(*(pSt + i));
	}
}

void PrintOneData(const Student& rSt) {   // 개인 학생 정보 출력 함수
	cout << "이름 : " << rSt.StdName << "  학번 : " << rSt.Hakbun << "\n";  //학생 학번 출력
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "              과목명  과목학점  과목등급    과목평점 \n";           //학생 3과목 각각 과목명 학점 등급 평점 출력
	cout.width(70); cout.fill('=');  cout << "\n";
	for (int j = 0; j < rSt.SubNum; j++) {
		cout << "              " << rSt.Sub[j].SubName << "      " << rSt.Sub[j].Hakjum << "           " << rSt.Sub[j].Grade << "        " << rSt.Sub[j].GPA << "\n";
	}
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "                               평균평점        " << rSt.AveGPA << "\n";   //학생 평균평점 출력
	cout << "\n";
};

Student* StdSearch(Student* pSt) {  // 학생 이름 검색 함수

	string searchName;
	cout << "검색 할 학생 이름 : ";        //검색할 학생 이름 입력받아서
	InputValue(searchName);

	for (int i = 0; i < StdNum; i++) {            //학생 수 만큼 돌면서
		if ((pSt + i)->StdName == searchName) {     //만약 이름이 찾는사람이랑 같은 사람이있으면
			return pSt + i;    //이름이 같은곳의 주소를 리턴
		}
	}
	return NULL;  //입력받은 이름이 없다면 NULL리턴
};

Subject* SubSearch(const Student* pSt) {  //과목 검색 함수
	string subName;  //검색할 과목명 string으로 선언
	cout << "검색 할 과목 이름 : ";
	InputValue(subName);  //과목명 검색 받음
	for (int i = 0; i < pSt->SubNum; i++) {   //학생의 과목수만큼 반복문을 돌면서
		if (pSt->Sub[i].SubName == subName) {    //과목명이 검색한 과목과 일치하는게 있으면
			return &pSt->Sub[i];	//구조체의 주소(과목의 시작주소)를 반환합니다  
		}
	}
	return NULL; //없으면 NULL 리턴
}


void PrintAllStdList(Student* pSt, int StudentNum) {  //전체 학생의 학번 이름 출력
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "           학번              이름\n";
	cout.width(70); cout.fill('=');  cout << "\n";

	for (int t = 0; t < StudentNum; t++) {
		cout << "           " << pSt[t].Hakbun << "                " << pSt[t].StdName << "\n";    //반복문을 이용하여 학번 이름만 출력
	}
	cout << "\n";
}

void ModifyStdInfo(Student* pSt) {  //정보를 수정하는 함수

	Student* St = StdSearch(pSt);  //StdSearch(pSt)값을 Student 포인터 St가 가르키게함

	if (St != NULL) {  //만약 검색받은 학생이 존재한다면
		string Type="0";  //학생정보 수정할지 과목정보 수정할지 입력받을 string형 Type선언

		cout << "\n";
		cout << "수정(학생정보/과목정보) : ";

		InputValue(Type);  //Type입력받음

		if (Type == "과목정보") {  //만약 과목정보를 수정할거면

			Subject* Sub = SubSearch(St);  //SubSearch를 통해 과목을 입력받고 있는 과목인지 확인

			if (Sub == NULL) {  //없는 과목을 입력하면
				cout << "제대로 입력해주세요.\n";  //제대로 입력해달라고 출력
			}

			else {   //있는 과목이면
				cout << "*< " << Sub->SubName << ", 학점 : " << Sub->Hakjum << ", 등급 : " << Sub->Grade << ">의 정보를 수정하세요\n";  //과목 정보 출력해주고
				cout << "교과목명 : ";

				InputValue(Sub->SubName);  //이름 바꿔줌
				cout << "과목학점 : ";
				InputValue(Sub->Hakjum);  //학점바꿔줌
				cout << "과목등급 : ";
				InputValue(Sub->Grade);  //등급 바꿔줌

				for (int a = 0; a < St->SubNum; a++) {  //과목수만큼 반복하며 성적 변환
					CalcGPA(St->Sub[a]);
				}

				St->AveGPA = CalcAveGPA(St->Sub, St->SubNum);  //총평점도 다시계산해줌
			}
		}
		else if (Type == "학생정보") {  //만약 학생정보를 수정한다고 입력했으면
			cout << "*<" <<St->StdName<< ", " << St->Hakbun << ">의 정보를 수정하세요\n";
			cout << "이름 : ";
			
			InputValue(St->StdName);  //이름바꿔줌
			cout << "학번 : ";
			InputValue(St->Hakbun);  //학번바꿔줌
		}
	}

	else {  //이름을 이상하게 입력하면
		cout << "학생이름을 한번 더 확인해주세요!\n";  //확인요구
	}

}

void InputData(Student* std, int StdNum) {   //전체 학생의 신상 정보 및 성적 정보를 입력받는 함수

	for (int i = 0; i < StdNum; i++) {   //학생수만큼 반복문을 돈다

		cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";   //이름과 학번을 입력받음
		// 이름 입력
		cout << "이름 : ";
		
		InputValue((std+i)->StdName);   //이름을 입력받음
		
		cout << "학번 : ";    // 학번 입력
		InputValue((std + i)->Hakbun);   //학번을 입력받음

		cout << "전체 과목 수를 입력해주세요 : ";   //전체 과목수를 입력 받음 . 과목수는 학생마다 다르기때문에 동적할당을 사용할 것임
		InputValue((std + i)->SubNum);    //과목수를 입력 받음
		cout << "\n";

		(std + i)->Sub = new Subject[(std + i)->SubNum];   //입력받은 수 만큼 과목수 동적할당

		cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (int j = 0; j < std[i].SubNum; j++) {        //학생에 관한 각 과목 정보 받음
			cout << "교과목명 : ";
			
			InputValue(std[i].Sub[j].SubName);     //교과목명 받음
			cout << "과목학점수(숫자) : ";
			InputValue(std[i].Sub[j].Hakjum);   //과목 학점수 받음
			
			cout << "과목등급<A+ ~ F> : ";
			
			InputValue(std[i].Sub[j].Grade);    //과목 등급 받음
			cout << '\n';
		}
		cout << "\n\n\n\n";
	}

	for (int a = 0; a < StdNum; a++) {    //학생들 성적 평점 계산
		for (int b = 0; b < std[a].SubNum; b++) {
			CalcGPA(std[a].Sub[b]);   //과목수만큼 CalcGPA함수 실행
		}
	}

	for (int k = 0; k < StdNum; k++) {   //학생수만큼 반복
		std[k].AveGPA = CalcAveGPA(std[k].Sub, std[k].SubNum);   // 학생 평균평점구하기
	}
}






