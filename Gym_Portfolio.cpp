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
    string name;
    int contact;
    string subcription;
    string time;
    string pw;

    //! Function to return variable value in struct
    int id() {
        return id;
    }
    string name() {
        return name;
    }
    //? Use for user pw validation
    string pw() {
        return pw;
    }
    //!!!!!!!!!!!!!!! End of returning variable function !!!!!!!!!!!!!!!!!!!!!!!
    //? GYM LOGO on top
    void logo() {
        clear();
        cout << "********************************" << endl;
        cout << "|GYM-MANGEMENT SYSTEM USER MODE|" << endl;
        cout << "********************************" << endl;
    }
    //? Function to create memembers
    void createMemember() {
        logo();
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Contact: ";
        cin >> contact;
        cout << "Enter Subscription: ";
        cin >> id;
        cout << "Enter Time: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pw;
    }
};

//? User Menu
void userMenu() {
    string choiceInput;
    char choice;
    while (choice != '1' || choice != '2' || choice != '3' || choice != 'b' || choice != 'B' )
    {
        clear();
        cout << "********************************" << endl;
        cout << "|GYM-MANGEMENT SYSTEM USER MODE|" << endl;
        cout << "********************************" << endl;
        cout << "[1] Register GYM membership" << endl;
        cout << "[2] Edit your membership" << endl;
        cout << "[3] Delete your membership" << endl;
        cout << "[B] Go back to Main-Menu" << endl;
        cout << endl;
        cout << "Your choice: ";
        //? This will get only the first character the user enter
        getline(cin, choiceInput);
        if (choiceInput.size() == 1) {
            choice = choiceInput[0];
        }
        if (choice == 'b' || choice == 'B')
        {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            break;
        } 
        switch (choice) {
            case '1': 
                
                break;
            case '2': 
                break;
            case '3': 
                break;
            default:
                cout << "\nPlease try again";
                loading();
                clear();
        }
    }
}

//? Admin Menu
void adminMenu() {
    clear();
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADD Login Feature later!!!
    string choiceInput;
    char choice;
    while (choice != '1' || choice != '2' || choice != '3' || choice != '4' || choice != '5' || choice != 'b' || choice != 'B' )
    {
        clear();
        cout << "*********************************" << endl;
        cout << "|GYM-MANGEMENT SYSTEM ADMIN MODE|" << endl;
        cout << "*********************************" << endl;
        cout << "[1] Register GYM membership" << endl;
        cout << "[2] Edit membership" << endl;
        cout << "[3] Search for a particular membership" << endl;
        cout << "[4] Display all memberships" << endl;
        cout << "[5] Delete membership" << endl;
        cout << "[B] Go back to Main-Menu" << endl;
        cout << endl;
        cout << "Your choice: ";
        //? This will get only the first character the user enter
        getline(cin, choiceInput);
        if (choiceInput.size() == 1) {
            choice = choiceInput[0];
        }
        if (choice == 'b' || choice == 'B')
        {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            break;
        } 
        switch (choice) {
            case '1': 
                break;
            case '2': 
                break;
            case '3': 
                break;
            case '4': 
                break;
            case '5': 
                break;
            default:
                cout << "\nPlease try again";
                loading();
                clear();
        }
    }
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
        //? This will get only the first character the user enter
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