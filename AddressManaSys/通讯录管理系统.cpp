#include <iostream>
#include <string>

using namespace std;
#define MAX 1000

void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
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
		cout << "通讯录已满，无法继续添加！" << endl;
		return;
	}
	else {
		cout << "请输入要添加的联系人姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1. 男性 \t 2. 女性" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入：" << endl;
				cout << "1. 男性 \t 2. 女性" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		abs->m_size += 1;

		cout << "添加联系人成功！" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs) {
	if (abs->m_size == 0) {
		cout << "当前通讯录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "联系电话：" << abs->personArray[i].m_phone << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_address << endl;

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
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		for (int i = res; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size -= 1;
		cout << "联系人删除成功！" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs) {
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		cout << "姓名：" << abs->personArray[res].m_name << "\t";
		cout << "性别：" << (abs->personArray[res].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[res].m_age << "\t";
		cout << "联系电话：" << abs->personArray[res].m_phone << "\t";
		cout << "家庭住址：" << abs->personArray[res].m_address << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs) {
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;

	int res = isExit(abs, name);
	if (res == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		cout << "请输入修改后的姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[res].m_name = name;

		cout << "请输入修改后的性别：" << endl;
		cout << "1. 男性 \t 2. 女性" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[res].m_sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入：" << endl;
				cout << "1. 男性 \t 2. 女性" << endl;
			}
		}

		cout << "请输入修改后的年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[res].m_age = age;

		cout << "请输入修改后的联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[res].m_phone = phone;

		cout << "请输入修改后的家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[res].m_address = address;

		cout << "修改联系人成功！" << endl;
		system("pause");
		system("cls");
	}
}

void cleanPerson(AddressBook* abs) {
	cout << "确定要清空全部联系人吗？" << endl;
	cout << "1. 确定 \t 2. 取消" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select == 1) {
			abs->m_size = 0;
			cout << "全部联系人已清空！" << endl;
			break;
		}
		else if (select == 2) {
			break;
		}
		else {
			cout << "输入有误，请重新输入：" << endl;
			cout << "1. 确定 \t 2. 取消" << endl;
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
			cout << "欢迎下次使用..." << endl;
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