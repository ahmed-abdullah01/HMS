#ifndef PHARMACY_H
#define PHARMACY_H

#include "String.h"
#include "dynamic_array.h"
#include <fstream>
#include <iostream>

class Medicine {
public:
    String name;
    int price;

    Medicine() : name("nil"), price(0) {}  

    Medicine(const String& n, int p) : name(n), price(p) {}
    Medicine(const Medicine& other):name(other.name),price(other.price){}
};

class Pharmacy {
    Dynamic_array<Medicine> stock;

public:
    Pharmacy();

    void load_medicines();
    void show_all() const;
    bool get_price(const String& name, int& price) const;

    void buy_medicines(Dynamic_array<String>& bought, int& total_cost);
};

#endif
