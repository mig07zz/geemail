/*
this is a class to use sqlite commands using cpp
*/

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

extern sqlite3 *db;
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
class sql_driver{
    
    public:
        char *zErrMsg = 0;
        int rc;
        sql_driver();
        void open_database(const char * db_name);
        void make_3_coloumn_table(string tablename,string c1,string c2,string c3);
    private:
    
};