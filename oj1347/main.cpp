#include <iostream>

using namespace std;

#define elemType char

//AC

class linkStructure
{
private:
	struct node
	{
		elemType data;
		node*next;
		node():next(NULL){}
		node(const elemType &x):data(x),next(NULL){}
	};

	node* head;
	node* tail;

	void swap(node *p, node *q)
	{
		elemType tem = p->data;
		p->data = q->data;
		q->data = tem;
	}

	node *slice(node *low, node *high)
	{
		elemType key = low->data;
		node*p = low, *q = low->next;
		while(q != high)
		{
			if(q->data < key)
			{
				p = p->next;
				swap(p, q);

			}
			q = q->next;
		}
		if(q->data < key) swap(q,p);
		swap(low, p);
		return p;
	}

	void quickSort(node *low, node* high)
	{
		if(low != high and low != NULL and high != NULL)
		{
			node *p = slice(low, high);
			quickSort(low, p);
			quickSort(p->next, high);
		}
	}


public:
	linkStructure(){head = tail = new node();}

	//common
	bool isEmpty(){ return head->next == NULL; }

	void print()
	{
		node* p = head->next;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}


	//linkStack
	void push(const elemType &x)
	{
		node* tem = new node(x);
		tem->next = head->next;
		head->next = tem;
	}

	elemType pop()
	{
		node*tem = head->next;
		elemType x = tem->data;
		head->next = tem->next;
		delete tem;
		return x;
	}

	elemType top() { return head->next->data; }


	//linkQueue
	void enQueue(const elemType &x)
	{
		node* tem = new node(x);
		tail->next = tem;
		tail = tem;
	}

	elemType deQueue()
	{
		node* tem = head->next;
		head->next = tem->next;
		elemType x = tem->data;
		delete tem;
		return x;
	}

	//linkList

};



bool isChar(const char x)
{
	return (x>='a' and x <= 'z') or (x>='A' and x<='Z');
}


int main()
{
	linkStructure colorText;
    char input[1002], x;
    cin.getline(input, 1001);
    int red = 0, yellow = 0, blue = 0;
    for(int i = 0; input[i] != '\0'; i++)
	{

		x = input[i];
		if(x == '<' and input[i+1] == 'r')
		{
			while(input[i] != '>')i++;
			colorText.push('r');
			while(input[i] != '<' and input[i+1] != '/' and input[i+1] != 'r' and input[i+1] != 'y' and input[i+1] != 'b')
			{
				x = input[i];i++;
				if(isChar(x))red++;
			}
			i--;continue;
		}
		else if(x == '<' and input[i+1] == 'y')
		{
			while(input[i] != '>')i++;
			colorText.push('y');
			while(input[i] != '<'and input[i+1] != '/' and input[i+1] != 'r' and input[i+1] != 'y' and input[i+1] != 'b')
			{
				x = input[i];i++;
				if(isChar(x))yellow++;
			}
			i--;continue;
		}
		else if(x == '<' and input[i+1] == 'b')
		{
			while(input[i] != '>')i++;
			colorText.push('b');
			while(input[i] != '<'and input[i+1] != '/' and input[i+1] != 'r' and input[i+1] != 'y' and input[i+1] != 'b')
			{
				x = input[i];i++;
				if(isChar(x))blue++;
			}
			i--;continue;
		}
		else if(x == '<'and input[i+1] == '/')
		{

			if(!colorText.isEmpty()) colorText.pop();
			while(input[i] != '>')i++;
			continue;
		}
		else if(isChar(x) and !colorText.isEmpty())
		{
			switch(colorText.top())
			{
				case 'r':{red++;break;}
				case 'y':{yellow++; break;}
				case 'b':{blue++; break;}
			}
		}

	}
cout<<red<<" "<<yellow<<" "<< blue<<endl;


    return 0;
}
