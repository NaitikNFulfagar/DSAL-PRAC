/*
Beginning with an empty binary search tree, 
Construct binary search tree by inserting the values in the order given.
 After constructing a binary tree -
    i.    Insert new node,
    ii.   Find number of nodes in longest path from root, 
    iii.  Minimum data value found in the tree, 
    iv.   Change a tree so that the roles of the left and right pointers are swapped at every node, 
    v.    Search a value
*/

#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node()
    {
        left=NULL;
        right=NULL;
    }
};


class bst
{

    public:
        node* root;
        bst()
        {
            root=NULL;
        }
        void createtree();
        void inDisplay(node*);
        void preDisplay(node*);
        void postDisplay(node*);
        void smallest(node*);
        void Largest(node*);
        void search(int);
        void mirror(node*);
        int height(node*);
};

void bst::createtree()
{
    
    node* temp;
    node* newnode=new node;
    cout<<"Enter Number : ";
    cin>>newnode->data;
    if (root==NULL)
    {
        root=newnode;
    }
    else
    {
        temp=root;
        while(true)
        {
            if (newnode->data   <   temp->data)
            {
                if (temp->left==NULL)
                {     
                    temp->left=newnode;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else if (newnode->data  >   temp->data)
            {
                if (temp->right==NULL)
                {     
                    temp->right=newnode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
            else
            {
            cout<<"\nEnter Value Already Exist!!!";
            break;
            }
         }
    }
}

void bst::inDisplay(node* temp)
{

    if(temp!=NULL)
    {
        inDisplay(temp->left);
        cout<<temp->data<<",";
        inDisplay(temp->right);
    }
}

void bst::preDisplay(node* temp)
{

    if(temp!=NULL)
    {
        cout<<temp->data<<",";
        preDisplay(temp->left);
        preDisplay(temp->right);
    }
}

void bst::postDisplay(node* temp)
{

    if(temp!=NULL)
    {
        postDisplay(temp->left);
        postDisplay(temp->right);
        cout<<temp->data<<",";
    }
}

void bst::smallest(node* temp)
{
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    cout<<"Smallest Number : "<<temp->data<<endl;
    
    
}

void bst::Largest(node* temp)
{
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    cout<<"Largest Number : "<<temp->data<<endl;
  
}

void bst::search(int st)
{
    int chk=0;
    node* temp;
    if (root==NULL)
    {
        cout<<"Tree is Empty";
    }
    else
    {
        temp=root;
        chk=0;
        while(temp!=NULL)
        {
            if (st   <   temp->data)
            {
                   temp=temp->left;
            }
            else if (st  >   temp->data)
            {
                    temp=temp->right;
            }
            else
            {
                cout<<"\nElement Found!!!";
                chk=1;
                break;
            }
         }
         if (chk==0)
         {
            cout<<"\nElement NOT Found!!!";
         }
    }
}

void bst::mirror(node* r)
{
	node* temp;
	if (r!=NULL)
	{
        temp=r->left;
        r->left=r->right;
        r->right=temp;     
     
    mirror(r->left);
    mirror(r->right);
    }
}

int bst::height(node* temp)
{
	int LH,RH;
	if(temp==NULL)
	{
		return 0;     
	}
	else if(temp->left==NULL&&temp->right==NULL)
	{
		return 0;     
	}
	LH=height(temp->left);
	RH=height(temp->right);	
	if (LH>RH)
	{
		return LH+1;
	}
	else
	{
		return RH+1;
	} 
}



int main()
{
    bst o;
    int ch,dc;
    do
    {
        cout<<"\n***Menu***";
        cout<<"\n1.Create Node";
        cout<<"\n2.Display";
        cout<<"\n3.Smallest";
        cout<<"\n4.Largest";
        cout<<"\n5.Search";
        cout<<"\n6.Mirror";        
        cout<<"\n7.Height";        
        cout<<"\n8.Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            	cout<<"\nEnter 5 Elements\n";
            	for(int i=0;i<5;i++)
            	{
                	o.createtree();
                }
                break;
            case 2:
                cout<<"\n1.Inorder Display";
                cout<<"\n2.Preorder Display";
                cout<<"\n3.Postorder Display";
                cout<<"\nEnter Choice : ";
                cin>>dc;
                if(dc==1)
                {
                    o.inDisplay(o.root);
                    cout<<endl;
                }
                else if(dc==2)
                {
                    o.preDisplay(o.root);
                    cout<<endl;

                }
                else if(dc==3)
                {
                    o.postDisplay(o.root);                   
                    cout<<endl;
                }                
                break;
            
            case 3:
                o.smallest(o.root);
                break;
            case 4:
                o.Largest(o.root);
                break;
            case 5:
                int el;
                cout<<"\nEnter Element: ";
                cin>>el;
                o.search(el);
                break;
            case 6:
   	            cout<<"\nBefore Mirror \n";
                o.inDisplay(o.root);
                o.mirror(o.root);
                cout<<"\nAfter Mirror Sequence\n";
                o.inDisplay(o.root);
                break; 
            case 7:
                cout<<"\n Height of Tree is : "<<o.height(o.root);
                break;    
         }
     }while(ch!=8);

    return 0;
}

//Coded By Naitik Fulfagar