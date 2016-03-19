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
	int number;
	// read .data file first
	ifstream file((baseName+".data").c_str());
	if(!file){
		cout<<"Unable to open .data file "<<baseName<<"."<<endl;
		return false;
	}
	file >> width >> ws;
	file >> height >> ws;
	file >> number >> ws;
	file.close();
	// read .raw files
	int i,w,h;
	for (i=0; i<number; i++){	// for each raw file
		ostringstream ss;
		ss << i;	// convert index to string
		ifstream file((baseName+ss.str()+".raw").c_str(), ios::binary);	// open file in binary mode
		if(!file){
			cout<<"Unable to open .raw file "<<baseName<<"."<<endl;
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
		file.close();
		slices.push_back(array);	// add slice to the vector
	}
	return true;
}

// compute difference map and write out; define in .cpp
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

}

// extract slice sliceId and write to output - define in .cpp
void VolImage::extract(int sliceId, std::string output_prefix){
	using namespace std;
	// open an output.data file
	ofstream file(output_prefix+".data");
	if(file.is_open()){ // write width, height and number_of_slices=1
		file << width << " ";
		file << height << " ";
		file << 1;
		file.close();
	}
	else {
		cout << "Unable to open file " << output_prefix << ".data" << endl;
	}
	// open an output.raw file in binary mode
	file.open(output_prefix+".raw", ios::binary);
	if(file.is_open()){
		int h,w;
		// loop through the slice and write each byte to it
		for(h=0; h<height; h++){
			for(w=0; w<width; w++){
				file << slices.at(sliceId)[h][w];
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file " << output_prefix << ".raw" << endl;
	}
}

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void){

}
