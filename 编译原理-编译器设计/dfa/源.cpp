/*
采用类似于邻接矩阵的二维数组M存储上述的图结构。首先定义转换函数:

$T:S_i×c → S_j, c∈\Sigma $
该矩阵的行索引表示结点 S i S_i Si​,列索引为对应的字母 c c c,
c c c为字母表中的元素， c ′ c&#x27; c′表示该字符映射之后所得到的下标编号，
因此对于数组M中的元素有如下形式 M [ S i ] [ c ′ ] = S j M[S_i][c&#x27;]=S_j M[Si​][c′]=Sj​,
之所以采用该存储方式，而不采用邻接矩阵是因为该种方法可以保证在O(1)的时间复杂度内查找到对应转换的下一个状态。
定义完上述的存储结构之后，便可以方便地描述整个算法的思路:
算法步骤:
①将当前状态 S c u r r e n t S_{current} Scurrent​设为自动机的起始状态 S b e g i n S_{begin} Sbegin​
②根据输入的字符串中的当前字符 c c u r r e n t c_{current} ccurrent​对当前状态进行装换 
S c u r r e n t = M [ S c u r r e n t ] [ c c u r r e n t ′ ] S_{current}=M[S_{current}][c_{current}&#x27;] Scurrent​=M[Scurrent​][ccurrent′​]
③循环遍历字符串中的每个字符，重复步骤②,如果中间出现无法装换或者字符串遍历结束后未到达终止状态 S e n d S_{end} 
Send​则输入的字符串不匹配。如果字符串匹配完成之后，有 S c u r r e n t S_{current} Scurrent​等于 S e n d S_{end} Send​，则匹配成功。
继续思考
1.状态转换函数对应的字符为集合怎么办？
2.NFA无法编程实现？是不是都得先转化为DFA之后才能编程实现?

*/
#include <iostream>
#include <string>
#include <set>
#include <map>
#define N 10
using namespace std;

map<char, int> alpha2idx;

int Map[N][N];

set<char> alphaSet;//定义字母表，存储所有符号的集合，用于将符号映射到索引

int main()
{
    int n;//表示有转换函数的个数
    int s_begin, s_end;//起始状态和结束状态
    int s0, s1;
    string str;//待识别的字符串
    cin >> n;
    cin >> s_begin >> s_end;
    char alpha;
    int idx4alpha = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Map[i][j] = -1;//初始化邻接矩阵

    for (int i = 0; i < n; i++) {
        cin >> s0 >> alpha >> s1;
        if (alphaSet.find(alpha) == alphaSet.end()) {//判断当前字符是否已经转换为对应的索引
            alpha2idx[alpha] = idx4alpha;
            alphaSet.insert(alpha);
            idx4alpha++;
        }
        Map[s0][alpha2idx[alpha]] = s1;//储存转换函数
    }

    //打印邻接矩阵
//    for(int i=0;i<N;i++){
//        for(int j=0;j<idx4alpha;j++){
//            cout<<Map[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    while (cin >> str) {
        int curState = s_begin;//初始状态
        cout << curState << "->";
        int len = str.size();
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (alphaSet.find(str[i]) == alphaSet.end()) {//判断当前字母是否在字母表里面
                flag = false;
                break;
            }
            else {
                i != len - 1 ? cout << Map[curState][alpha2idx[str[i]]] << "->" : cout << Map[curState][alpha2idx[str[i]]];

                if (Map[curState][alpha2idx[str[i]]] != -1) {//转换函数存在
                    curState = Map[curState][alpha2idx[str[i]]];//更新当前状态
                }
                else {//不存在对应的转换关系
                    flag = false;
                    break;
                }
            }
        }
        cout << endl;
        //判断最后是否达到了结束状态
        if (curState == s_end && flag) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }

    }

    return 0;
}
/*
9
0 4
0 a 1
0 b 2
1 a 1
1 b 3
2 b 2
2 a 1
3 a 1
3 b 4
4 a 1
aaaaaaabb
*/