#include "main.h"


void SortToId(vector<ToDoListModel>& arrayToDoListModel_vector);
int RequestInput(void(*func)());
void DeleteID(vector<ToDoListModel>& arrayToDoListModel_vector, int id);
void EtidID(vector<ToDoListModel>& arrayToDoListModel_vector, int id);

//�������� ���������� ����� id ��� �������������� � ��������
bool CheckCorrectID(vector<ToDoListModel>& arrayToDoListModel_vector, int id);

void CreateToDoList(vector< ToDoListModel>& arrayToDoListModel_vector)
{

	string nameToDo = CreateOrEditRequestInputName();
	string descriptionToDo = CreateOrEditRequestInputDescriptions();
	int priorityToDo = CreateOrEditRequestInputPriority();
	tm tmDateAndTime = CreateOrEditRequestInputDate();
	tmDateAndTime = CreateOrEditRequestInputTime(tmDateAndTime);

	ToDoListModel toDoListModel(nameToDo, descriptionToDo, priorityToDo, tmDateAndTime);//����� ���������
	arrayToDoListModel_vector.push_back(toDoListModel);//��������� � ������

	NoteSuccessfullyCreatedText();
}

#pragma region edit
void EditToDoList(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	SortToId(arrayToDoListModel_vector);
	ShowToDoList(arrayToDoListModel_vector);

	bool isBack = false;
	string selectIdStr = DataInput(SelectIDForEditText);
	if (selectIdStr == "n")
	{
		CancelText();
		return;
	}
	int selectId = ConvertStringToInt(selectIdStr);
	while (!CheckCorrectID(arrayToDoListModel_vector, selectId))
	{
		ErrorRetyText();
		selectIdStr = DataInput(RetryOrBackText);//����� ������ ����������� ��� ��� ��� �������� �����
		selectId = ConvertStringToInt(selectIdStr);

		if (selectId == 2)//���� �����
		{
			isBack = true; break;
		}

		ShowToDoList(arrayToDoListModel_vector);
		selectIdStr = DataInput(SelectIDForEditText);
		selectId = ConvertStringToInt(selectIdStr);
	}
	if (isBack)
		return;

	EtidID(arrayToDoListModel_vector, selectId);
	NoteSuccessfullyEditText();
}

void EtidID(vector< ToDoListModel>& arrayToDoListModel_vector, int id)
{
	auto res = std::find_if(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(),
							[id](const ToDoListModel& obj)
	{
		return obj.Id == id;
	});
	if (res != arrayToDoListModel_vector.end())
	{
		if (RequestInput(IsChangeNameText) == 1)
		{
			res->Name = CreateOrEditRequestInputName();
			SuccessfullyText();
		}
		if (RequestInput(IsChangeDescriptionText) == 1)
		{
			res->Description = CreateOrEditRequestInputDescriptions();
			SuccessfullyText();
		}
		if (RequestInput(IsChangePriorityText) == 1)
		{
			res->Priority = CreateOrEditRequestInputPriority();
			SuccessfullyText();
		}
		if (RequestInput(IsChangeDateAndTimeText) == 1)
		{
			tm tmDateAndTime = CreateOrEditRequestInputDate();
			res->DateStruct = tmDateAndTime;
			SuccessfullyText();
		}
	}
}
#pragma endregion

#pragma region delete
void DeleteToDoList(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	SortToId(arrayToDoListModel_vector);
	ShowToDoList(arrayToDoListModel_vector);

	bool isBack = false;
	string selectIdStr = DataInput(SelectIDForDeleteText);
	if (selectIdStr == "n")
	{
		CancelText();
		return;
	}

	int selectId = ConvertStringToInt(selectIdStr);

	while (!CheckCorrectID(arrayToDoListModel_vector, selectId))
	{
		ErrorRetyText();
		selectIdStr = DataInput(RetryOrBackText);//����� ������ ����������� ��� ��� ��� �������� �����
		selectId = ConvertStringToInt(selectIdStr);

		if (selectId == 2)//���� �����
		{
			isBack = true; break;
		}

		ShowToDoList(arrayToDoListModel_vector);
		selectIdStr = DataInput(SelectIDForEditText);
		selectId = ConvertStringToInt(selectIdStr);
	}
	if (isBack)
		return;

	DeleteID(arrayToDoListModel_vector, selectId);
	NoteSuccessfullyDeleteText();
}

void DeleteID(vector< ToDoListModel>& arrayToDoListModel_vector, int id)
{
	auto res = std::find_if(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(),
							[id](const ToDoListModel& obj)
	{
		return obj.Id == id;
	});
	if (res != arrayToDoListModel_vector.end())
	{
		arrayToDoListModel_vector.erase(res);
	}
}
#pragma endregion

