/*���ķ�G[S]����VN��VT��P��S���������ַ���Ϊ��
FIRST��������{ a | ��a�£�a��VT����,�¡�V* }��
�����ţ��š�FIRST��������
�ɶ�����Կ�����FIRST��������ָ���Ŵ����ܹ��Ƶ��������з��Ŵ��д��ڴ��׵��ս������ɵļ��ϡ�����FIRST��Ҳ��Ϊ�׷��ż���
�����x1x2��xn��FIRST�������ɰ����з�����ã�
��FIRST������������i��1��
��xi��VT����xi��FIRST��������
��xi��VN��
�� ����FIRST��xi������FIRST��xi����FIRST��������
�� ���š�FIRST��xi������FIRST��xi����{ �� }��FIRST��������
i��i + 1���ظ���1������2����ֱ��xi��VT����i��2��3������n����xi��VN������FIRST��xi����i > nΪֹ��
��һ���ķ��д��ڦŲ���ʽʱ�����磬����A���ţ�ֻ��֪����Щ���ſ��ԺϷ��س����ڷ��ս��A֮�󣬲���֪���Ƿ�ѡ��A���Ų���ʽ����Щ�Ϸ��س����ڷ��ս��A֮��ķ�����ɵļ��ϱ���ΪFOLLOW���ϡ��������Ǹ����ķ���FOLLOW���Ķ��塣
���ķ�G[S]����VN��VT��P��S������
FOLLOW��A����{ a | S�� Aa ����a��VT }��
��S��A��#��FOLLOW��A����
�ɶ�����Կ�����FOLLOW��A����ָ���ķ�G[S]�����о����У������ڷ��ս��A����ս���ŵļ��ϡ�
FOLLOW���ɰ����з�����ã�
�����ķ�G[S]�Ŀ�ʼ����S����#��FOLLOW��S����
���ķ�G[S]��������B��xAy�Ĺ�������x��y��V * ����FIRST��y����{ �� }��FOLLOW��A����
���ķ�G[S]��������B��xA�Ĺ��򣬻�����B��xAy�Ĺ����Ҧš�FIRST��y��������x��y��V * ����FOLLOW��B����FOLLOW��A����*/
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAX 50
int NONE[MAX] = { 0 };
string strings;       //����ʽ
string Vn;           //���ս��
string Vt;           //�ս��
string first[MAX];  //���ÿ���ս����first��
string First[MAX];  //���ÿ�����ս����first��
string Follow[MAX]; //���ÿ�����ս����follow��
int N;               //����ʽ����
struct STR
{
	string left;
	string right;
};

void rec(STR* p)                 //ʶ��Vn��Vt
{
	int i, j;
	for (i = 0; i < N; i++)                                              //��i������ʽ
	{
		for (j = 0; j < (int)p[i].left.length(); j++)//���
		{
			if ((p[i].left[j] >= 'A' && p[i].left[j] <= 'Z'))                //����j����ĸ�Ǵ�д
			{
				if (Vn.find(p[i].left[j]) > 100)                             //Vn��û�ҵ����غܴ��ֵ
					Vn += p[i].left[j];
			}
			else
			{
				if (Vt.find(p[i].left[j]) > 100)                           //Сд��ĸ��Vt
					Vt += p[i].left[j];
			}
		}
		for (j = 0; j < (int)p[i].right.length(); j++)//�Ҳ�
		{
			if (!(p[i].right[j] >= 'A' && p[i].right[j] <= 'Z'))
			{
				if (Vt.find(p[i].right[j]) > 100)
					Vt += p[i].right[j];
			}
			else
			{
				if (Vn.find(p[i].right[j]) > 100)
					Vn += p[i].right[j];
			}
		}
	}
}
void getlr(STR* p, int i)                                             //������ʽ�����Ҳ��ֱ����left��right
{
	int j;
	for (j = 0; j < strings.length(); j++)
	{
		if (strings[j] == '-' && strings[j + 1] == '>')
		{
			p[i].left = strings.substr(0, j);
			p[i].right = strings.substr(j + 2, strings.length() - j);
		}
	}
}

string Letter_First(STR* p, char ch)
{
	int t;
	if (!(Vt.find(ch) > 100))                        //��Vt�first��������
	{
		first[Vt.find(ch)] = ch;
		return first[Vt.find(ch) - 1];
	}
	if (!(Vn.find(ch) > 100))                      //��Vn�еĵ�i��
	{
		for (int i = 0; i < N; i++)                //��i������ʽ
		{
			if (p[i].left[0] == ch)             //����ַ���ch
			{
				if (!(Vt.find(p[i].right[0]) > 100))
				{
					if (First[Vn.find(ch)].find(p[i].right[0]) > 100)     //�Ҳ��һ���ַ���Vt������Vni��first������
					{
						First[Vn.find(ch)] += p[i].right[0];
					}
				}
				if (p[i].right[0] == '#')
				{
					if (First[Vn.find(ch)].find('#') > 100)           //�Ҳ��һ���ַ��ǿգ�����Vni��first������
					{
						First[Vn.find(ch)] += '#';
					}
				}
				if (!(Vn.find(p[i].right[0]) > 100))                //�Ҳ��һ����ĸ��Vn
				{
					if (p[i].right.length() == 1)                      //ֻ��һ����ĸ
					{
						string ff;
						ff = Letter_First(p, p[i].right[0]);                        //���Ҳ���ĸ��first���ϼ��뵽�����ĸ��
						for (int k = 0; k < ff.length(); k++)
						{
							if (First[Vn.find(ch)].find(ff[k]) > 100)
							{
								First[Vn.find(ch)] += ff[k];
							}
						}
					}
					else                                               //�����ĸ����Vn
					{
						for (int j = 0; j < p[i].right.length(); j++)
						{

							string TT;
							TT = Letter_First(p, p[i].right[j]);
							if (!(TT.find('#') > 100) && (j + 1) < p[i].right.length())             //�Ҳ��ĩλ��ĸ��first�����п�
							{
								for (int t = 0; t < TT.length(); t++)
								{
									if (TT[t] != '#' && First[Vn.find(ch)].find(TT[t]) > 100)       //�Ҳ���ĸ���޿�first�����뵽Vni��first��
										First[Vn.find(ch)] += TT[t];
								}
								//cout << p[i].right[j]<<"already ";
							}
							else                                                                 //�������޿ջ��пյ������һ����ֱ�Ӽ���
							{
								for (t = 0; t < TT.length(); t++)
								{
									if (First[Vn.find(ch)].find(TT[t]) > 100)
										First[Vn.find(ch)] += TT[t];
								}
								break;
							}
						}
					}
				}
			}
		}
		return  First[Vn.find(ch)];
	}
}
string Letter_Follow(STR* p, char ch)
{
	int t, k;
	NONE[Vn.find(ch)]++;                  //ɨ��1��
	if (NONE[Vn.find(ch)] == 2)
	{
		NONE[Vn.find(ch)] = 0;
		return Follow[Vn.find(ch)];      //�ڶ���ɨ����ֱ�ӷ���
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < p[i].right.length(); j++)
		{
			if (p[i].right[j] == ch)                       //�Ҳ�ɨ�赽A
			{
				if (j + 1 == p[i].right.length())                  //A��ĩβ        S->aA
				{
					string gg;
					gg = Letter_Follow(p, p[i].left[0]);
					//	NONE[Vn.find(p[i].left[0])] = 0;              //NONE[S]=0    A->aA  NONE[A]��0��ɨ
					for (int k = 0; k < gg.length(); k++)
					{
						if (Follow[Vn.find(ch)].find(gg[k]) > 100)          //S��follow���뵽A��
						{
							Follow[Vn.find(ch)] += gg[k];
						}
					}
				}
				else                                                //A����ĩβ      S->AB
				{
					string FF;
					for (int m = j + 1; m < p[i].right.length(); m++)
					{
						string TT;
						TT = Letter_First(p, p[i].right[m]);
						if (!(TT.find('#') > 100) && (m + 1) < p[i].right.length())              //A�����Vn��first���п��Ҳ������һ��
						{
							for (t = 0; t < TT.length(); t++)
							{
								if (FF.find(TT[t]) > 100 && TT[t] != '#')                         //ȥ���ռ���
									FF += TT[t];
							}
						}
						else {                                                                  //first��û�пջ������һ���п�
							for (t = 0; t < TT.length(); t++)
							{
								if (FF.find(TT[t]) > 100)
									FF += TT[t];
							}
							break;                                                             //û�յ�ֱ��break
						}
					}
					if (FF.find('#') > 100)
					{
						for (k = 0; k < FF.length(); k++)
						{
							if (Follow[Vn.find(ch)].find(FF[k]) > 100)
								Follow[Vn.find(ch)] += FF[k];

						}
					}
					else {
						for (k = 0; k < FF.length(); k++)
						{
							if ((Follow[Vn.find(ch)].find(FF[k]) > 100) && FF[k] != '#')
							{
								Follow[Vn.find(ch)] += FF[k];
							}
						}
						string dd;
						dd = Letter_Follow(p, p[i].left[0]);                   //���һ���п� S��follow����A��follow
						//NONE[Vn.find(p[i].left[0])] = 0;
						for (k = 0; k < dd.length(); k++)
						{
							if (Follow[Vn.find(ch)].find(dd[k]) > 100)
							{
								Follow[Vn.find(ch)] += dd[k];
							}
						}
					}
				}
			}
		}
	}  return Follow[Vn.find(ch)];
}
int main()
{
	int i, j, k;
	cout << "���������ʽ����:";
	cin >> N;
	cout << "\n�����������ʽ��#����գ�:" << endl;
	STR* p = new STR[MAX];
	for (i = 0; i < N; i++)
	{
		cin >> strings;
		getlr(p, i);
	}
	rec(p);
	cout << endl;
	cout << "\n=========================================" << endl;
	cout << "���ս��" << "\t" << "FIRST" << "\t\t" << "FOLLOW" << endl;
	for (i = 0; i < Vn.length(); i++)
	{
		cout << "  " << Vn[i] << "\t\t{";
		string pp;
		pp = Letter_First(p, Vn[i]);
		for (j = 0; j + 1 < pp.length(); j++)
		{
			cout << pp[j] << ",";
		}
		cout << pp[pp.length() - 1] << "} ";
		Follow[0] += '$';                              //��ʼ������$
		cout << " {";
		string ppp;
		ppp = Letter_Follow(p, Vn[i]);
		for (k = 0; k + 1 < ppp.length(); k++)
		{
			cout << ppp[k] << ",";
		}
		cout << ppp[ppp.length() - 1] << "}" << endl;
	}
	cout << "\n=========================================" << endl;
	return 0;
}