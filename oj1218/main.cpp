#include <iostream>

using namespace std;

//AC

int slice(int *a,int low, int high)
	{
		int key = a[low], i = low, j = low+1, tem;
		for(j = low+1; j <= high; j++)
		{
			if(key > a[j])
			{
				i++;
				tem = a[i]; a[i] = a[j]; a[j] = tem;
			}
		}
		tem = a[low]; a[low] = a[i]; a[i] = tem;
		return i;
	}

void quickSort(int *a,int low, int high)
	{
		if(low< high)
		{
			int w = slice(a,low, high);
			quickSort(a, low, w-1);
			quickSort(a, w+1, high);
		}
	}

class setTest
{
private:
	struct node
	{
		int data;
		node*next;
		node *prev;
		node(const int &x){data = x; next = NULL;prev = NULL;}
		node(){next = NULL;prev = NULL;}
	};



	node*head, *tail;

public:
	setTest()
	{
		head = new node(); tail = new node();
		head->next = tail;
		tail->prev = head;

	}



	void print()
	{
		node *p = head->next;
		while(p != tail)
		{
			cout<<p->data<< " "; p = p->next;
		}
		cout<<endl;
	}




	void plusSet(int *s, int len)
	{
		node *p = head->next, *tem;

		for(int i =1; i <=len; i++)
		{
			if(head->next == tail)
			{
				p = head->next;
				tem = new node(s[i]);
				tem->next = p; tem->prev = p->prev;
				p->prev->next = tem; p->prev = tem;
			}
			else
			{

				p = head->next;
				while(p != tail)
				{
					if(p->data == s[i]) break;
					if(p->data > s[i])
					{
						tem = new node(s[i]);
						tem->next = p; tem->prev = p->prev;
						p->prev->next = tem; p->prev = tem;
						break;
					}
					p = p->next;
				}
				if(p == tail)
				{
					tem = new node(s[i]);
					tem->next = p; tem->prev = p->prev;
					p->prev->next = tem; p->prev = tem;
				}
			}

		}
		/*
		for(int i = 1; i <= len; i++)
		{
			if(p == tail)
			{
				tem = new node(s[i]);
				tem->next = p; tem->prev = p->prev;
				p->prev->next = tem; p->prev = tem;
			}
			else
			{
				while(p->data<s[i]) p = p->next;
				if(p->data == s[i]) continue;
				tem = new node(s[i]);
				tem->next = p; tem->prev = p->prev;
				p->prev->next = tem; p->prev = tem;
				p = tem;
			}

		}
		*/
	}

	void minusSet(int *s, int len)
	{
		node* p = head->next;
		if(p == tail) return;

		int i = 1;
		while(p != tail)
		{
			for(i = 1; i <=len; i++)
			{
				if(p->data == s[i])
				{
					p->prev->next = p->next; p->next->prev = p->prev;
				}

			}
			p = p->next;
		}
		/*

		for(int i =1; i <= len;i++)
		{
			if(p == head) p =head->next;
			while(p->data < s[i]) p = p->next;
			if(p->data == s[i])
			{

				p->prev->next = p->next; p->next->prev = p->prev;
				p = p->prev;
			}
			else
			{
				p = p->prev;
			}
		}
		*/
	}

	void andSet(int *s, int len)
	{
		node*p = head->next;
		int i = 1;
		bool f;
		while(p != tail)
		{
			f = false;
			for(i = 1; i <=len; i++)
			{
				if(p->data == s[i]) f = true;
			}
			if(!f)
			{
				p->prev->next = p->next; p->next->prev = p->prev;
			}
			p = p->next;
		}
		/*
		for(i =1; i <= len; i++)
		{
			if(p == tail) return;
			if(p->data == s[i]){p=p->next; continue;}
			else if(p->data >s[i]){continue;}
				else
				{
					p->prev->next = p->next; p->next->prev = p->prev;
					p = p->next; i--;
				}
		}
		if(p != tail and p!= head) {p->prev->next = tail; tail->prev = p->prev;  }
			*/
	}
};


int main()
{
    int n,m,i,j, *s;
    char c;
    setTest testSet;

    cin>>n;
    for(i = 1; i <=n;i++)
	{
		cin>>c>>m;
		s = new int[m+1];
		for(j = 1; j <= m; j++)
		{
			cin>>s[j];
		}

		quickSort(s,1, m);
		switch(c)
		{
			case '+':{testSet.plusSet(s, m);break;}
			case '-':{testSet.minusSet(s, m);break;}
			case '*':{testSet.andSet(s, m);break;}
		}
		testSet.print();
	}



    return 0;
}
