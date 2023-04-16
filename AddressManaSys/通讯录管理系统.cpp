#include <iostream>
#include <string>

using namespace std;
#define MAX 1000

void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

struct Person {
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_address;
};

struct AddressBook {
	struct Person personArray[MAX];
	int m_size;
};

void addPerson(AddressBook* abs) {
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷�������ӣ�" << endl;
		return;
	}
	else {
		cout << "������Ҫ��ӵ���ϵ��������" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1. ���� \t 2. Ů��" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else {
				cout << "�����������������룺" << endl;
				cout << "1. ���� \t 2. Ů��" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		abs->m_size += 1;

		cout << "�����ϵ�˳ɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs) {
	if (abs->m_size == 0) {
		cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "��ϵ�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "��ͥסַ��" << abs->personArray[i].m_address << endl;

		}
	}

	system("pause");
	system("cls");
}

int isExit(AddressBook* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
	
}

void deletePerson(AddressBook* abs) {
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		for (int i = res; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size -= 1;
		cout << "��ϵ��ɾ���ɹ���" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs) {
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		cout << "������" << abs->personArray[res].m_name << "\t";
		cout << "�Ա�" << (abs->personArray[res].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[res].m_age << "\t";
		cout << "��ϵ�绰��" << abs->personArray[res].m_phone << "\t";
		cout << "��ͥסַ��" << abs->personArray[res].m_address << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs) {
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		cout << "�������޸ĺ��������" << endl;
		string name;
		cin >> name;
		abs->personArray[res].m_name = name;

		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1. ���� \t 2. Ů��" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[res].m_sex = sex;
				break;
			}
			else {
				cout << "�����������������룺" << endl;
				cout << "1. ���� \t 2. Ů��" << endl;
			}
		}

		cout << "�������޸ĺ�����䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[res].m_age = age;

		cout << "�������޸ĺ����ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[res].m_phone = phone;

		cout << "�������޸ĺ�ļ�ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[res].m_address = address;

		cout << "�޸���ϵ�˳ɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void cleanPerson(AddressBook* abs) {
	cout << "ȷ��Ҫ���ȫ����ϵ����" << endl;
	cout << "1. ȷ�� \t 2. ȡ��" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select == 1) {
			abs->m_size = 0;
			cout << "ȫ����ϵ������գ�" << endl;
			break;
		}
		else if (select == 2) {
			break;
		}
		else {
			cout << "�����������������룺" << endl;
			cout << "1. ȷ�� \t 2. ȡ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

int main() {
	int select = 0;

	AddressBook abs;
	abs.m_size = 0;

	while (true) {
		showMenu();
		cin >> select;

		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��..." << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}