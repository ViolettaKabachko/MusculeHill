#include "ClubMember.h"
#include"Coach.h"
#include"Calendar.h"
#include "DataBase.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


int main()
{
    srand((unsigned)time(NULL));
    short answer;
    string email;
    string password;
    ClubMember* cm = NULL;
    Coach* ch = NULL;
    DataBase* db = new DataBase();
    string name;
    string surname;
    int age = 0;
    int experience;
    char sex = 0;
    bool is_signed_in = false;
    bool main = true, running = true;
    int day, month, hour, minute;
    int choice;
    Class cl;
    vector<Date>::iterator iter;
    db->registrationCoach(
        "Gigachad",
        "Sigma",
        28,
        "g@s.com",
        "228",
        'M',
        1000,
        true
    );
    db->getCoachByEmail("g@s.com")->add_new_free_date(Date(2024, 5, 6, 13, 30));
    db->getCoachByEmail("g@s.com")->add_new_free_date(Date(2024, 6, 6, 14, 30));

    cout << "Welcome to MusculeHill! Log in or register if you don't have an account: " << endl;
    
    while (running) {
        // Вход и регистрация
        while (!is_signed_in && running) {
            cout << "1 - Sign In" << endl << "2 - Register" << endl;
            cin >> answer;

            switch (answer) {
            case 1:
                cout << "Enter the email: ";
                cin >> email;
                if (db->getEmailAmount(email) == 0) {
                    cout << "There is not such account" << endl;
                    break;
                }
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
                        cout << "Logged in successfully" << endl << endl;
                    }
                    else
                        cout << "Incorrect data" << endl;
                }
                catch (...) {
                    cout << "Error occurred" << endl;
                }
                break;
            case 2:
                cout << "Do you wanna register as club member or as coach? (1 - coach, 2 - member) " << endl;
                cin >> answer;
                while (answer != 1 && answer != 2) {
                    cout << "Repeat: ";
                    cin >> answer;
                }
                cout << "Name: ";
                cin >> name;

                cout << "Surname: ";
                cin >> surname;

                cout << "Age: ";
                cin >> age;
                while (age < 14 || age > 99) {
                    cout << "Repeat: ";
                    cin >> age;
                }

                cout << "Email: ";
                cin >> email;
                while (email.find("@") == std::string::npos) {
                    cout << "Repeat: ";
                    cin >> email;
                }

                cout << "Sex (M / W): ";
                cin >> sex;
                while (sex != 'M' && sex != 'W') {
                    cout << "Repeat: ";
                    cin >> sex;
                }

                cout << "Password: ";
                cin >> password;
                while (password.length() < 6) {
                    cout << "Password is too weak ";
                    cin >> password;
                }
                switch (answer) {
                case 1:
                    cout << "Experience: ";
                    cin >> experience;
                    while (experience < 3) {
                        cout << "Lack of experience, try another: ";
                        cin >> experience;
                    }
                    db->registrationCoach(name,
                        surname,
                        age,
                        email,
                        password,
                        sex,
                        experience, true);
                    break;
                case 2:
                    auto emails = db->getCoachesEmail();
                    db->registrationUser(name, surname, age, email, password, sex, false, emails[rand() % emails.size()]);
                    break;
                }
                cout << "Registered successefully" << endl << endl;
            default:
                running = false;
                break;
            }
        }

        //Основна часть
        while (is_signed_in) {
            vector<Date>* free_dates;
            cout << "Your profile: " << endl << endl;
            if (cm != NULL) {
                while (is_signed_in) {
                    cout << "1 - buy an abonement" << endl
                        << "2 - check planned classes" << endl
                        << "3 - plan new classes" << endl
                        << "4 - quit" << endl
                        << "Your choice: ";

                    cin >> answer;

                    switch (answer) {
                    case 1:
                        cm->setAbonement(true);
                        break;
                    case 2:
                        if (db->getClassesByEmail(cm->getEmail()).size() == 0) {
                            cout << "No plannes dates" << endl;
                        }
                        else {
                            for (Class cl : db->getClassesByEmail(cm->getEmail())) {
                                cout << "Coach: " << db->getCoachByEmail(cl.coach)->getFullName() << endl;
                                cout << "Date and time: " << cl.date.get_string() << endl;
                            }
                        }
                        break;
                    case 3:
                        free_dates = db->getCoachByEmail(cm->getCoach())->getFreeDates();
                        if (free_dates->size() == 0)
                            cout << "No free dates" << endl;
                        for (int i = 0; i < free_dates->size(); i++)
                            cout << i + 1 << " - " << free_dates->operator[](i).get_string() << endl;
                        cout << "Choose the date`s number or 0 for skip: ";
                        cin >> choice;
                        while (choice < 0 || choice > free_dates->size()) {
                            cout << "Repeat: ";
                            cin >> choice;
                        }
                        if (choice != 0) {
                            cl = Class(free_dates->operator[](choice - 1), cm->getCoach(), cm->getEmail());
                            db->addClass(cl);
                            iter = free_dates->begin();
                            for (int i = 0; i < choice - 1; i++)
                                iter++;
                            free_dates->erase(iter);
                        }
                        break;
                    case 4:
                        is_signed_in = false;
                        cm = NULL;
                        break;
                    default:
                        main = false;
                    }
                }
            }
            else {
                while (is_signed_in) {
                    cout << "1 - check planned classes" << endl
                        << "2 - add free dates" << endl
                        << "3 - check free dates" << endl
                        << "4 - quit" << endl
                        << "Your choice: ";

                    cin >> answer;
                    switch (answer) {
                    case 1:
                        if (db->getClassesByEmail(ch->getEmail()).size() == 0)
                            cout << "No plannes dates" << endl;
                        else {
                            for (Class cl : db->getClassesByEmail(ch->getEmail())) {
                                cout << "Client: " << db->getClubMemberByEmail(cl.member)->getFullName() << endl;
                                cout << "Date and time: " << cl.date.get_string() << endl;
                            }
                        }
                        break;
                    case 2:
                        cout << "Month: ";
                        cin >> month;
                        while (month < 1 || month > 12) {
                            cout << "Repeat: ";
                            cin >> month;
                        }

                        cout << "Day: ";
                        cin >> day;
                        while (day < 1 || day > 31) {
                            cout << "Repeat: ";
                            cin >> day;
                        }

                        cout << "Hour: ";
                        cin >> hour;
                        while (hour < 0 || hour > 23) {
                            cout << "Repeat: ";
                            cin >> hour;
                        }

                        cout << "Minute: ";
                        cin >> minute;
                        while (minute < 0 || minute > 23) {
                            cout << "Repeat: ";
                            cin >> minute;
                        }

                        ch->add_new_free_date(Date(2024, month, day, hour, minute));
                    case 3:
                        if (ch->getFreeDates()->size() == 0) {
                            cout << "No free dates" << endl;
                            break;
                        }

                        for (int i = 0; i < ch->getFreeDates()->size(); i++)
                            cout << i + 1 << " - " << ch->getFreeDates()->operator[](i).get_string() << endl;
                        break;
                    case 4:
                        is_signed_in = false;
                        ch = NULL;
                        break;
                    default:
                        main = false;
                    }
                }
            }
        }
    }
    
}


