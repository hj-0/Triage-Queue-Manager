#pragma once

#include <string>

class Ailment
{
	std::string name_;
	int severity_;
	int time_sensitivity_;
	int contagiousness_;

	//calculated score equation
	int score_ = (severity_ * time_sensitivity_) + contagiousness_;

public:
	Ailment() : name_(""), severity_(0), time_sensitivity_(0), contagiousness_(0) {}
	//4-args ctor
	Ailment(std::string name, int severity, int time_sensitivity, int contagiousness) : name_(name), severity_(severity), time_sensitivity_(time_sensitivity), contagiousness_(contagiousness) {}

	//getter functions
	std::string get_name() const { return name_; }
	int get_severity() const { return severity_; }
	int get_time_sensitivity() const { return time_sensitivity_; }
	int get_contagiousness() const { return contagiousness_; }
	int get_score() const { return score_; }
};

//operator == overloading
inline bool operator ==(Ailment const& lhs, Ailment const& rhs) {
	return lhs.get_name() == rhs.get_name();
}
