#include <iostream>
#include <string>
#include <math.h>
using namespace std;



//returns 'true' if the arguement string is a number
bool isNumber(string s){
	for (int i=0;i<s.length();i++){
		if (isdigit(s[i]) == false)
			return false;
	}
	return true;
}

//reads from the user input an int / keeps asking until the input is int is in [1,5]
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
		if(i>0 && i<6)break;
		else cout<<"Non valid number try again!!!"<<endl;
		
	}
	
	return i;
}


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


void showMenu()
{
	cout<<"Self balancing tree functions:"<<endl;
	cout<<"1 : show max"<<endl;
	cout<<"2 : insert"<<endl;
	cout<<"3 : delete max"<<endl;
	cout<<"4 : view tree"<<endl;
	cout<<"5 : exit"<<endl;
	cout<<"\ntype the cooresponding number to choose an action"<<endl;
}


//struct node of tree
struct Node   
{
	int key; 
	Node *left;  
	Node *right;
	int height;
};  

//function that returns the maximum of two ints  
int max(int a, int b)  
{  
	return (a > b)? a : b;  
}

//function that returns the height of given node
int getHeight(Node *N)  
{  
	if (N == NULL)  //if the node is null then the height is 0
		return 0;  
	return N->height;  
}  

//function that returns the balance of given node
int getBalance(Node *N)  
{  
	if (N == NULL)  //if the node is null then the balance is 0
		return 0;  
	return getHeight(N->left) - getHeight(N->right);  
}  

Node* maxNode = NULL;
void getMax(){
	
	if(maxNode==NULL)cout<<"Tree is empty so there is no max node"<<endl;
	else cout<<"Max node is: "<<maxNode->key<<endl;
	}
void findNewMax(Node* root)
{
	Node* maxval=root;
	while(root->right!=NULL)
	{
		root = root->right;
		if(root->key > maxval->key)maxval=root;
	}
	//cout<<maxval<<endl;
	maxNode = maxval;
}


//function that creates a new node with given key
Node* newNode(int key)  
{  
	Node* node = new Node(); 
	node->key = key;  
	node->left = NULL;  	//the new node initially has no left child
	node->right = NULL;  	//the new node initially has no right child
	node->height = 1; 		//the new node initially is added at a leaf                     
	return(node);  
}  

//PreOrder traversal 
void preOrder(Node *root)  
{  
	if(root != NULL)  
	{  
		cout << root->key << " ";  
		preOrder(root->left);  
		preOrder(root->right);  
	}  
} 

//PostOrder traversal 
void postOrder(Node *root)
{
	if(root != NULL)  
	{          
		preOrder(root->left);  
		preOrder(root->right);  
		cout << root->key << " ";  
	}  
}

//InOrder traversal 
void inOrder(Node *root)
{
	if(root != NULL)  
	{ 
		inOrder(root->left);
		cout << root->key << " ";  
		inOrder(root->right);  
	} 
}

//function INSERT
void insert2(Node* root, int key) 
{
	Node* curr = root;			//
	Node* ins = newNode(key);	//
	while(true)
	{
		if(key > curr->key)
		{
			if (curr->right==NULL)
			{
				curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
				curr->right = ins;
				return;
			}
			else
			{
				curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
				curr = curr->right;
				continue;
			}
		}
		else
		{
			if(getHeight(curr->left)>getHeight(curr->right))
			{
				if (curr->right==NULL)
				{
					curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
					curr->right = ins;
					return;
				}
				else
				{
					curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
					curr = curr->right;
					continue;
				}
			}
			else
			{
				if (curr->left==NULL)
				{
					curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
					curr->left = ins;
					return;
				}
				else
				{
					curr->height=1+max(getHeight(curr->right),getHeight(curr->left));
					curr = curr->left;
					continue;
				}
			}
		}
		
		
		
		
		
	}

} 

//
///
////
/////  rotation functions : /////
////
///
//

//Right rotation
Node* rightRotation(Node* a)  
{  
	Node* b = a->left;  
	Node* br = b->right;  
  
	// Perform rotation  
	b->right = a;  
	a->left = br;  
  
	// Update heights  
	a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
	b->height = max(getHeight(b->left),getHeight(b->right)) + 1;

    // Return new root  
    return b;  
}  

//Left rotation 
Node* leftRotation(Node* a)
{	cout<<"Left rotation"<<endl;
	if(a->key < a->right->key)
	{
		cout<<"case 1"<<endl;
		Node* b = a->right;
		Node* bl = b->left;
		
		
		b->left = a;
		a->right = bl;
		
		
		a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
		
		b->height = max(getHeight(b->left),getHeight(b->right)) + 1;
		return b;
	}
	else
	{
		cout<<"case 2"<<endl;
		Node* b = a->right;
		
		Node* al = a->left;
		Node* c = b->right;
		
		a->right = c;
		a->left = b;
		b->right = al;
		
		b->height = max(getHeight(b->left),getHeight(b->right)) + 1;
		a->height = max(getHeight(a->left),getHeight(a->right)) + 1;
		return a;
	}
}

//Rotation for Left Right Case:
Node* leftRightCase(Node* z)
{	

z->left = leftRotation(z->left);
return rightRotation(z);
	/*
	cout<<"Rotation for Left Right Case"<<endl;
	//find y and x
	
	Node* y = z->left;
	Node* x = y->right;
	
	if(x->key > y->key)
	{
		cout<<"case 1"<<endl;
		//take children of x
		Node* xr = x->right;
		Node* xl = x->left;
		
		x->right = z;
		x->left = y;
		
		z->left = xr;
		y->right = xl;
		
		y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
		x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
		z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
		return x;
	}
	else
	{
		Node* xr = x->right;
		Node* yl = y->left;
		
		y->right = z;
		z->left = xr;
		y->left = x;
		x->right = yl;
		
		y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
		x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
		z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
		return y;
	}
	
	
	
	*/
	
	
}

//Rotation for Right Left Case:
Node* rightLeftCase(Node* z)
{
	
	
z->right = leftRotation(z->right);
return leftRotation(z);
	
	/*
	cout<<"Rotation for Right Left Case"<<endl;
	//find y and x
	
	Node* y = z->right;
	Node* x = y->left;
	
	Node* yl = y->right;
	
	y->right = z;
	z->right = yl;
	y->left = x;
	
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	z->height = max(getHeight(z->left),getHeight(z->right)) + 1;
	
	return y;
	
	*/
}


//function that checks if a rotation is needed
//if so it checks the case and calls the appropriate rotation function
Node* rotate(Node* node)
{
	int balance = getBalance(node);//get balance of current node
	if (balance > 1 || balance < -1)
	{
		cout<<"Node is unbalanced"<<endl;

		
		//nodes that will rotate:
		Node* z = node;//current node
		Node* y = NULL;//child node
		Node* x = NULL;//grand child node
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
		
		cout<<"z is "<<z->key<<endl;
		cout<<"y is "<<y->key<<endl;
		cout<<"x is "<<x->key<<endl;
		
		if(z->left==y && y->left==x)
		{
			cout<<"Left Left Case"<<endl;
			return rightRotation(z);
		}
		else if(z->left==y && y->right==x)
		{
			cout<<"Left Right Case"<<endl;
			return leftRightCase(z);
		}
		else if(z->right==y && y->right==x)
		{
			cout<<"Right Right Case"<<endl;
			return leftRotation(z);
		}
		else if(z->right==y && y->left==x)
		{
			cout<<"Right Left Case"<<endl;
			return rightLeftCase(z);
		}
		
		
		
		

	}
	
	else cout<<"Node is balanced"<<endl;
	return node;
}




//insert function
Node* insert(Node* node,int key)
{
	
	
	
	
	//if node is empty insert
	if (node == NULL)
	{  
		Node* dummyNode = newNode(key);
		if(maxNode == NULL  )maxNode=dummyNode;
		else if(maxNode->key < dummyNode->key)maxNode=dummyNode;
		return(dummyNode);  
	}
  
	if (key < node->key)
	{
		if(getHeight(node->left) < getHeight(node->right))node->left = insert(node->left, key);
		else node->right = insert(node->right, key);
	}  
		  
	//if the key is bigger than the current root it goes right
	else if (key > node->key)  
		node->right = insert(node->right, key);  



	//Update height of this ancestor node
	node->height = 1 + max(getHeight(node->left),getHeight(node->right));
	
	
	
	//if(maxNode == NULL  )maxNode=node;
	//else if(maxNode->key < node->key)maxNode=node;
	
	
	node = rotate(node);
	
	return node;
}





/*

void delMax2(Node* root)
{
	if(maxNode->right==NULL && maxNode->left==NULL)
	{
		maxNode = NULL;
	}
	else 
	{
		//first initialize the length and fill the array with -1
		
		int maxNumbNodesl = pow(2,max(getHeight(maxNode->left->left),getHeight(maxNode->left->right)) + 1) - 1 ; 
		int mynodesl[maxNumbNodesl];
		
		int maxNumbNodesr = pow(2,max(getHeight(maxNode->right->left),getHeight(maxNode->right->right)) + 1) - 1 ; 
		int mynodesr[maxNumbNodesr];
		
		for (int i=0; i < maxNumbNodesl ; i++)
		{
			mynodesl[i]=-1;
		}
		
		
		for (int i=0; i < maxNumbNodesr ; i++)
		{
			mynodesr[i]=-1;
		}
		
		int j = 0;
		
		if(root != NULL)  
		{  
			mynodesl[j]=root->key;
			j+=1;
			if(root==maxNode)mynodes[j]=-1;
			preOrder(root->left);  
			preOrder(root->right);  
		}
		
		
		j = 0;
		
		if(root != NULL)  
		{  
			mynodes[j]=root->key;
			j+=1;
			if(root==maxNode)mynodes[j]=-1;
			preOrder(root->left);  
			preOrder(root->right);  
		}
		
		
		
		

		for (int i=0; i < maxNumbNodes ; i++)
		{
			cout<<mynodes[i]<<endl;
		}
		
		maxNode = NULL;
		
		for (int i=0; i < maxNumbNodes ; i++)
		{
			if(mynodes[i]==-1)continue;
			root = insert(root,mynodes[i]);
		}
	}
	
	
}

*/


//InOrder traversal with insert
void inOrderInsert(Node* root ,Node* child)
{
	if(child != NULL)  
	{ 
		inOrderInsert(root,child->left);
		root = insert(root,child->key);
		inOrderInsert(root,child->right);  
	} 
}


//function that finds the height for delmax(case 2)
int depth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = getHeight(node->left);  
        int rDepth = depth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  





//

Node* delMax(Node* root)
{
	//if max is root
	if(maxNode == root)
	{
		if(maxNode->right==NULL && maxNode->left==NULL)
		{
			root = NULL;
			maxNode = NULL;
			return root;
		}
		
		else if(maxNode->right!=NULL && maxNode->left==NULL)
		{
			root = root->right;
			maxNode = root;
			return root;
		}
		
		else if(maxNode->right==NULL && maxNode->left!=NULL)
		{
			root = root->left;
			maxNode = root;
			return root;
		}
		
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
	//if max is not root
	
	else
	{
		cout<<"my test"<<endl;
		Node* tempRight = maxNode->right;
		Node* tempLeft = maxNode->left;
		
		Node* parent =NULL;
		parent = root;
		while(parent->right!=NULL)
		{
			if(parent->right->key == maxNode->key)break;
			parent=parent->right;
		}
		cout<<"the parent is "<<parent->key<<endl;
		
		//delete maxNode
		maxNode = NULL;
		parent ->right = NULL;
		//fix height of parent
		parent->height = max(getHeight(parent->left),1);
		//fix height of the affected nodes
		cout<<"asdsa";
		Node* pntr=root;
			while(true)
			{
				if(pntr == parent)break;
				pntr->height = depth(pntr);
				parent=parent->right;
			}
			cout<<"2222";
		root->height = max(getHeight(root->left),getHeight(root->right));
		
		//check root for rotations
		while(true){
		int balance = getBalance(root);//get balance of current node
		if (balance > 1 || balance < -1)root = rotate(root);
		else break;
		}
		
			
		findNewMax(root);
		inOrderInsert(root,tempRight);
		inOrderInsert(root,tempLeft);
		return root;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	else
	{
		if(maxNode->right==NULL && maxNode->left==NULL)
		{
			cout<<"Max is "<<maxNode->key<<" and it is leaf"<<endl;
			Node* parent =NULL;
			parent = root;
			while(parent->right!=NULL)
			{
				if(parent->right->key == maxNode->key)break;
				parent=parent->right;
			}
			cout<<"the parent is "<<parent->key<<endl;
			
			parent->right = NULL;
			
			//find the new max
			findNewMax(root);
			
			//check root for rotations
			rotate(root);
			
			return root;
		}
		
		else if(maxNode->right!=NULL && maxNode->left==NULL)
		{
			cout<<"Max is "<<maxNode->key<<" and it has only right child"<<endl;
			//save the child
			Node* temp = maxNode->right;
			cout<<"temp root is "<<temp->key<<endl;
			//find the parent
			Node* parent =NULL;
			parent = root;
			while(parent->right!=NULL)
			{
				if(parent->right->key == maxNode->key)break;
				parent=parent->right;
			}
			cout<<"the parent is "<<parent->key<<endl;
			
			
			//connect parent with the right child
			parent->right = temp;
			//delete max
			maxNode=NULL;
			//start from root
			
			Node* pntr=root->right;
			while(true)
			{
				if(pntr == temp)break;
				pntr->height = max(getHeight(pntr->left),getHeight(pntr->right) - 1);	//fix the heights
				parent=parent->right;
			}
			
			
			//find the new max
			findNewMax(root);
			
			//check root for rotations
			rotate(root);
			
			
			return root;
		}
		else if(maxNode->right==NULL && maxNode->left!=NULL)
		{
			cout<<"Max is "<<maxNode->key<<" and it has only left child"<<endl;			
			//save the child
			Node* temp = maxNode->left;
			//find the parent
			Node* parent =NULL;
			parent = root;
			while(parent->right!=NULL)
			{
				if(parent->right->key == maxNode->key)break;
				parent=parent->right;
			}
			cout<<"the parent is "<<parent->key<<endl;
			
			//delete max
			maxNode=NULL;
			
			//fix parent's height:
			parent->height = max(getHeight(parent->left),1);
			//find height reduction:
			int reduction = getHeight(temp) + 1 ;//height of left child + 1
			//start from root
			Node* pntr=root->right;
			while(true)
			{
				if(pntr == parent)break;
				pntr->height = max(getHeight(pntr->left),getHeight(pntr->right) - reduction);	//fix the heights
				parent=parent->right;
			}
			
			//find the new max
			findNewMax(root);
			
			//check root for rotations
			rotate(root);
			
			//insert the keys from the subtree temp
			inOrderInsert(root,temp);
			
			
			return root;
		}
		else
		{
			cout<<"Max is "<<maxNode->key<<" and it has right and left child"<<endl;
			
			
			
			return root;
		}
		
	}
	*/
}



int main()
{
	Node* root = NULL;
	
	
	cout<<"A tree has been created and its ready for use"<<endl;
	showMenu();

	while(true)
	{
		int i = getInt(i);
		if(i==1){getMax();continue;}
		if(i==2)
		{
			cout<<"Give number for tree insertion"<<endl;
			int j = getIntGen(j);
			root = insert(root,j);
			//preOrder(root);
	//cout<<endl;
	//inOrder(root);
	//cout<<endl<<getHeight(root);
	continue;
		}
		else if(i==3)
		{
			delMax(root);
			continue;
		}
		else if(i==4)
		{
			cout<<"preOrder traversal is ";
			preOrder(root);
			cout<<endl;
			cout<<"inOrder traversal is ";
			inOrder(root);
			cout<<endl;
			continue;
		}
		else break;
		
		
	}
	

	
	
	/*
root = insert(root,5);
root = insert(root,3);
root = insert(root,2);
root = insert(root,1);
root = insert(root,10);
root = insert(root,12);
root = insert(root,13);
root = insert(root,20);root = insert(root,53);
root = insert(root,40);
root = insert(root,14);
root = insert(root,15);
root = insert(root,16);
root = insert(root,17);
root = insert(root,50);
root = insert(root,51);
root = insert(root,52);

root = insert(root,9);
root = insert(root,6);
root = insert(root,7);
root = insert(root,8);
root = insert(root,18);
root = insert(root,19);
	
	
	
	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl<<getHeight(root)<<endl;
	//findMax(root);
	getMax();
	//cout<<maxNode->right->key<<endl;
	//cout<<maxNode->left->key<<endl;
	//delMax(root);

//preOrder(root);
	//cout<<endl;
	//inOrder(root);
	//cout<<endl<<getHeight(root)<<endl;
	
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	
	root = insert(root,5);
	root = insert(root,4);
	root = insert(root,6);
	getMax();
	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl<<getHeight(root)<<endl;
	//findNewMax(root);
	
	cout<<"Root is "<<root->key<<endl;
	
	root = delMax(root);
	preOrder(root);
	//if(maxNode == NULL)cout<<"there is no node";
	
	getMax();
	
	inOrder(root);
	
	
	*/
	
	
	
	
	/*
	
	root = insert(root,10);
	root = insert(root,9);
	root = insert(root,20);
	root = insert(root,5);
	root = insert(root,4);
	//root = insert(root,6);
	
	*/
	
	/*
	root = insert(root,10);
	root = insert(root,50);
	root = insert(root,6);
	root = insert(root,60);
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,5);
	*/
	
	
	
	
	
	// root = insert(root,5);
// root = insert(root,3);
// root = insert(root,2);
// root = insert(root,1);
// root = insert(root,10);
// root = insert(root,12);
// root = insert(root,13);
// root = insert(root,20);root = insert(root,53);
// root = insert(root,40);
// root = insert(root,14);
// root = insert(root,15);
// root = insert(root,16);
// root = insert(root,17);
// root = insert(root,50);
// root = insert(root,51);
// root = insert(root,52);

// root = insert(root,9);
// root = insert(root,6);
// root = insert(root,7);
// root = insert(root,8);
// root = insert(root,18);
// root = insert(root,19);
	
	
	// /*
	// root = insert(root,50);
	// root = insert(root,9);
// root = insert(root,6);
// root = insert(root,7);
// root = insert(root,8);
// */

	// getMax();
	// preOrder(root);
	// cout<<endl;
	// inOrder(root);
	// cout<<endl<<getHeight(root)<<endl;
	
	
	
	// root = delMax(root);
	
	// getMax();
	// preOrder(root);
	// cout<<endl;
	// inOrder(root);
	// cout<<endl<<getHeight(root)<<endl;
	
	
	
	
	return 0;
}