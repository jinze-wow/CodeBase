//
//  DiskTrack.h
//  DiskSchedulingAlgorithms
//
//  Created by cjz on 2022/6/30.
//

#ifndef DiskTrack_h
#define DiskTrack_h
#include <iostream>
#include "Array.h"
using namespace std;

// 磁道访问序列数组
Array<int> diskTrack;
// 被访问的下一个磁道数组
Array<int> nextTrack;
// 寻道距离数组
Array<int> moveDistance;

// 开始磁道号
int startTrack;

// 磁头移动方向
enum HeadMovementDirection {
    smallToBig,
    bigToSmall
};

// 平均寻道长度
float averageSeekLength() {
    int total = 0;
    for (int i = 0; i < moveDistance.length(); i++) {
        total += moveDistance[i];
    }
    return float(total) / float(diskTrack.length());
}

// 输出结果表格
void printResultTable(string algorithmName) {
    // 输出表头
    cout << "+----------------------------+" << endl;
    if (algorithmName.length() == 4) {
        cout << "|            " << algorithmName << "            |" << endl;
    }
    else if (algorithmName.length() == 5) {
        cout << "|            " << algorithmName << "           |" << endl;
    }
    else if (algorithmName.length() == 20) {
        cout << "|    " << algorithmName << "    |" << endl;
    }
    else if (algorithmName.length() == 19) {
        cout << "|     " << algorithmName << "    |" << endl;
    }
    cout << "|--------------+-------------|" << endl;
    cout << "|next disktrack|move distance|" << endl;
    cout << "|--------------+-------------|" << endl;
    // 输出表
    for (int i = 0; i < nextTrack.length(); i++) {
        // 输出被访问的下一磁道号
        if (0 <= nextTrack[i] && nextTrack[i] <= 9) {
            printf("|      %d       |", nextTrack[i]);
        }
        else if (10 <= nextTrack[i] && nextTrack[i] <= 99) {
            printf("|      %d      |", nextTrack[i]);
        }
        else if (100 <= nextTrack[i] && nextTrack[i] <= 999) {
            printf("|      %d     |", nextTrack[i]);
        }
        else {
            cout << "|最大支持3位数   ";
        }
        // 输出移动距离
        if (0 <= moveDistance[i] && moveDistance[i] <= 9) {
            printf("      %d      |\n", moveDistance[i]);
        }
        else if (10 <= moveDistance[i] && moveDistance[i] <= 99) {
            printf("      %d     |\n", moveDistance[i]);
        }
        else if (100 <= moveDistance[i] && moveDistance[i] <= 999) {
            printf("      %d    |\n", moveDistance[i]);
        }
        else {
            cout << "  最大支持3位数|" << endl;
        }
        cout << "|--------------+-------------|" << endl;
    }
    // 输出平均寻道长度
    printf("|average seek distance: %.2f|\n", averageSeekLength());
    cout << "+----------------------------+" << endl;
}

#endif /* DiskTrack_h */