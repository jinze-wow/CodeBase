#include<stdio.h>//ʵ����
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define Max 11
#define MX 999999
int D[Max][Max];
int path[Max][Max];
typedef struct Ver{//������Ϣ
    char num[5];
    char name[51];
    char instruct[101];
}Ver;
typedef struct{//�ڽӾ���
    Ver vex[Max];//�����
    int arcs[Max][Max];
    int vnum,arcnum;
}AMGragh;
void menu(){
    cout<<"************��ӭ��************"<<endl;
    cout<<"        1���鿴���о���           "<<endl;
    cout<<"        2�������ѯ               "<<endl;
    cout<<"        3����·                   "<<endl;
    cout<<"        4���޸ľ��������Ϣ       "<<endl;
    cout<<"        5���˳�                   "<<endl;
    cout<<"**********************************"<<endl;
    cout<<"��ѡ��..."<<endl;
}
void Allprint(AMGragh G){//������о�����Ϣ
    cout<<"---------------У԰��������---------------"<<endl;
    cout<<"��������   "<<"  "<<"����"<<"     "<<"    ���"<<endl;
    for(int i=0;i<G.vnum;i++){
        cout<<G.vex[i].name<<"    "<<G.vex[i].num<<"   "<<G.vex[i].instruct<<endl;
    }
    cout<<endl;
}
void CreateUDG(AMGragh &G){//��ͼ
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
    strcpy(G.vex[0].name,"��Է��ʳ��");
    strcpy(G.vex[1].name,"���ٳ�    ");
    strcpy(G.vex[2].name,"������    ");
    strcpy(G.vex[3].name,"ͼ���    ");
    strcpy(G.vex[4].name,"�㳡1     ");
    strcpy(G.vex[5].name,"�㳡2     ");
    strcpy(G.vex[6].name,"ʪ�ع�԰  ");
    strcpy(G.vex[7].name,"��԰2     ");
    strcpy(G.vex[8].name,"�� 1      ");
    strcpy(G.vex[9].name,"��԰3     ");
    strcpy(G.vex[0].instruct,"��Է��ʳ�������и��ָ�������ʳ����������󱥿ڸ�");
    strcpy(G.vex[1].instruct,"���ٳ��Ǳ�Է��һ���˶����أ�Ҳ��һ������");
    strcpy(G.vex[2].instruct,"��������ʩ��ȫ�������������ڴ˿��Ծ��������˶��Ŀ��֣�");
    strcpy(G.vex[3].instruct,"ͼ��ݻ������ʣ�����ḻ�����˸����Ķ�������");
    strcpy(G.vex[4].instruct,"�㳡1��ѧУ�������ڣ�Ҳ��������ĵط�");
    strcpy(G.vex[5].instruct,"�㳡2�ϻ�ٰ�һЩ��������У԰��Ƹ�ᣬ�����ֻ������ߵ���԰");
    strcpy(G.vex[6].instruct,"ʪ�ع�԰��Сʯ�ź���������ľ�������Ŀ�����");
    strcpy(G.vex[7].instruct,"��԰2�ı�־��һ�԰�ɫ�Ĵ��࣬������ˮ���룬����ˮ�п���Ư��������");
    strcpy(G.vex[8].instruct,"�� 1��ˮ�峺���ף����ܿ������õ�С��");
    strcpy(G.vex[9].instruct,"��԰3������У���Ե������������������������Ƕ�ĸУ�İ�");
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
    for(int i=1;i<=10;i++)//��ʼ��·������
        for(int j=1;j<=10;j++){
            if(G.arcs[i][j]==0&&i!=j)
                G.arcs[i][j]=MX;
        }
    G.arcnum=13;
}
void Change(AMGragh &G){//�޸���Ϣ
    Allprint(G);
    cout<<"������Ҫ�޸���Ϣ�Ĵ��ţ�";
    char c[5];
    cin>>c;
    for(int i=0;i<G.vnum;i++){
        if(strcmp(c,G.vex[i].num)==0)//�ַ����Ƚϵķ������в���
        {
            memset(G.vex[i].name,0,sizeof(G.vex[i].name));
            memset(G.vex[i].num,0,sizeof(G.vex[i].num));
            memset(G.vex[i].instruct,0,sizeof(G.vex[i].instruct));
            char num1[5];
            char name1[51];
            char instruct1[101];
            cout<<"�������޸ĺ�ľ�����Ϣ��"<<endl;
            cout<<"�������ƣ�";
            scanf("%s",name1);
            cout<<"���ţ�";
            scanf("%s",num1);
            cout<<"��飺";
            scanf("%s",instruct1);
            strcpy(G.vex[i].name,name1);
            strcpy(G.vex[i].num,num1);
            strcpy(G.vex[i].instruct,instruct1);
            cout<<"�޸ĳɹ���"<<endl;
            break;
        }
    }
}
void Query(AMGragh G){//��ѯ����
    cout<<"�������ѯ����Ĵ��ţ�";
    char c[5];
    cin>>c;
    int i;
    for(i=0;i<G.vnum;i++)
        if(strcmp(c,G.vex[i].num)==0)
        {
            cout<<"�������ƣ�"<<G.vex[i].name<<"   ";
            cout<<"���ţ�"<<G.vex[i].num<<"   ";
            cout<<"��飺"<<G.vex[i].instruct<<endl;
            break;
        }
    if(i==G.vnum)
        cout<<"�ô��Ų�����!"<<endl;
}
void Floyd(AMGragh G){//���������㷨��������·��
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
void Path(AMGragh G,int a,int b){//��þ���·��
   int p[Max];
   p[0]=b;
   int i=1;
   while(a!=b){
    b=path[a][b];
    p[i]=b;
    ++i;
   }
   cout<<"·��:"<<G.vex[a-1].name;
   i=i-2;
   while(i>=0){
    cout<<"--->"<<G.vex[p[i]-1].name;
    --i;
   }
}
void Ask(AMGragh G){//��·
    Allprint(G);
    cout<<"����������Ŀ�ĵ�(1~10�����ڼ�������,�м��ÿո����):";
    int a,b;
    cin>>a>>b;
    Floyd(G);
    cout<<endl<<endl<<"��"<<G.vex[a-1].name<<"��"<<G.vex[b-1].name<<":"<<endl<<endl<<"���·�����ȣ�"<<D[a][b]*10<<"��"<<endl;
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
            cout<<"��л����ʹ�ã�"<<endl;
            return 0;
        default:
            cout<<"û�и�ѡ�"<<endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
