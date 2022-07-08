#include "main.h"



//static string AppName = "To do list";
//static string ButtonAdd = "Add";
//static string ButtonDelete = "Delete";
//static string ButtonEdit = "Edit";


void NameEnterNoteText()
{
	cout << "Enter note name(part of the note): ";
}

void DescriptionEnterNoteText()
{
	cout << "Enter note descriptions(part of the note): ";
}
void PriorityEnterNoteText()
{
	cout << "Enter note priority(1 - 100): ";
}
void DateExecutionEnterNoteText()
{
	cout << "Enter note date of execution(format 10.01.2022): ";
}
void TimeExecutionEnterNoteText()
{
	cout << "Enter note time of execution(format 20:45): ";
}

void DateDisplayEnterNoteText()
{
	cout << "Enter a date to display the note: ";
}

void SelectIDForEditText()
{
	cout << "Type n to cancel. ";
	cout << " Select ID for edit: ";

}
void SelectIDForDeleteText()
{
	cout << "Type n to cancel. ";
	cout << " Select ID for delete: ";
}

void RetryOrBackText()
{
	cout << "1 - Repeat ID entry " << endl;
	cout << "2 - Ñome back" << endl;
}
void CancelText()
{
	cout << "Cancel" << endl;
	cout << "---------------------" << endl;

}
void NotSortext()
{
	cout << "Not Sort" << endl;

}
void NoteSuccessfullyCreatedText()
{
	cout << "Note successfully created" << endl;
	cout << "---------------------" << endl;

}
void NoteSuccessfullyEditText()
{
	cout << "Note successfully edit" << endl;
	cout << "---------------------" << endl;

}
void NoteSuccessfullyDeleteText()
{
	cout << "Note successfully delete" << endl;
	cout << "---------------------" << endl;

}
void SuccessfullyText()
{
	cout << "---------------------" << endl;
	cout << "Successfully." << endl;
	cout << "---------------------" << endl;

}
void ErrorRetyText()
{
	cout << "Error. Retry...." << endl;
	cout << "---------------------" << endl;
}

void ErrorSaveDataText()
{
	cout << "Error save data" << endl;
}
void ErrorLoadDataText()
{
	cout << "Error load data, check correct neme file" << endl;
}
void NotFoundText()
{
	cout << "Not found...." << endl;
	cout << "---------------------" << endl;
}

void SearchProgressText()
{
	cout << "Search in progress...." << endl;
}
void ChoiceText()
{
	cout << "Choice: ";
}

void FillForDebugText()
{
	cout << "---------------------" << endl;
	cout << "1 - Fill in notes for debugging" << endl;
	cout << "2 - Skip" << endl;
	cout << "---------------------" << endl;
}

void StartText()
{
	cout << "---------------------" << endl;
	cout << "\tTo-do list" << endl;
	cout << "---------------------" << endl;
}

void MainMenuText()
{
	cout << "1 - Create/edit/delete to-do list" << endl;
	cout << "2 - Search to-do list" << endl;
	cout << "3 - To-do list view" << endl;
	cout << "4 - Safe to file" << endl;
	cout << "5 - Load from file" << endl;
	cout << "6 - delete all to-do list" << endl;
}

void CreateEditDeleteMenuText()
{	
	cout << "1 - Create new to-do list" << endl;
	cout << "2 - Edit to-do list" << endl;
	cout << "3 - Delete to-do list" << endl;
	cout << "4 - Back to main menu" << endl;
}

void SearchMenuText()
{
	cout << "1 - Search cases by name" << endl;
	cout << "2 - Search cases by descriptions" << endl;
	cout << "3 - Search cases by priority" << endl;
	cout << "4 - Search cases by date or time of execution" << endl;
	cout << "5 - Back to main menu" << endl;
}


void ShowMenuText()
{
	cout << "1 - To-do list display: per day" << endl;
	cout << "2 - To-do list display: per week" << endl;
	cout << "3 - To-do list display: per month" << endl;
	cout << "4 - To-do list display: All" << endl;
	cout << "5 - Back to main menu" << endl;
}

void SortShowMenuText()
{
	cout << "1 - Show sorted by priority" << endl;
	cout << "2 - Show sorted by date and time" << endl;
	cout << "3 - Not Sort" << endl;
	cout << "4 - Come back" << endl;
	cout << "5 - Back to main menu" << endl;
}

void ShowCurrentDayOrSelectDateText()
{
	cout << "1 - Show from current day" << endl;
	cout << "2 - Select date" << endl;
	cout << "3 - Come back" << endl;
	cout << "4 - Back to main menu" << endl;
}

void IsChangeNameText()
{
	cout << "1 - Change name" << endl;
	cout << "2 - Skip" << endl;
}
void IsChangeDescriptionText()
{
	cout << "1 - Change description" << endl;
	cout << "2 - Skip" << endl;
}
void IsChangePriorityText()
{
	cout << "1 - Change priority" << endl;
	cout << "2 - Skip" << endl;
}
void IsChangeDateAndTimeText()
{
	cout << "1 - Change date and time" << endl;
	cout << "2 - Skip" << endl;
}

void MainMenuSeparatorText()
{
	cout << "_____________________Main_Menu_____________________" << endl;
}
void SearchMenuSeparatorText()
{
	cout << "_____________________Search_Menu_____________________" << endl;
}
void VeiwSeparatorText()
{
	cout << "_____________________View_Menu_____________________" << endl;
}
void RedactionMenuSeparatorText()
{
	cout << "_____________________Redaction_Menu_____________________" << endl;
}

void SearchDateOrTimeText()
{
	cout << "1 - Search by data" << endl;
	cout << "2 - Search by time" << endl;
	cout << "3 - Come back" << endl;
}

void EnterNameFileToSaveText()
{	
	cout << "Enter a filename to save (one word without spaces): ";
}
void EnterNameFileToLoadText()
{
	cout << "Enter a filename to save: ";
}

void SearchSaveFileText()
{
	cout << "Search save file....." << endl;
}

void FindFileText()
{
	cout << "Find file:" << endl;
}
void EnterNameForLoadText()
{
	cout << "Enter file name for load: ";
}
void NotFoundFileForLoadText()
{
	cout << "No file found for load: " << endl;
}