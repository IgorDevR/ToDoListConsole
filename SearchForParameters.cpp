#include "main.h"

void PrintSpecific(ToDoListModel& toDoListMode);

void SearchForName(vector<ToDoListModel>& arrayToDoListModel_vector, string name);
void SearchForDescription(vector<ToDoListModel>& arrayToDoListModel_vector, string description);
void SearchForPriority(vector<ToDoListModel>& arrayToDoListModel_vector, int priority);
void SearchForDate(vector<ToDoListModel>& arrayToDoListModel_vector, tm date);
void SearchForTime(vector<ToDoListModel>& arrayToDoListModel_vector, tm time);

void Enter_Name_Descr_Prior_DateTime_ForSearch(vector< ToDoListModel>& arrayToDoListModel_vector, string typeSearch)
{

	if (typeSearch == "n")
	{
		string inputUser = CreateOrEditRequestInputName();
		SearchProgressText();
		SearchForName(arrayToDoListModel_vector, inputUser);
	}

	if (typeSearch == "d")
	{
		string inputUser = CreateOrEditRequestInputDescriptions();
		SearchProgressText();
		SearchForDescription(arrayToDoListModel_vector, inputUser);
	}

	if (typeSearch == "p")
	{
		int inputUser = CreateOrEditRequestInputPriority();
		SearchProgressText();
		SearchForPriority(arrayToDoListModel_vector, inputUser);
	}

	if (typeSearch == "D")
	{
		tm tmDate = CreateOrEditRequestInputDate();
		SearchProgressText();
		SearchForDate(arrayToDoListModel_vector, tmDate);
	}

	if (typeSearch == "T")
	{
		tm tmTime = CreateOrEditRequestInputTime(tmTime);
		SearchProgressText();
		SearchForTime(arrayToDoListModel_vector, tmTime);

	}

}

void SearchForName(vector< ToDoListModel>& arrayToDoListModel_vector, string name)
{
	bool isFound = false;
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{
		if (arrayToDoListModel_vector[i].Name.find(name) != std::string::npos)
		{
			PrintSpecific(arrayToDoListModel_vector[i]);
			isFound = true;
		}
	}
	if (!isFound)
		NotFoundText();
}
void SearchForDescription(vector< ToDoListModel>& arrayToDoListModel_vector, string description)
{
	bool isFound = false;
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{
		if (arrayToDoListModel_vector[i].Description.find(description) != std::string::npos)
		{
			PrintSpecific(arrayToDoListModel_vector[i]);
			isFound = true;
		}
	}
	if (!isFound)
		NotFoundText();
}
void SearchForPriority(vector< ToDoListModel>& arrayToDoListModel_vector, int priority)
{
	bool isFound = false;
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{
		if (arrayToDoListModel_vector[i].Priority == priority)
		{
			PrintSpecific(arrayToDoListModel_vector[i]);
			isFound = true;
		}
	}
	if (!isFound)
		NotFoundText();
}

void SearchForDate(vector< ToDoListModel>& arrayToDoListModel_vector, tm date)
{
	bool isFound = false;
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{
		if (arrayToDoListModel_vector[i].DateStruct.tm_mday == date.tm_mday &&
			arrayToDoListModel_vector[i].DateStruct.tm_mon == date.tm_mon &&
			arrayToDoListModel_vector[i].DateStruct.tm_year == date.tm_year)			
		{
			PrintSpecific(arrayToDoListModel_vector[i]);
			isFound = true;
		}
	}
	if (!isFound)
		NotFoundText();
}
void SearchForTime(vector< ToDoListModel>& arrayToDoListModel_vector, tm time)
{
	bool isFound = false;
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{

		if (arrayToDoListModel_vector[i].DateStruct.tm_hour == time.tm_hour &&
			arrayToDoListModel_vector[i].DateStruct.tm_min == time.tm_min)			
		{
			PrintSpecific(arrayToDoListModel_vector[i]);
			isFound = true;
		}
	}
	if (!isFound)
		NotFoundText();
}