#include "appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment() {}

Appointment::Appointment(const String& d, const String& t, const String& r)
    : date(d), time(t), reason(r) {
}

void Appointment::print() const {
    cout << "Date: ";
    date.print();
    cout << " Time: ";
    time.print();
    cout << " Reason: ";
    reason.print();
    cout << "\n";
}
