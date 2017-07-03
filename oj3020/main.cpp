#include <iostream>
#include <queue>
using namespace std;

//ac

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
		curSize = 0; maxSize = 20;
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
	int n, m;
	cin>>n>>m;
	priorityQueue<long long> q;
	int f, i;
	long long x, wpl = 0;
	for( i = 1; i <= n; i++)
	{
		cin>>f;
		q.enQueue(f);
	}
	if (m!=2)
      {
        while ((n-1)%(m-1)!=0)
          {
            n++;
            q.enQueue(0);
          }
      }


	while(n != 1)
	{
		x = 0;
		for(i = 1; i <= m; i++)
			x += q.deQueue();
		n = n-m+1;
		wpl+= x;
		q.enQueue(x);
	}
	cout<<wpl ;

    return 0;
}
