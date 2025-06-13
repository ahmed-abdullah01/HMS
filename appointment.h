#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "String.h"

class Appointment {
    String date;
    String time;
    String reason;

public:
    Appointment();
    Appointment(const String& d, const String& t, const String& r);
    void print() const;
};

#endif
