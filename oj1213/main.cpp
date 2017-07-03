#include <iostream>

using namespace std;

//AC

class binaryTree
{
private:
	struct node
	{
		int data;
		node *leftChild;
		node *rightChild;
		node(int x):data(x),leftChild(NULL),rightChild(NULL){}
	};
	node *root;

	node* creat(int rootNum, int *leftChildren, int *rightChildren, int *value)
	{
		node *tem = new node(value[rootNum]);
		if(leftChildren[rootNum] != 0)
			tem->leftChild = creat(leftChildren[rootNum], leftChildren, rightChildren, value);
		if(rightChildren[rootNum]!= 0)
			tem->rightChild = creat(rightChildren[rootNum], leftChildren, rightChildren, value);
		return tem;
	}

public:

	binaryTree(){root = NULL;}
	void creatTree(int rootNum, int *leftChildren, int *rightChildren, int *value)
	{
		root = new node(value[rootNum]);
		if(leftChildren[rootNum] != 0)
			root->leftChild = creat(leftChildren[rootNum], leftChildren, rightChildren, value);
		if(rightChildren[rootNum]!= 0)
			root->rightChild = creat(rightChildren[rootNum], leftChildren, rightChildren, value);
	}

	friend bool same(binaryTree &t1, binaryTree &t2);

	bool sameRoot(node *r1, node *r2)
	{
		bool f1 = false,f2 = false;
		if(r1->leftChild != NULL  and r2->leftChild != NULL)
			f1 = sameRoot(r1->leftChild, r2->leftChild);
		if(r1->rightChild != NULL  and r2->rightChild != NULL)
			f2 = sameRoot(r1->rightChild, r2->rightChild);

		if(r1->leftChild == NULL  and r2->leftChild == NULL) f1 = true;
		if(r1->rightChild == NULL  and r2->rightChild == NULL) f2 = true;

		return f1 and f2 and r1->data == r2->data;
	}


};


bool same(binaryTree &t1, binaryTree &t2)
{
	return t1.sameRoot(t1.root, t2.root) and t1.root->data == t2.root->data;
}


int main()
{
    int n,p,q,v,m, rootN;
    cin>>n;
    int *leftChildren = new int[n+1], *rightChildren = new int[n+1], *value = new int[n+1], *findRoot = new int[n+1];

    for(int i = 1; i <= n; i++) findRoot[i] = 0;

	for(int i = 1; i <= n; i++)
	{
		cin>>p>>q>>v;
		leftChildren[i] = p;
		rightChildren[i] = q;
		value[i] = v;
		findRoot[p] = 1; findRoot[q] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(findRoot[i] == 0) rootN = i;

	binaryTree tree1, tree2;

	tree1.creatTree(rootN, leftChildren, rightChildren, value);

	cin>>m;
	int *leftChildren2 = new int[m+1], *rightChildren2 = new int[m+1], *value2 = new int[m+1], *findRoot2 = new int[m+1];
    int rootN2;
    for(int i = 1; i <= m; i++) findRoot2[i] = 0;

	for(int i = 1; i <= m; i++)
	{
		cin>>p>>q>>v;
		leftChildren2[i] = p;
		rightChildren2[i] = q;
		value2[i] = v;
		findRoot2[p] = 1; findRoot2[q] = 1;
	}
	for(int i = 1; i <= m; i++)
		if(findRoot2[i] == 0) rootN2 = i;

	tree2.creatTree(rootN2, leftChildren2, rightChildren2, value2);


	if(same(tree1, tree2)) cout<<"Y"<<endl;
	else cout<<"N"<<endl;



    return 0;
}
