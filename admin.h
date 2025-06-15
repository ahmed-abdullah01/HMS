#ifndef ADMIN_H
#define ADMIN_H

#include "String.h"

class Admin {
    String user_id;
    String password;
public:
    Admin();  
    Admin(const String& uid, const String& pass); 
    bool login(const String& input_userid, const String& input_password);
    void show_admins() const;
    void show_doctors() const;
    void show_patients() const;
    void show_rooms() const;
    void remove_doctor(const String& username);
    void remove_patient(const String& username);
    void show_doctors_by_department() const;
};

#endif
