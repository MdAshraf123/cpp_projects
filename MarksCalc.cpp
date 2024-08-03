#include <iostream>
using std::cout;
using std::endl;
using std::string;

class students
{
public:
    string name;
    int math;
    int science;
    int oops;
    int percent;

public:
    students(string name, int math, int science, int oops) : name(name), math(math), science(science), oops(oops)
    {
        this->percent = (math + science + oops) / 3;
    };
};
int main()
{
    //creating n objects for students data;
    int n;
    cout << "For how many students you have array- ";
    std::cin >> n;
    students **objects = new students *[n];
    //feeding data in it;
    for (int i = 0; i < n; i++)
    {
        static string nam;
        static int mat;
        static int scienc;
        static int oop;
        cout << "Enter " << i+1 << "th elements- "<<endl<<"First name- ";
        std::cin >> nam;
        cout<<"Enter math marks- ";
        std::cin>> mat;
        cout<<"Enter science marks- ";
        std::cin >> scienc;
        cout<<"Enter oops marks- ";
        std::cin >> oop;
        objects[i] = new students(nam, mat, scienc, oop);
    }
//displaying data before sorting;
    for (int p = 0; p < n; p++)
    {
        cout << objects[p]->name << endl;
        cout << objects[p]->math << endl;
        cout << objects[p]->science << endl;
        cout << objects[p]->oops << endl;
        cout << objects[p]->percent <<"%"<< endl;
    }
//sorting here
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (objects[i]->percent > objects[j]->percent)
            {
                students **object = new students *;
                *object = objects[i];
                objects[i] = objects[j];
                objects[j] = *object;
            }
        }
    }
//displaying data after sorting--------
    cout << "After sorting-------------" << endl;
    for (int p = 0; p < n; p++)
    {
        cout <<"Name of the student- " <<objects[p]->name << endl;
        cout <<"Math marks- " <<objects[p]->math << endl;
        cout <<"Science marks- "<< objects[p]->science << endl;
        cout <<"Oops marks- "<< objects[p]->oops << endl;
        cout <<"Percentage- "<<objects[p]->percent <<"%"<< endl;
    }
    return 0;
}
