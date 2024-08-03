#include<iostream>
#include<iomanip>
#include<unistd.h>
#include<fstream>
using namespace std;
class account {
    string holder;
    unsigned long accountNo;
    long balance;
    public:
    account(){
        this->balance=0;
    }
    void accountData(){
        cout<<"--------Acount data------------"<<endl;
        cout<<"Account holder name- "<<holder<<endl;
        cout<<"Acount no- "<<accountNo<<endl;
        cout<<"Balance- "<<balance<<endl;
    }
    void deposit(){
        cout<<"-----------Balance deposit window-------------"<<endl;
        static int deposit;
        unsigned int temp;
        cout<<"Enter holder name- ";
        cin>>holder;
        cout<<"Enter accout no.- ";
        cin>>accountNo;
        cout<<"How much balance you have to add- ";
        cin>>deposit;
        balance=balance+deposit;
    }
     void withdraw(){
        cout<<endl<<setw(20)<<"---------------Balance withdraw window--------------"<<endl;
        static int withdraw;
        cout<<setw(55)<<"How much balance you have to withdraw- ";
        cin>>withdraw;
        if(withdraw<=balance){
            balance=balance-withdraw;
        }else
        {
         cout<<"Unavailable balance";
        }

    }
    
};

int main(){
fstream file("record.txt",ios::app|ios::in);
account holder1;
int choice;
cout<<setw(60)<<"*********Option window**********"<<endl;
cout<<setw(53)<<" Enter 1 to deposit "<<endl
<<setw(54)<<"Enter 2 to withdraw "<<endl
<<setw(57)<<"Enter 3 to accountData "<<endl;
cout<<setw(53)<<endl<<"Enter your choise- ";

bool status=true;
while(status){
cin>>choice;
switch (choice)
{
case 1:holder1.deposit();   
break;
case 2:holder1.withdraw();
break;
case 3:holder1.accountData();
break;
case 4:status=false;
break;
default:cout<<" Wrong choise "<<endl;

}

}
    return 0;
}