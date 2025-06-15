#include "hospital.h"
#include "pharmacy.h"
#include "admin.h"
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <fstream>

using namespace std;

void HospitalSystem::run() {
    while (true) {
        cout << "===================================================" << endl;
        cout << "=                                                 =" << endl;
        cout << "=            Hospital Management System           =" << endl;
        cout << "=                                                 =" << endl;
        cout << "===================================================" << endl;
        cout << "1. Login\n2. Signup\n3. Exit\nChoose: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            system ("cls");
            login();
        }
        else if (ch == 2)
        {
            system("cls");
            signup();
        }
        else
        {
            break;
        }
    }
}

void HospitalSystem::login() {
    int type;
    cout << "Login Page" << endl;
    cout << "1. Doctor\n2. Patient\n3. Admin\n4. Back\nChoose type: ";
    cin >> type;

    if (type == 4)
    {
        system("cls");
        cout << "Returned Back Successfully!" << endl;
        return;
    }

    String type_name;
    if (type == 1)
    {
        type_name = "Doctor";
    }
    else if (type == 2)
    {
        type_name = "Patient";
    }
    else if (type == 3)
    {
        type_name = "Admin";
    }



    String username, password;
    system("cls");
    cout << "Enter your credidentials to login as " <<type_name << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    system("cls");
    if (type == 1) {
        ifstream file("doctor.txt");
        if (file.is_open()) {
            String uname, pwd, dept;
            while (file >> uname >> pwd >> dept) {
                if (uname == username && pwd == password) {
                    Doctor d(0, pwd, uname, dept);
                    d.display_menu();
                    return;
                }
            }
            file.close();
        }
        system("cls");
        cout << "Invalid doctor credentials\n";
    }

    else if (type == 2) {
        ifstream file("patient.txt");
        if (file.is_open()) {
            String uname, pwd;
            while (file >> uname >> pwd) {
                if (uname == username && pwd == password) {
                    Patient p(0, pwd, uname);
                    p.display_menu();
                    return;
                }
            }
            file.close();
        }
        system("cls");
        cout << "Invalid patient credentials\n";
    }

    else if (type == 3) {
        if (admin_login(username, password)) {
            Admin a;
            Pharmacy pharmacy;
            while (true) {
                cout << "Admin Menu\n";
                cout << "1. View Doctors\n";
                cout << "2. View Doctors by Department\n";
                cout << "3. View Patients\n";
                cout << "4. View Admins\n";
                cout << "5. View Rooms\n";
                cout << "6. View Pharmacy\n";
                cout << "7. Remove Doctors\n";
                cout << "8. Remove Patients\n";
                cout << "9. Logout\n";
                cout << "Choose: ";

                int op;
                cin >> op;

                if (op == 1) {
                    a.show_doctors();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 2) {
                    a.show_doctors_by_department();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 3) {
                    a.show_patients();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 4) {
                    a.show_admins();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 5) {
                    system("cls");
                    a.show_rooms();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 6) {
                    pharmacy.show_all();
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 7) {
                    String uname;
                    system("cls");
                    a.show_doctors();
                    cout << "Enter doctor username to remove: ";
                    cin >> uname;
                    a.remove_doctor(uname);
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 8) {
                    String uname;
                    system("cls");
                    a.show_patients();
                    cout << "Enter patient username to remove: ";
                    cin >> uname;
                    a.remove_patient(uname);
                    cout << "Press any key to continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                else if (op == 9) {
                    system("cls");
                    cout << "Logged out successfully!" << endl;
                    break;
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
        else {
            system("cls");
            cout << "Invalid admin credentials\n";
        }
    }


    else {
        system("cls");
        cout << "Invalid type selected\n";
    }
}

void HospitalSystem::signup() {
    int type;
    cout << "Sign-Up Page" << endl;
    cout << "1. Doctor\n2. Patient\n3. Back\nChoose type: ";
    cin >> type;

    

    String type_name;
    if (type == 1)
    {
        type_name = "Doctor";
    }
    else if (type == 2)
    {
        type_name = "Patient";
    }

    String username, password;
    system("cls");
    cout << "Enter your credidentials to Sign-Up as " << type_name << endl;
    if (type == 3)
    {
        system("cls");
        cout << "Returned Back Successfully!" << endl;
        return;
    }
    else if (type == 1) {
        while (true) {
            cout << "Choose Username: ";
            cin >> username;

            ifstream check("doctor.txt");
            bool exists = false;
            String uname, pwd, dept;
            while (check >> uname >> pwd >> dept) {
                if (uname == username) {
                    exists = true;
                    break;
                }
            }
            check.close();

            if (exists) {
                system("cls");
                cout << "Username already exists. Please choose another.\n";
            }
            else {
                break;
            }
        }

        cout << "Choose Password: ";
        cin >> password;

        cout << "\nChoose Department:\n";
        cout << "1. Cardiologist\n";
        cout << "2. Orthopedic\n";
        cout << "3. Physician\n";
        cout << "4. Neurologist\n";
        cout << "5. General Surgeon\n";
        cout << "Enter choice: ";
        int dep_choice;
        cin >> dep_choice;

        String dept_name;
        if (dep_choice == 1) {
            dept_name = "Cardiologist";
        }
        else if (dep_choice == 2) { 
            dept_name = "Orthopedic"; 
        }
        else if (dep_choice == 3) {
            dept_name = "Physician";
        }
        else if (dep_choice == 4) {
            dept_name = "Neurologist";
        }
        else if (dep_choice == 5) {
            dept_name = "GeneralSurgeon"; 
        }
        else {
            dept_name = "Unknown";
        }

        ofstream out("doctor.txt", ios::app);
        if (out.is_open()) {
            out << username << " " << password << " " << dept_name << "\n";
            out.close();
            system("cls");
            cout << "Doctor registered successfully.\n";
        }
        else {
            system("cls");
            cout << "Error opening doctor.txt for writing.\n";
        }
    }

    else if (type == 2) {
        Patient p;

        while (true) {
            cout << "Choose Username: ";
            cin >> username;

            ifstream check("patient.txt");
            bool exists = false;
            String uname, pwd;
            while (check >> uname >> pwd) {
                if (uname == username) {
                    exists = true;
                    break;
                }
            }
            check.close();

            if (exists) {
                system("cls");
                cout << "Username already exists. Please choose another.\n";
            }
            else {
                break;
            }
        }


        cout << "Choose Password: ";
        cin >> password;

        ofstream out("patient.txt", ios::app);
        if (out.is_open()) {
            out << username << " " << password << "\n";
            out.close();
            system("cls");
            cout << "Patient registered successfully.\n";
        }
        else {
            system("cls");
            cout << "Error opening patient.txt for writing.\n";
        }
    }

    else {
        system("cls");
        cout << "Invalid user type selected.\n";
    }
}

bool HospitalSystem::admin_login(const String& id, const String& pass) {
    ifstream file("admin.txt");
    if (!file.is_open()) {
        return false;
    }
    String uid, pwd;
    while (file >> uid >> pwd) {
        if (uid == id && pwd == pass) {
            return true;
        }
    }
    return false;
}
