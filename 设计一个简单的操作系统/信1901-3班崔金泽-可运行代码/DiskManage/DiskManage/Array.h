#include<bits/stdc++.h>
#ifndef Array_h
#define Array_h
#include <iostream>
using namespace std;

#define DEFAULTCAP 10

template <typename T>
class Array {
private:
    int size;//������ʵ����
    int capacity;//����Ŀռ��С
    void expand() {
        while (size >= capacity) {
            T* oldElem = elem;
            elem = new T[capacity *= 2];
            for (int i = 0; i < size; i++) {
                elem[i] = oldElem[i];
            }
            delete[] oldElem;
        }
    }//����
public:
    T* elem;//����

    Array();//���캯��������˳���
    Array(int s);//����˳���, �����ʼ�ռ�Ϊs
    Array(int a, int b, T* e);//���ڸ��ƵĹ��캯��, ��e�����[a, b)����Ϊ������
    int length() { return size; }
    void append(T e);
    void insert(T e, int p);//����ָ����ŵ�Ԫ�أ���Ԫ��e�������±�Ϊp��λ��
    T remove(int p);//ɾ��ָ�����Ԫ�أ����������ݱ���
    T operator [] (int i) { return elem[i]; }//ͨ���±��ȡ��Ԫ
    void clear();//����������ݲ��ջ��ڴ�ռ����·���

    void sort();//����ӿڣ����ʹ���������򷽷��е�һ��
    void mergingSort(int low, int high);//�鲢����
    void straightInsertionSort();//ֱ�Ӳ�������
    void binaryInsertionSort();//�۰��������
    void bubbleSort();//��������
    void simpleSelectionSort();//��ѡ������
    void heapSort();//������

    T getMin() { return getMin(0, size); }//��ȡ���������е���Сֵ
    T getMin(int low, int high);//������[i, j)�л�ȡ��Сֵ
    T getMax() { return getMax(0, size); }//��ȡ���������е����ֵ
    T getMax(int low, int high);//������[i, j)�л�ȡ���ֵ

    int search(T e);//���ҽӿڣ����ʹ�����в��ҷ����е�һ��
    int sequentialSearch(T e);//˳������Ƿ�������Ϊe��Ԫ�ز��������±�
    int reverseSearch(T e);//��������Ƿ�������Ϊe��Ԫ�ز��������±�
    int binarySearch(T e);//�۰�����Ƿ�������Ϊe��Ԫ�ز��������±�

    void reverse();//��Ԫ������
    void input();//����
    void output();//���

    void swap(T& e1, T& e2);//��������Ԫ�ص�ֵ
};



template <typename T>
Array<T> merge(Array<T> A1, Array<T> A2) {//�鲢��������˳���
    Array<T> A3;
    int i = 0, j = 0, k = 0;
    while (i < A1.length() && j < A2.length()) {//ֹͣѭ��������������һ��˳����Ѿ��ȽϽ�������һ��˳���Ϳ���ֱ�Ӱ�ʣ�ಿ�ֽ�����˳����
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
        for (; j < A2.length(); j++) {//��ʣ�ಿ��ֱ�����ӵ��±��
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
    if (p >= size) p = size;//���p���ڵ��ڳ��ȣ���������б�ĩβ
    for (int i = size - 1; i > p; i--) {//����ǰ��p��֮���Ԫ�����κ���һλ
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

// MARK: - �����㷨
template <typename T>
void Array<T>::sort() {
    switch (size % 4) {
    case 0: simpleSelectionSort();
    case 1: straightInsertionSort();
    case 2: binaryInsertionSort();
    case 3: bubbleSort();
    }
}

// ֱ�Ӳ�������
template <typename T>
void Array<T>::straightInsertionSort() {
    for (int i = 1; i < size; i++) {
        int j;
        if (elem[i] < elem[i - 1]) {
            elem[size] = elem[i];//elem[size]����ʱ�洢���ڱ�
            elem[i] = elem[i - 1];
            for (j = i - 2; elem[size] < elem[j] && j >= 0; j--) {
                elem[j + 1] = elem[j];
            }
            elem[j + 1] = elem[size];
        }
    }
}

// �۰��������
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

// ��������
template <typename T>
void Array<T>::bubbleSort() {
    bool sorted = false;//�б������������������ʱ��һ��������û�н��й�������¼�Ĳ���
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

// ��ѡ������
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

// MARK: - �����㷨
template <typename T>
int Array<T>::search(T e) {
    switch (size % 3) {
    case 0: return sequentialSearch(e);
    case 1: return reverseSearch(e);
    default: return binarySearch(e);
    }
}

// ˳�����
template <typename T>
int Array<T>::sequentialSearch(T e) {
    for (int i = 0; i < size; i++) {
        if (elem[i] == e)
            return i;
    }
    return -1;
}

// �������
template <typename T>
int Array<T>::reverseSearch(T e) {
    for (int i = size - 1; i >= 0; i--) {
        if (elem[i] == e)
            return i;
    }
    return -1;
}

// �۰����
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

// ת��
template <typename T>
void Array<T>::reverse() {
    for (int i = 0; i < size / 2; i++) {
        swap(elem[i], elem[size - i - 1]);
    }
}

template <typename T>
void Array<T>::input() {
    cout << "����Ԫ�ظ���: ";
    cin >> size;
    expand();//����Ƿ���Ҫ����
    cout << "����Ԫ��: ";
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