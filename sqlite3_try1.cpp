//this is some code for experimenting using cpp to run sql commands

#include <iostream>
// #include <sqlite3.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3_driver.hpp"

using namespace std;


int main (int argc, char* argv[]){
    sql_driver mysql_driver;
    // sqlite3 *db;
    const char * databaseName;
    databaseName = "mydatabases/testDatabase.db";
    int rc;
    string sqlcmd;
    
    /*open database*/
    mysql_driver.open_database(databaseName);
    string  tname;
    string c1;
    string c2;
    string c3;
    
    tname = "user_entries";
    c1 = "username";
    c2 = "password";
    c3 = "salt";

    mysql_driver.make_3_coloumn_table(tname,c1,c2,c3);
    
    
    return 0;
}
