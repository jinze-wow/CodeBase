#include<stdio.h>//实验四
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define Max 11
#define MX 999999
int D[Max][Max];
int path[Max][Max];
typedef struct Ver{//顶点信息
    char num[5];
    char name[51];
    char instruct[101];
}Ver;
typedef struct{//邻接矩阵
    Ver vex[Max];//顶点表
    int arcs[Max][Max];
    int vnum,arcnum;
}AMGragh;
void menu(){
    cout<<"************欢迎您************"<<endl;
    cout<<"        1、查看所有景点           "<<endl;
    cout<<"        2、景点查询               "<<endl;
    cout<<"        3、问路                   "<<endl;
    cout<<"        4、修改景点基本信息       "<<endl;
    cout<<"        5、退出                   "<<endl;
    cout<<"**********************************"<<endl;
    cout<<"请选择..."<<endl;
}
void Allprint(AMGragh G){//输出所有景点信息
    cout<<"---------------校园景点总览---------------"<<endl;
    cout<<"景点名称   "<<"  "<<"代号"<<"     "<<"    简介"<<endl;
    for(int i=0;i<G.vnum;i++){
        cout<<G.vex[i].name<<"    "<<G.vex[i].num<<"   "<<G.vex[i].instruct<<endl;
    }
    cout<<endl;
}
void CreateUDG(AMGragh &G){//建图
    G.vnum=10;
    strcpy(G.vex[0].num,"01");
    strcpy(G.vex[1].num,"02");
    strcpy(G.vex[2].num,"03");
    strcpy(G.vex[3].num,"04");
    strcpy(G.vex[4].num,"05");
    strcpy(G.vex[5].num,"06");
    strcpy(G.vex[6].num,"07");
    strcpy(G.vex[7].num,"08");
    strcpy(G.vex[8].num,"09");
    strcpy(G.vex[9].num,"10");
    strcpy(G.vex[0].name,"北苑美食城");
    strcpy(G.vex[1].name,"北操场    ");
    strcpy(G.vex[2].name,"体育馆    ");
    strcpy(G.vex[3].name,"图书馆    ");
    strcpy(G.vex[4].name,"广场1     ");
    strcpy(G.vex[5].name,"广场2     ");
    strcpy(G.vex[6].name,"湿地公园  ");
    strcpy(G.vex[7].name,"公园2     ");
    strcpy(G.vex[8].name,"湖 1      ");
    strcpy(G.vex[9].name,"公园3     ");
    strcpy(G.vex[0].instruct,"北苑美食城里面有各种各样的美食，可以让你大饱口福");
    strcpy(G.vex[1].instruct,"北操场是北苑的一个运动场地，也是一个篮球场");
    strcpy(G.vex[2].instruct,"体育馆设施齐全，建筑优美，在此可以尽情享受运动的快乐！");
    strcpy(G.vex[3].instruct,"图书馆环境安适，藏书丰富，让人感受阅读的美好");
    strcpy(G.vex[4].instruct,"广场1与学校西门相邻，也是升国旗的地方");
    strcpy(G.vex[5].instruct,"广场2上会举办一些文艺晚会和校园招聘会，更是轮滑爱好者的乐园");
    strcpy(G.vex[6].instruct,"湿地公园有小石桥和美丽的树木，让人心旷神怡");
    strcpy(G.vex[7].instruct,"公园2的标志是一对白色的大海豚，坐落在水中央，夏天水中开有漂亮的莲花");
    strcpy(G.vex[8].instruct,"湖 1的水清澈见底，还能看到活泼的小鱼");
    strcpy(G.vex[9].instruct,"公园3里往届校友栽的树，生机勃勃，代表着他们对母校的爱");
    G.arcs[1][2]=G.arcs[2][1]=2;
    G.arcs[1][9]=G.arcs[9][1]=19;
    G.arcs[2][3]=G.arcs[3][2]=3;
    G.arcs[2][4]=G.arcs[4][2]=5;
    G.arcs[3][4]=G.arcs[4][3]=2;
    G.arcs[4][5]=G.arcs[5][4]=3;
    G.arcs[4][7]=G.arcs[7][4]=29;
    G.arcs[4][10]=G.arcs[10][4]=33;
    G.arcs[5][6]=G.arcs[6][5]=6;
    G.arcs[6][7]=G.arcs[7][6]=7;
    G.arcs[7][8]=G.arcs[8][7]=8;
    G.arcs[8][9]=G.arcs[9][8]=1;
    G.arcs[9][10]=G.arcs[10][9]=2;
    for(int i=1;i<=10;i++)//初始化路径长度
        for(int j=1;j<=10;j++){
            if(G.arcs[i][j]==0&&i!=j)
                G.arcs[i][j]=MX;
        }
    G.arcnum=13;
}
void Change(AMGragh &G){//修改信息
    Allprint(G);
    cout<<"请输入要修改信息的代号：";
    char c[5];
    cin>>c;
    for(int i=0;i<G.vnum;i++){
        if(strcmp(c,G.vex[i].num)==0)//字符串比较的方法进行查找
        {
            memset(G.vex[i].name,0,sizeof(G.vex[i].name));
            memset(G.vex[i].num,0,sizeof(G.vex[i].num));
            memset(G.vex[i].instruct,0,sizeof(G.vex[i].instruct));
            char num1[5];
            char name1[51];
            char instruct1[101];
            cout<<"请输入修改后的景点信息："<<endl;
            cout<<"景点名称：";
            scanf("%s",name1);
            cout<<"代号：";
            scanf("%s",num1);
            cout<<"简介：";
            scanf("%s",instruct1);
            strcpy(G.vex[i].name,name1);
            strcpy(G.vex[i].num,num1);
            strcpy(G.vex[i].instruct,instruct1);
            cout<<"修改成功！"<<endl;
            break;
        }
    }
}
void Query(AMGragh G){//查询景点
    cout<<"请输入查询景点的代号：";
    char c[5];
    cin>>c;
    int i;
    for(i=0;i<G.vnum;i++)
        if(strcmp(c,G.vex[i].num)==0)
        {
            cout<<"景点名称："<<G.vex[i].name<<"   ";
            cout<<"代号："<<G.vex[i].num<<"   ";
            cout<<"简介："<<G.vex[i].instruct<<endl;
            break;
        }
    if(i==G.vnum)
        cout<<"该代号不存在!"<<endl;
}
void Floyd(AMGragh G){//弗洛伊德算法，获得最短路径
    int i,j,k;
    for(i=1;i<=G.vnum;++i)
        for(j=1;j<=G.vnum;j++){
            D[i][j]=G.arcs[i][j];
            if(D[i][j]<MX&&i!=j)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    for(k=1;k<=G.vnum;k++)
        for(i=1;i<=G.vnum;++i)
            for(j=1;j<=G.vnum;j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j]=path[k][j];
                }
}
void Path(AMGragh G,int a,int b){//获得具体路径
   int p[Max];
   p[0]=b;
   int i=1;
   while(a!=b){
    b=path[a][b];
    p[i]=b;
    ++i;
   }
   cout<<"路径:"<<G.vex[a-1].name;
   i=i-2;
   while(i>=0){
    cout<<"--->"<<G.vex[p[i]-1].name;
    --i;
   }
}
void Ask(AMGragh G){//问路
    Allprint(G);
    cout<<"请输入起点和目的地(1~10，即第几个景点,中间用空格隔开):";
    int a,b;
    cin>>a>>b;
    Floyd(G);
    cout<<endl<<endl<<"从"<<G.vex[a-1].name<<"到"<<G.vex[b-1].name<<":"<<endl<<endl<<"最短路径长度："<<D[a][b]*10<<"米"<<endl;
    Path(G,a,b);
    cout<<endl;
}
int main(){
    AMGragh G;
    memset(G.arcs,0,sizeof(G.arcs));
    CreateUDG(G);
    int m;
    while(m!=5){
        menu();
        cin>>m;
        switch(m){
        case 1:
            Allprint(G);
            break;
        case 2:
            Query(G);
            break;
        case 3:
            Ask(G);
            break;
        case 4:
            Change(G);
            break;
        case 5:
            cout<<"感谢您的使用！"<<endl;
            return 0;
        default:
            cout<<"没有该选项！"<<endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
