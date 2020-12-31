#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc, char ** argv) {

    std::string file_path_1 = "test_data/test.txt";
    std::string file_path_2 = "";

    fstream fs_in_1(file_path_1, ios::in);
    fstream fs_in_2(file_path_2, ios::in);

    if(!fs_in_1.good() ) {
        std::cout << "file open failed" << std::endl;
        return EXIT_FAILURE;
    }

    vector<int64_t> timestamp1, timestamp2;

    string s;
    while (getline(fs_in_1, s))
    {
        // std::cout << "ts: " << s << std::endl;

        int64_t ts = atol(s.c_str());
        timestamp1.emplace_back(ts);
        timestamp2.emplace_back(ts);
        /* code */
    }

    // 51
    std::vector<int64_t> times = {860047, 860048, 860050, 860051, 860052 ,860053, 860054, 860055, 860056};
    for(auto time : times) {

        std::vector<int64_t>::iterator iter_upper = std::upper_bound(timestamp1.begin(), timestamp1.end(), time) ;
        if( iter_upper!= timestamp1.end()) {
            std::cout << time <<  " upper_bound " <<*iter_upper << std::endl;
        }

        std::vector<int64_t>::iterator iter_lower = std::lower_bound(timestamp1.begin(), timestamp1.end(), time) ;
        if( iter_lower!= timestamp1.end()) {
            std::cout << time <<  " lower_bound " <<*iter_lower << std::endl;
        }
    }

    for(auto time :times){
        
        auto iter_range = std::equal_range(timestamp2.begin(), timestamp2.end(), time);

        std::cout << time << std::endl ;
        vector<int64_t>::iterator iter;
        for(iter = iter_range.first; iter != iter_range.second; iter++){
            std::cout <<" range:" << *iter << "," ; 
        }

        std::cout << std::endl;

    }

    // int64_t time3 = 860049 ;
    
    // vector<int64_t>::iterator iter_range;
    // for( iter_range= a.first; iter_range != a.second ; iter_range++ ){

    //     std::cout << "iter range: " << * iter_range << std::endl;
    // }

    return EXIT_SUCCESS;
}