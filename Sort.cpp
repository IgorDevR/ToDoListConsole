#include "main.h"

//сортировка приоритет
bool compPrior(const ToDoListModel& a, const ToDoListModel& b);
//сортировка дата
bool compDate(const ToDoListModel& a, const ToDoListModel& b);
//сорт Id 
bool compId(const ToDoListModel& a, const ToDoListModel& b);


void SortToPriority(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	{
		sort(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(), compPrior);
	}
	
}

void SortToDate(vector< ToDoListModel>& arrayToDoListModel_vector)
{	
	{
		sort(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(), compDate);
	}
}

void SortToId(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	sort(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(), compId);}


bool compPrior(const ToDoListModel& a, const ToDoListModel& b)
{
	return a.Priority < b.Priority;
}


bool compDate(const ToDoListModel& a, const ToDoListModel& b)
{	
	int aTime = (a.DateStruct.tm_year * 1000) + (a.DateStruct.tm_mon * 100) + (a.DateStruct.tm_mday);
	int bTime = (b.DateStruct.tm_year * 1000) + (b.DateStruct.tm_mon * 100) + (b.DateStruct.tm_mday);

	bool tmp = aTime < bTime;


	return tmp;		
}

bool compId(const ToDoListModel& a, const ToDoListModel& b)
{
	return a.Id < b.Id;
}

void SetupStruct(tm& DateStruct)
{
	DateStruct.tm_year -= 1900;
	DateStruct.tm_mon -= 1;  // note: zero indexed
	//DateStruct.tm_mday// note: not zero indexed
}