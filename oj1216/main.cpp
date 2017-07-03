#include <iostream>

using namespace std;

//ac

class priorityQueue
{
private:
	int curSize;
	int maxSize;
	int *a;

public:
	priorityQueue(int capacity = 20000)
	{
		maxSize = capacity;
		a = new int[maxSize];
		curSize = 0;
	}
	bool isEmpty(){return curSize == 0;}

	void enQueue(int &x)
	{
		int hole = ++curSize;
		for(; hole>1 and x <a[hole/2]; hole/=2 )
			a[hole] = a[hole/2];
		a[hole] = x;
	}

	int deQueue()
	{
		int minItem;
		minItem = a[1];
		a[1] = a[curSize--];
		percolateDown(1);
		return minItem;
	}

	void percolateDown(int hole)
	{
		int child, tem = a[hole];
		for(; hole*2 <= curSize; hole = child)
		{
			child = hole * 2;
			if(child != curSize and a[child+1] <a[child]) child++;
			if(a[child]< tem) a[hole] = a[child];
			else break;
		}
		a[hole] = tem;

	}
	int getMin(){return a[1];}

	void print()
	{
		for(int i = 1; i <= curSize; i++) cout<<a[i]<<" ";
		cout<<endl;
	}

	int findX(int x)
	{
		int Minindex , minElem , i;

		for(i = 1; i <= curSize; i++)
		{
			if(a[i] > x) {minElem = a[i]; Minindex = i; break; }
		}

		for(int j = i; j <= curSize; j++)
		{
			if(a[j] > x and minElem > a[j])
			{
				minElem = a[j]; Minindex = j;
			}
		}
		return Minindex;
	}

	void decreace(int i, int v)
	{
		a[i] -= v;
		int hole = i, x = a[i];
		for(; hole>1 and x <a[hole/2]; hole/=2 )
			a[hole] = a[hole/2];
		a[hole] = x;

	}

};


int main()
{
    int m, i, x, k,v;
    char input[10];
    cin>>m;
    priorityQueue priQueue;

    for(i = 1; i <= m; i++)
	{
		cin>>input;

		if(input[0] == 'i')
		{
			cin>>x;
			priQueue.enQueue(x);
		}

		else if(input[0] == 'f')
		{
			cin>>x;
			cout<<priQueue.findX(x)<<endl;

		}
		else if(input[0] == 'd')
		{
			cin>>k>>v;
			priQueue.decreace(k,v);

		}
		//priQueue.print();
	}

    return 0;
}
