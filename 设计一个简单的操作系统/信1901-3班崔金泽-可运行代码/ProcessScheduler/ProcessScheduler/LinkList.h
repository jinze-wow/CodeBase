#pragma once
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node *pNext;
};
template <typename T>
class NodeList {
private:
    //ͷ�ڵ�
    Node<T> *first;
    //��ǰ���ݳ���
    int length;
    //�ȽϺ���
    int(*compare)(T& left, T& right);
public:
    //��ʼ��
    NodeList();
    //�������캯��
    NodeList(const NodeList<T>&);
    //����
    ~NodeList();
    //���룬����ʱ�Ƿ�����
    NodeList& Insert(int x, const T &value, const bool sort = false);
    //�Ƿ�Ϊ��
    bool IsEmpty() const;
    //��ȡ����
    int GetLength() const;
    //���ص�x��Ԫ��
    bool Find(int x, T &ret) const;
    //����������������
    int Search(const T& value) const;
    //ɾ����x������
    NodeList& Delete(const int x);
    //��ӡ��
    std::ostream& Print(std::ostream& out) const;
    //����
    NodeList& Sort();
    //����ϲ�
    NodeList& AddNodeList(const NodeList& Source, const bool sort = false);
    //���ñȽϺ���
    void SetCompareFunction(int(*function)(T& left, T&right));
};

//��ʼ��
template<typename T>
NodeList<T>::NodeList() {
    first = new Node<T>;
    first->pNext = nullptr;
    length = 0;
    compare = nullptr;
}

//�������캯��
template<typename T>
NodeList<T>::NodeList(const NodeList<T>& nodelist) {
    first = new Node<T>;
    first->pNext = nullptr;
    length = 0;
    compare = nullptr;
    AddNodeList(nodelist);
}

//����
template<typename T>
NodeList<T>::~NodeList() {
    while(first != nullptr) {
        Node<T> *p = first;
        first = first->pNext;
        //cout<<p<<endl;
        delete p;
        length--;
    }
}

//���룬����ʱ�Ƿ�����
template<typename T>
NodeList<T>& NodeList<T>::Insert(int x, const T& value, const bool sort) {
    if(x < 0 || x > length) {
        x = length;
    }
    Node<T> *p = first;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    Node<T> *newp = new Node<T>;
    newp->data = value;
    newp->pNext = p->pNext;
    p->pNext = newp;
    length++;
    if(sort) {
        Sort();
    }
    return *this;
}

//�Ƿ�Ϊ��
template<typename T>
bool NodeList<T>::IsEmpty() const {
    return length == 0 || first->pNext == nullptr;
}

//��ȡ����
template<typename T>
int NodeList<T>::GetLength() const {
    return length;
}

//���ص�x��Ԫ��
template<typename T>
bool NodeList<T>::Find(int x, T& ret) const {
    if(x < 0 || x > length - 1) {
        return false;
    }
    Node<T> *p = first->pNext;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    ret = p->data;
    return true;
}

//����������������
template<typename T>
int NodeList<T>::Search(const T& value) const {
    Node<T> *p = first->pNext;
    for(int i = 0; i < length && p != nullptr; i++, p = p->pNext) {
        if(compare(p->data, value) == 0) {
            return i;
        }
    }
    return -1;
}

//ɾ����x������
template<typename T>
NodeList<T>& NodeList<T>::Delete(const int x) {
    if(x < 0 || x > length - 1) {
        return *this;
    }
    Node<T> *p = first;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    Node<T> *temp = p->pNext;
    p->pNext = temp == nullptr ? nullptr : temp->pNext;
    delete temp;
    length--;
    return *this;
}

//��ӡ��
template<typename T>
std::ostream& NodeList<T>::Print(std::ostream& out) const {
    Node<T> *p = first->pNext;
    for(int i = 0; i < length && p != nullptr; i++, p = p->pNext) {
        out << p->data << '\n';
    }
    return out;
}

//����
template<typename T>
NodeList<T>& NodeList<T>::Sort() {
    Node<T> *p = first->pNext;
    bool finish = false;
    for(int i = 0; i < length - 1; i++) {
        finish = true;
        Node<T> *temp = p;
        for(int j = 0; j < length - 1 - i; j++) {
            if(compare(temp->data, temp->pNext->data) > 0) {
                T ii;
                ii = temp->data;
                temp->data = temp->pNext->data;
                temp->pNext->data = ii;
                finish = false;
            }
            temp = temp->pNext;
        }
        if(finish) {
            break;
        }
    }
    return *this;
}

//����ϲ�
template<typename T>
NodeList<T>& NodeList<T>::AddNodeList(const NodeList& Source, const bool sort) {
    T value;
    for(int i = 0; i < Source.length; i++) {
        Source.Find(i, value);
        this->Insert(this->length, value, false);
    }
    if(sort) {
        this->Sort();
    }
    return *this;
}

//���ñȽϺ���
template<typename T>
void NodeList<T>::SetCompareFunction(int(*function)(T& left, T& right)) {
    compare = function;
}
