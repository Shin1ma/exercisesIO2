// exercisesIO2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include <iostream>
#include<sstream>
#include<fstream>
#include <vector>
#include "ExerciseClass.h"

std::vector<std::string> GetInput(std::istream& in);                    //gets input
void Output(std::ostream& out, std::vector<std::string> novowelsvec);       //outputs

int main()
{
    std::string Iname;
    std::string Oname;

    try {
                            //file opening and checkà
        std::cout << "Input file:";
        std::cin >> Iname;

        std::ifstream InputFile(Iname);
        if (!InputFile) throw std::runtime_error("unvalid file name");

        std::cout << "Output file:";
        std::cin >> Oname;
        std::ofstream OutputFile(Oname);
        if (!InputFile) throw std::runtime_error("unvalid file name");

        //gets input and outputs it
        std::vector<std::string> NoVowelWords = GetInput(InputFile);
        Output(OutputFile, NoVowelWords);

        std::cout << "All done\n";
    }

    catch (const std::runtime_error& e) { std::cout << e.what() << "\n"; }
}


std::vector<std::string> GetInput(std::istream& in) {
    NoVowelString NoVowelStrings(in, true);     //instantiates the class with an input source and , and get input by it
    std::vector<std::string> ProcessedInput;
    std::string s;

    while (NoVowelStrings >> s) {
        ProcessedInput.push_back(s);
    }

    return ProcessedInput;
}
void Output(std::ostream& out, std::vector<std::string> novowelsvec) {
    for (int i = 0; i < novowelsvec.size(); i++) out << novowelsvec[i] << " ";
}

