#include<iostream>
#include<windows.h>
using namespace std;
void print(string task[], int count)
{
    cout<<"Task to do : "<<endl;
    cout<<"-------------------------------"<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"Task  "<<i<< ": "<<task[i]<<endl;
    }
    cout<<"-------------------------------"<<endl;
}
int main()
{
    string task[10]={""};
    int count=0;
    int option=-1;
    while(option!=0)
    {
        cout<<"---TO DO LIST ---"<<endl;
        cout<<"1 - To add new task"<<endl;
        cout<<"2 - To view task"<<endl;
        cout<<"3 - Delete the task"<<endl;
        cout<<"0 - Terminate the task"<<endl;
        cin>>option;
        switch(option)
        {
            case 1: 
            {
                if(count>9)
                {
                    cout<<"``` Task list is full ```"<<endl;
                }
                else
                {
                    cout<<"Enter a new task : ";
                    cin.ignore();
                    getline(cin, task[count]);
                     count++;
                }
                break;
            }
            case 2:
               system("cls");
               print(task,count);
               break;
             case 3:
                {
                    system("cls");
                    print(task,count);
                    int del=0;
                    cout<<"Enter a task no. to delete : ";
                    cin>>del;
                    if(del<0 || del>9)
                    {
                        cout<<"You enter invalid task no."<<endl;
                        break;
                    }
                    for(int i=del;i<count;i++)
                    {
                        task[i]=task[i+1];
                    }
                    count=count-1;
                    break;                        
                } 
                case 0:
                  cout<<"Terminate the program -------"<<endl;
                   break;
                default:
                      cout<<"You entered invalid option!"<<endl; 
        }
    }
    return 0;
}