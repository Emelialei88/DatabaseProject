#include "SQLParser.h"
#include <sstream>
#include <iostream>

SQLParser::SQLParser(const string & command)
    :m_state(State::GOOD)
{
    parser(command);
}

SQLParser::SQLType SQLParser::get_sql_type(void) const
{
    return m_type;
}

const string & SQLParser::get_name(void) const
{
    return m_name;
}

const string & SQLParser::get_email(void) const
{
    return m_email;
}

SQLParser::State SQLParser::get_state(void) const
{
    return m_state;
}

void SQLParser::parser(const string& command)
{
    //insert liubei lb@qq.com
    //update zhangfei newemail@qq.com 
    //delete zhangfei
    //select *
    //exit
    if (command.size() < 4)
    {
        m_type = SQLType::UNKNOWN;
        return;
    }
    istringstream iss(command);
    string operatorWord;
    iss >> operatorWord;
    
    if (operatorWord == "insert")
    {
        m_type = SQLType::INSERT;
        iss >> m_name >> m_email;
        if (m_name.empty() || m_email.empty())
        {
            m_state = State::BAD;
            cout << "not valid insert! without name or email." << endl;
        }
    }
    else if (operatorWord == "update")
    {
        m_type = SQLType::UPDATE;
        iss >> m_name >> m_email;
        if (m_name.empty() || m_email.empty())
        {
            m_state = State::BAD;
            cout << "not valid update! without name or email." << endl;
        }
    }
    else if (operatorWord == "delete")
    {
        // to do your code
        m_type = SQLType::DELETE;
        iss >> m_name;
        if (m_name.empty()) 
        {
            m_state = State::BAD;
            cout << "not valid delete! without name." << endl;
        }
    }
    else if (operatorWord == "select")
    {
        m_type = SQLType::SELECT;
        string next;
        iss >> next;
        if (next != "*")
        {
            m_state = State::BAD;
            cout << "not valid select * !";
        }
    }
    else if (operatorWord == "exit")
    {
        m_type = SQLType::EXIT;
    }
    else
    {
        m_type = SQLType::UNKNOWN;
        m_state = State::BAD;
    }
}
