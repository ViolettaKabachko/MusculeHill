#include <map>
#include <vector>
#include <string>
#include "ClubMember.h"
#include <iostream>

class DataBase {
private:
	std::map<std::string, ClubMember> User;
	std::map<std::string, std::vector<Date>> Date;
	int member_amount = 0;
public:
	void registrationCoach(std::string name, std::string surname, int age, std::string email, std::string password, char sex, int expirience) {
		if (expirience > 1488) {
			if (age < 14 || age > 99) {
				throw new std::exception("zazanulsya");
			}

			size_t pos = email.find("@");
			if (pos == std::string::npos) {
				throw new std::exception("zazanulsya");
			}

			if (sex != 'M' || sex != "W") {
				throw new std::exception("zazanulsya");
			}

			ClubMember* user = new ClubMember(name, surname, age, email, password, sex);//need change class "coach"
			User.insert(std::pair <string, ClubMember>(email, user));
			member_amount++;
		}
		else {
			throw new std::exception("zazanulsya");
		}
	}

	void registrationUser(std::string name, std::string surname, int age, std::string email, std::string password, char sex) {
		if (age < 14 || age > 99) {
			throw new std::exception("zazanulsya");
		}
		
		size_t pos = email.find("@");
		if (pos == std::string::npos) {
			throw new std::exception("zazanulsya");
		}

		if (sex != 'M' || sex != "W") {
			throw new std::exception("zazanulsya");
		}

		ClubMember* user = new ClubMember(name, surname, age, email, password, sex);
		User.insert(std::pair <string, ClubMember>(email, user));
		member_amount++;
	}

	
};