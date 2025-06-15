# 🏥 Hospital Management System (C++ OOP Final Project)

This is a console-based Hospital Management System developed in C++ as a final project for the Object-Oriented Programming (OOP) course.

It demonstrates the use of advanced OOP principles including inheritance, polymorphism, composition, templates, file handling, and a custom `String` and `Dynamic_array` implementation.

---

## 💡 Features

- 🔐 User Authentication (Admin, Doctor, Patient)
- 🧑‍⚕️ Doctor Signup with Department
- 📅 Patient Appointment Booking (One Doctor per Patient)
- 🏨 Room Booking System (with room limits and unbooking option)
- 🧾 Billing System
- 💊 Pharmacy Module (Medicine listing & patient purchases)
- 📋 Medical Records with History and Disease Tracking
- 🏛 Admin Dashboard:
  - View all Patients, Doctors, Booked Rooms, and Medicines

---

## 🧰 Technologies & Concepts Used

- C++ (Object-Oriented Programming)
- Custom `String` and `Dynamic_array` classes (Generic Templates)
- File Handling (`fstream`)
- Class Relationships:
  - Inheritance (User → Doctor, Patient, Admin)
  - Composition (Pharmacy is a part of Hospital)
  - Aggregation (Patient linked with Doctor, Room, Pharmacy)
- Exception Handling
- Split header/source files
- CLI-based user interface

