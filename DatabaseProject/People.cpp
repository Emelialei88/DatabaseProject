#include "People.h"
#include <iomanip>

istream& operator>> (istream& is, People& people)
{
    is >> people.name;
    is >> people.email;
    return is;
}

ostream& operator<< (ostream& os, const People& people)
{
    return os <<setw(15)<<left<<people.name
              <<setw(20)<<left<<people.email;
}

People::People()
{
}

People::People(const string & name1, const string & email1)
    :name(name1)
    ,email(email1)
{
    if (name.empty())
    {
        cout << "not valid name : empty name." << endl;
    }
}

bool People::operator==(const People & other_people)
{
    return this->name == other_people.name;
}
