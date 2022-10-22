

typedef struct
{
    int weight;
    int lchild,rchild,parent;
} HTNode,*HuffmanTree;


void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
    int i=1;
    while(HT[i].parent!=0&&i<=n)//�ҵ�һ����û���ӵģ���parent=0��
        i++;
    if(i==n+1)
        return ;
    s1=i;
    i++;
    while(HT[i].parent!=0&&i<=n)//ͬ��
        i++;
    if(i==n+1)
        return ;
    s2=i;
    i++;
    if(HT[s1].weight>HT[s2].weight)//��s1��s2С
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
    int m=2*n-1;//������2n-1���ڵ�
    HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));//��1��ʼ������һ��
    for(int i=1; i<=m; i++)//��ʼ��
    {
        HT[i].lchild=0;
        HT[i].parent=0;
        HT[i].rchild=0;
        HT[i].weight=0;
    }
    for(int i=1; i<=n; i++)
        cin>>HT[i].weight;
    int s1,s2;
    for(int i=n+1; i<=m; i++)//��n-1���ڵ�Ĵ���
    {
        Select(HT,i-1,s1,s2);//�½ڵ��ȨֵΪ������С��Ȩֵ��
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
    col=(char *)malloc(sizeof(char)*n);//�洢ÿ���������ʱ�ռ�
    col[n-1]='\0';
    //Ϊʲô��n-1,n���ڵ㴴���Ĺ���������Ϊn-1
    //·������Ϊn-2�����ֻ��n-2�����֡�
    for(int i=1; i<=n; i++)
    {
        int str=n-1;
        int p=i,f=i;
        while(HT[f].parent!=0)//��Ҷ����Ѱ��
        {
            f=HT[f].parent;
            if(HT[f].lchild==p)
                col[--str]='0';
            else if(HT[f].rchild==p)
                col[--str]='1';
            p=f;
        }
        HC[i]=(char *)malloc(sizeof(char)*(n-str));    //Ϊ��i���ַ��������ռ�
        strcpy(HC[i],&col[str]);//���Ƶ�������
    }
    free(col);
    return ;
}

void TransCode(HuffmanTree HT,char b[],char a[],char c[],int n)
{
    //b������Ҫ����Ķ����Ʊ���
    //a������Ҷ�Ӷ�Ӧ���ַ�
    //c����洢����õ�������
    FILE *fw;
    int q=2*n-1;   //��ʼ��Ϊ�������±�
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
        if(HT[q].lchild==0&&HT[q].rchild==0)//Ҷ�ӽڵ㣬��ʱ����
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
    fscanf(fp,"%c",&c);//���ļ��ж�ȡһ���ַ�
    while(!feof(fp))
    {
        for(int i=1; i<=n; i++)
            if(a[i]==c)//�ҵ���Ӧ�ı���
            {
                k=i;
                break;
            }
        for(int i=0; HC[k][i]!='\0'; i++)//������ַ�����
            fputc(HC[k][i],fw);
        fscanf(fp,"%c",&c);//������һ��
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
    cout<<"codefile.txt��"<<endl;
    fscanf(fp,"%c",&temp);
    for(int i=1;!feof(fp);i++)
    {
        printf("%c",temp);
        if(i%50==0)//50��һ����
            cout<<endl;
        fputc(temp,fw);//��д��codeprint�ļ���
        fscanf(fp,"%c",&temp);
    }
    cout<<endl;
    cout<<"�����Ѵ����ļ�codeprin.txt"<<endl;
    fclose(fp);
    fclose(fw);
}

void co_tree(unsigned char T[100][100],int s,int *m,int j,HuffmanTree HT)
{
    int k,l;
    l=++(*m);
    for(k=0;k<s;k++)//���Խ�ǰ��ո�Խ��
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
            if(T[i][j]==' ')//�ո�
               printf(" "),fputc(T[i][j],fp);
            else//�ַ�
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
char a[100]; //�洢Ҫ����������ַ�
    char b[400];  //�洢Ҫ����Ķ����Ʊ���
    char c[100]; //�洢��������Ľ��
    HuffmanTree HT=NULL;
    char ** HC;
    while(1)
    {
        char s1[]= {"���"},s2[]= {"�ַ�"},s3[]= {"Ȩֵ"},s4[]= {"˫��"},s5[]= {"����"},s6[]= {"�Һ���"};
        int flag=1,choose,num,cc=0;
        menu();
        char temp;
        cout<<"ѡ�����:";
        cin>>choose;
        switch(choose)
        {
        case 1:
            cout<<"�����ַ�������";
            cin>>num;
            cout<<"��������"<<num<<"���ַ�:";
            for(int i=1; i<=num; i++)
                cin>>a[i];
            cout<<"��������"<<num<<"���ַ���Ȩֵ:";
            CreatHuffmanTree(HT,num);
            //cout<<"���i"<<"\t�ַ�"<<"\tȨֵ"<<"\t˫��"<<"\t����"<<"\t�Һ���"<<endl;
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
            cout<<"���i\t"<<"�ַ�\t"<<"Ȩֵ\t"<<"����\t"<<endl;
            for(int i=1; i<=num; i++)
                cout<<i<<"\t"<<a[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
            break;
        case 3:
            Coding(HT,HC,num,a);
            cout<<"�����Ʊ����Ѵ���codefile.txt"<<endl;
            break;
        case 4:
            cout<<"��codefile.txt�ļ��ж�ȡ��������:"<<endl;
            if((fp=fopen("codefile.txt","rb"))==NULL)
                cout<<"error"<<endl;
            while(1)
            {
                temp = fgetc(fp); //��һ���ֽڡ�
                if(temp == EOF) break; //���ļ�β���˳�ѭ����
                b[cc++] =temp ;//��ֵ���ַ������С�
            }
            b[cc]='\0';
            printf("%s\n",b);
            fclose(fp);
            TransCode(HT,b,a,c,num);
            cout<<"������:";
            printf("%s\n",c);
            cout<<"�������Ѵ���textfile.txt"<<endl;
            break;
        case 5:
            printf_code();
            break;
        case 6:
            cout<<"��ӡ����������"<<endl;
            printf_tree(num,HT);
            break;
        case 7:
            flag=0;
            break;
        default:
            cout<<"����������������"<<endl;
            continue;
        }
        if(flag==0)
            break;
    }
    return 0;

