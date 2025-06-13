#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
    char* cs;
    int len;
    int cap;

public:
    String();
    String(const char*);
    String(const String&);
    String(const char c, int l);
    String(int num);

    static int getlen(const char*);
    static int getlen(const String);

    String& copy(const String&);
    String itos(int);
    int stoi() const;

    String& operator=(const String&);
    String& operator+=(const String&);
    String operator+(const String&) const;

    const char& operator[](int) const;
    char& operator[](int);
    bool operator==(const String&) const;

    String& toupper();
    String& to_lower();
    String& trim();

    void regrow();
    void remove_at(int);
    void insert_at(int, char);
    void insert_at(int, const String&);
    void remove_first(char);
    void remove_last(char);
    void remove_all(char);
    void print() const;

    bool is_equal(const String&);
    bool is_greater(const String&);
    bool is_smaller(const String&);

    int find_first(char);
    int find_last(char);
    int find_first(const String&) const;
    int find_last(const String&) const;
    int* find_all(char, int&);
    int* find_all(const String&, int&) const;
    int* all_sub(const char*, int&);

    String& replace_first(char);
    ~String();

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
};

#endif
