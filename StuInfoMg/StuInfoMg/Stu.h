#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

class Student {
	friend ostream & operator<<(ostream & os, Student & stu) {
		os << "   " << stu.GetStuId() << "        " << stu.GetStuName() << "        " << stu.GetStuAge();
		return os;
	};
	friend istream & operator>>(istream & is, Student & stu) {
		is >> stu.StuId >> stu.StuName >> stu.StuAge;
		return is;
	};

public:
	Student() { StuId = -1; }

	int GetStuId() const { return StuId; }
	void SetStuId(int val) { StuId = val; }

	string GetStuName() const { return StuName; }
	void SetStuName(string val) { StuName = val; }

	int GetStuAge() const { return StuAge; }
	void SetStuAge(int val) { StuAge = val; }

private:
	int StuId;
	string StuName;
	int StuAge;
};