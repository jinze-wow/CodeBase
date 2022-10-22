

typedef struct
{
    int weight;
    int lchild,rchild,parent;
} HTNode,*HuffmanTree;


void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
    int i=1;
    while(HT[i].parent!=0&&i<=n)//找到一个还没连接的，即parent=0；
        i++;
    if(i==n+1)
        return ;
    s1=i;
    i++;
    while(HT[i].parent!=0&&i<=n)//同上
        i++;
    if(i==n+1)
        return ;
    s2=i;
    i++;
    if(HT[s1].weight>HT[s2].weight)//让s1比s2小
        swap(s1,s2);
    for(; i<=n; i++)
    {
        if(HT[i].parent==0)
        {
            if(HT[i].weight<HT[s1].weight)
                s2=s1,s1=i;
            else if(HT[i].weight<HT[s2].weight)
                s2=i;
        }
    }
    return ;
}


void CreatHuffmanTree(HuffmanTree &HT,int n)
{
    if(n<=1)
        return ;
    int m=2*n-1;//树共有2n-1个节点
    HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));//从1开始多申请一个
    for(int i=1; i<=m; i++)//初始化
    {
        HT[i].lchild=0;
        HT[i].parent=0;
        HT[i].rchild=0;
        HT[i].weight=0;
    }
    for(int i=1; i<=n; i++)
        cin>>HT[i].weight;
    int s1,s2;
    for(int i=n+1; i<=m; i++)//后n-1个节点的创建
    {
        Select(HT,i-1,s1,s2);//新节点的权值为两个最小的权值和
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    return ;
}


void CreatHuffmanCode(HuffmanTree &HT,char ** &HC,int n)
{
    char *col;
    HC=(char **)malloc(sizeof(char *)*(n+1));
    col=(char *)malloc(sizeof(char)*n);//存储每个编码的临时空间
    col[n-1]='\0';
    //为什么是n-1,n个节点创建的哈夫曼树高为n-1
    //路径条数为n-2，最长的只有n-2个数字。
    for(int i=1; i<=n; i++)
    {
        int str=n-1;
        int p=i,f=i;
        while(HT[f].parent!=0)//从叶向上寻找
        {
            f=HT[f].parent;
            if(HT[f].lchild==p)
                col[--str]='0';
            else if(HT[f].rchild==p)
                col[--str]='1';
            p=f;
        }
        HC[i]=(char *)malloc(sizeof(char)*(n-str));    //为第i个字符编码分配空间
        strcpy(HC[i],&col[str]);//复制到编码中
    }
    free(col);
    return ;
}

void TransCode(HuffmanTree HT,char b[],char a[],char c[],int n)
{
    //b数组是要翻译的二进制编码
    //a数组是叶子对应的字符
    //c数组存储翻译得到的内容
    FILE *fw;
    int q=2*n-1;   //初始化为根结点的下标
    int k=0;
    int len=strlen(b);
    if((fw=fopen("textfile.txt","w"))==NULL)
        cout<<"Open file error!"<<endl;
    for(int i=0; i<len; i++)
    {
        if(b[i]=='0')
            q=HT[q].lchild;
        else if(b[i]=='1')
            q=HT[q].rchild;
        if(HT[q].lchild==0&&HT[q].rchild==0)//叶子节点，此时可译
        {
            c[k++]=a[q];
            fputc(a[q],fw);
            q=2*n-1;
        }
        c[k]='\0';
    }
    return ;
}


void Coding(HuffmanTree &HT,char ** &HC,int n,char a[])
{
    FILE *fp,*fw;
    char c;
    int k;
    if((fp=fopen("tobetran.txt","r"))==NULL)
        cout<<"Open file error!"<<endl;
    if((fw=fopen("codefile.txt","w"))==NULL)
        cout<<"Open file error!"<<endl;
    fscanf(fp,"%c",&c);//从文件中读取一个字符
    while(!feof(fp))
    {
        for(int i=1; i<=n; i++)
            if(a[i]==c)//找到对应的编码
            {
                k=i;
                break;
            }
        for(int i=0; HC[k][i]!='\0'; i++)//输出该字符编码
            fputc(HC[k][i],fw);
        fscanf(fp,"%c",&c);//继续下一个
    }
    fclose(fp);
    fclose(fw);
    return ;
}

void printf_code()
{
    FILE *fp,*fw;
    char temp;
    if((fp=fopen("codefile.txt","r"))==NULL)
        cout<<"error"<<endl;
    if((fw=fopen("codeprin.txt","w"))==NULL)
        cout<<"error"<<endl;
    cout<<"codefile.txt："<<endl;
    fscanf(fp,"%c",&temp);
    for(int i=1;!feof(fp);i++)
    {
        printf("%c",temp);
        if(i%50==0)//50个一换行
            cout<<endl;
        fputc(temp,fw);//再写到codeprint文件中
        fscanf(fp,"%c",&temp);
    }
    cout<<endl;
    cout<<"编码已存入文件codeprin.txt"<<endl;
    fclose(fp);
    fclose(fw);
}

void co_tree(unsigned char T[100][100],int s,int *m,int j,HuffmanTree HT)
{
    int k,l;
    l=++(*m);
    for(k=0;k<s;k++)//深度越深，前面空格越多
        T[l][k]=' ';
    T[l][k]=HT[j].weight;
    if(HT[j].lchild)
        co_tree(T,s+1,m,HT[j].lchild,HT);
    if(HT[j].rchild)
        co_tree(T,s+1,m,HT[j].rchild,HT);
    T[l][++k]='\0';
    return ;
}
void printf_tree(int num,HuffmanTree HT)
{
    unsigned char T[100][100];
    FILE *fp;
    int m=0;
    co_tree(T,0,&m,2*num-1,HT);
    if((fp=fopen("treeprin.txt","w"))==NULL)
        cout<<"Open file error!"<<endl;
    for(int i=1;i<=2*num-1;i++)
    {
        for(int j=0;T[i][j]!='\0';j++)
        {
            if(T[i][j]==' ')//空格
               printf(" "),fputc(T[i][j],fp);
            else//字符
               printf("%u",T[i][j]),fprintf(fp,"%u",T[i][j]);
        }
         cout<<endl;
         fputc(10,fp);
    }
    fclose(fp);
    return ;
}

 int main()
{
char a[100]; //存储要编码的所有字符
    char b[400];  //存储要翻译的二进制编码
    char c[100]; //存储翻译出来的结果
    HuffmanTree HT=NULL;
    char ** HC;
    while(1)
    {
        char s1[]= {"结点"},s2[]= {"字符"},s3[]= {"权值"},s4[]= {"双亲"},s5[]= {"左孩子"},s6[]= {"右孩子"};
        int flag=1,choose,num,cc=0;
        menu();
        char temp;
        cout<<"选择操作:";
        cin>>choose;
        switch(choose)
        {
        case 1:
            cout<<"输入字符个数：";
            cin>>num;
            cout<<"依次输入"<<num<<"个字符:";
            for(int i=1; i<=num; i++)
                cin>>a[i];
            cout<<"依次输入"<<num<<"个字符的权值:";
            CreatHuffmanTree(HT,num);
            //cout<<"结点i"<<"\t字符"<<"\t权值"<<"\t双亲"<<"\t左孩子"<<"\t右孩子"<<endl;
            //for(int i=1; i<=num*2-1; i++)
                //cout<<i<<"\t"<<a[i]<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
            FILE *fp;
            if((fp=fopen("hfmtree.txt","w"))==NULL)
                cout<<"error"<<endl;
            fwrite(&s1,sizeof(s1),1,fp);fwrite(&s2,sizeof(s2),1,fp);fwrite(&s3,sizeof(s3),1,fp);
            fwrite(&s4,sizeof(s4),1,fp);fwrite(&s5,sizeof(s5),1,fp);fwrite(&s6,sizeof(s6),1,fp);
            fputc(10,fp);//10=/n
            for(int i=1; i<=2*num-1; i++)
            {
                fprintf(fp,"%-3d  ",i);
                fwrite(&a[i],1,1,fp);
                /*fprintf(fp,"    %-3d    ",HT[i].weight);
                fprintf(fp,"%-3d    ",HT[i].parent);
                fprintf(fp,"%-3d    ",HT[i].lchild);
                fprintf(fp,"%-3d    ",HT[i].rchild);
                fputc(10,fp);*/
            }
            fclose(fp);
            break;
        case 2:
            CreatHuffmanCode(HT,HC,num);
            cout<<"结点i\t"<<"字符\t"<<"权值\t"<<"编码\t"<<endl;
            for(int i=1; i<=num; i++)
                cout<<i<<"\t"<<a[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
            break;
        case 3:
            Coding(HT,HC,num,a);
            cout<<"二进制编码已存入codefile.txt"<<endl;
            break;
        case 4:
            cout<<"从codefile.txt文件中读取进行译码:"<<endl;
            if((fp=fopen("codefile.txt","rb"))==NULL)
                cout<<"error"<<endl;
            while(1)
            {
                temp = fgetc(fp); //读一个字节。
                if(temp == EOF) break; //到文件尾，退出循环。
                b[cc++] =temp ;//赋值到字符数组中。
            }
            b[cc]='\0';
            printf("%s\n",b);
            fclose(fp);
            TransCode(HT,b,a,c,num);
            cout<<"译码结果:";
            printf("%s\n",c);
            cout<<"翻译结果已存入textfile.txt"<<endl;
            break;
        case 5:
            printf_code();
            break;
        case 6:
            cout<<"打印哈夫曼树："<<endl;
            printf_tree(num,HT);
            break;
        case 7:
            flag=0;
            break;
        default:
            cout<<"输入有误，重新输入"<<endl;
            continue;
        }
        if(flag==0)
            break;
    }
    return 0;

