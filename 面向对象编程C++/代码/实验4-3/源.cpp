/*��дһ������ʹ����ģ�������Ԫ�ؽ��в��Һ���ͣ����������ģ�壬
Ȼ��ֱ�ʵ����Ϊint�ͺ�double�͵����������࣬
���ֱ������������˫�������������Ҫ��Ĳ���*/
//�޽���2021/5/15
#include<iostream>
using namespace std;
const int SIZE = 100;

 // Array -> ģ����(��ģ��)  
 template < class Type>class Array {
private:
    int l, z;
    Type a[SIZE];
 public:
     Array(Type * b, int n)
     {
         int i;
         l = n;
         cout << "���캯��: " << endl;        
         for (i = 0; i < l; i++)
         {
             a[i] = b[i];
            
             cout << a[i] << " ";
         }
         cout << endl;
     }
     void find(Type t);
     void sum();

};

template < class Type>
 void Array<Type>::find(Type t) {
     int e = 0;
     int flag = 0;            // 0��ʾδ�ҵ� 
     for (int i = 0; i < l; i++)
     {
         if (a[i] == t)
         {
             flag = 1;
             cout << "�ǵ�" << i + 1 << "��Ԫ��" << endl;
             e = i;
             break;
        }
	 }
     // �ж��Ƿ�δ�ҵ���Ԫ�� 
    if (flag == 0)
     {
       cout << "δ�ҵ���Ԫ��" << endl;
     }
}
 template < class Type>
 void Array<Type>::sum() {
	     int i;
	     Type res = 0;            // resӦ�ó�ʼ��        
	     for (i = 0; i < l; i++)
		     {
		         res += a[i];
		     }
		     cout << "�����Ϊ��" << res << endl;
	
}
 int main()
 {
	 int i, x, y, q;
     double p;
	  // ������ʼ���� 
     cout << "������������������Ԫ�ظ���: " << endl;
     cin >> x >> y;
     int* a;
     double* b;
     a = new int[x];
     b = new double[y];
     cout << "������int������Ԫ��" << endl;
     for (i = 0; i < x; i++)
     {
         cin >> a[i];
     }
     cout << "������double������Ԫ��" << endl;
     for (i = 0; i < y; i++)
     {
         cin >> b[i];
     }

     // �ó�ʼ�����ʼ�� ģ�������� 
     Array<int> c(a, x);
     Array<double> d(b, y);

     // int�����鹦��չʾ 
     cout << "int �����飺" << endl;
     cout << "������Ҫ���ҵ�Ԫ��: ";
     cin >> q;
     c.find(q);
    cout << "���:" << endl;
     c.sum();
     // double�����鹦��չʾ 
     cout << "double �����飺" << endl;

     cout << "������Ҫ���ҵ�Ԫ��: ";
     cin >> p;
     c.find(p);
     cout << "���:" << endl;
     d.sum();
    // ������� 
		     delete[]a;
	     delete[]b;
	    return 0;
 }
