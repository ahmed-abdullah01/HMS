#include "String.h"
#include <iostream>
using namespace std;

int String::getlen(const char* str) {
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}

int String::getlen(const String str) {
    return str.len;
}

String::String() : len(0), cap(0), cs(nullptr) {}

String::String(const String& str) {
    len = str.len;
    cap = str.cap;
    cs = new char[cap + 1];
    for (int i = 0; i < len; i++) {
        cs[i] = str.cs[i];
    }
    cs[len] = '\0';
}

String::String(const char* str) {
    len = getlen(str);
    cap = len;
    cs = new char[cap + 1];
    for (int i = 0; i < len; i++) {
        cs[i] = str[i];
    }
    cs[len] = '\0';
}

String::String(const char c, int l) {
    len = cap = l;
    cs = new char[cap + 1];
    for (int i = 0; i < len; i++) {
        cs[i] = c;
    }
    cs[len] = '\0';
}

String::String(int num) {
    itos(num);
}

String& String::copy(const String& s) {
    if (this != &s) {
        delete[] cs;
        len = s.len;
        cap = s.cap;
        cs = new char[cap + 1];
        for (int i = 0; i < len; i++) {
            cs[i] = s.cs[i];
        }
        cs[len] = '\0';
    }
    return *this;
}

void String::regrow() {
    int new_cap = cap == 0 ? 2 : cap * 2;
    char* new_cs = new char[new_cap + 1];
    for (int i = 0; i < len; i++) {
        new_cs[i] = cs[i];
    }
    delete[] cs;
    cs = new_cs;
    cap = new_cap;
    cs[len] = '\0';
}

String String::itos(int num) {
    if (cs) delete[] cs;
    if (num == 0) {
        len = cap = 1;
        cs = new char[2];
        cs[0] = '0';
        cs[1] = '\0';
        return *this;
    }

    int temp = num, count = 0;
    while (temp > 0) {
        temp /= 10;
        count++;
    }

    len = cap = count;
    cs = new char[cap + 1];
    cs[len] = '\0';

    for (int i = len - 1; i >= 0; i--) {
        cs[i] = (num % 10) + '0';
        num /= 10;
    }

    return *this;
}

int String::stoi() const {
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (cs[i] < '0' || cs[i] > '9') return 0;
        result = result * 10 + (cs[i] - '0');
    }
    return result;
}

String& String::trim() {
    int start = 0, end = len - 1;
    while (start <= end && (cs[start] == ' ' || cs[start] == '\n' || cs[start] == '\t')) start++;
    while (end >= start && (cs[end] == ' ' || cs[end] == '\n' || cs[end] == '\t')) end--;

    int newLen = end - start + 1;
    for (int i = 0; i < newLen; i++) {
        cs[i] = cs[start + i];
    }
    len = newLen;
    cs[len] = '\0';
    return *this;
}

void String::remove_at(int i) {
    if (i < 0 || i >= len) return;
    for (int j = i; j < len - 1; j++) {
        cs[j] = cs[j + 1];
    }
    len--;
    cs[len] = '\0';
}

void String::insert_at(int n, char ch) {
    if (n < 0 || n > len) return;
    if (len + 1 >= cap) regrow();
    for (int i = len; i > n; i--) {
        cs[i] = cs[i - 1];
    }
    cs[n] = ch;
    len++;
    cs[len] = '\0';
}

void String::insert_at(int n, const String& sub) {
    if (n < 0 || n > len) return;
    while (len + sub.len > cap) regrow();
    for (int i = len - 1; i >= n; i--) {
        cs[i + sub.len] = cs[i];
    }
    for (int i = 0; i < sub.len; i++) {
        cs[n + i] = sub.cs[i];
    }
    len += sub.len;
    cs[len] = '\0';
}

String String::operator+(const String& right) const {
    String temp;
    temp.len = len + right.len;
    temp.cap = temp.len;
    temp.cs = new char[temp.cap + 1];
    for (int i = 0; i < len; i++) temp.cs[i] = cs[i];
    for (int i = 0; i < right.len; i++) temp.cs[len + i] = right.cs[i];
    temp.cs[temp.len] = '\0';
    return temp;
}

String& String::operator+=(const String& right) {
    while (len + right.len > cap) regrow();
    for (int i = 0; i < right.len; i++) {
        cs[len + i] = right.cs[i];
    }
    len += right.len;
    cs[len] = '\0';
    return *this;
}

String& String::operator=(const String& right) {
    if (this != &right) {
        delete[] cs;
        len = right.len;
        cap = right.cap;
        cs = new char[cap + 1];
        for (int i = 0; i < len; i++) {
            cs[i] = right.cs[i];
        }
        cs[len] = '\0';
    }
    return *this;
}

const char& String::operator[](int i) const {
    if (i < 0 || i >= len) return cs[0];
    return cs[i];
}

char& String::operator[](int i) {
    if (i < 0 || i >= len) return cs[0];
    return cs[i];
}

bool String::operator==(const String& other) const {
    if (len != other.len) return false;
    for (int i = 0; i < len; i++) {
        if (cs[i] != other.cs[i]) return false;
    }
    return true;
}

String& String::toupper() {
    for (int i = 0; i < len; i++) {
        if (cs[i] >= 'a' && cs[i] <= 'z') cs[i] -= 32;
    }
    return *this;
}

String& String::to_lower() {
    for (int i = 0; i < len; i++) {
        if (cs[i] >= 'A' && cs[i] <= 'Z') cs[i] += 32;
    }
    return *this;
}

void String::print() const {
    for (int i = 0; i < len; i++) cout << cs[i];
    cout << endl;
}

ostream& operator<<(ostream& out, const String& str) {
    for (int i = 0; i < str.len; i++) {
        out << str.cs[i];
    }
    return out;
}

istream& operator>>(istream& in, String& str) {
    char ch;
    char buffer[1000];
    int i = 0;

    while (in.get(ch) && std::isspace(static_cast<unsigned char>(ch)));
    if (in.eof())
    {
        return in;
    }
    buffer[i++] = ch;
    while (in.get(ch) && !std::isspace(static_cast<unsigned char>(ch))) {
        if (i < 999) {
            
            buffer[i++] = ch;
        }
    }

    buffer[i] = '\0';
    str = String(buffer);
    return in;
}

String::~String() {
    delete[] cs;
}
