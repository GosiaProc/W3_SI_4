#include<iostream>
#include<fstream>
#include <string>
#include<ctime>
/*
using std::cout;
using std::cin;
using std::string;
using std::fstream;
*/
using namespace std;

/*class task {
	string status;
	string taskscontent;
	time_t date;
	int priorytet;

};
*/


int main() {

	
		string zadanie;
		cout<<"podaj zadanie";
		cin >> zadanie;
		cout << zadanie;

	std::cout
		<< "    |                           URGENT | NOT URGENT                       |\n"
		   " -- | -------------------------------- | -------------------------------- | --\n"
		   "    |                          |                                  |\n"
		   "    |                                  |                                  |\n"
		   " I  |                                  |                                  |\n"
		   " M  |                                  |                                  |\n"
		   " P  |                                  |                                  |\n"
		   " O  |                                  |                                  |\n"
		   " R  |                                  |                                  |\n"
		   " T  |                                  |                                  |\n"
		   " A  |                                  |                                  |\n"
		   " N  |                                  |                                  |\n"
		   " T  |                                  |                                  |\n"
		   "    |                                  |                                  |\n"
		   "    |                                  |                                  |\n"
		   " -- | -------------------------------- | -------------------------------- | --\n"
		   "    |                                  |                                  |\n" 
		   " N  |                                  |                                  |\n"
		   " O  |                                  |                                  |\n"
		   " T  |                                  |                                  |\n"
		   "    |                                  |                                  |\n"
		   " I  |                                  |                                  |\n"
		   " P  |                                  |                                  |\n"
		   " O  |                                  |                                  |\n"
		   " R  |                                  |                                  |\n"
		   " T  |                                  |                                  |\n"
		   " A  |                                  |                                  |\n"
		   " N  |                                  |                                  |\n"
		   " T  |                                  |                                  |\n"
		   " -- | -------------------------------- | -------------------------------- | --\n";
	fstream plik;
	plik.open("macierz.csv", ios::out | ios::app);
	plik << zadanie << endl;
	plik.close();
	return 0;
}