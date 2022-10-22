//https://blog.csdn.net/master_hunter/article/details/115496923
#include <iostream>
#define sourceNum 3//Դ����
#define processNum 5//�����������
typedef unsigned int NUM;//���޷������α�������ΪNUM
using namespace std;

class bankAlgorithm {
    //��װ�����
private:
    NUM ava[sourceNum] = { 3,3,2 };//availble����
    NUM work[sourceNum] = { 0 };//work����
    NUM max[processNum][sourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };//max����
    NUM allocation[processNum][sourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,2,1},{0,0,2} };//allocation����
    NUM need[processNum][sourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };//need����
    NUM request[4] = { 0 };//request����
    bool finish[processNum] = { 0 };//��־�Ƿ��������
public:
    bool sendRequest();//����request����
    bool askForSafetyCheck();//����ȫ�Լ��
    void display();//չʾ����
};
    /*
    �����I�������Request[N]�������м��㷨�����¹�������ж�

    1.���Request[N]<= Need [I, N]����ת(2)�����򣬳���
    2.���Request[N]<= Available����ת(3)�����򣬳���
    3.ϵͳ��̽������Դ���޸�������ݣ�
    Available = Available -Request
    Allocation = Allocation +Request
    Need= Need - Request
    4.ϵͳִ�а�ȫ�Լ�飬�簲ȫ������������������̽���Է������ϣ�ϵͳ�ָ�ԭ״�����̵ȴ�
    */
bool bankAlgorithm::sendRequest() {
    cout << "Please insert the request vector, 1 for process,2-4 for request num\n";
    //��������
    cin >> request[0] >> request[1] >> request[2] >> request[3];
    cout << "Now checking the request vector...\n";
    //���need����
    if (need[request[0]][0] >= request[1] && need[request[0]][1] >= request[2] && need[request[0]][2] >= request[3]) {
        //���availble����
        if (ava[0] >= request[1] && ava[1] >= request[2] && ava[2] >= request[3]) {
            cout << "Now checking the safety...\n";
            NUM oldAvail_0 = ava[0];
            NUM oldAvail_1 = ava[1];
            NUM oldAvail_2 = ava[2];
            //���allocation����
            NUM oldAllocation_0 = allocation[request[0]][0];
            NUM oldAllocation_1 = allocation[request[0]][1];
            NUM oldAllocation_2 = allocation[request[0]][2];
            //����Ϊ�ı��������ֵ
            NUM oldNeed_0 = need[request[0]][0];
            NUM oldNeed_1 = need[request[0]][1];
            NUM oldNeed_2 = need[request[0]][2];
            ava[0] = ava[0] - request[1];
            ava[1] = ava[1] - request[2];
            ava[2] = ava[2] - request[3];
            allocation[request[0]][0] = allocation[request[0]][0] + request[1];
            allocation[request[0]][1] = allocation[request[0]][1] + request[2];
            allocation[request[0]][2] = allocation[request[0]][2] + request[3];
            need[request[0]][0] = need[request[0]][0] - request[1];
            need[request[0]][1] = need[request[0]][1] - request[2];
            need[request[0]][2] = need[request[0]][2] - request[3];
            /*��ȫ�Լ������������������Work= Available��Finish[M]=False�ӽ��̼������ҵ�һ���������������Ľ���
            Finish[i]=False��Need <=Work
            ���ҵ�������̻����Դ����˳��ִ�У�ֱ����ɣ��Ӷ��ͷ���Դ Work=Work+ Allocation Finish=True Go To 2
            �����еĽ���Finish[M]=true�����ʾ��ȫ������ϵͳ����ȫ*/
            if (!askForSafetyCheck()) {
                ava[0] = oldAvail_0;
                ava[1] = oldAvail_1;
                ava[2] = oldAvail_2;
                allocation[request[0]][0] = oldAllocation_0;
                allocation[request[0]][1] = oldAllocation_1;
                allocation[request[0]][2] = oldAllocation_2;
                need[request[0]][0] = oldNeed_0;
                need[request[0]][1] = oldNeed_1;
                need[request[0]][2] = oldNeed_2;
                cout << "False! Failing the safety test\n";
                return false;
            }
            else {
                display();
            }
        }
        else {
            cout << "False! The request num is bigger than availble num\n";
            return false;
        }
    }
    else {
        cout << "False! The request num is bigger than need num\n";
        return false;
    }
    return true;
}

bool bankAlgorithm::askForSafetyCheck() {
    //��ȫ�Լ�麯��
    for (int i = 0; i < processNum; i++) { finish[i] = false; }//��ʼ���������
    int k = processNum - 1;
    bool key = true;
    //��ʼ��work����
    for (int i = 0; i < sourceNum; i++) {
        work[i] = ava[i];
    }
    //�ҵ�һ��������finish==false��need��=work�Ľ��̣��ý��̻����Դ���˳��ִ�У�ֱ���ͷ��Լ���������Դ
    while (k >= 0) {
        if (finish[k] == false) {
            for (int i = 0; i < sourceNum; i++) {
                if (need[k][i] > work[i]) {
                    key = false;
                }
            }
            if (key) {
                for (int i = 0; i < sourceNum; i++) {
                    work[i] = work[i] + allocation[k][i];
                }
                finish[k] = true;
                k = processNum;
            }
            key = true;
        }
        k--;
    }
    //ֻ�е����н��̵�finish��Ϊtrue��ϵͳ�Ŵ��ڰ�ȫ״̬
    if ((finish[0]) && (finish[1]) && (finish[2]) && (finish[3])) {
        return true;
    }
    else {
        cout << "No. ";
        if (!finish[0]) {
            cout << "1 ";
        }if (!finish[1]) {
            cout << "2 ";
        }if (!finish[2]) {
            cout << "3 ";
        }if (!finish[3]) {
            cout << "4 ";
        }
        cout << "process can not pass the vector security test\n";
    }
    return false;
}

void bankAlgorithm::display() {
    //չʾ����
    cout << "==================================\n";
    cout << "max\n";
    for (int i = 0; i < processNum; i++) {
        for (int j = 0; j < sourceNum; j++) {
            cout << max[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "allocation\n";
    for (int i = 0; i < processNum; i++) {
        for (int j = 0; j < sourceNum; j++) {
            cout << allocation[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "need\n";
    for (int i = 0; i < processNum; i++) {
        for (int j = 0; j < sourceNum; j++) {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "availble\n";
    for (int i = 0; i < sourceNum; i++) {
        cout << ava[i] << " ";
    }
    cout << "\nwork\n";
    for (int i = 0; i < sourceNum; i++) {
        cout << work[i] << " ";
    }
    cout << "\n";
    cout << "==================================\n";
}

int main(int argc, const char* argv[]) {
    bankAlgorithm bank;
    cout << "=================Welcome to the bank algorithm=================\n";
    while (true) {
        bank.sendRequest();
    }
    return 0;
}