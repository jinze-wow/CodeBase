#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int password;//存储密码，即m
	int num;
	struct Node* next;
}Node, * Link;

void InitList(Link& L) {//创建一个空的链表
	L = (Node*)malloc(sizeof(Node));
	if (!L)
		exit(1);
	L->password = 0;
	L->num = 0;
	L->next = L;
}
void CreateList(int n, Link& L) {//初始化链表
	Link p, q;
	q = L;
	printf("请输入这%d个人的初始密码分别为：", n);
	for (int i = 1; i <= n; i++) {
		p = (Node*)malloc(sizeof(Node));
		if (!p)
			exit(1);
		scanf_s("%d", &p->password);
		p->num = i;
		L->next = p;
		L = p;
	}
	L->next = q->next;
	free(q);
}
void PrintList(Link& L, int m, int n) {//找位置
	Link p, q;
	p = L;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i < m; i++)
			p = p->next;
		q = p->next;
		m = q->password;
		printf("%d ", q->num);
		p->next = q->next;
		free(q);
	}
}
int main() {
	Link L, p, q;
	int n, m;
	L = NULL;
	InitList(L);
	printf("初始密码为：");
	scanf_s("%d", &m);
	printf("总人数为：");
	scanf_s("%d", &n);
	CreateList(n, L);
	printf("正确的输出为：");
	PrintList(L, m, n);
	printf("\n");
	return 0;
}