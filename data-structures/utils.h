#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split_str(string str, char delimiter=',') {
    vector<string> result;
    stringstream ss(str);
    string substr;
    while (ss.good()) {
        getline(ss, substr, delimiter);
        result.push_back(substr);
    }
    return result;
}