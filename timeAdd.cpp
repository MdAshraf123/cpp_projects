//Addition of two time  ;;;;;
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class time{
   
    int hours;
    int minute;
    public:
   void get(){
    cout<<"Enter time- ";
    scanf("%d%d",&hours,&minute);
    };
    class time addtime(time&,time&);
    void showtime();
};

class time time::addtime(time &obj1,time &obj2){
    time t;
    int temp;
    t.hours=obj1.hours+obj2.hours;
    t.minute=obj1.minute+obj2.minute;
    temp=t.minute/60;
    t.hours+=temp;
    t.minute-=temp*60;
    return t;
};
void time::showtime(){
    cout<<"Time after addition- "<<this->hours<<":"<<this->minute;
};

int main(){
    class time t1,t2,stime;
    t1.get();
    t2.get();
    stime=stime.addtime(t1,t2);
    stime.showtime();
   //cout<<stime.hours;
   getch();
    return 0;
}