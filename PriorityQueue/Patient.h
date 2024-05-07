#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;

public:
	Patient() : name_("") {}
	//1-arg ctor
	Patient(std::string name) : name_(name) {}

	//getter function
	std::string get_name() const { return name_; }

	//add_ailment function
	void add_ailment(Ailment ailments);

	//get_ailments function
	LinkedList<Ailment> get_ailments() const;

	//get_score function
	int get_score() const;

};

//operator == overloading 
inline bool operator ==(Patient const& lhs, Patient const& rhs) {
	return lhs.get_name() == rhs.get_name();
}

