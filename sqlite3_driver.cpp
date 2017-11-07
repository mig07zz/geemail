#include "sqlite3_driver.hpp"
// #include <sqlite3.h>

sqlite3 *db;


static int callback(void *NotUsed, int argc, char **argv, char **azColName){
       int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

// CLASS STUFF============================

sql_driver::sql_driver(){}

void sql_driver::open_database(const char * db_name){
    int rc;
    
    /*open database*/
    rc = sqlite3_open(db_name,&db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        // return;
    } else {
        fprintf(stderr, "Opened database successfully %d\n",rc);
    }
    // sqlite3_close(db);
}



void sql_driver::make_3_coloumn_table(string tablename,string c1,string c2, string c3){ // need to check input to make sure it does not overflow
    // char* sql_cmd;
    char buffer[800];
    char* zErrMsg2 = 0;
    //bullshit conversion
    const char * tname = tablename.c_str();
    const char * col1 = c1.c_str();
    const char * col2 = c2.c_str();
    const char * col3 = c3.c_str();
         
     sprintf(buffer,
     "CREATE TABLE %s ("  \
     "ID INT PRIMARY KEY NOT NULL AUTO INCREMENT," \
     "%s TEXT NOT NULL," \
     "%s TEXT NOT NULL," \
     "%s TEXT );",
     tname,col1,col2,col3);
     
     const char* sql_cmd;
     sql_cmd = buffer;
     
     sql_driver::rc = sqlite3_exec(db,sql_cmd,callback,0,&zErrMsg2);
    
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
        
}

void sql_driver::insert_into_3_col_table(table_3col_t * t,string c1,string c2,string c3){
    char buffer[800];
    char * Errormsg = 0;
    int rc;
    const char * tname = t->tableName.c_str();
    const char * col1 = t->col1.c_str();
    const char * col2 = t->col2.c_str();
    const char * col3 = t->col3.c_str();
    const char * val1 = c1.c_str();
    const char * val2 = c2.c_str();
    const char * val3 = c3.c_str();
    
    sprintf(buffer,
    "INSERT INTO %s (%s,%s,%s)"\
    "VALUES ('%s', '%s', '%s');",
    tname,col1,col2,col3,val1,val2,val3);
    
     const char* sql_cmd;
     sql_cmd = buffer;
    
    rc = sqlite3_exec(db,sql_cmd,callback,0,&Errormsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error on insert Funct: %s\n", Errormsg);
        sqlite3_free(Errormsg);
    } else {
        fprintf(stdout, "insertion successful\n");
    }
    
    
}