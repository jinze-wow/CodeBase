#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
struct head
{
    int b,c;					  //字符,数
    long count;                   //文件中该字符出现的次数
    long parent, lch, rch;        //生成树
    char bits[256];               //哈夫曼树编码
};

struct head header[512], tmp;  //节点树



//函数：compress()
//作用：读取文件内容并加以压缩
//将压缩内容写入另一个文档
int compress(const char* filename, const char* outputfile)
{
    char buf[512];
    unsigned char c;
    long i, j, m, n, f;
    long min1, pt1, flength;
    FILE* ifp, * ofp;
    int per = 10;
    ifp = fopen(filename, "rb");                  //打开原始文件,rb 以读/写方式打开一个二进制文件，只允许读/写数据。
    if (ifp == NULL)
    {
        printf("打开文件失败:%s\n", filename);
        return 0;                             //如果打开失败，则输出错误信息
    }
    ofp = fopen(outputfile, "wb");                 //打开压缩后存储信息的文件 wb:只写方式打开或新建一个二进制文件，只允许写数据。
    if (ofp == NULL)
    {
        printf("打开文件失败:%s\n", outputfile);
        return 0;
    }
    flength = 0;
    while (!feof(ifp))  //功能是检测流上的文件结束符
    {
        fread(&c, 1, 1, ifp); 
       //fread( void *buffer,  size,  count, FILE *stream )
       /*buffer 指向要读取的数组中首个对象的指针  size  每个对象的大小（单位是字节）  
       count    要读取的对象个数   stream  输入流*/
        header[c].count++;                       //读文件，统计字符出现次数
        cout << c;                               
        flength++;                               //记录文件的字符总数
    }
    cout << endl;
    flength--;
    header[c].count--;
    for (i = 0; i < 512; i++)                    //HUFFMAN算法中初始节点的设置
    {
        if (header[i].count != 0)
            header[i].b = (unsigned char)i;  //表示byte时，都用unsigned char
           /*将每个哈夫曼码值及其对应的ASCII码存放在一维数组header[i]中，
           且编码表中的下标和ASCII码满足顺序存放关系*/
        else
            header[i].b = -1;   //哈夫曼初始化节点都是-1
        header[i].parent = -1;
        header[i].lch = header[i].rch = -1;
    }

    for (i = 0; i < 256; i++)                    //将节点按出现次数排序
    {
        for (j = i + 1; j < 256; j++)
        {
            if (header[i].count < header[j].count)
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }
   
   

    for (i = 0; i < 256; i++)                    //统计不同字符的数量
    {
        if (header[i].count == 0)
            break;
    }

    n = i; //外部叶子结点数为n个时，内部结点数为n-1，整个哈夫曼树的需要的结点数为2*n - 1.

    m = 2 * n - 1;
    for (i = n; i < m; i++)//构建哈夫曼树
    {
        min1 = 999999999;//结点出现的最大次数
        for (j = 0; j < i; j++) 
        {
            if (header[j].parent != -1) continue;
            // parent != -1说明该结点已存在哈夫曼树中，跳出循环重新选择新结点
            if (min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }
        header[i].count = header[pt1].count;
        header[pt1].parent = i;
        // 依据parent域值（结点层数）确定树中结点之间的关系
        header[i].lch = pt1;//计算左分支权值大小
        min1 = 999999999;
        for (j = 0; j < i; j++)
        {
            if (header[j].parent != -1) continue;
            if (min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }
        header[i].count += header[pt1].count;
        header[i].rch = pt1;//计算右分支权值大小
        header[pt1].parent = i;
    }

    for (i = 0; i < n; i++)     //构造HUFFMAN树，设置字符的无重复前缀编码
    {
        f = i;   //i=1，f=1
        header[i].bits[0] = 0;  //根节点编码为0
        while (header[f].parent != -1)//1的母亲非空
        {
            j = f;//j=1
            f = header[f].parent;//1=1的母亲结点0
            if (header[f].lch == j)//如果左孩子是1，置左分支编码0
            {
                j = strlen(header[i].bits);//j=1
                memmove(header[i].bits + 1, header[i].bits, j + 1);//memmove用于拷贝字节
                header[i].bits[0] = '0';//左0右1，依次存储连接“0” “1”编码
            }
            else//置右分支编码1
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '1';
            }
           
        }
        cout << header[i].b << " : " << header[i].bits << endl;
    }

   


    //读原文件的每一个字符，按照设置好的编码替换文件中的字符
    fseek(ifp, 0, SEEK_SET);                                //将指针定在文件起始位置
    fseek(ofp, 8, SEEK_SET);                                //以8位二进制数为单位进行读取
    buf[0] = 0;//定义缓冲区
    f = 0;
    pt1 = 8;
    /*假设原文件第一个字符是"A"，8位2进制为01000001（65），编码后为0110识别编码第一个’0’，
    将其左移一位，。下一个是'1'，应该|（或） 1，结果00000001
    同理4位都做完，应该是00000110，由于字节中的8位并没有全部用完，们应该继续读下一个字符，
    根据编码表继续拼完剩下的4位，如果字符的编码不足4位，还要继续读个字符，
    如果字符编码超过4位，那么我们将把剩下的位信息拼接到一个新的字节里*/

    printf("当前文件有:%d字符\n", flength);
    printf("正在压缩\n");

    while (!feof(ifp))
    {
        c = fgetc(ifp);
        f++;
        for (i = 0; i < n; i++)
        {
            if (c == header[i].b) break;
        }
        strcat(buf, header[i].bits);
        j = strlen(buf);
        c = 0;
        while (j >= 8)      //当剩余字符数量不小于8个时，压缩存储
        {
            for (i = 0; i < 8; i++)           //按照八位二进制数转化成十进制ASCII码写入文件一次进行压缩
            {
                if (buf[i] == '1') c = (c << 1) | 1;
                else c = c << 1;
            }
            fwrite(&c, 1, 1, ofp);
            pt1++;//统计压缩后文件的长度
            strcpy(buf, buf + 8);//一个字节一个字节的拼接
            j = strlen(buf);
        }
        if (f == flength)
            break;
    }
   

    if (j > 0)             //当剩余字符数量少于8个时
    {
        strcat(buf, "00000000");
        for (i = 0; i < 8; i++)
        {
            if (buf[i] == '1') c = (c << 1) | 1;
            else c = c << 1;           //对不足的位数进行补零
        }
        fwrite(&c, 1, 1, ofp);
        pt1++;
    }
    fseek(ofp, 0, SEEK_SET);          //将编码信息写入存储文件
    fwrite(&flength, 1, sizeof(flength), ofp);
    fwrite(&pt1, sizeof(long), 1, ofp);
    fseek(ofp, pt1, SEEK_SET);
    fwrite(&n, sizeof(long), 1, ofp);
    for (i = 0; i < n; i++)
    {
        tmp = header[i];

        fwrite(&(header[i].b), 1, 1, ofp);
        pt1++;
        c = strlen(header[i].bits);
        fwrite(&c, 1, 1, ofp);
        pt1++;
        j = strlen(header[i].bits);

        if (j % 8 != 0)      //当位数不满8时，对该数进行补零操作
        {
            for (f = j % 8; f < 8; f++)
                strcat(header[i].bits, "0");
        }

        while (header[i].bits[0] != 0)
        {
            c = 0;
            for (j = 0; j < 8; j++)//字符的有效存储不超过8位，则对有效位数位移实现两字符编码的连接

            {
                if (header[i].bits[j] == '1') c = (c << 1) | 1;//| 1不改变原位置的0,1值
                else c = c << 1;
            }
            strcpy(header[i].bits, header[i].bits + 8);//把字符的编码按照原先的存储顺序进行连接
            fwrite(&c, 1, 1, ofp);      //将所得的编码信息写入文件
            pt1++;
        }
        
        header[i] = tmp;
    }
    fclose(ifp);
    fclose(ofp);                              //关闭文件

    cout << "压缩后文件有:" << pt1<<"位二进制字节\n";
    cout <<"压缩后文件有"<<pt1/8+1<<"位字符\n" ;
    float persent = (pt1 / 8 + 1) / 1.0*flength;
    cout << "压缩率是" << persent<<"%"<<endl;

    return 1;                                       //返回压缩成功信息
}


//函数：uncompress()
//作用：解压缩文件，并将解压后的内容写入新文件
int uncompress(const char* filename, const char* outputfile)
{
    char buf[255], bx[255];
    unsigned char c;
    char out_filename[512];
    long i, j, m, n, f, p, l;
    long flength;
    int per = 10;
    int len = 0;
    FILE* ifp, * ofp;
    char c_name[512] = { 0 };
    ifp = fopen(filename, "rb");                                              //打开文件
    if (ifp == NULL)
    {
        return 0;     //若打开失败，则输出错误信息
    }

    //读取原文件长
    if (outputfile)
        strcpy(out_filename, outputfile);
    else
        strcpy(out_filename, c_name);

    ofp = fopen(out_filename, "wb");                                            //打开文件
    if (ofp == NULL)
    {
        return 0;
    }

    fseek(ifp, 0, SEEK_END);
    len = ftell(ifp);
    fseek(ifp, 0, SEEK_SET);

    printf("当前文件有:%d字符\n", len);
    printf("正在解压\n");

    fread(&flength, sizeof(long), 1, ifp); //读取源文件长度，对文件进行定位                                   //读取原文件长
    fread(&f, sizeof(long), 1, ifp);
    fseek(ifp, f, SEEK_SET);
    fread(&n, sizeof(long), 1, ifp);                                          //读取原文件各参数
    for (i = 0; i < n; i++)                                                  //读取压缩文件内容并转换成二进制码
    {
        fread(&header[i].b, 1, 1, ifp);
        fread(&c, 1, 1, ifp);
        p = (long)c;//读取源文件字符的权值
        header[i].count = p;
        header[i].bits[0] = 0;
        if (p % 8 > 0) m = p / 8 + 1;
        else m = p / 8;
        for (j = 0; j < m; j++)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2); //将f转换为二进制表示的字符串
            f = strlen(buf);
            for (l = 8; l > f; l--)
            {
                strcat(header[i].bits, "0");                                  //位数不足，执行补零操作
            }
            strcat(header[i].bits, buf);
        }
        header[i].bits[p] = 0;
    }

    for (i = 0; i < n; i++) //根据哈夫曼编码的长短，对结点进行排序
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(header[i].bits) > strlen(header[j].bits))
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }

    p = strlen(header[n - 1].bits);
    fseek(ifp, 8, SEEK_SET);
    m = 0;
    bx[0] = 0;


    while (1) // 通过哈夫曼编码的长短，依次解码，从原来的位存储还到字节存储

    {
        while (strlen(bx) < (unsigned int)p)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2);
            f = strlen(buf);
            for (l = 8; l > f; l--)//在单字节内对相应位置补O
            {
                strcat(bx, "0");
            }
            strcat(bx, buf);
        }
        for (i = 0; i < n; i++)
        {
            if (memcmp(header[i].bits, bx, header[i].count) == 0) break;
        }
        strcpy(bx, bx + header[i].count);/*从压缩文件中的按位存储还到按字节存储字符，
                                         字符位置不改变*/
        c = header[i].b;
        fwrite(&c, 1, 1, ofp);
        m++;
        cout << header[i].b << " : " << header[i].bits << endl;
        if (m == flength) break;
    }

    fclose(ifp);
    fclose(ofp);

    
    cout << "解压后文件为" << out_filename<<endl;
    cout << "解压后文件有:" << flength << "位字符\n";

    return 1;                   //输出成功信息
}

void text2bin(const char* filename, const char* extractfilename2) {
    int count = 0;
    int ch, a;
    char temp;
    FILE* fin = fopen(filename, "r");
    FILE* fout = fopen(extractfilename2, "w");
    while (fscanf(fin, "%c", &temp) != EOF) {
        ch = temp;
        for (a = 7; a >= 0; a--) fprintf(fout, "%d", ch >> a & 1);
    }
    fclose(fin);
    fclose(fout);

}





int main(int argc, const char* argv[])
{
    int flag;
    char c;
    char filename[100], extractfilename[100], extractfilename2[100];
    while (1)
    {
        printf("\t _______________________________________________\n");
        printf("\t|                                               |\n");
        printf("\t| C-压缩文件                                    |\n");
        printf("\t| E-解压缩                                      |\n");
        printf("\t| Q-退出                                        |\n");
        printf("\t|_______________________________________________|\n");
        printf("\n");
        do
        {
            printf("\n\t请选择功能:");
            scanf(" %c", &c);
            c = toupper(c); //小写变大写
            putchar('\n');
            if ('C' != c && 'E' != c && 'Q' != c)
            {
                printf("\t选项错误,请重新输入!\n");
            }
        } while ('C' != c && 'E' != c && 'Q' != c);

        if ('C' == c)
        {
            printf("\t请您输入需要压缩的文件:");
            fflush(stdin);  //fflush(stdin)刷新标准输入缓冲区，把输入缓冲区里的东西丢弃
            cin>>filename;
            putchar('\n');

            printf("\t请您输入压缩后的文件:");
            fflush(stdin);
            cin >> extractfilename;
            putchar('\n');

            printf("\t请您输入要保存的压缩后的二进制文件名:");
            fflush(stdin);
            cin >> extractfilename2;
            putchar('\n');

           
            flag = compress(filename, extractfilename);

            putchar('\n');

            if (-1 == flag)
            {
                printf("\t文件打开失败!\n");
                exit(1);
            }
            else
            {
                printf("\n\t压缩操作完成!\n\n");
                text2bin(filename, extractfilename2);
            }

        }
        else if ('E' == c)
        {
            printf("\t请您输入需要解压的文件:");
            fflush(stdin);
            cin >> extractfilename;
            putchar('\n');

            printf("\t请您输入解压缩后的文件:");
            fflush(stdin);
            cin >> filename;
            putchar('\n');



            flag = uncompress(extractfilename, filename);
            putchar('\n');

            if (-1 == flag)
            {
                printf("\t文件打开失败!\n");
                exit(1);
            }
            else
            {
                printf("\n\t解压缩操作完成!\n\n");
            }
        }
        if ('Q' == c) {
                printf("\t感谢使用!\n");
                exit(0);
            }
        
    }
    return 0;
}