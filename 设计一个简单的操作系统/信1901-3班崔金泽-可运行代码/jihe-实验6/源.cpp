#include <windows.h>
#include <iostream>
#include<string>
#include<queue>
#include <iomanip>
#include <random>
#include <algorithm>
using namespace std;
//******************************************************
const unsigned short SIZE_OF_BUFFER = 10;   //����������
unsigned short ProductID = 0;               //��Ʒ��
unsigned short ConsumeID = 0;               //�������ĵĲ�Ʒ��
unsigned short in = 0;                      //��Ʒ��������ʱ���±�
unsigned short out = 0;                     //��Ʒ��������ʱ���±�
int pv_buffer[SIZE_OF_BUFFER];               //�������Ǹ�ѭ������
bool pv_continue = true;                     //���Ƴ������
HANDLE pv_hMutex;                            //�����̼߳�Ļ��⣬��Ҫ���ڿ���̨��ӡ 
HANDLE fullSemaphore;                        //�����߽��̵�˽���ź���
HANDLE emptySemaphore;                       //�����߽��̵�˽���ź���
int sum = 0;
DWORD WINAPI Producer(LPVOID);              //�������߳�
DWORD WINAPI Consumer(LPVOID);              //�������߳�
//*******************************************************
int couttime = 0;			//����ʱ��
float sumtime = 0;		//����תʱ��
float sumrighttime = 0;	//�ܴ�Ȩ��תʱ��
//**********************************************************
const int Max_process = 50;//��������
const int Max_source = 50;//�����Դ��
//**********************************************************
//����һ����Ʒ����ģ��������²�Ʒ��ID��
void Produce()
{
	cout << "���� " << ++ProductID << "�Ų�Ʒ   ";
	Sleep(1500);
	cout << "  " << endl;
	cout << "##############################################" << endl;
}
//���������Ĳ�Ʒ���뻺����
void Put()
{
	cout << "��ֿ��з����Ʒ     ";
	pv_buffer[in] = ProductID;
	in = (in + 1) % SIZE_OF_BUFFER;
	Sleep(1500);
	sum = sum + 1;
	cout << "��Ʒ����Ϊ��" << sum << endl;
	cout << "##############################################" << endl;
}
//�ӻ�������ȡ��һ����Ʒ
void Take()
{
	ConsumeID = pv_buffer[out];
	cout << "ȡ�� " << ConsumeID << " �Ų�Ʒ    ";
	pv_buffer[out] = -1;
	out = (out + 1) % SIZE_OF_BUFFER;
	Sleep(1500);
	cout << " " << endl;
	cout << "##############################################" << endl;
}
//����һ����Ʒ
void Consume()
{
	cout << "���� " << ConsumeID << " �Ų�Ʒ        ";
	Sleep(1500);
	sum = sum - 1;
	cout << "��Ʒ����Ϊ��" << sum << endl;
	cout << "##############################################" << endl;
}
//������
DWORD  WINAPI Producer(LPVOID lpPara)
{
	while (pv_continue) {
		WaitForSingleObject(emptySemaphore, INFINITE);  // P(emptySemaphore) �������ź��� -1 
		WaitForSingleObject(pv_hMutex, INFINITE);      // P(Mutex) ��ȡ�̼߳以���ź� 
		Produce();
		Put();
		Sleep(1500);
		ReleaseSemaphore(fullSemaphore, 1, NULL);        // V(fullSemaphore) �������ź��� +1 
		ReleaseMutex(pv_hMutex);                      // V(Mutex) �ͷ��̼߳以���ź� 
	}
	return 0;
}
//������
DWORD  WINAPI Consumer(LPVOID lpPara)
{
	while (pv_continue) {
		WaitForSingleObject(fullSemaphore, INFINITE);   //P(fullSemaphore) �������ź���-1 
		WaitForSingleObject(pv_hMutex, INFINITE);       //P(Mutex) ����̼߳以���ź� 
		Take();
		Consume();
		Sleep(1500);
		ReleaseSemaphore(emptySemaphore, 1, NULL);        //V(emptySemaphore) �������ź���+1 
		ReleaseMutex(pv_hMutex);                       //V(Mutex) �ͷ��̼߳以���ź� 
	}
	return 0;
}
//������Ȩ�㷨*****************************************************************************
typedef struct pcb {
	string pName;//������
	int priorityNumber;//������
	float serviceTime;//����ʱ��
	float estimatedRunningtime;//��������ʱ��
	float startTime;
	float endTime;
	char state;//״̬
	bool operator<(const struct pcb& a)const {
		return priorityNumber < a.priorityNumber || priorityNumber == a.priorityNumber && estimatedRunningtime < a.estimatedRunningtime;
	}
}PCB;
void createProcess(priority_queue<PCB>& p, int n) {//����n�����̣���ͷ���
	cout << "��ʼ��������" << endl;
	PCB r;//�������
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "�����̵����֡�������������ʱ��(����:A 1 2 ):";
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
	cout << "������\t������ ����ʱ�� ������ʱ�� ��ʣ����ʱ��" << endl;
	while (p.size() != 0) {
		s = p.top();
		cout << s.pName << "\t" << s.priorityNumber << "\t " << s.serviceTime << "\t  ";
		cout << s.serviceTime - s.estimatedRunningtime << "\t     " << s.estimatedRunningtime << endl;
		p.pop();
	}
	cout << "----------------------------------------------------------" << endl;
}
void runProcess(priority_queue<PCB>& p) {//���н���
	PCB s;
	while (p.size() != 0) {
		s = p.top();
		p.pop();
		cout << "�������еĽ���" << endl;
		cout << "������\t������ ����ʱ�� ������ʱ�� ��ʣ����ʱ��" << endl;//�����ǰ����
		cout << s.pName << "\t" << s.priorityNumber << "\t " << s.serviceTime << "\t  ";
		cout << s.serviceTime - s.estimatedRunningtime << "\t     " << s.estimatedRunningtime << endl;
		if (s.serviceTime == s.estimatedRunningtime)
		{
			s.startTime = couttime;
		}
		couttime = couttime + 1;
		s.priorityNumber--;//��������1
		s.estimatedRunningtime--;//��������ʱ���1
		if (s.estimatedRunningtime == 0) {
			s.state = 'C';
			s.endTime = couttime;
			cout << "-------------------------------------------------------" << endl;
			cout << "����" << s.pName << "ִ�����" << endl;
			cout << s.pName << "��תʱ��Ϊ" << s.endTime - s.startTime << endl;
			cout << s.pName << "��Ȩ��תʱ��Ϊ" << (s.endTime - s.startTime) / s.serviceTime << endl;
			cout << "--------------------------------------------------------" << endl;
			sumtime = sumtime + (s.endTime - s.startTime);
			sumrighttime = sumrighttime + ((s.endTime - s.startTime) / s.serviceTime);
		}
		else
			p.push(s);
		cout << "����" << s.pName << "ִ��һ��֮����������еĽ���" << endl;
		printProcess(p);
	}
	cout << endl;
}
//�洢����*********************************************************************************
void FIFO(int b, string a)
{
	char m[10] = { '#','#','#','#','#','#','#','#','#','#' };//������������ݳ�ʼ��
	int i = 0, j, x, y = 0, count1 = 0;//yΪ�û����,count1Ϊȱҳ���
	do {
		if (i < b)
		{
			m[y] = a[i];//ȱҳ��ҳ��д��
			i++;
			count1++;//ȱҳ���++
			y = (y + 1) % b;//�û����++
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//��ӡ
				cout << m[j];
			cout << endl;
			continue;
		}
		for (j = 0; j < b; j++)//�ж��Ƿ�ȱҳ
		{
			if (a[i] == m[j])//δȱҳ��x��ֵ1
			{
				x = 1;
				break;
			}
		}

		if (x == 1)//δȱҳ����
		{
			i++;
			x = 0;
			cout << a[i - 1] << " " << endl;
			continue;
		}
		else//ȱҳ����
		{
			m[y] = a[i];
			i++;
			y = (y + 1) % b;
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//��ӡ
				cout << m[j];
			cout << endl;
			count1++;
		}
	} while (a[i] != '#');
	cout << "ҳ��ȱҳ����" << "  " << "ҳ���û�����" << "  " << "ȱҳ��" << endl;
	cout << "     " << count1 << "           " << count1 - b << "           " << 1.0 * count1 / (a.size() - 1) << endl;;
	/*��ӡ�û�������ȱҳ����*/
}
void LRU(int b, string a)
{
	char m[10] = { '#','#','#','#','#','#','#','#','#','#' };
	int i = 0, j, x, y = 0, count1 = 0, min = 10000;//minΪ���δʹ�õĳ�ʼֵ
	cout << "�û��������±�" << endl;
	do {
		if (i < b)
		{
			m[y] = a[i];//ȱҳ��ҳ��д��
			i++;
			count1++;//ȱҳ���++
			y = y + 1;//�û����++
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//��ӡ
				cout << m[j];
			cout << endl;
			continue;
		}
		for (j = 0; j < b; j++)//�ж��Ƿ�ȱҳ
		{
			if (a[i] == m[j])
			{
				x = 1;
				break;
			}
		}

		if (x == 1)//δȱҳ�Ŵ���
		{
			i++;
			x = 0;
			cout << a[i - 1] << " " << endl;
			continue;
		}
		else//ȱҳ����
		{
			for (j = 0; j < b; j++)//�������δʹ�õ�ҳ��
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
			m[y] = a[i];//�û����δʹ�õ�ҳ��
			min = 10000;//��min��ʼ��
			i++;
			cout << a[i - 1] << " ";
			for (j = 0; j < b; j++)//��ӡ
				cout << m[j];
			cout << endl;
			count1++;
		}
	} while (a[i] != '#');
	cout << "ҳ��ȱҳ����" << "  " << "ҳ���û�����" << "  " << "ȱҳ��" << endl;
	cout << "     " << count1 << "           " << count1 - b << "           " << 1.0 * count1 / (a.size() - 1) << endl;;
}
//���м��㷨***********************************************************************************
class bank
{
private:
	int available[Max_source];//������Դ��
	int max[Max_process][Max_source];//�������
	int allocation[Max_process][Max_source];//�ѷ�����Դ��
	int need[Max_process][Max_source];//������Դ��
	int request[Max_process][Max_source];//������Ҫ��Դ��
	bool finish[Max_process];//�ж�ϵͳ�Ƿ����㹻����Դ����
	int p[Max_process];//��¼����
	int m;//������ʾ����
	int n;//��ʾ��Դ
public:
	void Init();//��ɶԱ����ĳ�ʼ��
	bool Safe();//��ȫ����㷨
	void Banker();//���м��㷨
	void Display(int, int);//��ʾ��������Դ״̬

};
void bank::Init()
{
	cout << "�������������";
	cin >> m;
	cout << "��������Դ��������";
	cin >> n;
	cout << "������ÿ�������������ĸ���Դ��" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> max[i][j];
	cout << "������ÿ�������ѷ���ĸ���Դ��" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> allocation[i][j];
			need[i][j] = max[i][j] - allocation[i][j];//ע�������need����С��0��Ҫ���б����������룬������continue��������ǰѭ��
			if (need[i][j] < 0)
			{
				cout << "������ĵ�" << i + 1 << "�����̵ĵ�" << j + 1 << "����Դ�������⣡\n���������룡";
				j--;//���������Դ��
				continue;//��������ѭ��
			}
		}
	cout << "�����������Դ���е���Ŀ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> available[i];
	}
}
//m��ʾ���̣�n��ʾ��Դ
void bank::Display(int n, int m)
{
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "ϵͳ���õ���Դ��Ϊ��	";
	for (int i = 0; i < n; i++)
	{
		cout << available[i] << "	";
	}
	cout << endl << "�����̻���Ҫ����Դ����" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "	����" << i << ":";
		for (int j = 0; j < n; j++)
			cout << "		" << need[i][j];
		cout << endl;
	}
	cout << endl << "�������Ѿ��õ�����Դ:		" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "	����" << i << ":";
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
	int i, cusneed, flag = 0;//cusneed��ʾ��Դ���̺�
	char again;//����¼��һ���ַ������ж��Ƿ����������Դ
	while (1)
	{
		Display(n, m);
		cout << endl;
		/*������Դ*/
		while (true)
		{
			cout << "������Ҫ����Ľ��̺�" << endl;
			cin >> cusneed;
			if (cusneed > m)
			{
				cout << "û�иý��̣�����������" << endl;
				continue;
			}
			cout << "���������������ĸ���Դ��" << endl;
			for (int i = 0; i < n; i++)
				cin >> request[cusneed][i];
			for (int i = 0; i < n; i++)
			{
				if (request[cusneed][i] > need[cusneed][i])
				{
					cout << "���������Դ����������������������������������" << endl;
					continue;
				}
				if (request[cusneed][i] > available[i])
				{
					cout << "���������Դ����������ϵͳ��ǰ��Դӵ������" << endl;
					break;
				}
			}
			break;
		}
		/*��������Դ���󲻺�����������������Դ�������ʱ��ִ�����м��㷨*/
		for (int i = 0; i < n; i++)
		{
			available[i] -= request[cusneed][i];//������Դ��ȥ�ɹ������
			allocation[cusneed][i] += request[cusneed][i];//�ѷ�����Դ���ϳɹ������
			need[cusneed][i] -= request[cusneed][i];//���̻���Ҫ�ļ�ȥ�ɹ������
		}
		/*�жϷ���������Դ��ϵͳ�Ƿ�ȫ���������ȫ�����������Դ����ϵͳ*/
		if (Safe())
			cout << "����ɹ���";
		else
		{
			cout << "����ʧ�ܣ�" << endl;
			/*������ϵͳ������Դ����*/
			for (int i = 0; i < n; i++)
			{
				available[i] += request[cusneed][i];
				allocation[cusneed][i] -= request[cusneed][i];
				need[cusneed][i] += request[cusneed][i];
			}
		}
		/*�Խ��̵�������Դ�����жϣ��Ƿ���Ҫ��Դ������֮�����ж�need�����Ƿ�Ϊ0*/
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
			cout << "����" << cusneed << "ռ�е���Դ���ͷţ���" << endl;
			flag = 0;
		}
		for (int i = 0; i < m; i++)
			finish[i] = false;
		/*�ж��Ƿ��������*/
		cout << "��������: y   ֹͣ���䣺n" << endl;
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
	/*��work������г�ʼ������ʼ��ʱ��avilable������ͬ*/
	for (int i = 0; i < n; i++)
		work[i] = available[i];
	/*��finish�����ʼ��ȫΪfalse*/
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
				p[l++] = i;//��¼���̺�
				i = -1;
			}
			else
				continue;
		}
	}
	if (l == m)
	{
		cout << "ϵͳ�ǰ�ȫ��" << endl;
		cout << "��ȫ���У�" << endl;
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
//���̵����㷨*****************************************************************
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
		cout << "FCFS�㷨\n";
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
		cout << "SSTF�㷨\n";
		Print();
		Reset();
	}
	// dir = true �ƶ�����Ϊ���̺�С����ķ���
	void SCAN(bool dir = true) {
		ScanCscanHelper(dir, 0);
		cout << "SCAN�㷨\n";
		Print();
		Reset();
	}
	void CSCAN(bool dir = true) {
		ScanCscanHelper(dir, 1);
		cout << "CSCAN�㷨\n";
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
		cout << "��ʼ�ŵ��ţ�" << diskStartPos << endl;
		cout << "���ŵ��ţ�" << diskMaxPos << endl;
		cout << "������˳��\t\n";
		for (int diskNow : diskInputSeq)
			cout << diskNow << " ";
		cout << "\nʵ�ʷ���˳��\t\n";
		for (int diskActual : diskOutputSeq)
			cout << diskActual << " ";
		cout << "\n�ƶ��Ĵŵ�����\t" << sumStep << endl;
		cout << "ƽ��Ѱ����\t" << sumStep / diskOutputSeq.size() << "\n";
		cout << "************************************************************************" << endl;
	}
	void Reset() {
		sumStep = 0;
		diskOutputSeq.clear();
	}

private:
	int diskStartPos;			// ��ʼ�Ĵŵ��� or ���̻�е�۵�ǰλ��
	int diskMaxPos;				// ���Ĵŵ���
	double sumStep = 0;			// ���ʵ��ܲ���
	vector<int> diskInputSeq;	// �ŵ�������˳��
	vector<int> diskOutputSeq;	// �ŵ�ʵ�ʵķ���˳��
};
//���������******************************************************
int main()
{
	int NumberChoice;
	cout << "******************************************" << endl;
	cout << "1������������������ģ��" << endl;
	cout << "2����ռʽ�����ȼ��㷨ģ��" << endl;
	cout << "3��FIFO�㷨��LRU�㷨ģ��" << endl;
	cout << "4�����м��㷨ģ��" << endl;
	cout << "5��5�ִ��̵����㷨ģ��" << endl;
	cout << "**********��ѡ��ĳһ���ܽ���ģ��*************" << endl;
	cin >> NumberChoice;
	cout << "*******************************************" << endl;
	if (NumberChoice == 1) {
		//����Mutex��Semaphore
		pv_hMutex = CreateMutex(NULL, FALSE, NULL);
		fullSemaphore = CreateSemaphore(NULL, 0, SIZE_OF_BUFFER, NULL);
		emptySemaphore = CreateSemaphore(NULL, SIZE_OF_BUFFER,
			SIZE_OF_BUFFER, NULL);
		//��������ʼ��
		for (int i = 0; i < SIZE_OF_BUFFER; ++i) {
			pv_buffer[i] = -1;   //��ֵΪ-1ʱ����Ϊ��
		}
		const unsigned short PRODUCERS_COUNT = 3;       //�����ߵĸ���
		const unsigned short CONSUMERS_COUNT = 2;       //�����ߵĸ���						//�ܵ��߳���
		const unsigned short THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;
		HANDLE pvThreads[THREADS_COUNT];     //���̵߳�handle
		DWORD producerID[PRODUCERS_COUNT];  //�������̵߳ı�ʶ��
		DWORD consumerID[CONSUMERS_COUNT];  //�������̵߳ı�ʶ��
		cout << "##############################################" << endl;
		cout << "��ʼ����������СΪ10 " << endl;
		cout << "##############################################" << endl;
		for (int i = 0; i < PRODUCERS_COUNT; i++) {
			pvThreads[i] = CreateThread(NULL, 0, Producer, NULL, 0, &producerID[i]);
			if (pvThreads[i] == NULL) break;
		}
		//�����������߳�
		for (int i = 0; i < CONSUMERS_COUNT; i++) {
			pvThreads[PRODUCERS_COUNT + i]
				= CreateThread(NULL, 0, Consumer, NULL, 0, &consumerID[i]);
			if (pvThreads[i] == NULL) break;
		}
		while (pv_continue) {
			if (getchar()) {  //���س�����ֹ��������
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
		cout << "��������̵ĸ�����";
		cin >> n;
		createProcess(p, n);
		runProcess(p);
		cout << "���н���ִ�����" << endl;
		cout << "ƽ����תʱ��Ϊ" << fixed << setprecision(2) << sumtime / n << endl;
		cout << "ƽ����Ȩ��תʱ��Ϊ" << fixed << setprecision(2) << sumrighttime / n << endl;
		getchar();
		getchar();
		return 0;
	}
	else if (NumberChoice == 3)
	{
		string a;
		int b;
		cout << "�������������:";
		cin >> b;
		cout << "������ҳ������:��#��β��";
		cin >> a;
		cout << "##############################################" << endl;
		cout << "FIFO�㷨����:" << endl;
		FIFO(b, a);
		cout << "##############################################" << endl;
		cout << "LRU�㷨����:" << endl;
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
		cout << "��ѡ��Ҫʹ�õ��㷨" << endl;
		cout << "0������" << endl;
		cout << "1��FCFS" << endl;
		cout << "2��SSTF" << endl;
		cout << "3��SCAN" << endl;
		cout << "4��CSCAN" << endl;
		cout << "5��NsteptSCAN" << endl;
		while (cin >> choice) {
			if (choice == 0) { cout << "����"; break; };//���� 
			if (choice == 1)  disk1.FCFS();//����FCFS�㷨
			if (choice == 2)  disk1.SSTF();//����SSTF�㷨
			if (choice == 3)  disk1.SCAN(false);//����SCAN�㷨
			if (choice == 4)  disk1.CSCAN(false);//����CSCAN�㷨
			if (choice == 5)  disk1.NstepSCAN(3);//����NstepSCAN�㷨
			cout << "��ѡ��Ҫʹ�õ��㷨" << endl;
			cout << "0������" << endl;
			cout << "1��FCFS" << endl;
			cout << "2��SSTF" << endl;
			cout << "3��SCAN" << endl;
			cout << "4��CSCAN" << endl;
			cout << "5��NsteptSCAN" << endl;
		}
		return 0;
	}
	else {
		cout << "������������������" << endl;
	}
}
