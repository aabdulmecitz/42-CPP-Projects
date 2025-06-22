#include <iostream>
#include <string>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void replace_in_file(const std::string& filename, const std::string& s1, const std::string& s2);

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << RED << "Error: Program requires exactly 3 arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << " <filename> <string1> <string2>" << RESET << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty() || s2.empty()) {
        std::cerr << RED << "Error: Strings cannot be empty" << RESET << std::endl;
        return 1;
    }
    if (s1 == s2) {
        std::cerr << RED << "Error: Strings cannot be the same" << RESET << std::endl;
        return 1;
    }

    replace_in_file(filename, s1, s2);
    std::cout << GREEN << "Replacement completed successfully." << RESET << std::endl;

    return 0;
}

//> Check it again

void replace_in_file(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << RED << "Error: Could not open file " << filename << RESET << std::endl;
        return;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << RED << "Error: Could not create output file " << outFilename << RESET << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string result;
        size_t pos = 0;
        size_t prev = 0;
        while ((pos = line.find(s1, prev)) != std::string::npos) {
            result.append(line, prev, pos - prev);
            result += s2;
            prev = pos + s1.length();
        }
        result.append(line, prev, std::string::npos);
        outputFile << result;
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }
    inputFile.close();
    outputFile.close();
    std::cout << GREEN << "Replaced all occurrences of \"" << s1 << "\" with \"" << s2 << "\" in " << filename << " and saved to " << outFilename << RESET << std::endl;
    std::cout << YELLOW << "Output file: " << outFilename << RESET << std::endl;
}