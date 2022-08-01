//! CS-126 Final-year project by Seakmeng Hor and Bunlong Prak
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define maxx 50
//? Function to clear console
void clear() {
    system("cls");
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

int main() {
    vector <gym> gymInfo;
    return 0;
}