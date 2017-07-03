#include <iostream>

using namespace std;


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
	node *lastVisit;
	int lastVisitNum;
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
	void traverse_reverse() const;
	friend  linkList<elemType> operator+(linkList<elemType> &x1, linkList<elemType> &x2)
	{
		linkList<elemType> s;
		int i = 0, l1 = x1.length(), l2 = x2.length();
		s.curlength = l1 + l2;
		for(i = 0 ; i < l1; i++)
		{
			s.insert_elem(i, x1.visit(i));
		}
		for(i = 0; i < l2; i++)
		{
			s.insert_elem(i+l1, x2.visit(i));
		}
		return s;
	}


	linkList<elemType> &operator=(linkList<elemType> &x)
	{
		if(this == &x) return *this;
		clear_All();
		curlength  = 0;

		while(curlength < x.curlength)
		{
			node *p, *tem;
			if(curlength == 0 ) p =head;
			else p = get(curlength-1);
			tem = new node( x.visit(curlength), p->next, p);
			p->next->prev = tem;
			p->next = tem;
			curlength++;
		}
		return *this;
	}
};


template <class elemType>
void linkList<elemType>::checkBound(int i) const
{
	if(i < 0 or i >= curlength) cout<<"out of bound"<<endl;
}


template <class elemType>
typename linkList<elemType>::node* linkList<elemType>::get(int i)
{
	checkBound(i);
	node *p;
	if(i == lastVisitNum + 1)
	{
		lastVisit = lastVisit->next;
		lastVisitNum = i;
		return lastVisit;
	}
	if(i == lastVisitNum - 1)
	{
		lastVisit = lastVisit->prev;
		lastVisitNum = i;
		return lastVisit;
	}


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
	lastVisitNum = i;
	lastVisit = p;
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
	lastVisit = NULL;
	lastVisitNum = -10;
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


template <class elemType>
void linkList<elemType>::traverse_reverse() const
{
	node *p = tail->prev;
	while(p != head)
	{
		cout<<p->data<<" ";
		p = p->prev;
	}
}


int main()
{
	int m, n, i = 0, j = 0;
	char t[10];
	cin>>t;

	if(t[0] == 'i')
	{
		int x;
		linkList<int> l1, l2;
		cin>>n>>m;
		for(i = 0; i < n; i++)
		{
			cin>>x;
			l1.insert_elem(i, x);
		}
		for(j = 0; j < m; j++)
		{
			cin>>x;
			l2.insert_elem(j, x);
		}
		linkList<int> sum = l1 + l2;
		sum.traverse();
	}
	else if(t[0] == 'c')
	{
		char x;
		linkList<char> l1, l2;
		cin>>n>>m;
		for(i = 0; i < n; i++)
		{
			cin>>x;
			l1.insert_elem(i, x);
		}
		for(j = 0; j < m; j++)
		{
			cin>>x;
			l2.insert_elem(j, x);
		}
		linkList<char> sum = l1 + l2;
		sum.traverse();
	}
	else if(t[0] == 'd')
	{
		double x;
		linkList<double> l1, l2;
		cin>>n>>m;
		for(i = 0; i < n; i++)
		{
			cin>>x;
			l1.insert_elem(i, x);
		}
		for(j = 0; j < m; j++)
		{
			cin>>x;
			l2.insert_elem(j, x);
		}
		linkList<double> sum = l1 + l2;
		sum.traverse();
	}

    return 0;
}
