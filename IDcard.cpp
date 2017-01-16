 #include "c1.h"

typedef struct Record 
{
	int Month;
	int Day;
	float Cost;
	char Food[20];
	char Place[10];
}ElemType;
float money=0;

typedef struct
{
	char User_Name[10];
	char Code[10];
}User;


#include "c2-1.h"
#include "bo2-1.c"

int Login(User c[])
{
	int i,flag=1;
	char x[10],y[10],temp[10];
	while(flag)
	{
		puts("�������û���:"); 
		scanf("%s",&x);
		for(i=0;i<5;i++)
		{if(strcmp(c[i].User_Name,x)==0) 
		strcpy(temp,c[i].Code); 
		}
		puts("����������:");   
		scanf("%s",&y);	
		if(strcmp(y,temp)==0)
		flag=0;	
		else puts("�û������������!����������\n");
	}
	 return 1;
}

void ShowMessages()
{
	printf("\n$$$$$$$$$$$$$$$$$$$$$");
	printf("\n��ѡ������Ҫ�Ĳ���:");
	printf("\n1:��Ӽ�¼");
	printf("\n2:��ѯ���Ѽ�¼");
	printf("\n3:һ��ͨ��ֵ");
	printf("\n4:���ѹ���(ά����)");
	printf("\n5:�޸�����");
	printf("\n0:�˳�ϵͳ!\n");
}

void AddRecord(SqList_Records *L)
{
	ElemType e;
	printf("\n�������������Ѽ�¼\n---------------\n");
	puts("�������ڣ��£�:");  scanf("%d",&(e.Month));
	puts("�������ڣ��գ�:");  scanf("%d",&(e.Day));
	puts("���ѽ��:");        scanf("%f",&(e.Cost)); money-=(e.Cost);
	puts("������Ŀ:");        
	scanf("%s",&(e.Food));
	puts("���ѵص�:");        
	scanf("%s",&(e.Place));
	printf("\n---------------\n");
	ListInsert_Records(L,ListLength_Records(*L)+1,e);
	printf("��ӳɹ�\n");	
}

void PrintRecord(ElemType e)
{ 
	printf("   %2d��%2d��",e.Month,e.Day);
	printf("    %-6.2f      ",e.Cost);
	printf("%-6s        ",(e.Food));
	printf("%-6s",(e.Place));
	printf("\n");
}

void Deposit(float x)
{
	float a;
	printf("\n�������ֵ���:");
	scanf("%f",&a);
	while(a<0)
	{
		printf("\n������Ľ���ȷ������������:"); 
		scanf("%f",&a);
	}
	money+=a;
	printf("\n��ֵ�ɹ�!\n����ǰ���Ϊ:%.2f\n",money);
}

void ChangeCode(User c[],int i)
{
	char a[10];
	puts("\n������ԭ����:");
	gets(a);
	if(strcmp(a,c[i].Code)==0)
	{
		puts("����������:");
		scanf("%s",&(c[i].Code));
		puts("�޸ĳɹ�!\n");
	}
	else
		puts("�������,�޸�ʧ��!");
}
	   


void main()
 {
	SqList_Records L;
	ElemType e;
	int a,flag;
	User c[5]={{"1","a"}};
	InitList_Records(&L);
	puts("����������ӭʹ��һ��ͨ����ϵͳ��������\n\n");
	flag=Login(c);
	if(!flag);
	while(1)
	{		 
		ShowMessages();
		printf("��ѡ����:\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a)
		{
		case 0:
			DestroyList_Records(&L);
			exit(0);
			break;
		case 1:
			AddRecord(&L);
			break;
		case 2:
			if(!ListLength_Records(L))
			{printf("\n��ǰû�м�¼!\n");	break;}
			printf("\n   ��������   ���ѽ��     ������Ŀ      ���ѵص�    \n");
			ListTraverse_Records(L,PrintRecord);
			printf("\n����%d�����Ѽ�¼",ListLength_Records(L));
			printf("\n��ǰ���:%.2f\n\n",money);
			break;
		case 3:
			printf("\n��ǰ���:%.2f\n",money);
			Deposit(money); 
			break;
		case 4:
			{
				char c;
				puts("\n***��ӭʹ�����ѹ�����***\n");
				printf("��ѡ�����²���:\n");
				printf("\na:����������");
				printf("\nb:�����ѽ������");
				printf("\nc:�����ѵص�����");
				printf("\n0:�˳�ϵͳ!\n");
				scanf("%c",&c);
				fflush(stdin);
				switch(c)
				{
				;
				}

			}
		case 5:
			{
				int i=0;
				ChangeCode(c,i);
				if(Login(c))
				break;
			}
		}
	}
 }
  
