#include <iostream>
#include <fstream>
#include "io.h"
#include "filew.h"

using namespace std;
int main(int argc,char *argv[])
{
	filew *file=new filew;
	
	if (argc < 2) { 
		cout << "a)Not enough arguments" << endl; 
		return -1; 
	}
	if (argc > 4) {
		cout << "b) Too much arguments you've put!" << endl;
		return -1;
	}
	file->getproc(argv[1], argv[2], argv[3], file, argc);
	delete file;
	
	return 0;
}