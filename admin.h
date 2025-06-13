#ifndef ADMIN_H
#define ADMIN_H

#include "String.h"

class Admin {
public:
    bool login(const String& inputUserID, const String& inputPassword);
    void show_admins() const;
    void show_doctors() const;
    void show_patients() const;
    void remove_doctor(const String& username);
    void remove_patient(const String& username);
};

#endif
