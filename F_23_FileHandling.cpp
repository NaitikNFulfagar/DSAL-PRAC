/*
    Department maintains a student information. The file contains roll number, name, division and address. 
    Allow user to add, delete information of student. Display information of particular employee. 
    If record of student does not exist an appropriate message is displayed. 
    If it is, then the system displays the student details. 
    Use sequential file to main the data. 
*/

#include<iostream>
#include<fstream>
using namespace std;

class data
{
    public:
    int rno;
    char name[20];
    char div[10];
    char add[25];
};

class StudentDataBase
{
    public:
    data obj;
    ofstream o;
    ifstream i;
    fstream io;
    void create();
    void display();
    void search(int);
    void deleteinfo(int);
};

void StudentDataBase::create()
{
    o.open("DataBase.dat",ios::app|ios::binary);
    cout<<"\nEnter Roll No. : ";cin>>obj.rno;
    cout<<"\nEnter Name     : ";cin>>obj.name;
    cout<<"\nEnter Divsion  : ";cin>>obj.div;
    cout<<"\nEnter Address  : ";cin>>obj.add;
    o.write((char*)&obj,sizeof(obj));
    o.close();
}

void StudentDataBase::search(int x)
{
    i.open("DataBase.dat",ios::in|ios::binary);
    cout<<"\tRoll No.\tName\t\t\tDivsion\tAddress"<<endl;
    while(i.read((char *)&obj,sizeof(obj)))
    {   
        if(obj.rno==x)
        {
            cout<<"\t"<<obj.rno<<"\t\t"<<obj.name<<"\t\t\t"<<obj.div<<"\t"<<obj.add<<endl;
        }
    }
    i.close();
}

void StudentDataBase::deleteinfo(int x)
{
    o.open("temp.dat",ios::out|ios::binary);
    i.open("DataBase.dat",ios::in|ios::binary);
    while(i.read((char *)&obj,sizeof(obj)))
    {
        if(obj.rno!=x)
        {        
            o.write((char *)&obj,sizeof(obj));
        }
    }
    o.close();
    i.close();
    remove("DataBase.dat");
    rename("temp.dat","DataBase.dat");
}

void StudentDataBase::display()
{
    i.open("DataBase.dat",ios::in|ios::binary);
    cout<<"\tRoll No.\tName\t\t\tDivsion\tAddress"<<endl;
    while(i.read((char *)&obj,sizeof(obj)))
    {        
        cout<<"\t"<<obj.rno<<"\t\t"<<obj.name<<"\t\t\t"<<obj.div<<"\t"<<obj.add<<endl;
    }
    i.close();
}
int main()
{
    remove("DataBase.dat");
    StudentDataBase o;
    int ch,var;
    do
    {
        cout<<"\n***Menu***";
        cout<<"\n1.Create Record";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Delete";        
        cout<<"\n5.Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            	cout<<"\nEnter Record of 5 Students :-\n";
            	for(int i=0;i<3;i++)
            	{
                	o.create();
                }
                break;

            case 2:
                o.display();     
                break;
            
            case 3:
                cout<<"\nEnter Roll No. to be Searched : ";
                cin>>var;
                o.search(var);
                break;

            case 4:
                cout<<"\nEnter Roll No. to be Deleted : ";
                cin>>var;
                o.deleteinfo(var);
                cout<<"\nRecord Deleted Successfully!";
                break;
                
            default:
                cout<<"\nEnter Vaild opition!";
                break;    
        }
    }while(ch!=5);

    return 0;
}
//Coded By Naitik Fulfagar