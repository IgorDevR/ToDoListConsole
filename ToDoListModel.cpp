#include "ToDoListModel.h"


ToDoListModel::ToDoListModel(string name, string description, int priority, tm tmDateAndTime)
{
	Id = ++ID;

	Name = name;
	Description = description;
	Priority = priority;
	
	DateStruct = { 0,0,0,0,0,0,0,0,0 };
	DateStruct = tmDateAndTime;
}
ToDoListModel::ToDoListModel()
{

	Name = "";
	Description = "";
	Priority = 0;

	DateStruct = { 0,0,0,0,0,0,0,0,0 };


}


