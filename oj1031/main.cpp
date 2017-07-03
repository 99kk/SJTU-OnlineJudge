#include <iostream>

using namespace std;

//ac

int n;
int a[101][101];
bool visited[101][101];
int xdir[4] = {1,0,0,-1}, ydir[4] = {0,1,-1,0}, curmax, curmin;

struct position
{
	int x, y;
	position(int a, int b){x = a, y = b;}
	position(const position &p){x = p.x; y = p.y;}
	position(){}
};

template<class elemType>
class linkQueue
{
private:
	struct node
	{
		elemType data;
		node* next;
		node(const elemType &x, node*p = NULL) {data = x; next = p;}
		node():next(NULL){}
		~node(){}
	};
	node *head;
	node *tail;

public:
	linkQueue(){head = tail = NULL;}

	bool isEmpty(){return head == NULL;}

	void enQueue(const elemType &x)
	{
		if(tail == NULL) head = tail = new node(x);
		else
		{
			node *p = new node(x);
			tail->next = p;
			tail = tail->next;
		}
	}

	elemType deQueue()
	{
		node *tem = head;
		elemType x = head->data;
		head = head->next;
		if(head == NULL) tail = NULL;
		delete tem;
		return x;
	}

	elemType getHead(){return head->data;}

	void print()
	{
		node*p=head;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};

bool findPath(int lowBound, int highBound)
{
	if(a[1][1] < lowBound or a[1][1] > highBound or a[n][n] < lowBound or a[n][n] > highBound) return false;

	for(int j = 1; j <= n; j++)
		for(int k = 1; k <= n; k++)
				visited[j][k] = false;

	linkQueue<position> q;
	q.enQueue((position){1,1});
	position pos;
	while(!q.isEmpty())
	{
		pos = q.deQueue();
		visited[pos.x][pos.y] = true;
		if(pos.x == n and pos.y == n) return true;
		for(int i = 0; i < 4; i++)
		{
			if(pos.x + xdir[i] >0 and pos.x+xdir[i] <=n and pos.y + ydir[i] >0 and pos.y+ydir[i] <=n)
				if(a[pos.x + xdir[i]][pos.y + ydir[i]] >= lowBound and a[pos.x + xdir[i]][pos.y + ydir[i]] <= highBound)
					if(!visited[pos.x + xdir[i]][pos.y + ydir[i]])
			{
				q.enQueue((position){pos.x + xdir[i], pos.y + ydir[i]});
				visited[pos.x + xdir[i]][pos.y + ydir[i]] = true;
			}
		}
	}
	return false;
}


int findMin()
{
	int low = 0, high = curmax - curmin, mid, i, j;

	while(low < high)
	{
		mid = (low + high)/2;
		bool found = false;
		for( i = 0; i <= 110 - mid; i++ )
		{
			if(findPath(i, i+ mid))
				{found = true; break;}

		}

		if(found)
		{
			high = mid;
		}
		else low = mid+1;
	}
	return low;
}


int main()
{
    int i, j ;
    cin>>n;
    for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			cin>>a[i][j];
			visited[i][j] = false;
			curmax  = max(curmax, a[i][j]);
			curmin = min(curmin, a[i][j]);
		}

	cout<<findMin();




    return 0;
}
