#include "ExerciseClass.h"


bool NoVowelString::IsVowel(char ch) {      //checks if ch is vowel
	for (const auto& i : Vowels){
		if (ch == i) return true;
	}
	return false;
}

NoVowelString& NoVowelString::operator>>(std::string& s) {
    while (!(Buffer >> s)) {        //when the buffer is empty and already gave input get new input and process it, if not just return
        Emptied = false;            //the buffer didn't empty to s

        if (Buffer.bad() || !(InputSource.good())) return *this;        //checks
        Buffer.clear();

        std::string vowelstring;
        InputSource >> vowelstring;

        for (int i = 0; i < vowelstring.size(); i++) {                      //eliminating vowels and handling CaseSensitiveness
            if (!CaseSensitive) vowelstring[i] = tolower(vowelstring[i]);
            if (IsVowel(tolower(vowelstring[i]))) {
                vowelstring.erase(vowelstring.begin() + i);
                i -= 1;
            }
        }
        Buffer.str(vowelstring);        //get the processed string into the buffer
    }
    Emptied = true;                     //the buffer emptied into s
    return *this;
}

NoVowelString::operator bool() {
	return  Emptied || InputSource.good();      //if the buffer has been emptied succesfully or the source is still good return true
}