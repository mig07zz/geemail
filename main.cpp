//this is some code for experimenting using cpp to run sql commands

#include <iostream>
// #include <sqlite3.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3_driver.hpp"

using namespace std;


void print_bucket(vector<bucket8_t> &b){
    
    for (int i =0;i<b.size();i++){
        cout<<"printing contents of bucket-------"<<endl;
        cout<<b[i].val0<<"|"<<b[i].val1<<"|"<<b[i].val2<<"|"<<b[i].val3<<"|"<<endl;
        cout<<b[i].val4<<"|"<<b[i].val5<<"|"<<b[i].val6<<"|"<<b[i].val7<<"|"<<endl;
    }
}


int main (int argc, char* argv[]){
    sql_driver mysql_driver;
    // sqlite3 *db;
    const char * databaseName;
    databaseName = "mydatabases/testDatabase.db";
    int rc;
    string sqlcmd;
    
    /*open database*/
    mysql_driver.open_database(databaseName);
    
    vector<User_t> users_table;
    string tableName = "testTable";
    
  
    mysql_driver.make_users_table(tableName,"username","password","salt");
    // cout<<"this is the vector size"<<users_table.size()<<endl;
    // mysql_driver.populate_users_table(&users_table,tableName);
    // cout<<"table has been populated, now inserting a new value"<<endl;
    // cout<<"this is the vector size"<<users_table.size()<<endl;
    
    
    User_t new_entry;
    new_entry.username = "potato";
    new_entry.password = "paper";
    new_entry.salt = 1235;
    
    cout<<"entering a new user--------------"<<endl;
    mysql_driver.insert_user(tableName,new_entry);
    cout<<"this is the vector size"<<users_table.size()<<endl;
    
    cout<<"deleting an old user......"<<endl;
    
    string old_user = "tea";
 
    mysql_driver.delete_user(tableName,"tea");
//   cout<<"here888888888888888888";
    vector<bucket8_t> bucket;
    
    mysql_driver.get_all_usernames(tableName,bucket);
    // cout<<"here888888888888888888"<<endl;
    print_bucket(bucket);
    // cout<<"getting all users the search way"<<endl;    
    // for (int i=0;i<users_table.size();i++){
    //     cout<<"username: "<<users_table[i].username<<endl;
    //     cout<<"password: "<<users_table[i].password<<endl;
    //     cout<<"salt:     "<<users_table[i].salt<<endl;
    //     cout<<"----------------------------------------"<<endl;
    // }
    
    // mysql_driver.quick_table_view(tableName);

//email table tests****************************************
    cout<<"making email table......"<<endl;
    string emailT_name = "Emails_table";
    vector<Message_t> emails_list;
    mysql_driver.make_email_table(emailT_name,"receiver","sender","time_stamp","message","read","password","salt");
    cout<<"email table has been created..."<<endl;
    Message_t new_email;
    new_email.receiver = "fouad";
    new_email.sender ="potato";
    new_email.time_stamp = "11/9/2017-17:30:50";
    new_email.message = "test";
    new_email.read = 0;
    new_email.password = "qscft";
    new_email.salt = atoi("pepper");
    
    mysql_driver.insert_email(emailT_name,new_email);
    
    cout<<"testing the delete entry fucntion"<<endl;
    mysql_driver.delete_entry(emailT_name,"message","test");
    
    mysql_driver.update_entry(emailT_name,"read","sender","fouad","1");
    // mysql_driver.quick_table_view(emailT_name);
    
    // mysql_driver.conditional_search(emailT_name,"read","1",bucket);
    mysql_driver.double_condition_search(emailT_name,"sender","potato","receiver","fouad",bucket);
    
    print_bucket(bucket);
    
    mysql_driver.close_database();
    
    return 0;
}
