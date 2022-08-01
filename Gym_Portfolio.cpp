//! CS-126 Final-year project by Seakmeng Hor and Bunlong Prak
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
using namespace std;

#define maxx 50
//? Function to clear console
void clear() {
    system("cls");
}

//? Loading to make it cool
void loading() {
    for (int i = 0; i <= 5; i++) {
        cout << ".";
        Sleep(300);
    }
}

//? Struct of user info it has {id, name, contact, subcription, time, pw}
struct gym {
    //? Declare of user infos in order to collect and store
    int id;
    char name;
    int contact;
    string subcription;
    string time;
    string pw;

    //? Function to create memembers
    void createMemember() {
        
    }
};

//? User Menu
void userMenu() {
    clear();
    cout << "Hello";
    Sleep(5000);
}

//? Admin Menu
void adminMenu() {
    clear();
    cout << "Hello";
    Sleep(5000);
}

//? Main Menu when start
void mainMenu() {
    string choiceInput;
    char choice;
    while (choice != '1' || choice != '2' || choice != 'x' || choice != 'X' )
    {
        clear();
        cout << "**********************" << endl;
        cout << "|GYM-MANGEMENT SYSTEM|" << endl;
        cout << "**********************" << endl;
        cout << "[1] User Mode" << endl;
        cout << "[2] Admin Mode" << endl;
        cout << "[X] Exit" << endl;
        cout << endl;
        cout << "Your choice: ";
        //! This will get only the first letter the user enter
        getline(cin, choiceInput);
        if (choiceInput.size() == 1) {
            choice = choiceInput[0];
        }
        if (choice == 'x' || choice == 'X')
        {
            clear();
            cout << "Exiting";
            loading();
            clear();
            cout << "Thank you for using our program :)";
            break;
        } 
        switch (choice) {
            case '1': 
                userMenu();
                break;
            case '2': 
                adminMenu();
                break;
            default:
                cout << "\nPlease try again";
                loading();
                clear();
        }
    }
}

int main() {
    vector <gym> gymInfo;
    mainMenu();
    return 0;
}