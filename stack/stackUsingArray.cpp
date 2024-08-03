////program of stack......
#include<iostream>
//#include<dos.h>
#include <thread>
#include <chrono>
#include<unistd.h>
#include<conio.h>
using namespace std;
const int n=50;
int a[n];
int top=-1;
void insert(){
    if(top<n){
        top++;
        cout<<"Enter number you want to insert- ";
        cin>>a[top];
    }else{
        cout<<"Stack is full.";
    }

//sleep(1);
//system("cls");
}
void multiins(){
        top++;
        cout<<"Enter numbers, to stop press -1 "<<endl;
        for(int i=0;i<n;i++)
        { cin>>a[top];
          if(a[top]==-1){//how can i take input of -1 here???????????
            top--;
            break;
          } ;
          top++;
         }
       //  this_thread::sleep_for(chrono::seconds(2));
    //    sleep(2);
    //      system("cls");
}

void delet(){
    if(top!=-1){
        top--;
        cout<<"Successfully poped"<<endl;
    }else{
        cout<<"Stack is empty.";
    }
    // sleep(1);
    // system("cls");
}
 void display(){
    if(top==-1){
        cout<<"Stack is empty-"<<endl;
    }else{
    for(int i=0;i<=top;i++){
        cout<<a[i]<<' ';
    }
    }
    //  getch();
    // system("cls");
 }
 void check(){
    if(top==-1){
        cout<<"Stack is empty- "<<endl<<"Total space- "<<n;
    }else{
    cout<<"The last element is- "<<a[top]<<endl;
    cout<<"Evalable space- "<<n-top-1.<<endl;
    }
//    /ystem("cls");
 }
int main(){
    bool c=true;
    cout<<"*********Operation window**********"<<endl;
        cout<<"Press 1 to insert "<<endl
        <<"Press 2 to multiple inputs"<<endl
        <<"Press 3 to delete "<<endl
        <<"Press 4 to display"<<endl
        <<"Press 5 to last element and empty space"<<endl
        <<"Press 6 to exit"<<endl;
        cout<<"Enter your choice- ";
    while(c){
        int choice;
        cin>>choice;
        switch(choice){
            case 1: insert();
            break;
            case 2: multiins();
            break;
            case 3: delet();
            break;
            case 4: display();
            break;
            case 5: check();
            break;
            case 6: c=false;
            break;
            default: cout<<"Please choose a right option "<<endl;
            system("cls");
        };
        
    };
     cout<<"*********Thank you**********"<<endl;

    return 0;
}