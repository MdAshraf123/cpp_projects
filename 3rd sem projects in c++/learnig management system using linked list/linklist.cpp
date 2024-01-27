// nitinchoudhary3020@gmail.com
#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>
using namespace std;
struct node
{
    int id;
    char name[15];
    char roll[8];
    char course[5];
    int sem;
    float marks;
    float classAttend;
    struct node *next;
};

struct node *head = NULL;
node *createNode()
{
    node *ptr = new node;
    ptr->next = NULL;
    cout << "Enter student id- ";
    cin >> ptr->id;
    cout << "Enter student name-";
    cin >> ptr->name;
    cout << "Enter roll- ";
    cin >> ptr->roll;
    cout << "Enter course name- ";
    cin >> ptr->course;
    cout << "Enter sem- ";
    cin >> ptr->sem;
    cout << "Enter total obtained marks(out of 500)- ";
    cin >> ptr->marks;
    cout << "Enter class Attendence- ";
    cin >> ptr->classAttend;
    return ptr;
};
// to create a new node along with its data and insert it in the last
void setNode()
{
    if (head == NULL)
    {
        head = createNode();
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        };
        ptr->next = createNode();
    }
}
// to display data of all nodes
void display(node *ptr)
{
    cout << endl;
    cout << "_______________" << ptr->name << "'s data______________" << endl;
    cout << "Student id- " <<setw(23)<< ptr->id << endl;
    cout << "Student name- " <<setw(24)<< ptr->name << endl;
    cout << "Roll no.- " <<setw(28)<< ptr->roll << endl;
    cout << "Course- " << setw(27)<<ptr->course << endl;
    cout << "Semester- " <<setw(24)<< ptr->sem << endl;
    cout << "Obtained Marks(out of 500)- " <<setw(7)<< ptr->marks << endl;
    cout << "Percent- " <<setw(27)<< ptr->marks / 5 << " %" << endl;
    cout << "Class Attendence- " <<setw(16)<< ptr->classAttend << " %" << endl;

    if (ptr->classAttend < 75)
    {
        cout << "Exam status:-                   Not elegible for exam " << endl;
    }
    else
    {
        cout << "Exam status:-                  Elegible for exam " << endl;
    }
}
void traverse()
{
    cout << "-----------Student data ----------" << endl;
    node *ptr = head;
    while (ptr != NULL)
    {
        display(ptr);
        ptr = ptr->next;
    };
}
// to find the location of an element in the linklist
void searching()
{
    int a;
    node *ptr = head;
    cout << "Enter student id to search- ";
    cin >> a;
    while (ptr != NULL)
    {
        static int count;
        count++;
        if (ptr->id == a)
        {
            cout << "Record found at address of- " << ptr << endl
                 << count << "th node" << endl;
            display(ptr);
            break;
        }
        ptr = ptr->next;
    };
}
// to insert a node in the mid of the linklist
void insertBefore()
{
    int item;
    node *track = head, *preloc = NULL;
    node *ptr = createNode();
    cout << "Enter record id before which you have to insert it- ";
    cin >> item;

    while (track != NULL)
    {
        static int co = 0;
        if (track->id == item)
        {
            ptr->next = track;
            preloc->next = ptr;
            break;
        }
        co++;
        cout << co;
        preloc = track;
        track = track->next;
    }
}

void deleteNode()
{
    int id;
    node *prev = head, *curr = head;
    cout << "Enter record id- ";
    cin >> id;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            prev->next = curr->next;
            delete curr;
            cout << "* Deleted Successfully" << endl;
            cout << endl;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    int p = 1;
    ///--------- Reading Data from file and alongwith creating linkedlist------

    struct node obj;
    struct node *ptr = NULL;
    struct node *ptr1;
    ifstream ind("dsa.txt", ios::in);
    if (!ind.is_open())
    {
        cerr << "File did not open \n"
             << endl;
        return 0;
    }

    while (ind.read((char *)&obj, sizeof(obj)))
    {
        ptr = new struct node;
        *ptr = obj;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            ptr1 = head;
        }
        else
        {
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            };
            ptr1->next = ptr;
        }
    };
    ind.close();

    //-----end of file handling---
    while (p)
    {
        int choice;
        cout << "---------Option Dialog------------" << endl;
        cout << "Enter 1 to insert new record" << endl
             << "Enter 2 to display students record" << endl
             << "Enter 3 to search record" << endl
             << "Enter 4 to delete record" << endl
             << "Enter 5 to insert record in between the record" << endl
             << "Enter 6 to exit" << endl;
        cout << "Enter your choice- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            setNode();
            break;
        case 2:
            traverse();
            break;
        case 3:
            searching();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            insertBefore();
            break;
        case 6:
            p = 0;
            cout << "**********Thank You************";
            // exit(0);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    // writing all nodes in to the file
    {
        struct node *ptr2;
        ptr2 = head;
        ofstream out("dsa.txt", ios::out);
        while (ptr2 != NULL)
        {
            out.write((char *)&(*ptr2), sizeof(*ptr2));
            ptr2 = ptr2->next;
            // cout << "successfully writen\n";
        }
        out.close();
    }
    // end of writing in to file

    return 0;
}