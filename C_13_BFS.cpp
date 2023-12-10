/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS.
Use the map of the area around the college as the graph.
Identify the prominent land marks as nodes and perform DFS and BFS on that.
*/
#include<iostream>
using namespace std;
class Queue
{
	public:
	int a[20],f,r;
	Queue()
	{
		f=r=-1;
	}
	void insert(int key)
	{
		if(r<=20)
		{
			a[++r]=key;
		}
		else
		{
			cout<<"Queue is Full!";
		}
	}

	int Delete()
	{
		if(f!=r)
		{
			return (a[++f]);
		}
		else if (f==20)
		{
			cout<<"Queue is Empty!";
		}
	}
};

class graph
{
	int a[10][10],vcnt,Rcnt;
	int v[20];
	public:
		graph()
		{
				Rcnt = 0;
				vcnt=0;
		}
		void read_adjacency();
		void display_adjacency();
		void BFS();
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

void graph::BFS()
{
	int sv,curr;
	cout<<"Enter starting vertex ";
	cin>>sv;
	v[Rcnt++]=sv;
	Queue q;
	q.insert(sv);
	for(int i=1; i<=vcnt; i++)
	{
		curr=q.Delete();
		for(int c=1;c<=vcnt;c++)
		{
			if(a[curr][c]==1)
			{
				
				if(search(c)==0)
				{
					q.insert(c);
					v[Rcnt++]=c;
				}
			}
		}
	}
	cout<<"BFS=";
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
	o.BFS();
    return 0;
}
//Coded By Naitik Fulfagar