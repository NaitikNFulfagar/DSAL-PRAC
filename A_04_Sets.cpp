/*
To create ADT that implement the "set" concept.
    a. Add (new Element) -Place a value into the set ,
    b. Remove (element) Remove the value
    c. Contains (element) Return true if element is in collection,
    d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection,
    e. Intersection of two sets ,
    f. Union of two sets,
    g. Difference between two sets,
    h. Subset
*/

#include <iostream>
using namespace std;
class Set
{
    public:
    int a[100];
    int cnt;
    
    Set()
    {
        cnt=0;
    }
    void insert();
    void remove();
    void Display();
    int size();
    bool find(int);
    Set nintersection(Set);
    Set nunion(Set);
    Set ndiff(Set);
    void subset(Set);
};

void Set::insert()
{
    int var;
    cout<<"\nEnter 5 Elements :\n";
    for(int i=0;i<5;i++)
    {
        cin>>var;
        if(!find(var))
        {
            a[cnt++]=var;
        }
    }
}

void Set::remove()
{
    int no,k;
    cout<<"\nEnter No. to be Deleted :";
    cin>>no;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]==no)
        {
            k=i;
            break;
        }
    }
    for (int  j = k; j < cnt; j++)
    {
        a[j]=a[j+1];
    }
    cnt--;
}

void Set::Display()
{
    cout<<"\nElements in Set :\n";
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i]<<endl;
    }
}

int Set::size()
{
    return cnt;
}

bool Set::find(int x)
{
    bool flag=false;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]==x)
        {
            flag=true;
            break;
        }
    }
    return flag;
}

Set Set::nintersection(Set B)
{
    Set temp;
    for(int i=0;i<cnt;i++)
    {
        if(B.find(a[i]))
        {
            temp.a[temp.cnt++]=a[i];
        }
    }
    return temp;
}

Set Set::nunion(Set B)
{
    Set temp;
    for(int i=0;i<cnt;i++)
    {
        temp.a[temp.cnt++]=a[i];
    }
    for(int j=0;j<B.cnt;j++)
    {
        if(!find(B.a[j]))
        {
            temp.a[temp.cnt++]=B.a[j];
        }
    }
    return temp;
}

Set Set::ndiff(Set B)
{
    Set temp;
    for(int i=0;i<B.cnt;i++)
    {
        if(!find(B.a[i]))
        {
            temp.a[temp.cnt++]=B.a[i];
        }
    }
    return temp;
}

void Set::subset(Set B)
{
    for(int i=0;i<B.cnt;i++)
    {
        if(!find(B.a[i]))
        {
            cout<<"\nFalse";
            return;
        }
    }
    cout<<"\nTrue";
}

int main()
{
    Set A,B,C,D,E,F;
    int ch;
        do
    {
        cout<<"\n*****Menu******";
        cout<<"\n01.Enter Element in Set A";
        cout<<"\n02.Enter Element in Set B";
        cout<<"\n03.Remove Element from Set A";
        cout<<"\n04.Remove Element from Set B";
        cout<<"\n05.Set A intersection Set B";
        cout<<"\n06.Set A union Set B";
        cout<<"\n07.A-B";
        cout<<"\n08.B-A";
        cout<<"\n09.Set A subset of Set B";
        cout<<"\n10.Set B subset of Set A";
        cout<<"\n11.Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                A.insert();
                A.Display();
                break;

            case 2:
                B.insert();
                B.Display();
                break;

            case 3:
                A.remove();
                A.Display();
                break;

            case 4:
                B.remove();
                B.Display();
                break;

            case 5:
                C=A.nintersection(B);
                C.Display();
                break;

            case 6:
                D=A.nunion(B);
                D.Display();
                break;

            case 7:
                E=B.ndiff(A);
                E.Display();
                break;

            case 8:
                E=A.ndiff(B);
                E.Display();
                break;
                
            case 9:
                B.subset(A);
                break;
                
            case 10:
                A.subset(B);
                break;
            
            default:
                cout<<"\nEnter Valid Input!!!!";
                break;
        }
    }while ((ch!=11));
}

//Coded By Naitik Fulfagar