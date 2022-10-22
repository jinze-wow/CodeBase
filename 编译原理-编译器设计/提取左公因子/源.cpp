/*
在判断LL（1）文法是否符合的时候，需要判断LL（1）文法是否存在左公因子，和左递归的情况，
以下给出相应的判断方法以及通过提取左公因子和消除左递归使非LL（1）文法转换为LL（1）法的方法
第一种情况：存在左公因子  ；解决方法：提取左公因子；
若文法中存在形如：
A->ay|ab   两个产生式左部第一个符号相同，则不符合LL（1）文法，指代不明，则表示存在左公因子
解决方法：
转换成 A->aM1,aM2，aM3....的形式：
得：  A->aM  M->y|b   则成功提取左公因子；
第二种情况：存在左递归；
左递归有两种类型： （1）直接左递归 ： A->AB, A∈Vn，B属于V*
（2）间接左递归  A->Bb  B->Aa   A,B∈Vn，a，b属于V*
（这里第二种情况注意，因为是左递归，所以看得就是第一个字符，一定要跟这个类型一样的A->B.... 
以及B->A.... 这种才是左递归，如果A->B.... ,B->aA...,  这种就不是左递归了，因为样式不同，请注意）
同样消除左递归的方法：
如果是间接左递归，则先转换成直接左递归：
例子：
A->Bb | c    B->Aa    将B->Aa代入到另一个式子： A->Aab | c，
转换   A->cM  M->abM    M->ε

就是得出结论，优先删除右部第一个符号和左部相同的即    A->Aab，就是要删除这个右部的第一个A  
然后在所有A相关式子后面补一个新的符号 M   变成A->abM    以及A->cM     
然后再补充一个式子： M->ε 就得到自己需要的符合的LL（1）文法
什么是左因子分解？假设如果特定语法具有多个公共前缀字符串。然后，自上而下的解析器对于解析字符串应该采用哪个产生式感到困惑。
因此，为了消除这种混淆，我们使用左因子分解。使用左分解是为了使语法对自顶向下的解析器有用。
这里我们取出出现在同一个非终结符的 2 个产生式中的左因子。因此，这样做是为了避免解析器回溯。

在左因子分解中
对于公共前缀，我们只制作 1 个产品。
因此，这里的公共前缀可以是终结符或非终结符，也可以是两者的组合。
在新作品的帮助下，添加了其余的推导。
在这个左因子分解过程之后获得的结果被称为左因子分解语法。

这是一个例子：   A -> αB/αC    所以，这里 A、B、C 是非终结符，α 是公因数。左分解后，得到的文法如下。
A -> αS'
S’ -> B/C
在这里我们可以说这基本上是一种语法转换技术。换句话说，左因子分解是一种转换技术，
我们将语法从左递归形式转换为等效的非左递归形式。在下面的 C++ 代码中，要求用户输入父非终端和产生式规则。根据输入生成输出。*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, j, l, i, m;
    int len[10] = {};
    string a, b1, b2, flag;
    char c;
    cout << "Enter the Parent Non-Terminal : ";
    cin >> c;
    a.push_back(c);
    b1 += a + "\'->";
    b2 += a + "\'\'->";;
    a += "->";
    cout << "Enter total number of productions : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the Production " << i + 1 << " : ";
        cin >> flag;
        len[i] = flag.size();
        a += flag;
        if (i != n - 1)
        {
            a += "|";
        }
    }
    cout << "The Production Rule is : " << a << endl;
    char x = a[3];
    for (i = 0, m = 3; i < n; i++)
    {
        if (x != a[m])
        {
            while (a[m++] != '|');
        }
        else
        {
            if (a[m + 1] != '|')
            {
                b1 += "|" + a.substr(m + 1, len[i] - 1);
                a.erase(m - 1, len[i] + 1);
            }
            else
            {
                b1 += "#";
                a.insert(m + 1, 1, a[0]);
                a.insert(m + 2, 1, '\'');
                m += 4;
            }
        }
    }
    char y = b1[6];
    for (i = 0, m = 6; i < n - 1; i++)
    {
        if (y == b1[m])
        {
            if (b1[m + 1] != '|')
            {
                flag.clear();
                for (int s = m + 1; s < b1.length(); s++)
                {
                    flag.push_back(b1[s]);
                }
                b2 += "|" + flag;
                b1.erase(m - 1, flag.length() + 2);
            }
            else
            {
                b1.insert(m + 1, 1, b1[0]);
                b1.insert(m + 2, 2, '\'');
                b2 += "#";
                m += 5;
            }
        }
    }
    b2.erase(b2.size() - 1);
    cout << "After Left Factoring : " << endl;
    cout << a << endl;
    cout << b1 << endl;
    cout << b2 << endl;
    return 0;
}