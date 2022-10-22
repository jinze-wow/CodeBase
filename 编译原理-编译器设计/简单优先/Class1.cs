using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 简单优先
{

    class Program
    {
        /*-------------------------------变量声明---------------------------------------------------------------------------------------*/
        static string effectValue = "i+*()#";   //有效的字符集合
        static List<string> grammarList = new List<string>();   //文法列表
        static Dictionary<string, List<string>> grammarDic = new Dictionary<string, List<string>>();    //文法字典
        static Dictionary<string, List<string>>.KeyCollection vertex;   //非终结符集合
        static Dictionary<string, string> firstVT = new Dictionary<string, string>();   //firstVT集
        static Dictionary<string, string> lastVT = new Dictionary<string, string>();    //lastVT集
        static char[,] priorityTable = new char[7, 7];   //算符优先关系表
        static string message;      //要分析的字符串
        static MyStack stack = new MyStack();


        /*----------------------------主函数--------------------------------------------------------------------------------------------*/
        static void Main(string[] args)
        {
            inputGrammar();    //获得文法字符串
            getVT();           //获得firstVT和lastVT
            printVT();         //输出firstVT和lastVT
            getPriorityTable();//得到优先关系表
            printPriorityTable();//打印优先关系表
            inputMessage();     //获得要分析的字符串

            //判断字符串是否符合要求
            if (judgeMessage())
                //进行算符优先分析
                if (analyze())
                    Console.WriteLine("分析成功！该句子符合算符优先。");
                else Console.WriteLine("分析失败！该句子不符合算符优先。");
        }

        /*---------------------------------------输入数据---------------------------------------------------------------------*/
        static void inputGrammar()
        {
            Console.WriteLine("该系统支持的终结符有：i,+,*,(,)，请勿输入其他终结符！");
            Console.WriteLine("请输入要分析的文法：（在单独一行输入#结束输入）");
            Console.WriteLine("如：E→E+T|T\nT→T*F|F\nF→(E)|i\n#\n");
            while (true)
            {
                string str = Console.ReadLine();
                if (str.Equals("#"))
                    break;
                else grammarList.Add(str);
            }
            //将文法转存为文法字典保存
            foreach (string str in grammarList)
            {
                List<string> l1 = new List<string>();
                string[] s1 = str.Split('→');
                string[] s2 = s1[1].Split('|');
                foreach (string s in s2)
                    l1.Add(s);
                grammarDic.Add(s1[0], l1);
            }
            vertex = grammarDic.Keys;   //将文法字典的key值给vector
        }

        /*---------------------------------------得到firstVT和lastVT----------------------------------------------------------*/
        static void getVT()
        {
            //第一遍遍历，将第一个非终结符和在串头的终结符加入firstVT
            foreach (string v in vertex)
            {
                List<string> l = grammarDic[v];
                foreach (string s in l)
                {
                    getFirstVT(s, v);
                    getLastVT(s, v);
                }
            }
            trimFirstVT();
            trimLastVT();

        }

        //得到firstVT
        static void getFirstVT(string s, string v)
        {
            //从前往后，找合适字符加入firstVT
            for (int i = 0; i < s.Length; i++)
            {
                string t = Convert.ToString(s[i]);
                //如果是非终结符，且在字符串最前，将其加入firstVT
                if (grammarDic.ContainsKey(t) && i == 0)
                    if (firstVT.ContainsKey(v))
                        if (!firstVT[v].Contains(t))
                            firstVT[v] += t;
                        else firstVT.Add(v, t);
                //将第一个终结符加入firstVT
                if (!grammarDic.ContainsKey(t))
                {
                    if (firstVT.ContainsKey(v))
                        firstVT[v] += t;
                    else firstVT.Add(v, t);
                    break;
                }
            }
        }

        //得到lastVT
        static void getLastVT(string s, string v)
        {
            //从后往前，找合适字符加入lastVT
            for (int i = s.Length - 1; i >= 0; i--)
            {
                string t = Convert.ToString(s[i]);
                //如果是非终结符，且在字符串最后，将其加入lastVT
                if (grammarDic.ContainsKey(t) && i == s.Length - 1)
                    if (lastVT.ContainsKey(v))
                        if (!lastVT[v].Contains(t))
                            lastVT[v] += t;
                        else lastVT.Add(v, t);
                //将最后一个终结符加入firstVT
                if (!grammarDic.ContainsKey(t))
                {
                    if (lastVT.ContainsKey(v))
                        lastVT[v] += t;
                    else lastVT.Add(v, t);
                    break;
                }
            }
        }

        //将firstVT中的终结符去掉
        static void trimFirstVT()
        {
            //逆序遍历终结符集（必须逆序）
            foreach (string v in vertex.Reverse())
            {
                string s1 = firstVT[v];
                for (int i = 0; i < s1.Length; i++)
                {
                    string t = Convert.ToString(s1[i]);
                    //若firstVT集中含有终结符，进行整理
                    if (grammarDic.ContainsKey(t))
                    {
                        firstVT[v] = firstVT[v].Replace(t, ""); //删除此终结符
                        string s2 = firstVT[t];
                        //将此终结符的firstVT集添加进来
                        for (int j = 0; j < s2.Length; j++)
                        {
                            if (!s1.Contains(s2[j]) && !grammarDic.ContainsKey(Convert.ToString(s2[j])))
                                firstVT[v] += s2[j];
                        }
                    }
                }
            }
        }

        //将firstVT中的终结符去掉，过程同trimFirstVT()
        static void trimLastVT()
        {
            foreach (string v in vertex.Reverse())
            {
                string s1 = lastVT[v];
                for (int i = 0; i < s1.Length; i++)
                {
                    string t = Convert.ToString(s1[i]);
                    if (grammarDic.ContainsKey(t))
                    {
                        lastVT[v] = lastVT[v].Replace(t, "");
                        string s2 = lastVT[t];
                        for (int j = 0; j < s2.Length; j++)
                        {
                            if (!s1.Contains(s2[j]) && !grammarDic.ContainsKey(Convert.ToString(s2[j])))
                                lastVT[v] += s2[j];
                        }
                    }
                }
            }
        }

        /*------------------------------------------------------打印firstVT和lastVT------------------------------------------------------*/
        static void printVT()
        {
            //输出firstVT
            Console.WriteLine("\nfirstVT：");
            foreach (string s in firstVT.Keys)
            {
                Console.Write("firstVT " + s + " : ");
                for (int i = 0; i < firstVT[s].Length; i++)
                    Console.Write(firstVT[s][i] + "  ");
                Console.WriteLine("");
            }
            //输出lastVT
            Console.WriteLine("lastVT：");
            foreach (string s in lastVT.Keys)
            {
                Console.Write("lastVT " + s + " : ");
                for (int i = 0; i < lastVT[s].Length; i++)
                    Console.Write(lastVT[s][i] + "  ");
                Console.WriteLine();
            }
        }

        /*--------------------------------------------------------算符优先关系表----------------------------------------------------*/
        //得到算符优先关系表
        static void getPriorityTable()
        {
            //添加文法：E→#E#
            string str = vertex.FirstOrDefault();
            grammarDic[str].Add("#" + str + "#");
            int i1, j1;
            //对优先关系表进行初始化
            for (int i = 1; i <= effectValue.Length; i++)
            {
                priorityTable[0, i] = effectValue[i - 1];
                priorityTable[i, 0] = effectValue[i - 1];
            }
            //对产生式右部进行遍历
            foreach (string v in vertex)
            {
                List<string> g = grammarDic[v];
                foreach (string s in g)
                {
                    for (int i = 0; i < s.Length; i++)
                    {
                        string t = Convert.ToString(s[i]);
                        //若只有一个非终结符，则#=#
                        if (s.Length == 1)
                        {
                            if (grammarDic.ContainsKey(t))
                                priorityTable[6, 6] = '=';
                        }
                        else
                        {
                            if (i > 0)
                            {
                                string tp = Convert.ToString(s[i - 1]);
                                //出现ab型的产生式，则a=b
                                if ((!grammarDic.ContainsKey(tp)) && (!grammarDic.ContainsKey(t)))
                                {
                                    i1 = effectValue.IndexOf(tp);
                                    j1 = effectValue.IndexOf(t);
                                    priorityTable[i1, j1] = '=';
                                }
                                //出现aA型的产生式，则a<firstVT[A]
                                if ((!grammarDic.ContainsKey(tp)) && grammarDic.ContainsKey(t))
                                {
                                    i1 = effectValue.IndexOf(tp) + 1;
                                    string fir = firstVT[t];
                                    for (int j = 0; j < fir.Length; j++)
                                    {
                                        j1 = effectValue.IndexOf(fir[j]) + 1;
                                        priorityTable[i1, j1] = '<';
                                    }
                                }
                                //出现Aa型的产生式，则lastVT[A]>a
                                if (grammarDic.ContainsKey(tp) && (!grammarDic.ContainsKey(t)))
                                {
                                    j1 = effectValue.IndexOf(t) + 1;
                                    string lat = lastVT[tp];
                                    for (int j = 0; j < lat.Length; j++)
                                    {
                                        i1 = effectValue.IndexOf(lat[j]) + 1;
                                        priorityTable[i1, j1] = '>';
                                    }
                                }
                                if (i < s.Length - 1)
                                {
                                    string tn = Convert.ToString(s[i + 1]);
                                    //出现aAb型的产生式，则a=b
                                    if ((!grammarDic.ContainsKey(tp)) && grammarDic.ContainsKey(t) && (!grammarDic.ContainsKey(tn)))
                                    {
                                        i1 = effectValue.IndexOf(tp) + 1;
                                        j1 = effectValue.IndexOf(tn) + 1;
                                        priorityTable[i1, j1] = '=';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //输出算符优先关系表
        static void printPriorityTable()
        {
            Console.WriteLine("\n算符优先关系表如下：");
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                    Console.Write(priorityTable[i, j] + "\t");
                Console.WriteLine("\n");
            }
        }

        /*-------------------------------------------算符优先分析-----------------------------------------------------------------*/
        //得到要分析的字符串
        static void inputMessage()
        {
            Console.WriteLine("\n该分析器只能识别i,+,*,(,),#，请勿输入其他字符！");
            Console.WriteLine("请输入要分析的字符串，用#结尾（如i+i*i#）");
            message = Console.ReadLine();
        }

        //检测输入的字符串是否符合要求
        static Boolean judgeMessage()
        {
            //检测输入的字符串是否合法
            bool isLegal = true;
            bool flag = true;
            if (message[message.Length - 1] != '#')
            {
                Console.WriteLine("字符串必须以#结尾！");
                flag = false;
            }
            for (int i = 0; i < message.Length; i++)
                if (!effectValue.Contains(message[i]))
                    isLegal = false;
            if (!isLegal)
            {
                Console.WriteLine("该字符串中含有非法字符！");
                flag = false;
            }

            return flag;
        }

        //进行算符优先分析
        static Boolean analyze()
        {
            bool flag = true;
            stack.push("#");    //对栈进行初始化

            //对待处理串中的每个字符进行遍历
            for (int i = 0; i < message.Length;)
            {
                string s = stack.getString();   //获得栈中数据
                int j = s.Length - 1;

                //寻找栈中第一个终结符
                while (grammarDic.ContainsKey(s[j].ToString()) || s[j] == 'E')
                {
                    j--;
                }

                //获取栈中第一个终结符，与字符串头元素在优先表中的位置
                int i1 = effectValue.IndexOf(s[j]) + 1;
                int j1 = effectValue.IndexOf(message[i]) + 1;

                //优先表值进行相应的操作
                switch (priorityTable[i1, j1])
                {
                    case '<': moveIn(i); i++; break;
                    case '=': moveIn(i); i++; break;
                    case '>': flag = reduction(i, j); break;
                    default: break;
                }

                //分析完成输出结果
                if (stack.getString().Equals("#E") && i >= message.Length - 1)
                {
                    Console.WriteLine(stack.getString() + "\t\t" + message.Substring(i) + "\t\t" + "分析完成");
                    break;
                }
                //分析失败退出循环
                if (!flag)
                    break;
            }
            return flag;
        }

        //移进操作
        static void moveIn(int i)
        {
            Console.WriteLine(stack.getString() + "\t\t" + message.Substring(i) + "\t\t移进");
            stack.push(message[i].ToString());
        }

        //归约操作
        static Boolean reduction(int n, int i)
        {
            string s = stack.getString();
            bool flag = true;
            int k = i - 1;

            //遍历每一个文法
            foreach (string v in vertex)
            {
                string c = s[i].ToString();
                List<string> list = grammarDic[v];
                foreach (string g in list)
                {
                    if (g.Contains(c))
                    {
                        Console.WriteLine(s + "\t\t" + message.Substring(n) + "\t\t规约");
                        if (c == "i")
                        {
                            //防止多个i连一起的情况发生
                            if (s[i - 1] == 'i')
                                flag = false;
                            else
                            {
                                stack.pop();
                                stack.push("E");
                            }
                        }
                        else if (s.Length > g.Length)
                        {
                            for (int j = 0; j < g.Length; j++)
                                stack.pop();
                            stack.push("E");
                        }
                        //开头不能为运算符
                        else if (s[i - 1] != 'i')
                            flag = false;
                    }
                }
            }
            return flag;
        }

        /*----------------------------------------------------堆栈操作--------------------------------------------------------------*/
        //系统自带的堆栈不是很好用，于是我自己写了一个
        class MyStack
        {
            string data;
            int top;
            public MyStack()
            {
                data = "";
                top = -1;
            }
            public void push(string s)
            {
                data += s;
                top++;
            }
            public string pop()
            {
                data = data.Substring(0, data.Length - 1);
                top--;
                return data;
            }
            public string getString()
            {
                return data;
            }
        }
    }
}