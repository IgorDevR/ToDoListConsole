#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "ToDoListModel.h"
#include <ctime>
#include <functional>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <filesystem>
using namespace std;
 
 enum periodEnum
{	
	day,
	week,
	month,
	year,
	all,
};

 enum typeSortEnum
 {	
	 priority,
	 date,
	 notSort,
 };

void MainMenuText();
void NameEnterNoteText();
void PriorityEnterNoteText();
void DateExecutionEnterNoteText();
void TimeExecutionEnterNoteText();
void DateDisplayEnterNoteText();
void SelectIDForEditText();
void SelectIDForDeleteText();
void RetryOrBackText();
void CancelText();
void DescriptionEnterNoteText();
void NotSortext();
void NoteSuccessfullyCreatedText();
void NoteSuccessfullyEditText();
void NoteSuccessfullyDeleteText();
void SuccessfullyText();
void ErrorRetyText();
void ErrorSaveDataText();
void ErrorLoadDataText();
void NotFoundText();
void SearchProgressText();
void ChoiceText();
void FillForDebugText();
void StartText();
void CreateEditDeleteMenuText();
void SearchMenuText();
void ShowMenuText();
void SortShowMenuText();
void ShowCurrentDayOrSelectDateText();
void IsChangeNameText();
void IsChangeDescriptionText();
void IsChangePriorityText();
void IsChangeDateAndTimeText();
void MainMenuSeparatorText();
void SearchMenuSeparatorText();
void VeiwSeparatorText();
void RedactionMenuSeparatorText();
void SearchDateOrTimeText();
void EnterNameFileToSaveText();
void EnterNameFileToLoadText();
void SearchSaveFileText();
void FindFileText();
void EnterNameForLoadText();
void NotFoundFileForLoadText();

//запрос ввода
string DataInput(void (*func)());
//завпрос ввода на новой строке
string DataInputChoice(void(*func)());
//из строки в инт
int ConvertStringToInt(string userInput);
//из массива строк в tm структуру 
tm ConvertStringToTmStruct(array<string, 3> priorityStr);
//из массива строк в массив интов
array<int, 3> ConvertStringToIntArrDate(array<string, 3> priorityStr);
//из массива строк в массив интов
array<int, 2> ConvertStringToIntArrTime(array<string, 2> timeStr);
//конверт строки в массив через разделитель
array<string, 3> ConvertStringToDateSeparator(string date);
//конверт строки в массив через разделитель
array<string, 2> ConvertStringToTimeSeparator(string date);



//имя заметки
string CreateOrEditRequestInputName();
//описание заметки
string CreateOrEditRequestInputDescriptions();
//приоритет
int CreateOrEditRequestInputPriority();
//дата
tm CreateOrEditRequestInputDate();
//время
tm CreateOrEditRequestInputTime(tm& tmDateAndTime);

//основное меню выбора
void MainMenu(vector< ToDoListModel>& arrayToDoListModel_vector);
//меню показать заметки(основное подменю)
void ShowToDoListMenu(vector< ToDoListModel>& arrayToDoListModel_vector);
//проверка приоритета от 1 до 100
bool IsInputPriorityCorrect(int priority);
//проверка ввода даты месяцы 1 - 12 дни и года
bool IsInputDateCorrect(array<int, 3> dateArr);
//проверка ввода времени 00:00 - 23:59
bool IsInputTimeCorrect(array<int, 2> timeArr);

void ShowToDoList(vector< ToDoListModel>& arrayToDoListModel_vector);

// Set up the date structure
void SetupStruct(tm& DateStruct);
//прибавить дней к структуре tm 
//void DatePlusDays(struct tm* date, int days);
//void ShowToDoListDayMenu(vector< ToDoListModel>& arrayToDoListModel_vector);











