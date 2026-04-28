#include <iostream>
#include <vector>
#include <numeric>
#include "Hierarchy.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Person*> staff; 
    int choice;

    do {
        cout << "\nМЕНЮ СИСТЕМИ" << endl;
        cout << "1. Додати Студента" << endl;
        cout << "2. Додати Лiкаря" << endl;
        cout << "3. Додати Продавця" << endl;
        cout << "4. Вивести список людей" << endl;
        cout << "5. Середнiй дохiд усiх категорiй" << endl;
        cout << "0. Вихiд" << endl;
        cout << "Ваш вибiр: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            string s, n, pass, pl;
            int y;
            cout << "Прiзвище: "; cin >> s;
            cout << "Iм'я: "; cin >> n;
            cout << "Рiк народження: "; cin >> y;
            cout << "Паспорт: "; cin >> pass;
            cout << "Мiсце роботи/навчання: "; cin >> pl;

            if (choice == 1) {
                int g[5]; cout << "Введiть 5 оцiнок: ";
                for (int i = 0; i < 5; i++) cin >> g[i];
                staff.push_back(new Student(s, n, y, pass, pl, g));
            }
            else if (choice == 2) {
                int exp, pat;
                cout << "Досвiд (рокiв): "; cin >> exp;
                cout << "Кiлькiсть пацiєнтiв: "; cin >> pat;
                staff.push_back(new Doctor(s, n, y, pass, pl, exp, pat));
            }
            else if (choice == 3) {
                int cars; cout << "Продано авто: "; cin >> cars;
                staff.push_back(new Seller(s, n, y, pass, pl, cars));
            }
        }
        else if (choice == 4) {
            cout << "\nСписок людей:" << endl;
            for (const auto& p : staff) p->displayInfo();
        }
        else if (choice == 5) {
            if (staff.empty()) { cout << "Масив порожнiй!" << endl; continue; }
            double totalIncome = 0;
            for (const auto& p : staff) totalIncome += p->calculateIncome();
            cout << "\nСереднiй дохiд усiх у списку: " << totalIncome / staff.size() << " грн" << endl;
        }

    } while (choice != 0);

    for (auto p : staff) delete p;

    return 0;
}