#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "DifM1.h"
#include <tuple>
using namespace std;

class PhoneBook : public Person, public PhoneBook
{
protected:
    vector<pair<Person, PhoneNumber>> record;
public:
    string surname, name;
    optional<string> secondName;
    int countryCode, cityCode;
    string number;
    optional<string> additNum;
    PhoneBook() = default;
    PhoneBook(ifstream& file) {
        
        if (file.is_open())
        {
            while (file >> surname >> name >> secondName.emplace() >> countryCode >> cityCode >> number >> additNum.emplace())
            {
                if (secondName.has_value())
                    if (secondName.value() == "-")
                        secondName = nullopt;
                Person person(surname, name, secondName);
                if (additNum.has_value())
                    if (additNum.value() == "-")
                        additNum = nullopt;
                    else
                        additNum.emplace() = stoi(additNum.value());

                PhoneNumber phoneNum(countryCode, cityCode, number, additNum);

                record.push_back(make_pair(person, phoneNum));
            }
        }
        file.close();
    };

    void SortByName();
    
    void SortByPhone();
    
    tuple<string, PhoneNumber> GetPhoneNumber(const string& surname);
    
    void ChangePhoneNumber(const Person& person, const PhoneNumber& newPhNum);

    friend ostream& operator<< (ostream& out, PhoneBook book);
    
};

ostream& operator<< (ostream& out, PhoneBook book)
{
    for (const auto& [person, number] : book.record)
    {
        out << person << setw(5) << number << endl;
    }
    return out;
}

void PhoneBook::SortByName()
{
    Less less;
    sort(record.begin(), record.end(), less);
}

void PhoneBook::SortByPhone()
{
    Less less;
    sort(record.begin(), record.end(),less);
}

tuple <string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& ssurname)
{
    int count = 0;
    for (const auto& [person, number] : record)
    {
        if (person.person == ssurname)
        {
            count++;
        }
    }
    if (count == 0) {
        cout << "Not found!" << endl;
    }
    else if (count == 1)
        cout << "" << endl;

    else if (count > 1){
        cout << "Found more than 1!" << endl;
   }     
}

void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& newPhNum)
{
    auto find_rec = std::find_if(record.begin(), record.end(),
        [&person](const auto& rec)
        {
            return rec.first == person;
        });
    if (find_rec != record.end()) find_rec->second = newPhNum;
}



int main()
{
    ifstream file("PhoneBook.txt"); 
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
    
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "915544", 13 });
    cout << book;

    return 0;
}

