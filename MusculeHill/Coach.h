#pragma once
#include "ClubMember.h"
#include "Class.h"
#include <vector>
#include "Date.h"

using namespace std;

class Coach : public ClubMember {
protected:
	int experience;
	vector<Date> free_dates = {};
public:
	Coach(std::string firstName, std::string surename, int userAge, std::string memberEmail, std::string pASSword, char sexxx, bool abonementType, int experience)
	{
		this->name = firstName;
		this->surname = surename;
		this->age = userAge;
		this->email = memberEmail;
		this->password = pASSword;
		this->sex = sexxx;
		this->abonement_type = true;
		this->experience = experience;
	}

	void add_new_free_date(Date date) {
		free_dates.push_back(date);
	}

	vector<Date>* getFreeDates() {
		return &free_dates;
	}
};