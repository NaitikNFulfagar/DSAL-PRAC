/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS.
Use the map of the area around the college as the graph.
Identify the prominent land marks as nodes and perform DFS and BFS on that. 
*/
#include<iostream>
using namespace std;

class stack
{
    int t;
    int a[20];
    public:
    stack()
    {
        t=-1;
    }
    void push(int x)
    {
        if(t<20)
        {
            a[++t]=x;
            //cout<<t<<endl;
        }
        else
        {
            cout<<"Stack is Full !!";
        }
    }

    int pop()
    {
        if(t==-1)
        {
            cout<<"Stack is Empty";
        }
        else
        {
            return a[t--];
        }
    }

};

class graph
{
    int a[10][10];
    int vcnt,Rcnt;
    int v[20];
    public:
        graph()
        {
            Rcnt = 0;
            vcnt=0;
        }
        void read_adjacency();
        void display_adjacency();
        void DFS();
        int search(int);

    
};

void graph::read_adjacency()
{
	cout<<"Enter vertex count :";
	cin>>vcnt;
	cout<<"\nStart Entering Elements : ";
	for(int i=1;i<=vcnt;i++)
	{
		for(int j=1;j<=vcnt;j++)
		{
			cin>>a[i][j];
		}
	}
}

void graph::display_adjacency()
{
	for(int i=1;i<=vcnt;i++)
	{
		for(int j=1;j<=vcnt;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void graph :: DFS()
{
	stack s;
	int flag,i,j,cur;
	cout<<"Enter starting vertix :";
	cin>>cur;
	Rcnt = 0;
	flag = 0;
	s.push(cur);
	v[Rcnt++] = cur;
	cur = s.pop();
	
	for(i = cur; i<=vcnt;)
	{
		if (flag == 0)
		{
			for (j = 1; j<= vcnt;j++)
			{
				if(a[i][j] == 1)
				{
					s.push(j);
				}
				flag = 1;
			}
		}
		
		cur = s.pop();
		
		if(search(cur) == 0)
		{
			v[Rcnt++] = cur;
			flag = 0;
		}
		
		i = cur;
		if(Rcnt == vcnt)
		{
			break;
		}
	}
	cout<<"DFS=";
	for(int i=0;i<Rcnt;i++)
	{
			cout<<"   "<<v[i];
	}
	
}


int graph::search(int key)
{
    int i;

    for(i = 0; i<Rcnt; i++)
    {
           if(v[i] == key)
           {
                  return(1);
           }
    }
    if(i == Rcnt )
    {
           return(0);
    }
} 

int main()
{
	graph o;
	o.read_adjacency();
	o.display_adjacency();
	o.DFS();
    return 0;
}

//Coded By Naitik Fulfagar