#include "pharmacy.h"
using namespace std;
Pharmacy::Pharmacy() {
    load_medicines();
}

void Pharmacy::load_medicines() {
    ifstream file("medicines.txt");
    if (!file.is_open()) {
        cout << "Failed to load medicines.txt\n";
        return;
    }

    String name;
    int price;

    while (file >> name >> price) {
        stock.push(Medicine(name, price));
    }

    file.close();
}

void Pharmacy::show_all() const {
    cout << "Available Medicines:\n";
    for (int i = 0; i < stock.size(); i++) {
        stock[i].name.print();
        cout << " - Rs. " << stock[i].price << endl;
    }
}

bool Pharmacy::get_price(const String& name, int& price) const {
    for (int i = 0; i < stock.size(); i++) {
        if (stock[i].name == name) {
            price = stock[i].price;
            return true;
        }
    }
    return false;
}

void Pharmacy::buy_medicines(Dynamic_array<String>& meds, int& total_med_cost) {
    while (true) {
        system("cls");
        show_all();

        cout << "\nEnter medicine name to buy (or 0 to exit): ";
        String name;
        cin >> name;

        if (name == "0") {
            break;
        }

        int price;
        if (get_price(name, price)) {
            meds.push(name);
            total_med_cost += price;
            cout << name << " added to cart. Price: " << price << endl;
        }
        else {
            cout << "Medicine not found.\n";
        }

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }
}



