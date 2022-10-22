
#ifndef DiskSchedulingAlgorithms_h
#define DiskSchedulingAlgorithms_h
#include "DiskTrack.h"
#include <iostream>
#include <math.h>
using namespace std;

// MARK: - �����ȷ���(FCFS)
void FCFS() {
    // ��һ�ŵ��ż�ԭʼ����˳��
    nextTrack = diskTrack;
    moveDistance.append(abs(diskTrack[0] - startTrack));
    for (int i = 1; i < diskTrack.length(); i++) {
        moveDistance.append(abs(diskTrack[i] - diskTrack[i - 1]));
    }
    // ������
    printResultTable("FCFS");
    // ����nextTrack����
    nextTrack.clear();
    // ����moveDistance����
    moveDistance.clear();
}

// MARK: - ���Ѱ��ʱ������(SSTF)
void SSTF() {
    // ���ƴŵ����к��������޸�����Ĳ���, �����޸�ԭʼ����
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // ��ǰ�ŵ�
    int currentTrack = startTrack;
    // ����ƶ�����
    int shortestMoveDistance;
    // ����ŵ����±� (�����ֵ0��Զ�����õ�, ֻ��Ϊ������һ������warning)
    int nearestTrack = 0;
    // ������������
    for (int i = 0; i < diskTrack.length(); i++) {
        shortestMoveDistance = INT_MAX;
        for (int i = 0; i < tempArray.length(); i++) {
            // ���д����ʴŵ��ŵ��ڵ�ǰ�ŵ���ʱ
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
        // ����ǰ�ƶ���������ƶ���������
        moveDistance.append(shortestMoveDistance);
        // ���µ�ǰ�ŵ�
        currentTrack = tempArray[nearestTrack];
        // ����ǰ�ŵ�������һ���ŵ�������
        nextTrack.append(currentTrack);
        // �Ƴ���ǰ�ŵ���, ������һ����������Ѱ������ŵ�
        tempArray.remove(nearestTrack);
    }
    // ������
    printResultTable("SSTF");
    // ����nextTrack����
    nextTrack.clear();
    // ����moveDistance����
    moveDistance.clear();
}

// MARK: - ɨ��(SCAN)�㷨
void SCAN(HeadMovementDirection hmd) {
    // ���ƴŵ����к��������޸�����Ĳ���, �����޸�ԭʼ����
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // ����ͷ��ǰ�ŵ��ż��������������
    tempArray.append(startTrack);
    tempArray.sort();
    // �����ͷ�ƶ�����Ϊ�Ӵ�С, ���������������Ϊ��������
    if (hmd == bigToSmall) {
        tempArray.reverse();
    }
    // ����ʼλ�����
    for (int i = tempArray.sequentialSearch(startTrack) + 1; i < tempArray.length(); i++) {
        nextTrack.append(tempArray[i]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    // �����ŵ��ƶ�����ʼ��ǰһ���ŵ�
    nextTrack.append(tempArray[tempArray.sequentialSearch(startTrack) - 1]);
    moveDistance.append(abs(tempArray[tempArray.length() - 1] - tempArray[tempArray.sequentialSearch(startTrack) - 1]));
    // ����ʼ��ǰһ���ŵ���ŵ��ż�С�����ƶ�
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

// MARK: - ѭ��ɨ��(CSCAN)�㷨
void CSCAN(HeadMovementDirection hmd) {
    // ���ƴŵ����к��������޸�����Ĳ���, �����޸�ԭʼ����
    Array<int> tempArray(0, diskTrack.length(), diskTrack.elem);
    // ����ͷ��ǰ�ŵ��ż��������������
    tempArray.append(startTrack);
    tempArray.sort();
    // �����ͷ�ƶ�����Ϊ�Ӵ�С, ���������������Ϊ��������
    if (hmd == bigToSmall) {
        tempArray.reverse();
    }
    // ����ʼλ���������±�������
    for (int i = tempArray.sequentialSearch(startTrack) + 1; i < tempArray.length(); i++) {
        nextTrack.append(tempArray[i]);
        moveDistance.append(abs(tempArray[i] - tempArray[i - 1]));
    }
    // �����ŵ��ƶ�����һ���ŵ�
    nextTrack.append(tempArray[0]);
    moveDistance.append(abs(tempArray[tempArray.length() - 1] - tempArray[0]));
    // �ӵ�һ���ŵ���ŵ�����������ӷ����ƶ�
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