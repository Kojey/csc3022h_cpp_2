/**
 * Driver file for volimage
 * Author: Othniel Konan
 * Date: March 2016
 */

#include <iostream>
#include <sstream>
#include "libs/volimage.h"

void clear();

int main(int argc, char * argv[]){
	using namespace std;
	string cmd_arg[4] = {"volimage", "-g", "-x", "-d"};
	VolImage vol;
	if( argc > 2) vol.readImages(string(argv[2]));
	// Read argc from command line
	switch(argc){
		case 3:	// volimage <imageBase>
			cout<<"volimage <imageBase>"<<endl;
			if(string(argv[1])!=cmd_arg[0]) return 0;	// wrong argument name
			break;
		case 5:	// volimage <imageBase> [-g i]
			cout<<"volimage <imageBase> [-g i]"<<endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[1]) return 0;	// Wrong argument names
/*			{
				istringstream ss(argv[4]);
				int i;
				ss >> i;
				cout << "integer i = " << i << endl;
			}*/
			break;
		case 6:	// volimage <imageBase> [-x i output_file_name]
			cout<<"volimage <imageBase> [-x i output_file_name]"<<endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[2]) return 0;
			{
				cout << "in Here" << endl;
				istringstream ss(argv[4]);
				int i;
				ss >> i;
				vol.extract(i, string(argv[5]));
			}break;
		case 7:	// volimage <imageBase> [-d i j output_file_name]
			cout<<"volimage <imageBase> [-d i j output_file_name]"<<endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[3]) return 0;
			break;
		default:
			cout<<"default"<<endl;
			cout << argc << endl;
			return 0;
	}

	return 0;
}

void clear(void) { system("clear"); }
