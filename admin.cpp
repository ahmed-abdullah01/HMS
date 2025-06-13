#include "admin.h"
#include <fstream>
#include <iostream>

using namespace std;

bool Admin::login(const String& inputUserID, const String& inputPassword) {
    ifstream file("admin.txt");
    if (!file.is_open()) {
        return false;
    }
    String uid, pwd;
    while (file >> uid >> pwd) {
        if (uid == inputUserID && pwd == inputPassword) {
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

    String uid, pwd;
    cout << "\n=========Admin list:=========" <<endl;
    while (file >> uid >> pwd) {
        uid.print();
    }
}

void Admin::show_doctors() const {
    ifstream file("doctor.txt");
    if (!file.is_open()) {
        cout << "Could not open doctor.txt\n";
        return;
    }

    String uid, pwd;
    cout << "\n=========Doctor list:=========\n";
    while (file >> uid >> pwd) {
        uid.print();
    }
}

void Admin::show_patients() const {
    ifstream file("patient.txt");
    if (!file.is_open()) {
        cout << "Could not open patient.txt\n";
        return;
    }

    String uid, pwd;
    cout << "\n=========Patient list:\=========\n";
    while (file >> uid >> pwd) {
        uid.print();
    }
}

void Admin::remove_doctor(const String& username) {
    ifstream file("doctor.txt");
    ofstream temp("temp.txt");

    if (!file.is_open() || !temp.is_open()) {
        cout << "Error opening files for doctor removal\n";
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
    remove("doctor.txt");
    rename("temp.txt", "doctor.txt");

    if (removed)
        cout << "Doctor removed successfully.\n";
    else {
        cout << "Doctor not found.\n";

    }
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
}
