/*
*  直接插入： charu函数
*  选择：  xuanzepai函数 
*  冒泡:  maopao函数
*  快排： Qsort 递归函数 
*  希尔：shell 函数 
*  归并：GB 函数 
*/ 
# include <stdio.h>  
# include <stdlib.h>
# include <time.h>
# define N 30000
# define SR 1001
int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,b,bb,d,dd,e,ee,f,ff,num;   //单个字母的为记录的比较次数-移动的次数，双字母为关键字的移动次数 
long long c,cc;
void charu(int A[],int n);//对n个元素                     直接插入排序
void xuanzepai(int A[],int n);//对n个元素                  选择升序 
void maopao(int A[],int n);  //                            冒泡排序 
void Quicksort(int A[],int L,int R);//对[L,R]个元素       快速升序
void shell(int A[],int n);//对n个元素                     shell 升序 
void GBPX(int S[],int L,int R,int T[]);//                  归并排序 
int GB(int S[],int L,int M,int R,int T[]);//数组归并操作    
int gainint(int *p,int min,int max);//防输错而建的函数    *p的范围[min,max] 
int change(int *a,int *b);//交换函数                      交换a b的值 
void charu(int A[],int n)//返回循环比较次数 
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
void xuanzepai(int A[],int n)//以A[0]为比较依据 升序  
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
void Quicksort(int A[],int L,int R)//快速排序 升序   
{  
    int i=L,j=R,T=A[L]; //T为基准数  
    if(L>R)  return;  
    while(i!=j) //当数组左右两边没相遇  
    {  
        while(A[j]>=T&&i<j){j--;d++;}  //从右向左找
        while(A[i]<=T&&i<j){i++;d++;} //从左向右找   
        if(i<j)dd+=change(&A[i],&A[j]); //交换两数  
    }  
    if(L!=i)
        dd+=change(&A[L],&A[i]);       //基准数归位  
    Quicksort(A,L,i-1);         //递归左  
    Quicksort(A,i+1,R);         //递归右  
}  
void shell(int A[],int n)//希尔排序 增量为2 
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
int GB(int S[],int L,int M,int R,int T[])//数组归并操作  
{  
    int i=M,j=R,k=0,count=0;  
    while(i>=L&&j>M)  
    {  
        f++;
        if(S[i]>S[j])  
        {  
            T[k++]=S[i--];//从临时数组的最后一个位置开始排序  
              
        }  
        else  T[k++]=S[j--];   
        count++;
    }  
    
    while(i>=L){f++;T[k++]=S[i--];} //若前半段数组还有元素未放入临时数组T中  
    while(j>M){f++;T[k++]=S[j--];}     
    for(i=0,f+=k;i<k;i++)  S[R-i]=T[i];//写回原数组
    return count;  
}  
void GBPX(int S[],int L,int R,int T[])  
{  
    int M;    
    if(L<R)  
    {  
        M=(L+R)>>1;  
        GBPX(S,L,M,T);//找左半段的逆序对数目  
        GBPX(S,M+1,R,T);//找右半段的逆序对数目  
        ff+=GB(S,L,M,R,T);//找完左右半段逆序对以后两段数组有序，找两段之间的逆序对。  
    }     
}  
int gainint(int *p,int min,int max)//输入int *p直至满足(a,b)输入结束，并返回*p的位数          
{           
    do{          
        *p=min-1;    //此处是为了减少意外情况的发生 虽然那种意外情况不常见    
        scanf("%d",p);          
        while(getchar()!='\n');          
        if(*p>max||*p<min)          
            printf("输入有误,请重新输入[%d--%d]:",min,max);          
    }while(*p>max||*p<min);          
    return *p;          
}  
int change(int *a,int *b)//交换函数                       交换a b的值   
{  
    int c=*a;  
    *a=*b;  
    *b=c;  
    return 3;
}  
int main(){    
    int i,t; 
    srand(time(0));
    printf("请输入N [2,%d]:",N);
    gainint(&num,2,N);
    for(i=0;i<num;i++)
     printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%SR);
    charu(A,num);
    printf("\n直接插入排序:\n比较次数:%10d\t移动次数%10d\n\n",a,aa);
    xuanzepai(B,num);
    printf("简单选择排序:\n比较次数:%10d\t移动次数%10d\n\n",b+bb/3,bb);
    c=(num-1)*num/2;
    maopao(C,num); 
    printf("冒泡排序:\n比较次数:%10lld\t移动次数%10lld\n\n",c+cc/3,cc);
    Quicksort(D,0,num-1);
    printf("快速排序:\n比较次数:%10d\t移动次数%10d\n\n",d+dd/3,dd);
    shell(E,num);
    printf("希尔排序:\n比较次数:%10d\t移动次数%10d\n\n",e+ee/3,ee);
    GBPX(F,0,num-1,G);
    printf("归并排序:\n比较次数:%10d\t移动次数%10d\n\n",f,ff);
    printf("按任意键继续……");
	getchar(); 
    return 0;  
}  

