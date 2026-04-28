#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <iostream>
#include <vector>
#include <string>

class Person {
protected:
    std::string surname, name, passport, place;
    int birthYear;

public:
    Person(std::string s, std::string n, int y, std::string pass, std::string pl)
        : surname(s), name(n), birthYear(y), passport(pass), place(pl) {
    }

    virtual ~Person() {}

    virtual double calculateIncome() const = 0;

    int getAge() const { return 2026 - birthYear; }

    virtual std::string getCategory() const = 0;

    void displayInfo() const {
        std::cout << getCategory() << ": " << surname << " " << name
            << " | Вiк: " << getAge()
            << " | Дохiд: " << calculateIncome() << " грн" << std::endl;
    }
};


class Student : public Person {
    int grades[5];
public:
    Student(std::string s, std::string n, int y, std::string pass, std::string pl, int g[])
        : Person(s, n, y, pass, pl) {
        for (int i = 0; i < 5; i++) grades[i] = g[i];
    }
    double calculateIncome() const override {
        double avg = 0;
        for (int i = 0; i < 5; i++) avg += grades[i];
        return (avg / 5.0) * 500; 
    }
    std::string getCategory() const override { return "Студент"; }
};

class Doctor : public Person {
    int experience, patients;
public:
    Doctor(std::string s, std::string n, int y, std::string pass, std::string pl, int exp, int pat)
        : Person(s, n, y, pass, pl), experience(exp), patients(pat) {
    }

    double calculateIncome() const override {
        return 5000 + (experience * 100) + (patients * 50);
    }
    std::string getCategory() const override { return "Лiкар"; }
};

class Seller : public Person {
    int carsSold;
public:
    Seller(std::string s, std::string n, int y, std::string pass, std::string pl, int cars)
        : Person(s, n, y, pass, pl), carsSold(cars) {
    }

    double calculateIncome() const override {
        return carsSold * 3000; 
    }
    std::string getCategory() const override { return "Продавець"; }
};

#endif