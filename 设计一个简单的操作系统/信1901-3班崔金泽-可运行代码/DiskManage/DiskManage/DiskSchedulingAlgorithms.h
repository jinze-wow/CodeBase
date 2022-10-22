
#ifndef DiskSchedulingAlgorithms_h
#define DiskSchedulingAlgorithms_h
#include "DiskTrack.h"
#include <iostream>
#include <math.h>
using namespace std;

// MARK: - 先来先服务(FCFS)
void FCFS() {
    // 下一磁道号即原始数组顺序
    nextTrack = diskTrack;
    moveDistance.append(abs(diskTrack[0] - startTrack));
    for (int i = 1; i < diskTrack.length(); i++) {
        moveDistance.append(abs(diskTrack[i] - diskTrack[i - 1]));
    }
    // 输出表格
    printResultTable("FCFS");
    // 重置nextTrack数组
    nextTrack.clear();
    // 重置moveDistance数组
    moveDistance.clear();
}

// MARK: - 最短寻道时间优先(SSTF)
void SSTF() {
    // 复制磁道序列函数用于修改数组的操作, 避免修改原始数组
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // 当前磁道
    int currentTrack = startTrack;
    // 最短移动距离
    int shortestMoveDistance;
    // 最近磁道的下标 (这个初值0永远不会用到, 只是为了消除一个编译warning)
    int nearestTrack = 0;
    // 遍历整个序列
    for (int i = 0; i < diskTrack.length(); i++) {
        shortestMoveDistance = INT_MAX;
        for (int i = 0; i < tempArray.length(); i++) {
            // 当有待访问磁道号等于当前磁道号时
            if (tempArray[i] == currentTrack) {
                shortestMoveDistance = 0;
                nearestTrack = i;
                break;
            }
            if (abs(currentTrack - tempArray[i]) < shortestMoveDistance) {
                shortestMoveDistance = abs(currentTrack - tempArray[i]);
                nearestTrack = i;
            }
        }
        // 将当前移动距离加入移动距离数组
        moveDistance.append(shortestMoveDistance);
        // 更新当前磁道
        currentTrack = tempArray[nearestTrack];
        // 将当前磁道加入下一个磁道号数组
        nextTrack.append(currentTrack);
        // 移除当前磁道号, 便于下一次在数组中寻找最近磁道
        tempArray.remove(nearestTrack);
    }
    // 输出表格
    printResultTable("SSTF");
    // 重置nextTrack数组
    nextTrack.clear();
    // 重置moveDistance数组
    moveDistance.clear();
}

// MARK: - 扫描(SCAN)算法
void SCAN(HeadMovementDirection hmd) {
    // 复制磁道序列函数用于修改数组的操作, 避免修改原始数组
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // 将磁头当前磁道号加入进行升序排序
    tempArray.append(startTrack);
    tempArray.sort();
    // 如果磁头移动方向为从大到小, 则把升序数组逆置为降序数组
    if (hmd == bigToSmall) {
        tempArray.reverse();
    }
    // 从起始位置向后
    for (int i = tempArray.sequentialSearch(startTrack) + 1; i < tempArray.length(); i++) {
        nextTrack.append(tempArray[i]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    // 从最后磁道移动到起始点前一个磁道
    nextTrack.append(tempArray[tempArray.sequentialSearch(startTrack) - 1]);
    moveDistance.append(abs(tempArray[tempArray.length() - 1] - tempArray[tempArray.sequentialSearch(startTrack) - 1]));
    // 从起始点前一个磁道向磁道号减小方向移动
    for (int i = tempArray.sequentialSearch(startTrack) - 1; i > 0; i--) {
        nextTrack.append(tempArray[i - 1]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    if (hmd == smallToBig) {
        printResultTable("SCAN (small to big)");
    }
    else {
        printResultTable("SCAN (big to small)");
    }
    nextTrack.clear();
    moveDistance.clear();
}

// MARK: - 循环扫描(CSCAN)算法
void CSCAN(HeadMovementDirection hmd) {
    // 复制磁道序列函数用于修改数组的操作, 避免修改原始数组
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // 将磁头当前磁道号加入进行升序排序
    tempArray.append(startTrack);
    tempArray.sort();
    // 如果磁头移动方向为从大到小, 则把升序数组逆置为降序数组
    if (hmd == bigToSmall) {
        tempArray.reverse();
    }
    // 从起始位置延数组下标序号向后
    for (int i = tempArray.sequentialSearch(startTrack) + 1; i < tempArray.length(); i++) {
        nextTrack.append(tempArray[i]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    // 从最后磁道移动到第一个磁道
    nextTrack.append(tempArray[0]);
    moveDistance.append(abs(tempArray[tempArray.length() - 1] - tempArray[0]));
    // 从第一个磁道向磁道数组序号增加方向移动
    for (int i = 1; i < tempArray.sequentialSearch(startTrack); i++) {
        nextTrack.append(tempArray[i]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    if (hmd == smallToBig) {
        printResultTable("CSCAN (small to big)");
    }
    else {
        printResultTable("CSCAN (big to small)");
    }
    nextTrack.clear();
    moveDistance.clear();
}

#endif /* DiskSchedulingAlgorithms_h */