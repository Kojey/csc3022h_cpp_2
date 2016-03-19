/**
 * Header file for the interface library
 * Author: Othniel Konan
 * Date: March 2016
 */


#ifndef VOLIMAGE_H
#define VOLIMAGE_H

#include <vector>
#include <string>
static int size=0;
static int number=0;
int getNumber(void);
void printInfo(std::string methodString, int _size);
class VolImage
{
private: // private members
	int width, height; // width and height of image stack
	std::vector<unsigned char**> slices; // data for each slice, in order
public: // public members
	VolImage(); // default constructor - define in .cpp
	~VolImage(); // destructor - define in .cpp file
// populate the object with images in stack and
//set member variables define in .cpp
	bool readImages(std::string baseName);
// compute difference map and write out; define in .cpp
	void diffmap(int sliceI, int sliceJ, std::string output_prefix);
// extract slice sliceId and write to output - define in .cpp
	void extract(int sliceId, std::string output_prefix);
	void g_extract(int row, std::string output_prefix);
// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
	int volImageSize(void); // define in .cpp
};


#endif
