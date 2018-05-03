using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Bai15
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable hashTable = new Hashtable();
            hashTable.Add("12345", "duy anh");
            hashTable.Add("10245", "alo chat");
            hashTable.Add("mssv", "20155076");

            Console.WriteLine("Hashtable name: {0}", hashTable);
            Console.WriteLine("Count = {0}", hashTable.Count);

            Console.WriteLine("Keys and Values: ");
            Print(hashTable);

            MyArray ma = new MyArray();
            int[] arr = ma.GetRandomArray();
            ma.PrintMyArr(arr);
            Console.WriteLine("------------------------------------");
            Array.Sort(arr);
            ma.PrintMyArr(arr);
            Console.WriteLine("------------------------------------");
            Array.Reverse(arr);
            ma.PrintMyArr(arr);
        }
        private static void Print(Hashtable table)
        {
            IDictionaryEnumerator ide = table.GetEnumerator();
            while (ide.MoveNext())
            {
                Console.WriteLine("Key: {0}, Value: {1}", ide.Key, ide.Value);
            }
        }
    }
    class MyArray
    {
        public int[] GetRandomArray()
        {
            Random rd = new Random();
            int len = rd.Next(10, 200);
            int[] arr = new int[len];
            for (int i = 0; i < len; i++)
                arr[i] = rd.Next(0, 1000);
            return arr;
        }
        public void PrintMyArr(int[] a)
        {
            foreach (int e in a)
            {
                Console.Write("{0} ", e);
            }
            Console.WriteLine();
        }
    }
}
