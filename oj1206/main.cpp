#include <iostream>


#define elemType char


//AC
using namespace std;



class linkstack
{
private:
	struct node
	{
		elemType data;
		node *next;
		node(const elemType &x, node *p = NULL)
		{
			data = x; next = p;
		}
		node():next(NULL){}
		~node(){}
	};

	node *head;
public:
	linkstack(){head = NULL;}
	~linkstack(){}

	bool isEmpty() const  {return head == NULL;}

	void push(const elemType &x)
	{
		node *tem = new node(x, head);
		head = tem;
	}

	elemType pop()
	{
		if(isEmpty()) return 0;
		node *tem = head;
		elemType x = head->data;
		head = head->next;
		delete tem;
		return x;
	}

	elemType top(){ if(isEmpty())return 0; return head->data;}

	void print()
	{
		node *p = head;;
		while(p != NULL)
		{
			elemType x = p->data;
			cout<<x<< " ";
			p = p->next;
		}
		cout<<endl;
	}
};

bool Compare(char word[], const char *target)
{
	int i = 0, j = 0;
	while(word[i] != '\0' and target[j] != '\0')
		{if(word[i] != target[j]) return false;i++;j++;}
	if(word[i] == '\0' and target[j] == '\0') return true;
	return false;
}


int main()
{
	char word[80];
	char  exam;
	linkstack checkAll,checkBeginEnd, checkIfElse, checkThen;
	const char * begi = "begin", *en = "end", *iff = "if", *elsee = "else", *then = "then";

	while(cin>>word)
	{
		if(Compare(word,begi))
		{
			checkAll.push('{');
			checkBeginEnd.push('{');
		}

		if(Compare(word, en) )
		{
			exam = checkAll.pop();
			while(exam == '<' ) {exam = checkAll.pop();checkIfElse.pop();}
			if(exam != '{') {cout<<"Error!"; return 0;}

			exam = checkBeginEnd.pop();
			if(exam != '{') {cout<<"Error!"; return 0;}
		}

		if(Compare(word, iff) )
		{

			checkAll.push('<');
			checkIfElse.push('<');
			checkThen.push('<');
		}

		if(Compare(word, elsee))
		{
			exam = checkAll.pop();
			if(exam != '<') {cout<<"Error!"; return 0;}
			exam = checkIfElse.pop();
			if(exam != '<') {cout<<"Error!"; return 0;}

		}

		if(Compare(word, then) )
		{
			exam = checkIfElse.top();
			if(exam != '<') {cout<<"Error!"; return 0;}
			exam = checkAll.top();
			if(exam != '<') {cout<<"Error!"; return 0;}
			exam = checkThen.pop();
			if(exam != '<') {cout<<"Error!"; return 0;}

		}
		/*cout<<"check all:" ; checkAll.print();
	cout<<"check beginEnd:"; checkBeginEnd.print();
	cout<<"checkIfElse:"; checkIfElse.print();
	cout<<"checkThen:"; checkThen.print();*/
	}
	/*
	cout<<"check all:" ; checkAll.print();
	cout<<"check beginEnd:"; checkBeginEnd.print();
	cout<<"checkIfElse:"; checkIfElse.print();
	cout<<"checkThen:"; checkThen.print();*/
	if(checkAll.isEmpty() and checkBeginEnd.isEmpty() and checkIfElse.isEmpty() and checkThen.isEmpty() ) cout<<"Match!";
	else cout<<"Error!";
    return 0;
}
