#include<iostream>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode *left, *right;
};
BSTNode *root = NULL;
void CreateBST();
void InOrderBST(BSTNode*);
bool Searchdata(int, BSTNode*); 
void CreateBST()
{
	BSTNode *temp, *ptr, *p;
	char ans = 'Y';
	while(ans=='Y'||ans=='y')
	{
		temp = new BSTNode;
		cout<<"\n Enter Data in node : ";
		cin>>temp->data;
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL)
			root=temp;
		else
		{
			p=root;
			if(temp->data<root->data)
				ptr=root->left;
			else
				ptr=root->right;
			
			while(ptr!=NULL)
			{
				if(temp->data<ptr->data)
					ptr=ptr->left;
				else
					ptr=ptr->right;
				p=ptr;
			}
			
			if(temp->data<p->data)
				p->left=temp;
			else
				p->right=temp;
		}
		cout<<"\n Do you want to create another node ?(Y/N) : ";
		cin>>ans;
	}
	
}
void InOrderBST(BSTNode *root)
{
	if(root!=NULL)
	{
		InOrderBST(root->left);
		cout<<"\t\a"<<root->data;
		InOrderBST(root->right);
	}
}
bool Searchdata(int d, BSTNode* root)
{
	BSTNode *ptr;
	int flag=false;
	ptr = root;
	if(ptr->data==d)
		flag = true;
	else if(d<ptr->data)
		ptr=ptr->left;
	else
		ptr=ptr->right;
	while(ptr!=NULL)
	{
		if(d<ptr->data)
			ptr=ptr->left;
		else if(d>ptr->data)
			ptr=ptr->right;
		else
		{
			d=ptr->data;
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
	while(1)
	{
		cout<<"\n==================================================================";
		cout<<"\n 	Basic Opertions on Binary Search Tree(Iterative Methods)       ";
		cout<<"\n==================================================================";
		cout<<"\n 1. Create Binary Search Tree.";
		cout<<"\n 2. Inorder Traversal of Binary Search Tree.";
		cout<<"\n 3. Searching any element in the Binary Search Tree.";
		cout<<"\n 4. Exit.";
		cout<<"\n\t Choose your option : ";
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1:
				CreateBST();
				break;
				
			case 2:
				InOrderBST(root);
				break;
				
			case 3:
				cout<<"\n Enter the data to be searched in the BST : ";
				int d;
				cin>>d;
				Searchdata(d,root);
				break;
				
			case 4:
				cout<<"\n Thanks for using..";
				exit(0);
				
			default:
				cout<<"\n Invalid Option : Try Again..";
		}					
	}	
}		 
	
