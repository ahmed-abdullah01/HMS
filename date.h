#ifndef DATE_H
#define DATE_H

class Date {
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    Date& operator=(const Date& other);

    void display() const;
};

#endif
