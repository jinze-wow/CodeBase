#include<iostream>
using namespace std;
/*ʹ�ú���ģ�壬ʵ����������������������Сֵ��
����������Բ�ͬ�������ݽ��в��ԣ�ʵ����ʾʵ��������ʽʵ��������

*/

//����ģ��
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
    int intArray[] = { 1,2,3 };//int���������
    double doubleArray[] = { 1.1,1.2,1.3 };//double���������
    //���㳤��
    int intArrayLength, doubleArrayLength;
    intArrayLength = sizeof(intArray) / sizeof(int);
    doubleArrayLength = sizeof(doubleArray) / sizeof(double);


    cout << "int��Сֵ:" << GetMin<int>(intArray, intArrayLength) << endl;//��ʽ
    cout << "double����Сֵ:" << GetMin<double>(doubleArray, doubleArrayLength) << endl;
    return 0;
}