#ifndef PATIENT_H
#define PATIENT_H

#include "user.h"
#include "appointment.h"
#include "medical_record.h"
#include "dynamic_array.h"
#include "pharmacy.h"

class Patient : public User {
    Dynamic_array<Appointment> appointments;
    MedicalRecord record;
    Pharmacy pharmacy;
    Dynamic_array<String> meds;
    int total_med_cost = 0;


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
    void unbook_room();
    void book_appointment();
    bool already_has_appointment();
    void save_appointment_to_file(const String& doctor_username);


    void view_doctors_by_department(); 
    void generate_bill();
};

#endif
