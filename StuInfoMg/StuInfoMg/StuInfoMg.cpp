// StuInfoMg.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "View.h"

int main()
{
	string path = "c:/Users/53261/Desktop/student_management.txt";
	map<int, Student> Stu_Mp;
	MainView Viewer;
	Viewer.Welcome();
	Viewer.ShowMenu();

	string OperateType;
	cin >> OperateType;

	while (OperateType != "0") {
		if (OperateType == "1") Viewer.AddAStuAtView(Stu_Mp); // 录入
		else if (OperateType == "2") Viewer.UpdateByIdAtView(Stu_Mp); // 修改
		else if (OperateType == "3") Viewer.FindAStuAtView(Stu_Mp); // 查找
		else if (OperateType == "4") Viewer.DeleteByIdAtView(Stu_Mp); // 删除
		else if (OperateType == "5") Viewer.ShowAllStuAtView(Stu_Mp); // 显示所有
		else if (OperateType == "6") Viewer.SaveToFileAtView(Stu_Mp, path); // 保存至文件
		else if (OperateType == "7") Viewer.ReadFromFileAtView(Stu_Mp, path); // 从文件读取
		else {
			Viewer.Welcome();
			Viewer.ShowMenu();
		}
		cin >> OperateType;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
