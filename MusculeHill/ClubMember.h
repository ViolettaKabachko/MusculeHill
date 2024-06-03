#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Date.h"
#include "Class.h"

class ClubMember {
protected:
	std::string name;
	std::string surname;
	int age;
	std::string email;
	std::string password;
	char sex;
	bool abonement_type;
	std::string coach;

public:
	ClubMember() : name(""), surname(""), age(0), email(""), password(""), sex('M'), abonement_type(false), coach("") {};

	ClubMember(std::string firstName, std::string middlename, int userAge,std::string memberEmail ,std::string pASSword, char sexxx, bool abonementType, std::string coach):
		name(firstName), surname(middlename), age(userAge), email(memberEmail), password(pASSword), sex(sexxx), abonement_type(abonementType), coach(coach) {
	}
	~ClubMember() {
	}
	
	void setAbonement(bool abonement_type) {
		this->abonement_type = abonement_type;
	}
	
	std::string getPassword() {
		return this->password;
	}

	std::string getEmail() {
		return this->email;
	}

	std::string getFullName() {
		return name + " " + surname;
	}

	std::string getCoach() {
		return coach;
	}
};