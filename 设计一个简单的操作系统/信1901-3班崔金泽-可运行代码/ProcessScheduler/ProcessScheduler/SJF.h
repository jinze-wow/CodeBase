#pragma once
#include "LinkList.h"
#include "Job.h"
class SJF {
public:
    //���캯��
    SJF(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //ִ��
    void execute(std::ostream&);
private:
    NodeList<Job> list;
};
