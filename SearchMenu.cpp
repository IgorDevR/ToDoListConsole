#include "main.h"

void SearchDateTimeMenu(vector<ToDoListModel>& arrayToDoListModel_vector, string typeSearch);
void Enter_Name_Descr_Prior_DateTime_ForSearch(vector<ToDoListModel>& arrayToDoListModel_vector, string typeSearch);

void SearchMenu(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	while (true)
	{
		SearchMenuSeparatorText();
		string select = DataInputChoice(SearchMenuText);

		int selectInt = ConvertStringToInt(select);
		string typeSearch = "";

		switch (selectInt)
		{
			case 1:
				typeSearch = "n";//name 
				Enter_Name_Descr_Prior_DateTime_ForSearch(arrayToDoListModel_vector, typeSearch);
				break;
			case 2:
				typeSearch = "d";//description
				Enter_Name_Descr_Prior_DateTime_ForSearch(arrayToDoListModel_vector, typeSearch);
				break;
			case 3:
				typeSearch = "p";//priority
				Enter_Name_Descr_Prior_DateTime_ForSearch(arrayToDoListModel_vector, typeSearch);
				break;
			case 4:
				typeSearch = "d";//date and time
				SearchDateTimeMenu(arrayToDoListModel_vector, typeSearch);
				break;
			case 5:
				return; //возврат в главное меню
				break;

			default: ErrorRetyText();
				break;
		}
	}

}
void SearchDateTimeMenu(vector< ToDoListModel>& arrayToDoListModel_vector, string typeSearch)
{
	while (true)
	{
		SearchMenuSeparatorText();
		string select = DataInputChoice(SearchDateOrTimeText);

		int selectInt = ConvertStringToInt(select);
		string typeSearch = "";

		switch (selectInt)
		{
			case 1:
				typeSearch = "D";//name 
				Enter_Name_Descr_Prior_DateTime_ForSearch(arrayToDoListModel_vector, typeSearch);
				return;
			case 2:
				typeSearch = "T";//description
				Enter_Name_Descr_Prior_DateTime_ForSearch(arrayToDoListModel_vector, typeSearch);
				return;	
			case 3:
				return; //назад		
			default: ErrorRetyText();
				break;
		}
	}

}









