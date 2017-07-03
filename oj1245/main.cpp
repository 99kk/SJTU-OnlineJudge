#include <iostream>

using namespace std;

//AC

template <class elemType>
class linkStack
{
private:
	struct node
	{
		elemType data;
		node *next;
		node(const elemType &x, node* N = NULL)
		{
			data = x; next = N;
		}
		node():next(NULL){}
		~node(){}
	};
	node *element;

public:
	linkStack(){element = NULL;}
	~linkStack()
	{
		node *tem;
		while(element != NULL)
		{
			tem = element;
			element = element->next;
			delete tem;
		}
	}

	bool isEmpty() {return element == NULL;}
	void push(const elemType &x) {node *tem = new node(x, element); element = tem;}
	elemType pop()
	{
		node *tem = element;
		elemType x = element->data;
		element  = element->next;
		delete tem;
		return x;
	}

	elemType top() const {return element->data;}

	void print()
	{
		node *p = element;
		while(p->next != NULL)
			{
				if(p->data >= 0)
					cout<<p->data<<" ";
				else
					switch(p->data)
					{
						case -3:{cout<<"+ ";break;}
						case -4:{cout<<"- ";break;}
						case -5:{cout<<"* ";break;}
						case -6:{cout<<"/ ";break;}
					}
				p = p->next;
			}

		cout<<p->data<<endl;
	}
};



int cal(linkStack<int> &prefix)
{
	if(prefix.isEmpty()) return -7;
	int op = prefix.pop();
	if(op >= 0) return  op;
	else
		switch(op)
	{
		case -3:{return cal(prefix) + cal(prefix);break;}
		case -4:{return cal(prefix) - cal(prefix);break;}
		case -5:{return cal(prefix) * cal(prefix);break;}
		case -6:{return cal(prefix) / cal(prefix);break;}
	}
}

int main()
{
	linkStack<int> input, oprators, prefix;
	char x;
	char str[1001];
	int num, op, i = 0;
	cin.getline(str,1000);
	while(str[i] != '\0')
	{
		x = str[i];i++;
        if(x >= '0' and x <= '9')
		{
			num = x - '0';
			while(true)
			{
				x = str[i];i++;
				if(x == ')'){ input.push(num); input.push(-2); break;}
				if(x >= '0' and x <= '9')
					num = num * 10 + x - '0';
				else
					{input.push(num); i--;break;}
			}
		}
		else
			switch(x)
			{
				case '(':{input.push(-1);break;}
				case ')':{input.push(-2);break;}
				case '+':{input.push(-3);break;}
				case '-':{input.push(-4);break;}
				case '*':{input.push(-5);break;}
				case '/':{input.push(-6);break;}
			}
	}

	while(!input.isEmpty())
	{
		op = input.pop();
		if(op >= 0) prefix.push(op);
		else
		{
			switch(op)
			{
				case -1: {while(!oprators.isEmpty())
							{
								int tem = oprators.pop();
								if(tem == -2) break;
								prefix.push(tem);
							}
							break;}
				case -2: {oprators.push(-2);break;}

				case -3:{while(!oprators.isEmpty() and oprators.top() <= -5) prefix.push(oprators.pop());
						oprators.push(-3);break;}

				case -4:{while(!oprators.isEmpty() and oprators.top() <= -5) prefix.push(oprators.pop());
						oprators.push(-4);break;}

				case -5:{oprators.push(-5);break;}

				case -6:{oprators.push(-6);break;}

			}
		}
	}

	while(!oprators.isEmpty()) prefix.push(oprators.pop());

	prefix.print();

	cout<<cal(prefix);
    return 0;
}
