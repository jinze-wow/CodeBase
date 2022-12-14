
//cjz 2022-6-29
//数据：3 20 
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//https://blog.csdn.net/minose/article/details/105799394
#include "stdafx.h"

void init();
void Work();    
void Welcome();
void Opt();     //OPT算法
void Fifo();    //FIFO算法
void Lru();     //LRU算法
void Input(unsigned &, unsigned &); //输入设置的内存大小和页面数量
void Output(vector<int>::iterator); //输出当前页面
void Outputmem(vector<int>&);       //输出当前时刻内存使用情况
void Inputpages(vector<int>&, const unsigned &);    //输入页面
vector<int>::iterator Found(vector<int>&, vector<int>::iterator, unsigned); //从向量中查找一个数并返回它的迭代器

vector<int>pages, mem;  //pages:输入的页面顺序表， mem:当前时刻内存占用情况
vector<int>::iterator pagesIter, memIter;   //迭代器
unsigned size, pagesNum;    //size:内存大小， pagesNum:页面数量

int main()
{
    Work();
    return 0;
}

void init()
{
    pages.clear();
    mem.clear();
    size = -1;
    pagesNum = -1;
}

void Work()
{
    int comd;
    while (true)
    {
        Welcome();
        cin >> comd;
        system("cls");
        switch (comd)
        {
        case 1: {
            init();
            Input(size, pagesNum);
            Inputpages(pages, pagesNum);
            break;
        }
        case 2: {
            Opt();
            break;
        }
        case 3: {
            Fifo();
            break;
        }
        case 4: {
            Lru();
            break;
        }
        case 0: {
            return;
        }
        default: {
            cout << endl << "请输入正确选项" << endl << endl;
            break;
        }
        }
        system("pause");
        system("cls");
    }
}

void Welcome()
{
    cout << "*************  请选择选项  *************" << endl;
    cout << "* 1. 输入数据                          *" << endl;
    cout << "* 2. OPT算法(最佳置换算法)             *" << endl;
    cout << "* 3. FIFO算法(先进先出置换算法)        *" << endl;
    cout << "* 4. LRU算法(最近最久未使用)           *" << endl;
    cout << "* 0. 退出                              *" << endl;
    cout << "****************************************" << endl;
}

void Opt()
{
    vector<int>tmp;
    vector<int>::iterator tmpIter;//在置换的时候用来找要替换的值的
    map<unsigned, int>mp;//C++ 中 map 提供的是一种键值对容器，里面的数据都是成对出现的,
                         //每一对中的第一个值称之为关键字(key)，每个关键字只能在 map 中出现一次；第二个称之为该关键字的对应值。
    tmp.clear();
    mp.clear();
    mem.clear();
    unsigned cnt = 0;
    for (pagesIter = pages.begin(); pagesIter != pages.end(); pagesIter++)
    {
        Output(pagesIter);
        if (mp[*pagesIter] == 0)
        {
            cnt++;
            if (mem.size() < size)
            {
                mem.push_back(*pagesIter);
                mp[*pagesIter] = 1;
                tmp = mem;
            }
            else
            {
                for (auto ixIter = pagesIter + 1; ixIter != pages.end(); ixIter++)//向后寻找
                {
                    if (tmp.size() == 1)
                        break;
                    tmpIter = Found(tmp, tmpIter, *ixIter);
                    if (tmpIter != tmp.end())
                        tmp.erase(tmpIter);
                }
                tmpIter = tmp.begin();
                memIter = Found(mem, memIter, *tmpIter);
                mem.insert(memIter, *pagesIter);
                memIter = Found(mem, memIter, *tmpIter);
                mp[*memIter] = 0;
                mem.erase(memIter);
                mp[*pagesIter] = 1;
                tmp = mem;
            }
            Outputmem(mem);
        }
    }
    cout << endl;
    cout << "缺页中断次数: " << cnt << endl;
    cout << "缺页率: "<< cnt / (1.0*pagesNum) << endl << endl;
}

void Fifo()
{
    queue<unsigned>que;
    map<unsigned, int>mp;
    while (!que.empty())
        que.pop();
    mp.clear();
    mem.clear();
    unsigned cnt = 0;
    for (pagesIter = pages.begin(); pagesIter != pages.end(); pagesIter++)
    {
        Output(pagesIter);
        if (mp[*pagesIter] == 0)
        {
            cnt++;
            if (mem.size() < size)
            {
                mem.push_back(*pagesIter);
                que.push(*pagesIter);
                mp[*pagesIter] = 1;
            }
            else
            {
                unsigned x = que.front();
                que.pop();
                memIter = Found(mem, memIter, x);
                mem.insert(memIter, *pagesIter);
                que.push(*pagesIter);
                mp[*pagesIter] = 1;
                memIter = Found(mem, memIter, x);
                mem.erase(memIter);
                mp[x] = 0;
            }
            Outputmem(mem);
        }
    }
    cout << endl;
    cout << "缺页中断次数: " << cnt << endl;
    cout << "缺页率: "<< cnt / (1.0*pagesNum) << endl << endl;
}

void Lru()
{
    vector<int>tmp;
    vector<int>::iterator tmpIter;
    map<unsigned, int>mp;
    mem.clear();
    tmp.clear();
    mp.clear();
    unsigned cnt = 0;
    for (pagesIter = pages.begin(); pagesIter != pages.end(); pagesIter++)
    {
        Output(pagesIter);
        if (mp[*pagesIter] == 0)
        {
            cnt++;
            if (mem.size() < size)
            {
                mem.push_back(*pagesIter);
                mp[*pagesIter] = 1;
                tmp.push_back(*pagesIter);//vector尾部加入一个数据。  312  21324
            }
            else
            {
                tmpIter = tmp.begin();
                memIter = Found(mem, memIter, *tmpIter);
                mem.insert(memIter, *pagesIter);
                memIter = Found(mem, memIter, *tmpIter);
                mem.erase(memIter);
                mp[*tmpIter] = 0;
                mp[*pagesIter] = 1;
                tmp.erase(tmpIter);
                tmp.push_back(*pagesIter);
            }
            Outputmem(mem);
        }
        else
        {
            tmpIter = Found(tmp, tmpIter, *pagesIter);
            tmp.erase(tmpIter);
            tmp.push_back(*pagesIter);
        }
    }
    cout << endl;
    cout << "缺页中断次数: " << cnt << endl;
    cout << "缺页率: "<< cnt / (1.0*pagesNum) << endl << endl;
}

void Input(unsigned &size, unsigned &pagesNum)
{
    cout << "请输入内存大小和页面数量" << endl;
    cin >> size >> pagesNum;
}

void Inputpages(vector<int>&ivec, const unsigned &pagesNum)
{
    cout << "请输入" << pagesNum << "个页面" << endl;
    for (unsigned ix = 0; ix < pagesNum; ix++)
    {
        unsigned page;
        cin >> page;
        ivec.push_back(page);
    }
}

void Output(vector<int>::iterator iter)
{
    cout << *iter << endl;
}

void Outputmem(vector<int>&ivec)
{
    for (auto ix : ivec)
    {
        cout << " " << ix;
    }
    cout << endl;
}

vector<int>::iterator Found(vector<int>&ivec, vector<int>::iterator iter, unsigned x)
{
    for (iter = ivec.begin(); iter != ivec.end(); iter++)
    {
        if (*iter == x)
        {
            return iter;
        }
    }
    return ivec.end();
}

