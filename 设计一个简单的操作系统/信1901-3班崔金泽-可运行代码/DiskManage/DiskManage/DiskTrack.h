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

// �ŵ�������������
Array<int> diskTrack;
// �����ʵ���һ���ŵ�����
Array<int> nextTrack;
// Ѱ����������
Array<int> moveDistance;

// ��ʼ�ŵ���
int startTrack;

// ��ͷ�ƶ�����
enum HeadMovementDirection {
    smallToBig,
    bigToSmall
};

// ƽ��Ѱ������
float averageSeekLength() {
    int total = 0;
    for (int i = 0; i < moveDistance.length(); i++) {
        total += moveDistance[i];
    }
    return float(total) / float(diskTrack.length());
}

// ���������
void printResultTable(string algorithmName) {
    // �����ͷ
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
    // �����
    for (int i = 0; i < nextTrack.length(); i++) {
        // ��������ʵ���һ�ŵ���
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
            cout << "|���֧��3λ��   ";
        }
        // ����ƶ�����
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
            cout << "  ���֧��3λ��|" << endl;
        }
        cout << "|--------------+-------------|" << endl;
    }
    // ���ƽ��Ѱ������
    printf("|average seek distance: %.2f|\n", averageSeekLength());
    cout << "+----------------------------+" << endl;
}

#endif /* DiskTrack_h */