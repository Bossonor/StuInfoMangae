#pragma once
#include "StuMg.h"

class MainView {
public:
	MainView() {}

	/* 欢迎 */
	void Welcome() {
		system("cls");
		cout << "欢迎来到学生信息管理系统" << endl;
	}

	/* 显示菜单 */
	void ShowMenu() {
		cout << "\n操作步骤" << endl;
		cout << "1. 录入" << endl;
		cout << "2. 修改" << endl;
		cout << "3. 查找" << endl;
		cout << "4. 删除" << endl;
		cout << "5. 显示所有" << endl;
		cout << "6. 保存至文件" << endl;
		cout << "7. 从文件导入" << endl;
		cout << "0. 退出\n" << endl;
		cout << "请选择操作：";
	}

	/* view 显示所有学生 */
	void ShowAllStuAtView(const map<int, Student>& mp) {
		system("cls");
		cout << "|   id    " << "|   name   " << "|   age   |" << endl;
		StudentManage StuMg;
		StuMg.ShowAllInfo(mp);

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 添加一个学生 */
	void AddAStuAtView(map<int, Student>& mp) {
		StudentManage StuMg;
		int id, age;
		string name;
		Student Stu;

		system("cls");
		cout << "录入" << endl;
		cout << "ID:";
		cin >> id;
		cout << "Name:";
		cin >> name;
		cout << "Age:";
		cin >> age;

		Stu.SetStuId(id);
		Stu.SetStuName(name);
		Stu.SetStuAge(age);
		StuMg.AddAStu(mp, Stu);

		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 查找一个学生 */
	void FindAStuAtView(const map<int, Student>& mp) {
		system("cls");
		cout << "请输入要查找学生的ID" << endl;
		int id;
		cin >> id;

		StudentManage StuMg;
		Student Stu;
		Stu = StuMg.FindStuById(mp, id);

		if (Stu.GetStuId() != -1) cout << Stu << endl;
		else cout << "查无此人" << endl;

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 删除一个学生 */
	void DeleteByIdAtView(map<int, Student>& mp) {
		system("cls");
		cout << "请输入要删除的学生的ID" << endl;
		int id;
		cin >> id;

		StudentManage StuMg;
		bool flag = StuMg.DeleteStuById(mp, id);
		if (flag) cout << "删除成功" << endl;
		else cout << "查无此人" << endl;

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 更新一个学生 */
	void UpdateByIdAtView(map<int, Student>& mp) {
		system("cls");
		cout << "请输入要修改的学生的ID" << endl;
		int id, age;
		cin >> id;
		string name;
		cout << "Name:";
		cin >> name;
		cout << "Age";
		cin >> age;

		Student Stu, Stu2;
		Stu.SetStuId(id);
		Stu.SetStuName(name);
		Stu.SetStuAge(age);

		StudentManage StuMg;
		Stu2 = StuMg.UpdateStu(mp, Stu);
		if (Stu2.GetStuId() != -1) {
			cout << Stu2 << endl;
			cout << "修改成功" << endl;
		}
		else cout << "查无此人" << endl;

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 保存进文件 */
	void SaveToFileAtView(const map<int, Student>& mp, string path) {
		if (mp.begin() == mp.end()) {
			system("cls");
			cout << "还没有任何学生信息，无法保存" << endl;
		}
		else {
			StudentManage StuMg;
			bool flag = StuMg.SaveToFile(mp, path);
			if (flag) {
				system("cls");
				cout << "保存成功" << endl;
			}
			else cout << "保存失败" << endl;
		}

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}

	/* view 把文件中的东西导入*/
	void ReadFromFileAtView(map<int, Student>& mp, string path) {
		system("cls");
		StudentManage StuMg;
		bool flag = StuMg.ReadFromFile(mp, path);
		if (flag) cout << "读取成功" << endl;
		else cout << "读取失败" << endl;

		system("pause");
		system("cls");
		Welcome();
		ShowMenu();
	}
};