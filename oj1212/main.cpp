#include <iostream>

using namespace std;

//AC


template<class elemType>
class linkQueue
{
private:
	struct node
	{
		elemType data;
		node* next;
		node(const elemType &x, node*p = NULL) {data = x; next = p;}
		node():next(NULL){}
		~node(){}
	};
	node *head;
	node *tail;

public:
	linkQueue(){head = tail = NULL;}

	bool isEmpty(){return head == NULL;}

	void enQueue(const elemType &x)
	{
		if(tail == NULL) head = tail = new node(x);
		else
		{
			node *p = new node(x);
			tail->next = p;
			tail = tail->next;
		}
	}

	elemType deQueue()
	{
		node *tem = head;
		elemType x = head->data;
		head = head->next;
		if(head == NULL) tail = NULL;
		delete tem;
		return x;
	}

	elemType getHead(){return head->data;}

	void print()
	{
		node*p=head;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};

template<class elemType>
class binaryTree
{
private:
	struct node
	{
		elemType data;
		node *left;
		node *right;
		node():left(NULL),right(NULL){}
		node(elemType d, node *l = NULL, node *r = NULL){data = d; left = l; right = r;}
		~node(){}
	};
	node* root;

public:
	binaryTree():root(NULL){}
	binaryTree(const elemType value){root = new node(value);}
	binaryTree(const node* p){root = p;}
	~binaryTree(){clear();}

	elemType getRoot(){return root->data;}
	elemType getLeft(){return root->left->data;}
	elemType getRight(){return root->right->data;}

	void makeTree(const elemType &x, binaryTree &l, binaryTree &r)
	{
		root = new node(x, l.root, r.root);
		l.root = NULL;
		r.root = NULL;
	}

	void deleteLeft()
	{
		binaryTree tem = root->left;
		root->left = NULL;
		tem.clear();
	}
	void deleteRight()
	{
		binaryTree tem = root->right;
		root->right = NULL;
		tem.clear();
	}

	bool isEmpty()const{return root == NULL;}

	void clear() {if(root!=NULL) clear(root); root = NULL; }

	int size() const {return size(root);}

	int hight() const { return hight(root); }

	void preOrder() const
	{
		if(root != NULL) preOrder(root);
	}

	void postOrder() const { if(root!= NULL) postOrder(root); }

	void midOrder() const { if(root != NULL) midOrder(root); }

private:
	int hight(node *t) const
	{
		if(root == NULL) return 0;
		else
		{
			int lt = hight(t->left), rt = hight(t->right);
			return 1 + ((lt>rt)?lt:rt);
		}
	}

	void clear(node * t)
	{
		if(t->left != NULL) clear(t->left);
		if(t->right != NULL) clear(t->right);
		delete t;
	}

	int size(node *t) const
	{
		if(t == NULL) return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(node *t) const
	{
		if(t!= NULL)
		{
			cout<<t->data<<" ";
			preOrder(t->left); preOrder(t->right);
		}
	}

	void postOrder(node *t)const
	{
		if(t != NULL)
		{
			postOrder(t->left);postOrder(t->right);
			cout<<t->data<<" ";

		}
	}

	void midOrder(node *t)const
	{
		if(t!= NULL)
		{
			midOrder(t->left);
			cout<<t->data<<" ";
			midOrder(t->right);
		}
	}

	node* create(int rootNum, int *leftChildren, int *rightChildren, int *value)
	{
		node *tem = new node(value[rootNum]);
		//cout<<rootNum<<" "<<leftChildren[rootNum]<<" "<<rightChildren[rootNum] <<endl;
		if(leftChildren[rootNum] != 0)
		{
			tem->left =  create(leftChildren[rootNum], leftChildren, rightChildren, value);
		}
		if(rightChildren[rootNum]!= 0)
		{

			tem->right = create(rightChildren[rootNum], leftChildren, rightChildren, value);
		}

		return tem;
	}

	public:

	void createTree(int rootNum, int *leftChildren, int *rightChildren, int *value)
	{
		root = new node(value[rootNum]);

		if(leftChildren[rootNum] != 0)
		{
			node *tem = create(leftChildren[rootNum], leftChildren, rightChildren, value);
			root->left = tem;
		}
		if(rightChildren[rootNum]!= 0)
		{
			node *tem = create(rightChildren[rootNum], leftChildren, rightChildren, value);
			root->right = tem;
		}


	}

	void print()
	{
		linkQueue<node*> que;
		que.enQueue(root);
		while(!que.isEmpty())
		{
			node *tem = que.deQueue();
			if(tem->left != NULL) que.enQueue(tem->left);
			if(tem->right != NULL) que.enQueue(tem->right);
			cout<<tem->data<<" ";
		}
	}



};




int main()
{
    int n;
    cin>>n;

    int *lchildren = new int[n+1], *rchildren = new int[n+1], *value = new int[n+1], *findRoot = new int[n+1];
    int l, r, v, rootNum = 0;
     for(int i = 1; i <= n; i++) findRoot[i] = 0;
    for(int i = 1; i <= n; i++)
	{
		cin>>l>>r>>v;
		lchildren[i] = l; rchildren[i] = r; value[i] = v;
		findRoot[l] = 1; findRoot[r] = 1;
	}

    for(int i = 1; i <= n; i++)
		if(findRoot[i] == 0) {rootNum = i;break;}


	binaryTree<int> tree;
	tree.createTree(rootNum, lchildren, rchildren, value);
	tree.print();


    return 0;
}
