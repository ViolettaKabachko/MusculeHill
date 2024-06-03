#include "ClubMember.h"
#include"Coach.h"
#include"Calendar.h"
#include "DataBase.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
    short answer;
    string email, password;
    ClubMember* cm;
    Coach* ch;
    DataBase* db = new DataBase();
    bool is_signed_in = false;

    cout << "Welcome to MusculeHill! Log in or register if you don't have an account: " << endl;
    cout << "1 - Sign In" << endl << "2 - Register" << endl;
    cin >> answer;
    while (!(answer == 1 || answer == 2)) {
        cout << "Repeat: ";
        cin >> answer;
    }

    while (!is_signed_in) {
        switch (answer) {
        case 1:
            cout << "Enter the email: ";
            cin >> email;
            cout << "Enter the password: ";
            cin >> password;

            try {
                bool signInRes = db->signIn(email, password);
                if (signInRes) {
                    if (db->getClubMemberByEmail(email) != NULL)
                        cm = db->getClubMemberByEmail(email);
                    else
                        ch = db->getCoachByEmail(email);
                    is_signed_in = true;
                }
                else
                    cout << "Incorrect data" << endl;
            }
            catch (...) {
                cout << "Error occurred" << endl;
            }
            break;

        }
    }
    
}


