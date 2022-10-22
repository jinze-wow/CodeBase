//
//  main.cpp
//  DiskSchedulingAlgorithms
//
//  Created by cjz on 2022/6/30.
//

#include <iostream>
#include "DiskTrack.h"
#include "DiskSchedulingAlgorithms.h"
using namespace std;

int main() {
    startTrack = 100;

    diskTrack.append(78);
    diskTrack.append(30);
    diskTrack.append(9);
    diskTrack.append(15);
    diskTrack.append(102);
    diskTrack.append(140);
    diskTrack.append(156);
    diskTrack.append(54);
    diskTrack.append(45);
    diskTrack.append(127);

    // ע�����´����ԴӼ�����������(ʹ��ʱ��Ҫע���Ϸ�����)
    /*
    cout << "�����ʼλ��: ";
    cin >> startTrack;
    cout << "����ŵ���: ";
    int n;
    cin >> n;
    cout << "��������ŵ����: ";
    int m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        diskTrack.append(m);
    }
    */

    SSTF();
    FCFS();
    SCAN(bigToSmall);
    SCAN(smallToBig);
    CSCAN(bigToSmall);
    CSCAN(smallToBig);

    return 0;
}