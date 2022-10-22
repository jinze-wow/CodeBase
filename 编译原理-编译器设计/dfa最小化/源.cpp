#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#define MAX 507

using namespace std;

struct Node
{
    int x;
    int type;
    Node() {}
    Node(int a, int b)
        :x(a), type(b) {}
    bool operator < (const Node& a) const
    {
        return type < a.type;
    }
};

int mp[MAX][MAX];
vector<int> _edge[MAX];
vector<int> _val[MAX];
vector<int> edge[MAX];
vector<int> val[MAX];
vector<int> point;
vector<pair<int, int> > ans1;
vector<int> ans2;
vector<Node> col;
int fa[MAX];
int type[MAX];
int state[MAX];
int used[MAX];
int kinds;
int groups_num;
int n;
int m;

void init();
int _find(int x);
void _union(int x, int y);
void _add(int u, int v, int x);
void add(int u, int v, int x);
void minimize();
void make_csv();

int main()
{
    init();
    scanf_s("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf_s("%d", &type[i]);
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        scanf_s("%d%d%d", &u, &v, &x);
        _add(u, v, x);
    }
    minimize();
    //最小化后的点的保留结果
    puts("points : ");
    printf("%d\n", (int)point.size());
    for (int i = 0; i < point.size(); i++)
        printf("%d ", point[i]);
    puts("");
    //最小化后的边的保留结果
    puts("edge: ");
    m = ans1.size();
    for (int i = 0; i < ans1.size(); i++)
        printf("%d %d %d\n", ans1[i].first, ans1[i].second, ans2[i]);
    puts("");
    make_csv();
}

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        edge[i].clear();
        _edge[i].clear();
    }
    point.clear();
    memset(type, 255, sizeof(type));
    memset(used, 0, sizeof(used));
    kinds = 0;
    groups_num = 2;
    col.clear();
    for (int i = 0; i < MAX; i++)
        fa[i] = i;
}

void _add(int u, int v, int x)
{
    _edge[u].push_back(v);
    _val[u].push_back(x);
    if (used[x]) return;
    used[x] = x;
    kinds++;
}

void add(int u, int v, int x)
{
    edge[u].push_back(v);
    val[u].push_back(x);
}

int _find(int x)
{
    return x == fa[x] ? x : fa[x] = _find(fa[x]);
}

void _union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    fa[x] = y;
}

void minimize()
{
    queue<vector<Node> > q[2];
    col.clear();
    for (int i = 1; i <= n; i++)
    {
        if (type[i] == 0)
            col.push_back(Node(i, 0));
    }
    q[1].push(col);
    col.clear();
    for (int i = 1; i <= n; i++)
    {
        if (type[i] == 1)
            col.push_back(Node(i, 1));
    }
    q[1].push(col);
    col.clear();
    for (int i = 1; i <= kinds; i++)
    {
        int cur = i % 2;
        int next = (i + 1) % 2;
        while (!q[next].empty()) q[next].pop();
        while (!q[cur].empty())
        {
            vector<Node> front = q[cur].front();
            q[cur].pop();
            for (int j = 0; j < front.size(); j++)
            {
                Node& temp = front[j];
                int u = temp.x;
                for (int k = 0; k < _edge[u].size(); k++)
                {
                    int v = _edge[u][k];
                    int x = _val[u][k];
                    if (x != i) continue;
                    temp.type = type[v];
                }
            }
            sort(front.begin(), front.end());
            if (front[0].type == front[front.size() - 1].type)
                q[next].push(front);
            else
            {
                col.clear();
                col.push_back(front[0]);
                for (int j = 1; j < front.size(); j++)
                {
                    if (front[j].type != front[j - 1].type)
                    {
                        q[cur].push(col);
                        col.clear();
                        groups_num++;
                    }
                    type[front[j].x] = groups_num;
                    col.push_back(front[j]);
                }
                q[cur].push(col);
            }
        }
    }
    //#define DEBUG
#ifdef DEBUG
    int id = (kinds + 1) % 2;
    int num = 1;
    while (!q[id].empty())
    {
        vector<Node> temp = q[id].front();
        q[id].pop();
        printf("%d : ", num++);
        for (int i = 0; i < temp.size(); i++)
            printf("%d ", temp[i].x);
        puts("");
    }

#else
    int id = (kinds + 1) % 2;
    while (!q[id].empty())
    {
        vector<Node> temp = q[id].front();
        q[id].pop();
        for (int i = 1; i < temp.size(); i++)
            _union(temp[i].x, temp[i - 1].x);
    }
    memset(used, 0, sizeof(used));
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= n; i++)
    {
        int x = _find(i);
        if (used[x]) continue;
        used[x] = 1;
        point.push_back(x);
    }
    ans1.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < _edge[i].size(); j++)
        {
            int v = _edge[i][j];
            int x = _val[i][j];
            int a = _find(i);
            int b = _find(v);
            if (mp[a][b]) continue;
            mp[a][b] = 1;
            add(a, b, x);
            ans1.push_back(make_pair(a, b));
            ans2.push_back(x);
        }
#endif
}

void make_csv()
{
    freopen("g1.csv", "w", stdout);
    printf("%d,%d, \n", n, m);
    for (int i = 0; i < point.size(); i++)
        if (i == 0) printf("%d", point[i]);
        else printf(",%d", point[i]);
    puts("");
    for (int i = 0; i < m; i++)
        printf("%d,%d,%d\n", ans1[i].first, ans1[i].second, ans2[i]);
    fclose(stdout);
}