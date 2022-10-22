//https://blog.csdn.net/master_hunter/article/details/115496923
#include <iostream>
#define sourceNum 3//源数量
#define processNum 5//处理进程数量
typedef unsigned int NUM;//把无符号整形变量设置为NUM
using namespace std;

class bankAlgorithm {
    //封装后的类
private:
    NUM ava[sourceNum] = { 3,3,2 };//availble数组
    NUM work[sourceNum] = { 0 };//work数组
    NUM max[processNum][sourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };//max数组
    NUM allocation[processNum][sourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,2,1},{0,0,2} };//allocation数组
    NUM need[processNum][sourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };//need数组
    NUM request[4] = { 0 };//request数组
    bool finish[processNum] = { 0 };//标志是否完成数组
public:
    bool sendRequest();//发送request请求
    bool askForSafetyCheck();//请求安全性检查
    void display();//展示函数
};
    /*
    设进程I提出请求Request[N]，则银行家算法按如下规则进行判断

    1.如果Request[N]<= Need [I, N]，则转(2)；否则，出错
    2.如果Request[N]<= Available，则转(3)；否则，出错
    3.系统试探分配资源，修改相关数据：
    Available = Available -Request
    Allocation = Allocation +Request
    Need= Need - Request
    4.系统执行安全性检查，如安全，则分配成立；否则试探险性分配作废，系统恢复原状，进程等待
    */
bool bankAlgorithm::sendRequest() {
    cout << "Please insert the request vector, 1 for process,2-4 for request num\n";
    //输入数据
    cin >> request[0] >> request[1] >> request[2] >> request[3];
    cout << "Now checking the request vector...\n";
    //检查need数组
    if (need[request[0]][0] >= request[1] && need[request[0]][1] >= request[2] && need[request[0]][2] >= request[3]) {
        //检查availble数组
        if (ava[0] >= request[1] && ava[1] >= request[2] && ava[2] >= request[3]) {
            cout << "Now checking the safety...\n";
            NUM oldAvail_0 = ava[0];
            NUM oldAvail_1 = ava[1];
            NUM oldAvail_2 = ava[2];
            //检查allocation数组
            NUM oldAllocation_0 = allocation[request[0]][0];
            NUM oldAllocation_1 = allocation[request[0]][1];
            NUM oldAllocation_2 = allocation[request[0]][2];
            //以下为改变老数组的值
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
            /*安全性检查设置两个工作向量Work= Available；Finish[M]=False从进程集合中找到一个满足下述条件的进程
            Finish[i]=False，Need <=Work
            如找到，设进程获得资源，可顺利执行，直至完成，从而释放资源 Work=Work+ Allocation Finish=True Go To 2
            如所有的进程Finish[M]=true，则表示安全；否则系统不安全*/
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
    //安全性检查函数
    for (int i = 0; i < processNum; i++) { finish[i] = false; }//初始化完成数组
    int k = processNum - 1;
    bool key = true;
    //初始化work向量
    for (int i = 0; i < sourceNum; i++) {
        work[i] = ava[i];
    }
    //找到一个能满足finish==false，need《=work的进程，该进程获得资源后可顺利执行，直到释放自己的所有资源
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
    //只有当所有进程的finish都为true，系统才处于安全状态
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
    //展示函数
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