#include "People.h"
#include "Database.h"
#include "SQLParser.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout<<"please input the db.txt file !"<<endl;
        return -1;
    }
    cout<<"db file : "<<argv[1]<<endl;
    
    Database db;
    bool success = db.load(argv[1]);//"database.db.txt"
    if (!success)
    {
        return -1;
    }
    cout << "load db success." << endl;

    while (true)
    {
        cout<<"db>";
        string command;
        getline(cin, command);

        if (command.size() > 0)
        {
            SQLParser parser(command);
            if (parser.get_state() != SQLParser::State::GOOD)
            {
                continue;
            }
            switch (parser.get_sql_type())
            {
            case SQLParser::SQLType::SELECT:
                db.print_table(); break;
            case SQLParser::SQLType::INSERT:
                db.insert(parser.get_name(), parser.get_email()); break;
            case SQLParser::SQLType::UPDATE:
                //to do your code
                db.update(parser.get_name(), parser.get_email()); break;
            case SQLParser::SQLType::DELETE:
                //to do your code
                db.delete_record(parser.get_name()); break;
            case SQLParser::SQLType::EXIT:
                db.save_data(); 
                cout << "database exited." << endl;
                return 0;
            default:
                cout << "sql not valid!" << endl;
                break;
            }
        }
    }

    return 0;
}