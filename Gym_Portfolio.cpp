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
void deleteMember();
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
    }
    //? Function to create members
    void createMember()
    {
        getData();
        saveMember();
        cout << "Register successfully" << endl << endl;
        cout << "Returning to the menu";
        loading();
    }
    //? Show data for displayRecord function
    void showData() {
        cout << "Member ID :" << id << endl;
        cout << "Member Name: " << name << endl;
        cout << "Member Contact: " << contact << endl;
        cout << "Member Subscription: " << subscription << " membership" << endl;
        cout << "Member payment: " << fee << " monthly"<< endl;
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
}

//? Delete function
void deleteMember() {
    readDatabase();
    string input;
    string inputPw;
    bool login = false;
    bool username = false;
    while (username == false) {
        clear();
        gymFunction.logo();
        cout << "[X] to go back to Main-Menu" << endl << endl;
        cout << "Enter username or id: ";
        cin >> input;
        if (input == "x" || input == "X") {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            mainMenu();
            break;
        }
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (input == gymInfo[i].id || input == gymInfo[i].name) {
                username = true;
                break;
            }
        }
        if (username == false) {
        cout << "User or Id is not correct, please try again";
        loading();
        }
    }
    while (login == false) {
        cout << "Enter password: ";
        cin >> inputPw;
        if (inputPw == "x" || inputPw == "X") {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            mainMenu();
            break;
        }
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (inputPw == gymInfo[i].pw) {
                login = true;
                break;
            }
        }
        if (login == false) {
        cout << "User or Id is not correct, please try again";
        loading();
        cout << endl;
        }
    }
    if (login == true) {
        fileTemp.open ("gymDatabaseTemp.txt", ios::app | ios::out);
        clear();
        gymFunction.logo();
        cout << endl;
        //? After reading database and placing all the info into vector we check to search for user info
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (gymInfo[i].name == input || gymInfo[i].id == input) {
                cout << "User found, we are deleting the membership";
                loading();
                cout << endl << endl;
                //? Remove object element from vector
                gymInfo.erase(gymInfo.begin()+i);
                for (int i = 0; i < gymInfo.size() - 1; i++) {
                    if (gymInfo[i].name != input || gymInfo[i].id != input) {
                        if (fileTemp.is_open()) {
                            fileTemp <<  gymInfo[i].id << " " << gymInfo[i].name << " " << gymInfo[i].contact << " " << gymInfo[i].subscription << " " << gymInfo[i].fee << " " << gymInfo[i].pw << endl;
                        }
                    }  
                }
                cout << "Membership delete sucessfully";
                loading();
                break;
            } 
        }
        fileTemp.close();
        remove("GymDatabase.txt");
        rename("GymDatabaseTemp.txt", "GymDatabase.txt");
    }
}

//? Modify function
void modifyMember() {
    readDatabase();
    string input;
    string inputPw;
    bool login = false;
    bool username = false;
    while (username == false) {
        clear();
        gymFunction.logo();
        cout << "[X] to go back to Main-Menu" << endl << endl;
        cout << "Enter username or id: ";
        cin >> input;
        if (input == "x" || input == "X") {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            mainMenu();
            break;
        }
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (input == gymInfo[i].id || input == gymInfo[i].name) {
                username = true;
                break;
            }
        }
        if (username == false) {
        cout << "User or Id is not correct, please try again";
        loading();
        }
    }
    while (login == false) {
        cout << "Enter password: ";
        cin >> inputPw;
        if (inputPw == "x" || inputPw == "X") {
            clear();
            cout << "Going back to Main-Menu";
            loading();
            clear();
            mainMenu();
            break;
        }
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (inputPw == gymInfo[i].pw) {
                login = true;
                break;
            }
        }
        if (login == false) {
        cout << "User or Id is not correct, please try again";
        loading();
        cout << endl;
        }
    }
    if (login == true) {
        fileTemp.open ("gymDatabaseTemp.txt", ios::app | ios::out);
        //? After reading database and placing all the info into vector we check to search for user info
        for (int i = 0; i < gymInfo.size() - 1; i++) {
            if (gymInfo[i].name == input || gymInfo[i].id == input) {
                cout << "User found, we are redirecting you to modification mode";
                loading();
                gymFunction.getData();
                fileTemp << gymFunction.gymId() << " " << gymFunction.gymName() << " " << gymFunction.gymContact() << " " << gymFunction.gymSub() << " "  << gymFunction.gymFee() << " "<< gymFunction.gymPw() << endl;
                //? Remove object element from vector
                gymInfo.erase(gymInfo.begin()+i);
                for (int i = 0; i < gymInfo.size() - 1; i++) {
                    if (gymInfo[i].name != input || gymInfo[i].id != input) {
                        if (fileTemp.is_open()) {
                            fileTemp <<  gymInfo[i].id << " " << gymInfo[i].name << " " << gymInfo[i].contact << " " << gymInfo[i].subscription << " " << gymInfo[i].fee << " " << gymInfo[i].pw << endl;
                        }
                    }  
                }
                cout << "Modification sucessfully" << endl << endl;
                system("pause");
                break;
            } 
        }
        fileTemp.close();
        remove("GymDatabase.txt");
        rename("GymDatabaseTemp.txt", "GymDatabase.txt");
    }
    //? Ask user to try again
    // if (found == false) {
    // cout << "ID or Username not found!" << endl;
    // cout << "\nDo you want to try again?" << endl;
    // cout << "[Y] Yes \t[N] No" << endl;
    // cout << "Your choice: ";
    // cin >> again;
    // cout << endl;
    // while (true) {
    //     if (again == "Y" || again == "y") {
    //         clear();
    //         searchMember();
    //         break;
    //     } else if (again == "N" || again == "n") {
    //         cout << "Going back to Menu";
    //         loading();
    //         break;
    //     }
    // }
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
    //? Ask user to try again
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
        cout << "[2] Search for a particular membership" << endl;
        cout << "[3] Edit your membership" << endl;
        cout << "[4] Delete your membership" << endl;
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
            searchMember();
            break;
        case '3':
            modifyMember();
            break;
        case '4':
            deleteMember();
            break;
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
    string username;
    string password;
    while (password != "adminadmin") {
    clear();
        cout << "**********************************" << endl;
        cout << "|GYM-MANAGEMENT SYSTEM ADMIN MODE|" << endl;
        cout << "**********************************" << endl;
        cout << "Enter username: ";
        cin >> username;
        if (username == "admin") {
            while (true) {
                cout << "\nEnter password: ";
                cin >> password;
                if (password == "adminadmin") {
                    // Do nothing
                    break;
                } else {
                    cout << "\nPassword is not correct";
                    Sleep(2000);
                    clear();
                }
            }
        } else {
            cout << "\nUsername is not correct";
            Sleep(2000);
        }
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ADD Login Feature later!!!
    char choice;
    while (choice != '1' || choice != '2' || choice != '3' || choice != '4' || choice != '5' || choice != 'b' || choice != 'B')
    {
        clear();
        cout << "**********************************" << endl;
        cout << "|GYM-MANAGEMENT SYSTEM ADMIN MODE|" << endl;
        cout << "**********************************" << endl;
        cout << "[1] Register GYM membership" << endl;
        cout << "[2] Search for a particular membership" << endl;
        cout << "[3] Edit membership" << endl;
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
            searchMember();
            break;
        case '3':
            modifyMember();
            break;
        case '4':
            gymFunction.displayRecord();
            break;
        case '5':
            deleteMember();
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
    string thank = "Thank you for using our program :)";
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
            for (char c : thank) {
                cout << c;
                Sleep(180);
            }
            exit(0);
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