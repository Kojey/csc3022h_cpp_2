/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "volimage.h"


Volimgae::VolImage(){

} // default constructor - define in .cpp

Volimage::~VolImage(){

} // destructor - define in .cpp file

// populate the object with images in stack and
//set member variables define in .cpp
bool Volimage::readImages(std::string baseName) {
	return true;
}

// compute difference map and write out; define in .cpp
void Volimage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

}

// extract slice sliceId and write to output - define in .cpp
void Volimage::extract(int sliceId, std::string output_prefix){

}

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int Volimage::volImageSize(void){

}
