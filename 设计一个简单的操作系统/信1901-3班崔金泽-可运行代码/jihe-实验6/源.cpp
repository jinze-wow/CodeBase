#include <windows.h>
#include <iostream>
#include<string>
#include<queue>
#include <iomanip>
#include <random>
#include <algorithm>
using namespace std;
//******************************************************
const unsigned short SIZE_OF_BUFFER = 10;   //缓冲区长度
unsigned short ProductID = 0;               //产品号
unsigned short ConsumeID = 0;               //将被消耗的产品号
unsigned short in = 0;                      //产品进缓冲区时的下标
unsigned short out = 0;                     //产品出缓冲区时的下标
int pv_buffer[SIZE_OF_BUFFER];               //缓冲区是个循环队列
bool pv_continue = true;                     //控制程序结束
HANDLE pv_hMutex;                            //用于线程间的互斥，主要用于控制台打印 
HANDLE fullSemaphore;                        //消费者进程的私用信号量
HANDLE emptySemaphore;                       //生产者进程的私用信号量
int sum = 0;
DWORD WINAPI Producer(LPVOID);              //生产者线程
DWORD WINAPI Consumer(LPVOID);              //消费者线程
//*******************************************************
int couttime = 0;			//计数时间
float sumtime = 0;		//总周转时间
float sumrighttime = 0;	//总带权周转时间
//**********************************************************
const int Max_process = 50;//最大进程数
const int Max_source = 50;//最大资源数
//**********************************************************
//生产一个产品。简单模，仅输出新产品的ID号
void Produce()
{
	cout << "生产 " << ++ProductID << "号产品   ";
	Sleep(1500);
	cout << "  " << endl;
	cout << "##############################################" << endl;
}
//把新生产的产品放入缓冲区
void Put()
{
	cout << "向仓库中放入产品     ";
	pv_buffer[in] = ProductID;
	in = (in + 1) % SIZE_OF_BUFFER;
	Sleep(1500);
	sum = sum + 1;
	cout << "产品总数为：" << sum << endl;
	cout << "##############################################" << endl;
}
//从缓冲区中取出一个产品
void Take()
{
	ConsumeID = pv_buffer[out];
	cout << "取走 " << ConsumeID << " 号产品    ";
	pv_buffer[out] = -1;
	out = (out + 1) % SIZE_OF_BUFFER;
	Sleep(1500);
	cout << " " << endl;
	cout << "##############################################" << endl;
}
//消耗一个产品
void Consume()
{
	cout << "消费 " << ConsumeID << " 号产品        ";
	Sleep(1500);
	sum = sum - 1;
	cout << "产品总数为：" << sum << endl;
	cout << "##############################################" << endl;
}
//生产者
DWORD  WINAPI Producer(LPVOID lpPara)
{
	while (pv_continue) {
		WaitForSingleObject(emptySemaphore, INFINITE);  // P(emptySemaphore) 生产者信号量 -1 
		WaitForSingleObject(pv_hMutex, INFINITE);      // P(Mutex) 获取线程间互斥信号 
		Produce();
		Put();
		Sleep(1500);
		ReleaseSemaphore(fullSemaphore, 1, NULL);        // V(fullSemaphore) 消费者信号量 +1 
		ReleaseMutex(pv_hMutex);                      // V(Mutex) 释放线程间互斥信号 
	}
	return 0;
}
//消费者
DWORD  WINAPI Consumer(LPVOID lpPara)
{
	while (pv_continue) {
		WaitForSingleObject(fullSemaphore, INFINITE);   //P(fullSemaphore) 消费者信号量-1 
		WaitForSingleObject(pv_hMutex, INFINITE);       //P(Mutex) 获得线程间互斥信号 
		Take();
		Consume();
		Sleep(1500);
		ReleaseSemaphore(emptySemaphore, 1, NULL);        //V(emptySemaphore) 生产者信号量+1 
		ReleaseMutex(pv_hMutex);                       //V(Mutex) 释放线程间互斥信号 
	}
	return 0;
}
//高优先权算法*****************************************************************************
typedef struct pcb {
	string pName;//进程名
	int priorityNumber;//优先数
	float serviceTime;//服务时间
	float estimatedRunningtime;//估计运行时间
	float startTime;
	float endTime;
	char state;//状态
	bool operator<(const struct pcb& a)const {
		return priorityNumber < a.priorityNumber || priorityNumber == a.priorityNumber && estimatedRunningtime < a.estimatedRunningtime;
	}
}PCB;
void createProcess(priority_queue<PCB>& p, int n) {//创建n个进程，带头结点
	cout << "开始创建进程" << endl;
	PCB r;//工作结点
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个进程的名字、优先数、服务时间(例如:A 1 2 ):";
		cin >> r.pName;
		cin >> r.priorityNumber;
		cin >> r.serviceTime;
		r.estimatedRunningtime = r.serviceTime;
		r.state = 'R';
		p.push(r);
	}
	cout << "----------------------------------------------------------" << endl;
}
void printProcess(priority_queue<PCB> p) {
	PCB s;
	cout << "进程名\t优先数 服务时间 已运行时间 还剩运行时间" << endl;
	while (p.size() != 0) {
		s = p.top();
		cout << s.pName << "\t" << s.priorityNumber << "\t " << s.serviceTime << "\t  ";
		cout << s.serviceTime - s.estimatedRunningtime << "\t     " << s.estimatedRunningtime << endl;
		p.pop();
	}
	cout << "----------------------------------------------------------" << endl;
}
void runProcess(priority_queue<PCB>& p) {//运行进程
	PCB s;
	while (p.size() != 0) {
		s = p.top();
		p.pop();
		cout << "正在运行的进程" << endl;
		cout << "进程名\t优先数 服务时间 已运行时间 还剩运行时间" << endl;//输出当前进程
		cout << s.pName << "\t" << s.priorityNumber << "\t " << s.serviceTime << "\t  ";
		cout << s.serviceTime - s.estimatedRunningtime << "\t     " << s.estimatedRunningtime << endl;
		if (s.serviceTime == s.estimatedRunningtime)
		{
			s.startTime = couttime;
		}
		couttime = couttime + 1;
		s.priorityNumber--;//优先数减1
		s.estimatedRunningtime--;//估计运行时间减1
		if (s.estimatedRunningtime == 0) {
			s.state = 'C';
			s.endTime = couttime;
			cout << "-------------------------------------------------------" << endl;
			cout << "进程" << s.pName << "执行完成" << endl;
			cout << s.pName << "周转时间为" << s.endTime - s.startTime << endl;
			cout << s.pName << "带权周转时间为" << (s.endTime - s.startTime) / s.serviceTime << endl;
			cout << "--------------------------------------------------------" << endl;
			sumtime = sumtime + (s.endTime - s.startTime);
			sumrighttime = sumrighttime + ((s.endTime - s.startTime) / s.serviceTime);
		}
		else
			p.push(s);
		cout << "进程" << s.pName << "执行一次之后就绪队列中的进程" << endl;
		printProcess(p);
	}
	cout << endl;
}
//存储管理*********************************************************************************
void FIFO(int b, string a)
{
	char m[10] = { '#','#','#','#','#','#','#','#','#','#' };//将物理块数内容初始化
	int i = 0, j, x, y = 0, count1 = 0;//y为置换标记,count1为缺页标记
	do {
		if (i < b)
		{
			m[y] = a[i];//缺页后将页面写入
			i++;
			count1++;//缺页标记++
			y = (y + 1) % b;//置换标记++
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//打印
				cout << m[j];
			cout << endl;
			continue;
		}
		for (j = 0; j < b; j++)//判断是否缺页
		{
			if (a[i] == m[j])//未缺页则将x赋值1
			{
				x = 1;
				break;
			}
		}

		if (x == 1)//未缺页处理
		{
			i++;
			x = 0;
			cout << a[i - 1] << " " << endl;
			continue;
		}
		else//缺页处理
		{
			m[y] = a[i];
			i++;
			y = (y + 1) % b;
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//打印
				cout << m[j];
			cout << endl;
			count1++;
		}
	} while (a[i] != '#');
	cout << "页面缺页次数" << "  " << "页面置换次数" << "  " << "缺页率" << endl;
	cout << "     " << count1 << "           " << count1 - b << "           " << 1.0 * count1 / (a.size() - 1) << endl;;
	/*打印置换次数和缺页次数*/
}
void LRU(int b, string a)
{
	char m[10] = { '#','#','#','#','#','#','#','#','#','#' };
	int i = 0, j, x, y = 0, count1 = 0, min = 10000;//min为最久未使用的初始值
	cout << "置换过程如下表" << endl;
	do {
		if (i < b)
		{
			m[y] = a[i];//缺页后将页面写入
			i++;
			count1++;//缺页标记++
			y = y + 1;//置换标记++
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//打印
				cout << m[j];
			cout << endl;
			continue;
		}
		for (j = 0; j < b; j++)//判断是否缺页
		{
			if (a[i] == m[j])
			{
				x = 1;
				break;
			}
		}

		if (x == 1)//未缺页才处理
		{
			i++;
			x = 0;
			cout << a[i - 1] << " " << endl;
			continue;
		}
		else//缺页处理
		{
			for (j = 0; j < b; j++)//查找最久未使用的页面
			{
				for (int t = i - 1; t >= 0; t--)
				{
					if (m[j] == a[t])
						break;
					if (t < min)
						min = t;
					y = j;
				}
			}
			m[y] = a[i];//置换最久未使用的页面
			min = 10000;//将min初始化
			i++;
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//打印
				cout << m[j];
			cout << endl;
			count1++;
		}
	} while (a[i] != '#');
	cout << "页面缺页次数" << "  " << "页面置换次数" << "  " << "缺页率" << endl;
	cout << "     " << count1 << "           " << count1 - b << "           " << 1.0 * count1 / (a.size() - 1) << endl;;
}
//银行家算法***********************************************************************************
class bank
{
private:
	int available[Max_source];//可用资源数
	int max[Max_process][Max_source];//最大需求
	int allocation[Max_process][Max_source];//已分配资源数
	int need[Max_process][Max_source];//还需资源数
	int request[Max_process][Max_source];//进程需要资源数
	bool finish[Max_process];//判断系统是否有足够的资源分配
	int p[Max_process];//记录序列
	int m;//用来表示进程
	int n;//表示资源
public:
	void Init();//完成对变量的初始化
	bool Safe();//安全检测算法
	void Banker();//银行家算法
	void Display(int, int);//显示进程与资源状态

};
void bank::Init()
{
	cout << "请输入进程数：";
	cin >> m;
	cout << "请输入资源种类数：";
	cin >> n;
	cout << "请输入每个进程最多所需的各资源数" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> max[i][j];
	cout << "请输入每个进程已分配的各资源数" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> allocation[i][j];
			need[i][j] = max[i][j] - allocation[i][j];//注意这里的need可能小于0；要进行报错并重新输入，可以用continue来跳出当前循环
			if (need[i][j] < 0)
			{
				cout << "你输入的第" << i + 1 << "个进程的第" << j + 1 << "个资源数有问题！\n请重新输入！";
				j--;//忽略这个资源数
				continue;//跳出本次循环
			}
		}
	cout << "请输入各个资源现有的数目" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> available[i];
	}
}
//m表示进程，n表示资源
void bank::Display(int n, int m)
{
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "系统可用的资源数为：	";
	for (int i = 0; i < n; i++)
	{
		cout << available[i] << "	";
	}
	cout << endl << "各进程还需要的资源量：" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "	进程" << i << ":";
		for (int j = 0; j < n; j++)
			cout << "		" << need[i][j];
		cout << endl;
	}
	cout << endl << "各进程已经得到的资源:		" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "	进程" << i << ":";
		for (int j = 0; j < n; j++)
		{
			cout << "		" << allocation[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}
void bank::Banker()
{
	int i, cusneed, flag = 0;//cusneed表示资源进程号
	char again;//键盘录入一个字符用于判断是否继续请求资源
	while (1)
	{
		Display(n, m);
		cout << endl;
		/*请求资源*/
		while (true)
		{
			cout << "请输入要申请的进程号" << endl;
			cin >> cusneed;
			if (cusneed > m)
			{
				cout << "没有该进程，请重新输入" << endl;
				continue;
			}
			cout << "请输入进程所请求的各资源数" << endl;
			for (int i = 0; i < n; i++)
				cin >> request[cusneed][i];
			for (int i = 0; i < n; i++)
			{
				if (request[cusneed][i] > need[cusneed][i])
				{
					cout << "你输入的资源请求数超过进程数需求量！请重新输入" << endl;
					continue;
				}
				if (request[cusneed][i] > available[i])
				{
					cout << "你输入的资源请求数超过系统当前资源拥有数！" << endl;
					break;
				}
			}
			break;
		}
		/*上述是资源请求不合理的情况，下面是资源请求合理时则执行银行家算法*/
		for (int i = 0; i < n; i++)
		{
			available[i] -= request[cusneed][i];//可用资源减去成功申请的
			allocation[cusneed][i] += request[cusneed][i];//已分配资源加上成功申请的
			need[cusneed][i] -= request[cusneed][i];//进程还需要的减去成功申请的
		}
		/*判断分配申请资源后系统是否安全，如果不安全则将申请过的资源还给系统*/
		if (Safe())
			cout << "分配成功！";
		else
		{
			cout << "分配失败！" << endl;
			/*进行向系统还回资源操作*/
			for (int i = 0; i < n; i++)
			{
				available[i] += request[cusneed][i];
				allocation[cusneed][i] -= request[cusneed][i];
				need[cusneed][i] += request[cusneed][i];
			}
		}
		/*对进程的需求资源进行判断，是否还需要资源，简言之就是判断need数组是否为0*/
		for (int i = 0; i < n; i++)
			if (need[cusneed][i] <= 0)
				flag++;
		if (flag == n)
		{
			for (int i = 0; i < n; i++)
			{
				available[i] += allocation[cusneed][i];
				allocation[cusneed][i] = 0;
				need[cusneed][i] = 0;
			}
			cout << "进程" << cusneed << "占有的资源已释放！！" << endl;
			flag = 0;
		}
		for (int i = 0; i < m; i++)
			finish[i] = false;
		/*判断是否继续申请*/
		cout << "继续分配: y   停止分配：n" << endl;
		cin >> again;
		if (again == 'y')
			continue;
		break;
	}
}

bool bank::Safe()
{
	int l = 0, j, i;
	int work[Max_source];
	/*对work数组进行初始化，初始化时和avilable数组相同*/
	for (int i = 0; i < n; i++)
		work[i] = available[i];
	/*对finish数组初始化全为false*/
	for (int i = 0; i < m; i++)
		finish[i] = false;
	for (int i = 0; i < m; i++)
	{
		if (finish[i] == true)
			continue;
		else
		{
			for (j = 0; j < n; j++)
			{
				if (need[i][j] > work[j])
					break;
			}
			if (j == n)
			{
				finish[i] = true;
				for (int k = 0; k < n; k++)
					work[k] += allocation[i][k];
				p[l++] = i;//记录进程号
				i = -1;
			}
			else
				continue;
		}
	}
	if (l == m)
	{
		cout << "系统是安全的" << endl;
		cout << "安全序列：" << endl;
		for (int i = 0; i < l; i++)
		{
			cout << p[i];
			if (i != l - 1)
				cout << "-->";
		}
		cout << endl << endl;
		return true;
	}
	return false;
}
//磁盘调度算法*****************************************************************
class DiskScheduling {
public:
	DiskScheduling() :DiskScheduling(10, 0, 200) {}
	DiskScheduling(int diskNum, int startPos, int maxPos) {
		uniform_int_distribution<unsigned> u(0, maxPos);
		default_random_engine e(10);
		while (diskNum--) {
			diskInputSeq.push_back(u(e));
		}
		diskStartPos = startPos;
		diskMaxPos = maxPos;
	}
	DiskScheduling(vector<int>& diskInput) {
		diskMaxPos = *max_element(diskInput.begin(), diskInput.end());
		diskStartPos = 0;
		diskInputSeq = diskInput;
	}
	DiskScheduling(vector<int>& diskInput, int startPos, int maxPos) {
		diskMaxPos = maxPos;
		diskStartPos = startPos;
		diskInputSeq = diskInput;
	}
	void FCFS() {
		diskOutputSeq = diskInputSeq;
		for (auto i = diskInputSeq.begin(); i != diskInputSeq.end() - 1; ++i) {
			sumStep += abs(*i - *(i + 1));
		}
		sumStep += abs(diskStartPos - diskInputSeq[0]);
		cout << "FCFS算法\n";
		Print();
		Reset();
	}
	void SSTF() {
		vector<int> diskTemp(diskInputSeq);
		int diskStartTemp = diskStartPos;
		int count = diskTemp.size();
		while (count--) {
			auto minNow = min_element(diskTemp.begin(), diskTemp.end(), [diskStartTemp](const int& first, const int& second) {
				return abs(diskStartTemp - first) < abs(diskStartTemp - second);
				});
			diskOutputSeq.push_back(*minNow);
			sumStep += abs(diskStartTemp - *minNow);
			diskStartTemp = *minNow;
			*minNow = INT_MAX;
		}
		cout << "SSTF算法\n";
		Print();
		Reset();
	}
	// dir = true 移动方向为磁盘号小到大的方向
	void SCAN(bool dir = true) {
		ScanCscanHelper(dir, 0);
		cout << "SCAN算法\n";
		Print();
		Reset();
	}
	void CSCAN(bool dir = true) {
		ScanCscanHelper(dir, 1);
		cout << "CSCAN算法\n";
		Print();
		Reset();
	}
	void NstepSCAN(int nGroup, bool dir = true) {
		int diskStartTemp = diskStartPos;
		vector<int> diskTemp;
		int groupSize = (int)ceil(diskInputSeq.size() / (double)nGroup);
		for (auto i = diskInputSeq.begin(); i != diskInputSeq.end(); i += groupSize) {
			if (diskInputSeq.end() - i < groupSize)
				diskTemp.assign(i, diskInputSeq.end()), i = diskInputSeq.end() - groupSize;
			else
				diskTemp.assign(i, i + groupSize);
			DiskScheduling diskT(diskTemp, diskStartTemp, diskMaxPos);
			diskT.ScanCscanHelper(dir, 0);
			sumStep += diskT.getSumStep();
			vector<int> diskOutputGroup = diskT.getDiskOutputSeq();
			diskStartTemp = *diskOutputGroup.rbegin();
			diskOutputSeq.insert(diskOutputSeq.end(), diskOutputGroup.begin(), diskOutputGroup.end());
		}
		cout << "NstepSCAN\n";
		Print();
		Reset();
	}
	void ScanCscanHelper(int dir, int opt) {
		vector<int> diskTemp(diskInputSeq);
		sort(diskTemp.begin(), diskTemp.end(), [dir](const int& first, const int& second) {
			return dir ? first > second: first < second;
			});
		auto i = diskTemp.begin();
		for (; i != diskTemp.end() - 1; i++) {
			if ((*i - diskStartPos) * (*(i + 1) - diskStartPos) <= 0) {
				if ((*(i + 1) - diskStartPos) == 0) i++;
				break;
			}
		}
		reverse(diskTemp.begin(), i + 1);
		if (opt == 1) reverse(i + 1, diskTemp.end());
		diskOutputSeq = diskTemp;
		for (auto j = diskOutputSeq.begin(); j != diskOutputSeq.end() - 1; ++j) {
			sumStep += abs(*j - *(j + 1));
		}
		sumStep += abs(diskStartPos - diskOutputSeq[0]);
	}
	int getSumStep() { return sumStep; }
	vector<int> getDiskOutputSeq() { return diskOutputSeq; }
private:
	void Print() {
		cout << "************************************************************************" << endl;
		cout << "起始磁道号：" << diskStartPos << endl;
		cout << "最大磁道号：" << diskMaxPos << endl;
		cout << "待访问顺序\t\n";
		for (int diskNow : diskInputSeq)
			cout << diskNow << " ";
		cout << "\n实际访问顺序\t\n";
		for (int diskActual : diskOutputSeq)
			cout << diskActual << " ";
		cout << "\n移动的磁道总数\t" << sumStep << endl;
		cout << "平均寻道数\t" << sumStep / diskOutputSeq.size() << "\n";
		cout << "************************************************************************" << endl;
	}
	void Reset() {
		sumStep = 0;
		diskOutputSeq.clear();
	}

private:
	int diskStartPos;			// 起始的磁道号 or 磁盘机械臂当前位置
	int diskMaxPos;				// 最大的磁道号
	double sumStep = 0;			// 访问的总步数
	vector<int> diskInputSeq;	// 磁道待访问顺序
	vector<int> diskOutputSeq;	// 磁道实际的访问顺序
};
//主程序测试******************************************************
int main()
{
	int NumberChoice;
	cout << "******************************************" << endl;
	cout << "1：生产者消费者问题模拟" << endl;
	cout << "2：抢占式高优先级算法模拟" << endl;
	cout << "3：FIFO算法和LRU算法模拟" << endl;
	cout << "4：银行家算法模拟" << endl;
	cout << "5：5种磁盘调度算法模拟" << endl;
	cout << "**********请选择某一功能进行模拟*************" << endl;
	cin >> NumberChoice;
	cout << "*******************************************" << endl;
	if (NumberChoice == 1) {
		//创建Mutex和Semaphore
		pv_hMutex = CreateMutex(NULL, FALSE, NULL);
		fullSemaphore = CreateSemaphore(NULL, 0, SIZE_OF_BUFFER, NULL);
		emptySemaphore = CreateSemaphore(NULL, SIZE_OF_BUFFER,
			SIZE_OF_BUFFER, NULL);
		//缓冲区初始化
		for (int i = 0; i < SIZE_OF_BUFFER; ++i) {
			pv_buffer[i] = -1;   //当值为-1时该项为空
		}
		const unsigned short PRODUCERS_COUNT = 3;       //生产者的个数
		const unsigned short CONSUMERS_COUNT = 2;       //消费者的个数						//总的线程数
		const unsigned short THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;
		HANDLE pvThreads[THREADS_COUNT];     //各线程的handle
		DWORD producerID[PRODUCERS_COUNT];  //生产者线程的标识符
		DWORD consumerID[CONSUMERS_COUNT];  //消费者线程的标识符
		cout << "##############################################" << endl;
		cout << "开始，缓冲区大小为10 " << endl;
		cout << "##############################################" << endl;
		for (int i = 0; i < PRODUCERS_COUNT; i++) {
			pvThreads[i] = CreateThread(NULL, 0, Producer, NULL, 0, &producerID[i]);
			if (pvThreads[i] == NULL) break;
		}
		//创建消费者线程
		for (int i = 0; i < CONSUMERS_COUNT; i++) {
			pvThreads[PRODUCERS_COUNT + i]
				= CreateThread(NULL, 0, Consumer, NULL, 0, &consumerID[i]);
			if (pvThreads[i] == NULL) break;
		}
		while (pv_continue) {
			if (getchar()) {  //按回车后终止程序运行
				pv_continue = false;
			}
		}
		system("pause");
		return 0;

	}
	else if (NumberChoice == 2)
	{
		priority_queue<PCB> p;
		int n;
		cout << "请输入进程的个数：";
		cin >> n;
		createProcess(p, n);
		runProcess(p);
		cout << "所有进程执行完毕" << endl;
		cout << "平均周转时间为" << fixed << setprecision(2) << sumtime / n << endl;
		cout << "平均带权周转时间为" << fixed << setprecision(2) << sumrighttime / n << endl;
		getchar();
		getchar();
		return 0;
	}
	else if (NumberChoice == 3)
	{
		string a;
		int b;
		cout << "请输入物理块数:";
		cin >> b;
		cout << "请输入页号序列:（#结尾）";
		cin >> a;
		cout << "##############################################" << endl;
		cout << "FIFO算法如下:" << endl;
		FIFO(b, a);
		cout << "##############################################" << endl;
		cout << "LRU算法如下:" << endl;
		LRU(b, a);
		cout << "##############################################" << endl;
		return 0;

	}
	else if (NumberChoice == 4)
	{
		bank peter;
		peter.Init();
		peter.Safe();
		peter.Banker();
		return 0;

	}
	else if (NumberChoice == 5)
	{
		DiskScheduling disk1(20, 100, 200);
		int choice;
		cout << "请选择要使用的算法" << endl;
		cout << "0：结束" << endl;
		cout << "1：FCFS" << endl;
		cout << "2：SSTF" << endl;
		cout << "3：SCAN" << endl;
		cout << "4：CSCAN" << endl;
		cout << "5：NsteptSCAN" << endl;
		while (cin >> choice) {
			if (choice == 0) { cout << "结束"; break; };//结束 
			if (choice == 1)  disk1.FCFS();//调用FCFS算法
			if (choice == 2)  disk1.SSTF();//调用SSTF算法
			if (choice == 3)  disk1.SCAN(false);//调用SCAN算法
			if (choice == 4)  disk1.CSCAN(false);//调用CSCAN算法
			if (choice == 5)  disk1.NstepSCAN(3);//调用NstepSCAN算法
			cout << "请选择要使用的算法" << endl;
			cout << "0：结束" << endl;
			cout << "1：FCFS" << endl;
			cout << "2：SSTF" << endl;
			cout << "3：SCAN" << endl;
			cout << "4：CSCAN" << endl;
			cout << "5：NsteptSCAN" << endl;
		}
		return 0;
	}
	else {
		cout << "输入有误，请重新输入" << endl;
	}
}
