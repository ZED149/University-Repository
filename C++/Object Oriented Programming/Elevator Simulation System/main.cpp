


#include <iostream>
using namespace std;
#include "Rider.h"
#include "Floor.h"
#include "Building.h"
#include "Elevator.h"
#include <Windows.h>
#include <map>


int main()
{
	// adding floors
	Floor f1("First Floor", 0);
	Floor f2("Second Floor", 100);
	Floor f3("Third Floor", 200);
	Floor f4("Fourth Floor", 305);
	Floor f5("Fifth Floor", 410);

	// adding elevators
	Elevator e1("IDLE", 0, 0);
	Elevator e2("going DOWN", 1, 3);
	Elevator e3("IDLE", 0, 0);

	// initializing building
	Building B1;
	// adding floors to the building
	Building::Floors.push_back(f1);
	Building::Floors.push_back(f2);
	Building::Floors.push_back(f3);
	Building::Floors.push_back(f4);
	Building::Floors.push_back(f5);
	// adding elevators to the building
	Building::Elevators.push_back(e1);
	Building::Elevators.push_back(e2);
	Building::Elevators.push_back(e3);

	int _time = 0;
	while (_time < 3)
	{
		if (_time != 0)
		{
			// now adding random riders to the random floors
			srand(time(0));
			int my_rand = rand();
			map<int, Rider> random_riders;
			random_riders.insert({ 1, Rider("Salman", 26, 0, 1, (Building::Floors[0] < Building::Floors[1]), (Building::Floors[0] > Building::Floors[1])) });
			random_riders.insert({ 2, Rider("Awais", 20, 2, 4, (Building::Floors[2] < Building::Floors[4]), (Building::Floors[2] > Building::Floors[4])) });
			random_riders.insert({ 3, Rider("Rukhma", 25, 4, 1, (Building::Floors[4] < Building::Floors[1]), (Building::Floors[4] > Building::Floors[1])) });
			random_riders.insert({ 4, Rider("Farhana", 54, 1, 4, (Building::Floors[1] < Building::Floors[4]), (Building::Floors[1] > Building::Floors[4])) });
			random_riders.insert({ 5, Rider("Shakeel", 63, 3, 1, (Building::Floors[3] < Building::Floors[1]), (Building::Floors[3] > Building::Floors[1])) });
			random_riders.insert({ 6, Rider("Shahid", 55, 3, 2, (Building::Floors[3] < Building::Floors[2]), (Building::Floors[3] > Building::Floors[2])) });
			for (int i = 0; i < 10; i++)
			{	// selecting a random rider from random_rider list
				my_rand = (rand() % 6) + 1;
				auto temp = random_riders[my_rand];
				int floor_rand = rand() % 5;
				Building::Floors[floor_rand].add_rider(temp);
			}
		}

		cout << "----------------------------------------------------------\n";
		cout << "-- Time " << _time << " ------------------------------------------------\n";
		// priting elevators in the building
		int i = 0;
		for (auto elev : Building::Elevators)
		{
			if (i == 1)
				cout << "Elevator at " << elev.starting_floor << " " << elev.state << " \t\t" << elev.riders << " riders\t\t[" << elev.starting_floor << "]" << endl;
			else
				cout << "Elevator at " << elev.starting_floor << " " << elev.state << " \t\t\t" << elev.riders << " riders\t\t" << endl;
			i++;
		}

		// now printing floors
		i = 1;
		for (auto floor : Building::Floors)
		{
			if(_time == 0)
				cout << " " << i++ << " " << floor.floor_name << "\t at\t" << floor.floor_id << "\" \tUp/Down: " << floor.getUpRiders() << "/" << floor.getDownRiders() << " \tButton: " << endl;
			else
			{
				cout << " " << i++ << " " << floor.floor_name << "\t at\t" << floor.floor_id << "\" \tUp/Down: " << floor.getUpRiders() << "/" << floor.getDownRiders();
				//cout << " \tButton: [" << endl;
				if (floor.getUpRiders() > 0 && floor.getDownRiders() > 0)
					cout << "\tButton: [Up/Down]" << endl;
				else if (floor.getUpRiders() > 0)
					cout << "\tButton: [Up]" << endl;
				else if (floor.getDownRiders() > 0)
					cout << "\tButton: [Down]" << endl;
				else
					cout << "\tButton: " << endl;
			}
		}

		_time++;
		Sleep(3000);
		cout << "Press ENTER to continue..." << endl;
		cin.get();
	}
}