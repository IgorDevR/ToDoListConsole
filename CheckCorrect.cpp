#include "main.h"


bool ConverDataPlusPeriod(tm& tmDate, periodEnum period);

bool IsInputPriorityCorrect(int priority)
{
	if (priority >= 1 && priority <= 100)
		return true;


	return false;

}

bool IsInputDateCorrect(array <int,3> dateArr)
{	
	if(dateArr[2] / 1000 == 0)
		return false;

	switch (dateArr[1] >= 1 && dateArr[1] <= 12)
	{	
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (dateArr[0] >= 1 && dateArr[0] <= 31)
				return true;		
			break;

		case 2:
			if (dateArr[0] >= 1 && dateArr[0] <= 28)
				return true;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			if (dateArr[0] >= 1 && dateArr[0] <= 30)
				return true;
			break;
		

		default:
			return false;
	}
	return false;

}
bool IsInputTimeCorrect(array <int, 2> timeArr)
{
	if ((timeArr[0] >= 0 && timeArr[0] <= 23) &&
		(timeArr[1] >= 0 && timeArr[1] <= 59))
		return true;

	return false;

}



bool CheckCorrectID(vector< ToDoListModel>& arrayToDoListModel_vector, int id)
{
	auto res = std::find_if(arrayToDoListModel_vector.begin(), arrayToDoListModel_vector.end(),
							[id](const ToDoListModel& obj)
	{
		return obj.Id == id;
	});
	if (res != arrayToDoListModel_vector.end())
	{
		return true;
	}

	return false;

}

bool CheckCorrectFileNameToSave(string fileName)
{
	if (fileName.find(" ") != std::string::npos)
	{
		return false;
	}
	return true;

}

bool CheckPeriod(std::vector<ToDoListModel>& a, tm& dateStructStart, int i, periodEnum period)
{
	bool periodComp = false;

	tm dateStructEnd = dateStructStart;
	ConverDataPlusPeriod(dateStructEnd, period);
	
	int aTime = (a[i].DateStruct.tm_year * 1000) + (a[i].DateStruct.tm_mon * 100) + (a[i].DateStruct.tm_mday);
	int startTime = (dateStructStart.tm_year * 1000) + (dateStructStart.tm_mon * 100) + (dateStructStart.tm_mday);
	int endTime = (dateStructEnd.tm_year * 1000) + (dateStructEnd.tm_mon * 100) + (dateStructEnd.tm_mday);

	if(period == periodEnum::day)
	periodComp =
			aTime == startTime && 
			aTime == endTime;
	else
		periodComp =
		aTime >= startTime &&
		aTime < endTime;	

	return periodComp;
}