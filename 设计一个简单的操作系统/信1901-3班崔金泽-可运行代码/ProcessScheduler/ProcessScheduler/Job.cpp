#include "Job.h"
std::ostream & operator<<(std::ostream &output, Job &job) {
    output << "JobID:" << job.jobId
        << "\tArrivalTime:" << job.arrivalTime
        << "\t ExecutionTime:" << job.executionTime
        << "\tPriority:" << job.priority;
    return output;
}
//������ʱ��������
int jobSortArrivalTime(Job& left, Job& right) {
    int x = left.arrivalTime - right.arrivalTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
//��ִ��ʱ�䳤��������
int jobSortExecutionTime(Job& left, Job& right) {
    int x = left.executionTime - right.executionTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
//�����ȼ�������
int jobSortPriority(Job& left, Job& right) {
    int x = left.priority - right.priority;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
