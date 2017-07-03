#include <iostream>
#include <stdio.h>
#include<string>
using namespace std;

// ac

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
	bool lookPath(const elemType &x, string &s)
	{
		s.append("*");
		return lookPath(x, root, s);

	}

private:
	bool lookPath(const elemType &x, node *t, string &s)
	{
		if(t == NULL) return false;
		else if(x < t->data) { s.append("l"); return lookPath(x, t->leftSon, s);}
		else if(x > t->data) { s.append("r"); return lookPath(x, t->rightSon, s);}
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
		else if(x < t->data)
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
		else if(x < t->data) {  remove(x, t->leftSon); }
		else if(x > t->data) {  remove(x, t->rightSon);}
		else
		{
			if(t->rightSon == NULL) t = t->leftSon;
			else
			{
				node *tem = t->rightSon;
				while(tem->leftSon != NULL) tem = tem->leftSon;
				t->data = tem->data;
				replaceWithRightSon(t->data, t->rightSon);
			}
		}
	}

	void replaceWithRightSon(const elemType &x, node *&t)
	{
		if(x < t->data)
			replaceWithRightSon(x, t->leftSon);
		else
			t= t->rightSon;
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
    int q, i, x;
    scanf("%d", &q);
    char op;
    binarySearchTree<int> bst;

    for(i = 0; i < q; i++)
	{
		scanf("%*c");
		scanf("%c%d", &op, &x);

		switch(op)
		{
		case '+':
			bst.insert(x);break;
		case '-':
			bst.remove(x); break;
		case '*':
			string s;
			if(bst.lookPath(x, s)) { printf("%s\n", &s[0]);   }
			else printf("Nothing.\n");
		}
		//bst.midOrder();
	}

    return 0;
}
