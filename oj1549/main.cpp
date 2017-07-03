#include <iostream>

using namespace std;

//AC

class linkstackForparen
{
private:
	struct node
	{
		char data;
		int order;
		node *next;
		node(){  next = NULL; }
		node(char x, int n):data(x),order(n),next(NULL){}
		~node(){}
	};
	node*head;
	node*tail;
public:
	linkstackForparen(){head = tail = new node();}
	 void push(const char x, int n)
	 {
	 	node *tem = new node(x, n);
	 	tem->next = head->next;
	 	head->next = tem;
	 }
	 char pop(int &n)
	 {
	 	node *tem = head->next;
	 	head->next = tem->next;
	 	char x = tem->data;
	 	n = tem->order;
	 	delete tem;
	 	return x;
	 }

	 bool isEmpty(){ return head->next == NULL;}

	 void print()
	 {
	 	node *p = head->next;
	 	while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	 }


};



int main()
{
	char input[102], x, c;
	cin.getline(input, 101);
	int i = 0, remark[101], n = -1;
	linkstackForparen parenMatch;
	for(int j = 0; j < 101; j++) remark[j] = -1;

	while(input[i]!= '\0')
	{
		x = input[i];
		if(x == '(')
		{

			parenMatch.push(x, i);
		}
		if(x == ')')
		{
			if(parenMatch.isEmpty()) {remark[i] = 1;}
			else
			{
				c = parenMatch.pop(n);

			}
		}
		i++;
	}


	while(!parenMatch.isEmpty())
	{

		c = parenMatch.pop(n);
		if(n >= 0)
		{
			remark[n] = 1;
		}
	}
	cout<<input<<endl;

	for(i = 0; input[i] != '\0'; i++)
	{
		if(remark[i] > 0)
		{
			if(input[i] == '(') cout<<"$";
			if(input[i] == ')') cout<<"?";
		}
		else cout<<" ";
	}


    return 0;
}
