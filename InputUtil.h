#ifndef INPUTUTIL_H   //헤더의 중복을 막기 위해 씀
#define INPUTUTIL_H

class InputUtil {  //사용자로부터 입력 받는 것 모은 Class

public:
	static void InputValue(int& i) {  //int 입력받는 함수
		
		while (1) {     //무한 반복
			cin >> i;  //int형 i 입력받음

			if (cin.fail()) {  //cin.fail 즉 정수가 아닌 값이 들어오면
				cin.clear();    //지우고
				cin.ignore(255,'\n');   //버퍼를 비워준다
				cout << "정수로 입력해주세요 : ";   //정수로 입력해달라고 요청
			}

			else {  //만약 정수로 입력이 들어왔으면
				cin.ignore();   //버퍼를 비워주고
				break;       //반복문 탈출
			}

		}
	}

	static void InputValue(string& str) {  //string 입력 받는 함수
		while (1) {        //무한 반복
			getline(cin, str);  //getline을 통해 string str 입력받음
			if (cin.fail()) {    //cin.fail 즉 정수가 아닌 값이 들어오면
				cin.clear();       //지우고
				cin.ignore(255, '\n');    //버퍼를 비워준다
				cout << "문자열로 입력해주세요 : ";   //문자열로 입력해달라고 요청
			}
			else {   //만약 string으로 입력이 들어왔으면
				break;  //반복문 탈출
			}
		}
	
	}

	static void InputValue(char *c) {  //char형 입력 받는 함수
		while (1) {    //무한 반복
			cin >> c;  //char형 c입력 받음
			if (cin.fail()) {    //cin.fail 즉 char형이 아닌 값이 들어오면
				cin.clear();      //지우고
				cin.ignore(255, '\n');  //버퍼를 비워준다
				cout << "문자로 입력해주세요 : ";  //문자로 입력해달라고 요청
			}

			else {  //만약 char형으로 들어왔으면
				cin.ignore();  //버퍼를 비워준다
				break;   //반복문 탈출
			}

		}
	}
	static void InputValue(float &f) {  //float형으로 입력 받는 함수
		while (1) {   //무한 반복
			cin >> f;  //float형 f 입력 받음
			if (cin.fail()) { //cin.fail 즉 float형이 아닌 값이 들어오면
				cin.clear();    // 지우고
				cin.ignore(255, '\n');   // 버퍼를 비워준다
				cout << "실수로 입력해주세요 : ";  //실수로 입력해달라고 요청
			}

			else {   //만약 float형으로 들어왔으면
				cin.ignore();  //버퍼를 비워준다
				break;   //반복문 탈출
			}

		}
	}

	static void InputValue(double &d) {    //double형으로 입력 받는 함수
		while (1) {   //무한 반복
			cin >> d;  //double형 d 입력받음
			if (cin.fail()) { //cin.fail 즉 double형이 아닌 값이 들어오면
				cin.clear();   // 지우고
				cin.ignore(255, '\n');  // 버퍼를 비워준다
				cout << "실수로 입력해주세요 : ";  //실수로 입력해달라고 요청
			}
			else {  //만약 double형으로 들어왔으면
				cin.ignore();  //버퍼를 비워준다
				break;  //반복문 탈출
			}

		}
	}

};

#endif // !INPUTUTIL_H
