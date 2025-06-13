#ifndef USER_H
#define USER_H

#include "String.h"

class User {
protected:
    int user_id;
    String password;
    String name;
    String role;

public:
    User();
    User(int id, const String& pwd, const String& name, const String& role);
    
    virtual int get_user_id() const;
    virtual String get_name() const;
    virtual String get_password() const;
    virtual String get_role() const;
    virtual bool authenticate(const String& input_password) const;
    virtual void display_menu() = 0;
    virtual ~User() = default;
};

#endif