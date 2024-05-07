
#include "Patient.h"
#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <sstream>

PriorityQueue<Patient> queue;
LinkedList<Ailment> ailments;

using namespace std;

int main(int argc, char* argv[])
{
	int selection;

	cout << "                                     ****************************************************" << endl;
	cout << "                                     * Welcome to Fanshawe College Medical Center F2020 *" << endl;
	cout << "                                     ****************************************************" << endl;

	do {
		cout << "\n\nPlease make a Selection: " << endl;
		cout << endl;
		cout << "         1 - Add Patient" << endl;
		cout << "         2 - Process Next Patient In Queue" << endl;
		cout << "         3 - Display Queue" << endl;
		cout << "         4 - View Processed Patients History" << endl;
		cout << "         5 - Load Queue" << endl;
		cout << "         6 - Save Queue" << endl;
		cout << "         0 - Exit" << endl;
		cin >> selection;
		cout << "\n";

		Patient patient;
		string patientName, ailmentName, clear;
		int severity = 0;
		int time_sensitivity = 0;
		int contagiousness = 0;
		switch (selection) {
			case 1: {
				cout << "Enter patient name: ";
				cin >> ws;
				getline(cin, patientName, '\n');
				cin.putback('\n');
				patient = (patientName);
				while (getline(cin, ailmentName)) {
					cout << "\tEnter ailment (leave blank when done): ";
					getline(cin, ailmentName);
					if (ailmentName == "") { break; }
					cout << "\tEnter severity: ";
					cin >> ws;
					while (!(cin >> severity) || (severity < 0 || severity > 10)) {
						cout << "Please enter a valid number\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "\tEnter severity: ";
					}
					cout << "\tEnter time criticality: ";
					cin >> ws;
					while (!(cin >> time_sensitivity) || (time_sensitivity < 0 || time_sensitivity > 10)) {
						cout << "Please enter a valid number\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "\tEnter time criticality: ";
					}
					cout << "\tEnter contagiousness: ";
					cin >> ws;
					while (!(cin >> contagiousness) || (contagiousness < 0 || contagiousness > 10)) {
						cout << "Please enter a valid number\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "\tEnter time contagiousness: ";
					}
					cout << "\n";
					ailments.push_back(Ailment(ailmentName, severity, time_sensitivity, contagiousness));
				}
				patient.add_ailment(ailments.end()->data);
				queue.enqueue(patient);
			}
				break;
			case 2: {
				cout << queue.dequeue().get_name() << " moved to patient room!\n";
				Patient nextPatient = queue.dequeue();
				cout << "Next in queue: " << nextPatient.get_name() << " with priority score " << nextPatient.get_score();
			}
				break;
			case 3: {
				cout << "Patients In Queue: \n";
				Patient patientsInQueue;

				for (::size_t i = 0; i <= queue.size(); ++i) {
					patientsInQueue = queue.dequeue();
					cout << i << " : " << patientsInQueue.get_name() << " - " << patientsInQueue.get_score() << " - ";
					while (ailments.end()) {
						if (ailments.begin() != nullptr) {
							cout << ailments.begin()->data.get_name() << ", ";
							ailments.pop_front();
						}
						else {
							break;
						}
					}
					cout << endl;
				}	
			}
				break;
			case 4: {
				cout << "History: \n";
				Patient patientProcessed;
				for (::size_t i = queue.size(); i--;) {
					patientProcessed = queue.dequeue();
					cout << patientProcessed.get_name() << " - " << patientProcessed.get_score() << " - " << endl;
					while (ailments.end()) {
						if (ailments.begin() != nullptr) {
							cout << ailments.begin()->data.get_name() << ", ";
							ailments.pop_front();
						}
						else {
							break;
						}
					}
					cout << endl;
				}
			}
				break;
			case 5: {
				string filepath;
				string patientName, noOfAilments, ailmentName, severitySS, time_sensitivitySS, contagiousnessSS;
				int severity, time_sensitivity, contagiousness;
				cout << "Enter path to file: ";
				cin >> filepath;
				ifstream csv(filepath.substr(2), ios::in);
				if (!csv) {
					cout << "Error: failed to open " << filepath.substr(2) << endl;
				}
				while (csv.good()) {
					getline(csv, patientName, ',');
					getline(csv, noOfAilments, ',');
					getline(csv, ailmentName, ',');
					getline(csv, severitySS, ',');
					stringstream sv(severitySS);
					sv >> severity;
					getline(csv, time_sensitivitySS, ',');
					stringstream tms(time_sensitivitySS);
					tms >> time_sensitivity;
					getline(csv, contagiousnessSS);
					stringstream ctg(contagiousnessSS);
					ctg >> contagiousness;

					Patient patient(patientName);
					patient.add_ailment(Ailment(ailmentName, severity, time_sensitivity, contagiousness));
					queue.enqueue(patient);
				}
				csv.close();
			}
				break;
			case 6: {
				string filepath;
				cout << "Enter path to file: ";
				cin >> filepath;
				ofstream csv;
				csv.open(filepath.substr(2));
				for(::size_t i = 0; i <= queue.size(); ++i) {
					Patient	patient = queue.dequeue();
					csv << patient.get_name() << ", " << patient.get_ailments().begin()->data.get_name() << ", " << patient.get_ailments().begin()->data.get_severity()
						<< ", " << patient.get_ailments().begin()->data.get_time_sensitivity() << ", " << patient.get_ailments().begin()->data.get_contagiousness() << endl;
				}
				csv.close();
			}
				break;
			case 0: {
				cout << "Exiting...";
			}
				break;
			default: {
				cout << "********* Invalid option entered, Please select a valid option *********" << endl;
				getline(cin, clear);
			}
		}
	} while (selection != 0);

}