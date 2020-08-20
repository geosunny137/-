#pragma once
#ifndef MD5_H 
#define MD5_H 

#include <string> 
#include <fstream> 

/* Type define */
typedef unsigned char byte;
typedef unsigned int uint32;
typedef unsigned int uint4;

using std::string;
using std::ifstream;

/* MD5 declaration. */
class MD5 {

};

string Getmd5(const string& file);

#endif/*MD5_H*/

