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

//������ �����
string DataInput(void (*func)());
//������� ����� �� ����� ������
string DataInputChoice(void(*func)());
//�� ������ � ���
int ConvertStringToInt(string userInput);
//�� ������� ����� � tm ��������� 
tm ConvertStringToTmStruct(array<string, 3> priorityStr);
//�� ������� ����� � ������ �����
array<int, 3> ConvertStringToIntArrDate(array<string, 3> priorityStr);
//�� ������� ����� � ������ �����
array<int, 2> ConvertStringToIntArrTime(array<string, 2> timeStr);
//������� ������ � ������ ����� �����������
array<string, 3> ConvertStringToDateSeparator(string date);
//������� ������ � ������ ����� �����������
array<string, 2> ConvertStringToTimeSeparator(string date);



//��� �������
string CreateOrEditRequestInputName();
//�������� �������
string CreateOrEditRequestInputDescriptions();
//���������
int CreateOrEditRequestInputPriority();
//����
tm CreateOrEditRequestInputDate();
//�����
tm CreateOrEditRequestInputTime(tm& tmDateAndTime);

//�������� ���� ������
void MainMenu(vector< ToDoListModel>& arrayToDoListModel_vector);
//���� �������� �������(�������� �������)
void ShowToDoListMenu(vector< ToDoListModel>& arrayToDoListModel_vector);
//�������� ���������� �� 1 �� 100
bool IsInputPriorityCorrect(int priority);
//�������� ����� ���� ������ 1 - 12 ��� � ����
bool IsInputDateCorrect(array<int, 3> dateArr);
//�������� ����� ������� 00:00 - 23:59
bool IsInputTimeCorrect(array<int, 2> timeArr);

void ShowToDoList(vector< ToDoListModel>& arrayToDoListModel_vector);

// Set up the date structure
void SetupStruct(tm& DateStruct);
//��������� ���� � ��������� tm 
//void DatePlusDays(struct tm* date, int days);
//void ShowToDoListDayMenu(vector< ToDoListModel>& arrayToDoListModel_vector);











