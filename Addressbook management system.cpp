#include <iostream>
#include <string>
#include <fstream>
#define MAX 1000
using namespace std;
struct person {
	string name;//姓名
	int age;//年龄
	int sex;//性别 1 男 2 女
	string phonenumber;//电话号码
	string address;//家庭住址
};
struct AddressBook {
	struct person personArray[MAX];//通讯录中的人
	int size;//通讯录里当前人数  
};

//保存数据到文件
void saveFile(AddressBook* abs) {
	ofstream savefile("AddressBook.txt", ios::out); {
		for (int i = 0;i < abs->size;i++) {
			savefile << abs->personArray[i].name << " ";
			savefile << abs->personArray[i].age << " ";
			savefile << abs->personArray[i].sex << " ";
			savefile << abs->personArray[i].phonenumber << " ";
			savefile << abs->personArray[i].address << endl;;
			
		}
	}
	savefile.close();
}
//从文件读取数据
void loadFile(AddressBook* abs) {
	ifstream loadfile("AddressBook.txt", ios::in);
	if (!loadfile.is_open())return;
	else {
		string name;
		string phonenumber;
		string address;
		int sex;
		int age;
		while (loadfile >> name >> age >> sex >> phonenumber >> address) {
			abs->personArray[abs->size].name = name;
			abs->personArray[abs->size].age=age;
			abs->personArray[abs->size].sex=sex;
			abs->personArray[abs->size].phonenumber=phonenumber;
			abs->personArray[abs->size].address=address;
			abs->size++;
		}
	}
	loadfile.close();
}
//查联系人
int check(AddressBook* abs, string name) {
	for (int i = 0;i < abs->size;i++) {
		if (abs->personArray[i].name == name)return i;
		
		}
	return -1;
}
//查找联系人 
void findperson(AddressBook* abs, int ret) {
	if (ret == -1)cout << "根本没有这个人" << endl;
	else {
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男":"女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phonenumber << "\t";
		cout << "家庭住址：" << abs->personArray[ret].address << endl;
	}
	system("pause");
	system("cls");
}

//删除联系人
void deleteperson(AddressBook*abs,int ret) {
	if (ret == -1)cout << "根本没有这个人" << endl;
	else {
		for (int i = ret ;i < abs->size - 1;i++) {
			abs->personArray[i] = abs->personArray[i + 1];
        }
		abs->size--;
		cout << "删除联系人成功!" << endl;
	}
}
void addperson(AddressBook* abs) {
	if (abs->size > MAX) {
		cout << "通讯录已满！"<<endl;
	}
	else {
		//name
		string name1;
		cout << "请输入联系人姓名;" << endl;
		cin >> name1;
		abs->personArray[abs->size].name = name1;
		//age
		int age1;
		cout << "请输入联系人年龄;" << endl;
		cin >> age1;
		abs->personArray[abs->size].age = age1;
		//sex
		cout << "请输入联系人姓别;" << endl;
		cout << "1-------------男" << endl;
		cout << "2-------------女" << endl;
		int sex1= 0;
		cin >> sex1;
		while (sex1 != 1 && sex1 != 2) {
			cout << "请输入正确的性别！" << endl;
			cin >> sex1;
		}
		abs->personArray[abs->size].sex = sex1;
		//phonenumber
		cout << "请输入电话号码:" << endl;
		string n1;
		cin >> n1;
		abs->personArray[abs->size].phonenumber = n1;
		//家庭住址
		cout << "请输入家庭住址:" << endl;
		string z1;
		cin >> z1;
		abs->personArray[abs->size].address = z1;
		abs->size++;
		cout << "添加联系人成功!" << endl;
		system("pause");
		system("cls");
	}
}
//修改联系人
void changeperson(AddressBook* abs, int ret) {
	if (ret == -1)cout << "根本没有这个人" << endl;
	else {
		cout << "请修改联系人姓名;" << endl;
		
		cin >> abs->personArray[ret].name;
		//age
		
		cout << "请修改联系人年龄;" << endl;
		cin >> abs->personArray[ret].age;
		
		//sex
		cout << "请修改联系人姓别;" << endl;
		cout << "1-------------男" << endl;
		cout << "2-------------女" << endl;
		
		cin >> abs->personArray[ret].sex;
		while (abs->personArray[ret].sex != 1 && abs->personArray[ret].sex != 2) {
			cout << "请输入正确的性别！" << endl;
			cin >> abs->personArray[ret].sex;
		}
		
		//phonenumber
		cout << "请修改电话号码:" << endl;
		string n1;
		cin>> abs->personArray[ret].phonenumber;
		
		//家庭住址
		cout << "请修改家庭住址:" << endl;
		string z1;
		cin>> abs->personArray[ret].address;
		
		
		cout << "修改联系人成功!" << endl;
		
	}
	system("pause");
	system("cls");
}
//显示联系人
void showperson(AddressBook* abs) {
	if (abs->size == 0) {
		cout << "没有联系人" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++) {
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phonenumber << "\t";
			cout << "家庭住址：" << abs->personArray[i].address << endl;
		}
		
	}
    system("pause");
	system("cls");
}
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1，添加联系人 *****" << endl;
	cout << "***** 2，显示联系人 *****" << endl;
	cout << "***** 3，删除联系人 *****" << endl;
	cout << "***** 4，查找联系人 *****" << endl;
	cout << "***** 5，修改联系人 *****" << endl;
	cout << "***** 6，清空联系人 *****" << endl;
	cout << "***** 0，退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}
//清空联系人
void cleanperson(AddressBook* abs) {
	abs->size = 0;
	cout << "清空联系人成功!" << endl;
	system("pause");
	system("cls");
}
int main() {
	AddressBook abs;
	abs.size = 0;
	loadFile(&abs);
	while (true) {
		showMenu();
		int select;
		cin >> select;
		
		switch (select) {
		case 1://1，添加联系人
			addperson(&abs);
			break;
		case 2://2，显示联系人 
			showperson(&abs);
			break;
		case 3://3，删除联系人
		{
			string name;
			cout << "请输入您要删除的联系人姓名:";
			cin >> name;
			int ret = check(&abs, name);
			deleteperson(&abs, ret);
			system("pause");
			system("cls");
		}
			break;
		case 4://4，查找联系人
		{
			string name;
			cout << "请输入您要查找的联系人姓名:" << endl;
			cin >> name;
			int ret = check(&abs, name);
			findperson(&abs, ret);
		}
			break;
		case 5://5，修改联系人
		{
			cout << "请输入你要修改的联系人姓名 ：";
			string name;
			cin >> name;
			int ret = check(&abs, name);
			changeperson(&abs, ret);
		}
			break;
		case 6://6，清空联系人
		{
			cout << "您确定要清空所有联系人吗？" << endl;
			cout << "1---------------------是" << endl;
			cout << "2---------------------否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)cleanperson(&abs);
			else {
				system("pause");
				system("cls");
			}
		}
			break;
		case 0://0，退出通讯录
			saveFile(&abs);
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		
	}
	
}
