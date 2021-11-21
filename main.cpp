#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main()
{
    head = NULL;
    fstream activeSessionRecord;

    int option;
    string id, name, birth, addr, gender, program, year;

    ClearFileContents(activeSessionRecord);

    do
    {
        ShowMenu();
        cin >> option;
        InputValidation();

        switch (option)
        {
        case 1:
        {
            activeSessionRecord.open("LastSessionRecord.txt", fstream::app);
            system("cls");

            cout << "Please accomplish the form below." << endl;
            cin.ignore();
            cout << "Student ID Number: ";
            getline(cin, id);
            cout << "Full Name (First, MI, Last): ";
            getline(cin, name);
            cout << "Birthday: ";
            getline(cin, birth);
            cout << "Address: ";
            getline(cin, addr);
            cout << "Gender: ";
            getline(cin, gender);
            cout << "Program: ";
            getline(cin, program);
            cout << "Year Level: ";
            getline(cin, year);

            NewRecord(id, name, birth, addr, gender, program, year);

            WriteToFile(activeSessionRecord, id, name, birth, addr, gender, program, year);

            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            int option;

            do
            {
                system("cls");
                cout << "What do you want to search by?" << endl;
                cout << "[1] Student ID Number" << endl;
                cout << "[2] Full Name" << endl;
                cout << "Please enter your choice: ";
                cin >> option;
                InputValidation();

                if (option == 1)
                {
                    cout << "Please enter the ID Number: ";
                    cin.ignore();
                    getline(cin, id);
                    system("cls");

                    SearchByID(id);
                    system("pause");
                }
                else if (option == 2)
                {
                    cout << "Please enter the full name (First, MI, Last): ";
                    cin.ignore();
                    getline(cin, name);
                    system("cls");

                    SearchByName(name);
                    system("pause");
                }
            } while (option != 1 && option != 2);
        }
        break;
        case 3:
        {
            DisplayAll();
            system("pause");
        }
        break;
        case 4:
        {
            int option;
            do
            {
                SpecificRecordsMenu();
                cin >> option;
                InputValidation();
            } while (option < 1 || option > 6);

            cout << "Please enter the student ID number: ";
            cin.ignore();
            getline(cin, id);

            SeachSpecificRecord(option, id);
            system("pause");
        }
        break;
        case 5:
        {
            cout << "Please enter the ID number that is to be deleted: ";
            cin.ignore();
            getline(cin, id);

            DeleteRecord(id);
            system("pause");
        }
        break;
        case 6:
        {
            ShowCredits();
        }
        break;
        }
    } while (option != 6);

    system("pause");
}