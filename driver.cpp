/**
 * Driver file for volimage
 * Author: Othniel Konan
 * Date: March 2016
 */

#include <iostream>
#include <sstream>

void clear();

int main(int argc, char * argv[]){
	using namespace std;
	string cmd_arg[4] = {"volimage", "-g", "-x", "-d"};
	// Read argc from commande line
	switch(argc){
		case 3:	// volimage <imageBase>
			cout << "volimage <imageBase>" << endl;
			if(string(argv[1])!=cmd_arg[0]) return 1;	// wrong argument name
			break;
		case 5:	// volimage <imageBase> [-g i]
			cout << "volimage <imageBase> [-g i]" << endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[1]) return 1;	// Wrong argument names
			{
				istringstream ss(argv[4]);
				int i;
				ss >> i;
				cout << "integer i = " << i << endl;
			}
			break;
		case 6:	// 1volimage <imageBase> [-x i output_file_name]
			cout << "volimage <imageBase> [-x i output_file_name]" << endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[2]) return 1;
			break;
		case 7:	// volimage <imageBase> [-d i j output_file_name]
			cout << "volimage <imageBase> [-d i j output_file_name]" << endl;
			if(string(argv[1])!=cmd_arg[0] || string(argv[3])!= cmd_arg[3]) return 1;
			break;
		default:
			cout << "Wrong arguments" << endl;
			return 1;
	}

	return 0;
}

void clear(void) { system("clear"); }
