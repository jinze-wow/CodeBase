#include <iostream>
#include <fstream>
#include "Job.h"
#include "LinkList.h"
#include "FCFS.h"
#include "SJF.h"
#include "HPF.h"
#include "RR.h"
using namespace std;

int main() {
    ifstream file("data.txt", ios::in);
    if(!file.is_open()) {
        cout << "data.txt can't open for read!" << endl;
        system("pause");
        exit(1);
    }
    char str[45];
    //�����ж���
    file.getline(str, 45);

    //��ҵ��
    NodeList<Job> jobs;
    jobs.SetCompareFunction(jobSortArrivalTime);

    Job job;
    while(file >> job.jobId) {
        file >> job.arrivalTime;
        file >> job.executionTime;
        file >> job.priority;
        jobs.Insert(jobs.GetLength(), job, true);
    }
    file.close();

    //�����ȷ���
    cout << "******************* ��ʼģ�� FCFS �����ȷ��� ********************\n\n";
    FCFS fcfs(jobs);
    fcfs.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";

    //����ҵ����
    cout << "******************** ��ʼģ�� SJF ����ҵ���� ********************\n\n";
    SJF sjf(jobs);
    sjf.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";

    //����Ȩ��������
    cout << "****************** ��ʼģ�� HPF ����Ȩ�������� ******************\n\n";
    HPF hpf(jobs);
    hpf.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";

    //ʱ��Ƭ��ת
    cout << "********************* ׼��ģ�� RR ʱ��Ƭ��ת ********************"
        << endl << "������ʱ��Ƭ��С��slice > 0����";
    unsigned int slice = 0;
    while(slice <= 0) {
        cin >> slice;
    }
    cout << "********************* ��ʼģ�� RR ʱ��Ƭ��ת ********************\n\n";
    RR rr(jobs, slice);
    rr.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";
    system("pause");
    return 0;
}
