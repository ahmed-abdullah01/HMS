#include "patient.h"
#include "pharmacy.h"
#include <fstream>
#include <iostream>
using namespace std;

Patient::Patient() {}

Patient::Patient(int id, const String& pass, const String& name)
    : User(id, pass, name, "Patient") {
}

void Patient::view_doctors_by_department() {
    cout << "Choose Department:\n";
    cout << "1. Cardiologist\n";
    cout << "2. Orthopedic\n";
    cout << "3. Physician\n";
    cout << "4. Neurologist\n";
    cout << "5. General Surgeon\n";
    cout << "Enter choice: ";
    int depChoice;
    cin >> depChoice;

    String selected;
    if (depChoice == 1) {
        selected = "Cardiologist";
    }
    else if (depChoice == 2) {
        selected = "Orthopedic";
    }
    else if (depChoice == 3) {
        selected = "Physician";
    }
    else if (depChoice == 4) {
        selected = "Neurologist";
    }
    else if (depChoice == 5) {
        selected = "GeneralSurgeon";
    }
    else {
        selected = "General";
    }

    ifstream file("doctor.txt");
    if (!file.is_open()) {
        cout << "Could not open doctor.txt\n";
        return;
    }

    String uname, pwd, dept;
    bool found = false;
    while (file >> uname >> pwd >> dept) {
        if (dept == selected) {
            cout << "Doctor: ";
            uname.print();
            cout << " - Department: ";
            dept.print();
            cout << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No doctors found in this department.\n";
    }

    file.close();
}


void Patient::display_menu() {

    while (true) {
        cout << "Patient Menu" << endl;
        cout << "1. Book Appointment" << endl;
        cout << "2. Book Room" << endl;
        cout << "3. Visit Pharmacy" << endl;
        cout << "4. Generate Bill" << endl;
        cout << "5. Unbook Room" << endl;
        cout << "6. Logout" << endl;

        int c;
        cin >> c;

        if (c == 1) {
            book_appointment();
        }
        else if (c == 2) {
            book_room();
        }
        else if (c == 3) {


            pharmacy.buy_medicines(this->meds, this->total_med_cost);

        }
        else if (c == 4) {
            generate_bill();
        }
        else if (c == 6) {
            system("cls");
            cout << "Logged out Successfully!" << endl;
            break;
        }
        else if (c == 5) {
            unbook_room();
        }
        else {
            cout << "Invalid choice.\n";
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
        }
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
    cout << endl;
}

bool Patient::already_has_appointment() {
    ifstream in("appointments.txt");
    if (!in.is_open()) {
        return false;
    }
    String pat, doc;
    while (in >> pat >> doc) {
        if (pat == get_name()) {
            return true;
        }
    }
    return false;
}

void Patient::save_appointment_to_file(const String& doctor_username) {
    ofstream out("appointments.txt", ios::app);
    if (out.is_open()) {
        out << get_name() << " " << doctor_username << "\n";
        out.close();
        cout << "Appointment booked successfully with Dr. ";
        doctor_username.print(); cout << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    else {
        cout << "Failed to save appointment.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
}

void Patient::book_appointment() {
    if (already_has_appointment()) {
        cout << "You already have an appointment. You can book again only if doctor removes it.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    system("cls");
    cout << "Choose Department:\n";
    cout << "1. Cardiologist\n";
    cout << "2. Orthopedic\n";
    cout << "3. Physician\n";
    cout << "4. Neurologist\n";
    cout << "5. General Surgeon\n";
    cout << "Enter choice: ";
    int dep_choice;
    cin >> dep_choice;

    String selected;
    if (dep_choice == 1) {
        selected = "Cardiologist";
    }
    else if (dep_choice == 2) {
        selected = "Orthopedic";
    }
    else if (dep_choice == 3) {
        selected = "Physician";
    }
    else if (dep_choice == 4) {
        selected = "Neurologist";
    }
    else if (dep_choice == 5) {
        selected = "GeneralSurgeon";
    }
    else {
        selected = "General";
    }

    ifstream in("doctor.txt");
    if (!in.is_open()) {
        cout << "Unable to open doctor file.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    system("cls");
    cout << "Available Doctors in selected department:\n";
    String uname, pwd, dept;
    Dynamic_array<String> matching_doctors;
    while (in >> uname >> pwd >> dept) {
        if (dept == selected) {
            uname.print();
            cout << endl;
            matching_doctors.push(uname);
        }
    }
    in.close();

    if (matching_doctors.size() == 0) {
        cout << "No doctors found in this department.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }

    cout << "\nEnter doctor username to book: ";
    String doc;
    cin >> doc;

    bool valid = false;
    for (int i = 0; i < matching_doctors.size(); i++) {
        if (doc == matching_doctors[i]) {
            valid = true;
            break;
        }
    }

    if (valid) {
        save_appointment_to_file(doc);
    }
    else {
        cout << "Invalid doctor selected.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
}

void Patient::book_room() {
    ifstream check("rooms.txt");
    if (!check.is_open()) {
        cout << "Could not open rooms.txt\n";
        return;
    }

    bool already_booked = false;
    bool room_taken[10] = { false };

    String patient_name;
    int room_number;

    while (check >> patient_name >> room_number) {
        if (patient_name == get_name()) {
            already_booked = true;
        }
        if (room_number >= 1 && room_number <= 10) {
            room_taken[room_number - 1] = true;
        }
    }

    check.close();

    if (already_booked) {
        cout << "You already have a room booked.\n";
    }
    else {
        int available_room_number = -1;
        for (int i = 0; i < 10; i++) {
            if (!room_taken[i]) {
                available_room_number = i + 1;
                break;
            }
        }

        if (available_room_number == -1) {
            cout << "No rooms available.\n";
        }
        else {
            ofstream out("rooms.txt", ios::app);
            if (out.is_open()) {
                out << get_name() << " " << available_room_number << "\n";
                out.close();
                cout << "Room " << available_room_number << " booked successfully.\n";
            }
            else {
                cout << "Failed to book room.\n";
            }
        }
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}


void Patient::unbook_room() {
    ifstream in("rooms.txt");
    ofstream temp("temp.txt");

    if (!in.is_open() || !temp.is_open()) {
        cout << "Error opening files for unbooking.\n";
        return;
    }

    String pname;
    int rno;
    bool found = false;

    while (in >> pname >> rno) {
        if (pname == get_name()) {
            found = true;
            continue;
        }
        temp << pname << " " << rno << "\n";
    }

    in.close();
    temp.close();
    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");

    if (found) {
        cout << "Room unbooked successfully.\n";
    }
    else {
        cout << "No room found under your name.\n";
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

void Patient::generate_bill() {
    int room_cost = 0;

    ifstream in("rooms.txt");
    String pname;
    int rno;
     
    while (in >> pname >> rno) {
        if (pname == get_name()) {
            room_cost = 5000;
            break;
        }
    }
    in.close();

    int dr_cost = 0;
    ifstream drin("appointments.txt");
    String patname, docname;

    while (drin >> patname >> docname) {
        if (patname == get_name()) {
            dr_cost = 1000;
            break;
        }
    }
    drin.close();

    int total = room_cost + total_med_cost + dr_cost;
    cout << "----- Bill -----\n";
    cout << "Room Charges: " << room_cost << "\n";
    cout << "Doctor Charges: " << dr_cost << "\n";
    cout << "Medicine Charges: " << total_med_cost << "\n";
    cout << "Total: " << total << "\n";

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}