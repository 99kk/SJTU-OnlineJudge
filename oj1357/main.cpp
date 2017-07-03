#include <iostream>

using namespace std;

//AC

template<class elem>
class linkQueue
{
private:

	struct node
	{
		elem data;
		node*next;
		node():next(NULL){}
		node(const elem &x):data(x),next(NULL){}
	};
	node* head, *tail;
public:
	linkQueue(){head = tail = NULL;}

	void enQueue(const elem &x)
	{
		if(tail == NULL) head = tail = new node(x);
		else
		{
			node *p = new node(x);
			tail->next = p;
			tail = tail->next;
		}
	}

	elem deQueue()
	{
		node *tem = head;
		elem x = head->data;
		head = head->next;
		if(head == NULL) tail = NULL;
		delete tem;
		return x;
	}
	bool isEmpty(){return head == NULL;}
	void print()
	{
		node *p = head;
		while(p!=NULL)
		{
			cout<<p->data<<" "; p = p->next;
		}
		cout<<endl;
	}
};


int checkPath(char a[], int path[])
{
	int hNum = 0, jNum = 0, i;

	linkQueue<int> q;
	bool visited[26] = {false};
	for(i = 1; i <=25; i++) visited[i] = false;
	int positionID, curNum = 0;

	q.enQueue(path[0]);visited[path[0]] = true;

	while(!q.isEmpty())
	{
		positionID = q.deQueue(); curNum++;
		if(a[positionID] == 'H') hNum++;
			else jNum++;
		for(i = 0; i < 7; i++)
		{
			if(visited[path[i]]) continue;
			if(positionID +1 == path[i] and positionID %5 != 0) {q.enQueue(path[i]);visited[path[i]] = true;}
			if(positionID -1 == path[i] and positionID %5 != 1) {q.enQueue(path[i]);visited[path[i]] = true;}
			if(positionID + 5 == path[i] or positionID - 5 == path[i]) {q.enQueue(path[i]);visited[path[i]] = true;}
		}
	}

	if(curNum == 7 and hNum<jNum){

		return 1;}
	else return 0;


}

int main()
{
    int i, n = 0, path[7] = {0};
    char  a[26];
    for(i = 1; i <=25; i++)
			cin>>a[i];


	for(path[0] = 1; path[0] <= 19; path[0]++)
		for(path[1] = path[0]+1; path[1] <= 20; path[1]++)
		for(path[2] = path[1]+1; path[2] <= 21; path[2]++)
		for(path[3] = path[2]+1; path[3] <= 22; path[3]++)
		for(path[4] = path[3]+1; path[4] <= 23; path[4]++)
		for(path[5] = path[4]+1; path[5] <= 24; path[5]++)
		for(path[6] = path[5]+1; path[6] <= 25; path[6]++)
			n+= checkPath(a, path);

cout<<n;


    return 0;
}
