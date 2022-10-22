#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
struct head
{
    int b,c;					  //�ַ�,��
    long count;                   //�ļ��и��ַ����ֵĴ���
    long parent, lch, rch;        //������
    char bits[256];               //������������
};

struct head header[512], tmp;  //�ڵ���



//������compress()
//���ã���ȡ�ļ����ݲ�����ѹ��
//��ѹ������д����һ���ĵ�
int compress(const char* filename, const char* outputfile)
{
    char buf[512];
    unsigned char c;
    long i, j, m, n, f;
    long min1, pt1, flength;
    FILE* ifp, * ofp;
    int per = 10;
    ifp = fopen(filename, "rb");                  //��ԭʼ�ļ�,rb �Զ�/д��ʽ��һ���������ļ���ֻ�����/д���ݡ�
    if (ifp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", filename);
        return 0;                             //�����ʧ�ܣ������������Ϣ
    }
    ofp = fopen(outputfile, "wb");                 //��ѹ����洢��Ϣ���ļ� wb:ֻд��ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
    if (ofp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", outputfile);
        return 0;
    }
    flength = 0;
    while (!feof(ifp))  //�����Ǽ�����ϵ��ļ�������
    {
        fread(&c, 1, 1, ifp); 
       //fread( void *buffer,  size,  count, FILE *stream )
       /*buffer ָ��Ҫ��ȡ���������׸������ָ��  size  ÿ������Ĵ�С����λ���ֽڣ�  
       count    Ҫ��ȡ�Ķ������   stream  ������*/
        header[c].count++;                       //���ļ���ͳ���ַ����ִ���
        cout << c;                               
        flength++;                               //��¼�ļ����ַ�����
    }
    cout << endl;
    flength--;
    header[c].count--;
    for (i = 0; i < 512; i++)                    //HUFFMAN�㷨�г�ʼ�ڵ������
    {
        if (header[i].count != 0)
            header[i].b = (unsigned char)i;  //��ʾbyteʱ������unsigned char
           /*��ÿ����������ֵ�����Ӧ��ASCII������һά����header[i]�У�
           �ұ�����е��±��ASCII������˳���Ź�ϵ*/
        else
            header[i].b = -1;   //��������ʼ���ڵ㶼��-1
        header[i].parent = -1;
        header[i].lch = header[i].rch = -1;
    }

    for (i = 0; i < 256; i++)                    //���ڵ㰴���ִ�������
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
   
   

    for (i = 0; i < 256; i++)                    //ͳ�Ʋ�ͬ�ַ�������
    {
        if (header[i].count == 0)
            break;
    }

    n = i; //�ⲿҶ�ӽ����Ϊn��ʱ���ڲ������Ϊn-1������������������Ҫ�Ľ����Ϊ2*n - 1.

    m = 2 * n - 1;
    for (i = n; i < m; i++)//������������
    {
        min1 = 999999999;//�����ֵ�������
        for (j = 0; j < i; j++) 
        {
            if (header[j].parent != -1) continue;
            // parent != -1˵���ý���Ѵ��ڹ��������У�����ѭ������ѡ���½��
            if (min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }
        header[i].count = header[pt1].count;
        header[pt1].parent = i;
        // ����parent��ֵ����������ȷ�����н��֮��Ĺ�ϵ
        header[i].lch = pt1;//�������֧Ȩֵ��С
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
        header[i].rch = pt1;//�����ҷ�֧Ȩֵ��С
        header[pt1].parent = i;
    }

    for (i = 0; i < n; i++)     //����HUFFMAN���������ַ������ظ�ǰ׺����
    {
        f = i;   //i=1��f=1
        header[i].bits[0] = 0;  //���ڵ����Ϊ0
        while (header[f].parent != -1)//1��ĸ�׷ǿ�
        {
            j = f;//j=1
            f = header[f].parent;//1=1��ĸ�׽��0
            if (header[f].lch == j)//���������1�������֧����0
            {
                j = strlen(header[i].bits);//j=1
                memmove(header[i].bits + 1, header[i].bits, j + 1);//memmove���ڿ����ֽ�
                header[i].bits[0] = '0';//��0��1�����δ洢���ӡ�0�� ��1������
            }
            else//���ҷ�֧����1
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '1';
            }
           
        }
        cout << header[i].b << " : " << header[i].bits << endl;
    }

   


    //��ԭ�ļ���ÿһ���ַ����������úõı����滻�ļ��е��ַ�
    fseek(ifp, 0, SEEK_SET);                                //��ָ�붨���ļ���ʼλ��
    fseek(ofp, 8, SEEK_SET);                                //��8λ��������Ϊ��λ���ж�ȡ
    buf[0] = 0;//���建����
    f = 0;
    pt1 = 8;
    /*����ԭ�ļ���һ���ַ���"A"��8λ2����Ϊ01000001��65���������Ϊ0110ʶ������һ����0����
    ��������һλ������һ����'1'��Ӧ��|���� 1�����00000001
    ͬ��4λ�����꣬Ӧ����00000110�������ֽ��е�8λ��û��ȫ�����꣬��Ӧ�ü�������һ���ַ���
    ���ݱ�������ƴ��ʣ�µ�4λ������ַ��ı��벻��4λ����Ҫ���������ַ���
    ����ַ����볬��4λ����ô���ǽ���ʣ�µ�λ��Ϣƴ�ӵ�һ���µ��ֽ���*/

    printf("��ǰ�ļ���:%d�ַ�\n", flength);
    printf("����ѹ��\n");

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
        while (j >= 8)      //��ʣ���ַ�������С��8��ʱ��ѹ���洢
        {
            for (i = 0; i < 8; i++)           //���հ�λ��������ת����ʮ����ASCII��д���ļ�һ�ν���ѹ��
            {
                if (buf[i] == '1') c = (c << 1) | 1;
                else c = c << 1;
            }
            fwrite(&c, 1, 1, ofp);
            pt1++;//ͳ��ѹ�����ļ��ĳ���
            strcpy(buf, buf + 8);//һ���ֽ�һ���ֽڵ�ƴ��
            j = strlen(buf);
        }
        if (f == flength)
            break;
    }
   

    if (j > 0)             //��ʣ���ַ���������8��ʱ
    {
        strcat(buf, "00000000");
        for (i = 0; i < 8; i++)
        {
            if (buf[i] == '1') c = (c << 1) | 1;
            else c = c << 1;           //�Բ����λ�����в���
        }
        fwrite(&c, 1, 1, ofp);
        pt1++;
    }
    fseek(ofp, 0, SEEK_SET);          //��������Ϣд��洢�ļ�
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

        if (j % 8 != 0)      //��λ������8ʱ���Ը������в������
        {
            for (f = j % 8; f < 8; f++)
                strcat(header[i].bits, "0");
        }

        while (header[i].bits[0] != 0)
        {
            c = 0;
            for (j = 0; j < 8; j++)//�ַ�����Ч�洢������8λ�������Чλ��λ��ʵ�����ַ����������

            {
                if (header[i].bits[j] == '1') c = (c << 1) | 1;//| 1���ı�ԭλ�õ�0,1ֵ
                else c = c << 1;
            }
            strcpy(header[i].bits, header[i].bits + 8);//���ַ��ı��밴��ԭ�ȵĴ洢˳���������
            fwrite(&c, 1, 1, ofp);      //�����õı�����Ϣд���ļ�
            pt1++;
        }
        
        header[i] = tmp;
    }
    fclose(ifp);
    fclose(ofp);                              //�ر��ļ�

    cout << "ѹ�����ļ���:" << pt1<<"λ�������ֽ�\n";
    cout <<"ѹ�����ļ���"<<pt1/8+1<<"λ�ַ�\n" ;
    float persent = (pt1 / 8 + 1) / 1.0*flength;
    cout << "ѹ������" << persent<<"%"<<endl;

    return 1;                                       //����ѹ���ɹ���Ϣ
}


//������uncompress()
//���ã���ѹ���ļ���������ѹ�������д�����ļ�
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
    ifp = fopen(filename, "rb");                                              //���ļ�
    if (ifp == NULL)
    {
        return 0;     //����ʧ�ܣ������������Ϣ
    }

    //��ȡԭ�ļ���
    if (outputfile)
        strcpy(out_filename, outputfile);
    else
        strcpy(out_filename, c_name);

    ofp = fopen(out_filename, "wb");                                            //���ļ�
    if (ofp == NULL)
    {
        return 0;
    }

    fseek(ifp, 0, SEEK_END);
    len = ftell(ifp);
    fseek(ifp, 0, SEEK_SET);

    printf("��ǰ�ļ���:%d�ַ�\n", len);
    printf("���ڽ�ѹ\n");

    fread(&flength, sizeof(long), 1, ifp); //��ȡԴ�ļ����ȣ����ļ����ж�λ                                   //��ȡԭ�ļ���
    fread(&f, sizeof(long), 1, ifp);
    fseek(ifp, f, SEEK_SET);
    fread(&n, sizeof(long), 1, ifp);                                          //��ȡԭ�ļ�������
    for (i = 0; i < n; i++)                                                  //��ȡѹ���ļ����ݲ�ת���ɶ�������
    {
        fread(&header[i].b, 1, 1, ifp);
        fread(&c, 1, 1, ifp);
        p = (long)c;//��ȡԴ�ļ��ַ���Ȩֵ
        header[i].count = p;
        header[i].bits[0] = 0;
        if (p % 8 > 0) m = p / 8 + 1;
        else m = p / 8;
        for (j = 0; j < m; j++)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2); //��fת��Ϊ�����Ʊ�ʾ���ַ���
            f = strlen(buf);
            for (l = 8; l > f; l--)
            {
                strcat(header[i].bits, "0");                                  //λ�����㣬ִ�в������
            }
            strcat(header[i].bits, buf);
        }
        header[i].bits[p] = 0;
    }

    for (i = 0; i < n; i++) //���ݹ���������ĳ��̣��Խ���������
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


    while (1) // ͨ������������ĳ��̣����ν��룬��ԭ����λ�洢�����ֽڴ洢

    {
        while (strlen(bx) < (unsigned int)p)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2);
            f = strlen(buf);
            for (l = 8; l > f; l--)//�ڵ��ֽ��ڶ���Ӧλ�ò�O
            {
                strcat(bx, "0");
            }
            strcat(bx, buf);
        }
        for (i = 0; i < n; i++)
        {
            if (memcmp(header[i].bits, bx, header[i].count) == 0) break;
        }
        strcpy(bx, bx + header[i].count);/*��ѹ���ļ��еİ�λ�洢�������ֽڴ洢�ַ���
                                         �ַ�λ�ò��ı�*/
        c = header[i].b;
        fwrite(&c, 1, 1, ofp);
        m++;
        cout << header[i].b << " : " << header[i].bits << endl;
        if (m == flength) break;
    }

    fclose(ifp);
    fclose(ofp);

    
    cout << "��ѹ���ļ�Ϊ" << out_filename<<endl;
    cout << "��ѹ���ļ���:" << flength << "λ�ַ�\n";

    return 1;                   //����ɹ���Ϣ
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
        printf("\t| C-ѹ���ļ�                                    |\n");
        printf("\t| E-��ѹ��                                      |\n");
        printf("\t| Q-�˳�                                        |\n");
        printf("\t|_______________________________________________|\n");
        printf("\n");
        do
        {
            printf("\n\t��ѡ����:");
            scanf(" %c", &c);
            c = toupper(c); //Сд���д
            putchar('\n');
            if ('C' != c && 'E' != c && 'Q' != c)
            {
                printf("\tѡ�����,����������!\n");
            }
        } while ('C' != c && 'E' != c && 'Q' != c);

        if ('C' == c)
        {
            printf("\t����������Ҫѹ�����ļ�:");
            fflush(stdin);  //fflush(stdin)ˢ�±�׼���뻺�����������뻺������Ķ�������
            cin>>filename;
            putchar('\n');

            printf("\t��������ѹ������ļ�:");
            fflush(stdin);
            cin >> extractfilename;
            putchar('\n');

            printf("\t��������Ҫ�����ѹ����Ķ������ļ���:");
            fflush(stdin);
            cin >> extractfilename2;
            putchar('\n');

           
            flag = compress(filename, extractfilename);

            putchar('\n');

            if (-1 == flag)
            {
                printf("\t�ļ���ʧ��!\n");
                exit(1);
            }
            else
            {
                printf("\n\tѹ���������!\n\n");
                text2bin(filename, extractfilename2);
            }

        }
        else if ('E' == c)
        {
            printf("\t����������Ҫ��ѹ���ļ�:");
            fflush(stdin);
            cin >> extractfilename;
            putchar('\n');

            printf("\t���������ѹ������ļ�:");
            fflush(stdin);
            cin >> filename;
            putchar('\n');



            flag = uncompress(extractfilename, filename);
            putchar('\n');

            if (-1 == flag)
            {
                printf("\t�ļ���ʧ��!\n");
                exit(1);
            }
            else
            {
                printf("\n\t��ѹ���������!\n\n");
            }
        }
        if ('Q' == c) {
                printf("\t��лʹ��!\n");
                exit(0);
            }
        
    }
    return 0;
}