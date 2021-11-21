#include <iostream>
#include <fstream>

using namespace std;

class Node
{
public:
    string StudentID;
    string Name;
    string Birthday;
    string Address;
    string Gender;
    string Program;
    string YearLevel;
    Node *Next;
};

Node *head = new Node();

void ShowMenu()
{
    system("cls");
    cout << "1. Add new record" << endl;
    cout << "2. Search record" << endl;
    cout << "3. Display all record" << endl;
    cout << "4. Display specific record" << endl;
    cout << "5. Delete record" << endl;
    cout << "6. Quit program" << endl;
    cout << "Please enter your choice: ";
}

void NewRecord(string id, string name, string birth, string addr, string gender, string program, string year)
{
    Node *newNode = new Node();
    newNode->StudentID = id;
    newNode->Name = name;
    newNode->Birthday = birth;
    newNode->Address = addr;
    newNode->Gender = gender;
    newNode->Program = program;
    newNode->YearLevel = year;
    newNode->Next = NULL;

    if (head == NULL)
    {
        newNode->Next = head;
        head = newNode;
    }
    else
    {
        Node *currentNode = head;
        while (currentNode->Next != NULL)
        {
            currentNode = currentNode->Next;
        }
        newNode->Next = currentNode->Next;
        currentNode->Next = newNode;
    }
    cout << "New record created successfully." << endl;
}

void ClearFileContents(fstream &filestream)
{
    filestream.open("LastSessionRecord.txt", fstream::out | fstream::trunc);
    filestream.close();
}

void WriteToFile(fstream &filestream, string id, string name, string birth, string addr, string gender, string program, string year)
{
    if (filestream.is_open())
    {
        filestream << "Student ID Number: " << id << endl;
        filestream << "Full Name: " << name << endl;
        filestream << "Birthday: " << birth << endl;
        filestream << "Address: " << addr << endl;
        filestream << "Gender: " << gender << endl;
        filestream << "Program: " << program << endl;
        filestream << "Year Level: " << year << endl;
        filestream << endl;
        filestream.close();
    }
    else
    {
        cout << "No such file was created." << endl;
    }
}

void SearchByID(string id)
{
    if (head == NULL)
    {
        cout << "Sorry, record not found." << endl;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->StudentID == id)
            {
                cout << "Student ID Number: " << temp->StudentID << endl;
                cout << "Full Name: " << temp->Name << endl;
                cout << "Birthday: " << temp->Birthday << endl;
                cout << "Address: " << temp->Address << endl;
                cout << "Gender: " << temp->Gender << endl;
                cout << "Program: " << temp->Program << endl;
                cout << "Year Level: " << temp->YearLevel << endl;
                return;
            }
            temp = temp->Next;
        }

        if (temp == NULL)
        {
            cout << "Sorry, record not found." << endl;
        }
    }
}

void SearchByName(string name)
{
    if (head == NULL)
    {
        cout << "Sorry, record not found." << endl;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->Name == name)
            {
                cout << "Student ID Number: " << temp->StudentID << endl;
                cout << "Full Name: " << temp->Name << endl;
                cout << "Birthday: " << temp->Birthday << endl;
                cout << "Address: " << temp->Address << endl;
                cout << "Gender: " << temp->Gender << endl;
                cout << "Program: " << temp->Program << endl;
                cout << "Year Level: " << temp->YearLevel << endl;
                return;
            }
            temp = temp->Next;
        }

        if (temp == NULL)
        {
            cout << "Sorry, record not found." << endl;
        }
    }
}

void DisplayAll()
{
    system("cls");
    Node *p = head;

    if (p == NULL)
    {
        cout << "No exisitng record from active session." << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << "Student ID Number: " << p->StudentID << endl;
            cout << "Full Name: " << p->Name << endl;
            cout << "Birthday: " << p->Birthday << endl;
            cout << "Address: " << p->Address << endl;
            cout << "Gender: " << p->Gender << endl;
            cout << "Program: " << p->Program << endl;
            cout << "Year Level: " << p->YearLevel << endl;
            cout << endl;

            p = p->Next;
        }
    }
}

void InputValidation()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
}

void SpecificRecordsMenu()
{
    system("cls");
    cout << "What record do you want to see?" << endl;
    cout << "[1] - Full Name" << endl;
    cout << "[2] - Birthday" << endl;
    cout << "[3] - Address" << endl;
    cout << "[4] - Gender" << endl;
    cout << "[5] - Program" << endl;
    cout << "[6] - Year Level" << endl;
    cout << "Please enter your selection here: ";
}

void SeachSpecificRecord(int option, string id)
{
    system("cls");
    if (head == NULL)
    {
        cout << "Sorry, record not found." << endl;
    }
    else
    {
        Node *temp = head;
        while (temp)
        {
            if (option == 1)
            {
                if (temp->StudentID == id)
                {
                    cout << "Full Name: " << temp->Name << endl;
                    return;
                }
            }
            else if (option == 2)
            {
                if (temp->StudentID == id)
                {
                    cout << "Birthday: " << temp->Birthday << endl;
                    return;
                }
            }
            else if (option == 3)
            {
                if (temp->StudentID == id)
                {
                    cout << "Address: " << temp->Address << endl;
                    return;
                }
            }
            else if (option == 4)
            {
                if (temp->StudentID == id)
                {
                    cout << "Gender: " << temp->Gender << endl;
                    return;
                }
            }
            else if (option == 5)
            {
                if (temp->StudentID == id)
                {
                    cout << "Program: " << temp->Program << endl;
                    return;
                }
            }
            else if (option == 6)
            {
                if (temp->StudentID == id)
                {
                    cout << "Year Level: " << temp->YearLevel << endl;
                    return;
                }
            }

            temp = temp->Next;
        }
        if (temp == NULL)
        {
            cout << "Sorry, record not found." << endl;
        }
    }
}

void DeleteRecord(string id)
{
    system("cls");

    Node *temp = head;
    Node *current = NULL;

    if (temp != NULL) // Deletion at the beginning
    {
        head = temp->Next;
        delete temp;

        cout << "Successfully deleted the record." << endl;
        return;
    }

    while (temp != NULL)
    {
        current = temp;
        temp = temp->Next;

        if (temp == NULL)
        {
            cout << "Sorry, record not found." << endl;
            current->Next = temp->Next;
            return;

            delete temp;
            cout << "Successfully deleted the record." << endl;
            return;
        }
    }
}

void ShowCredits()
{
    system("cls");
    cout << "###############################" << endl;
    cout << "####    CCS0007L FINALS    ####" << endl;
    cout << "###############################" << endl;
    cout << endl;

    cout << "Final Project for CCS0007L" << endl;
    cout << "Created by: Jejomar P. Cariaga" << endl;
    cout << "Instructor: Engr. John Benedic Enriquez" << endl;
    cout << endl;
}