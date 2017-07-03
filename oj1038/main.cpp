#include <iostream>

using namespace std;

//AC

template<class elemType>
class linkList
{
private:
	struct node
	{
		elemType data;
		node *next;
		node *prev;
		node(const elemType &x, node *p = NULL, node *q = NULL)
		{
			data = x; next = p; prev = q;
		}
		node():next(NULL), prev(NULL){}
		~node(){}
	};
	node *head;
	node *tail;

	int curlength;
	void checkBound(int i) const;
	node *get(int i);
public:
	linkList();
	~linkList();
	void clear_All();
	int length() const {return curlength;}
	void insert_elem(int i, const elemType &x);
	elemType visit(int i);
	void traverse() const;
	void remove_elem(int i)
	{
		node *p = get(i);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		curlength--;
	}
};


template <class elemType>
void linkList<elemType>::checkBound(int i) const
{
	if(i < 0 or i >= curlength) ;
}


template <class elemType>
typename linkList<elemType>::node* linkList<elemType>::get(int i)
{
	checkBound(i);
	node *p;


	if(i < curlength / 2)
	{
		p = head->next;
		for(int j = 0; j < i; j++)
			p = p->next;
	}
	else
	{
		p = tail->prev;
		for(int j = curlength-1; j > i; j--)
			p = p->prev;
	}
	return p;
}


template <class elemType>
linkList<elemType>::linkList()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	head->prev = NULL;
	tail->next = NULL;

	curlength = 0;
}

template<class elemType>
void linkList<elemType>::clear_All()
{
	node *p = head->next, *q;
	head->next = tail;
	tail->prev = head;
	while(p != tail)
	{
		q = p->next;
		delete p;
		p = q;
	}
	curlength = 0;
}

template <class elemType>
linkList<elemType>::~linkList()
{
	clear_All();
	delete head;
	delete tail;
}

template <class elemType>
void linkList<elemType>::insert_elem(int i, const elemType &x)
{
	node *p, *tem;
	if(curlength == 0 or i == 0) p = head;
	else p = get(i-1);
	tem = new node(x, p->next, p);
	p->next->prev = tem;
	p->next = tem;
	curlength++;
}


template <class elemType>
elemType linkList<elemType>::visit(int i)
{
	return get(i)->data;
}


template <class elemType>
void linkList<elemType>::traverse() const
{
	node *p = head->next;

	while(p != tail)
	{
		cout<<p->data<<" ";
		p = p->next;
	}

}


int main()
{
	linkList<int> a;
	int m, k, lastMonsey = 0, curMonsey = 0;
	cin>>m;
	for(int i= 0; i < m; i++)
	{
		a.insert_elem(i, i+1);
	}

	for(int i = 1; i <= m-1; i++)
	{
		cin>>k;
		curMonsey = lastMonsey + k -1;
		curMonsey = curMonsey % a.length();

		a.remove_elem(curMonsey);
		lastMonsey = curMonsey;
	}

	a.traverse();
}
