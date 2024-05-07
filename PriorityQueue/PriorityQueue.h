#pragma once

#include "Patient.h"
template <typename T>
class PriorityQueue {
	LinkedList<T> patients_;
public:

	bool empty() {
		return patients_.empty();
	}

	size_t size() {
		return patients_.size();
	}

	void enqueue(const T value) {

		//add a new patient to the front
		patients_.push_front(value);
		
		struct LinkedList<T>::Node* current_ptr = patients_.begin();
		struct LinkedList<T>::Node* next_ptr = current_ptr->next;

		if(patients_.size() != 1) { //if there is a node pointing to another node means it has 2 patients so we can use it to compare then continue on to the next line
			//run the loop until next_ptr points to a 'nullptr'
			while (next_ptr) {
				if (next_ptr->data.get_score() >= current_ptr->data.get_score()) { //if the priority of next element is greater than or equal to the current element, swap it
					//swap elements
					T temp = current_ptr->data;
					current_ptr->data = next_ptr->data;
					next_ptr->data = temp;
				}
				else { //if swap is not necessary, break the loop
					break;
				}
				//simultaneously 'move' the current_ptr and next_ptr to the next position
				current_ptr = next_ptr;
				next_ptr = next_ptr->next;
			}
		}
	}

	T dequeue() {
		return patients_.pop_front(); //pop the front element which has a 'higher' priority
	}
};




