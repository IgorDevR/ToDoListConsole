#include "main.h"

void SearchMenu(vector< ToDoListModel>& arrayToDoListModel_vector);
void Save(vector< ToDoListModel>& arrayToDoListModel_vector);
void Load(vector< ToDoListModel>& arrayToDoListModel_vector);
void DeleteAll(vector< ToDoListModel>& arrayToDoListModel_vector);

void RedactionMenu(vector< ToDoListModel>& arrayToDoListModel_vector);


void MainMenu(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	while (true)
	{
		MainMenuSeparatorText();
		string select = DataInputChoice(MainMenuText);

		int selectInt = ConvertStringToInt(select);

		switch (selectInt)
		{
			case 1:
				RedactionMenu(arrayToDoListModel_vector);
				break;
			case 2:
				SearchMenu(arrayToDoListModel_vector);
				break;
			case 3:
				ShowToDoListMenu(arrayToDoListModel_vector);
				break;
			case 4:
				Save(arrayToDoListModel_vector);
				break;
			case 5:
				Load(arrayToDoListModel_vector);
				break;
			case 6:
				DeleteAll(arrayToDoListModel_vector);
				break;
			default: ErrorRetyText();
				break;
		}
	}
}



