#include <iostream>
#include <stdio.h>
using namespace std;

//AC

template<class elemType>
class priorityQueue
{
private:
	int curSize, maxSize;
	elemType *a;

	void doubleSpace()
	{
		maxSize *= 2;
		elemType *tem = a;
		a = new elemType[maxSize+1];
		for(int i = 1; i <= curSize; i++) a[i] = tem[i];
	}

	void percolateDown(int hole)
	{
		int child;
		elemType tem = a[hole];
		for(; hole * 2 <= curSize; hole = child)
		{
			child = hole*2;
			if(child != curSize and a[child+1] < a[child]) child++;
			if(a[child] < tem) a[hole] = a[child];
			else break;
		}
		a[hole] = tem;
	}
public:
	priorityQueue()
	{
		curSize = 0; maxSize = 5;
		a = new elemType[maxSize+1];
	}

	priorityQueue(const elemType *item, int s)
	{
		maxSize = s + 20; curSize = s;
		a = new elemType[maxSize];
		for(int i = 1; i <= curSize; i++) a[i] = item[i];
		buildHeap();
	}

	bool isEmpty()const {return curSize == 0;}

	void enQueue(const elemType &x)
	{
		if(curSize+1 == maxSize) doubleSpace();
		int hole = ++curSize;
		for(;hole>1 and x < a[hole/2]; hole/=2)
			a[hole] = a[hole/2];
		a[hole] = x;
	}

	elemType deQueue()
	{
		elemType tem = a[1];
		a[1] = a[curSize--];
		percolateDown(1);
		return tem;
	}
	void buildHeap()
	{
		for(int i = curSize/2; i >0; i--)
			percolateDown(i);
	}
};

int main()
{
    int n, m, x, a, b, i,op;
    cin>>n>>m;
    priorityQueue<int> *q = new priorityQueue<int> [n];
    for(i = 0; i < n; i++)
	{
		scanf("%d",&x);
		//cin>>x;
		q[i].enQueue(x);
	}
	for(i = 0; i < m; i ++)
	{
		scanf("%d",&op);
		//cin>>op;
		switch(op)
		{
			case 0:
			{
				scanf("%d%d",&a,&b);
				//cin>>a>>b;
				while(!q[b].isEmpty()) q[a].enQueue(q[b].deQueue());
				break;
			}
			case 1:
				{
					scanf("%d",&a);
					//cin>>a;
					if(q[a].isEmpty()) printf("-1\n");   //cout<<-1<<endl;
					else  printf("%d\n",q[a].deQueue());  //cout<<q[a].deQueue()<<endl;
					break;
				}
			case 2:
				{
					scanf("%d%d",&a,&b);
					//cin>>a>>b;
					q[a].enQueue(b);
				}
		}
	}
    return 0;
}
