#include <iostream>

using namespace std;

//AC

class phoneBook
{
private:
		struct node
	{
		int phoneNum;
		int num;
		node *next;
		node(const int phone){phoneNum = phone; num = 1; next = NULL;}
		node():num(0),next(NULL){}
		~node(){}
	};
	node *head;
	node *tail;
	node *find(const int phoneNum)
	{
		node *p = head->next;
		while(p != NULL)
		{
			if(p->phoneNum == phoneNum) return p;
			p = p->next;
		}
		return p;
	}
public:
	phoneBook(){head = new node();tail = head;}

	void insert(const int phoneNum)
	{

			node *tem = new node(phoneNum);
			tail->next = tem;
			tail = tem;

	}

	node *slice(node *low, node *high)
	{


		int key = low->phoneNum;
		node *p = low, *q = low->next;

		while(q != high)
		{
			if(q->phoneNum < key)
			{
				p = p->next;
				int temPhone = p->phoneNum, temNum = p->num;
				p->phoneNum = q->phoneNum; p->num = q->num;
				q->phoneNum = temPhone; q->num = temNum;
			}
			q = q->next;
		}

		if(q->phoneNum < key)
			{
				p = p->next;
				int temPhone = p->phoneNum, temNum = p->num;
				p->phoneNum = q->phoneNum; p->num = q->num;
				q->phoneNum = temPhone; q->num = temNum;
			}


			int temPhone = p->phoneNum, temNum = p->num;
			p->phoneNum = low->phoneNum; p->num = low->num;
			low->phoneNum = temPhone; low->num = temNum;


		return p;
	}

	void quiksort(node *low, node *high)
	{

		if(low != high and low != NULL and high != NULL)
		{

			node *partion = slice(low, high);
			quiksort(low, partion);
			quiksort(partion->next, high);
		}
	}


	void print()
	{
		quiksort(head->next, tail);

		bool Nodupulicate = true;
		node *p = head->next;
		int prevPhone = p->phoneNum, times = 1;
		p = p->next;
		while(p != NULL)
		{
			if(prevPhone == p->phoneNum) times++;
			else
			{
				if(times >=2)
				{
					int pre = prevPhone/10000, re = prevPhone - prevPhone/10000 * 10000;
					int preZero = 0, reZero = 0;
					if(pre<100){preZero++;if(pre<10){preZero++; if(pre == 0) preZero++; } }
					if(re<1000){reZero++;if(re<100){reZero++;if(re<10){reZero++;if(re==0){reZero++; } } } }
					for(int i = 0; i < preZero; i++)cout<<"0";
					cout<<pre<<"-";
					for(int i = 0; i < reZero; i++)cout<<"0";
					cout<<re<<" "<<times<<endl; Nodupulicate = false;
				}
				prevPhone = p->phoneNum;
				times = 1;
			}

			p = p->next;
		}
		if(times >=2)
				{
					int pre = prevPhone/10000, re = prevPhone - prevPhone/10000 * 10000;
					int preZero = 0, reZero = 0;
					if(pre<100){preZero++;if(pre<10){preZero++; if(pre == 0) preZero++; } }
					if(re<1000){reZero++;if(re<100){reZero++;if(re<10){reZero++;if(re==0){reZero++; } } } }
					for(int i = 0; i < preZero; i++)cout<<"0";
					cout<<pre<<"-";
					for(int i = 0; i < reZero; i++)cout<<"0";
					cout<<re<<" "<<times<<endl; Nodupulicate = false;
				}



		if(Nodupulicate) cout<<"No duplicates.";
	}
};




int main()
{
	int n, k = 0, phone,i;
	phoneBook book;

	cin>>n;
	char phoneNumber[20];
	for(i = 0; i < n; i++)
	{
		k = 0; phone = 0;
		cin>>phoneNumber;
		do
		{
			switch(phoneNumber[k])
			{
				case 'A': {phone = phone * 10 + 2;break;}
				case 'B': {phone = phone * 10 + 2;break;}
				case 'C': {phone = phone * 10 + 2;break;}
				case 'D': {phone = phone * 10 + 3;break;}
				case 'E': {phone = phone * 10 + 3;break;}
				case 'F': {phone = phone * 10 + 3;break;}
				case 'G': {phone = phone * 10 + 4;break;}
				case 'H': {phone = phone * 10 + 4;break;}
				case 'I': {phone = phone * 10 + 4;break;}
				case 'J': {phone = phone * 10 + 5;break;}
				case 'K': {phone = phone * 10 + 5;break;}
				case 'L': {phone = phone * 10 + 5;break;}
				case 'M': {phone = phone * 10 + 6;break;}
				case 'N': {phone = phone * 10 + 6;break;}
				case 'O': {phone = phone * 10 + 6;break;}
				case 'P': {phone = phone * 10 + 7;break;}
				case 'R': {phone = phone * 10 + 7;break;}
				case 'S': {phone = phone * 10 + 7;break;}
				case 'T': {phone = phone * 10 + 8;break;}
				case 'U': {phone = phone * 10 + 8;break;}
				case 'V': {phone = phone * 10 + 8;break;}
				case 'W': {phone = phone * 10 + 9;break;}
				case 'X': {phone = phone * 10 + 9;break;}
				case 'Y': {phone = phone * 10 + 9;break;}
				case '-': {break;}
				default : {phone = phone * 10 + phoneNumber[k] - '0';}
			}
			k++;
		}while(phoneNumber[k] != '\0');

		book.insert(phone);


	}

	book.print();

    return 0;
}
