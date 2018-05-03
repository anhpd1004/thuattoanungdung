using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StackAndQueue
{
    class Program
    {
        static void Main(string[] args)
        {
            MyQueue<Int32> q = new MyQueue<int>();
            q.Enqueue(5);
            q.Enqueue(10);
            q.Enqueue(11);
            q.Enqueue(2);
            q.PrintQueue();
            Console.WriteLine(q.Peek());
            q.Dequeue();
        }
    }

    //STACK
    class MyStack<T>
    {
        private int count;
        private T[] s;

        public MyStack()
        {
            this.count = 0;
            this.s = new T[1];
        }

        //tra ve phan tu dau tien ma khong xoa
        public T Peek()
        {
            return s[count - 1];
        }
        //tra ve phan tu dau tien va xoa 
        public T Pop()
        {
            count--;
            return s[count];
        }
        //them phan tu vao dau 
        public void Push(T data)
        {
            if(this.s.Length > count) 
            {
                s[count] = data;
                count++;
            }
            else
            {
                T[] newS = new T[s.Length * 2];
                for (int i = 0; i < s.Length; i++)
                {
                    newS[i] = s[i];
                }
                newS[count] = data;
                count++;
                s = newS;
            }
        }
        //xoa tat ca cac thanh phan trong ngan xep
        public void Clear()
        {
            T[] t = new T[1];
            this.s = t;
            count = 0;
        }
        //tra ve so phan tu cua Stack
        public int Count() { return this.count; }

        //kiem tra xem Stack co rong khong
        public bool IsEmpty()
        {
            return this.count == 0;
        }

        //hien thi Stack
        public void PrintStack()
        {
            if (IsEmpty()) 
            {
                Console.WriteLine("Empty Stack.");
                return;
            }
            for (int i = 0; i < this.count - 1; i++)
            {
                Console.Write(s[i] + ", ");
            }
            Console.Write(s[count - 1] + "\n");
        }
    }

    class MyQueue<T>
    {
        private Node<T> head, tail;
        private int count;

        class Node<T>
        {
            private T data;
            public Node<T> pre;
            public Node()
            {
                this.pre = null;
            }
            public Node(T data)
            {
                this.data = data;
                this.pre = null;
            }
            public T Data
            {
                get
                {
                    return this.data;
                }
                set
                {
                    this.data = value;
                }
            }
        }

        public MyQueue()
        {
            this.head = new Node<T>();
            this.tail = head;
            this.count = 0;
        }

        //tra ve phan tu dau tien vao hang doi ma khong xoa
        public T Peek()
        {
            return tail.Data;
        }
        //them phan tu vao dau hang doi 
        public void Enqueue(T data)
        {
            Node<T> newNode = new Node<T>(data);
            head.pre = newNode;
            head = newNode;
            count++;
        }
        //lay va xoa phan tu o cuoi hang doi, tuc la phan tu vao dau tien
        public T Dequeue()
        {
            Node<T> newNode = new Node<T>(tail.Data);
            tail = tail.pre;
            count--;
            return newNode.Data;
        }
        //xoa tat ca cac thanh phan trong ngan xep
        
        //tra ve so phan tu cua Stack
        public int Count() { return this.count; }

        //kiem tra xem Queue co rong hay khong
        public bool IsEmpty()
        {
            return this.count == 0;
        }

        //hien thi Stack
        public void PrintQueue()
        {
            if (IsEmpty())
            {
                Console.WriteLine("Empty Queue.");
                return;
            }
            Node<T> t = tail;
            while (t != null)
            {
                Console.Write(t.Data + ", ");
                t = t.pre;
            }
        }
    }
}
