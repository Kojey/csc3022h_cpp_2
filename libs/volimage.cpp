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

bool VolImage::readImages(std::string baseName) {
	/*
	 * populate the object with images in stack and set member variables
	 */
	using namespace std;
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
		size+=sizeof(array);
		for(h=0; h<height; h++){
			array[h] = new unsigned char [width];	// create pointer to unsigned char
			size+=sizeof(array[h]);
			for(w=0; w<width; w++) {
				if(!file.eof()){
					char * ptr = (char *) &array[h][w];	// typecast unsigned char to char for .read() method
					file.read(ptr,1);	// add a byte to the array
					size+=1;
				}
			}
		}
		file.close();
		slices.push_back(array);	// add slice to the vector
	}
	return true;
}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
	/*
	 * compute difference map and write out
	 */
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
				file << (unsigned char) abs((int)((float) (slices.at(sliceI))[h][w]-(float) (slices.at(sliceJ)[h][w]))/2);
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file " << output_prefix << ".raw" << endl;
	}
}

void VolImage::extract(int sliceId, std::string output_prefix){
	/*
	 * extract slice sliceId and write to output
	 */
	using namespace std;
	size=0;
	number=1;
	// open an output.data file
	ofstream file(output_prefix+".data");
	if(file.is_open()){ // write width, height and number_of_slices=1
		file << width << " ";
		file << height << " ";
		file << number;
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
		size+=sizeof(slices.at(sliceId));	// size of the pointer to the 2D array
		for(h=0; h<height; h++){
			size+=sizeof(slices.at(sliceId)[h]);	// size of 1D array
			for(w=0; w<width; w++){
				file << slices.at(sliceId)[h][w];
				size+= sizeof(slices.at(sliceId)[h][w]);	// size of an unsigned char
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file " << output_prefix << ".raw" << endl;
	}
}

int VolImage::volImageSize(void){
	/*
	 * number of bytes uses to store image data bytes and pointers (ignore vector<> container, dims etc)
	 */
	return size;
}

void VolImage::g_extract(int sliceId, std::string output_prefix){


}

int getNumber(void){
	return number;
}

void printInfo(std::string methodString, int _size){
	using namespace std;
	cout << methodString << endl;
	cout << "Number of images : ";
	cout << getNumber() << endl;
	cout << "Number of bytes required : ";
	cout << _size << endl;
}