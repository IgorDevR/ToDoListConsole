#include "main.h"

void PrintText(std::vector<ToDoListModel>& arrayToDoListModel_vector, int i, char  str[100], const int& SIZE);
bool CheckPeriod(std::vector<ToDoListModel>& arrayToDoListModel_vector, tm& dateStruct, int i, periodEnum period);

void ShowToDoList(vector< ToDoListModel>& arrayToDoListModel_vector )
{
	int const SIZE = 100;
	char str[SIZE];
	int size = arrayToDoListModel_vector.size();
	int cnt = 0;
	cout << "********************************" << endl;

	for (int i = 0; i < size; i++)
	{		
		cnt++;
			PrintText(arrayToDoListModel_vector, i, str, SIZE);		
	}
	cout << "Show note: " << cnt << "  Total notes: " << size << endl;
	cout << "********************************" << endl;
}

void ShowToDoListForPeriod(vector< ToDoListModel>& arrayToDoListModel_vector, tm dateStruct, periodEnum period)
{
	int const SIZE = 100;
	char str[SIZE];
	int size = arrayToDoListModel_vector.size();
	int cnt = 0;
	cout << "********************************" << endl;

	for (int i = 0; i < size; i++)
	{
		if (CheckPeriod(arrayToDoListModel_vector, dateStruct, i, period))
		{
			cnt++;
			PrintText(arrayToDoListModel_vector, i, str, SIZE);
		}
	}
	cout << "Show note: "<< cnt << "  Total notes: " << size << endl;
	cout << "********************************" << endl;
}



void PrintText(std::vector<ToDoListModel>& arrayToDoListModel_vector, int i, char  str[100], const int& SIZE)
{
	cout << "--------------------------------" << endl;
	cout << "ID to-do list: " << arrayToDoListModel_vector[i].Id << endl;
	cout << "Name to-do list: " << arrayToDoListModel_vector[i].Name << endl;
	cout << "Description to-do list: " << arrayToDoListModel_vector[i].Description << endl;
	cout << "Priority to-do list: " << arrayToDoListModel_vector[i].Priority << endl;
	strftime(str, SIZE, "%d.%m.%Y\t%H:%M", &arrayToDoListModel_vector[i].DateStruct);
	cout << "Date and time to-do list: " << str << endl;
	cout << "--------------------------------" << endl;
}


void PrintSpecific(ToDoListModel& toDoListMode)
{
	int const SIZE = 100;
	char str[SIZE];

	cout << "--------------------------------" << endl;
	cout << "ID to-do list: " << toDoListMode.Id << endl;
	cout << "Name to-do list: " << toDoListMode.Name << endl;
	cout << "Description to-do list: " << toDoListMode.Description << endl;
	cout << "Priority to-do list: " << toDoListMode.Priority << endl;
	strftime(str, SIZE, "%d.%m.%Y\t%H:%M", &toDoListMode.DateStruct);
	cout << "Date and time to-do list: " << str << endl;
	cout << "--------------------------------" << endl;
}