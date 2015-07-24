#include<iostream>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};
BSTNode *root = NULL;
BSTNode* CreateRecur(BSTNode*,int);
void InorderRecur(BSTNode*);
BSTNode* CreateRecur(BSTNode* root, int val)
{
	if(root == NULL)
	{
		root = new BSTNode;
		root->data = val;
		root->left = NULL;
		root->right= NULL; 
	}
	else
	{
		if(val<root->data)
			root->left = CreateRecur(root->left,val);
		else
			root->right = CreateRecur(root->right,val);
	}
	return root;
}
void InorderRecur(BSTNode* root)
{
	if(root!=NULL)
	{
		InorderRecur(root->left);
		cout<<"\t\a"<<root->data;
		InorderRecur(root->right);
	}
}
int main()
{
	while(1)
	{
		cout<<"\n==================================================================";
		cout<<"\n 	Basic Opertions on Binary Search Tree(Recursive Methods)       ";
		cout<<"\n==================================================================";
		cout<<"\n 1. Create Binary Search Tree.";
		cout<<"\n 2. Inorder Traversal of Binary Search Tree.";
		//cout<<"\n 3. Searching any element in the Binary Search Tree.";
		cout<<"\n 4. Exit.";
		cout<<"\n\t Choose your option : ";
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n Enter the Data at node : ";
				int data;
				cin>>data;
				root = CreateRecur(root,data);
				break;
				
			case 2:
				InorderRecur(root);
				break;
				
			/*case 3:
				cout<<"\n Enter the data to be searched in the BST : ";
				int d;
				cin>>d;
				Searchdata(d,root);
				break;*/
				
			case 4:
				cout<<"\n Thanks for using..";
				exit(0);
				
			default:
				cout<<"\n Invalid Option : Try Again..";
		}					
	}	
}		 

