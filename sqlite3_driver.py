#this is some code for utilizing python to manipulate sql
#author: Miguel 
#date created: 11/2/17

import os
import sqlite3



class sql_driver (object):

    def __init__(self):
        print ("available databases:")
        for file_ in os.listdir("mydatabases"):
            if file_.endswith(".db"):
                print(file_) 
        self.database = sqlite3.connect("database.db")   #by default connects to a database
        self.cursor = self.database.cursor() 

    def create_new_database(self,databaseName):
        self.connect_to_database(databaseName)
        self.update_cursor()

    def connect_to_database(self,database = 'database.db'):
        self.database = sqlite3.connect(database)
    
    def update_cursor(self):
        self.cursor = self.database.cursor()
    
    def create_table(self,table_entries,*table_vals):
        


if __name__=="__main__":
    mydb = sql_driver()
    mydb.create_new_database("mydatabases/database2.db")
    