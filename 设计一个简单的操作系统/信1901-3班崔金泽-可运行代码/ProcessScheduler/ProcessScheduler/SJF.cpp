#include "SJF.h"
//ִ��
void SJF::execute(std::ostream & output) {
    if(list.GetLength() == 0) {
        output << "�����Ϊ�գ�\n";
        return;
    }
    Job job;
    NodeList<Job> arrived;
    arrived.SetCompareFunction(jobSortExecutionTime);
    //��ǰʱ�䣬����
    unsigned int now = 0, total = 0;
    //�ܵȴ�ʱ�䣬����תʱ�䣬�ܴ�Ȩ��תʱ��
    double totalWait = 0, totalTurnover = 0, totalRightTurnover = 0;
    while(list.GetLength() > 0 || arrived.GetLength() > 0) {
        while(list.GetLength() > 0) {
            list.Find(0, job);
            if(job.arrivalTime <= now) {
                //�ѵ�����б���ִ��ʱ�䳤������
                arrived.Insert(arrived.GetLength(), job, true);
                list.Delete(0);
                continue;
            }
            break;
        }
        if(now < job.arrivalTime && arrived.GetLength() == 0) {
            now = job.arrivalTime;
            list.Delete(0);
        } else {
            arrived.Find(0, job);
            arrived.Delete(0);
        }
        now += job.executionTime;
        output << "ִ�������ҵ��" << job
            << "\n�ȴ�ʱ�䣺" << (now - job.executionTime - job.arrivalTime)
            << "\t��תʱ�䣺" << (now - job.arrivalTime)
            << "\t��Ȩ��תʱ�䣺" << (double(now - job.arrivalTime) / job.executionTime)
            << "\n";
        total++;
        totalWait += now - job.executionTime - job.arrivalTime;
        totalTurnover += now - job.arrivalTime;
        totalRightTurnover += double(now - job.arrivalTime) / job.executionTime;
    }
    output << "\nƽ���ȴ�ʱ�䣺" << (totalWait / total)
        << "\tƽ����תʱ�䣺" << (totalTurnover / total)
        << "\tƽ����Ȩ��תʱ�䣺" << (totalRightTurnover / total)
        << "\n";
}
