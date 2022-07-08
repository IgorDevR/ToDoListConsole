#include "main.h"




void SortToPriority(vector<ToDoListModel>& arrayToDoListModel_vector);
void SortToDate(vector< ToDoListModel>& arrayToDoListModel_vector);
//�������� �� �������� ����
void ShowToDoListPer_Day_Week_Month(vector< ToDoListModel>& arrayToDoListModel_vector, array <string, 3>, periodEnum period);
//������������� ��������� ����, � ����� ����������
void ShowByDataAndSortBeforePrinDisplay(vector<ToDoListModel>& arrayToDoListModel_vector, typeSortEnum typeSort, periodEnum period, bool currentDay);
//���� ����������
void ShowSortMenu(vector< ToDoListModel>& arrayToDoListModel_vector, periodEnum period);
//�������� �� �������� ��� ��� ������� ����
void ShowCurrentDayOrSelectDateMenu(vector<ToDoListModel>& arrayToDoListModel_vector, typeSortEnum typeSort, periodEnum period);

void ShowToDoListMenu(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	
	while (true)
	{
		
		VeiwSeparatorText();
		string select = DataInputChoice(ShowMenuText);
		int period;
		int selectInt = ConvertStringToInt(select);		
		switch (selectInt)
		{
			case 1:
				ShowSortMenu(arrayToDoListModel_vector, periodEnum::day);
				break;
			case 2:			
				ShowSortMenu(arrayToDoListModel_vector, periodEnum::week);
				break;
			case 3:
				ShowSortMenu(arrayToDoListModel_vector, periodEnum::month);
				break;
			case 4:
				ShowSortMenu(arrayToDoListModel_vector, periodEnum::all);
			case 5:
				break;
			default: ErrorRetyText();
				break;
		}
	}
}

void ShowSortMenu(vector< ToDoListModel>& arrayToDoListModel_vector, periodEnum period)
{

	while (true)
	{
		VeiwSeparatorText();
		string select = DataInputChoice(SortShowMenuText);

		int selectInt = ConvertStringToInt(select);
		
		switch (selectInt)
		{
			case 1://����������� �� ����������				
				ShowCurrentDayOrSelectDateMenu(arrayToDoListModel_vector,typeSortEnum::priority, period);
				break;
			case 2://����������� �� ����				
				ShowCurrentDayOrSelectDateMenu(arrayToDoListModel_vector, typeSortEnum::date, period);
				break;
			case 3://�� �����������				
				ShowCurrentDayOrSelectDateMenu(arrayToDoListModel_vector, typeSortEnum::notSort, period);
				break;
			case 4://����� �� 1 �����
				ShowToDoListMenu(arrayToDoListModel_vector);
				break;
			case 5:
				MainMenu(arrayToDoListModel_vector);
				break;
			default: ErrorRetyText();
				break;
		}
	}
}

void ShowCurrentDayOrSelectDateMenu(vector< ToDoListModel>& arrayToDoListModel_vector, typeSortEnum typeSort, periodEnum period)
{
	if (period == periodEnum::all)
	{
		ShowByDataAndSortBeforePrinDisplay(arrayToDoListModel_vector, typeSort, period, true);
		return;
	}

	while (true)
	{
		VeiwSeparatorText();
		string select = DataInputChoice(ShowCurrentDayOrSelectDateText);

		int selectInt = ConvertStringToInt(select);
		bool currentDay = false;
		switch (selectInt)
		{
			case 1://�� �������� ���
				currentDay = true;
				ShowByDataAndSortBeforePrinDisplay(arrayToDoListModel_vector,  typeSort, period, currentDay);
				break;
			case 2:// ������� ����
				currentDay = false;
				ShowByDataAndSortBeforePrinDisplay(arrayToDoListModel_vector, typeSort, period,  currentDay);
				break;
			case 3://����� �� 1 �����
				ShowToDoListMenu(arrayToDoListModel_vector);
				break;
			case 4:
				MainMenu(arrayToDoListModel_vector);
				break;
			default: ErrorRetyText();
				break;
		}
	}
}

void ShowByDataAndSortBeforePrinDisplay(vector< ToDoListModel>& arrayToDoListModel_vector, typeSortEnum typeSort, periodEnum period, bool currentDay)
{	
	array <string, 3> dateToDoStr;
	if (!currentDay)
	{
		string dateToDoStrDataInput = DataInput(DateExecutionEnterNoteText);
		dateToDoStr = ConvertStringToDateSeparator(dateToDoStrDataInput);//���� � ������ [0]-day [1]-month [2]-year
		array <int, 3>dateToDo = ConvertStringToIntArrDate(dateToDoStr);//������� � ��� ������
		while (!IsInputDateCorrect(dateToDo))//�������� �� ����������� ����� ����
		{
			ErrorRetyText();
			dateToDoStrDataInput = DataInput(DateExecutionEnterNoteText);
			dateToDoStr = ConvertStringToDateSeparator(dateToDoStrDataInput);
			dateToDo = ConvertStringToIntArrDate(dateToDoStr);
		}		
	}
	else
	{
		std::time_t t = std::time(0);   // get time now
		std::tm* now = std::localtime(&t);
		dateToDoStr[0] = to_string(now->tm_mday);
		dateToDoStr[1] = to_string(now->tm_mon);
		dateToDoStr[2] = to_string(now->tm_year);
	}


	if (typeSort == typeSortEnum::priority)
		SortToPriority(arrayToDoListModel_vector);

	else if (typeSort == typeSortEnum::date)
		SortToDate(arrayToDoListModel_vector);

	if (period == periodEnum::all)//�������� ��� �� ���� ������
	{
		ShowToDoList(arrayToDoListModel_vector);
		return;
	}	
		ShowToDoListPer_Day_Week_Month(arrayToDoListModel_vector, dateToDoStr, period);
	

	ShowToDoListMenu(arrayToDoListModel_vector);
}






