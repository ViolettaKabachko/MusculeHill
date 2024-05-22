
#include "ClubMember.h"
#include"Coach.h"
#include"Calendar.h"
#include "DataBase.h"
#include <iostream>

int main(){


    setlocale(LC_ALL, "Russian");

    ClubMember user1("Slava", "Chkalov", 17, "bibizian@gmail.com", "1010", 'M', true);
    ClubMember user2("Ksusha", "Belova", 18, "fitonya@mail.ru", "1290", 'W', true);
    ClubMember user3("Dmitriy", "Shtirlitz", 24, "pashalko@yandex.ru", "1488", 'M', true);
    ClubMember user4("Vladislav", "Chernenko", 34, "skuffchik@gmail.com", "9473", 'M', true);
    ClubMember user5("Olya", "Kotova", 23, "olya2001@gmail.com", "8888", 'W', true);
    
    DataBase base;
    base.registrationCoach("Zaza", "Zazovna", 55, "zazochka@gmail.com", "148856", 'W', 1489, true);
    base.registrationUser("Zazina", "Zazinova", 55, "zazinochka@gmail.com", "149856", 'W', true);

    if (base.signIN("zazinochka@gmail.com", "14986")) {
        std::cout << "successfull signin" << std::endl;
    }
    else {
        std::cout << "account not registered" << std::endl;
    }

    //TODO: прототип календаря надо довести до ума вид и автоматизировать его фул
    
    /*int b;
    std::cout << "Введите с какого дня недели начинается Май (1-7 = пн-вс):";
    std::cin >> b;
    std::cout << std::endl;
    Calendar calendar;

    calendar.countMonth(b, 31, "Май");*/
}


