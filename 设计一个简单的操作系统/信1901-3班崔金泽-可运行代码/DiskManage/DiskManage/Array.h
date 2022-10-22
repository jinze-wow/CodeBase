#include<bits/stdc++.h>
#ifndef Array_h
#define Array_h
#include <iostream>
using namespace std;

#define DEFAULTCAP 10

template <typename T>
class Array {
private:
    int size;//数组真实长度
    int capacity;//申请的空间大小
    void expand() {
        while (size >= capacity) {
            T* oldElem = elem;
            elem = new T[capacity *= 2];
            for (int i = 0; i < size; i++) {
                elem[i] = oldElem[i];
            }
            delete[] oldElem;
        }
    }//扩容
public:
    T* elem;//数据

    Array();//构造函数，创建顺序表
    Array(int s);//创建顺序表, 申请初始空间为s
    Array(int a, int b, T* e);//基于复制的构造函数, 将e数组的[a, b)复制为新数组
    int length() { return size; }
    void append(T e);
    void insert(T e, int p);//插入指定序号的元素，将元素e插入在下标为p的位置
    T remove(int p);//删除指定序号元素，返回其数据备份
    T operator [] (int i) { return elem[i]; }//通过下标读取表元
    void clear();//清除所有数据并收回内存空间重新分配

    void sort();//排序接口，随机使用下列排序方法中的一种
    void mergingSort(int low, int high);//归并排序
    void straightInsertionSort();//直接插入排序
    void binaryInsertionSort();//折半插入排序
    void bubbleSort();//起泡排序
    void simpleSelectionSort();//简单选择排序
    void heapSort();//堆排序

    T getMin() { return getMin(0, size); }//获取整个数组中的最小值
    T getMin(int low, int high);//在区间[i, j)中获取最小值
    T getMax() { return getMax(0, size); }//获取整个数组中的最大值
    T getMax(int low, int high);//在区间[i, j)中获取最大值

    int search(T e);//查找接口，随机使用下列查找方法中的一种
    int sequentialSearch(T e);//顺序查找是否有数据为e的元素并返回其下标
    int reverseSearch(T e);//倒序查找是否有数据为e的元素并返回其下标
    int binarySearch(T e);//折半查找是否有数据为e的元素并返回其下标

    void reverse();//表元素逆置
    void input();//输入
    void output();//输出

    void swap(T& e1, T& e2);//交换两个元素的值
};



template <typename T>
Array<T> merge(Array<T> A1, Array<T> A2) {//归并两个有序顺序表
    Array<T> A3;
    int i = 0, j = 0, k = 0;
    while (i < A1.length() && j < A2.length()) {//停止循环的条件是其中一个顺序表已经比较结束，另一个顺序表就可以直接把剩余部分接在新顺序表后
        if (A1[i] <= A2[j]) {
            A3.insert(A1[i], k++);
            i++;
        }
        else {
            A3.insert(A2[j], k++);
            j++;
        }
    }
    if (i == A1.length()) {
        for (; j < A2.length(); j++) {//将剩余部分直接连接到新表后
            A3.insert(A2[j], k++);
        }
    }
    else {
        for (; i < A1.length(); i++) {
            A3.insert(A1[i], k++);
        }
    }
    return A3;
}

template <typename T>
Array<T>::Array() {
    size = 0;
    capacity = DEFAULTCAP;
    elem = new T[capacity];
}

template <typename T>
Array<T>::Array(int s) {
    size = s;
    capacity = size;
    elem = new T[capacity];
}

template <typename T>
Array<T>::Array(int a, int b, T* e) {
    size = b - a;
    capacity = size;
    elem = new T[capacity];
    for (int i = 0; i < size; i++) {
        elem[i] = e[a + i];
    }
}

template <typename T>
void Array<T>::append(T e) {
    expand();
    elem[size] = e;
    size++;
}

template <typename T>
void Array<T>::insert(T e, int p) {
    expand();
    size++;
    if (p >= size) p = size;//如果p大于等于长度，则插入在列表末尾
    for (int i = size - 1; i > p; i--) {//将当前在p及之后的元素依次后移一位
        elem[i] = elem[i - 1];
    }
    elem[p] = e;
}

template <typename T>
T Array<T>::remove(int p) {
    T backup = elem[p];
    for (int i = p; i < size; i++) {
        elem[i] = elem[i + 1];
    }
    size--;
    return backup;
}

template <typename T>
void Array<T>::clear() {
    size = 0;
    capacity = DEFAULTCAP;
    elem = new T[capacity];
}

// MARK: - 排序算法
template <typename T>
void Array<T>::sort() {
    switch (size % 4) {
    case 0: simpleSelectionSort();
    case 1: straightInsertionSort();
    case 2: binaryInsertionSort();
    case 3: bubbleSort();
    }
}

// 直接插入排序
template <typename T>
void Array<T>::straightInsertionSort() {
    for (int i = 1; i < size; i++) {
        int j;
        if (elem[i] < elem[i - 1]) {
            elem[size] = elem[i];//elem[size]作临时存储的哨兵
            elem[i] = elem[i - 1];
            for (j = i - 2; elem[size] < elem[j] && j >= 0; j--) {
                elem[j + 1] = elem[j];
            }
            elem[j + 1] = elem[size];
        }
    }
}

// 折半插入排序
template <typename T>
void Array<T>::binaryInsertionSort() {
    for (int i = 1; i < size; i++) {
        int j;
        if (elem[i] < elem[i - 1]) {
            elem[size] = elem[i];
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (elem[size] < elem[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
                elem[j + 1] = elem[j];
            elem[high + 1] = elem[size];
        }
    }
}

// 起泡排序
template <typename T>
void Array<T>::bubbleSort() {
    bool sorted = false;//判别起泡排序结束的条件时在一趟排序中没有进行过交换记录的操作
    while (!sorted) {
        sorted = true;
        for (int j = 1; j < size; j++) {
            if (elem[j] < elem[j - 1]) {
                sorted = false;
                swap(elem[j], elem[j - 1]);
            }
        }
    }
}

// 简单选择排序
template <typename T>
void Array<T>::simpleSelectionSort() {
    for (int i = 0; i < size; i++) {
        if (elem[i] != getMin(i, size)) {
            swap(elem[i], elem[binarySearch(getMin(i, size))]);
        }
    }
}

template <typename T>
T Array<T>::getMin(int low, int high) {
    T min = elem[low];
    for (int i = low + 1; i < high; i++)
        if (elem[i] < min)
            min = elem[i];
    return min;
    /*
     sort();
     return elem[i];
     */
}

template <typename T>
T Array<T>::getMax(int low, int high) {
    T max = elem[low];
    for (int i = low + 1; i < high; i++)
        if (elem[i] > max)
            max = elem[i];
    return max;
    /*
     sort();
     return elem[j - 1];
     */
}

// MARK: - 查找算法
template <typename T>
int Array<T>::search(T e) {
    switch (size % 3) {
    case 0: return sequentialSearch(e);
    case 1: return reverseSearch(e);
    default: return binarySearch(e);
    }
}

// 顺序查找
template <typename T>
int Array<T>::sequentialSearch(T e) {
    for (int i = 0; i < size; i++) {
        if (elem[i] == e)
            return i;
    }
    return -1;
}

// 倒序查找
template <typename T>
int Array<T>::reverseSearch(T e) {
    for (int i = size - 1; i >= 0; i--) {
        if (elem[i] == e)
            return i;
    }
    return -1;
}

// 折半查找
template <typename T>
int Array<T>::binarySearch(T e) {
    sort();
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    while (low <= high && elem[mid] != e) {
        if (elem[mid] > e) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (elem[mid] == e)
        return mid;
    else
        return -1;
}

// 转置
template <typename T>
void Array<T>::reverse() {
    for (int i = 0; i < size / 2; i++) {
        swap(elem[i], elem[size - i - 1]);
    }
}

template <typename T>
void Array<T>::input() {
    cout << "输入元素个数: ";
    cin >> size;
    expand();//检查是否需要扩容
    cout << "输入元素: ";
    for (int i = 0; i < size; i++)
        cin >> elem[i];
}

template <typename T>
void Array<T>::output() {
    for (int i = 0; i < size; i++)
        cout << elem[i] << " ";
    cout << endl;
}

template <typename T>
void Array<T>::swap(T& e1, T& e2) {
    T t;
    t = e1;
    e1 = e2;
    e2 = t;
}

#endif /* Array_h */1