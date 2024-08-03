#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{  
     cout<<"\n\t\t Welcome to Guess The Number game!"<<endl;
     cout<<"NOTE: You have to guess a number betwen 1 and 100. You'll have limited choices based on the level you choose. Good Luck...!"<<endl;
     while(true)
     {
        cout<<"\n Enter the difficulty level : \n";
        cout<<"1 Easy \t";
        cout<<"2 Medium \t";
        cout<<"3 Difficult \t";
        cout<<"0 For ending the game! \n"<<endl;
        int choice;
        cout<<"Enter the number : ";
        cin>>choice;
        srand(time(0));
        int r=1+(rand()%100);
        int player;
        if(choice==1)
        {
            cout<<"\nYou have 10 choices for finding secret number between 1 and 100.. ";
            int left=10;    
            for(int i=0;i<10;i++)
            {
                cout<<"\n\n Enter the number : ";
                cin>>player;
                if(player==r)
                {
                    cout<<"Well played ! You won, "<<player<<" is the secret number"<<endl;
                    cout<<"\t\t\t Thanks for playing..."<<endl;
                    cout<<"Play the game again with us!!\n\n"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nope, "<<player<<" is not the right number\n";
       
                    if(player>r)
                    {
                        cout<<"the secret number is smaller than the number you have chosen "<<endl;
                    }
                    else
                    {
                        cout<<"The secret number is greater than the number you have chosen"<<endl;
                    }
                    left--;
                    cout<<left<<" choices are left. "<<endl;
                    if(left==0)
                    {
                       cout<<"You couldn't guess the correct number, it was" <<r<<" ,You lose!!!\n\n";
                       cout<<"Play the game again to win!!\n\n";
                    }
                }
            } 
        }
        else if(choice==2)
        {
            cout<<"\nYou have 7 choices for finding secret number between 1 and 100.. ";
            int left=7;    
            for(int i=0;i<7;i++)
            {
                cout<<"\n\n Enter the number : ";
                cin>>player;
                if(player==r)
                {
                    cout<<"Well played ! You won, "<<player<<" is the secret number"<<endl;
                    cout<<"\t\t\t Thanks for playing..."<<endl;
                    cout<<"Play the game again with us!!\n\n"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nope, "<<player<<" is not the right number\n";
       
                    if(player>r)
                    {
                        cout<<"the secret number is smaller than the number you have chosen "<<endl;
                    }
                    else
                    {
                        cout<<"The secret number is greater than the number you have chosen"<<endl;
                    }
                    left--;
                    cout<<left<<" choices are left. "<<endl;
                    if(left==0)
                    {
                       cout<<"You couldn't guess the correct number, it was" <<r<<" ,You lose!!!\n\n";
                       cout<<"Play the game again to win!!\n\n";
                    }
                }
            }
        }
        else if(choice==3)
        {
            cout<<"\nYou have 5 choices for finding secret number between 1 and 100.. ";
            int left=5;    
            for(int i=0;i<5;i++)
            {
                cout<<"\n\n Enter the number : ";
                cin>>player;
                if(player==r)
                {
                    cout<<"Well played ! You won, "<<player<<" is the secret number"<<endl;
                    cout<<"\t\t\t Thanks for playing..."<<endl;
                    cout<<"Play the game again with us!!\n\n"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nope, "<<player<<" is not the right number\n";
       
                    if(player>r)
                    {
                        cout<<"the secret number is smaller than the number you have chosen "<<endl;
                    }
                    else
                    {
                        cout<<"The secret number is greater than the number you have chosen"<<endl;
                    }
                    left--;
                    cout<<left<<" choices are left. "<<endl;
                    if(left==0)
                    {
                       cout<<"You couldn't guess the correct number, it was" <<r<<" ,You lose!!!\n\n";
                       cout<<"Play the game again to win!!\n\n";
                    }
                }
            }
        }
        else if(choice==0)
        {
            exit(0);
        }
        else
        {
              cout<<"Wrong Choice, Enter the valid choice to play the game! (0,1,2,3)"<<endl;
        }
     }
     return 0;
}