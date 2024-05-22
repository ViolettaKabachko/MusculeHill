#include <map>
#include <vector>
#include <string>
#include "ClubMember.h"
#include "Coach.h"
#include <iostream>

class DataBase {
private:
	std::map<std::string, ClubMember*> User;
	//std::map<std::string, std::vector<Date>> Date;
	int member_amount = 0;
public:
	void registrationCoach(std::string name, std::string surname, int age, std::string email, std::string password, char sex, int experience, bool abonement) {
		if (experience > 1488) {
			if (age < 14 || age > 99) {
				throw new std::exception("zazanulsya");
			}

			size_t pos = email.find("@");
			if (pos == std::string::npos) {
				throw new std::exception("zazanulsya");
			}

			if (password.length() < 6) {
				throw new std::exception("zazanulsya");
			}

			if (sex != 'M' && sex != 'W') {
				throw new std::exception("zazanulsya");
			}

			Coach* coach = new Coach(name, surname, age, email, password, sex, abonement, experience);
			User.emplace(email, coach);
			member_amount++;
		}
		else {
			throw new std::exception("zazanulsya");
		}
	}

	void registrationUser(std::string name, std::string surname, int age, std::string email, std::string password, char sex, bool abonement) {
		if (age < 14 || age > 99) {
			throw new std::exception("zazanulsya");
		}
		
		size_t pos = email.find("@");
		if (pos == std::string::npos) {
			throw new std::exception("zazanulsya");
		}

		if (password.length() < 6) {
			throw new std::exception("zazanulsya");
		}

		if (sex != 'M' && sex != 'W') {
			throw new std::exception("zazanulsya");
		}

		ClubMember* user = new ClubMember(name, surname, age, email, password, sex, abonement);
		User.emplace(email, user);
		member_amount++;
	}

	bool signIN(std::string email, std::string password) {

		size_t pos = email.find("@");
		if (pos == std::string::npos) {
			throw new std::exception("zazanulsya");
		}

		if (User.count(email) > 0) {
			if (User[email]->getPassword() == password) {
				return true;
			}
		}

		return false;
	}

};