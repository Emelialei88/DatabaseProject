#include "Database.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool Database::load(const string& database_file)
{
    ifstream fin(database_file);
    if (!fin.is_open())
    {
        cout<<"can not open file "<<database_file<<endl;
        return false;
    }
    m_database_file_path = database_file;
    //read records to your container
    //.....
    while (true)
    {
        People people;
        fin>>people;
        if (fin.eof())
        {
            break;
        }
        m_data.push_back(people);
    }
    return true;
}

void Database::print_table(void) const
{
    cout<<"all records:"<<endl;

    //your print all records code
    //..... 
    for(auto& people : m_data)
    {
        cout<<people<<endl;
    }
}

void Database::insert(const string & name, const string & email)
{
    People person(name, email);
    auto itr = find(m_data.begin(), m_data.end(), person);
    if (itr != m_data.end())
    {
        cout << name << " is already in database!" << endl;
        return;
    }
    m_data.push_back(person);
    cout << "insert success." << endl;
}

void Database::update(const string & name, const string & email)
{
    // to do your code
}

void Database::delete_record(const string & name)
{
    // to do your code 
}

void Database::save_data(void)
{
    ofstream fout(m_database_file_path);
    for (auto& item : m_data)
    {
        fout << item << endl;
    }
}
