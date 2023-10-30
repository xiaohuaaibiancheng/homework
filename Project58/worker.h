#pragma once
#include<iostream>
#include<string>
using namespace std;

//员工抽象类用来作为父类
class Worker
{
public:
	//获取个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id;//职工编号
	string m_name;//职工姓名
	int m_DeptId;//职工所在部门编号

};