#pragma once
#include <iostream>
#include <cstring>

class ClubMember {
protected:
	std::string name;
	std::string surname;
	int age;
	std::string email;
	std::string password;
	char sex;
	bool abonement_type;


public:
	ClubMember(std::string firstName, std::string middlename, int userAge,std::string memberEmail ,std::string pASSword, char sexxx, bool abonementType):
		name(firstName), surname(middlename), age(userAge), email(memberEmail), password(pASSword), sex(sexxx), abonement_type(abonementType) {
	}
	~ClubMember() {
	}
	
	std::string getPassword() {
		return this->password;
	}

	/*void displayUserInfo() {
		std::cout << "Name: " << name << ", Age: " << age << ", Email: " << email << std::endl;
	}*/
};