#pragma once
#include<iostream>
#include<string>
using namespace std;

//Ա��������������Ϊ����
class Worker
{
public:
	//��ȡ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_name;//ְ������
	int m_DeptId;//ְ�����ڲ��ű��

};