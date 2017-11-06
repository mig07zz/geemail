#this is some code for messing around with sql databases;
#author: Miguel 
#date created: 10/31/17

import sqlite3

class createDatabases(object):

    def __init__(self,databaseName = "database"):
       print ("this might be populated later, or not...")
       self.database = self.create_new_database(databaseName)
       self.cursor = self.database.cursor()

    def create_new_database(self,databasename = "default"):
        return sqlite3.connect(databasename+".db")

    def check_if_table_exists(self,tablename = "tablename"):
        sql_cmd = """
        SELECT COUNT(*)
        FROM information_schema.tables
        WHERE table_name = {tablename}
        """.format(**locals())
        self.cursor.execute(sql_cmd)
        if self.cursor.fetchone()[0] == 1:
            return True
        return False
        
    def create_users_table(self):
        if (self.check_if_table_exists("users_table")):
            return 
        else:
            command_str = """
            CREATE TABLE users_table(
                user_id INTEGER PRIMARY KEY,
                user_name VARCHAR(20),
                password VARCHAR(64)     
            );"""
            self.cursor.execute(command_str)
        return

    def get_all_entries(self,table = "tableName"):
        self.cursor.execute("SELECT * FROM {table}".format(**locals()))
        print(self.cursor.fetchall())

    def new_user_entry(self,*vals):
        assert (len(vals)==3), "wrong number of inputs"
        ID = vals[0]
        usrnm = vals[1]
        psswd = vals[2]
        sql_cmd = """
        INSERT INTO users_table(user_name,password)
        VALUES({usrnm},{psswd});
        """.format(**locals())
        print sql_cmd
        self.cursor.execute(sql_cmd)

        







if __name__=="__main__":
    myDatabase = createDatabases()
    # myDatabase.get_all_entries(0)
    # myDatabase.create_users_table()
    myDatabase.new_user_entry(1,"'migo'","'pass'")
    myDatabase.get_all_entries("'users_table'")
