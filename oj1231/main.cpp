#include <iostream>

using namespace std;

//lca

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
};



int main()
{
	int n, x, y, i, a, b, *father;
	cin>>n>>x>>y;

	father = new int[n+1];

	for(i = 1 ; i <= n; i++)
	{
		cin>>a>>b;
		father[a]  = i; father[b] = i;
	}

	binarySearchTree<int> bst;

	bst.insert(x);
	while(x != 1)
	{
		x = father[x];
		bst.insert(x);
	}


	while(y != 1)
	{
		if(bst.find(y))
		{
			cout<<y<<endl;
			return 0;
		}
		y = father[y];

	}
	if(bst.find(y))
		{
			cout<<y<<endl;
			return 0;
		}



    return 0;
}
