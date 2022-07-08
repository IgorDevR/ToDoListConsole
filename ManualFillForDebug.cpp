#include "main.h";


void ManualFillForDebug(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	string select = DataInputChoice(FillForDebugText);
	int selectInt = ConvertStringToInt(select);
	if (selectInt != 1)
		return;


	string	nameToDo = "manualFill 1";
	string	descriptionToDo = "this is manual Fill 1";
	int	priorityToDoStr = 5;
	tm tmDateAndTime = { 0,31,12, 4,1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel1(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel1);

	nameToDo = "manualFill 2";
	descriptionToDo = "this is manual Fill 2";
	priorityToDoStr = 8;
	tmDateAndTime = { 0,32,12, 1,1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel2(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel2);

	nameToDo = "manualFill 3";
	descriptionToDo = "this is manual Fill 3";
	priorityToDoStr = 11;
	tmDateAndTime = { 0,33,12, 3,1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel3(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel3);

	nameToDo = "manualFill 4";
	descriptionToDo = "this is manual Fill 4";
	priorityToDoStr = 2;
	tmDateAndTime = { 0,34,12, 7, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel4(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel4);

	nameToDo = "manualFill 5 ";
	descriptionToDo = "this is manual Fill 5";
	priorityToDoStr = 32;
	tmDateAndTime = { 0,35,12, 9, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel5(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel5);

	nameToDo = "manualFill 6 ";
	descriptionToDo = "this is manual Fill 6";
	priorityToDoStr = 44;
	tmDateAndTime = { 0,36,12, 7, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel6(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel6);

	nameToDo = "manualFill 7 END MONTH __";
	descriptionToDo = "this is manual Fill 7";
	priorityToDoStr = 76;
	tmDateAndTime = { 0,37,12, 31, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel7(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel7);

	nameToDo = "manualFill 8 NEW MONTH __";
	descriptionToDo = "this is manual Fill 8";
	priorityToDoStr = 29;
	tmDateAndTime = { 0,38,12, 1, 2, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel8(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel8);

	nameToDo = "manualFill 9";
	descriptionToDo = "this is manual Fill 9";
	priorityToDoStr = 51;
	tmDateAndTime = { 0,39,12, 15, 2, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel9(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel9);

	nameToDo = "manualFill 10";
	descriptionToDo = "this is manual Fil l0";
	priorityToDoStr = 42;
	tmDateAndTime = { 0,40,12, 16, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel10(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel10);

	nameToDo = "11";
	descriptionToDo = "22";
	priorityToDoStr = 12;
	tmDateAndTime = { 0,41,12, 2, 1, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel11(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel11);

	nameToDo = "11";
	descriptionToDo = "22";
	priorityToDoStr = 13;
	tmDateAndTime = { 0,42,12, 6, 2, 2000 ,0,0,0};
	SetupStruct(tmDateAndTime);

	ToDoListModel toDoListModel12(nameToDo, descriptionToDo, priorityToDoStr, tmDateAndTime);
	arrayToDoListModel_vector.push_back(toDoListModel12);
}