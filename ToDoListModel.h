#pragma once
#include <string>
#include <iostream>
#include <array>
using namespace std;

static int ID;

class ToDoListModel
{
public:
	struct DataTimeStruct;

	ToDoListModel(string name, string description, int priority, tm tmDateAndTime);
	ToDoListModel();

	int Id;

	string Name;
	int Priority;
	string Description;

	tm DateStruct;	

private:
	
};


