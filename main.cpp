#include "Solution.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<std::vector<char> > readGrid(const std::string& filename) {
    std::vector<std::vector<char> > grid;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return grid;
    }

    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        std::vector<char> row;
        std::stringstream ss(line);
        char ch;

        // Iterate over each character in the line
        while (ss >> ch) {
            if (ch == '[' || ch == ']' || ch == ',' || ch == '\"') continue;
            row.push_back(ch);
        }

        grid.push_back(row);
    }

    file.close();
    return grid;
}

int main() {

    vector<vector<char> > grid1 = readGrid("TestCases/Case_1.in");
    vector<vector<char> > grid2 = readGrid("TestCases/Case_2.in");
    vector<vector<char> > grid39 = readGrid("TestCases/Test_39.in");
    Solution s;
    int numIslands1, numIslands2, numIslands39;
    numIslands1 = s.numIslands(grid1);
    numIslands2 = s.numIslands(grid2);
    numIslands39 = s.numIslands(grid39);
    cout << "Total number of islands for Case 1 is: " << numIslands1 << endl;
    cout << "Total number of islands for Case 2 is: " << numIslands2 << endl;
    cout << "Total number of islands for Test Case 39 is: " << numIslands39 << endl;

    return 0;
}
