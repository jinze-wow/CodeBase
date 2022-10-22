#pragma once
#include "LinkList.h"
#include "Job.h"
class HPF {
public:
    //���캯��
    HPF(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //ִ��
    void execute(std::ostream&);
private:
    NodeList<Job> list;
};
