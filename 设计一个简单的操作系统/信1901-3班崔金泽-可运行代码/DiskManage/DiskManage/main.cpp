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

    // 注释以下代码以从键盘输入数据(使用时需要注释上方内容)
    /*
    cout << "输入初始位置: ";
    cin >> startTrack;
    cout << "输入磁道数: ";
    int n;
    cin >> n;
    cout << "依次输入磁道序号: ";
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