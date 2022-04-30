#pragma once
#include <iostream>
#include <optional>
#include <tuple>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


class Person
{
private:
    string surname;
    string name;
    optional<string> secondName;

public:
    Person() = default;
    Person(const string& psurname, const string& pname, const optional<string>& psecondName) {};

    friend ostream& operator<< (const Person& p, ostream& stream);

    friend bool operator< (const Person& p1, const Person& p2);

    friend bool operator== (const Person& p1, const Person& p2);
};

class PhoneNumber
{
private:

    int countryCode;
    int cityCode;
    string number;
    optional<string> additNum;

public:
    PhoneNumber() = default;
    PhoneNumber(const int& pcontryCode, const int& pcityCode, const string& pnumber,const optional<string>& padditNum) {};
    
    friend ostream& operator<< (const PhoneNumber& pn, ostream& stream);

    friend bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2);

    friend bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2);

};


ostream& operator<< (const Person& p, ostream& os)
{
    os << p.surname << ' ';
    os << p.name << ' ';
    if (p.secondName)
    {
        os << *p.secondName << ' ';
    }

    return os;
}

bool operator< (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.secondName) < tie(p2.surname, p2.name, p2.secondName);
}

bool operator== (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.secondName) == tie(p2.surname, p2.name, p2.secondName);
}

ostream& operator<< (const PhoneNumber& pn, ostream& os)
{
    os << "+" << pn.countryCode;
    os << "(" << pn.cityCode << ")";
    os << pn.number;
    if (pn.additNum)
    {
        os << *pn.additNum;
    }
}

bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2)
{
    return tie(pn1.countryCode, pn1.cityCode, pn1.number, pn1.additNum) < tie(pn2.countryCode, pn2.cityCode, pn2.number, pn2.additNum);
}

bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2)
{
    return tie(pn1.countryCode, pn1.cityCode, pn1.number, pn1.additNum) == tie(pn2.countryCode, pn2.cityCode, pn2.number, pn2.additNum);
}

class Less {
public:
    
    bool operator() (const pair<Person, PhoneNumber>& left, const pair<Person, PhoneNumber>& right)
    {
        if (left.first == right.first)
            return left.second < right.second;
        else
            return left.first < right.first;
    }
};