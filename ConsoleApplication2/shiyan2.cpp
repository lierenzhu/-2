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
void Clearstack(slink s)  //��ջ�� 
{
	s=NULL;
}
float Emptystack(slink s)  //�ж�ջ�Ƿ�Ϊ��
{
	if(s==NULL) return(1);  //ջ�շ���1
	else return(0);          //ջ�ǿշ���0 
} 
char Getstop(slink s) //ȡջ��Ԫ��
{
	if(s!=NULL) return (s->data);  
	return (0);   
}
void Push(slink*s,char x)  //Ԫ��x��ջ
{
	slink p;
	p=(slink)malloc(sizeof(snode));   //���ɽ�ջp�ڵ� 
	p->data=x;                        //������Ԫ�� 
	p->next=*s;                      //p�ڵ���Ϊ�µ�ջ������ 
	*s=p;
}
char Pop(slink*s)     //��ջ
{
	char x;
	slink p;
	if(Emptystack(*s)) return (-1);  //ջ�գ�����-1 
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return (x);      //�ɹ� 
	}
}
void Push1(slink1*s,float x)  //Ԫ��x��ջ
{
	slink1 p;
	p=(slink1)malloc(sizeof(snode1));   //���ɽ�ջp�ڵ� 
	p->data=x;                        //������Ԫ�� 
	p->next=*s;                      //p�ڵ���Ϊ�µ�ջ������ 
	*s=p;
}
int Emptystack1(slink1 s)  //�ж�ջ�Ƿ�Ϊ��
{
	if (s == NULL) return(1);  //ջ�շ���1
	else return(0);          //ջ�ǿշ���0 
}
float Pop1(slink1*s)     //��ջ
{
	float x;
	slink1 p;
	if(Emptystack1(*s)) return (-1);  //ջ�գ�����-1 
	else
	{
		x=(*s)->data;
		p=*s;
		*s=(*s)->next;
		free(p);
		return (x);      //�ɹ� 
	}
}

void Clearstack1(slink1 s)  //��ջ�� 
{
	s=NULL;
}
float Getstop1(slink1 s) //ȡջ��Ԫ��
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
			//case '��':
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
	    //case '��':
		case '(':b=3;break;
	}
	if(a>=b) return (1);
	else return (0);       
} 
void Mid_post(char E[],char B[])  //��׺���ʽB����׺���ʽE��ת�� 
{
	int i=0,j=0;
	char x; float a;
	slink s=NULL;   //�ÿ�ջ 
	Clearstack(s);
	Push(&s,'#');    //��������ջ 
	do
	{	
		x=B[i++];      //ɨ�赱ǰ���ʽ����x 
		switch(x)
		{   
		    case ' ':break; 
		    case '#':
			{
				while(!Emptystack(s))
				{
				    E[j++]=' ';                 //ջ�ǿ�ʱ 
					E[j++]=Pop(&s);
				}
			}break;
		    case ')':
			{
				while(Getstop(s)!='(')
				{
				    E[j++]=' '; 
					E[j++]=Pop(&s);
				}                    //������ջֱ������'(' 
				Pop(&s);                //�˵�'(' 
			}break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			{
				while(Precede(Getstop(s),x))   //ջ���������Q1����x�Ƚ� 
					{
					    E[j++]=' ';
				        E[j++]=Pop(&s);
					}	
				//E[j++]=' ';
				Push(&s,x);          //Q1<xʱ��x��ջ
				E[j++]=' ';    
				             
			}break; 
			default:E[j++]=x;
		}
		
	}while(x!='#'); 
	E[j]='\0';
	Clearstack(s);
}
float Ecount(char E[])  //��׺���ʽ��ֵ 
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
                        case '9':printf("1�Ƿ�����!����������!\n");return(0);break;
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
					case '#':printf("2�Ƿ�����!����������!\n");return(0);break;
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
					case '#':printf("3�Ƿ�����!����������!\n");return(0);break;
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
					case ')':printf("4�Ƿ�����!����������!\n");return(0);break;
			    }
			    k=i+1;
			    while(B[k]==' ') k++;
			    switch(B[k])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case '#':printf("5�Ƿ�����!����������!\n");return(0);break;
			    }
		    }break;
			case ')':
            {
			    j=i-1;
			    while(B[j]==' ') j--;
			    switch(B[j])
			    {
				   case '(':printf("6�Ƿ�����!����������!\n");return(0);break;
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
                    case '9':printf("7�Ƿ�����!����������!\n");return(0);break;
			    }
		    }break;
            case '\0':break;
            case '.' :break;
            default:printf("8�Ƿ�����!����������!\n");return(0);
			
	    }
	i++;
} 
    if(B[0]=='#')
    {
        printf("���ʽΪ��!����������!\n");return(0);
    }
    else if (B[c-1]!='#')
    {
        printf("9�Ƿ�����!����������!\n");return(0);
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
	printf("��ѡ�����뷽ʽ��1.�ļ����룻2.��������\n");
	scanf("%d", &isFromFile);
	if (isFromFile == 2)
	{
		
			do
			{
				printf("��������׺���ʽ:\n");
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
			printf("��׺���ʽΪ:\n");
			printf("%s\n", E);
			a = Ecount(E);
			printf("���=%f\n", a);
			printf("�Ƿ����?��:1��:0\n");
			scanf("%d", &c);
			getchar();
		
	}
	else
	{
		int i = 0;
		if (fpRead == NULL)
		{
			printf("δ�ҵ��ļ�...\n");
		}
		while (fscanf(fpRead,"%c",&fp) && fp!='#')
		{
			B[i] = fp;
			i++;
		}
		B[i] = '#';
		Mid_post(E, B);
		printf("���ñ��ʽΪ��\n");
		printf("%s\n", E);
		a = Ecount(E);
		printf("���=%f\n", a);
		printf("�Ƿ����?��:1��:0\n");
		scanf("%d", &c);
		getchar();
	}
	} while (c == 1);
} 
