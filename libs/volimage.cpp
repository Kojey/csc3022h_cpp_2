/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "volimage.h"


VolImage::VolImage(){
	width=0;
	height=0;
} // default constructor - define in .cpp

VolImage::~VolImage(){
	int i,h;
	for(i=0; i<slices.size(); i++){
		for(h=0; h<height; h++){
			delete [] (slices.at(i))[h];
		}
		delete [] slices.at(i);
	}

} // destructor - define in .cpp file

// populate the object with images in stack and
//set member variables define in .cpp

bool VolImage::readImages(std::string baseName) {
	using namespace std;
	// baseName must have the form <directory>/<name>
	string dir,name;
	stringstream ss(baseName);
	getline(ss,dir,'/');
	getline(ss,name,'/');
	name = name.substr(0,name.find(".data"));
	int number;
	// read .data file first
	ifstream file(baseName.c_str());
	if(!file){
		cout<<"Unable to open file "<<baseName<<"."<<endl;
		return false;
	}
	file >> width >> ws;
	file >> height >> ws;
	file >> number >> ws;
	// read .raw files
	int i,w,h;
	for (i=0; i<number; i++){	// for each raw file
		ostringstream ss;
		ss << i;	// convert index to string
		ifstream file((dir+"/"+name+ss.str()+".raw").c_str(), ios::binary);	// open file in binary mode
		if(!file){
			cout<<"Unable to open file "<<baseName<<"."<<endl;
			return false;
		}
		unsigned char ** array = new unsigned char * [height]; // create pointer to pointer of unsigned char
		for(h=0; h<height; h++){
			array[h] = new unsigned char [width];	// create pointer to unsigned char
			for(w=0; w<width; w++) {
				if(!file.eof()){
					char * ptr = (char *) &array[h][w];	// typecast unsigned char to char for .read() method
					file.read(ptr,1);
				}
			}
		}
		slices.push_back(array);	// add slice to the vector
	}
	return true;
}

// compute difference map and write out; define in .cpp
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

}

// extract slice sliceId and write to output - define in .cpp
void VolImage::extract(int sliceId, std::string output_prefix){

}

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void){

}
