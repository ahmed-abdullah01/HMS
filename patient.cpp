#include "patient.h"
#include <fstream>
#include <iostream>
using namespace std;

Patient::Patient() {}

Patient::Patient(int id, const String& pass, const String& name)
    : User(id, pass, name, "Patient") {
}

void Patient::display_menu() {
    while (true) {
        cout << "Patient Menu" << endl;
        cout << "1. Book Appointment" << endl;
        cout << "2. Book Room" << endl;
        cout << "3. Generate Bill" << endl;
        cout << "4. Exit" << endl;

        int c;
        cin >> c;

        if (c == 1) book_appointment();
        else if (c == 2) view_medical_history();
        else if (c == 3) {
            cout << "Bill functionality here\n";
        }
        else break;
    }
}

void Patient::view_medical_history() {
    record.print();
}

MedicalRecord& Patient::get_record() {
    return record;
}

void Patient::print_basic() const {
    cout << "Patient ID: " << get_user_id() << " Name: ";
    get_name().print();
    cout << "\n";
}

bool Patient::already_has_appointment() {
    ifstream in("appointments.txt");
    if (!in.is_open()) return false;

    String pat, doc;
    while (in >> pat >> doc) {
        if (pat == get_name()) {
            return true;
        }
    }
    return false;
}

void Patient::save_appointment_to_file(const String& doctorUsername) {
    ofstream out("appointments.txt", ios::app);
    if (out.is_open()) {
        out << get_name() << " " << doctorUsername << "\n";
        out.close();
        cout << "Appointment booked successfully with Dr. ";
        doctorUsername.print(); cout << endl;
    }
    else {
        cout << "Failed to save appointment.\n";
    }
}

void Patient::book_appointment() {
    if (already_has_appointment()) {
        cout << "You already have an appointment. You can book again only if doctor removes it.\n";
        return;
    }

    cout << "Available Doctors:\n";
    ifstream in("doctor.txt");
    if (!in.is_open()) {
        cout << "Unable to open doctor file.\n";
        return;
    }

    String uname, pwd;
    while (in >> uname >> pwd) {
        uname.print();
        cout << endl;
    }
    in.close();

    cout << "Enter doctor username to book: ";
    String doc;
    cin >> doc;

    save_appointment_to_file(doc);
}
