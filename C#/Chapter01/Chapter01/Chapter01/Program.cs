using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;

namespace Chapter01
{
    class Program
    {
        static void Main(string[] args)
        {

            MyWaterJug mw = new MyWaterJug();
            mw.PrintResult(mw.WaterJug(7, 10, 8));
        }
    }
    class LargestWeightSubsequence
    {
        //cach 1
        public long Algo1(int[] a)
        {
            int count = 0;
            int len = a.Length;
            long max = a[0];
            for (int i = 0; i < len; i++)
            {
                for (int j = i; j < len; j++)
                {
                    long s = 0;
                    for (int k = i; k <= j; k++)
                        s += a[k];
                    max = (max < s) ? s : max;
                }
            }
            return max;
        }
        //cach 2
        public long Algo2(int[] a)
        {
            int len = a.Length;
            long max = a[0];
            for (int i = 0; i < len; i++)
            {
                long s = 0;
                for (int j = i; j < len; j++)
                {
                    s += a[j];
                    max = (max < s) ? s : max;
                }
            }
            return max;
        }
        //cach 3
        //Divide and Conquer

        public long Algo3(int[] a)
        {
            int len = a.Length;
            long max = MaxSeq(0, len - 1, a);
            return max;
        }

        private long MaxSeq(int i, int j, int[] a)
        {
            if (i == j) return a[i];
            int m = (i + j) / 2;
            long ml = MaxSeq(i, m, a);//o nua dau
            long mr = MaxSeq(m + 1, j, a);//o nua sau
            long maxL = MaxLeft(i, m, a);
            long maxR = MaxRight(m + 1, j, a);
            long maxLR = maxL + maxR;//o giua
            long max = ml > mr ? ml : mr;
            max = max > maxLR ? max : maxLR;
            return max;
        }

        private long MaxLeft(int i, int j, int[] a)//find the largest weight subsequence in the left seq
        {
            long max = a[j];
            long s = 0;
            for (int k = j; k >= i; k--)
            {
                s += a[k];
                max = max < s ? s : max;
            }
            return max;
        }
        private long MaxRight(int i, int j, int[] a)//find the largest weight subsequence in the right seq
        {
            long max = a[i], s = 0;
            for (int k = i; k <= j; k++)
            {
                s += a[k];
                max = max < s ? s : max;
            }
            return max;
        }
        //cách 4
        //Dynamic programing
        public long Algo4(int[] a)
        {
            int len = a.Length;
            long max = a[0];
            long s = a[0];
            for (int i = 1; i < len; i++)
            {
                s = (s + a[i] > a[i]) ? (s + a[i]) : a[i];
                max = max < s ? s : max;
            }
            return max;
        }
    }
    class MyRandom
    {
        private int n;

        public int N
        {
            get
            {
                return this.n;
            }
            set
            {
                this.n = value;
            }
        }

        public MyRandom(int n)
        {
            this.n = n;
        }
        public MyRandom()
        {
            n = 0;
        }
        public void MakeSequence()
        {

            Random rd = new Random();
            int temp = 1 << 8;
            int flag = 0;
            StreamWriter sw = new StreamWriter("MakeSequence.inp");
            for (int i = 0; i < n; i++)
            {
                flag = rd.Next(2);
                if (flag == 1)
                    sw.WriteLine(rd.Next(temp));
                else
                    sw.WriteLine(-rd.Next(temp));
            }
            sw.Close();
        }
        public int[] GetSequence()
        {
            int[] arr = new int[n];
            StreamReader sr = new StreamReader("MakeSequence.inp");
            for (int i = 0; i < n; i++)
            {
                Int32.TryParse(sr.ReadLine(), out arr[i]);
            }
            sr.Close();
            return arr;
        }
    }
    class Sort
    {

        public void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public bool Compare(int a, int b)
        {
            if (a < b)
                return true;
            return false;
        }
        //sắp xếp chèn
        public void InsertionSort(int[] a)
        {
            int len = a.Length;
            for (int i = 1; i < len; i++)
            {
                int last = a[i];
                int j = i;
                while (j > 0 && (a[j - 1] > last))//tìm và chèn phần tử thứ k vào vị trí thích hợp
                {
                    a[j] = a[j - 1];
                    j--;
                }
                a[j] = last;
            }
        }
        //sắp xếp chọn
        public void SelecttionSort(int[] a)
        {
            int len = a.Length;
            for (int i = 0; i < len - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < len; j++)
                    if (a[min] > a[j])
                        min = j;
                Swap(ref a[i], ref a[min]);
            }
        }
        //Sắp xếp nổi bọt
        public void BubbleSort(int[] a)
        {
            int len = a.Length;
            int i = len;
            while (i > 0)
            {
                for (int j = 0; j < i - 1; j++)
                    if (a[j] > a[j + 1])
                        Swap(ref a[j], ref a[j + 1]);
                i--;
            }
        }
        //Sắp xếp trộn
        public void MergeSort(int[] a, int L, int R)
        {
            if (L < R)
            {
                int M = (L + R) / 2;
                MergeSort(a, L, M);
                MergeSort(a, M + 1, R);
                Merge(a, L, M, R);
            }
        }
        private void Merge(int[] a, int L, int M, int R)
        {
            int first1 = L, first2 = M + 1;
            int[] t = new int[R + 1];
            for (int k = L; k <= R; k++)
            {
                if (first1 > M)
                {//quét hết dãy con bên trái
                    t[k] = a[first2];
                    first2++;
                }
                else if (first2 > R)
                {//quét hết dãy con bên phải
                    t[k] = a[first1];
                    first1++;
                }
                else
                {
                    if (a[first1] < a[first2])
                    {
                        t[k] = a[first1];
                        first1++;
                    }
                    else
                    {
                        t[k] = a[first2];
                        first2++;
                    }
                }
            }
            for (int k = L; k <= R; k++)
                a[k] = t[k];
        }
        //Sắp xếp nhanh
        public void QuickSort(int a, int L, int R)
        {

        }
    }
    class HashSetDemo
    {
        public void ExampleHashSet()
        {
            HashSet<Int32> S = new HashSet<Int32>();
            S.Add(20);
            if (S.Contains(20))
            {
                Console.WriteLine("true");
            }
        }
    }
    class StackDemo
    {
        public void ExampleStack()
        {
            Stack<Int32> st = new Stack<int>();
            Random rd = new Random();
            for (int i = 0; i < 20; i++)
            {
                int t = rd.Next(100);
                st.Push(t);
                Console.WriteLine("Push({0})", t);
            }
            Console.Write("stack: ");
            PrintStack(st);
            for (int i = 0; i < 20; i++)
            {
                Console.Write("Pop({0}): ", st.Pop());
                PrintStack(st);
            }
        }
        private void PrintStack(Stack<Int32> st)
        {
            foreach (int e in st)
                Console.Write("{0}, ", e);
            Console.WriteLine();
        }
        private bool match(char c, char cc)
        {
            if (c == '(' && cc == ')')
                return true;
            if (c == '{' && cc == '}')
                return true;
            if (c == '[' && cc == ']')
                return true;
            return false;
        }
        public bool check(String s)
        {
            Stack<char> S = new Stack<char>();
            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (c == '(' || c == '{' || c == '[')
                {
                    S.Push(c);
                }
                else
                {
                    if (S.Count != 0)
                    {
                        char cc = S.Pop();
                        if (!match(cc, c))
                            return false;
                    }
                }
            }
            return S.Count == 0;
        }
    }
    class MapDemo
    {
        public void ExampleMap()
        {

        }
    }
    class CountWord
    {
        public void Solve()
        {
            StreamReader sr = new StreamReader("countword.txt");
            Dictionary<String, Int32> m = new Dictionary<String, Int32>();
            ISet<String> s = new HashSet<string>();
            String line;
            while ((line = sr.ReadLine()) != null)
            {
                s.Add(line);
                int o = m[line];
                o++;
                m[line] = o;
            }
            IDictionaryEnumerator ide = m.GetEnumerator();
            foreach (String e in s)
            {
                Console.WriteLine("{0} - {1}", ide.Key, ide.Value);
            }
            sr.Close();
        }
    }
    class MyWaterJug
    {
        public class State
        {
            public int x, y;
            String msg;
            public State parent;

            public State(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
            public State()
            {
                this.x = 0;
                this.y = 0;
                this.msg = "";
            }

            public String Msg
            {
                get
                {
                    return this.msg;
                }
                set
                {
                    this.msg = value;
                }
            }

        }

        private Queue<State> Q = new Queue<State>();

        //đổ nước ở bình 1 ra ngoài
        private bool GenMove1Out(State st)
        {
            if (st.x > 0 & st.y > 0)
            {
                return true;
            }
            return false;
        }
        //đổ nước ở bình 2 ra ngoài
        private bool GenMove2Out(State st)
        {
            if (st.x > 0 & st.y > 0)
            {
                return true;
            }
            return false;
        }
        //đổ đầy nước vào bình 1
        private bool GenFill1In(State st, int a)
        {
            if (st.x < a)
            {
                return true;
            }
            return false;
        }
        //đổ đầy nước vào bình 2
        private bool GenFill2In(State st, int b)
        {
            if (st.y < b)
            {
                return true;
            }
            return false;
        }
        //đổ nước từ bình 1 sang bình 2
        private bool GenPourFrom1To2(State st, int b)
        {
            if (st.y < b && st.x > 0)
            {
                return true;
            }
            return false;
        }
        //đổ nước từ bình 2 sang bình 1
        private bool GenPourFrom2To1(State st, int a)
        {
            if (st.y > 0 && st.x < a)
            {
                return true;
            }
            return false;
        }
        //kết thúc
        private bool Solution(State st, int c)
        {
            return st.x == c || st.y == c || st.x + st.y == c;
        }
        public Stack<State> WaterJug(int a, int b, int c)
        {
            bool[,] Closed = new bool[a+1, b+1];
            for (int i = 0; i <= a; i++)
            {
                for (int j = 0; j <= b; j++)
                {
                    Closed[i, j] = false;
                }
            }
            Q.Enqueue(new State());
            while (Q.Count > 0)
            {
                State st = Q.Dequeue();
                if (Closed[st.x, st.y] == false)
                {
                    if (Solution(st, c)) 
                    {
                        Stack<State> S = new Stack<State>();
                        while (st != null)
                        {
                            S.Push(st);
                            st = st.parent;
                        }
                        return S;
                    }

                    if (GenMove1Out(st))
                    {
                        State newSt = new State(0, st.y);
                        newSt.parent = st;
                        newSt.Msg = "Do het nuoc tu binh 1 ra ngoai";
                        Q.Enqueue(newSt);
                    }
                    if (GenMove2Out(st))
                    {
                        State newSt = new State(st.x, 0);
                        newSt.parent = st;
                        newSt.Msg = "Do het nuoc tu binh 2 ra ngoai";
                        Q.Enqueue(newSt);
                    }
                    if (GenFill1In(st, a))
                    {
                        State newSt = new State(a, st.y);
                        newSt.parent = st;
                        newSt.Msg = "Do day nuoc vao binh 1";
                        Q.Enqueue(newSt);
                    }
                    if (GenFill2In(st, b))
                    {
                        State newSt = new State(st.x, b);
                        newSt.parent = st;
                        newSt.Msg = "Do day nuoc vao binh 2";
                        Q.Enqueue(newSt);
                    }
                    if (GenPourFrom1To2(st, b))
                    {
                        State newState;
                        if (st.x + st.y < b)
                        {
                            newState = new State(0, st.x + st.y);
                        }
                        else
                        {
                            newState = new State(st.x + st.y - b, b);
                        }
                        newState.parent = st;
                        newState.Msg = "Do nuoc tu binh 1 sang binh 2";
                        Q.Enqueue(newState);
                    }
                    if (GenPourFrom2To1(st, a))
                    {
                        State newState;
                        if (st.x + st.y < a)
                        {
                            newState = new State(st.x + st.y, 0);
                        }
                        else
                        {
                            newState = new State(a, st.x + st.y - a);
                        }
                        newState.parent = st;
                        newState.Msg = "Do nuoc tu binh 2 sang binh 1";
                        Q.Enqueue(newState);
                    }
                    Closed[st.x, st.y] = true;
                }
            }
            return null;
        }
        public void PrintResult(Stack<State> S)
        {
            while (S.Count > 0)
            {
                State temp = S.Pop();
                Console.WriteLine("{0}: {1},{2}", temp.Msg, temp.x, temp.y);
            }
        }
    }
}