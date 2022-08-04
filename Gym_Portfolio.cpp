//! CS-126 Final-year project by Seakmeng Hor and Bunlong Prak,hello meng
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <windows.h>
using namespace std;

//? Function declaration
void mainMenu();
void userMenu();
void adminMenu();
void saveMember();
//! End of Function declaration;
fstream file;
#define maxx 50
//? Function to clear console
void clear()
{
    system("cls");
}

//? Loading to make it cool
void loading()
{
    for (int i = 0; i <= 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
}

//? Struct of user info it has {id, name, contact, subcription, time, pw}
class gym
{
    //? Declare of user infos in order to collect and store
    int id;
    string name;
    int contact;
    string subscription;
    // string time;
    string pw;
    string fee;

    //? Make function public in order to use function outside of class
    public:
    //! Function to return variable value in struct
    int gymId()
    {
        return id;
    }
    string gymName()
    {
        return name;
    }
    //? Use for user pw validation
    string gymPw()
    {
        return pw;
    }
    int gymContact() {
        return contact;
    }
    string gymSub() {
        return subscription;
    }
    string gymFee() {
        return fee;
    }
    //!!!!!!!!!!!!!!! End of returning variable function !!!!!!!!!!!!!!!!!!!!!!!
    //? GYM LOGO on top
    void logo()
    {
        clear();
        cout << "********************************" << endl;
        cout << "|GYM-MANGEMENT SYSTEM USER MODE|" << endl;
        cout << "********************************" << endl;
    }
    //? Function to choose subscription
    void gymSubscription()
    {
        char choice;
        while (choice != '1' || choice != '2' || choice != '3')
        {
        subAgain:
            cout << "Choose membership subscription" << endl;
            cout << "[1] Diamond Membership" << endl;
            cout << "[2] Gold Membership" << endl;
            cout << "[3] Bronze Membership" << endl;
            cout << "Enter choice: ";
            //? This will get only the first character the user enter
            cin >> choice;
            switch (choice)
            {
            case '1':
                subscription = "Diamond";
                fee = "$40";
                break;
            case '2':
                subscription = "Gold";
                fee = "$25";
                break;
            case '3':
                subscription = "Bronze";
                fee = "$15";
                break;
            default:
                cout << "\nPlease try again";
                loading();
                cout << "\n\n";
                goto subAgain;
            }
            break;
        }
    }
    //? Get data from user
    void getData()
    {
        logo();
        cout << "Enter ID: ";
        cin >> id;
        cout << "\n\n";
        cout << "Enter Name: ";
        cin >> name;
        cout << "\n\n";
        cout << "Enter Contact: ";
        cin >> contact;
        cout << "\n\n";
        gymSubscription();
        cout << "\n\n";
        cout << "Enter Password: ";
        cin >> pw;
        cout << "\n";
        saveMember();
        cout << "Returning to the menu";
        loading();
    }
    //? Function to create memembers
    void createMember()
    {
        getData();
    }
};
//!!!!!!! End of Class !!!!!!!!!
//? delcare a vector to store info
vector<gym> gymInfo;
gym gymFunction;

//? make this  function to save member in admin menu without writing more code
void saveMember() {
    file.open("GymDatabase.txt", ios::app | ios::out);
    file << gymFunction.gymId() << " " << gymFunction.gymName() << " " << gymFunction.gymContact() << " " << gymFunction.gymSub() << " "  << gymFunction.gymFee() << " "<< gymFunction.gymPw() << endl;
    file.close();
    cout << "Register successfully" << endl << endl;
}

//? User Menu
void userMenu()
{
    char choice;
    while (choice != '1' || choice != '2' || choice != '3' || choice != 'b' || choice != 'B')
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
        cin >> choice;
        if (choice == 'b' || choice == 'B')
        {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            break;
        }
        switch (choice)
        {
        case '1':
            gymFunction.createMember();
            break;
        // case '2':
        //     break;
        // case '3':
        //     break;
        default:
            cout << "\nPlease try again";
            loading();
            clear();
            break;
        }
    }
}

//? Admin Menu
void adminMenu()
{
    clear();
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADD Login Feature later!!!
    char choice;
    while (choice != '1' || choice != '2' || choice != '3' || choice != '4' || choice != '5' || choice != 'b' || choice != 'B')
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
        cin >> choice;
        if (choice == 'b' || choice == 'B')
        {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            break;
        }
        switch (choice)
        {
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
void mainMenu()
{
    char choice;
    while (choice != '1' || choice != '2' || choice != 'x' || choice != 'X')
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
        cin >> choice;
        if (choice == 'x' || choice == 'X')
        {
            clear();
            cout << "Exiting";
            loading();
            clear();
            cout << "Thank you for using our program :)";
            break;
        }
        switch (choice)
        {
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

int main()
{
    vector<gym> gymInfo;
    mainMenu();
    return 0;
}