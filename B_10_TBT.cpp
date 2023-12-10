/*
    Consider threading a binary tree using Display threads rather than inorder threads.
    Design an algorithm for traversal without using stack and analyze its complexity.
*/

#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;
        int lb, rb;
        node()
        {
            right=left=NULL;
            lb=rb=0;
        }
};

class TBT
{
    node *root,*head;
    public:
    TBT()
    {
        root = NULL;
        head = NULL;
    }
    void createTBT();
    void Display();
};

void TBT::createTBT()
{
    node *NewNode, *temp;
    
    head = new node(); 
    head ->data = -1;
    head ->left = head;
    head ->right = head;

    NewNode = new node();
    cout<<"\nEnter new node : ";
    cin>>NewNode ->data;
    if(root==NULL)
    {
        root=NewNode;
        head ->left = root;
        head -> lb = 1;
        root ->left = head;
        root ->right = head;
        root ->lb = 0;
        root ->rb = 0;
    }
    
    else
    {   
        temp = root;
        while(true)  // find proper place for new node.
        {
            if(NewNode -> data < temp -> data) 
            {
                if(temp ->lb == 0)
                {
                    NewNode ->left = temp ->left;
                    temp ->left = NewNode;
                    temp->lb=1;
                    NewNode ->right = temp;
                    break;
                }
                else
                {
                    temp = temp ->left;
                }
            }
            else if(NewNode -> data > temp ->data)
            {
                if(temp ->rb ==0)
                {
                    NewNode ->right = temp ->right;
                    temp ->right  = NewNode;
                    temp ->rb = 1;
                    NewNode ->left = temp;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
            else
            {
                cout<<"\n Data is already exist";
                break;
            }
        }
    }
}

void TBT::Display()
{
    node *temp;
    temp = root;
    int flag =0;
    
    if(root == NULL)
    {
        cout<<"\nTree is empty";
    }
    else
    {
        while(temp != head)
        {
            if(flag ==0)
            {
                cout<<" "<<temp ->data;
            }
            if(temp->lb==1 && flag ==0)
            {
                temp = temp ->left;
                
            }
            else
            {
                if(temp ->rb == 1)
                {
                    temp = temp ->right;
                    flag=0;
                }
                else
                {
                    temp = temp->right;
                    flag =1;
                }
            }
        }
    }
}

int main()
{
    TBT o;
    int ch;
    do
        {
            cout<<"\n***Menu***";
            cout<<"\n1.Create Nodes";
            cout<<"\n2.Display";
            cout<<"\n3.Exit";
            cout<<"\nEnter Choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1:
                    cout<<"\nEnter 5 Numbers :-\n";
                    for(int i=0;i<5;i++)
                    {
                        o.createTBT();
                    }
                    break;

                case 2:
                    o.Display();     
                    break;
                
                default:
                    cout<<"\nEnter Vaild opition!";
                    break;    
            }
    }while(ch!=3);

    return 0;
}

//Coded By Naitik Fulfagar