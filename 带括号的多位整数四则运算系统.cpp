#include <stdio.h>

#include <stdlib.h>
 
#define TRUE 1

#define FALSE 0

#define Stack_Size 50

#include"stack.h"
//������

int main()
{
	SeqStack_num OVS;

	SeqStack OPTR;
	
	InitStack_num(&OVS);

	InitStack(&OPTR);//��ʼ��

	char ch,ch_temp,op;

	int num,v,temp,x;

	Push(&OPTR,'#');

	printf("Please input an expression(Ending with #):");

	ch=getchar();//����������// 

	while(ch!='#'||GetTop(&OPTR)!='#')
	{

		if(ch>='0'&&ch<='9')//������ 
		{
			temp=ch-'0';//�Ȱѵ�ǰ���������ַ�ת�������� 

			ch=getchar();//����������// 

			while(ch>='0'&&ch<='9')
			{

				temp=temp*10+ch-'0';

				ch=getchar();//����������// 

			}

			Push_num(&OVS,temp);
		}
		else
		
		{

		 switch(Compare(ch,GetTop(&OPTR)))

		 {

		 	case '>':Push(&OPTR,ch);ch=getchar();break;//����������// 

		 	case '=':

		 	case '<':

		 		num=GetTop_num(&OVS); 

				Pop_num(&OVS,&x);//���ڶ��������Ĳ�������ջ ���ݴ������ͱ���x�� 

				switch(GetTop(&OPTR)){

					case'+':num=GetTop_num(&OVS)+num;break;
					
					case'-':num=GetTop_num(&OVS)-num;break;

					case'*':num=GetTop_num(&OVS)*num;break;

					case'/':num=GetTop_num(&OVS)/num;break;

				}

				Pop(&OPTR,&op);//�����������������ջ ���ݴ����ַ�����op�� 

				Pop_num(&OVS,&x);//����һ�������Ĳ�������ջ  ���ݴ������ͱ���x�� 

				Push_num(&OVS,num);//�����е�һ������õ��Ľ������ջOVS�� 

				if(ch==')'){

					Pop(&OPTR,&op);

					ch=getchar();//����������// 
				}

		 }

		}

		v=GetTop_num(&OVS);

	}

	printf("the result is %d",v);

} 
