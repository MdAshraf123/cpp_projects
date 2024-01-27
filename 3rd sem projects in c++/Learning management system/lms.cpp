// Learning management system
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
// include <stdio.h>
#include <conio.h>

using namespace std;
void resetpassword()
{

    string password;
    {
        cout << "Enter your new password- ";
        cin >> password;
        ofstream file("password.txt", ios::out);
        file << password;
        file.close();
        cout << "Your password is succesfully changed" << endl;
    }
}
bool login()
{
    string pass, fpass;
    ifstream file("password.txt");
    file >> fpass;
    cout << "Enter password- ";
    cin >> pass;
    if (pass == fpass)
    {
        // cout << "-:Welcome:-" << endl;
        return true;
    }
    else
    {
        cout << "Wrong password" << endl;
        return false;
    };
}
// ADDMISSION CLASS-------
class admisn
{
protected:
    int id;

    char sname[10];
    char fname[10]; ////////sum of objects 43
    char state[10];
    char course[5];
    int duration;
    static int csepack;
    static int BCApack;
    static int FDpack;

public:
    admisn()
    {
        id = 0;
        strcpy(sname, "xyz");
        strcpy(fname, "xyz");
        strcpy(state, "xyz");
        strcpy(course, "xyz");
        duration = 0;
    }
    void newAdmission();
    void displayData();
    void displayfile();
    int searchData();

    void updateData();
    void deleteData();
};

int admisn::csepack = 666000;
int admisn::BCApack = 500000;
int admisn::FDpack = 450000;
// CLASS RECORD ----------
class classRecord : public admisn
{
private:
    char batch[10];
    int roll; /////////46
    float tmarks;
    float attend_percent;
    string passingStatus;

public:
    classRecord()
    {
        strcpy(batch, "xyz");
        roll = 000;
        tmarks = 0.00;
        attend_percent = 0.00;
        passingStatus = "xyz";
    }
    void D_getdata();
    void D_display();
    // void D_fileDisplay();
    void searchCData(int);
    void search_by();
    void D_update();
};
// NEW ADMISSIONS FUNCTION Definition------------
void admisn::newAdmission()
{
    int mid;
    cout << "\n\n------------------New Admission Window--------------------" << endl;

    cout << "Enter student name- ";
    cin.get(sname, 10);
    cin.ignore();
    cout << "Enter student id- ";
    cin >> id;
    mid = id;
    cin.ignore();
    cout << "Enter father's name- ";
    cin.get(fname, 10);
    fflush(stdin);
    cout << "Enter State- ";
    cin.get(state, 10);
    cin.ignore();
    cout << "Enter course- ";
    cin >> course;
    cout << "Enter duration- ";
    cin >> duration;
    fflush(stdin);
    //****file writing*****
    ofstream fil("record.txt", ios::app | ios::binary);
    fil.write((char *)this, sizeof(*this));
    fil.close();
}
// DATA DISPLAYING ------------------
void admisn::displayData()
{
    // cout << "\n-----------------" << this->sname << "'s Data------------------" << endl;

    cout << setw(3) << " " << right << id << setw(14) << sname << setw(18) << fname << setw(16) << state << setw(12) << course << setw(13) << duration;
    if (!strcmp(course, "cse") || !strcmp(course, "CSE"))
    {
        cout << setw(15) << csepack << endl;
    }
    else if (!strcmp(course, "bca") || !strcmp(course, "BCA"))
    {
        cout << setw(15) << BCApack << endl;
    }
    else
    {
        cout << setw(15) << FDpack << endl;
    }
}
//**********FILE READIN**********
void admisn::displayfile()
{
    ifstream fil("record.txt", ios::in);
    while (fil.read((char *)this, sizeof(*this)))
    {
        displayData();
    }
    fil.close();
};
//***********data searching by id++++++++++
int admisn::searchData()
{
    ifstream search;
    search.open("record.txt");
    int mId = 0, flag = 0;
    cout << "Enter id of student- ";
    cin >> mId;
    cout << "|---Id---|" << setw(17) << "|------Name------|" << setw(17) << "|--Father name--|" << setw(12) << "|---State---|" << setw(13) << "|---Course---|" << setw(12) << "|--Duration--|" << setw(13) << "|----Fee----|" << endl;
    while (search.read((char *)this, sizeof(*this)))
    {
        if (this->id == mId)
        {
            this->displayData();
            flag = 1;
            break;
        }
    };
    search.close();
    if (flag)
    {
        // cout << "Record found " << endl;
        return id;
    }
    else
    {
        cout << "Record not fund" << endl;
        return 0;
    }
}
//++++++++ data serching by ++++++++
void classRecord::search_by()
{
    ifstream re("classRecord.txt");
    int count = 0;
    string _identifier;
    int num;
    cout << "Filter data by- course(1)/batch(2)/state(3)- ";
    cin >> num;
    if (num == 1)
        cout << "Enter course name- ";
    else if (num == 2)
        // char compchar[10]=_identifier;
        cout << "Enter batch- ";

    else
        cout << "Enter state- ";

    cin >> _identifier;
    cout << "|---Id---|" << setw(17) << "|------Name------|" << setw(17) << "|--Father name--|" << setw(12) << "|---State---|" << setw(13) << "|---Course---|" << setw(12) << "|--Duration--|" << setw(13) << "|----Fee----|" << endl;
    while (re.read((char *)this, sizeof(*this)))
    {

        if (this->course == _identifier && num == 1)
        {
            displayData();
            ++count;
        }
        else if (this->batch == _identifier && num == 2)
        {
            displayData();
            cout << "Batch- " << this->batch << endl;
            ++count;
        }
        else if (this->state == _identifier && num == 3)
        {
            displayData();
            ++count;
        }
        // getch();
    }

    cout << endl;
    cout << "TOTAL STUDENTS- " << count << endl;
    if (!count)
    {
        cout << "There is no addmission in this course" << endl;
    }
}
//********updating data-------------
void admisn::updateData()
{
    int mid;
    ofstream file("temp.txt", ios::out);
    ifstream mainf("record.txt", ios::in);
    cout << "Enter student id of whome you want to update- ";
    cin >> mid;
    while (mainf.read((char *)this, sizeof(*this)))
    {

        if (this->id == mid)
        {
            cout << "Make corrections..." << endl;
            cout << "Name-";
            cin >> this->sname;
            cout << "Course- ";
            cin >> this->course;
            cout << "State- ";
            cin >> state;
            cout << "Duration- ";
            cin >> this->duration;
        }
        file.write((char *)this, sizeof(*this));
    }
    file.close();
    mainf.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}

/////////delete data from file++++++++++
void admisn::deleteData()
{
    int id;
    ifstream in("record.txt", ios::in);
    ofstream out("temp.txt", ios::out);
    cout << "Enter id of which you want to delete- ";
    cin >> id;
    while (in.read((char *)this, sizeof(*this)))
    {
        if (this->id == id)
        {
            continue;
        }
        out.write((char *)this, sizeof(*this));
    }
    in.close();
    out.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}
void classRecord::D_getdata()
{
    ofstream file("classRecord.txt", ios::app);
    if (searchData())
    {
        cout << "Enter batch- ";
        cin >> batch;
        cout << "Enter roll no.- ";
        cin >> roll;
        cout << "Enter Total marks obtained(out of 500)- ";
        cin >> tmarks;
        cout << "Enter attendence percent- ";
        cin >> attend_percent;
        if (tmarks / 5 > 30)
        {
            passingStatus = "pass";
        }
        else
        {
            passingStatus = "fail";
        };
    }
    else
    {
        cout << "Theres no any admision of this id " << endl;
    };
    file.write((char *)this, sizeof(*this));
    file.close();
}
void classRecord::D_display()
{
    // cout<<"----------------Display data-----------------"<<endl;
    cout << setw(4) << ' ' << left << setw(10) << id << setw(13) << batch << setw(22) << roll << setw(22) << tmarks / 5 << setw(18) << attend_percent << setw(16) << passingStatus << endl;

    if (attend_percent >= 70)
    {
        cout << "Elegibility for exam- "
             << "Elegible" << endl;
    }
    else
    {
        cout << "Elegibility for exam- "
             << "Not Elegible" << endl;
    }
}
void classRecord::searchCData(int a)
{
    ifstream reed("classRecord.txt");
    if (!reed.is_open())
    {
        cout << "File did not be opened" << endl;
    }
    bool flag = false;
    cout << setw(10) << "|--Id--|" << setw(14) << "|--Batch--|" << setw(16) << "|--Roll no.--|" << setw(23) << "|-Obtained Marks(%)-|" << setw(19) << "|-Attendence(%)-|" << setw(14) << "|--Status--|" << endl;
    while (reed.read((char *)this, sizeof(*this)))
    { /* */

        if (a == id)
        {
            D_display();
            flag = true;
        }
    };
    reed.close();
    if (!flag)
    {
        cout << "Class record is not found " << endl;
    }
}
void classRecord::D_update()
{
    int mid;
    ofstream out("temp.txt");
    ifstream in("classRecord.txt");
    cout << "Enter id- ";
    cin >> mid;
    while (in.read((char *)this, sizeof(*this)))
    {
        if (mid == id)
        {
            cout << "Make correction---" << endl;
            cout << "Batch- ";
            cin >> batch;
            cout << "Roll no.- ";
            cin >> roll;
            cout << "Obtained marks- ";
            cin >> tmarks;
            cout << "Attendence in percent- ";
            cin >> attend_percent;
        }
        out.write((char *)this, sizeof(*this));
    }
    out.close();
    in.close();
    remove("classRecord.txt");
    rename("temp.txt", "classRecord.txt");
}
// +++++++ MAIN FUNCTION ++++++++
int main()

{

    bool status = true;
    while (status)
    {
        int choice;
        for (int i = 2; i >= 0; i--)
        {
            if (login())
            {
                goto flag;
            }
            else
            {
                cout << setw(50) << right << "Remaining attempts" << i << endl;
                if (i != 0)
                    cout << "->Try again<-" << endl;
            }
        }
        cout << "Press 1 to reset your password" << endl
             << "Press 2 exit login page" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            resetpassword();
            break;
        case 2:
            status = false;
            exit(0);
            break;
        default:
            cout << "Choose right option please";
            break;
        }
    }

    exit(0);
flag:
flag1:
    system("cls");
    cout << endl;
    {
        char a = 178;
        char windowSwitch;
        cout << a << a << a << a << a << a << a << a << a << " WELCOM TO ADMIN WINDOW " << a << a << a << a << a << a << a << a << a << endl;
        cout << "Press 'a' for addmission window- " << endl
             << "Press 'b' for class-Record window- " << endl
             << "Press 'c' to exit" << endl
             << "Enter your choice- ";
        cin >> windowSwitch;
        switch (windowSwitch)
        {
        case 'a':
        {
            bool loopSwitch = true;
            int choice;
            admisn s1;
            classRecord cr;

            system("cls");
            cout << a << a << a << a << a << a << a << a << a << " ADMIN WINDOW " << a << a << a << a << a << a << a << a << a << endl;
            cout << "Enter 1 for new addmission- " << endl
                 << "Enter 2 to search a data " << endl
                 << "Enter 3 to delete data " << endl
                 << "Enter 4 to update data " << endl
                 << "Enter 5 to filter by- " << endl
                 << "Enter 6 to go to the main menue- " << endl;
            while (loopSwitch)
            {
                cout << "\nEnter your choice... ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    fflush(stdin);
                    cr.newAdmission();
                    break;
                case 2:
                    int copyid;
                    char yn;
                    if (copyid = cr.searchData())
                    {
                        cout << "Do you also want to see class status(y/n)?- ";
                        cin >> yn;
                        if (yn == 'y')
                        {
                            cr.searchCData(copyid);
                        }
                        else
                        {
                            break;
                        };
                    }
                    break;
                case 3:
                    s1.deleteData();
                    break;
                case 4:
                    s1.updateData();
                    break;
                case 5:
                    cr.search_by();
                    break;
                case 6:
                    loopSwitch = false;
                    goto flag1;
                    break;
                case 7:
                    cout << "|---Id---|" << setw(17) << "|------Name------|" << setw(17) << "|--Father name--|" << setw(12) << "|---State---|" << setw(13) << "|---Course---|" << setw(12) << "|--Duration--|" << setw(13) << "|----Fee----|" << endl;
                    cr.displayfile();
                    break;
                default:
                    cout << "Wrong choice" << endl;
                };
            };
        }
        break;
        case 'b':
        {
            int p;
            classRecord cr;
            system("cls");
            cout << a << a << a << a << a << a << a << a << a << " CLASS RECORD WINDOW " << a << a << a << a << a << a << a << a << a << endl;
            cout << "Enter 1 for data entry- " << endl
                 << "Enter 2 to searchcData- " << endl
                 << "Enter 3 to update data- " << endl
                 << "Enter 4 to go back to main menu- " << endl;

            bool swich = true;
            while (swich)
            {
                cout << "\nEnter option- ";
                cin >> p;
                switch (p)
                {
                case 1:
                    cr.D_getdata();
                    break;
                case 2:
                    int mid;
                    cout << "Enter id-";
                    cin >> mid;
                    cr.searchCData(mid);
                    break;
                case 3:
                    cr.D_update();
                    break;
                case 4:
                    swich = false;
                    goto flag1;
                    break;
                default:
                    cout << "Choose correct option " << endl;
                }
            }
        }
        break;
        case 'c':
            exit(0);
            break;
        default:
            cout << "Choose correct option- " << endl;
        } //*/

        getch();
    }
    return 0;
}
