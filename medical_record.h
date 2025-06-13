#ifndef MEDICAL_RECORD_H
#define MEDICAL_RECORD_H

#include "String.h"
#include "dynamic_array.h"

class MedicalRecord {
    Dynamic_array<String> history;

public:
    void add_entry(const String& entry);
    void print() const;
};

#endif
