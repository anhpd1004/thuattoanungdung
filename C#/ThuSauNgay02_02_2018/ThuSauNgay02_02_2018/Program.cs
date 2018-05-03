using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThuSauNgay02_02_2018
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryString bs = new BinaryString(13);
            bs.Try(1);
            bs.PrintSolution();
        }
    }
    class BinaryString
    {
        private int count;

        private int n;
        private int sum;

        public int[] arr;

        public BinaryString(int n)
        {
            count = 0;
            this.n = n;
            arr = new int[n + 1];
            arr[0] = 0;
            sum = 0;
        }

        public void PrintSolution()
        {
            Console.WriteLine(count);
        }
        private bool Check(int v, int k)
        {
            if (sum == 7 && v == 1) return false;
            return (v + arr[k-1] < 2);
        }
        public void Try(int k)
        {
            for (int i = 0; i < 2; i++)
            {
                if (Check(i, k))
                {
                    arr[k] = i;
                    sum += i;
                    if (k == n)
                    {
                        if (sum == 7)
                        {
                            count++;
                            foreach (int e in arr)
                                Console.Write(e);
                            Console.WriteLine();
                        }
                    }
                    else
                        Try(k + 1);
                    sum -= i;
                }
            }
        }
    }
    class HoanVi
    {
        private int n;
        private int count;
        private int[] x;
        private bool[] mark;

        public HoanVi(int n)
        {
            this.n = n;
            count = 0;
            x = new int[n + 1];
            x[0] = 0;
            mark = new bool[n + 1];
            for (int i = 0; i < n + 1; i++)
                mark[i] = false;

        }
        public void PrintSolution()
        {
            Console.WriteLine(count);
        }
        public void Try(int k)
        {
            for (int i = 1; i < n + 1; i++)
            {
                if (!mark[i])
                {
                    mark[i] = true;
                    x[k] = i;
                    if (k == n)
                    {
                        count++;
                        for (int j = 1; j <= n; j++)
                        {
                            Console.Write(x[j] + " ");
                        }
                            Console.WriteLine();
                    }
                    else
                        Try(k + 1);
                    mark[i] = false;
                }
            }
        }
    }
}
