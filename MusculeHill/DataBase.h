#include <map>
#include <vector>
#include <string>
#include "ClubMember.h"
#include "Coach.h"
#include <iostream>

using namespace std;

class DataBase {
private:
	std::map<std::string, ClubMember*> Users = { {"bibizian@gmail.com", new ClubMember("Slava", "Chkalov", 17, "bibizian@gmail.com", "1010", 'M', true)} };
	std::map<std::string, Coach*> Coaches;
	//std::map<std::string, std::vector<Date>> Date;
	int member_amount = 0;
public:
	DataBase() { };
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
			Coaches.emplace(email, coach);
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
		Users.emplace(email, user);
		member_amount++;
	}

	bool signIn(std::string email, std::string password) {

		size_t pos = email.find("@");
		if (pos == std::string::npos) {
			throw new std::exception("zazanulsya");
		}

		if (Users.count(email) > 0) {
			if (Users[email]->getPassword() == password) {
				return true;
			}
		}
		else if (Coaches.count(email) > 0) {
			if (Coaches[email]->getPassword() == password) {
				return true;
			}
		}
		else {
			return false;
		}
		return false;
	}

	ClubMember* getClubMemberByEmail(string email) {
		if (Users.count(email) > 0)
			return Users[email];
		return NULL;
	}

	Coach* getCoachByEmail(string email) {
		if (Coaches.count(email) > 0)
			return Coaches[email];
		return NULL;
	}
};