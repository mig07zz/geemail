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
   
   table_3col_t users_table;
   users_table.tableName = "user_entries";
   users_table.col1 = "username";
   users_table.col2 = "password";
   users_table.col3 = "salt";
        // string  tname;
    // string c1;
    // string c2;
    // string c3;
    
    // tname = "user_entries";
    // c1 = "username";
    // c2 = "password";
    // c3 = "salt";
    cout<<"making a table.................."<<endl;
    mysql_driver.make_3_coloumn_table(users_table.tableName,users_table.col1,users_table.col2,users_table.col3);
    
    
    int id = 1;
    cout<<"back in main"<<endl;
    cout<<"testing the insert function"<<endl;
    mysql_driver.insert_into_3_col_table(&users_table,id,"miguel","password","salt");
    cout<<"back from main"<<endl;
    id++;
    cout<<"testing the insert function"<<endl;
    mysql_driver.insert_into_3_col_table(&users_table,id,"ukulele","password2","salt2");
    cout<<"back from main"<<endl;
    
    
    cout<<"testing the show table function"<<endl;
    mysql_driver.show_table_3col(&users_table);
    cout<<"back in main"<<endl;
    cout<<"dropping a table: "<<users_table.tableName<<endl;
    mysql_driver.drop_table(users_table.tableName);
    
    return 0;
}
