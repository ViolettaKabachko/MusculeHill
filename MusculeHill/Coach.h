#pragma once
#include "ClubMember.h"

class Coach : public ClubMember {
protected:
	int experience;
public:
	Coach(std::string firstName, std::string middlename, int userAge, std::string memberEmail, std::string pASSword, char sexxx, bool abonementType, int experience) : ClubMember(
		firstName, middlename, userAge, memberEmail, pASSword, sexxx, abonementType), experience(experience) {
	}

	~Coach() {

	}

};