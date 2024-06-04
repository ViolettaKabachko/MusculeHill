#include "ClubMember.h"
#include"Coach.h"
#include"Calendar.h"
#include "DataBase.h"
#include <string>
#include <iostream>
#include <time.h>
#include <functional>

using namespace std;

// -- сюда валидэйт
template <typename T>
inline void validate(T& var, function<bool(T)> condition, string message) {
	while (condition(var)) {
		std::cout << message;
		std::cin >> var;
	}
}

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
    vector<Class> classes;
    vector<Class>* classes_ptr;
    vector<Date>* dates;
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

				validate<short>(answer, [](short answer) {return answer != 1 && answer != 2; }, "Repeat: ");

                cout << "Name: ";
                cin >> name;

                cout << "Surname: ";
                cin >> surname;

                cout << "Age: ";
                cin >> age;

				validate<int>(age, [](int age) {return age < 14 || age > 99; }, "Repeat: ");

                cout << "Email: ";
                cin >> email;

				validate<string>(email, [](string email) {return email.find("@") == std::string::npos; }, "Repeat: ");

                cout << "Sex (M / W): ";
                cin >> sex;

				validate<char>(sex, [](char sex) {return sex != 'M' && sex != 'W'; }, "Repeat: ");


                cout << "Password: ";
                cin >> password;

				validate<string>(password, [](string password) {return password.length() < 6; }, "Password is too weak");

                switch (answer) {
                case 1:
                    cout << "Experience: ";
                    cin >> experience;

					validate<int>(experience, [](int experience) {return  experience < 3; }, "Lack of experience try another");

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
                break;
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
                        cout << "Abonement is bought" << endl << endl;
                        break;
                    case 2:
                        if (db->getClassesByEmail(cm->getEmail()).size() == 0) {
                            cout << "No plannes dates" << endl;
                        }
                        else {
                            classes = db->getClassesByEmail(cm->getEmail());
                            classes_ptr = db->getClasses();
                            for (int i = 0; i < classes.size(); i++) {
                                cout << "-----------" << endl;
                                cout << i + 1 << endl;
                                cout << "Coach: " << db->getCoachByEmail(classes[i].coach)->getFullName() << endl;
                                cout << "Date and time: " << classes[i].date.get_string() << endl;
                                cout << "-----------" << endl;
                            }
                            
                            cout << "Which class do you want to visit? (0 - to skip) ";
                            cin >> answer;
                            validate<short>(answer, [=](short an) {return answer < 0 || answer > classes.size(); }, "Repeat: ");
                            if (answer == 0)
                                break;
                            for (int i = 0; i < classes_ptr->size(); i++) {
                                if (classes_ptr->operator[](i).coach == classes[answer - 1].coach &&
                                    classes_ptr->operator[](i).date == classes[answer - 1].date
                                    && classes_ptr->operator[](i).member == classes[answer - 1].member)
                                    classes_ptr->operator[](i).status = Attended;
                            }
                        }
                        break;
                    case 3:
                        free_dates = db->getCoachByEmail(cm->getCoach())->getFreeDates();
                        if (free_dates->size() == 0)
                            cout << "No free dates" << endl;
                        for (int i = 0; i < free_dates->size(); i++)
                            cout << i + 1 << " - " << free_dates->operator[](i).get_string() << endl;
                        cout << "Choose the date`s number (0 to skip): ";
                        cin >> choice;

						validate<int>(choice, [=](int choice) {return choice < 0 || choice > free_dates->size(); }, "Repeat: ");

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
                        << "2 - check free dates" << endl
                        << "3 - add free dates" << endl 
                        << "4 - delete free dates" << endl
                        << "5 - quit" << endl
                        << "Your choice: ";

                    cin >> answer;
                    switch (answer) {
                    case 1:
                        if (db->getClassesByEmail(ch->getEmail()).size() == 0)
                            cout << "No plannes dates" << endl;
                        else {
                            for (Class cl : db->getClassesByEmail(ch->getEmail())) {
                                cout << "------" << endl;
                                cout << "Client: " << db->getClubMemberByEmail(cl.member)->getFullName() << endl;
                                cout << "Date and time: " << cl.date.get_string() << endl;
                                cout << "------" << endl;
                            }
                        }
                        break;
                    case 2:
                        if (ch->getFreeDates()->size() == 0) {
                            cout << "No free dates" << endl << endl;
                            break;
                        }

                        for (int i = 0; i < ch->getFreeDates()->size(); i++)
                            cout << i + 1 << " - " << ch->getFreeDates()->operator[](i).get_string() << endl;
                        break;
                    case 3:
                        cout << "Month: ";
                        cin >> month;

						validate<int>(month, [](int month) {return month < 1 || month > 12; }, "Repeat: ");


                        cout << "Day: ";
                        cin >> day;

						validate<int>(day, [](int day) {return day < 1 || day > 31; }, "Repeat: ");


                        cout << "Hour: ";
                        cin >> hour;

						validate<int>(hour, [](int hour) {return hour < 0 || hour > 23; }, "Repeat: ");


                        cout << "Minute: ";
                        cin >> minute;

						validate<int>(minute, [](int minute) {return minute < 0 || minute > 60; }, "Repeat: ");


                        ch->add_new_free_date(Date(2024, month, day, hour, minute));
                        break;
                   
                    case 4:
                        if (ch->getFreeDates()->size() == 0) {
                            cout << "No free dates" << endl << endl;
                            break;
                        }
                        
                        dates = ch->getFreeDates();
                        for (int i = 0; i < dates->size(); i++)
                            cout << i + 1 << " - " << dates->operator[](i).get_string() << endl;
                        cout << "Which one to delete? ";
                        cin >> answer;
                        validate<short>(answer, [=](short an) {return an < 0 || an > dates->size();}, "Repeat: ");
                        iter = dates->begin();
                        for (int i = 0; i < answer - 1; i++)
                            iter++;
                        dates->erase(iter);
                        break;
                    case 5:
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


