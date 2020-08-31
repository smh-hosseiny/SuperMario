#include<vector>
#include <iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<fstream>


#include "Input.h"


using namespace std;

Input :: Input()
{}

vector<string> Input :: read_input(char *argv[])
{
	vector<string> input;
    string Command;
    ifstream myfile;
    
    myfile.open(argv[1]);

    if(!myfile)
    {
    	cout <<" unable to open file\n";
        exit(1);
    }

    else
	{
		 while (myfile.good())
        {
	    	getline(myfile, Command, '\n');
	        input.push_back(Command);
	    }
	    return input;
	}
}    






