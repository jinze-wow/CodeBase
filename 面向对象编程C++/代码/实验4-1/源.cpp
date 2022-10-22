#include<iostream>
using namespace std;
/*使用函数模板，实现求两个数，三个数的最小值。
主函数中针对不同类型数据进行测试（实现显示实例化和隐式实例化）。

*/

//函数模板
template<typename T>
T GetMin(T Array[], int Length) {
    T temp = Array[0];
    for (int i = 0; i < Length; i++) {
        if (temp > Array[i]) {
            temp = Array[i];
        }
    }
    return temp;
}

int main() {
    int intArray[] = { 1,2,3 };//int型数组测试
    double doubleArray[] = { 1.1,1.2,1.3 };//double型数组测试
    //计算长度
    int intArrayLength, doubleArrayLength;
    intArrayLength = sizeof(intArray) / sizeof(int);
    doubleArrayLength = sizeof(doubleArray) / sizeof(double);


    cout << "int最小值:" << GetMin<int>(intArray, intArrayLength) << endl;//显式
    cout << "double型最小值:" << GetMin<double>(doubleArray, doubleArrayLength) << endl;
    return 0;
}