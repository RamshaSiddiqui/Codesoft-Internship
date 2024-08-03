#include<iostream>
using namespace std;
int main()
{
    cout<<"\t\t\tSimple Calculator"<<endl;
    double a, b;
    cout<<"Enter the 1st number = ";
    cin>>a;
    cout<<"Enter the 2nd number = ";
    cin>>b;
    int c;
    cout<<"Enter any operator from the given options :  \n 1. Addition \t 2.Subtraction \t 3.Multiplication \t 4.Division";
    cin>>c;
    switch(c)
    {
        case 1:
                   cout<<a<<" + "<<b<<" = "<<a+b<<endl;
                   break;
        case 2:
                   cout<<a<<" - "<<b<<" = "<<a-b<<endl;
                   break;
        case 3:
                   cout<<a<<" * "<<b<<" = "<<a*b<<endl;
                   break;
        case 4:
                  if(b==0.0)
                  {
                     cout<<"Divide by zero case"<<endl;
                  }
                  else
                  {
                   cout<<a<<" / "<<b<<" = "<<a/b<<endl;
                   }
                    break;
        default:
                 cout<<"Invalid choice.."<<endl;                                                     
    }
    return 0;

}