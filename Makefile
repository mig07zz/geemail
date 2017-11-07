all: sql_D

sql_D: main.o driver.o
	g++ main.o driver.o -o sql_D -l sqlite3 -std=c++11
	
main.o: sqlite3_try1.cpp
	g++ -c sqlite3_try1.cpp -o main.o -std=c++11
	
driver.o: sqlite3_driver.cpp
	g++ -c sqlite3_driver.cpp -o driver.o -std=c++11
	
clean:
	rm *o sql_D