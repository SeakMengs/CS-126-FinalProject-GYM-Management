//! CS-126 Final-year project by Seakmeng Hor and Bunlong Prak
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <windows.h>
using namespace std;

//? Function declaration
void readDatabase();
void mainMenu();
void userMenu();
void adminMenu();
void saveMember();
void showData();
void displayMember();
void searchMember();
void modifyMember();
//! End of Function declaration;
fstream file, fileTemp;
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

//? Struct of user info it has {id, name, contact, subscription, time, pw}
class gym
{
    //? Make function public in order to use function outside of class
    public:
    //? Declare of user infos in order to collect and store
    string id;
    string name;
    string contact;
    string subscription;
    // string time;
    string fee;
    string pw;

    //! Function to return variable value in struct
    string gymId()
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
    string gymContact() {
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
        cout << "|GYM-MANAGEMENT SYSTEM USER MODE|" << endl;
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
    //? Function to create members
    void createMember()
    {
        getData();
    }
    //? Show data for displayRecord function
    void showData() {
        cout << "Member ID :" << id << endl;
        cout << "Member Name: " << name << endl;
        cout << "Member Contact: " << contact << endl;
        cout << "Member Subscription: " << subscription << " membership" << endl;
        cout << "Member payment: " << fee << " monthly"<< endl;
        cout << "Member Password: " << pw << endl;
        cout << endl;
    }
    //? Display record
    void displayRecord() {
        int count = 1;
        logo();
        file.open("GymDatabase.txt", ios::in);
        if (!file) {
            cout << "No data present" << endl << endl;
            loading();
        } else {
            //? from the end of file
            file.seekg(0, ios::end);  
            //? Check if file is empty
            if (file.tellg() == 0) {    
                cout << "No data present" << endl;
            } else {
            //? from the beginning of file
            file.seekg(0, ios::beg);
            //? if not end of file continue writing the output
            while (!file.eof()) {
                file >> id >> name >> contact >> subscription  >> fee >> pw;
                cout << "Member No.: " << count++ << endl;
                showData();
            }
            }
        }
        file.close();
        cout << endl;
        system("pause");
    }
    // void modifyMember() {
    //     bool found = false;
    //     string input;
    //     logo();
    //     file.open("GymDatabase.txt", ios::in);
    //     if (!file) {
    //         cout << "No data present" << endl << endl;
    //         loading();
    //     } else {
    //         cout << "Enter ID or Username:  ";
    //         cin >> input;
    //         fileTemp.open("GymDatabaseTemp.txt", ios::app | ios::out);
    //         file >> id >> name >> contact >> subscription  >> fee >> pw;
    //         //? if not end of file and have not found the id, continue the loop
    //         while(!file.eof() & found == false) {
    //             if (input != name || input != id) {
    //                 file << id << name << contact << subscription  << fee << pw;
    //             } else {
    //                 getData();
    //                 fileTemp >> id >> name >> contact >> subscription  >> fee >> pw;
    //                 found = true;
    //             }
    //         }
    //         file >> id >> name >> contact >> subscription  >> fee >> pw;
    //         if (found == false) {
    //             cout << "\nNo memberships found";
    //             loading();
    //             cout << "\n\n";
    //         }
    //         file.close();
    //         fileTemp.close();
    //         // remove("GymDatabase.txt");
    //         rename("GymDatabaseTemp.txt", "GymDatabase.txt");
    //         system("pause");
    //     }
    // }
};
//!!!!!!! End of Class !!!!!!!!!
//? delcare a vector to store info
vector<gym> gymInfo;
gym gymFunction;

//? Read from database and bring it into vector of gymInfo
void readDatabase() {
    //? Clear all elements of vector before read it from file
    gymInfo.clear();
    string idRead, nameRead, contactRead, subcriptionRead, feeRead, pwRead;
    file.open("GymDatabase.txt", ios::in);
    if (file.is_open()) {
    while (!file.eof()) {
        //? Read from file and place it in vector of gymInfo
        file >>  idRead >> nameRead >> contactRead >> subcriptionRead >> feeRead >> pwRead;
        gymInfo.emplace_back() = {idRead, nameRead, contactRead, subcriptionRead, feeRead, pwRead};
    }
    }
    file.close();
    //! For debugging do not delete
    // cout << "Size: " << gymInfo.size() << endl; 
    // for (int i = 0; i < gymInfo.size() - 1; i++) {
    //         cout << "Member ID: " << gymInfo[i].id << endl;
    //         cout << "Member Name: " << gymInfo[i].name << endl;
    //         cout << "Member Contact: " << gymInfo[i].contact << endl;
    //         cout << "Member Subscription: " << gymInfo[i].subscription << endl;
    //         cout << "Member payment: " << gymInfo[i].fee << endl;
    //         cout << "Member Password: " << gymInfo[i].pw << endl;
    //         cout << endl;
    // }
}

//? Search function
void searchMember() {
    readDatabase();
    string input;
    bool found = false;
    string again;
    gymFunction.logo();
    cout << "Enter ID or Username: ";
    cin >> input;
    cout << endl;
    //? After reading database and placing all the info into vector we check to search for user info
    for (int i = 0; i < gymInfo.size() - 1; i++) {
        if (gymInfo[i].name == input || gymInfo[i].id == input) {
            cout << "Member ID: " << gymInfo[i].id << endl;
            cout << "Member Name: " << gymInfo[i].name << endl;
            cout << "Member Contact: " << gymInfo[i].contact << endl;
            cout << "Member Subscription: " << gymInfo[i].subscription  << " membership" << endl;
            cout << "Member payment: " << gymInfo[i].fee << " monthly"<< endl;
            //? We do not want to show password here
            // cout << "Member Password: " << gymInfo[i].pw << endl;
            cout << endl;
            found = true;
            system("pause");
            break;
        }
    } 
    if (found == false) {
    cout << "ID or Username not found!" << endl;
    cout << "\nDo you want to try again?" << endl;
    cout << "[Y] Yes \t[N] No" << endl;
    cout << "Your choice: ";
    cin >> again;
    cout << endl;
    while (true) {
        if (again == "Y" || again == "y") {
            clear();
            searchMember();
            break;
        } else if (again == "N" || again == "n") {
            cout << "Going back to Menu";
            loading();
            adminMenu();
            break;
        }
    }
    }
}

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
        cout << "*********************************" << endl;
        cout << "|GYM-MANAGEMENT SYSTEM USER MODE|" << endl;
        cout << "*********************************" << endl;
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
        cout << "**********************************" << endl;
        cout << "|GYM-MANAGEMENT SYSTEM ADMIN MODE|" << endl;
        cout << "**********************************" << endl;
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
            gymFunction.createMember();
            break;
        case '2':
            // gymFunction.modifyMember();
            break;
        case '3':
            searchMember();
            break;
        case '4':
            gymFunction.displayRecord();
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
        cout << "***********************" << endl;
        cout << "|GYM-MANAGEMENT SYSTEM|" << endl;
        cout << "***********************" << endl;
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
    mainMenu();
    return 0;
}