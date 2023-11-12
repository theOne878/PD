#include <iostream>
using namespace std;

int main() {
    int days;
    cout << "Enter Number of days you visited Hospital: ";
    cin >> days;
	
	int day = 1;
    int doctors = 7;
    int patients;
    int patientsTreated = 0;
    int patientsunTreated = 0;
   	
    	while(day<=days){
        if ((patientsTreated < patientsunTreated) && (day % 3 == 0)) {
            doctors++;
        	}
        	
        cout << "Number of patients who visited hospital on Day" << day << ": ";
        cin >> patients;

        if (doctors >= patients) {
            patientsTreated = patientsTreated + patients;
        	} 
		else if(doctors < patients) {
            patientsTreated = patientsTreated + doctors;
            patientsunTreated = patientsunTreated + (patients - doctors);
        	}
        	
			day++;	
		}

    cout << "Treated Patients: " << patientsTreated << endl;
    cout << "Untreated Patients: " << patientsunTreated << endl;
}