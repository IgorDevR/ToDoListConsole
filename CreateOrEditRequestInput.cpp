#include "main.h"

string CreateOrEditRequestInputName()
{
	string nameToDo = DataInput(NameEnterNoteText);
	return nameToDo;
}

string CreateOrEditRequestInputDescriptions()
{
	string descriptionToDo = DataInput(DescriptionEnterNoteText);
	return descriptionToDo;
}
int CreateOrEditRequestInputPriority()
{
	string priorityToDoStr = DataInput(PriorityEnterNoteText);
	int priorityToDo = ConvertStringToInt(priorityToDoStr);	//������� ���������� � ���
	while (!IsInputPriorityCorrect(priorityToDo))//������� �� �������� 1-100
	{
		ErrorRetyText();
		priorityToDoStr = DataInput(PriorityEnterNoteText);
		priorityToDo = ConvertStringToInt(priorityToDoStr);
	}
	return priorityToDo;
}
tm CreateOrEditRequestInputDate()
{
	string dateToDoStrDataInput = DataInput(DateExecutionEnterNoteText);
	array <string, 3> dateToDoStr = ConvertStringToDateSeparator(dateToDoStrDataInput);//���� � ������ [0]-day [1]-month [2]-year
	array <int, 3>dateToDo = ConvertStringToIntArrDate(dateToDoStr);//������� � ��� ������
	while (!IsInputDateCorrect(dateToDo))//�������� �� ����������� ����� ����
	{
		ErrorRetyText();
		dateToDoStrDataInput = DataInput(DateExecutionEnterNoteText);
		dateToDoStr = ConvertStringToDateSeparator(dateToDoStrDataInput);
		dateToDo = ConvertStringToIntArrDate(dateToDoStr);
	}
	tm tmDateAndTime = { 0,0,0 };
	tmDateAndTime.tm_mday = dateToDo[0];
	tmDateAndTime.tm_mon = dateToDo[1];
	tmDateAndTime.tm_year = dateToDo[2];

	SetupStruct(tmDateAndTime);	

	return tmDateAndTime;
}

tm CreateOrEditRequestInputTime(tm& tmDateAndTime)
{
	string timeToDoStrInput = DataInput(TimeExecutionEnterNoteText);
	array <string, 2> timeToDoStr = ConvertStringToTimeSeparator(timeToDoStrInput);//���� � ������ [0]-HH [1]-MM 
	array <int, 2>timeToDo = ConvertStringToIntArrTime(timeToDoStr);//������� � ��� ������
	while (!IsInputTimeCorrect(timeToDo))//�������� �� ����������� ����� ����
	{
		ErrorRetyText();
		timeToDoStrInput = DataInput(TimeExecutionEnterNoteText);
		timeToDoStr = ConvertStringToTimeSeparator(timeToDoStrInput);
		timeToDo = ConvertStringToIntArrTime(timeToDoStr);
	}
	tmDateAndTime.tm_hour = timeToDo[0];
	tmDateAndTime.tm_min = timeToDo[1];

	return tmDateAndTime;
}