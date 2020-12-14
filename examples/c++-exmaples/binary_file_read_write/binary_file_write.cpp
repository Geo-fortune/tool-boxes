#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char ** argv) {

    std::string file_path = "test.txt";

    std::fstream ofile;
    ofile.open(file_path.c_str(), std::ios::in | std::ios::out | std::ios::binary );

    std::string notes = "Hello World!\n";

    // ofile << notes;
    // ofile << 1111 ;
    float a= 0.008672;
    // ofile.write((const char*)&a, sizeof(a));
    ofile.write((char*)&notes, sizeof(notes));
    std::cout << sizeof(notes)<< std::endl;

    ofile.seekg(0);

    std::string notes2 ;
    while(ofile.read((char*)&notes2, sizeof(notes2))) {

        std::cout << "notes2:" << notes2 << std::endl;

    }

    ofile.close();

    return EXIT_SUCCESS;
}