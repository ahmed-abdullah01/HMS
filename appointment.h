#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "date.h"

#include "String.h"

class Appointment {
    Date date;
    String time;
    String reason;

public:
    Appointment();
    Appointment(int& d, int& m, int& y, const String& t, const String& r);
    void print() const;
};

#endif
