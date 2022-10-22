#include <iostream>
using namespace std;

//数组打印
void P(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int quickSortPartition(int a[], int m, int n)
{
    int key = m;//m是最左边数，n是最右边数，i从最左边开始   3,4,2,1,5 i=0,j=4
    int j = n, i = m;
    int temp1, temp2;
    while (i != j)
    {
        while (a[j] > a[key] && i < j)//从最右往左寻找第一个小于3的数 i=0，j=3
        {
            --j;
        }
        if (i < j)
        {
            temp1 = a[j];//3,1交换位置，1,4,2,3,5
            a[j] = a[i];
            a[i] = temp1;
        }
        while ((a[i] < a[key]) && (i < j))//从左往右寻找第一个大于3的数 
        {
            ++i;
        }
        if (i < j)
        {
            temp2 = a[key];//3,4交换位置1,3,2,4,5  i=1 j=3
            a[key] = a[i];
            a[i] = temp2;
            return i;
        }
    }
  
}

void quickSort(int s[], int l, int r)
{
    //数组左界<右界才有意义，否则说明都已排好，直接返回
    if (l >= r) {
        return;
    }

    // 划分，返回基准点位置
    int i = quickSortPartition(s, l, r);

    // 递归处理左右两部分，i处为分界点，不用管i
    quickSort(s, l, i - 1);
    quickSort(s, i + 1, r);
}

int main()
{
    int m,i;
    cout << "请输入想要输入的数据个数：";
    cin >> m;
    int a[10];
    cout << "请输入想要输入的数据：";
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }
    P(a, m);
    quickSort(a, 0, m-1);//最后一个参数是n-1
    P(a, m);
    return 0;
}

