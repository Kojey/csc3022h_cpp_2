/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "volimage.h"


VolImage::VolImage(){
	width = 0;
	height = 0;
} // default constructor - define in .cpp

VolImage::~VolImage(){

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
