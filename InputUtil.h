#ifndef INPUTUTIL_H   //����� �ߺ��� ���� ���� ��
#define INPUTUTIL_H

class InputUtil {  //����ڷκ��� �Է� �޴� �� ���� Class

public:
	static void InputValue(int& i) {  //int �Է¹޴� �Լ�
		
		while (1) {     //���� �ݺ�
			cin >> i;  //int�� i �Է¹���

			if (cin.fail()) {  //cin.fail �� ������ �ƴ� ���� ������
				cin.clear();    //�����
				cin.ignore(255,'\n');   //���۸� ����ش�
				cout << "������ �Է����ּ��� : ";   //������ �Է��ش޶�� ��û
			}

			else {  //���� ������ �Է��� ��������
				cin.ignore();   //���۸� ����ְ�
				break;       //�ݺ��� Ż��
			}

		}
	}

	static void InputValue(string& str) {  //string �Է� �޴� �Լ�
		while (1) {        //���� �ݺ�
			getline(cin, str);  //getline�� ���� string str �Է¹���
			if (cin.fail()) {    //cin.fail �� ������ �ƴ� ���� ������
				cin.clear();       //�����
				cin.ignore(255, '\n');    //���۸� ����ش�
				cout << "���ڿ��� �Է����ּ��� : ";   //���ڿ��� �Է��ش޶�� ��û
			}
			else {   //���� string���� �Է��� ��������
				break;  //�ݺ��� Ż��
			}
		}
	
	}

	static void InputValue(char *c) {  //char�� �Է� �޴� �Լ�
		while (1) {    //���� �ݺ�
			cin >> c;  //char�� c�Է� ����
			if (cin.fail()) {    //cin.fail �� char���� �ƴ� ���� ������
				cin.clear();      //�����
				cin.ignore(255, '\n');  //���۸� ����ش�
				cout << "���ڷ� �Է����ּ��� : ";  //���ڷ� �Է��ش޶�� ��û
			}

			else {  //���� char������ ��������
				cin.ignore();  //���۸� ����ش�
				break;   //�ݺ��� Ż��
			}

		}
	}
	static void InputValue(float &f) {  //float������ �Է� �޴� �Լ�
		while (1) {   //���� �ݺ�
			cin >> f;  //float�� f �Է� ����
			if (cin.fail()) { //cin.fail �� float���� �ƴ� ���� ������
				cin.clear();    // �����
				cin.ignore(255, '\n');   // ���۸� ����ش�
				cout << "�Ǽ��� �Է����ּ��� : ";  //�Ǽ��� �Է��ش޶�� ��û
			}

			else {   //���� float������ ��������
				cin.ignore();  //���۸� ����ش�
				break;   //�ݺ��� Ż��
			}

		}
	}

	static void InputValue(double &d) {    //double������ �Է� �޴� �Լ�
		while (1) {   //���� �ݺ�
			cin >> d;  //double�� d �Է¹���
			if (cin.fail()) { //cin.fail �� double���� �ƴ� ���� ������
				cin.clear();   // �����
				cin.ignore(255, '\n');  // ���۸� ����ش�
				cout << "�Ǽ��� �Է����ּ��� : ";  //�Ǽ��� �Է��ش޶�� ��û
			}
			else {  //���� double������ ��������
				cin.ignore();  //���۸� ����ش�
				break;  //�ݺ��� Ż��
			}

		}
	}

};

#endif // !INPUTUTIL_H
