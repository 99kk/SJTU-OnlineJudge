#include <iostream>
#include <math.h>
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
	void remove_elem(int i);
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
void linkList<elemType>::remove_elem(int i)
{
	node *p = get(i);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	curlength--;
}

template <class elemType>
void linkList<elemType>::checkBound(int i) const
{
	if(i < 0 or i >= curlength) return;
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

void list_Op(linkList<char> t[], char line[], int row)
{
	int n1 = 0, n2 = 0, i = 5;
	while(line[i] != ' ')
	{
		n1  = n1 * 10 + (line[i] - '0');
		i++;
	}
	i++;
	while(line[i] != '\0')
	{
		n2 = n2 * 10 + (line[i] - '0');i++;
	}
	i++;
	if(n1<=n2 and n1>=1 and n2<=row)
		for(int i = n1; i <= n2; i++)
				{t[i].traverse();cout<<endl;}
	else	cout<<"Error!"<<endl;
}

void ins_op(linkList<char> t[], char line[], int row)
{
	int j = 0, i = 4, n1 = 0, n2 = 0;
	while(line[i] != ' ')
	{
		n1  = n1 * 10 + (line[i] - '0');i++;
	}
	i++;
	while(line[i] != ' ')
	{
		n2 = n2 * 10 + (line[i] - '0');i++;
	}
	i++;
	if(1<= n1 and n1<=row and n2>=1 and n2 <= t[n1].length()+1)
	{
		j = n2-1;
		while(line[i] != '\0')
	{
		t[n1].insert_elem(j, line[i]);
		i++; j++;
	}
	}
	else	cout<<"Error!"<<endl;

}

void del_op(linkList<char> t[], char line[], int row)
{
	int j = 0, i = 4, n1 = 0, n2 = 0, n3 = 0;
	while(line[i] != ' ')
	{
		n1  = n1 * 10 + (line[i] - '0');i++;
	}
	i++;
	while(line[i] != ' ')
	{
		n2 = n2 * 10 + (line[i] - '0');i++;
	}
	i++;
	while(line[i] != '\0')
	{
		n3 = n3 * 10 + (line[i] - '0');i++;
	}
	if(1<= n1 and n1<=row and n2>=1 and n2 <= t[n1].length()+1 and n2+n3>=1 and n2+n3<=t[n1].length()+1)
	{
		for(int i = n2; i < n2+n3; i++)
			t[n1].remove_elem(i-1);
	}
	else cout<<"Error!"<<endl;

}

int main()
{
    linkList<char> text[101];
    char line[2001];
    int i = 0, row = 1;
    while(true)
	{

		i = 0;
		cin.getline(line, 2000);
		if(line[0] == '*' and line[1] == '*') break;
		while(line[i] != '\0')
		{
			text[row].insert_elem(i, line[i]);
			i++;
		}
		row++;
	}
	row--;
	while(true)
	{
		cin.getline(line, 2000);
		if(line[0] == 'q' and line[1] == 'u' and line[2]=='i' and line[3] =='t' and line[4] == '\0')
		{
			for(i = 1; i < row; i ++)
			{
				text[i].traverse();
				cout<<endl;
			}
			text[row].traverse();
			break;
		}

		else if(line[0] == 'l' and line[1] == 'i' and line[2]=='s' and line[3] =='t' and line[4] == ' ')
		{
			list_Op(text, line, row);
		}
		else if(line[0] == 'i' and line[1] == 'n' and line[2]=='s' and line[3] ==' ')
		{
			ins_op(text, line, row);
		}
		else if(line[0] == 'd' and line[1] == 'e' and line[2]=='l' and line[3] ==' ')
		{
			del_op(text, line, row);
		}
		else cout<<"Error!"<<endl;
	}





    return 0;
}
