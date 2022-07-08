#include "main.h"


bool SearchFileToDirectory();
bool CheckCorrectFileNameToSave(string fileName);

void Save(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	string select = DataInput(EnterNameFileToSaveText);

	while (!CheckCorrectFileNameToSave(select))
	{
		select = DataInput(EnterNameFileToSaveText);
	}
	string extension = ".todo.txt";
	string PATH = select + extension;

	ofstream outText;
	outText.open(PATH);

	try
	{
		if (!outText.is_open())
		{
			ErrorSaveDataText();
		}
		else
		{
			for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
			{						
				outText << arrayToDoListModel_vector[i].Id << "\n";
				outText << arrayToDoListModel_vector[i].Name<< "\n";				
				outText << arrayToDoListModel_vector[i].Description<< "\n";				
				outText << arrayToDoListModel_vector[i].Priority<< "\n";				

				outText << arrayToDoListModel_vector[i].DateStruct.tm_year<< "\n";				
				outText << arrayToDoListModel_vector[i].DateStruct.tm_mon<< "\n";				
				outText << arrayToDoListModel_vector[i].DateStruct.tm_mday<< "\n";				
				outText << arrayToDoListModel_vector[i].DateStruct.tm_hour<< "\n";				
				outText << arrayToDoListModel_vector[i].DateStruct.tm_min<< "\n";
				
			}
		}
	}
	catch (const std::exception&)
	{
		outText.close();
	}
	outText.close();
	SuccessfullyText();


	//FILE* out = NULL;
	//const char* path = PATH.c_str();;

	//if ((fopen_s(&out, path, "w")) != NULL)
	//	ErrorSaveDataText();
	//else
	//{
	//	for (int i = 0; i < arrayToDoListModel_vector.size(); i++)
	//	{
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].Id);
	//		fprintf(out, "\n");
	//		fprintf(out, "%s ", arrayToDoListModel_vector[i].Name.c_str());
	//		fprintf(out, "\n");
	//		fprintf(out, "%s ", arrayToDoListModel_vector[i].Description.c_str());
	//		fprintf(out, "\n");
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].Priority);
	//		fprintf(out, "\n");

	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].DateStruct.tm_year);
	//		fprintf(out, "\n");
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].DateStruct.tm_mon);
	//		fprintf(out, "\n");
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].DateStruct.tm_mday);
	//		fprintf(out, "\n");
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].DateStruct.tm_hour);
	//		fprintf(out, "\n");
	//		fprintf(out, "%d ", arrayToDoListModel_vector[i].DateStruct.tm_min);
	//		fprintf(out, "\n");
	//	}
	//}
	//fclose(out);
}

void Load(vector< ToDoListModel>& arrayToDoListModel_vector)
{
	if (!SearchFileToDirectory())
	{
		return;
	}

	string select = DataInput(EnterNameForLoadText);

	while (!CheckCorrectFileNameToSave(select))
	{
		select = DataInputChoice(EnterNameForLoadText);
	}

	std::string line;

	std::ifstream in(select); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			ToDoListModel toDoListModel;
			
			toDoListModel.Id = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.Name = line;
			getline(in, line);
			toDoListModel.Description = line;
			getline(in, line);
			toDoListModel.Priority = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.DateStruct.tm_year = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.DateStruct.tm_mon = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.DateStruct.tm_mday = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.DateStruct.tm_hour = ConvertStringToInt(line);
			getline(in, line);
			toDoListModel.DateStruct.tm_min = ConvertStringToInt(line);

			arrayToDoListModel_vector.push_back(toDoListModel);
		}
	}
	in.close();     // закрываем файл

	SuccessfullyText();
}

bool SearchFileToDirectory()
{
	SearchSaveFileText();

	WIN32_FIND_DATAW wfd;

	HANDLE const hFind = FindFirstFileW(L"*.todo.txt", &wfd);

	int cnt = 0;
	if (INVALID_HANDLE_VALUE != hFind)
	{
		FindFileText();
		do
		{
			cnt++;
			std::wcout << &wfd.cFileName[0] << std::endl;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}
	if (cnt == 0)
	{
		NotFoundFileForLoadText();
		return false;
	}
	return true;
}


