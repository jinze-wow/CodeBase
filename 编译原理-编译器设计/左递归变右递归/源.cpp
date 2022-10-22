/*1．直接左递归的消除
消除产生式中的直接左递归是比较容易的。例如假设非终结符P的规则为
P→Pα / β
其中，β是不以P开头的符号串。那么，我们可以把P的规则改写为如下的非直接左递归形式：
P→βP’
 P’→αP’ / ε
这两条规则和原来的规则是等价的，即两种形式从P推出的符号串是相同的。
设有简单表达式文法G[E]：
E→E+T/ T
T→T*F/ F
F→（E）/ I
经消除直接左递归后得到如下文法：
E→TE’
E’ →+TE’/ ε
T→FT’
T’ →*FT’/ ε
F→（E）/ I
考虑更一般的情况，假定关于非终结符P的规则为
P→Pα1 / Pα2 /…/ Pαn / β1 / β2 /…/βm
其中，αi（I＝1，2，…，n）都不为ε，而每个βj（j＝1，2，…，m）都不以P开头，将上述规则改写为如下形式即可消除P的直接左递归：
P→β1 P’ / β2 P’ /…/βm P’
P’ →α1P’ / α2 P’ /…/ αn P’ /ε
2．间接左递归的消除
消除间接左递归的方法是，把间接左递归文法改写为直接左递归文法，然后用消除直接左递归的方法改写文法。
如果一个文法不含有回路，即形如PP的推导，也不含有以ε为右部的产生式，那么就可以采用下述算法消除文法的所有左递归。
消除左递归算法：
把文法G的所有非终结符按任一顺序排列，例如，A1，A2，…，An。
for （i＝1；i<=n；i++）
for （j＝1；j<=i－1；j++）
{   把形如Ai→Ajγ的产生式改写成Ai→δ1γ /δ2γ /…/δkγ
其中Aj→δ1 /δ2 /…/δk是关于的Aj全部规则；
消除Ai规则中的直接左递归；
}
化简由（2）所得到的文法，即去掉多余的规则。
利用此算法可以将上述文法进行改写，来消除左递归。
首先，令非终结符的排序为R、Q、S。对于R，不存在直接左递归。把R代入到Q中的相关规则中，则Q的规则变为Q→Sab/ ab/ b。
代换后的Q不含有直接左递归，将其代入S，S的规则变为S→Sabc/ abc/ bc/ c。
此时，S存在直接左递归。在消除了S的直接左递归后，得到整个文法为：
S→abcS’/ bcS’/ cS’
S’ →abcS’/ ε
Q→Sab/ ab/ b
R→Sa/ a
可以看到从文法开始符号S出发，永远无法达到Q和R，所以关于Q和R的规则是多余的，将其删除并化简，最后得到文法G[S]为：
S→abcS’/ bcS’/ cS’
S’ →abcS’/ ε
当然如果对文法非终结符排序的不同，最后得到的文法在形式上可能不一样，但它们都是等价的。例如，如果对上述非终结符排序选为S、Q、R，那么最后得到的文法G[R]为：
R→bcaR’/ caR’/ aR’
R’ →bcaR’/ ε
容易证明上述两个文法是等价的。
指明是否存在左递归，以及左递归的类型。对于直接左递归，可将其改为直接右递归；对于间接左递归（也称文法左递归），
则应按照算法给出非终结符不同排列的等价的消除左递归后的文法。（应该有n！种）*/

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
    cout << "输入规则的个数：" << endl;
    cin >> count;
    cout << "请输入" << count << "个规则：" << endl;
    for (i = 0; i < count; i++)
        cin >> principle[i];
    cout << "原文法为：" << endl;
    int loc = 0;
    for (i = 0; cout << principle[i] << endl, i < 3; i++);
    cout << endl;
    int start = 0, end = 0;
    int count2 = 0;
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            removeIndirect(i, j);//间接左递归变直接左递归
        }
        removeDirect(i, count2);//消除直接左递归
    }
    //cout<<"消除后的式子为："<<endl;
    //for(i=0;cout<<principle[i]<<endl,i<count-1;i++);
    //for(i=0;cout<<temp[i]<<endl,i<count2-1;i++);
    cout << "消除后的式子为：" << endl;
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
    //消除直接左递归，即将形如A->Ab|c 的转化为 A->cA'和A'->bA'|~
    string p1 = "", p2 = "";
    size_t flag1 = 3, flag2 = 0;
    char ch = principle[i][0];
    bool last = false; //判断是否结束
    while (flag1 != string::npos) //寻找文法中的|符号，如果h找不到则退出
    {
        flag2 = principle[i].find_first_of("|", flag1 + 1); //在文法中找到第flag+1个|
        if (flag2 == string::npos)flag2 = principle[i].length(); //只有一个|
        if (principle[i][flag1] == ch)
        {
            last = true;
            p1 += principle[i].substr(flag1 + 1, flag2 - flag1 - 1) + ch + "\'|";//加上‘
        }
        else
        {
            p2 += principle[i].substr(flag1, flag2 - flag1) + ch + "\'|";//加上’
        }
        flag1 = principle[i].find_first_not_of("|", flag2 + 1);
    }
    p2[p2.length() - 1] = '\0';
    if (last)  //结束时加上空~
    {
        temp[count2] = ch + ("\'->" + p1 + "~");
        count2++;
        principle[i].replace(3, principle[i].length() - 3, p2);
    }
}


void removeIndirect(int i, int j) {
    //间接左递归变直接左递归
    int start = 2;
    char aj = principle[j][0];
    //修改产生式
    bool rgt = false;
    int count1 = 0;
    string tt[MAX_SIZE];
    size_t s = 0, e = 0;
    do
    {
        start++;
        if (principle[i][start] == aj)//如果满足Ai->Aj*
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