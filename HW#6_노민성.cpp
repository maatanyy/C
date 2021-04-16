#include <iostream>
#include <string.h>   //strcmp ���� ���� �߰���
#include <string>     //string ���� �Լ� ���� ���� �߰���
using namespace std;

/**************************************************/
/*             HW#6 : string�� ����Ͽ� ����ó�����α׷� ����  */
/*  �ۼ��� : ��μ�   ��¥ : 2021�� 4�� 16��  */
/*                                                       */
/* ���� ���� :     �Լ��� ����Ͽ� ����ó�� ���α׷� �����*/
/*                  - - - - - - -
*
	#HW3   21. 3. 25
			������ ������ ��ȯ�� �� strcmp �̿��ؼ� ��ȯ
			�� �Լ����� �Ű����� ���ڸ� ������ ���ǿ� ���� ������
			CalcGPA()�Լ��� �Ű� ���� ���ڸ� ����ü ���۷�����
			CalcAveGPA()�Լ��� �Ű� ���� ���ڸ� ����ü �����ͷ�
			PrintAllData()�Լ��� �Ű� ���� ���ڸ� �����ͷ�
			PrintOneData()�Լ��� �Ű� ���� ���ڸ� ���۷�����
			StdSearch()�Լ��� �Լ� ���� �� ����Ÿ���� �����ͷ�

	#HW4    21. 4. 1
			�޴� ��� �Լ� �ζ��� �Լ��� ����
			�л����迭 (2��)���� �����Ҵ����� �Ҵ�
			���� �ԷµǴ� ���� ������ �κ� �ζ��� �Լ�ȭ(inline void InputValue(char *str),inline void InputValue(int &i))
			��ü �л� ��� ���� �Լ� �߰�(�̸�, �й���)
			�л� ���� ���� (�̸�, �й�) ��� �߰�

	#HW5   21. 4. 8
			���� �޸𸮸� ����Ͽ� ����ó�� ���α׷� ����
			�л��Ż� ���� �� ���� ���� �Է� �޴� �κ� �Լ��� ���ȭ
			�л����� ������� ����ڷκ��� �Է� �޾Ƽ� �����Ҵ��� �̿�
			����ڷ� ���� ���� �Է¹ް� new,delete�� �̿��� �����Ҵ����� �Լ� �籸��
			�����Ҵ��� �̿��Ͽ����Ƿ� �������� delete�� �̿��ؼ� �޸� ������ �������.

	#HW6   21. 4. 16
			���� �迭�� �Է� �޾Ҵ� ������ string���� ����
			���ڿ� �Է��Լ� geline�� ���� �Է��� ����
			cin�� �̿��� �� �״����� cin.ignore()�� ���� ���� ����
			������, �����, ��޵� ������ �� �ֵ��� ����
			Ư�� ������ �˻��ϴ� �Լ� �߰�

/*************************************************/

struct Subject {   // ���� ����
	string SubName;   // �����̸� string�� ���
	int Hakjum;   // ��������
	string Grade;   // ������ string�� ���
	float GPA;   // ���� ����
};

struct Student {   // �л� ����
	string StdName;    // �л��̸� string�� ���
	int Hakbun;    // �й�
	Subject* Sub = NULL;  // ����
	float AveGPA;   // ������ ��� ����
	int SubNum;   //����� �߰�����
};

inline void PrintMenu();  // �޴� ����Լ� �ζ��� �Լ��� ����
inline void InputValue(string &str); //���ڿ� ���� �Է� ���� �� ����ϴ� �Լ�
inline void InputValue(int& i);  //������ ���� �Է� ���� �� ����ϴ� �Լ�

void CalcGPA(Subject& Sub);   // ���� ��� �Լ�
float CalcAveGPA(Subject* Sub, int SubNum);  // ������ ���� ��� �Լ�
void PrintAllData(const Student* pSt, int StudentNum); // ��ü �л� ���� ��� �Լ�
void PrintOneData(const Student& rSt);  // ���� �л� ���� ��� �Լ�
void PrintAllStdList(Student* pSt, int StudentNum);  //��ü �л��� �й� �̸� ���
void ModifyStdInfo(Student* pSt);  //�л� ���� ����
void InputData(Student* pSt, int StudentNum);  //�л��� �Ż� ���� �� ������ �Է��ϴ� �Լ�
Student* StdSearch(Student* pSt);  // �л� �̸� �˻� �Լ�
Subject* SubSearch(const Student* pSt);  //Ư�� ������ �ֳ� �˻��ϴ� �Լ�


int num = 0;  //���� num���� �޴��׸� �̵��� �� ���
int StdNum;  //�л����� �ѹ� �Է¹����� �ٲ��� �ʾƼ� ���������� �����ߴ�.

int main(void) {

	Student* SearchStudent = NULL;  //�л��ֳ� ã�� �� �� Student�� ������ �ʱ�ȭ
	cout.precision(2);
	cout << fixed;


	cout << "��ü �л� ���� �Է����ּ��� : ";    //�л����� �Է¹���
	InputValue(StdNum);                            //�л��� �Է�
	cout << "\n";

	struct Student* stu = NULL;
	stu = new Student[StdNum]; // �Է¹��� �� ��ŭ �л� �� ���� �Ҵ�


	while (1) {  //���� �ݺ���,4�� �Է��� �� ���� �ݺ�

		PrintMenu();  //�޴� ���,�ζ��� �Լ��� ����

		if (num == 1) {
			InputData(stu, StdNum);  //InputData�� ���� �� �л��� ������ �޴´�
		}

		else if (num == 2) {           //2�� �Է�������
			PrintAllData(stu, StdNum);   //��� �л����� ���
		}

		else if (num == 3) {     //3�� �Է�������
			//string search_StdName;
			//cout << "�˻� �� �л� �̸� : ";        //�˻��� �л� �̸� �Է¹޾Ƽ�
			//InputValue(search_StdName);                   //search.StdName�� ����

			SearchStudent = StdSearch(stu);        //StdSearch�Լ� �Ἥ ���ϰ��� SearchSudent�� ����Ű����

			if (SearchStudent != NULL) {    //SearchSudent�� ����Ű�°��� ������� ������
				cout << "\n";
				PrintOneData(*SearchStudent);   //SearchSudent�� ����Ű�°��� �ִ� ���� PrintOneData�Լ��� ������
			}
			else {                            //SearchSudent�� ����Ű�°��� ���������
				cout << "�ش� �л��� �����ϴ�.\n\n";    //�ش� �л� ���ٰ� ���
			}
		}

		else if (num == 4) {    //4�� �Է½�
			PrintAllStdList(stu, StdNum);   //�л����� �̸� �й� ������ ����ϴ� �Լ� ȣ��
		}


		else if (num == 5) {

			//SearchStudent = StdSearch(stu);       
			ModifyStdInfo(stu);   //���ϴ� ������ �Է¹޾� �����ϴ� �Լ� ȣ��
		
		}

		else {  //�ٸ� ��ȣ �Է½� �Ƹ� 6��
			for (int i = 0; i < StdNum; i++) {   //�л��� ��ŭ �ݺ��� �ݺ�
				if (stu[i].Sub != NULL) {   //�л��� �������� ������ ������� ������
					delete[] stu[i].Sub;   //���� ���ش�
				}
			}
			if (stu != NULL) {  //�л��� ��ŭ �Է¹��� �л��� �������� ���� ���¶��
				delete[] stu;   //�������ش�.
			}
			break;
		}
	};
}

inline void PrintMenu() {              //�޴� ����Լ�, �޴������ְ� ���ϴ� ��� �Է� ����, �ζ��� �Լ���
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
	InputValue(num);      //��� �������� �Է¹���
};

inline void InputValue(string &str) {     //�ζ����Լ�
	getline(cin, str);  //getline�� ���� string str �Է¹���
};


inline void InputValue(int& i) {          //�ζ����Լ�, ������ �Է¹��������
	cin >> i;
	cin.ignore();   //cin���� �Է¹��� �Ŀ��� cin.ignore�Ἥ ���� ��������
};

void CalcGPA(Subject& Sub) {  // ���� ��� �Լ�


	if (Sub.Grade=="A+") {         //A+->4.5�� ��ȯ
		Sub.GPA = Sub.Hakjum * 4.5;
	}
	else if (Sub.Grade=="A0") {        //A0->4.0�� ��ȯ
		Sub.GPA = Sub.Hakjum * 4.0;
	}
	else if (Sub.Grade=="B+") {         //B+->3.5�� ��ȯ
		Sub.GPA = Sub.Hakjum * 3.5;
	}
	else if (Sub.Grade=="B0") {         //B0->3.0�� ��ȯ
		Sub.GPA = Sub.Hakjum * 3.0;
	}
	else if (Sub.Grade=="C+") {           //C+->2.5�� ��ȯ
		Sub.GPA = Sub.Hakjum * 2.5;
	}
	else if (Sub.Grade=="C0") {             //C0->2.0�� ��ȯ
		Sub.GPA = Sub.Hakjum * 2.0;
	}
	else if (Sub.Grade=="D+") {              //D+->1.5�� ��ȯ
		Sub.GPA = Sub.Hakjum * 1.5;
	}
	else if (Sub.Grade=="D0") {             //D0->1.0�� ��ȯ
		Sub.GPA = Sub.Hakjum * 1.0;
	}
	else if (Sub.Grade=="F") {             //F->0�� ��ȯ
		Sub.GPA = Sub.Hakjum * 0.0;
	}
	else if (Sub.Grade=="a+") {
		Sub.GPA = Sub.Hakjum * 4.5;
	}
	else if (Sub.Grade=="a0") {            //�빮�ڿ� ���� ���
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

float CalcAveGPA(Subject* Sub, int SubNum) {      // ������ ���� ��� �Լ� ����
	float c = 0;   //���� ����
	float d = 0;
	float e = 0;
	for (int i = 0; i < SubNum; i++) {  //�������ŭ GPA���� ���Ѵ��� d�� ����
		d += Sub[i].GPA;
	}
	for (int j = 0; j < SubNum; j++) {  //������������ �ٴ��ؼ� e�� ����
		e += Sub[j].Hakjum;
	}

	c = d / e;   //GPA��/������ = ��ü �����̰� �̰� c�� �����Ѵ�.
	return c;
};

void PrintAllData(const Student* pSt, int StudentNum) {  // ��ü �л� ���� ��� �Լ�
	cout << "\n";
	cout << "         ��ü �л� ���� ����\n";               //��ü �л� ���� ���� ���
	cout.width(70); cout.fill('=');  cout << "\n";

	for (int i = 0; i < StudentNum; i++) {     //��ü �л� �� ��ŭ ���� ���
		PrintOneData(*(pSt + i));
	}
}

void PrintOneData(const Student& rSt) {   // ���� �л� ���� ��� �Լ�
	cout << "�̸� : " << rSt.StdName << "  �й� : " << rSt.Hakbun << "\n";  //�л� �й� ���
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "              �����  ��������  ������    �������� \n";           //�л� 3���� ���� ����� ���� ��� ���� ���
	cout.width(70); cout.fill('=');  cout << "\n";
	for (int j = 0; j < rSt.SubNum; j++) {
		cout << "              " << rSt.Sub[j].SubName << "      " << rSt.Sub[j].Hakjum << "           " << rSt.Sub[j].Grade << "        " << rSt.Sub[j].GPA << "\n";
	}
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "                               �������        " << rSt.AveGPA << "\n";   //�л� ������� ���
	cout << "\n";
};

Student* StdSearch(Student* pSt) {  // �л� �̸� �˻� �Լ�

	string searchName;
	cout << "�˻� �� �л� �̸� : ";        //�˻��� �л� �̸� �Է¹޾Ƽ�
	InputValue(searchName);

	for (int i = 0; i < StdNum; i++) {            //�л� �� ��ŭ ���鼭
		if ((pSt + i)->StdName == searchName) {     //���� �̸��� ã�»���̶� ���� �����������
			return pSt + i;    //�̸��� �������� �ּҸ� ����
		}
	}
	return NULL;  //�Է¹��� �̸��� ���ٸ� NULL����
};

Subject* SubSearch(const Student* pSt) {  //���� �˻� �Լ�
	string subName;  //�˻��� ����� string���� ����
	cout << "�˻� �� ���� �̸� : ";
	InputValue(subName);  //����� �˻� ����
	for (int i = 0; i < pSt->SubNum; i++) {   //�л��� �������ŭ �ݺ����� ���鼭
		if (pSt->Sub[i].SubName == subName) {    //������� �˻��� ����� ��ġ�ϴ°� ������
			return &pSt->Sub[i];	//����ü�� �ּ�(������ �����ּ�)�� ��ȯ�մϴ�  
		}
	}
	return NULL; //������ NULL ����
}


void PrintAllStdList(Student* pSt, int StudentNum) {  //��ü �л��� �й� �̸� ���
	cout.width(70); cout.fill('=');  cout << "\n";
	cout << "           �й�              �̸�\n";
	cout.width(70); cout.fill('=');  cout << "\n";

	for (int t = 0; t < StudentNum; t++) {
		cout << "           " << pSt[t].Hakbun << "                " << pSt[t].StdName << "\n";    //�ݺ����� �̿��Ͽ� �й� �̸��� ���
	}
	cout << "\n";
}

void ModifyStdInfo(Student* pSt) {  //������ �����ϴ� �Լ�

	Student* St = StdSearch(pSt);  //StdSearch(pSt)���� Student ������ St�� ����Ű����

	if (St != NULL) {  //���� �˻����� �л��� �����Ѵٸ�
		string Type="0";  //�л����� �������� �������� �������� �Է¹��� string�� Type����

		cout << "\n";
		cout << "����(�л�����/��������) : ";

		InputValue(Type);  //Type�Է¹���

		if (Type == "��������") {  //���� ���������� �����ҰŸ�

			Subject* Sub = SubSearch(St);  //SubSearch�� ���� ������ �Է¹ް� �ִ� �������� Ȯ��

			if (Sub == NULL) {  //���� ������ �Է��ϸ�
				cout << "����� �Է����ּ���.\n";  //����� �Է��ش޶�� ���
			}

			else {   //�ִ� �����̸�
				cout << "*< " << Sub->SubName << ", ���� : " << Sub->Hakjum << ", ��� : " << Sub->Grade << ">�� ������ �����ϼ���\n";  //���� ���� ������ְ�
				cout << "������� : ";

				InputValue(Sub->SubName);  //�̸� �ٲ���
				cout << "�������� : ";
				InputValue(Sub->Hakjum);  //�����ٲ���
				cout << "������ : ";
				InputValue(Sub->Grade);  //��� �ٲ���

				for (int a = 0; a < St->SubNum; a++) {  //�������ŭ �ݺ��ϸ� ���� ��ȯ
					CalcGPA(St->Sub[a]);
				}

				St->AveGPA = CalcAveGPA(St->Sub, St->SubNum);  //�������� �ٽð������
			}
		}
		else if (Type == "�л�����") {  //���� �л������� �����Ѵٰ� �Է�������
			cout << "*<" <<St->StdName<< ", " << St->Hakbun << ">�� ������ �����ϼ���\n";
			cout << "�̸� : ";
			
			InputValue(St->StdName);  //�̸��ٲ���
			cout << "�й� : ";
			InputValue(St->Hakbun);  //�й��ٲ���
		}
	}

	else {  //�̸��� �̻��ϰ� �Է��ϸ�
		cout << "�л��̸��� �ѹ� �� Ȯ�����ּ���!\n";  //Ȯ�ο䱸
	}

}

void InputData(Student* std, int StdNum) {   //��ü �л��� �Ż� ���� �� ���� ������ �Է¹޴� �Լ�

	for (int i = 0; i < StdNum; i++) {   //�л�����ŭ �ݺ����� ����

		cout << "*" << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";   //�̸��� �й��� �Է¹���
		// �̸� �Է�
		cout << "�̸� : ";
		
		InputValue((std+i)->StdName);   //�̸��� �Է¹���
		
		cout << "�й� : ";    // �й� �Է�
		InputValue((std + i)->Hakbun);   //�й��� �Է¹���

		cout << "��ü ���� ���� �Է����ּ��� : ";   //��ü ������� �Է� ���� . ������� �л����� �ٸ��⶧���� �����Ҵ��� ����� ����
		InputValue((std + i)->SubNum);    //������� �Է� ����
		cout << "\n";

		(std + i)->Sub = new Subject[(std + i)->SubNum];   //�Է¹��� �� ��ŭ ����� �����Ҵ�

		cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";

		for (int j = 0; j < std[i].SubNum; j++) {        //�л��� ���� �� ���� ���� ����
			cout << "������� : ";
			
			InputValue(std[i].Sub[j].SubName);     //������� ����
			cout << "����������(����) : ";
			InputValue(std[i].Sub[j].Hakjum);   //���� ������ ����
			
			cout << "������<A+ ~ F> : ";
			
			InputValue(std[i].Sub[j].Grade);    //���� ��� ����
			cout << '\n';
		}
		cout << "\n\n\n\n";
	}

	for (int a = 0; a < StdNum; a++) {    //�л��� ���� ���� ���
		for (int b = 0; b < std[a].SubNum; b++) {
			CalcGPA(std[a].Sub[b]);   //�������ŭ CalcGPA�Լ� ����
		}
	}

	for (int k = 0; k < StdNum; k++) {   //�л�����ŭ �ݺ�
		std[k].AveGPA = CalcAveGPA(std[k].Sub, std[k].SubNum);   // �л� ����������ϱ�
	}
}






