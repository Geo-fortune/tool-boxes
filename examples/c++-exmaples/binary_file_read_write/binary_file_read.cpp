#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char ** argv) {

    std::string file_path = "test.txt";

    std::ifstream ifile;
    ifile.open(file_path.c_str(), std::ios::in | std::ios::binary );


    std::string notes;
    while(ifile.read((char*)&notes, sizeof(notes))) {

        std::cout << notes << std::endl;
    }


// ifile.write(notes.c_str(), notes.capacity() *sizeof(char));

    ifile.close();

    return EXIT_SUCCESS;
}