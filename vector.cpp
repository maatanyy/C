#include <iostream>   
#include <vector>  //벡터 클래스를 쓰기 위해 추가
using namespace std;  //std namespace 사용

/**************************************************/
/*       HW#7 : vector 클래스 사용해보기  */
/*  작성자 : 노민성   날짜 : 2021년 4월 28일  */
/*                                                       */
/* 문제 정의 :     함수를 사용하여 성적처리 프로그램 만들기*/
/*                  - - - - - - -*/

int CountWords(string);  //입력받은 단어 count하는 함수
void PrintWords();  //전체 단어 출력해주는 함수
void RemoveAll();   //동적할당 받은 것 해제해주는 함수

struct WORD {   //WORD 구조체 선언
    string str;   //string형 str를 변수로 가짐
    int count;   //int형 count를 변수로 가짐
};

vector <WORD*> words;   //WORD*를 배열의 원소로 가지는 Vector words선언

int main(void) {  
    cout << "문자열 입력. 종료: Ctrl+Z\n";    //문자열을 입력 받고 CTRL+Z입력시 종료
    string buffer;   //string 형 buffer 선언
    while (cin >> buffer)   //문자열이 들어올때까지 반복
        CountWords(buffer); // CountWordf함수로 입력받은 문자열 전달
   
    PrintWords(); // 단어출력


    return 0;   //종료
}

int CountWords(string input) {   //문자열 없으면 추가 하고 있으면 count 증가시키는 함수
    int size = words.size();   //words.size를 이용해서 words의 사이즈를 size에 저장
    for (int i = 0; i < size; i++) {   //size의 수만큼 반복문을 돔
        if (words[i]->str == input) {  //만약 새로 입력받은 input이 기존의 words[i]와 일치한다면
            words[i]->count += 1;   //기존의 words[i]->count를 하나 증가 시킨다.
            return 0;   //종료
        }
    }

    // 이 경우는 위의 반복문을 나온 경우 즉 기존에 vector에 입력받은 string이 없을 경우임
    WORD* pword = new WORD;    // WORD형 포인터 pword를 동적할당
    words.push_back(pword);   // 벡터 words[]에 push_back을 이용해서 동적할당한 포인터를 추가해줌
    pword->str = input;      // 새로 추가한 pword->str에 입력받은 input을 넣어줌
    pword->count = 1;        //  pword의 카운터를 1로 설정 (처음 들어온 경우에 해당하므로)
    return 0;           //종료
}

void PrintWords() {   //words 안에 있는 정보를 출력해주는 함수
    int size = words.size();  //words.size()를 통해 size의 크기를 알아내서 size에 저장해줌
    cout << " =====\n";
    for (int i = 0; i < size; i++) {   //size 만큼 반복문을 돌면서
        cout <<words[i]->str<<" : "<<words[i]->count<<"\n";   // words[i]->str 와 words[i]->count 출력, 즉 들어있는 문자열과 사용빈도 출력
    }
    cout << " =====\n";
}

void RemoveAll() {
    int size = words.size();

    for (int i = 0; i < size; i++) {
       delete words.back();
    }
}
