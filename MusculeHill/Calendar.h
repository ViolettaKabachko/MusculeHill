//#pragma once
//#include <iostream>
//#include <cstring>
//#include <vector>
//
//class Calendar {
//protected:
//	std::string record;
//public:
//
//	bool takeRecordForTraining() {
//
//	}
//
//    int countMonth(int startDay, int daysNumber, std::string name) {
//        std::string month[] = { "Январь","Феврал?,"Март","Апрель","Ма?,"Июнь","Июль","Август","Сентябр?,"Ок?бр?,"Ноябр?,"Декабр? };
//        //получени?текуще?даты гд?то здес?
//        // ?её сравнени??имеющими? гд?то здес?
//        std::cout << "                      " << name << std::endl << "__________________________________________________" << std::endl;
//        std::cout << "Пн\tВт\tСр\tЧт\tПт\tСб\tВс" << std::endl;
//        for (int i = 1; i < startDay; i++)
//            std::cout << "\t";
//        for (int i = 1; i <= daysNumber; i++)
//        {
//            std::cout << i << "\t";
//            if ((startDay + i) % 7 == 1)
//                std::cout <<std:: endl;
//        }
//        std::cout << std::endl;
//        std::cout <<std:: endl;
//        startDay = (startDay + daysNumber) % 7;
//        if (startDay == 0)
//            startDay = 7;
//        return startDay;
//    }
//};
