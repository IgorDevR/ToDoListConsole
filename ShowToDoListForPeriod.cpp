#include "main.h"



//������� ���� �� 30 ��� 7 ���� �� �������� ����
//void ConverDataToPeriod(array <string, 3>& dataArr);

void ShowToDoListForPeriod(vector<ToDoListModel>& arrayToDoListModel_vector, tm dateStruct, periodEnum period);


void ShowToDoListPer_Day_Week_Month(vector< ToDoListModel>& arrayToDoListModel_vector, array <string, 3> dateArrStr, periodEnum period)
{
	
	tm dateStruct = ConvertStringToTmStruct(dateArrStr);

	ShowToDoListForPeriod(arrayToDoListModel_vector, dateStruct, period);
	
}






