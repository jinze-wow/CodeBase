#pragma once
#include "LinkList.h"
#include "Job.h"
class FCFS {
public:
    //���캯��
    FCFS(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //ִ��
    void execute(std::ostream&);
private:
    NodeList<Job> list;
};
