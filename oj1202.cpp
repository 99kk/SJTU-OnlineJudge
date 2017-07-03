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
		cout<<p->data;
		p = p->next;
	}

}


template <class elemType>
void linkList<elemType>::traverse_reverse() const
{
	node *p = tail->prev;
	while(p != head)
	{
		cout<<p->data;
		p = p->prev;
	}
}


int main()
{
	linkList<int> n1, n2;
	char ch;
	int x = 0, i = 0;

	while(true)
	{
		cin.get(ch);
		x = int(ch) - '0';
		if( x < 0 or x > 9) break;
		n1.insert_elem(i, x);
		i++;
	}
	i = 0;
	while(true)
	{
		cin.get(ch);
		x = int(ch) - '0';
		if( x < 0 or x > 9 ) break;
		n2.insert_elem(i, x);
		i++;
	}

	i = 0;
	linkList<int> sum;
	bool carry = false;
	int onesum;
	int l1 = n1.length(),l2 = n2.length(), minl = min(l1, l2);
	while(i < minl)
	{
		onesum = n1.visit(l1-i-1) + n2.visit(l2-i-1) + carry;
		carry = false;
		if(onesum >= 10)
		{
			onesum -= 10;
			carry = true;
		}
		sum.insert_elem(0, onesum);
		i++;
	}

	if(i == l1)
		while(i < l2)
		{
			onesum = n2.visit(l2-i-1) + carry;
			carry = false;
			if(onesum >= 10)
			{
				onesum -= 10;
				carry = true;
			}
			sum.insert_elem(0, onesum);
			i++;
		}
	else
		while(i < l1)
		{
			onesum = n1.visit(l1-i-1) + carry;
			carry = false;
			if(onesum >= 10)
			{
				onesum -= 10;
				carry = true;
			}
			sum.insert_elem(0, onesum);
			i++;
		}
	if(carry) sum.insert_elem(0, carry);
	sum.traverse();
    return 0;
}
