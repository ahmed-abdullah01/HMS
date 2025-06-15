#include "admin.h"
#include <fstream>
#include <iostream>

using namespace std;
#include "admin.h"
#include <fstream>
#include <iostream>
using namespace std;

Admin::Admin() : user_id("nil"), password("nil") {}

Admin::Admin(const String& uid, const String& pass) : user_id(uid), password(pass) {}

bool Admin::login(const String& input_userid, const String& input_password) {
    ifstream file("admin.txt");
    if (!file.is_open()) {
        return false;
    }
    String uid, pass;
    while (file >> uid >> pass) {
        if (uid == input_userid && pass == input_password) {
            return true;
        }
    }
    return false;
}

void Admin::show_admins() const {
    ifstream file("admin.txt");
    if (!file.is_open()) {
        cout << "Could not open admin.txt\n";
        return;
    }

    String uid, pass;
    system("cls");
    cout << "=========Admin list:=========" <<endl;
    while (file >> uid >> pass) {
        uid.print();
    }
}

void Admin::show_doctors() const {
    ifstream file("doctor.txt");
    if (!file.is_open()) {
        cout << "Could not open doctor.txt\n";
        return;
    }

    String uid, pass, dept;
    system("cls");
    cout << "=========Doctor List:=========\n";
    while (file >> uid >> pass >> dept) {
        cout << "Doctor: ";
        uid.print();
        cout << " - Department: ";
        dept.print();
        cout << "\n";
        
    }
    
}


void Admin::show_patients() const {
    ifstream file("patient.txt");
    if (!file.is_open()) {
        cout << "Could not open patient.txt\n";
        return;
    }

    String uid, pwd;
    system("cls");
    cout << "=========Patient list:\=========\n";
    while (file >> uid >> pwd) {
        uid.print();
    }
    
}

void Admin::show_doctors_by_department() const {
    system("cls");
    cout << "Choose Department:\n";
    cout << "1. Cardiologist\n";
    cout << "2. Orthopedic\n";
    cout << "3. Physician\n";
    cout << "4. Neurologist\n";
    cout << "5. General Surgeon\n";
    cout << "Enter choice: ";
    int dep_choice;
    cin >>dep_choice;

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

    ifstream file("doctor.txt");
    if (!file.is_open()) {
        cout << "Could not open doctor.txt\n";
        return;
    }

    String uname, pass, dept;
    bool found = false;
    cout << "\nDoctors in " << selected << ":\n";
    while (file >> uname >> pass >> dept) {
        if (dept == selected) {
            cout << "Doctor: ";
            uname.print();
            cout << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No doctors found in this department.\n";
    }
}


void Admin::show_rooms() const {
    ifstream file("rooms.txt");
    if (!file.is_open()) {
        cout << "Could not open rooms.txt\n";
        return;
    }

    String pname;
    int rno;

    cout << "\n=========Room Bookings:=========" << endl;
    while (file >> pname >> rno) {
        cout << "Patient: ";
        pname.print();
        cout << " - Room: " << rno << endl;
    }

    file.close();

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}


void Admin::remove_doctor(const String& username) {
    ifstream file("doctor.txt");
    ofstream temp("temp.txt");

    if (!file.is_open() || !temp.is_open()) {
        cout << "Error opening files for doctor removal\n";
        return;
    }

    String uid, pwd, dept;
    bool removed = false;

    while (file >> uid >> pwd >> dept) {
        if (uid == username) {
            removed = true;
            continue;
        }
        temp << uid << " " << pwd << " " << dept << "\n";
    }

    file.close();
    temp.close();
    remove("doctor.txt");
    rename("temp.txt", "doctor.txt");

    if (removed) {
        cout << "Doctor removed successfully.\n";
    }
    else {
        cout << "Doctor not found.\n";
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

void Admin::remove_patient(const String& username) {
    ifstream file("patient.txt");
    ofstream temp("temp.txt");

    if (!file.is_open() || !temp.is_open()) {
        cout << "Error opening files for patient removal\n";
        return;
    }

    String uid, pwd;
    bool removed = false;
    while (file >> uid >> pwd) {
        if (uid == username) {
            removed = true;
            continue;
        }
        temp << uid << " " << pwd << "\n";
    }

    file.close();
    temp.close();
    remove("patient.txt");
    rename("temp.txt", "patient.txt");

    if (removed) {
        cout << "Patient removed successfully.\n";
    }
    else{
        cout << "Patient not found.\n";
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}



