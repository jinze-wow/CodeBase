/*1��ֱ����ݹ������
��������ʽ�е�ֱ����ݹ��ǱȽ����׵ġ����������ս��P�Ĺ���Ϊ
P��P�� / ��
���У����ǲ���P��ͷ�ķ��Ŵ�����ô�����ǿ��԰�P�Ĺ����дΪ���µķ�ֱ����ݹ���ʽ��
P����P��
 P������P�� / ��
�����������ԭ���Ĺ����ǵȼ۵ģ���������ʽ��P�Ƴ��ķ��Ŵ�����ͬ�ġ�
���м򵥱��ʽ�ķ�G[E]��
E��E+T/ T
T��T*F/ F
F����E��/ I
������ֱ����ݹ��õ������ķ���
E��TE��
E�� ��+TE��/ ��
T��FT��
T�� ��*FT��/ ��
F����E��/ I
���Ǹ�һ���������ٶ����ڷ��ս��P�Ĺ���Ϊ
P��P��1 / P��2 /��/ P��n / ��1 / ��2 /��/��m
���У���i��I��1��2������n������Ϊ�ţ���ÿ����j��j��1��2������m��������P��ͷ�������������дΪ������ʽ��������P��ֱ����ݹ飺
P����1 P�� / ��2 P�� /��/��m P��
P�� ����1P�� / ��2 P�� /��/ ��n P�� /��
2�������ݹ������
���������ݹ�ķ����ǣ��Ѽ����ݹ��ķ���дΪֱ����ݹ��ķ���Ȼ��������ֱ����ݹ�ķ�����д�ķ���
���һ���ķ������л�·��������PP���Ƶ���Ҳ�������Ԧ�Ϊ�Ҳ��Ĳ���ʽ����ô�Ϳ��Բ��������㷨�����ķ���������ݹ顣
������ݹ��㷨��
���ķ�G�����з��ս������һ˳�����У����磬A1��A2������An��
for ��i��1��i<=n��i++��
for ��j��1��j<=i��1��j++��
{   ������Ai��Aj�õĲ���ʽ��д��Ai����1�� /��2�� /��/��k��
����Aj����1 /��2 /��/��k�ǹ��ڵ�Ajȫ������
����Ai�����е�ֱ����ݹ飻
}
�����ɣ�2�����õ����ķ�����ȥ������Ĺ���
���ô��㷨���Խ������ķ����и�д����������ݹ顣
���ȣ�����ս��������ΪR��Q��S������R��������ֱ����ݹ顣��R���뵽Q�е���ع����У���Q�Ĺ����ΪQ��Sab/ ab/ b��
�������Q������ֱ����ݹ飬�������S��S�Ĺ����ΪS��Sabc/ abc/ bc/ c��
��ʱ��S����ֱ����ݹ顣��������S��ֱ����ݹ�󣬵õ������ķ�Ϊ��
S��abcS��/ bcS��/ cS��
S�� ��abcS��/ ��
Q��Sab/ ab/ b
R��Sa/ a
���Կ������ķ���ʼ����S��������Զ�޷��ﵽQ��R�����Թ���Q��R�Ĺ����Ƕ���ģ�����ɾ�����������õ��ķ�G[S]Ϊ��
S��abcS��/ bcS��/ cS��
S�� ��abcS��/ ��
��Ȼ������ķ����ս������Ĳ�ͬ�����õ����ķ�����ʽ�Ͽ��ܲ�һ���������Ƕ��ǵȼ۵ġ����磬������������ս������ѡΪS��Q��R����ô���õ����ķ�G[R]Ϊ��
R��bcaR��/ caR��/ aR��
R�� ��bcaR��/ ��
����֤�����������ķ��ǵȼ۵ġ�
ָ���Ƿ������ݹ飬�Լ���ݹ�����͡�����ֱ����ݹ飬�ɽ����Ϊֱ���ҵݹ飻���ڼ����ݹ飨Ҳ���ķ���ݹ飩��
��Ӧ�����㷨�������ս����ͬ���еĵȼ۵�������ݹ����ķ�����Ӧ����n���֣�*/

#include<iostream>
#include<string>
using namespace std;
const int MAX_SIZE = 10;
string principle[MAX_SIZE], temp[MAX_SIZE];

int main()
{
    int i = 0, count = 0;
    void removeDirect(int i, int count2);
    void removeIndirect(int i, int j);
    string DFS(string start, string * principle, int count, int temp);
    cout << "�������ĸ�����" << endl;
    cin >> count;
    cout << "������" << count << "������" << endl;
    for (i = 0; i < count; i++)
        cin >> principle[i];
    cout << "ԭ�ķ�Ϊ��" << endl;
    int loc = 0;
    for (i = 0; cout << principle[i] << endl, i < 3; i++);
    cout << endl;
    int start = 0, end = 0;
    int count2 = 0;
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            removeIndirect(i, j);//�����ݹ��ֱ����ݹ�
        }
        removeDirect(i, count2);//����ֱ����ݹ�
    }
    //cout<<"�������ʽ��Ϊ��"<<endl;
    //for(i=0;cout<<principle[i]<<endl,i<count-1;i++);
    //for(i=0;cout<<temp[i]<<endl,i<count2-1;i++);
    cout << "�������ʽ��Ϊ��" << endl;
    string sss = DFS(principle[2], principle, count, 0);
    for (i = 0; i < count; i++) {
        if (sss.find(principle[i][0]) < 100)
            cout << principle[i] << endl;
    }
    for (i = 0; cout << temp[i] << endl, i < count2 - 1; i++);
    return 0;
}

string DFS(string start, string* principle, int count, int temp) {
    string x = "";
    temp++;
    for (int i = 0; i < start.length(); i++) {
        if (start[i] >= 'A' && start[i] <= 'Z' && temp < count) {
            x += start[i];
            for (int j = 0; j < count - 1; j++) {
                if (principle[j][0] == start[i]) {
                    x += DFS(principle[j], principle, count, temp);
                }
            }
        }
    }
    return x;
}


void removeDirect(int i, int count2) {
    //����ֱ����ݹ飬��������A->Ab|c ��ת��Ϊ A->cA'��A'->bA'|~
    string p1 = "", p2 = "";
    size_t flag1 = 3, flag2 = 0;
    char ch = principle[i][0];
    bool last = false; //�ж��Ƿ����
    while (flag1 != string::npos) //Ѱ���ķ��е�|���ţ����h�Ҳ������˳�
    {
        flag2 = principle[i].find_first_of("|", flag1 + 1); //���ķ����ҵ���flag+1��|
        if (flag2 == string::npos)flag2 = principle[i].length(); //ֻ��һ��|
        if (principle[i][flag1] == ch)
        {
            last = true;
            p1 += principle[i].substr(flag1 + 1, flag2 - flag1 - 1) + ch + "\'|";//���ϡ�
        }
        else
        {
            p2 += principle[i].substr(flag1, flag2 - flag1) + ch + "\'|";//���ϡ�
        }
        flag1 = principle[i].find_first_not_of("|", flag2 + 1);
    }
    p2[p2.length() - 1] = '\0';
    if (last)  //����ʱ���Ͽ�~
    {
        temp[count2] = ch + ("\'->" + p1 + "~");
        count2++;
        principle[i].replace(3, principle[i].length() - 3, p2);
    }
}


void removeIndirect(int i, int j) {
    //�����ݹ��ֱ����ݹ�
    int start = 2;
    char aj = principle[j][0];
    //�޸Ĳ���ʽ
    bool rgt = false;
    int count1 = 0;
    string tt[MAX_SIZE];
    size_t s = 0, e = 0;
    do
    {
        start++;
        if (principle[i][start] == aj)//�������Ai->Aj*
        {
            size_t es = principle[i].find_first_of("|", start + 1);
            if (es == string::npos)
                es = principle[i].length();
            string te = principle[i].substr(start + 1, es - start - 1);
            if (!rgt)
            {
                s = principle[j].find_first_not_of("|", 3);
                while (s != string::npos)
                {
                    e = principle[j].find_first_of("|", s + 1);
                    if (e == string::npos)
                        e = principle[j].length();
                    tt[count1] = principle[j].substr(s, e - s);
                    count1++;
                    s = principle[j].find_first_not_of("|", e + 1);
                }
                rgt = true;
            }
            int k = 0;
            string ttl = "\0";
            for (; k < count1 - 1; k++)
                ttl += tt[k] + te + "|";
            ttl += tt[k] + te;
            principle[i].replace(start, es - start, ttl);
        }
        start = principle[i].find_first_of("|", start + 1);
    } while (start != string::npos);
}
/*
 S->Qc|c
 Q->Rb|b
 R->Sa|a

 R->Sa|a
 Q->Rb|b
 S->Qc|c

 Q->Rb|b
 S->Qc|c
 R->Sa|a
 
  A->aB|Bb
  B->Ac|d
 */