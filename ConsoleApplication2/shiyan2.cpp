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
	float data;
	struct node1 *next;
}snode1,*slink1;
void Clearstack(slink s)  //置栈空 
{
	s=NULL;
}
float Emptystack(slink s)  //判断栈是否为空
{
	if(s==NULL) return(1);  //栈空返回1
	else return(0);          //栈非空返回0 
} 
char Getstop(slink s) //取栈顶元素
{
	if(s!=NULL) return (s->data);  
	return (0);   
}
void Push(slink*s,char x)  //元素x进栈
{
	slink p;
	p=(slink)malloc(sizeof(snode));   //生成进栈p节点 
	p->data=x;                        //存入新元素 
	p->next=*s;                      //p节点作为新的栈顶链入 
	*s=p;
}
char Pop(slink*s)     //出栈
{
	char x;
	slink p;
	if(Emptystack(*s)) return (-1);  //栈空，返回-1 
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return (x);      //成功 
	}
}
void Push1(slink1*s,float x)  //元素x进栈
{
	slink1 p;
	p=(slink1)malloc(sizeof(snode1));   //生成进栈p节点 
	p->data=x;                        //存入新元素 
	p->next=*s;                      //p节点作为新的栈顶链入 
	*s=p;
}
int Emptystack1(slink1 s)  //判断栈是否为空
{
	if (s == NULL) return(1);  //栈空返回1
	else return(0);          //栈非空返回0 
}
float Pop1(slink1*s)     //出栈
{
	float x;
	slink1 p;
	if(Emptystack1(*s)) return (-1);  //栈空，返回-1 
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return (x);      //成功 
	}
}

void Clearstack1(slink1 s)  //置栈空 
{
	s=NULL;
}
float Getstop1(slink1 s) //取栈顶元素
{
	if(s!=NULL) return (s->data);  
	return (0);   
}
float Precede(char x,char y)  
{
	float a,b;
	switch(x)
	{
		case '#':
			//case '（':
		case '(':a=0;break;
		case '+':
	    case '-':a=1;break;
	    case '*':
	    case '/':a=2;break;
	    
	}
    switch(y)
	{
		case '+':
		case '-':b=1;break;
		case '*':
		case '/':b=2;break;
	    //case '（':
		case '(':b=3;break;
	}
	if(a>=b) return (1);
	else return (0);       
} 
void Mid_post(char E[],char B[])  //中缀表达式B到后缀表达式E的转换 
{
	int i=0,j=0;
	char x; float a;
	slink s=NULL;   //置空栈 
	Clearstack(s);
	Push(&s,'#');    //结束符入栈 
	do
	{	
		x=B[i++];      //扫描当前表达式分量x 
		switch(x)
		{   
		    case ' ':break; 
		    case '#':
			{
				while(!Emptystack(s))
				{
				    E[j++]=' ';                 //栈非空时 
					E[j++]=Pop(&s);
				}
			}break;
		    case ')':
			{
				while(Getstop(s)!='(')
				{
				    E[j++]=' '; 
					E[j++]=Pop(&s);
				}                    //反复出栈直到遇到'(' 
				Pop(&s);                //退掉'(' 
			}break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			{
				while(Precede(Getstop(s),x))   //栈顶运算符（Q1）与x比较 
					{
					    E[j++]=' ';
				        E[j++]=Pop(&s);
					}	
				//E[j++]=' ';
				Push(&s,x);          //Q1<x时，x进栈
				E[j++]=' ';    
				             
			}break; 
			default:E[j++]=x;
		}
		
	}while(x!='#'); 
	E[j]='\0';
	Clearstack(s);
}
float Ecount(char E[])  //后缀表达式求值 
{
	int i=0,n=1,c=0,p;
	float g,k,d,d1,g1;
	char x;
	float z,a,b;
	slink1 s=NULL;
	while(E[i]!='#')
	{
		x=E[i];
		switch(x)
		{
			case ' ':break;
			case '+':b=Pop1(&s);a=Pop1(&s);z=a+b;Push1(&s,z);break;
			case '-':b=Pop1(&s);a=Pop1(&s);z=a-b;Push1(&s,z);break;
			case '*':b=Pop1(&s);a=Pop1(&s);z=a*b;Push1(&s,z);break;
			case '/':b=Pop1(&s);a=Pop1(&s);z=a/b;Push1(&s,z);break;	
			default:
			{
			  g=0;g1=0; 
			  while(E[i]!=' ')
			  {
			      if(E[i]=='.')
			     {
				 	c=1;
			     	i++;
			     	continue;
				 }
				 if(c==0)
				 {
				  g1=E[i]-'0';
			      g=g*10+g1;
				  i++;
				  }
				 if(c==1)
				 {
				 	g1=E[i]-'0';
				 	for(p=1;p<=n;p++)
				 	{
				 		g1=g1/10;
					 }
					 g=g+g1;
					 n++;
					 i++;
				 }
			      
			  }
			  c=0;
			  n=1; 
			  Push1(&s,g);  
		    }
		}
		i++;
	}
	if(!Emptystack1(s)) return(Getstop1(s));
	Clearstack1(s);
}
int pd(char B[])
{   int i=0,c,j,k;
    c=strlen(B);
    
    while(B[i]!='#')
    {
	    switch(B[i])
	    {   
		    case ' ':break;
		    case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7': 
		    case '8':
            case '9':
            {   j=i+1;
            	if(B[j]==' ')
            	{
            	   while(B[j]==' ') j++;
            	    switch(B[j])
            	    {	    
		                case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7': 
		                case '8':
                        case '9':printf("1非法输入!请重新输入!\n");return(0);break;
            	    }
                }
            }break;
            case '+':
            case '-': 
		    case '*': 
		    case '/':
			{
			    j=i-1;
			    while(B[j]==' ') j--;
				switch(B[j])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case '(':
					case '#':printf("2非法输入!请重新输入!\n");return(0);break;
			    }
			    k=i+1;
			    while(B[k]==' ') k++;
			    switch(B[k])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case ')':
					case '#':printf("3非法输入!请重新输入!\n");return(0);break;
			    }
			}break;
			case '(':
			{
			    j=i-1;
			    while(B[j]==' ') j--;
				switch(B[j])
				{
					case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7': 
		            case '8':
                    case '9':
					case '#':
					case ')':printf("4非法输入!请重新输入!\n");return(0);break;
			    }
			    k=i+1;
			    while(B[k]==' ') k++;
			    switch(B[k])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case '#':printf("5非法输入!请重新输入!\n");return(0);break;
			    }
		    }break;
			case ')':
            {
			    j=i-1;
			    while(B[j]==' ') j--;
			    switch(B[j])
			    {
				   case '(':printf("6非法输入!请重新输入!\n");return(0);break;
		        }
			    k=i+1;
	  		    while(B[k]==' ') k++;
			    switch(B[k])
				{
					case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7': 
		            case '8':
                    case '9':printf("7非法输入!请重新输入!\n");return(0);break;
			    }
		    }break;
            case '\0':break;
            case '.' :break;
            default:printf("8非法输入!请重新输入!\n");return(0);
			
	    }
	i++;
} 
    if(B[0]=='#')
    {
        printf("表达式为空!请重新输入!\n");return(0);
    }
    else if (B[c-1]!='#')
    {
        printf("9非法输入!请重新输入!\n");return(0);
	} 
}
void main()
{
    float a,b,d;
	int c;
	char B[100],E[100];
	char fp;
	int isFromFile;
	FILE *fpRead = fopen("data.txt", "r");
	do
	{
	printf("请选择输入方式：1.文件输入；2.键盘输入\n");
	scanf("%d", &isFromFile);
	if (isFromFile == 2)
	{
		
			do
			{
				printf("请输入中缀表达式:\n");
				B[100] = fflush(stdin);
				gets_s(B);
				while (B[0] == '\0')
				{
					B[100] = fflush(stdin);
					gets_s(B);
				}
				b = pd(B);
			} while (b == 0);
			Mid_post(E, B);
			printf("后缀表达式为:\n");
			printf("%s\n", E);
			a = Ecount(E);
			printf("结果=%f\n", a);
			printf("是否继续?是:1否:0\n");
			scanf("%d", &c);
			getchar();
		
	}
	else
	{
		int i = 0;
		if (fpRead == NULL)
		{
			printf("未找到文件...\n");
		}
		while (fscanf(fpRead,"%c",&fp) && fp!='#')
		{
			B[i] = fp;
			i++;
		}
		B[i] = '#';
		Mid_post(E, B);
		printf("后置表达式为：\n");
		printf("%s\n", E);
		a = Ecount(E);
		printf("结果=%f\n", a);
		printf("是否继续?是:1否:0\n");
		scanf("%d", &c);
		getchar();
	}
	} while (c == 1);
} 
