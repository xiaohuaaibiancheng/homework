#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//#include "project.h"

#define NAMESIZE 50
#define ADDRESSSIZE 20
#define PHONESIZE 20

typedef struct PeopleContact        //定义联系人的存储结构
{
	int m_age;
	int m_sex;
	char m_name[NAMESIZE];
	char m_address[ADDRESSSIZE];
	char m_telephone[PHONESIZE];
	struct PeopleContact* next;
}PeopleContact;
typedef struct AddressBook          //联系薄的存储结构
{
	PeopleContact* head;
	int m_size;
}AddressBook;

enum Choose                         //不同选项的按键
{
	EXIT,  //0
	ADD,   //1
	DEL,   //2
	SEARCH,//3
	MODIFY,//4
	SHOW,  //5
	Empty   //6
};


void Initaddress(struct AddressBook* p)       //初始化联系薄
{
	p->head = NULL;
	p->m_size = 0;
}

void Menu()                                    //菜单以及他的功能
{
	printf("*********************************\n");
	printf("**      1. 添加联系人          **\n");
	printf("**      2. 删除联系人          **\n");
	printf("**      3. 查找联系人          **\n");
	printf("**      4. 修改联系人          **\n");
	printf("**      5. 显示所有联系人      **\n");
	printf("**      6. 清空通讯录          **\n");
	printf("**      0. exit                **\n");
	printf("*********************************\n");
}

void Add(AddressBook* p, PeopleContact* contact) //将联系人的信息添加至联系薄
{
	contact= (PeopleContact*)malloc(sizeof(PeopleContact));  //为联系人分配空间
	if (contact == NULL) {
		printf("Memory allocation failed\n");

	}
		//姓名                                  //联系人的信息
		printf("请输入姓名\n");
		scanf("%s", &contact->m_name);
		//年龄

		printf("请输入年龄\n");
		scanf("%d", &contact->m_age);
		//性别

		printf("请输入性别\n");
		printf("1----男\n2----女\n");
		scanf("%d", &contact->m_sex);

		//电话

		printf("请输入电话\n");
		scanf("%s", &contact->m_telephone);
		//住址

		printf("请输入住址\n");
		scanf("%s", &contact->m_address);
		contact->next=NULL;
		if(p->head==NULL)                            //为空即将第一个节点赋给头节点
           {
               p->head=contact;
               p->m_size++;
           }

        else                                         //否则将节点插入后面
        {
            PeopleContact*current=p;
        while(current->next!=NULL)
        current=current->next;
        current->next=contact;
		
		/*p->head=contact->next;
		p->head=contact;*/

		p->m_size++;
        }
		system("pause");
            system("cls");
	}
	void Delete(AddressBook* p)           //删除指定联系人
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("请输入你要删除人的姓名：\n");
	    scanf("%s",str);
	    int i=0,count=0;
	    for(i;i<p->m_size;i++)
        {
            if(strcmp(str, contact->m_name) == 0)
            {
                count=1;
                break;
            }

            contact=contact->next;
        }

         if(count==0)                   //防御性编程，若没有人则返回重新输入
            printf("查无此人\n");
            else
            {
                int j=0;
                PeopleContact*m=p->head;
                for(j;j<i-1;j++)
                    m=m->next;
                m->next=contact->next;
                free(contact);
                p->m_size--;
                printf("删除成功！");
            }

        system("pause");
        system("cls");

	}

	void Showperson(AddressBook* p)            //显示全部联系人的信息
	{
	    PeopleContact* contact;
	    contact=p->head;
	    if(p->m_size==0)
            printf("当前记录为空,请进行其他操作\n");
        else{
                int i=0;
            for(i;i<p->m_size;i++)

        {
            //名字
            printf("%s\t",contact->m_name);
            //性别
            if(contact->m_sex==1)
            printf("男\t");
            else
                printf("女\t");
            printf("%d\t",contact->m_age);
            //电话
            printf("%s\t\t",contact->m_telephone);
            //地址
            printf("%s\n",contact->m_address);
            contact=contact->next;
            printf("显示完毕\n");
        }
        }
        system("pause");
        system("cls");
	}
	void Search(AddressBook* p)     //寻找指定人的信息
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("请输入您要查找的联系人\n");
	    scanf("%s",str);
	    int i=0,count=0;
	    for(i;i<p->m_size;i++)
        {
            if(strcmp(str, contact->m_name) == 0)
            {
                count=1;
                break;
            }

            contact=contact->next;
        }

        if(count==0)
            printf("查无此人\n");
        else
        {
	    int i=0;
	    for(i;i<p->m_size;i++)  //循环遍历
        {
            if(strcmp(str,contact->m_name)==0)
            break;
            contact=contact->next; //指向下一个
        }
            //名字
            printf("%s\t",contact->m_name);
            //性别
            if(contact->m_sex==1)
            printf("男\t");
            else
                printf("女\t");
            //年龄
            printf("%d\t",contact->m_age);
            //电话
            printf("%s\t\t",contact->m_telephone);
            //地址
            printf("%s\n",contact->m_address);
            printf("显示完毕\n");
            }
            system("pause");
            system("cls");

	}
	void Modify(AddressBook* p)  //修改指定人的信息
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("请输入需要修改的联系人：\n");
	    scanf("%s",str);
	    int i=0,count=0;
	    for(i;i<p->m_size;i++)        //循环遍历
        {
            if(strcmp(str, contact->m_name) == 0)
            {
                count=1;
                break;
            }

            contact=contact->next;
        }

         if(count==0)
            printf("查无此人\n");
            else
            {
                printf("请输入修改后的姓名：\n");
                scanf("%s", &contact->m_name);
                printf("请输入修改后的性别：\n1---男\n2---女\n");
                scanf("%d", &contact->m_sex);
                printf("请输入修改后的年龄：\n");
                scanf("%d", &contact->m_age);
                printf("请输入修改后的电话：\n");
                scanf("%s", &contact->m_telephone);
                printf("请输入修改后的住址：\n");
                scanf("%s", &contact->m_address);
            }
            system("pause");
            system("cls");
	}
void empty(AddressBook* p)//逻辑清空，size为零   
{
    p->m_size=0;//人数为零
    printf("通讯录已经清空");
    system("pause");
    system("cls");
}
	int main(void)
	{
		int input = 0;
		struct AddressBook p;
		Initaddress(&p);
		PeopleContact* contact = NULL;
		do
		{
			Menu();
			printf("请输入需要进行操作的选项：\n");
			scanf("%d", &input);
			switch (input)
			{
			case ADD://添加联系人
			{
				Add(&p, contact);
				printf("添加成功！请输入下一个指令。\n");
				break;
			}
			case DEL://删除联系人
			    Delete(&p);
			    break;
			case SEARCH://查找联系人
			    Search(&p);
			    break;
			case MODIFY://修改联系人
			    Modify(&p);
			    break;
			case SHOW://显示联系人
            {
			    Showperson(&p);
			    break;
            }
			case Empty://清空通讯录
			    empty(&p);
			    break;
			case EXIT://退出通讯录
			{
				system("cls");
				printf("退出成功\n");
				break;
			}
			default:
				system("cls");
				printf("我们没有这个选项哦！请仔细看清后重新输入。\n");
				break;

			}

			/*if (contact != NULL) {
				free(contact);
				contact = NULL;
			}*/

		} while (input != EXIT);
		system("pause");
		return 0;
	}
