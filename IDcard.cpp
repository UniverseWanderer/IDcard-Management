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
		puts("请输入用户名:"); 
		scanf("%s",&x);
		for(i=0;i<5;i++)
		{if(strcmp(c[i].User_Name,x)==0) 
		strcpy(temp,c[i].Code); 
		}
		puts("请输入密码:");   
		scanf("%s",&y);	
		if(strcmp(y,temp)==0)
		flag=0;	
		else puts("用户名或密码错误!请重新输入\n");
	}
	 return 1;
}

void ShowMessages()
{
	printf("\n$$$$$$$$$$$$$$$$$$$$$");
	printf("\n请选择您需要的操作:");
	printf("\n1:添加记录");
	printf("\n2:查询消费记录");
	printf("\n3:一卡通充值");
	printf("\n4:消费管理(维护中)");
	printf("\n5:修改密码");
	printf("\n0:退出系统!\n");
}

void AddRecord(SqList_Records *L)
{
	ElemType e;
	printf("\n请输入您的消费记录\n---------------\n");
	puts("消费日期（月）:");  scanf("%d",&(e.Month));
	puts("消费日期（日）:");  scanf("%d",&(e.Day));
	puts("消费金额:");        scanf("%f",&(e.Cost)); money-=(e.Cost);
	puts("消费项目:");        
	scanf("%s",&(e.Food));
	puts("消费地点:");        
	scanf("%s",&(e.Place));
	printf("\n---------------\n");
	ListInsert_Records(L,ListLength_Records(*L)+1,e);
	printf("添加成功\n");	
}

void PrintRecord(ElemType e)
{ 
	printf("   %2d月%2d日",e.Month,e.Day);
	printf("    %-6.2f      ",e.Cost);
	printf("%-6s        ",(e.Food));
	printf("%-6s",(e.Place));
	printf("\n");
}

void Deposit(float x)
{
	float a;
	printf("\n请输入充值金额:");
	scanf("%f",&a);
	while(a<0)
	{
		printf("\n您输入的金额不正确，请重新输入:"); 
		scanf("%f",&a);
	}
	money+=a;
	printf("\n充值成功!\n您当前余额为:%.2f\n",money);
}

void ChangeCode(User c[],int i)
{
	char a[10];
	puts("\n请输入原密码:");
	gets(a);
	if(strcmp(a,c[i].Code)==0)
	{
		puts("输入新密码:");
		scanf("%s",&(c[i].Code));
		puts("修改成功!\n");
	}
	else
		puts("密码错误,修改失败!");
}
	   


void main()
 {
	SqList_Records L;
	ElemType e;
	int a,flag;
	User c[5]={{"1","a"}};
	InitList_Records(&L);
	puts("…………欢迎使用一卡通管理系统…………\n\n");
	flag=Login(c);
	if(!flag);
	while(1)
	{		 
		ShowMessages();
		printf("请选择功能:\n");
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
			{printf("\n当前没有记录!\n");	break;}
			printf("\n   消费日期   消费金额     消费项目      消费地点    \n");
			ListTraverse_Records(L,PrintRecord);
			printf("\n共有%d条消费记录",ListLength_Records(L));
			printf("\n当前余额:%.2f\n\n",money);
			break;
		case 3:
			printf("\n当前余额:%.2f\n",money);
			Deposit(money); 
			break;
		case 4:
			{
				char c;
				puts("\n***欢迎使用消费管理功能***\n");
				printf("请选择以下操作:\n");
				printf("\na:按日期排列");
				printf("\nb:按消费金额排列");
				printf("\nc:按消费地点排列");
				printf("\n0:退出系统!\n");
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
  
