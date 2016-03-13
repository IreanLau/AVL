#include<iostream>
using namespace std;

template<class T>
class AVL;
template<class T>
class TreeNode
{
	friend class AVL<T>;
public:
	TreeNode()
		:data(0), freq(1), hight(1),lson(NULL), rson(NULL) {}
	TreeNode(T x)
		:data(x), freq(1), hight(1),lson(NULL), rson(NULL) {}
	T data;
	unsigned int freq;
	int hight;
	TreeNode* lson;
	TreeNode* rson;
};


template<class T>
class AVL
{
public:
	AVL() :root(NULL)
	{}
	void insert(T x)
	{
		insertpri(root, x);
	}
	TreeNode<T>* find(T x)
	{
		return findpri(root, x);
	}
	void Delete(T x)
	{
		Deletepri(root, x);
	}
	void traversal()
	{
		inorder(root);
		cout << endl;
	}
private:
	void insertpri(TreeNode<T>*&root, T x);
	TreeNode<T>* findpri(TreeNode<T>*&root, T x);
	void Deletepri(TreeNode<T>*&root, T x);
	void inorder(TreeNode<T>*&root);
	int height(TreeNode<T>*&root)
	{
		if (NULL != root)
			return root->hight;

		return -1;
	}

	//single change
	void LL(TreeNode<T>*&pNode);//
	void RR(TreeNode<T>*&pNode);

	//two change
	void LR(TreeNode<T>*&pNode);
	void RL(TreeNode<T>*&pNode);

	int Max(int cmpa, int cmpb)
	{
		return cmpa >= cmpb ? cmpa : cmpb;
	}
private:
	TreeNode<T>* root;
};

//single change
template<class T>
void AVL<T>::LL(TreeNode<T>*&pNode)
{
	TreeNode<T>* tmp;
	tmp = pNode->lson;
	pNode->lson = tmp->rson;
	tmp->rson = pNode;
	
	pNode->hight = Max(height(pNode->lson), height(pNode->rson)) + 1;
	tmp->hight = Max(height(tmp->lson), height(tmp->rson)) + 1;

	pNode = tmp;
}

template<class T>
void AVL<T>::RR(TreeNode<T>*&pNode)
{
	TreeNode<T>* tmp;
	tmp = pNode->rson;
	pNode->rson = tmp->lson;
	tmp->lson = pNode;

	pNode->hight = Max(height(pNode->lson), height(pNode->rson)) + 1;
	tmp->hight = Max(height(tmp->lson), height(tmp->rson)) + 1;

	pNode = tmp;
}

//two change
template<class T>
void AVL<T>::LR(TreeNode<T>*&pNode)
{
	RR(pNode->lson);
	LL(pNode);
}

template<class T>
void AVL<T>::RL(TreeNode<T>*&pNode)
{
	LL(pNode->rson);
	RR(pNode);
}

template<class T>
TreeNode<T>* AVL<T>::findpri(TreeNode<T>*&root, T x)
{
	if (root == NULL)
	{
		cout << "not found" << endl;
		exit(1);
	}

	if (x < root->data)
		return findpri(root->lson, x);
	else if (x>root->data)
		return findpri(root->rson, x);
	else
		return root;
}

template<class T>
void AVL<T>::inorder(TreeNode<T>*&root)
{
	if (root == NULL)
		return;
	inorder(root->lson);
	cout << root->data << " ";
	inorder(root->rson);
}

template<class T>
void AVL<T>::insertpri(TreeNode<T>*&root, T x)
{
	if (NULL == root)
	{
		root = new TreeNode<T>(x);
		return;
	}

	if (x < root->data)
	{
		insertpri(root->lson, x);

		if ( 
			(root->lson &&root->rson) && 
			(height(root->lson) - height(root->rson) == 2)
				)
		{
			if (x < root->lson->data)
				LL(root);
			else
				LR(root);
		}
	}

	else if (x>root->data)
	{
		insertpri(root->rson, x);
		if (
			(root->lson &&root->rson) && 
			(height(root->rson) - height(root->lson) == 2)
				)
		{
			if (x > root->rson->data)
				RR(root);
			else
				RL(root);
		}
	}
	else ++(root->freq);

	root->hight = Max(height(root->lson), height(root->rson))+1;
}

template<class T>
void AVL<T>::Deletepri(TreeNode<T>*&root, T x)
{
	/*if (NULL == root)
	{
		cout << "Node is NULL,can not delete" << endl;
		exit(1);
	}

	if (x < root->data)
	{
		Deletepri(root->lson);
		if (
			(root->lson &&root->rson) &&
			(height(root->rson) - height(root->lson) == 2)
			)
		{
			if()
		}
	}
	else if (x>root->rson)
		Deletepri(root->rson);
	else
	{
		if (--(root->freq) == 0)
		{

		}
	}*/
}

void test()
{
	class AVL<int> bstint;
	bstint.insert(6);
	bstint.insert(3);
	bstint.insert(7);
	bstint.insert(1);
	bstint.insert(4);
	bstint.insert(2);
	bstint.insert(3);

	bstint.traversal();
	//bstint.Delete(4);
	bstint.traversal();
}


void main()
{
	test();
}