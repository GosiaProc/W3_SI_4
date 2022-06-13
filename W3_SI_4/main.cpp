#include<iostream>
#include<fstream>
#include <string>
#include<ctime>
#include<vector>
#include <sstream>
#include <locale>
#include <iomanip>
using namespace std;

struct task {
	string taskscontent;
	string status = "[ ]";
	time_t date;
	int priorytet;

	bool isUrgent() {
		time_t now = time(0);
		int diff = (date - now)/60/60/24;
		return (diff<3);
	}

	bool isImportant() {
		return (priorytet < 3);
	}

	void setDate2(int d, int m) {
		tm time = {};
		time.tm_year = 2022;
		time.tm_mon = m - 1;
		time.tm_mday = d - 1;
		date = mktime(&time);
	}

	void setDate(string input) {
		tm timeInStruct = {};
		stringstream mystream("2022-" + input);
		mystream >> std::get_time(&timeInStruct, "%Y-%d-%m");
		date = mktime(&timeInStruct);
	}
};

void readtasks(task* taskstable)

{
	for (int i = 0; i < 4; i++)
	{
		cout << "### ZADNIE NR: " << i + 1 << " ###" << endl;
		getline(cin >> ws, taskstable[i].taskscontent);
		cout << "Podaj priorytet zadania " << i + 1 << " (od 1 do 5):" << endl;
		cin >> taskstable[i].priorytet;
		cout << "Podaj deadline zadania: " << i + 1 << endl;
		cin >> taskstable[i].date;
	}
}

void displaytasks(vector<task> taskstable) {
	for (int i = 0; i < taskstable.size(); i++)
	{
		cout << taskstable[i].status << " "
			<< taskstable[i].date << " "
			<< taskstable[i].taskscontent << " "
			<< taskstable[i].priorytet << endl;
	}
}

vector<task> read_from_file() {
	vector<task> tasks;

	fstream fin;
	fin.open("tasks.csv", ios::in);
	string line;

	getline(fin, line, '\n');
	while (getline(fin, line, '\n')) {
		cout << " to jest linnia: " << line << endl;
		cout << "dzielenie linni na czesci:" << endl;

		stringstream lineStream(line);
		vector<string> task_properties;
		string substr;
		while (getline(lineStream, substr, ','))
		{
			task_properties.push_back(substr);
			//cout << substr << std::endl;
		}
		for (int i = 0; i < task_properties.size(); i++)
			cout << i << "  " << task_properties[i] << std::endl;

		task t;

		//t.date = stoi(task_properties[2]);
		t.taskscontent = task_properties[3];
		t.status = task_properties[1];
		t.priorytet = stoi(task_properties[4]);
		tasks.push_back(t);
	}
	return tasks;
}

int main() {

	vector<task> tasks = read_from_file();

	displaytasks(tasks);
/*	int m = 5;
	int d = 12;

	string today= "12-6";

	tm timeInStruct = {};
	stringstream mystream("2022-" + today);
	mystream >> std::get_time(&timeInStruct, "%Y-%d-%m");
	time_t timestamp = mktime(&timeInStruct);
*/
}

/*

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
	
*/