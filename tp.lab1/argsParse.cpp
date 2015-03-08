#define _CRT_SECURE_NO_WARNINGS 1
#include "argsParse.h"
using namespace std;

char argsParsing::getCMNDArg(char *procA)
{
	for (int i = 0; i < strlen(procA);i++){
		procA[i] = tolower(procA[i]);
	}
	if (strcmp(procA, "generate") == 0 || strcmp(procA, "create") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg='G';
		return 'G';
	}
	if (strcmp(procA, "del") == 0 || strcmp(procA, "delete") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg = 'D';
		return 'D';
	}
	if (strcmp(procA, "rename") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg = 'R';
		return 'R';
	}
	if (strcmp(procA, "copy") == 0){
		cout << "SUCCESS_FIRST_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg = 'C';
		return'C';
	}
	if (strcmp(procA, " ") == 0 || strcmp(procA, "") == 0){
		cout << "EMPTY_ARGS \t First argument [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg = 'N';
		return 'N';
	}
	if (strcmp(procA, "isexist") == 0) {
		cout << "SUCCESS_FIRST_ARG \t First argument [" << procA << "]\t First letter is " << *procA << "\n";
		this->CMNDarg = 'S';
		return 'S';
	}
	if (strcmp(procA, "abz") == 0) {
		this->CMNDarg = 'A';
		return 'A';
	}
	cout << "FAULT_CMND_ARG \t First argument is [" << procA << "]\t First letter is " << *procA << "\n";
	this->CMNDarg = 'E';
	return 'E';
}
