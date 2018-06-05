#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node 
{ 
    char data; 
    struct node *next; 
}snode,*slink;
typedef struct node1 
{ 
    int data; 
    struct node1 *next; 
}snode1,*slink1;  
void Clearstack(slink s) //��ջ��
{ 
    s=NULL; 
}  
int Emptystack(slink s) //�ж�ջ�Ƿ�Ϊ��
{ 
    if(s==NULL) return(1);//ջ�շ���1
    else return(0); //ջ�ǿշ���0
}  
char Getstop(slink s)//ȡջ��Ԫ��
{ 
    if(s!=NULL) return (s->data); 
    return (0); 
} 
void Push(slink*s,char x) //Ԫ��x��ջ
{ 
    slink p; 
    p=(slink)malloc(sizeof(snode));  //���ɽ�ջp�ڵ� 
    p->data=x; //������Ԫ�� 
    p->next=*s; //p�ڵ���Ϊ�µ�ջ������ 
    *s=p; 
}
char Pop(slink*s)
{
	char x;
	slink p;
	if(Emptystack(*s)) return(-1);
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return(x);
	}
}
void Clearstack1(slink1 s) //��ջ��
{ 
    s=NULL; 
}  
int Emptystack1(slink1 s) //�ж�ջ�Ƿ�Ϊ��
{ 
    if(s==NULL) return(1);//ջ�շ���1
    else return(0); //ջ�ǿշ���0
}  
char Getstop1(slink1 s)//ȡջ��Ԫ��
{ 
    if(s!=NULL) return (s->data); 
    return (0); 
} 
void Push1(slink1*s,int x) //Ԫ��x��ջ
{ 
    slink1 p; 
    p=(slink1)malloc(sizeof(snode1));  //���ɽ�ջp�ڵ� 
    p->data=x; //������Ԫ�� 
    p->next=*s; //p�ڵ���Ϊ�µ�ջ������ 
    *s=p; 
}
int Pop1(slink1*s)
{
	int x;
	slink1 p;
	if(Emptystack1(*s)) return(-1);
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return(x);
	}
}
int Precede(char x,char y)
{
	int a,b;
	switch(x)
	{
		case'#':
		case'(':a=0;break;
		case'+':
		case'-':a=1;break;
		case'*':
		case'/':a=2;break;	
	}
	switch(y)
	{
		case'+':
		case'-':b=1;break;
		case'*':
		case'/':b=2;break;
		case'(':b=3;break;
				
	}
	if(a>=b) return(1);
	else return(0);
}
void Mid_post(char E[],char B[])
{
	int i=0,j=0;
	char x;int a;
	slink s=NULL;
	Clearstack(s);
	Push(&s,'#');
	do
	{
		x=B[i++];
		switch(x)
		{
			case' ':break;
			case'#':
			{
				while(!Emptystack(s))
				{
					E[j++]=' ';
					E[j++]=Pop(&s);
				}
			}break;
			case')':
			{
				while(Getstop(s)!='(')
				{
					E[j++]=' ';
					E[j++]=Pop(&s);
				}
				Pop(&s);
			}break;
			case'+':
			case'-':
			case'*':
			case'/':
			case'(':
			{
				while(Precede(Getstop(s),x))
				{
					E[j++]=' ';
					E[j++]=Pop(&s);
				}
				Push(&s,x);
				E[j++]=' ';
			}break;
			default:E[j++]=x;	 
		}
	}while(x!='#');
	E[j]='\0';
	Clearstack(s);
}
int Ecount(char E[])
{
	int i=0,g=0,k=0,d=0,d1,g1;
	char x;
	int z,a,b;
	slink1 s=NULL;
	while(E[i]!='#')
	{
		x=E[i];
		switch(x)
		{
			case' ':break;
			case'+':b=Pop1(&s);a=Pop1(&s);z=a+b;Push1(&s,z);break;
			case'-':b=Pop1(&s);a=Pop1(&s);z=a-b;Push1(&s,z);break;
			case'*':b=Pop1(&s);a=Pop1(&s);z=a*b;Push1(&s,z);break;
			case'/':b=Pop1(&s);a=Pop1(&s);z=a/b;Push1(&s,z);break;
			default:x=E[i]-'0';Push1(&s,x);
		}
		i++;
	}
	if(!Emptystack1(s)) return(Getstop1(s)); 
 } 
 int pd(char B[])
{
	int i=0,c,j,k;
	c=strlen(B);
	while(B[i]!='#')
	{
		switch(B[i])
		{
			case' ':break;
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case'8':
			case'9':
			{  j=i+1;
			   if(B[j]==' ')
			   {
				while(B[j]==' ')j++;
				switch(B[j])
				{
					case'0':
					case'1':
					case'2':
					case'3':
					case'4':
					case'5':
					case'6':
					case'7':
					case'8':
					case'9':printf("1�Ƿ��������������룡\n");
					return(0);break;
					
	
				}
			}
			
			
			}break;
			case'+':
			case'-':	
			case'*':	
			case'/':
			{
				j=i-1;
				while(B[j]==' ')j--;
				switch(B[j])
				{
					case'+':
					case'-':
					case'*':
					case'/':
					case'(':	
					case'#':printf("2�Ƿ��������������룡\n");return(0);break;
				}
				k=i+1;
				while(B[k]==' ')k++;
				switch(B[k])
				{
					case'+':
					case'-':
					case'*':
					case'/':
					case')':
					case'#':printf("3�Ƿ��������������룡\n");return(0);break;	
				}
			}break;
				case'(':
				{
				j=i-1;
				while(B[j]==' ')j--;
				switch(B[j])
				{
					case'0':
					case'1':
					case'2':
					case'3':
					case'4':
					case'5':
					case'6':
					case'7':
					case'8':
					case'9':
					case'#':
					case')':printf("4�Ƿ��������������룡\n");return(0);break;	
				}
				k=i+1;
				while(B[k]==' ')k++;
				switch(B[k])
				{
					case'+':
					case'-':
					case'*':
					case'/':
					case'#':printf("5�Ƿ��������������룡\n");return(0);break;	
				}
				
			}break;
			case')':
			{
				j=i-1;
				while(B[j]==' ')j--;
				switch(B[j])
				{
					case'(':printf("6�Ƿ���������������");return(0);break; 
				}
				k=i+1;
				while(B[k]==' ')k++;
				switch(B[k])
				{
					case'0':
					case'1':
					case'2':
					case'3':
					case'4':
					case'5':
					case'6':
					case'7':
					case'8':
					case'9':printf("7�Ƿ����룬���������룡\n");return(0);break;	
			    } 
			}break;
			case'\0':break;
			default:printf("8�Ƿ��������������룡\n");return(0);				
			}i++;
				if(B[0]=='#')
				{
					printf("���ʽΪ�գ����������룡\n");return(0);
				}
				else if(B[c-1]!='#')
				{
					printf("9�Ƿ����룬���������룡\n");return(0); 
				} 
		}	
}

int main()
{
	int a,b,c,d;
	char B[100],E[100];
	do
	{
		do
		{
		    printf("��������׺���ʽ:\n");
		    B[100]=fflush(stdin);
		    gets_s(B);
		while(B[0]=='\0')
		{
			B[100]=fflush(stdin);
			gets_s(B);
		}
	        b=pd(B);
	}while(b==0);
	Mid_post(E,B);
	printf("��׺���ʽΪ:\n");
	printf("%s\n",E);
	a=Ecount(E);
	printf("���=%d\n",a);
	printf("�Ƿ������1��������0������\n");
	scanf("%d",&c);
    }while(c==1);
    return 0;
}
