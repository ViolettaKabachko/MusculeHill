#pragma once
#include "Date.h"
#include <string>

enum Attending {
	Skipped = -1,
	Planned = 0,
	Attended = 1
};

class Class {
public:
	Date date;
	std::string coach;
	std::string member;
	Attending status;

	Class() {
		 Date();
		 coach = "";
		 member = "";
		 status = Planned;
	}

	Class(Date date, std::string coach, std::string member) : date(date), coach(coach), member(member), status(Planned) { }
	
};