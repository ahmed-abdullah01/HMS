#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include "user.h"
#include "doctor.h"
#include "patient.h"
#include "appointment.h"
#include "medical_record.h"
#include "String.h"
#include "dynamic_array.h"
#include <fstream>

class HospitalSystem {
    Dynamic_array<User*> users;
    Dynamic_array<Doctor> doctors;
    Dynamic_array<Patient> patients;

public:
    void run();
    void login();
    void signup();
    bool admin_login(const String& id, const String& pass);
};

#endif
