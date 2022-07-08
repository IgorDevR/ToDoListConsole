#include "main.h"

string DataInput(void (*func)())
{
	cout << endl;
	string userInput;

	while (true)
	{
		func();
		

		getline(cin, userInput);

		if (userInput == "")
		{
			
			ErrorRetyText();
			continue;
		}
		cout << endl;
		return userInput;
	}

	return userInput = "";
}

string DataInputChoice(void (*func)())
{
	cout << endl;
	string userInput;

	while (true)
	{
		func();		
		ChoiceText();

		getline(cin, userInput);

		if (userInput == "")
		{

			ErrorRetyText();
			continue;
		}
		cout << endl;
		return userInput;
	}

	return NULL;
}

int  RequestInput(void (*func)())
{
	string str = DataInputChoice(func);
	int number = ConvertStringToInt(str);
	return number;
}




