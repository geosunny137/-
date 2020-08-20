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
public:
    MD5();
    MD5(const void* input, size_t length);
    MD5(const string& str);
    MD5(ifstream& in);
    void update(const void* input, size_t length);
    void update(const string& str);
    void update(ifstream& in);
    const byte* digest();
    string toString();
    void reset();

};

string Getmd5(const string& file);

#endif/*MD5_H*/

