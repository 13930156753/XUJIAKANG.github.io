#include <stdio.h>

#include <stdlib.h>
 
#define TRUE 1

#define FALSE 0

#define Stack_Size 50

#include"stack.h"
//主函数

int main()
{
	SeqStack_num OVS;

	SeqStack OPTR;
	
	InitStack_num(&OVS);

	InitStack(&OPTR);//初始化

	char ch,ch_temp,op;

	int num,v,temp,x;

	Push(&OPTR,'#');

	printf("Please input an expression(Ending with #):");

	ch=getchar();//这里有输入// 

	while(ch!='#'||GetTop(&OPTR)!='#')
	{

		if(ch>='0'&&ch<='9')//操作数 
		{
			temp=ch-'0';//先把当前操作数从字符转换成数字 

			ch=getchar();//这里有输入// 

			while(ch>='0'&&ch<='9')
			{

				temp=temp*10+ch-'0';

				ch=getchar();//这里有输入// 

			}

			Push_num(&OVS,temp);
		}
		else
		
		{

		 switch(Compare(ch,GetTop(&OPTR)))

		 {

		 	case '>':Push(&OPTR,ch);ch=getchar();break;//这里有输入// 

		 	case '=':

		 	case '<':

		 		num=GetTop_num(&OVS); 

				Pop_num(&OVS,&x);//将第二个进来的操作数出栈 （暂存入整型变量x） 

				switch(GetTop(&OPTR)){

					case'+':num=GetTop_num(&OVS)+num;break;
					
					case'-':num=GetTop_num(&OVS)-num;break;

					case'*':num=GetTop_num(&OVS)*num;break;

					case'/':num=GetTop_num(&OVS)/num;break;

				}

				Pop(&OPTR,&op);//将最后进来的运算符出栈 （暂存入字符变量op） 

				Pop_num(&OVS,&x);//将第一个进来的操作数出栈  （暂存入整型变量x） 

				Push_num(&OVS,num);//将进行第一次运算得到的结果存入栈OVS中 

				if(ch==')'){

					Pop(&OPTR,&op);

					ch=getchar();//这里有输入// 
				}

		 }

		}

		v=GetTop_num(&OVS);

	}

	printf("the result is %d",v);

} 
