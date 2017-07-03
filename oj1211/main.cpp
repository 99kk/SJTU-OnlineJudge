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

	node* create(int rootNum, int *leftChildren, int *rightChildren)
	{
		node *tem = new node(rootNum);
		//cout<<rootNum<<" "<<leftChildren[rootNum]<<" "<<rightChildren[rootNum] <<endl;
		if(leftChildren[rootNum] != 0)
		{
			tem->left =  create(leftChildren[rootNum], leftChildren, rightChildren);;
		}
		if(rightChildren[rootNum]!= 0)
		{

			tem->right = create(rightChildren[rootNum], leftChildren, rightChildren);;
		}

		return tem;
	}

	public:

	void createTree(int rootNum, int *leftChildren, int *rightChildren)
	{
		root = new node(rootNum);

		if(leftChildren[rootNum] != 0)
		{
			node *tem = create(leftChildren[rootNum], leftChildren, rightChildren);
			root->left = tem;
		}
		if(rightChildren[rootNum]!= 0)
		{
			node *tem = create(rightChildren[rootNum], leftChildren, rightChildren);
			root->right = tem;
		}


	}

	bool isCompleteTree()
	{
		if(!root) return true;

		bool leftMost = false;
		linkQueue<node *> que;

		que.enQueue(root);

		while(!que.isEmpty())
		{
			node *cur = que.deQueue();
			if(cur->left)
			{
				if(!leftMost) que.enQueue(cur->left);
				else return false;
			}
			else leftMost = true;

			if(cur->right)
			{
				if(!leftMost) que.enQueue(cur->right);
				else return false;
			}
			else leftMost = true;
		}
		return true;
	}




};



int main()
{
    int n;
    cin>>n;
	binaryTree<int> tree;
	int *leftChildren = new int[n+1], *rightChildren = new int[n+1], *findRoot = new int[n+1];
	for(int i = 1; i <= n; i++) findRoot[i] = 0;
	int root = 0, l, r;
	for(int i = 1; i <= n; i++)
	{
		cin>>l>>r;
		leftChildren[i] = l;
		rightChildren[i] = r;
		findRoot[l] = 1;
		findRoot[r] = 1;

	}


	for(int i = 1; i <= n; i++)
		if(findRoot[i] == 0) {root = i; break;}


	tree.createTree(root, leftChildren, rightChildren);


	if(tree.isCompleteTree()) cout<<"Y";
	else cout<<"N";


    return 0;
}
