#include <iostream>

using namespace std;

//AC but slow
class linkInt
{
private:
	struct node
	{
		int data;
		node *next;
		node *prev;
		node(const int x,node *p = NULL, node *q = NULL)
		{
			data = x; next = p; prev = q;
		}
		node():next(NULL),prev(NULL){}
		~node(){}
	};
	node* head;
	node* tail;
	int curlen;
	node* get(int i)
	{
		node *p ;
			p = head->next;
			for(int j = 0; j < i; j++)
				p = p->next;

		return p;
	}
public:
	linkInt()
	{
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		head->prev = NULL;
		tail->next = NULL;
		curlen = 0;
	}
	linkInt(linkInt &x)
	{
		clear_All();
		curlen = x.length();
		for(int i = 0; i < curlen; i++)
		{
			insert_elem(i, x.visit(i));
		}
	}

	void clear_All()
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
		curlen = 0;
	}

	int length() const {return curlen;}

	void insert_elem(int i, const int &x)
	{
		node *p, *tem;
		if(curlen == 0 or i == 0) p = head;
		else p = get(i-1);
		tem = new node(x, p->next, p);
		p->next->prev = tem;
		p->next = tem;
		curlen++;
	}

	int visit(int i){return get(i)->data;}

	void traverse() const
	{
		node *p = head->next;
	//	while(p->data == 0)
		//	p = p->next;
		while(p != tail)
		{
			cout<<p->data;
			p = p->next;
		}
	}

	linkInt &operator=(linkInt &x)
	{
		if(this == &x) return *this;
		clear_All();
		curlen  = x.length();
		int i = 0;
		while(i < curlen)
		{
			node *p, *tem;
			if(i == 0 or curlen == 0) p =head;
			else p = get(i-1);
			tem = new node( x.visit(i), p->next, p);
			p->next->prev = tem;
			p->next = tem;
			i++;
		}
		return *this;
	}

};

void add(linkInt &sum, linkInt &n1, linkInt &n2)
	{
		int i = 0;
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


	}


int main()
{
	linkInt n1, n2, product;
	char ch;
	int x = 0, i = 0, j = 0;

	while(true)
	{
		cin.get(ch);
		x = int(ch) - '0';
		if( x < 0 or x > 9) break;
		n1.insert_elem(i, x);
		i++;
	}
	while(true)
	{
		cin.get(ch);

		x = int(ch) - '0';
		if( x < 0 or x > 9 ) break;
		n2.insert_elem(j, x);
		j++;
	}

	product.insert_elem(0,0);

	linkInt sums[10];
	sums[0].insert_elem(0,0);
	sums[1] = n1;
	for(int k = 2; k <= 9; k++)
	{
		add(sums[k],  sums[k-1] , sums[1]) ;
	}

	for(int k = n2.length()-1; k >=0; k--)
	{
		int curDigtal = n2.visit(k);
		linkInt tem;
		tem = sums[curDigtal];

		for(int p = n2.length() - k -1; p > 0; p-- )
			tem.insert_elem(tem.length(),0);

		linkInt temp ;
		add(temp, product , tem);
		product = temp;


	}


	product.traverse();
    return 0;
}
