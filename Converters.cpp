#include "main.h"

#pragma region date and time

array <string, 3> ConvertStringToDateSeparator(string date)
{
	array <string, 3> dateArrStr = { "", "","" };
	char delim = '.';

	int i = 0, k = 0;
	while (date[i] != '\0')
	{
		if (date[i] == delim)
		{
			k++; i++;
		}
		dateArrStr[k] += date[i];
		i++;
	}
	return dateArrStr;
}

array <string, 2> ConvertStringToTimeSeparator(string date)
{
	array <string, 2> dateArrStr = { "", "" };
	char delim = ':';

	int i = 0, k = 0;
	while (date[i] != '\0')
	{
		if (date[i] == delim)
		{
			k++; i++;
		}
		dateArrStr[k] += date[i];
		i++;
	}
	return dateArrStr;
}

array<int, 3> ConvertStringToIntArrDate(array <string, 3> dateArrStr)
{
	array<int, 3> dateArrInt = { -1,-1,-1 };
	for (int i = 0; i < dateArrStr.size(); i++)
	{
		try
		{
			// string -> integer
			dateArrInt[i] = std::stoi(dateArrStr[i]);

		}
		catch (...)
		{
			// error management			
			return dateArrInt;
		}
	}

	return dateArrInt;
}
array<int, 2> ConvertStringToIntArrTime(array <string, 2> timeArrStr)
{
	array<int, 2> timeArrint = { -1,-1 };
	for (int i = 0; i < timeArrStr.size(); i++)
	{
		try
		{
			// string -> integer
			timeArrint[i] = std::stoi(timeArrStr[i]);

		}
		catch (...)
		{
			// error management			
			return timeArrint;
		}
	}

	return timeArrint;
}

tm ConvertStringToTmStruct(array <string, 3> priorityStr)
{
	int temp;
	tm dateStruct = { 0,0,0 };

	temp = dateStruct.tm_mday = std::stoi(priorityStr[0]);
	temp = dateStruct.tm_mon = std::stoi(priorityStr[1]);
	temp = dateStruct.tm_year = std::stoi(priorityStr[2]);

	SetupStruct(dateStruct);

	return dateStruct;
}
#pragma endregion


int ConvertStringToInt(string string)
{
	try
	{
		// string -> integer
		int numInt = std::stoi(string);
		return numInt;
	}
	catch (...)
	{
		// error management
		return -1;
	}

}


//void DatePlusDays(struct tm* date, int days)
//{
//	const time_t ONE_DAY = 24 * 60 * 60;
//
//	// Seconds since start of epoch
//	time_t date_seconds = mktime(date) + (days * ONE_DAY);
//
//	// Update caller date
//	// Use localtime because mktime converts to UTC so may change date
//	*date = *localtime(&date_seconds);
//}



//void ConverDataToPeriod(array <string, 3>& dataArr)
//{
//	int numMount = ConvertStringToInt(dataArr[1]);
//	int periodInt;
//	if (numMount >= 1 && numMount <= 12)
//		switch (numMount)
//		{
//			case 1:
//			case 3:
//			case 5:
//			case 7:
//			case 8:
//			case 10:
//			case 12:
//				dataArr[0] = "31";
//				break;
//			case 2:
//				dataArr[0] = "28";
//				break;
//			case 4:
//			case 6:
//			case 9:
//			case 11:
//				dataArr[0] = "30";
//				break;
//			default:
//				break;
//		}
//}
bool ConverDataPlusPeriod(tm& tmDate, periodEnum period)
{
	if (tmDate.tm_year / 100 == 0)
		return false;

	if (period == periodEnum::day)
		return true;

	if (period == periodEnum::week)
		tmDate.tm_mday = tmDate.tm_mon + 7;

	if (period == periodEnum::month)
		tmDate.tm_mon = tmDate.tm_mon + 1;

	

	if (tmDate.tm_mon == 0 || tmDate.tm_mon == 2 || tmDate.tm_mon == 4 ||//c учетом tm структуры индекс с 0
		tmDate.tm_mon == 6 || tmDate.tm_mon == 7 || tmDate.tm_mon == 9 ||
		tmDate.tm_mon == 11)
	{
		if (tmDate.tm_mday > 31)
		{
			tmDate.tm_mday = tmDate.tm_mday - 31;
			tmDate.tm_mon++;
		}

	}
	if (tmDate.tm_mon == 1)
	{
		if (tmDate.tm_mday > 28)
		{
			tmDate.tm_mday = tmDate.tm_mday - 28;
			tmDate.tm_mon++;
		}
	}
	if (tmDate.tm_mon == 3 || tmDate.tm_mon == 5 || tmDate.tm_mon == 8 || tmDate.tm_mon == 10)
	{
		if (tmDate.tm_mday > 30)
		{
			tmDate.tm_mday = tmDate.tm_mday - 30;
			tmDate.tm_mon++;
		}
	}


	return true;

}