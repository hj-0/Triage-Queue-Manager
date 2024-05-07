#include "Patient.h"

//Functions Implementation
void Patient::add_ailment(Ailment ailments) {
	ailments_.push_back(Ailment(ailments.get_name(), ailments.get_severity(), ailments.get_time_sensitivity(), ailments.get_contagiousness()));
}

LinkedList<Ailment> Patient::get_ailments() const {
	return ailments_;
}

int Patient::get_score() const {
	LinkedList<Ailment> ailments = get_ailments();
	const int score = ailments.begin()->data.get_score();

	return score;
}



