#include "doctor.h"
#include <iostream>
#include <fstream>

using namespace std;

Doctor::Doctor() {}

Doctor::Doctor(int id, const String& pwd, const String& name)
    : User(id, pwd, name, "Doctor") {
}

void Doctor::display_menu() {
    while (true) {
        cout << "Doctor Menu\n";
        cout << "1. View Appointments\n";
        cout << "2. Remove Appointment\n";
        cout << "3. Logout\n";
        cout << "Choose: ";
        int c;
        cin >> c;
        if (c == 1) show_appointments();
        else if (c == 2) {
            remove_appointment();
        }
        else {
            break;
        }
    }
}

void Doctor::show_appointments() {
    ifstream file("appointments.txt");
    if (!file.is_open()) {
        cout << "Error reading appointments.\n";
        return;
    }

    String patient, doctor;
    bool found = false;
    while (file >> patient >> doctor) {
        if (doctor == get_name()) {
            cout << "Patient: ";
            patient.print();
            cout << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No appointments found.\n";
    }

    file.close();
}

void Doctor::remove_appointment() {
    String docName = get_name();
    String targetPatient;

    cout << "Enter patient username to remove from appointments: ";
    cin >> targetPatient;

    ifstream infile("appointments.txt");
    ofstream tempfile("temp.txt");

    if (!infile.is_open() || !tempfile.is_open()) {
        cout << "Error accessing files.\n";
        return;
    }

    String patient, doctor;
    bool found = false;

    while (infile >> patient >> doctor) {
        if (patient == targetPatient && doctor == docName) {
            found = true;
            continue;
        }
        tempfile << patient << " " << doctor << "\n";
    }

    infile.close();
    tempfile.close();

    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");

    if (found) cout << "Appointment removed.\n";
    else cout << "No matching appointment found.\n";
}

void Doctor::print_basic() const {
    cout << "Doctor ID: " << get_user_id() << " Name: ";
    get_name().print();
    cout << "\n";
}
