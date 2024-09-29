#pragma once
#include <iostream>
#include<sstream>

class NoVowelString {
private:
    std::istream& InputSource;  //Istream source
    std::stringstream Buffer;   //buffer that communicates to the string requesting input by sstream
    const char Vowels[5] = { 'a', 'e', 'i', 'o', 'u' }; //vowels
    bool CaseSensitive; //Do I need to keep track of Upper letters or make them all lower
    bool Emptied;       //has the buffer been emptied

public:
    NoVowelString(std::istream& inputSource, bool casesensitive) :
        InputSource(inputSource), Buffer(""), CaseSensitive(casesensitive)
    {
    }

    bool IsVowel(char ch);  //checks if ch is a vowel

    NoVowelString& operator>>(std::string& s);      //gets input from source and operates it giving it to s
    operator bool();    //returns the stream as a bool

    //getters/setters
    bool IsCaseSensitive() { return CaseSensitive; }
    void SetCaseSensitive(bool value) { CaseSensitive = value; }
};
