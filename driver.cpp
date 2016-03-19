/**
 * Driver file for volimage
 * Author: Othniel Konan
 * Date: March 2016
 */

#include <iostream>
#include <sstream>
#include "libs/volimage.h"

int main(int argc, char * argv[]){
	using namespace std;
	string cmd_arg[4] = {"volimage", "-g", "-x", "-d"};
	string s;
	VolImage vol;
	if( argc > 2) vol.readImages(string(argv[2]));
	// Read argc from command line
	switch(argc){
		case 3:
			if(string(argv[1])!=cmd_arg[0]) return 0;	// wrong argument name
			s = "\nCommand: volimage <imageBase>\nDecription: Load data with base "+string(argv[2])+" to memory.";
			printInfo(s,vol.volImageSize());
			break;
		case 6:
			if(string(argv[1])!=cmd_arg[0] || ( string(argv[3])!= cmd_arg[2] && string(argv[3])!= cmd_arg[1]) ) return 0;
			if(string(argv[3])== cmd_arg[2]){
				istringstream ss(argv[4]);
				int i;ss >> i;
				vol.extract(i, string(argv[5]));
				s = "\nCommand: volimage <imageBase> [-x i output_file_name]\nDecription: Retrieve the slice with the index given and write this to an output sequence.";
				printInfo(s,vol.volImageSize());
			}
			else if(string(argv[3])== cmd_arg[1]){
				istringstream ss(argv[4]);
				int row;ss >> row;
				vol.g_extract(row, string(argv[5]));
				s = "\nCommand: volimage <imageBase> [-g i output_file_name]\nDecription: Extracts an image along row i of the volume, across all slices.";
				printInfo(s,vol.volImageSize());
			}
			break;
		case 7:
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[3]) return 0;
			{
				istringstream ss(argv[4]);
				int i,j;
				ss >> i;
				ss.clear();ss.str(argv[5]);ss >> j;
				vol.diffmap(i,j, string(argv[6]));
				s = "\nCommand: volimage <imageBase> [-d i j output_file_name]\nDecription: Computes the difference map between “slices” i and j.";
				printInfo(s,vol.volImageSize());
			}
			break;
		default:
			cout<<"Wrong arguments"<<endl;
			return 0;
	}

	return 0;
}
