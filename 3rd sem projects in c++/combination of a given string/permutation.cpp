// Code a C++ program to print all combinations of a string.
//  For e.g. entered string is XYZ Output is XYZ, XZY, YZX, ZXY……… 
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
char name[8];
int fact(int n) {
    if(n==0||n==1){
        return 1;
    }else{
        
        return n*=fact(n-1);
    }
}


int main(){
    int n=0,p=0,t;
    
    cout<<"Enter letter- ";
    cin>>name;
    for(int i=0;name[i]!='\0';i++){
        n++;
    }
 t=fact(n)/(n-1);
for(int i=0;i<t;i++){
    for(int j=n-1;j>0;j--){
        cout<<left<<setw(4)<<++p<<setfill('-')<<setw(6)<<name<<endl;
        char temp[8];
        strcpy(temp,name);
        name[j-1]=name[j];
        name[j]=temp[j-1];

    }
}
system("pause");
    return 0;
}