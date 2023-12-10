/*
You have a business with several offices; you want to lease phone lines to connect them up with each other;
and the phone company charges different amounts of money to connect different pairs of cities.
You want a set of lines that connects all your offices
with a minimum total cost. Solve the problem by suggesting appropriate data structures.
*/
#include<iostream>
using namespace std;
class snode
{
    public:       
    char u1,u2;
    int wt;
};

class test
{
    int n,m,x;
    snode arr[10],res[10];
    public:
    test()
    {
        n=0;
        m=1;
    }

    void inputsparse();
    void displaysparse();
    void bsort();
    void kruskals();
    void dispmst();
};

void test::inputsparse()
{
    cout<<"ENTER NO OF VERTICES: ";
    cin>>x;
    cout<<"ENTER NO OF EDGES: ";
    cin>>n;
    cout<<"ENTER 1ST VERTEX:\tENTER 2ND VERTEX:\tENTER WEIGHT: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].u1;
        cin>>arr[i].u2;
        cin>>arr[i].wt;
    }
    bsort();
}

void test::displaysparse()
{
    cout<<"1ST VERTEX:\t2ND VERTEX:\tWEIGHT: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].u1<<"\t\t"<<arr[i].u2<<"\t\t"<<arr[i].wt<<endl;
    }
}

void test::bsort()
{
snode temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].wt>arr[j+1].wt)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void test::dispmst()
{
    cout<<"Result:\n1ST VERTEX:\t2ND VERTEX:\tWEIGHT: \n";
    for(int i=0;i<m;i++)
    {
        cout<<res[i].u1<<"\t\t"<<res[i].u2<<"\t\t"<<res[i].wt<<endl;
    }
}

void test::kruskals()
{
    int cnt=0;
    int flag1,flag2,i;
    res[0]=arr[0];
    m=1;
    cnt=1;

    do
    {
        for(i=1; i<n  ; i++) //arr
        {
            flag1=0;
            flag2=0;
            for(int j=0;j<m;j++)
            {
                if (flag1==0 && (arr[i].u1==res[j].u1 || arr[i].u1==res[j].u2 ) )
                {
                    flag1++;
                }
                if( flag2==0 && (arr[i].u2==res[j].u1 || arr[i].u2==res[j].u2 ))
                {
                    flag2++;
                }
            }
            if(flag1!=1  ^ flag2 !=1) // ^ xor operation.
            {
                    res[m++]=arr[i];
            }
        }
    }while(m!=x-1);
}



int main()
{
    test obj;
    obj.inputsparse();
    obj.displaysparse();
    obj.kruskals();
    obj.dispmst();
    return 0;
}