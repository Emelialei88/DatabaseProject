#pragma once
#include <string>
#include <iostream>
using namespace std;

struct People
{
    friend istream& operator>> (istream& in, People& people);
    friend ostream& operator<< (ostream& os, const People& people);

    People();
    People(const string& name, const string& email);
    bool operator == (const People& other_people);
    
    string name;
    string email;
};