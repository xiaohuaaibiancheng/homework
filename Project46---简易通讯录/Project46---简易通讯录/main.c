#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//#include "project.h"

#define NAMESIZE 50
#define ADDRESSSIZE 20
#define PHONESIZE 20

typedef struct PeopleContact        //������ϵ�˵Ĵ洢�ṹ
{
	int m_age;
	int m_sex;
	char m_name[NAMESIZE];
	char m_address[ADDRESSSIZE];
	char m_telephone[PHONESIZE];
	struct PeopleContact* next;
}PeopleContact;
typedef struct AddressBook          //��ϵ���Ĵ洢�ṹ
{
	PeopleContact* head;
	int m_size;
}AddressBook;

enum Choose                         //��ͬѡ��İ���
{
	EXIT,  //0
	ADD,   //1
	DEL,   //2
	SEARCH,//3
	MODIFY,//4
	SHOW,  //5
	Empty   //6
};


void Initaddress(struct AddressBook* p)       //��ʼ����ϵ��
{
	p->head = NULL;
	p->m_size = 0;
}

void Menu()                                    //�˵��Լ����Ĺ���
{
	printf("*********************************\n");
	printf("**      1. �����ϵ��          **\n");
	printf("**      2. ɾ����ϵ��          **\n");
	printf("**      3. ������ϵ��          **\n");
	printf("**      4. �޸���ϵ��          **\n");
	printf("**      5. ��ʾ������ϵ��      **\n");
	printf("**      6. ���ͨѶ¼          **\n");
	printf("**      0. exit                **\n");
	printf("*********************************\n");
}

void Add(AddressBook* p, PeopleContact* contact) //����ϵ�˵���Ϣ�������ϵ��
{
	contact= (PeopleContact*)malloc(sizeof(PeopleContact));  //Ϊ��ϵ�˷���ռ�
	if (contact == NULL) {
		printf("Memory allocation failed\n");

	}
		//����                                  //��ϵ�˵���Ϣ
		printf("����������\n");
		scanf("%s", &contact->m_name);
		//����

		printf("����������\n");
		scanf("%d", &contact->m_age);
		//�Ա�

		printf("�������Ա�\n");
		printf("1----��\n2----Ů\n");
		scanf("%d", &contact->m_sex);

		//�绰

		printf("������绰\n");
		scanf("%s", &contact->m_telephone);
		//סַ

		printf("������סַ\n");
		scanf("%s", &contact->m_address);
		contact->next=NULL;
		if(p->head==NULL)                            //Ϊ�ռ�����һ���ڵ㸳��ͷ�ڵ�
           {
               p->head=contact;
               p->m_size++;
           }

        else                                         //���򽫽ڵ�������
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
	void Delete(AddressBook* p)           //ɾ��ָ����ϵ��
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("��������Ҫɾ���˵�������\n");
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

         if(count==0)                   //�����Ա�̣���û�����򷵻���������
            printf("���޴���\n");
            else
            {
                int j=0;
                PeopleContact*m=p->head;
                for(j;j<i-1;j++)
                    m=m->next;
                m->next=contact->next;
                free(contact);
                p->m_size--;
                printf("ɾ���ɹ���");
            }

        system("pause");
        system("cls");

	}

	void Showperson(AddressBook* p)            //��ʾȫ����ϵ�˵���Ϣ
	{
	    PeopleContact* contact;
	    contact=p->head;
	    if(p->m_size==0)
            printf("��ǰ��¼Ϊ��,�������������\n");
        else{
                int i=0;
            for(i;i<p->m_size;i++)

        {
            //����
            printf("%s\t",contact->m_name);
            //�Ա�
            if(contact->m_sex==1)
            printf("��\t");
            else
                printf("Ů\t");
            printf("%d\t",contact->m_age);
            //�绰
            printf("%s\t\t",contact->m_telephone);
            //��ַ
            printf("%s\n",contact->m_address);
            contact=contact->next;
            printf("��ʾ���\n");
        }
        }
        system("pause");
        system("cls");
	}
	void Search(AddressBook* p)     //Ѱ��ָ���˵���Ϣ
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("��������Ҫ���ҵ���ϵ��\n");
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
            printf("���޴���\n");
        else
        {
	    int i=0;
	    for(i;i<p->m_size;i++)  //ѭ������
        {
            if(strcmp(str,contact->m_name)==0)
            break;
            contact=contact->next; //ָ����һ��
        }
            //����
            printf("%s\t",contact->m_name);
            //�Ա�
            if(contact->m_sex==1)
            printf("��\t");
            else
                printf("Ů\t");
            //����
            printf("%d\t",contact->m_age);
            //�绰
            printf("%s\t\t",contact->m_telephone);
            //��ַ
            printf("%s\n",contact->m_address);
            printf("��ʾ���\n");
            }
            system("pause");
            system("cls");

	}
	void Modify(AddressBook* p)  //�޸�ָ���˵���Ϣ
	{
	    PeopleContact* contact;
	    contact=p->head;
	    char str[NAMESIZE];
	    printf("��������Ҫ�޸ĵ���ϵ�ˣ�\n");
	    scanf("%s",str);
	    int i=0,count=0;
	    for(i;i<p->m_size;i++)        //ѭ������
        {
            if(strcmp(str, contact->m_name) == 0)
            {
                count=1;
                break;
            }

            contact=contact->next;
        }

         if(count==0)
            printf("���޴���\n");
            else
            {
                printf("�������޸ĺ��������\n");
                scanf("%s", &contact->m_name);
                printf("�������޸ĺ���Ա�\n1---��\n2---Ů\n");
                scanf("%d", &contact->m_sex);
                printf("�������޸ĺ�����䣺\n");
                scanf("%d", &contact->m_age);
                printf("�������޸ĺ�ĵ绰��\n");
                scanf("%s", &contact->m_telephone);
                printf("�������޸ĺ��סַ��\n");
                scanf("%s", &contact->m_address);
            }
            system("pause");
            system("cls");
	}
void empty(AddressBook* p)//�߼���գ�sizeΪ��   
{
    p->m_size=0;//����Ϊ��
    printf("ͨѶ¼�Ѿ����");
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
			printf("��������Ҫ���в�����ѡ�\n");
			scanf("%d", &input);
			switch (input)
			{
			case ADD://�����ϵ��
			{
				Add(&p, contact);
				printf("��ӳɹ�����������һ��ָ�\n");
				break;
			}
			case DEL://ɾ����ϵ��
			    Delete(&p);
			    break;
			case SEARCH://������ϵ��
			    Search(&p);
			    break;
			case MODIFY://�޸���ϵ��
			    Modify(&p);
			    break;
			case SHOW://��ʾ��ϵ��
            {
			    Showperson(&p);
			    break;
            }
			case Empty://���ͨѶ¼
			    empty(&p);
			    break;
			case EXIT://�˳�ͨѶ¼
			{
				system("cls");
				printf("�˳��ɹ�\n");
				break;
			}
			default:
				system("cls");
				printf("����û�����ѡ��Ŷ������ϸ������������롣\n");
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
