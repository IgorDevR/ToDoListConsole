#include "main.h"

void ManualFillForDebug(vector< ToDoListModel>& arrayToDoListModel_vector);


int main()
{
	vector< ToDoListModel> ArrayToDoListModel_vector;

	ManualFillForDebug(ArrayToDoListModel_vector);

	StartText();

	MainMenu(ArrayToDoListModel_vector);



}