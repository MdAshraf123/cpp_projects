#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class user
{
public:
    int id;
    char sname[10];
    char fname[10]; ////////sum of objects 43
    char state[10];
    char course[5];
    int duration;
    char batch[10];
    int roll; /////////46
    float tmarks;
    float attend_percent;
    string passingStatus;
    void fetchData(int);
    void display();
    void createPassword(int);
};
typedef struct credencial
{
    int matchId;
    int pass;
} creden;
void login();
inline void user::display()
{
    cout << "-----------Your Welcome-----------" << endl
         << "Id- " << id << endl
         << "Roll no.- " << roll << endl
         << "Name- " << sname << endl
         << "course- " << course << endl
         << "Batch- " << batch << endl
         << "Total obtained marks- " << tmarks << endl
         << "Attendence in percent- " << attend_percent << "%" << endl;
    if (tmarks / 5 >= 30)
    {
        cout << "Passing Status- Pass" << endl;
    }
    else
    {
        cout << "Passing Status- Fail" << endl;
    }
}

void user::fetchData(int a)
{
    ifstream account("classRecord.txt");
    while (account.read((char *)this, sizeof(*this)))
    {
        if (this->id == a)
        {
            display();
            break;
        }
    }
    account.close();
}

void user::createPassword(int a)
{
    string password;
    creden obj;
    user obj1;
    obj.matchId = a;
    bool flag = false;
    ifstream in("classRecord.txt");
    ofstream userpass("userPassword.txt", ios::app);

    while (in.read((char *)this, sizeof(*this)))
    {
        if (this->id == a)
        {
            flag = true;
            break;
        }
    }
    in.close();
    if (flag)
    {
        cout << "You are recognized by our institute " << endl;
        cout << "Set your password- ";
        cin >> obj.pass;
        userpass.write((char *)&obj, sizeof(obj));
        userpass.close();
        cout << "Your credencial is created successfully" << endl;
        login();
    }
    else
    {
        cout << "Sorry, You are not recognized by our institute- " << endl;
    }
}
void login()
{
    bool check = false;
    creden obj1;
    user obj;
    int userid;
    int password;
    ifstream fin("userPassword.txt", ios::in);
    if (fin.fail())
    {
        cerr << "File opening failed! " << endl;
        return;
    }
    cout << "Enter your user id(Given by your accedmics)- ";
    cin >> userid;
    cout << "Enter password- ";
    cin >> password;
    while (fin.read((char *)&obj1, sizeof(obj1)))
    {
        // cout << obj1.matchId << endl
        //      << obj1.pass << endl;
        if (userid == obj1.matchId && password == obj1.pass)
        {
            obj.fetchData(userid);
            check = true;
            break;
        }
    }
    fin.close();
    if (!check)
    {
        cout << "Create your credencial to login" << endl;
        obj.createPassword(userid);
    }
}

int main()
{
    login();
    cout << "_________Thank You________";
    return 0;
}