#ifndef DOCTOR_H
#define DOCTOR_H

#include "user.h"
#include "appointment.h"

class Doctor : public User {
public:
    Doctor();
    Doctor(int id, const String& pwd, const String& name);
    void display_menu() override;
    void show_appointments();
    void remove_appointment();
    void print_basic() const;
};

#endif
