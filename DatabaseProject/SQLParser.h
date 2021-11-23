#pragma once
#include <string>
using namespace std;


class SQLParser
{
public:
    enum class SQLType
    {
        UNKNOWN,
        SELECT,
        INSERT,
        UPDATE,
        DELETE,
        EXIT,
    };
    enum class State
    {
        GOOD,
        BAD,
    };
    SQLParser(const string& command);
    SQLType get_sql_type(void) const;
    const string& get_name(void) const;
    const string& get_email(void) const;
    State get_state(void) const;
private:
    void parser(const string& command);
private:
    SQLType m_type;
    string m_name;
    string m_email;
    State m_state;
};

