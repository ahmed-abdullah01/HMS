#include "appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment() {}

Appointment::Appointment(int& d, int& m, int& y, const String& t, const String& r)
    : date(d,m,y), time(t), reason(r) {
}

void Appointment::print() const {
    cout << "Date: ";
    date.display();
    cout << " Time: ";
    time.print();
    cout << " Reason: ";
    reason.print();
    cout << endl;
}
