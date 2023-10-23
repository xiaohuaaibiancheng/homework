#include<iostream>
#include<cstdio>
using namespace std;
#define CHUNKSIZE 80

typedef struct SString
{
	char* data;
	int* next;
	int length;

}SString, * Sstring;

//初始化
void InitList(SString& s) {
	s.data = (char*)malloc(sizeof(char) * CHUNKSIZE);//C 申请一片连续的存储空间
	s.next = (int*)malloc(sizeof(int) * CHUNKSIZE);
}

void Creat_Ss(SString& s)
{
	int i = 1;
	s.data[0] = '~';

	while ((s.data[i] = getchar()) != '#')
	{
		i++;
	}
	s.length = i;
}
int n(SString S, SString T)
{
	int ipos = 0, flag = 0;
	int i = 1, j = 1;
	while (i < S.length && j < T.length)
	{
		if (S.data[i] == T.data[j] || T.data[j] == '?')
		{
			i++, j++;
		}
		else if (T.data[j] == '*')
		{
			if (T.data[j + 1] == '*')
			{
				j++;
			}
			ipos = j, flag = 1;
			if (T.data[j + 1] != S.data[i + 1] && T.data[j + 1] != '?')
			{
				i++;
			}
			else if (T.data[j + 1] == S.data[i + 1] || T.data[j + 1] == '?')
			{
				j++, i++;
			}
		}
		else if (S.data[i] != T.data[j] && T.data[j] != '*')
		{
			if (flag == 1)
			{
				j = ipos;
			}
			else
			{
				return 0;
			}
		}
	}

	if (j < T.length)
	{
		for (int k = j + 1; k < T.length; k++)
		{
			if (T.data[k] >= 'a' && T.data[k] <= 'z')
			{
				return 0;
			}
		}
		return 1;
	}
	else if (j == T.length)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*int LastNum(SString T)
{
	int flag = 0;
	for (int i = 1; i < T.length; i++)
	{
		flag = 0;
		if (T.data[i] == '*')
		{
			for (int j = i + 1; j < T.length; j++)
			{
				if (T.data[j] == '*')
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				return i;
			}

		}
	}
	return 0;
}*/

int main()
{
	SString S, T;
	InitList(S);
	InitList(T);
	Creat_Ss(T);
	(void)getchar();
	Creat_Ss(S);
	//int addr;
	//addr = LastNum(T);
	if (n(S, T))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}


	return 0;
}