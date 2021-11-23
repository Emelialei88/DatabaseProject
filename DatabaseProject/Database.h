#include "People.h"
#include <string>
using namespace std;
#include <vector>

class Database
{
public:
    bool load(const string& database_file);
    void print_table(void) const;
    void insert(const string& name, const string& email);
    void update(const string& name, const string& email);
    void delete_record(const string& name);
    void save_data(void);
private:
    vector<People> m_data;
    string m_database_file_path;
};