/*编写一个程序，使用类模板对数组元素进行查找和求和，设计数组类模板，
然后分别实例化为int型和double型的两个数组类，
最后分别对整型数组与双精度数组完成所要求的操作*/
//崔金泽2021/5/15
#include<iostream>
using namespace std;
const int SIZE = 100;

 // Array -> 模板类(类模板)  
 template < class Type>class Array {
private:
    int l, z;
    Type a[SIZE];
 public:
     Array(Type * b, int n)
     {
         int i;
         l = n;
         cout << "构造函数: " << endl;        
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
     int flag = 0;            // 0表示未找到 
     for (int i = 0; i < l; i++)
     {
         if (a[i] == t)
         {
             flag = 1;
             cout << "是第" << i + 1 << "个元素" << endl;
             e = i;
             break;
        }
	 }
     // 判断是否未找到该元素 
    if (flag == 0)
     {
       cout << "未找到该元素" << endl;
     }
}
 template < class Type>
 void Array<Type>::sum() {
	     int i;
	     Type res = 0;            // res应该初始化        
	     for (i = 0; i < l; i++)
		     {
		         res += a[i];
		     }
		     cout << "数组和为：" << res << endl;
	
}
 int main()
 {
	 int i, x, y, q;
     double p;
	  // 构建初始数组 
     cout << "请输入两种类型数组元素个数: " << endl;
     cin >> x >> y;
     int* a;
     double* b;
     a = new int[x];
     b = new double[y];
     cout << "请输入int型数组元素" << endl;
     for (i = 0; i < x; i++)
     {
         cin >> a[i];
     }
     cout << "请输入double型数组元素" << endl;
     for (i = 0; i < y; i++)
     {
         cin >> b[i];
     }

     // 用初始数组初始化 模板类数组 
     Array<int> c(a, x);
     Array<double> d(b, y);

     // int型数组功能展示 
     cout << "int 型数组：" << endl;
     cout << "请输入要查找的元素: ";
     cin >> q;
     c.find(q);
    cout << "求和:" << endl;
     c.sum();
     // double型数组功能展示 
     cout << "double 型数组：" << endl;

     cout << "请输入要查找的元素: ";
     cin >> p;
     c.find(p);
     cout << "求和:" << endl;
     d.sum();
    // 清除数据 
		     delete[]a;
	     delete[]b;
	    return 0;
 }
