#include "main.h"


void CreateToDoList(vector< ToDoListModel>& arrayToDoListModel_vector);
void EditToDoList(vector<ToDoListModel>& arrayToDoListModel_vector);
void DeleteToDoList(vector<ToDoListModel>& arrayToDoListModel_vector);

void RedactionMenu(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	while (true)
	{
		RedactionMenuSeparatorText();
		string select = DataInputChoice(CreateEditDeleteMenuText);

		int selectInt = ConvertStringToInt(select);

		switch (selectInt)
		{
			case 1:
				CreateToDoList(arrayToDoListModel_vector);
				break;
			case 2:
				EditToDoList(arrayToDoListModel_vector);
				break;
			case 3:
				DeleteToDoList(arrayToDoListModel_vector);
				break;
			case 4:
				MainMenu(arrayToDoListModel_vector);
				break;
			default: ErrorRetyText();
				break;
		}
	}
}

void DeleteAll(vector< ToDoListModel>& arrayToDoListModel_vector)
{

	arrayToDoListModel_vector.clear();

}