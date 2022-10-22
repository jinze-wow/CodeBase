#include <iostream>
using namespace std;

//�����ӡ
void P(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int quickSortPartition(int a[], int m, int n)
{
    int key = m;//m�����������n�����ұ�����i������߿�ʼ   3,4,2,1,5 i=0,j=4
    int j = n, i = m;
    int temp1, temp2;
    while (i != j)
    {
        while (a[j] > a[key] && i < j)//����������Ѱ�ҵ�һ��С��3���� i=0��j=3
        {
            --j;
        }
        if (i < j)
        {
            temp1 = a[j];//3,1����λ�ã�1,4,2,3,5
            a[j] = a[i];
            a[i] = temp1;
        }
        while ((a[i] < a[key]) && (i < j))//��������Ѱ�ҵ�һ������3���� 
        {
            ++i;
        }
        if (i < j)
        {
            temp2 = a[key];//3,4����λ��1,3,2,4,5  i=1 j=3
            a[key] = a[i];
            a[i] = temp2;
            return i;
        }
    }
  
}

void quickSort(int s[], int l, int r)
{
    //�������<�ҽ�������壬����˵�������źã�ֱ�ӷ���
    if (l >= r) {
        return;
    }

    // ���֣����ػ�׼��λ��
    int i = quickSortPartition(s, l, r);

    // �ݹ鴦�����������֣�i��Ϊ�ֽ�㣬���ù�i
    quickSort(s, l, i - 1);
    quickSort(s, i + 1, r);
}

int main()
{
    int m,i;
    cout << "��������Ҫ��������ݸ�����";
    cin >> m;
    int a[10];
    cout << "��������Ҫ��������ݣ�";
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }
    P(a, m);
    quickSort(a, 0, m-1);//���һ��������n-1
    P(a, m);
    return 0;
}

