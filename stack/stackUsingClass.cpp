#include"iostream"
#include"conio.h"
#include<stack>
#include<list>
using namespace std;
class stak{
    int *arr;
    int top;
    int size;
    public:
    stak(int size){
        size=size;
        arr=new int[size];
        top=-1;
    };

    void push(int a){
    if(size-top>1){
        top++;
        arr[top]=a;
    }else{cout<<"Array is full";}
    
   } 
   void tope(){
       cout<<"Element is"<< arr[top];
    }
   bool isEmpty(){
       return top==-1; 
   }
   bool isFull(){
    return size-1==top;
   }
   int pop(){
    if(!isEmpty()){
    int poped=arr[top];
     top--;
     return poped;
    }
   }
};

int main(){
    stak s(5);
  s.push(9);
  s.push(10);
  s.push(12);
  s.pop();
 cout<<"poped"<< s.pop()<<endl;
 s.tope();


    return 0;
}