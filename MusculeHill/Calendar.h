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
//        std::string month[] = { "������","������?,"����","������","��?,"����","����","������","�������?,"��?��?,"�����?,"������? };
//        //��������?������?���� ��?�� ����?
//        // ?� ��������??��������? ��?�� ����?
//        std::cout << "                      " << name << std::endl << "__________________________________________________" << std::endl;
//        std::cout << "��\t��\t��\t��\t��\t��\t��" << std::endl;
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
