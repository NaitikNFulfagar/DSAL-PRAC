/*
    Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. 
    Make use of two collision handling techniques and compare them using number of comparisons required to find aset of telephone numbers
*/

#include<iostream>
using namespace std;
#define size (long int)10

class Hashing
{
    public:
    long int mob[size];
    int tf=0,cnt=0;
    Hashing()
    {
        for(int i=0;i<size;i++)
        {
            mob[i]=-1;
        }
    }
    void linear(long int);
    void quadratic(long int);
    void display();
};

void Hashing::linear(long int x)
{
    tf++;
    long int inx=0; 
    inx = x % 10;
    if(tf>size)
    {
        cout<<"\nTable is Full!";
        return;
    }
    else if(mob[inx]==-1)
    {
        mob[inx]=x;
        cnt++;
        return;
    }
    else
    {
        while(mob[inx]!=-1)
        {
            cnt++;
            if(inx==size-1)
            {
                inx=0;
                continue;
            }
            inx++;
            
        }
        mob[inx]=x;
    }
}

void Hashing::quadratic(long int x)
{
    tf++;
    long int inx=0; 
    inx = x % 10;
    if(tf>size)
    {
        cout<<"\nTable is Full!";
        return;
    }
    else if(mob[inx]==-1)
    {
        mob[inx]=x;
        cnt++;
        return;
    }
    else
    {
        int j=1,tinx;
        while(mob[inx]!=-1)
        {
            cnt++;
            tinx=(inx+j*j)%size;
            if(mob[tinx]==-1)
            {
                //inx=0;
                mob[tinx]=x;
                break;
            }
            j++;
        }
    }
}



void Hashing::display()
{
    for(int i=0;i<size;i++)
    {
    cout<<i<<"\t"<<mob[i]<<endl;
    }
}

int main()
{
    int ch=0;
    long int mob;
    Hashing l,q;
    do
    {
        cout<<"\n*****Menu******";
        cout<<"\n1.Enter Number";
        cout<<"\n2.Display Linear List";
        cout<<"\n3.Display Quadratic List";
        cout<<"\n4.Compare";
        cout<<"\n5.Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"\nEnter 5 Mobile No.:";
                for(int i=0;i<5;i++)
                {
                    cin>>mob;
                    l.linear(mob);
                    q.quadratic(mob);
                }
                break;

            case 2:
                l.display();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout<<"\nLinear Probling Comparision : \t"<<l.cnt;
                cout<<"\nQuadratic Probling Comparision : \t"<<q.cnt;
                break;
            
            
            default:
                cout<<"\nEnter Valid Input!!!!";
                break;
        }
    }while ((ch!=5));
}

//Coded By Naitik Fulfagar