#include <map>
#include <vector>
#include <string>
#include "ClubMember.h"
#include "Coach.h"
#include <iostream>

using namespace std;

class DataBase {
private:
	std::map<std::string, ClubMember*> Users = { {"bibizian@gmail.com", new ClubMember("Slava", "Chkalov", 17, "bibizian@gmail.com", "1010", 'M', true, "g@s.com")} };
	std::map<std::string, Coach*> Coaches = { {"b@b.com", new Coach("Bibo", "Bobo", 43, "b@b.com", "1234567", 'M', true, 3)}};
	vector<Class> classes = { Class(Date(2024, 6, 3, 18, 0), "b@b.com", "bibizian@gmail.com") };
	int member_amount = 2;
public:
	DataBase() { };
	void registrationCoach(std::string name, std::string surname, int age, std::string email, std::string password, char sex, int experience, bool abonement) {
		if (experience > 2) {
			Coach* coach = new Coach(name, surname, age, email, password, sex, abonement, experience);
			Coaches[email] =  coach;
			member_amount++;
		}
		else {
			throw new std::exception("zazanulsya");
		}
	}

	void registrationUser(std::string name, std::string surname, int age, std::string email, std::string password, char sex, bool abonement, string coach) {
		ClubMember* user = new ClubMember(name, surname, age, email, password, sex, abonement, coach);
		Users[email] =  user;
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

	vector<Class> getClassesByEmail(string email) {
		vector <Class> res;
		for (Class cl : this->classes) {
			if (cl.coach == email || cl.member == email)
				res.push_back(cl);
		}
		return res;
	}
	
	int getEmailAmount(string email) {
		return this->Coaches.count(email) + this->Users.count(email);
	}

	vector<string> getCoachesEmail() {
		vector<string> res;
		for (auto pair : Coaches)
			res.push_back(pair.first);
		return res;
	}

	void addClass(Class& cl) {
		this->classes.push_back(cl);
	}
};