#include "medical_record.h"
#include <iostream>
using namespace std;

void MedicalRecord::add_entry(const String& entry) {
    history.push(entry);
}

void MedicalRecord::print() const {
    for (int i = 0; i < history.size(); i++) {
        cout << "- ";
        history[i].print();
        cout << "\n";
    }
}
