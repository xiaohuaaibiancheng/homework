#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
	return string("�ܲ�");
}