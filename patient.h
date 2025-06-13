#ifndef PATIENT_H
#define PATIENT_H

#include "user.h"
#include "appointment.h"
#include "medical_record.h"
#include "dynamic_array.h"

class Patient : public User {
    Dynamic_array<Appointment> appointments;
    MedicalRecord record;

public:
    Patient();
    Patient(int id, const String& pass, const String& name);
    void display_menu();
    void add_appointment(const Appointment& a);
    void show_appointments();
    void view_medical_history();
    MedicalRecord& get_record();
    void print_basic() const;
    void book_room();
    void book_appointment();
    bool already_has_appointment();
    void save_appointment_to_file(const String& doctorUsername);

};

#endif
