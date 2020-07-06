#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//Onomateponimo : Aristotelis Matakias
//A.M. : P19100
//Data Structures Exercise 2


//struct node of tree
struct Node
{
	int key;		//Number of node
	Node* left;		//Pointer to left child
	Node* right;	//Pointer to right child
	int height;		//Height of node
};

//create global pointer Node for the max Node of the tree
Node* maxNode = NULL;

//returns 'true' if the arguement string is a number
bool isNumber(string s){
	for (int i=0;i<s.length();i++){
		if (isdigit(s[i]) == false)
			return false;
	}
	return true;
}

//reads from the user input an int / keeps asking until the input is int in [1,6]
int getInt(int i)
{
	string s;
	while(true)
	{
		cout << "Choose action:" << endl;
		cin >> s;
		if (isNumber(s) == true){
			i = stoi(s);	//turn string to int
		}
		if(i>0 && i<7)break;
		else cout<<"Non valid number try again!!!"<<endl;
	}
	
	return i;
}

//reads from the user input an int / keeps asking until the input is non-negative int
int getIntGen(int i)
{
	string s;
	while(true)
	{
		cout << "Type new node" << endl;
		cin >> s;
		if (isNumber(s) == true){
			i = stoi(s);	//turn string to int
			break;
		}
	}
	
	return i;
}

//function that shows the menu on the screen
void showMenu()
{
	cout<<"Self balancing tree functions:"<<endl;
	cout<<"1 : show max"<<endl;
	cout<<"2 : insert"<<endl;
	cout<<"3 : delete max"<<endl;
	cout<<"4 : view tree"<<endl;
	cout<<"5 : exit"<<endl;
	cout<<"6 : info"<<endl;
	cout<<"\nType the cooresponding number to choose an action"<<endl;
}

//function that returns the maximum of two ints
int max(int a, int b)
{
	return (a > b)? a : b;
}

//function that returns the height of given node
int getHeight(Node *N)
{
	if (N == NULL)	//if the node is null then the height is 0
		return 0;
	return N->height;
}

//function that returns the balance of given node
int getBalance(Node *N)
{
	if (N == NULL)	//if the node is null then the balance is 0
		return 0;
	return getHeight(N->left) - getHeight(N->right);
}

//function that prints the max Node of the tree
void getMax(){
	
	if(maxNode==NULL)cout<<"Tree is empty so there is no max node"<<endl;
	else cout<<"Max node is: "<<maxNode->key<<endl;
}

//function that finds the max of the tree and stores it to the pointer maxNode
void findNewMax(Node* root)
{
	//start from root
	Node* maxval=root;
	while(root->right!=NULL)
	{
		root = root->right;	//go right
		if(root->key > maxval->key)maxval=root;	//if the node is bigger store it
	}
	//cout<<maxval<<endl;
	maxNode = maxval;
}

//function that creates a new node with given key
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;		//the new node initially has no left child
	node->right = NULL;		//the new node initially has no right child
	node->height = 1;		//the new node initially is added at a leaf
	return(node);
}

//PreOrder traversal 
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key <<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//PostOrder traversal 
void postOrder(Node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->key <<" ";
	}
}

//InOrder traversal 
void inOrder(Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout << root->key <<" ";
		inOrder(root->right);
	}
}

//
///
////
///// rotation functions : /////
////
///
//

//Right rotation
Node* rightRotation(Node* a)
{
	//cout<<"Right rotation"<<endl;
	Node* b = a->left;
	Node* br = b->right;
	
	//perform rotation
	b->right = a;
	a->left = br;
	
	//update heights
	a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
	b->height = max(getHeight(b->left),getHeight(b->right)) + 1;
	
	//return new root
	return b;
}

//Left rotation
Node* leftRotation(Node* a)
{	//cout<<"Left rotation"<<endl;
	//there are 2 cases:
	
	if(a->key < a->right->key)
	{
		//cout<<"case 1"<<endl;
		Node* b = a->right;
		Node* bl = b->left;
		
		//perform rotation
		b->left = a;
		a->right = bl;
		
		//update heights
		a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
		b->height = max(getHeight(b->left),getHeight(b->right)) + 1;
		
		
		//return new root
		return b;
	}
	
	else
	{
		//cout<<"case 2"<<endl;
		Node* b = a->right;
		Node* al = a->left;
		Node* c = b->right;
		
		//perform rotation
		a->right = c;
		a->left = b;
		b->right = al;
		
		//update heights
		b->height = max(getHeight(b->left),getHeight(b->right)) + 1;
		a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
		
		//return new root
		return a;
	}
}

//Rotation for Left Right Case:
Node* leftRightCase(Node* z)
{
	//cout<<"Rotation for Left Right Case"<<endl;
	//find y and x
	Node* y = z->left;
	Node* x = y->right;
	
	if(x->key > y->key)
	{
		//cout<<"case 1"<<endl;
		
		//perform rotation
		//take children of x
		Node* xr = x->right;
		Node* xl = x->left;
		
		x->right = z;
		x->left = y;
		
		z->left = xr;
		y->right = xl;
		
		//update heights
		y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
		z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
		x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
		//return new root
		return x;
	}
	else
	{
		//cout<<"case 2"<<endl;
		
		Node* xr = x->right;
		Node* yl = y->left;
		
		//perform rotation
		y->right = z;
		y->left = x;
		z->left = xr;
		x->right = yl;
		
		//update heights
		x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
		z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
		y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
		//return new root
		return y;
	}
}

//Rotation for Right Left Case:
Node* rightLeftCase(Node* z)
{
	//cout<<"Rotation for Right Left Case"<<endl;
	//find y and x
	Node* y = z->right;
	Node* x = y->left;
	
	Node* yl = y->right;
	
	//perform rotation
	y->right = z;
	//y->left = x;
	z->right = yl;
	
	//update heights	
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;	
	//return new root
	return y;
}

//function that checks if a rotation is needed
//if so it checks the case and calls the appropriate rotation function
Node* rotate(Node* node)
{
	int balance = getBalance(node);//get balance of current node
	if (balance > 1 || balance < -1)
	{
		//cout<<"Node is unbalanced"<<endl;

		//nodes that will rotate:
		Node* z = node;	//current node
		Node* y = NULL;	//child node
		Node* x = NULL;	//grand child node
		
		//find y and x:
		if(balance > 1)
		{
			y = z->left;
			if(getBalance(y)>1)x = y->left;
			else x = y->right;
		}
		else
		{
			y = z->right;
			if(getBalance(y)>1)x = y->left;
			else x = y->right;
		}
		
		//cout<<"z is "<<z->key<<endl;
		//cout<<"y is "<<y->key<<endl;
		//cout<<"x is "<<x->key<<endl;
		
		//now we need to find which case of inbalance we have
		
		//Left Left Case
		if(z->left==y && y->left==x)
		{
			//cout<<"Left Left Case"<<endl;
			return rightRotation(z);
		}
		//Left Right Case
		else if(z->left==y && y->right==x)
		{
			//cout<<"Left Right Case"<<endl;
			return leftRightCase(z);
		}
		//Right Right Case
		else if(z->right==y && y->right==x)
		{
			//cout<<"Right Right Case"<<endl;
			return leftRotation(z);
		}
		//Right Left Case
		else if(z->right==y && y->left==x)
		{
			//cout<<"Right Left Case"<<endl;
			return rightLeftCase(z);
		}

	}
	
	//else cout<<"Node is balanced"<<endl;
	return node;
}



//insert function
Node* insert(Node* node,int key)
{
	//if node is empty insert
	if (node == NULL)
	{  
		//check if the inserted node is the new max node before inserting
		Node* dummyNode = newNode(key);
		if(maxNode == NULL  )maxNode=dummyNode;
		else if(maxNode->key < dummyNode->key)maxNode=dummyNode;
		return(dummyNode);  
	}
	
	//if the key is smaller than the current root it goes to the subtree with the lowest height
	//if heights are equal it goes to the right
	if (key < node->key)
	{
		if(getHeight(node->left) < getHeight(node->right))node->left = insert(node->left, key);
		else node->right = insert(node->right, key);
	}

	//if the key is bigger than the current root it goes right
	else if (key > node->key)  
		node->right = insert(node->right, key);  

	//update height of this ancestor node
	node->height = 1 + max(getHeight(node->left),getHeight(node->right));
	

	node = rotate(node);
	
	return node;
}

//
////DELETE MAX section
//


//InOrder traversal which inserts every key to given tree 
//Parameters:
//root: root of tree where the nodes will be inserted
//child: root of tree whose nodes will be inserted to the above mentionted tree
void inOrderInsert(Node* root ,Node* child)
{
	if(child != NULL)
	{
		inOrderInsert(root,child->left);
		root = insert(root,child->key);
		inOrderInsert(root,child->right);
	}
}

//function that deletes max
Node* delMax(Node* root)
{
	//case 1:
	//if max is the root of the tree
	if(maxNode == root)
	{
		//root has no children
		if(maxNode->right==NULL && maxNode->left==NULL)
		{
			root = NULL;
			maxNode = NULL;
			return root;
		}
		
		//root has only right child
		else if(maxNode->right!=NULL && maxNode->left==NULL)
		{
			root = root->right;
			maxNode = root;
			return root;
		}
		
		//root has only left child
		else if(maxNode->right==NULL && maxNode->left!=NULL)
		{
			root = root->left;
			maxNode = root;
			return root;
		}
		
		//root has two children
		else
		{
			Node* leftChild = root->left;
			root = root->right;
			while(true){
			int balance = getBalance(root);//get balance of current node
			if (balance > 1 || balance < -1)root = rotate(root);
			else break;
			}
			inOrderInsert(root,leftChild);
			maxNode = NULL;
			findNewMax(root);
			return root;
		}
	}

	//case 2:
	//if max is not root of the tree
	else
	{
		//remove and store the children of the maxNode
		Node* tempRight = maxNode->right;
		Node* tempLeft = maxNode->left;
		
		Node* parent =NULL;
		parent = root;
		while(parent->right!=NULL)
		{
			if(parent->right->key == maxNode->key)break;
			parent=parent->right;
		}
		//cout<<"the parent is "<<parent->key<<endl;

		//delete maxNode
		maxNode = NULL;
		//put the right child of the maxNode that was saved under the parent as a right child
		parent ->right = tempRight;
		//fix height of parent
		parent->height = max(getHeight(parent->left),getHeight(parent->right));
		
		//fix height of the affected nodes above the parent
		Node* pntr=root;
			while(true)
			{
				if(pntr == parent)break;
				pntr->height = max(getHeight(pntr->left),getHeight(pntr->right)-1);
				//pntr->height = depth(pntr);
				pntr=pntr->right;
			}
		
		////fix height of root
		//root->height = max(getHeight(root->left),getHeight(root->right));
		
		//check root for rotations // repeat untill it is balanced
		while(true){
			int balance = getBalance(root);//get balance of current node
			if (balance > 1 || balance < -1)root = rotate(root);
			else break;
		}
		
		//find the new max
		findNewMax(root);
		//insert the nodes of the removed subtree
		inOrderInsert(root,tempLeft);
		return root;
	}
	

}

//
////--
//


int main()
{
	Node* root = NULL;
	cout<<"A tree has been created and its ready for use"<<endl;
		
	
	cout<<"A sample tree has been loaded."<<endl;
	root = insert(root,75);
	root = insert(root,60);
	root = insert(root,70);
	root = insert(root,55);
	root = insert(root,48);
	root = insert(root,34);
	root = insert(root,31);
	root = insert(root,20);
	root = insert(root,18);
	root = insert(root,15);
	root = insert(root,14);
	root = insert(root,13);
	root = insert(root,9);
	root = insert(root,8);
	

	
	showMenu();
	while(true)
	{
		int i = getInt(i);
		if(i==1)
		{
			getMax();
			continue;
		}
		else if(i==2)
		{
			cout<<"Give number for tree insertion"<<endl;
			int j = getIntGen(j);
			root = insert(root,j);
			continue;
		}
		else if(i==3)
		{
			if(root==NULL)
			{
				cout<<"The tree is empty Cannot delete anything!"<<endl;
				continue;
			}
			cout<<"Node "<<maxNode->key<<" will be deleted."<<endl;
			root = delMax(root);
			if(root==NULL)
			{
				cout<<"The tree is empty now!"<<endl;
				continue;
			}
			cout<<"New max is : "<<maxNode->key<<endl;
			continue;
		}
		else if(i==4)
		{
			if(root==NULL)
			{
				cout<<"The tree is empty !"<<endl;
				continue;
			}
			cout<<"preOrder traversal is ";
			preOrder(root);
			cout<<endl;
			cout<<"inOrder traversal is ";
			inOrder(root);
			cout<<endl;
			cout<<"postOrder traversal is ";
			postOrder(root);
			cout<<endl;
			continue;
		}
		else if(i==6)
		{
			cout<<"Tree property : The key of each node must be bigger than all the keys of the left subtee"<<endl;
			cout<<"while there is no rule for the right subtee."<<endl;
			cout<<"Name : Aristotelis Matakias \nA.M. : P19100"<<endl;
			
		}
		else 
		{
			cout<<"Au revoir..."<<endl;
			break;
			}
	}
	return 0;
}