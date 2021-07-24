#pragma once
#include "Stu.h"

class StudentManage {
public:
	StudentManage() {}

	Student AddAStu(map<int, Student>& mp, Student & stu) {
		mp[stu.GetStuId()] = stu;
		return stu;
	}

	bool DeleteStuById(map<int, Student>& mp, const int & id) {
		if (mp.find(id) != mp.end()) {
			mp.erase(id);
			return true;
		}
		return false;
	}

	Student UpdateStu(map<int, Student>& mp, const Student & stu) {
		Student stu1;
		if (mp.find(stu.GetStuId()) != mp.end()) {
			mp[stu.GetStuId()] = stu;
			stu1 = stu;
		}
		return stu1;
	}

	Student FindStuById(const map<int, Student>& mp, const int &id) const {
		Student stu;
		map<int, Student> ::const_iterator iter = mp.find(id);
		if (iter != mp.end()) stu = iter->second;
		return stu;
	}

	void ShowAllInfo(const map<int, Student>& mp) const {
		for (auto m : mp) cout << m.second << endl;
	}

	bool SaveToFile(const map<int, Student>& mp, const string & path) const {
		bool flag = true;
		fstream ofs(path, ios::out);
		if (ofs) {
			stringstream ss;
			cout << "文件打开" << endl;
			for (auto m : mp) ss << m.second << endl;
			ofs << ss.str(); // 注意，输出一定是 ss.str();
			ofs.close();
		}
		else
		{
			cout << "文件打开失败" << endl;
			flag = false;
		}
		return flag;
	}

	bool ReadFromFile(map<int, Student>& mp, string path) {
		bool flag = true;
		mp.clear();
		fstream ifs(path, ios::in);
		if (ifs) {
			cout << "文件打开" << endl;
			string s;
			stringstream ss;
			while (getline(ifs, s)) {// 怎么一行行地读取？
				Student Stu;
				ss << s;
				// cout<<ss.str();
				ss >> Stu;
				ss.clear();
				mp[Stu.GetStuId()] = Stu;
			}
			ifs.close();
		}
		else {
			cout << "文件打开失败" << endl;
			flag = false;
		}
		return flag;
	}
};