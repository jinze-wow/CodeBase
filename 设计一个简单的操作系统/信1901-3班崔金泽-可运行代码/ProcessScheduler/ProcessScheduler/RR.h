#pragma once
#include "LinkList.h"
#include "Job.h"
struct JobPack {
    Job job;
    unsigned int operated;
};
class RR {
public:
    //���캯��
    RR(NodeList<Job> jobs, unsigned int slice) : list(jobs), slice(slice) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //ִ��
    void execute(std::ostream&);
private:
    NodeList<Job> list;
    //ʱ��Ƭ
    unsigned int slice;
};
