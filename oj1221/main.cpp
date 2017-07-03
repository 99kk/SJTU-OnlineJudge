#include <iostream>
#include <string>
using namespace std;

//ac

template <class elemType>
class binarySearchTree
{
private:
	struct node
	{
		elemType data;
		node *leftSon;
		node *rightSon;
		node(const elemType&x):data(x),leftSon(NULL),rightSon(NULL){}
		node():leftSon(NULL),rightSon(NULL){}
	};
	node *root;
public:
	binarySearchTree(){root = NULL;}
	bool find(const elemType &x)
	{
		return find(x,root);
	}
private:
	bool find(const elemType &x, node *t)
	{
		if(t == NULL) return false;
		else if(x < t->data) return find(x, t->leftSon);
		else if(x > t->data) return find(x, t->rightSon);
		else return true;
	}
public:
	void insert(const elemType &x)
	{
		insert(x, root);
	}
private:
	void insert(const elemType &x, node*&t)
	{
		if(t == NULL)
			t = new node(x);
		else if(x > t->data)
			insert(x,t->rightSon);
		else if(x <= t->data)
			insert(x, t->leftSon);
	}
public:
	void remove(const elemType &x)
	{
		remove(x, root);
	}
private:
	void remove(const elemType &x, node *&t)
	{
		if(t == NULL) return;
		else if(x < t->data) remove(x, t->leftSon);
		else if(x > t->data) remove(x, t->rightSon);
		else
		{
			if(t->leftSon != NULL and t->rightSon != NULL)
			{
				node *tem = t->rightSon;
				while(tem->leftSon != NULL) tem = tem->leftSon;
				t->data = tem->data;
				remove(t->data, t->rightSon);
			}
			else
			{
				t = (t->leftSon != NULL) ? t->leftSon:t->rightSon;
			}
		}
	}
public:
	void deleteLess_than(const elemType& x)
	{
		deleteLess_than(x, root);
	}
private:
	void deleteLess_than(const elemType &x, node*&t)
	{
		if(t == NULL) return;
		else if(x <= t->data )
		{
			deleteLess_than(x, t->leftSon);
		}
		else if(x > t->data)
		{
			deleteLess_than(x, t->leftSon);
			deleteLess_than(x, t->rightSon);
			remove(t->data, t);
		}
	}
public:
	void deleteGreater_than(const elemType &x)
	{
		deleteGreater_than(x, root);
	}
private:
	void deleteGreater_than(const elemType &x, node *&t)
	{
		if(t == NULL) return;
		else if(x >= t->data)
			deleteGreater_than(x, t->rightSon);
		else
		{
			deleteGreater_than(x,t->leftSon);
			deleteGreater_than(x, t->rightSon);
			remove(t->data, t);
		}
	}
public:
	void deleteInterval(const elemType& a, const elemType &b)
	{
		deleteInterval(a,b,root);
	}
private:
	void deleteInterval(const elemType& a, const elemType &b, node *&t)
	{
		if(t == NULL) return;
		else if(t->data <= a) deleteInterval(a,b,t->rightSon);
		else if(t->data >= b) deleteInterval(a,b, t->leftSon);
		else
		{
			deleteInterval(a,b,t->leftSon);
			deleteInterval(a,b, t->rightSon);
			remove(t->data, t);
		}
	}
public:
	void findIth(int i, elemType &x)
	{
		int num = 0;
		return findIth(i, root, num, x);

	}
private:
	void findIth(int i, node *t, int &num, elemType &x)
	{
		if(num == i) return;
		if(t->leftSon != NULL) findIth(i, t->leftSon, num, x);
		num++; if(num == i) {x = t->data; return;}
		if(t->rightSon !=NULL) findIth(i, t->rightSon, num, x);
	}

public:
	void midOrder()
	{
		if(root == NULL) return;

		if(root->leftSon != NULL) midOrder(root->leftSon);
		cout<<root->data<<" ";
		if(root->rightSon != NULL) midOrder(root->rightSon);
		cout<<endl;
	}
private:
	void midOrder(node *t)
	{
		if(t->leftSon != NULL) midOrder(t->leftSon);
		cout<<t->data<<" ";
        if(t->rightSon != NULL)midOrder(t->rightSon);
	}
};



int main()
{
    int n, i, x, y;
    string order;
    cin>>n;
    binarySearchTree<int> bst;
    for(i = 0; i < n; i++)
	{
		cin>>order>>x;
		if(order == "insert")
		{
			bst.insert(x);
		}
		else if(order == "delete")
		{
			bst.remove(x);
		}
		else if(order == "delete_less_than")
		{
			bst.deleteLess_than(x);
		}
		else if(order == "delete_greater_than")
		{
			bst.deleteGreater_than(x);
		}
		else if(order == "delete_interval")
		{
			cin>>y;
			bst.deleteInterval(x,y);

		}
		else if(order == "find")
		{
			if(bst.find(x)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
		else if(order == "find_ith")
		{
			int ith = -1;
			bst.findIth(x,ith);
			if(ith>= 0) cout<<ith<<endl;
			else cout<<"N"<<endl;
		}

		//bst.midOrder();
	}
    return 0;
}
