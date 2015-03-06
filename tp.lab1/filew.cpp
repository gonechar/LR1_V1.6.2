#define _CRT_SECURE_NO_WARNINGS 1
#include "tp.lab1.h"
using namespace std;

void filew::fcreate()
{
	if (fname1 == "" )
	{
		cout << "b)Error! Empty file name! Enter file name!" << endl;
		return;
	}
	else
	{
		char *temp2 = new char[strlen(fname1)];
		strcpy(temp2, fname1);
		int i = strlen(temp2) - 1;
		while (temp2[i] != '\\')
		{
			i--;
		}
		i++;
		temp2[i] = '\0';
		if (_access(fname1, 0)&&!_access(temp2,0))
		{
			ofstream desc(fname1); cout << "z)Successful" << endl;
		}
		else
			cout << "g) cant create file" << endl;
	}
}
void filew::fdelete()
{
	if (fname1 == "")
	{
		cout << "b)Error! Empty file name! Enter file name!" << endl;
		return;
	}
	else
	{
		char *temp = new char[strlen(fname1) + 5];
		strcpy(temp,"DEL ");
		strcat(temp, fname1);
		if (!_access(fname1, 0))
		{
			system(temp); cout << "z)Successful" << endl;
		}
		else
			cout << "g)file not found" << endl;
	}
}
void filew::fcopy()
{
	if (fname1 == "" || fname2 == "")
	{
		cout << "b)Error! Empty file name! Enter file name!" << endl;
		return;
	}
	else
	{
		char *temp = new char[strlen(fname1) + strlen(fname2) + 15];
		strcpy(temp,"COPY ");
		strcat(temp, fname1);
		strcat(temp, " ");
		strcat(temp,fname2);
		char *temp2 = new char[strlen(fname1)];
		strcpy(temp2, fname1);
		int i = strlen(temp2) - 1;
		while (temp2[i] != '\\')
		{
			i--;
		}
		i++;
		temp2[i] = '\0';
		if (_access(fname2, 0) && !_access(fname1, 0) && !_access(temp2, 0))
		{
			system(temp); cout << "z)Successful" << endl;
		}
		else
			cout << "g)cant copy file or first file not found" << endl; 
		
	}
}
void filew::frename()
{
	if (fname1 == ""||fname2=="")
	{
		cout << "b)Error! Empty file name!Enter file name!" << endl;
		return;
	}
	else
	{
		if (rename(fname1, fname2) != 0)
		{
			cout << "c)Rename error" << endl; return;
		}
		else cout << "z)Successful" << endl;
	}
}

char filew::parseCMNDArg(char *procA)
{

	if (strcmp(procA, "GENERATE") == 0 || strcmp(procA, "Generate") == 0 || strcmp(procA, "generate") == 0 || strcmp(procA, "CREATE") == 0 || strcmp(procA, "create") == 0 || strcmp(procA, "Create") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		return 'G';
	}
	if (strcmp(procA, "DEL") == 0 || strcmp(procA, "del") == 0 || strcmp(procA, "Del") == 0 || strcmp(procA, "DELETE") == 0 || strcmp(procA, "delete") == 0 || strcmp(procA, "Delete") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		return 'D';
	}
	if (strcmp(procA, "RENAME") == 0 || strcmp(procA, "rename") == 0 || strcmp(procA, "Rename") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		return 'R';
	}
	if (strcmp(procA, "COPY") == 0 || strcmp(procA, "copy") == 0 || strcmp(procA, "Copy") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		return 'C';
	}
	if (strcmp(procA, " ") == 0 || strcmp(procA, "") == 0 ){
		cout << "EMPTY_ARGS \t First argument [" << procA << "]\t First letter is " << *procA << "\n";
		return 'N';
	}
	if (strcmp(procA, "ABZ") == 0)	return 'A';
	cout << "FAULT_CMND_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
	return 'E';
	system("pause");
}

void filew::getproc(char *fproc,char *str1,char *str2,filew *file,int argentum)
{
	fname1 = str1;
	fname2 = str2;
	char proc[6]; proc[0] = 'e';
	*proc = *fproc;

	char zArg = filew::parseCMNDArg(fproc);
	
	switch (zArg)
	{
	case 'G':{if (argentum < 3){ cout << "d)second argument error" << endl; return; } file->fcreate(); return; }
	case 'D':{if (argentum < 3){ cout << "d)second argument error" << endl; return; }file->fdelete(); return; }
	case 'C':{if (argentum < 4){ cout << "d)second argument error" << endl; return; }file->fcopy(); return; }
	case 'R':{if (argentum < 4){ cout << "d)second argument error" << endl; return; }file->frename(); return; }
	case 'N': {cout << "e)command was not given" << endl; return; }
	case 'E': {cout << "E)510 WRONG command was given" << endl; return; }
	case 'A': {cout << "______________________________________________________\n\n"; return; }
	default: {cout << "f)404 illegal command not found" << endl; return; }
	}
	
}


