#include "User.h"

User::User() : user_id(0), password(""), name(""), role("") {}

User::User(int id, const String& pwd, const String& name, const String& role)
    : user_id(id), password(pwd), name(name), role(role) {
}

int User::get_user_id() const {
    return user_id;
}

String User::get_name() const {
    return name;
}

String User::get_password() const {
    return password;
}

String User::get_role() const {
    return role;
}

bool User::authenticate(const String& input_password) const {
    return password == input_password;
}