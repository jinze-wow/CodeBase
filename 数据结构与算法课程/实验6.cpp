/*
*  ֱ�Ӳ��룺 charu����
*  ѡ��  xuanzepai���� 
*  ð��:  maopao����
*  ���ţ� Qsort �ݹ麯�� 
*  ϣ����shell ���� 
*  �鲢��GB ���� 
*/ 
# include <stdio.h>  
# include <stdlib.h>
# include <time.h>
# define N 30000
# define SR 1001
int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,b,bb,d,dd,e,ee,f,ff,num;   //������ĸ��Ϊ��¼�ıȽϴ���-�ƶ��Ĵ�����˫��ĸΪ�ؼ��ֵ��ƶ����� 
long long c,cc;
void charu(int A[],int n);//��n��Ԫ��                     ֱ�Ӳ�������
void xuanzepai(int A[],int n);//��n��Ԫ��                  ѡ������ 
void maopao(int A[],int n);  //                            ð������ 
void Quicksort(int A[],int L,int R);//��[L,R]��Ԫ��       ��������
void shell(int A[],int n);//��n��Ԫ��                     shell ���� 
void GBPX(int S[],int L,int R,int T[]);//                  �鲢���� 
int GB(int S[],int L,int M,int R,int T[]);//����鲢����    
int gainint(int *p,int min,int max);//���������ĺ���    *p�ķ�Χ[min,max] 
int change(int *a,int *b);//��������                      ����a b��ֵ 
void charu(int A[],int n)//����ѭ���Ƚϴ��� 
{  
    int i,j,temp;  
    for (i=1,a++;i<n;i++,a++)  
        if (A[i]<A[i-1])  
        {   
            temp=A[i];
            for(a++,aa++,j=i-1;j>=0&& A[j]>temp;j--,a++,aa++)
            	A[j+1]=A[j];
            A[j+1]=temp;
        }  
}  
void xuanzepai(int A[],int n)//��A[0]Ϊ�Ƚ����� ����  
{  
    int i,j,k;  
    for(i=0,b++;i<n-1;i++,b++)  
    {  
       k=i;  
       for(j=i+1,b++;j<n;j++,b++)  
          if(A[j]<A[k])  
              { k=j;b++;}  
       if(k!=i)    
       {
          bb+=change(&A[i],&A[k]);   
       }
    }   
} 
void maopao(int A[],int n)  
{  
    int i,j;  
    for (i = n -1 ; i>=0 ;i--)  
    {  
        for (j = 0; j<i; j++)  
        {  
            if(A[j]>A[j+1])
              cc+=change(&A[j],&A[j+1]);
        }  
    }  
}  
void Quicksort(int A[],int L,int R)//�������� ����   
{  
    int i=L,j=R,T=A[L]; //TΪ��׼��  
    if(L>R)  return;  
    while(i!=j) //��������������û����  
    {  
        while(A[j]>=T&&i<j){j--;d++;}  //����������
        while(A[i]<=T&&i<j){i++;d++;} //����������   
        if(i<j)dd+=change(&A[i],&A[j]); //��������  
    }  
    if(L!=i)
        dd+=change(&A[L],&A[i]);       //��׼����λ  
    Quicksort(A,L,i-1);         //�ݹ���  
    Quicksort(A,i+1,R);         //�ݹ���  
}  
void shell(int A[],int n)//ϣ������ ����Ϊ2 
{
	int i,j,k;
	for(k=n>>1,e++;k>0;k=k>>1,e++)
	{
		for(i=k,e++;i<n;i++,e++)
		{
			for(j=i-k,e++;j>=0;j-=k,e++)
			    if(A[j]>A[j+k])
			       ee+=change(&A[j],&A[j+k]);
		}
	}
}
int GB(int S[],int L,int M,int R,int T[])//����鲢����  
{  
    int i=M,j=R,k=0,count=0;  
    while(i>=L&&j>M)  
    {  
        f++;
        if(S[i]>S[j])  
        {  
            T[k++]=S[i--];//����ʱ��������һ��λ�ÿ�ʼ����  
              
        }  
        else  T[k++]=S[j--];   
        count++;
    }  
    
    while(i>=L){f++;T[k++]=S[i--];} //��ǰ������黹��Ԫ��δ������ʱ����T��  
    while(j>M){f++;T[k++]=S[j--];}     
    for(i=0,f+=k;i<k;i++)  S[R-i]=T[i];//д��ԭ����
    return count;  
}  
void GBPX(int S[],int L,int R,int T[])  
{  
    int M;    
    if(L<R)  
    {  
        M=(L+R)>>1;  
        GBPX(S,L,M,T);//�����ε��������Ŀ  
        GBPX(S,M+1,R,T);//���Ұ�ε��������Ŀ  
        ff+=GB(S,L,M,R,T);//�������Ұ��������Ժ�������������������֮�������ԡ�  
    }     
}  
int gainint(int *p,int min,int max)//����int *pֱ������(a,b)���������������*p��λ��          
{           
    do{          
        *p=min-1;    //�˴���Ϊ�˼�����������ķ��� ��Ȼ�����������������    
        scanf("%d",p);          
        while(getchar()!='\n');          
        if(*p>max||*p<min)          
            printf("��������,����������[%d--%d]:",min,max);          
    }while(*p>max||*p<min);          
    return *p;          
}  
int change(int *a,int *b)//��������                       ����a b��ֵ   
{  
    int c=*a;  
    *a=*b;  
    *b=c;  
    return 3;
}  
int main(){    
    int i,t; 
    srand(time(0));
    printf("������N [2,%d]:",N);
    gainint(&num,2,N);
    for(i=0;i<num;i++)
     printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%SR);
    charu(A,num);
    printf("\nֱ�Ӳ�������:\n�Ƚϴ���:%10d\t�ƶ�����%10d\n\n",a,aa);
    xuanzepai(B,num);
    printf("��ѡ������:\n�Ƚϴ���:%10d\t�ƶ�����%10d\n\n",b+bb/3,bb);
    c=(num-1)*num/2;
    maopao(C,num); 
    printf("ð������:\n�Ƚϴ���:%10lld\t�ƶ�����%10lld\n\n",c+cc/3,cc);
    Quicksort(D,0,num-1);
    printf("��������:\n�Ƚϴ���:%10d\t�ƶ�����%10d\n\n",d+dd/3,dd);
    shell(E,num);
    printf("ϣ������:\n�Ƚϴ���:%10d\t�ƶ�����%10d\n\n",e+ee/3,ee);
    GBPX(F,0,num-1,G);
    printf("�鲢����:\n�Ƚϴ���:%10d\t�ƶ�����%10d\n\n",f,ff);
    printf("���������������");
	getchar(); 
    return 0;  
}  

