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
void Clearstack(slink s) //置栈空
{ 
    s=NULL; 
}  
int Emptystack(slink s) //判断栈是否为空
{ 
    if(s==NULL) return(1);//栈空返回1
    else return(0); //栈非空返回0
}  
char Getstop(slink s)//取栈顶元素
{ 
    if(s!=NULL) return (s->data); 
    return (0); 
} 
void Push(slink*s,char x) //元素x进栈
{ 
    slink p; 
    p=(slink)malloc(sizeof(snode));  //生成进栈p节点 
    p->data=x; //存入新元素 
    p->next=*s; //p节点作为新的栈顶链入 
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
void Clearstack1(slink1 s) //置栈空
{ 
    s=NULL; 
}  
int Emptystack1(slink1 s) //判断栈是否为空
{ 
    if(s==NULL) return(1);//栈空返回1
    else return(0); //栈非空返回0
}  
char Getstop1(slink1 s)//取栈顶元素
{ 
    if(s!=NULL) return (s->data); 
    return (0); 
} 
void Push1(slink1*s,int x) //元素x进栈
{ 
    slink1 p; 
    p=(slink1)malloc(sizeof(snode1));  //生成进栈p节点 
    p->data=x; //存入新元素 
    p->next=*s; //p节点作为新的栈顶链入 
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
					case'9':printf("1非法输入请重新输入！\n");
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
					case'#':printf("2非法输入请重新输入！\n");return(0);break;
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
					case'#':printf("3非法输入请重新输入！\n");return(0);break;	
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
					case')':printf("4非法输入请重新输入！\n");return(0);break;	
				}
				k=i+1;
				while(B[k]==' ')k++;
				switch(B[k])
				{
					case'+':
					case'-':
					case'*':
					case'/':
					case'#':printf("5非法输入请重新输入！\n");return(0);break;	
				}
				
			}break;
			case')':
			{
				j=i-1;
				while(B[j]==' ')j--;
				switch(B[j])
				{
					case'(':printf("6非法输入请重新输入");return(0);break; 
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
					case'9':printf("7非法输入，请重新输入！\n");return(0);break;	
			    } 
			}break;
			case'\0':break;
			default:printf("8非法输入请重新输入！\n");return(0);				
			}i++;
				if(B[0]=='#')
				{
					printf("表达式为空！请重新输入！\n");return(0);
				}
				else if(B[c-1]!='#')
				{
					printf("9非法输入，请重新输入！\n");return(0); 
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
		    printf("请输入中缀表达式:\n");
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
	printf("后缀表达式为:\n");
	printf("%s\n",E);
	a=Ecount(E);
	printf("结果=%d\n",a);
	printf("是否继续？1：继续；0：结束\n");
	scanf("%d",&c);
    }while(c==1);
    return 0;
}
