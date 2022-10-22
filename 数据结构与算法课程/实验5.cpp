
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
#define NAME_NO 30
#define HASH_LENGTH 50 
#define M 50
 
typedef struct
{
	char *py;
	int k;
}NAME;
 
typedef struct 
{
	char *py;
	int k;
	int si;
}HASH;
 
 
NAME NameList[30];
HASH HashList[HASH_LENGTH];
 
void init_namelist()
{
	int i;	 
	int j;
	int s0;
	char *p;
 
	NameList[0].py="chenliang";//����  
    NameList[1].py="chenyuanhao";//��Ԫ��  
    NameList[2].py="chengwenliang";//������  
    NameList[3].py="dinglei";//����  
    NameList[4].py="fenghanzao";//�뺺��  
    NameList[5].py="fuzongkai";//���ڿ�  
    NameList[6].py="hujingbin";//������  
    NameList[7].py="huangjianwu";//�ƽ���  
    NameList[8].py="lailaifa";//������  
    NameList[9].py="lijiahao";//��κ�  
    NameList[10].py="liangxiaocong";//������  
    NameList[11].py="linchunhua";//�ִ���  
    NameList[12].py="liujianhui";//������  
    NameList[13].py="luzhijian";//¬־��  
    NameList[14].py="luonan";//���  
    NameList[15].py="quegaoxiang";//�ڸ���  
    NameList[16].py="sugan";//����  
    NameList[17].py="suzhiqiang";//��־ǿ  
    NameList[18].py="taojiayang";//�ռ���  
    NameList[19].py="wujiawen";//�����  
    NameList[20].py="xiaozhuomin";//Ф׿��  
    NameList[21].py="xujinfeng"; //����  
    NameList[22].py="yanghaichun";//���  
    NameList[23].py="yeweixiong";//Ҷά��  
    NameList[24].py="zengwei";//����  
    NameList[25].py="zhengyongbin";//֣Ӻ��  
    NameList[26].py="zhongminghua";//������  
    NameList[27].py="chenliyan";//������  
    NameList[28].py="liuxiaohui";//������  
    NameList[29].py="panjinmei";//�˽�÷ 
 
	for (i=0; i<NAME_NO; i++)
	{
		s0 = 0;
		p = NameList[i].py;
		for (j=0; *(p+j)!='\0'; j++)			
		{
			s0 += *(p+j);		
		}
		NameList[i].k = s0;
		printf("%13s %d\n", NameList[i].py, NameList[i].k%M );
	}
}
 
void CreateHashList()
{
	int i ;		
	int j;
	int collision_cnt = 0;
 
	for (i=0; i<HASH_LENGTH; i++)
	{
		HashList[i].py = "";
		HashList[i].k = 0;
		HashList[i].si = 0;
	}
	
	for (i=0; i<NAME_NO; i++)
	{
		int sum = 0;
		int adr = (NameList[i].k)%M;
		int d = adr;
 
		collision_cnt = 0;
 
		if (HashList[adr].si == 0)
		{
			printf("\e[48;5;9m success adr %d\e[0m\n", d);
			HashList[adr].k = NameList[i].k;
			HashList[adr].py = NameList[i].py;
			HashList[adr].si=1;
		}
		else
		{
			do
			{
				collision_cnt++;
				printf("collision adr=%d\n", d);
				d = (d+NameList[i].k%10+1)%M;
				sum +=1;
				printf("new adr %d, collision_cnt = %d\n",d,  collision_cnt);
				if (collision_cnt>10) 
				{
					printf("*******fail********\n");
					goto out;
				}
			}while(HashList[d].k != 0);	
 
			printf("\e[48;5;9m success adr %d\e[0m\n", d);
		
			HashList[d].k = NameList[i].k;
			HashList[d].py = NameList[i].py;
			HashList[d].si = sum+1;
		}
	}
	
out:
 
	printf("----------------------------------------\n");
	j = 0;
	for(i=0; i<HASH_LENGTH; i++)	
	{
			
		if (HashList[i].k != 0)	
		{
			j++;
			printf("%d:%13s, %d, %d\n",i, HashList[i].py, HashList[i].k, HashList[i].si );	
		}
		else
		{
			printf("%d:empty!\n", i);		
		}
	}
 
	printf("-----------totall = %d-------------\n", j);
}
 
void FindList()
{
	char name[20] = {0};
	int adr;
	int d;
	int sum=1;
	int i;
	int s0 = 0;
 
	printf("please input pinyin\n");
	scanf("%s", name);
 
	for (i=0; i<20; i++)
	{
		if(name[i] != '\0')
		s0 += name[i];
	}
 
	printf("to find: name:%s, key:%d\n", name, s0);
	
	adr = s0%M;
	d = adr;
		
	if ((HashList[adr].k == s0) && (strcmp(HashList[adr].py, name) == 0))
		printf("find name:%s key=%d, length=1\n", HashList[d].py, s0);
	else if (HashList[adr].k == 0)
		printf("no record\n");
	else
	{
		do
		{
			d = (d+s0%10+1)%M;
			sum++;
			if (HashList[d].k == 0)
			{
				printf("no record!\n");	
				break;
			}
			
			if ((HashList[d].k == s0) && (strcmp(HashList[d].py, name) == 0))
			{
				printf("find name:%s, key:%d, search_len=%d\n", HashList[i].py, s0, sum);	
				break;
			}
 
		}while(1);	
	}
 
}
 
 
int main(void)
{
	init_namelist();
	CreateHashList();
	FindList();
 
	return 0;
}
