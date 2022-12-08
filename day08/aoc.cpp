#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read_input() {
    std::vector<std::string> result;
    std::ifstream input_file("input.txt");
    std::string line;
    std::string sections;

    while (std::getline(input_file, line)) {
        result.push_back(line);
    }
    return result;
}

bool isHigh(std::vector<std::string> forest, int col, int row){
    int currNumber = forest[row][col] - '0';
    //Check left
    for(int x = col-1; x >= 0; x--) {
        int pointer = forest[row][x] - '0';
        if(pointer >= currNumber) break;
        if(x == 0) return true;
    }

    //Check right
    for(int x = col+1; x <= forest[row].length(); x++) {
        int pointer = forest[row][x] - '0';
        if(pointer >= currNumber) break;
        if(x == forest[row].length()-1) return true;
    }

    //Check up
    for(int y = row-1; y >= 0; y--) {
        int pointer = forest[y][col] - '0';
        if(pointer >= currNumber) break;
        if(y == 0) return true;
    }
    //Check down
    for(int y = row+1; y <= forest.size(); y++) {
        int pointer = forest[y][col] - '0';
        if(pointer >= currNumber) break;
        if(y == forest.size()) return true;
    }
    return false;
}


int calcScenicScore(std::vector<std::string> forest, int col, int row){
    int upScore = 0;
    int leftScore = 0;
    int rightScore = 0;
    int downScore = 0;
    int currNumber = forest[row][col] - '0';

    //Check up
    for(int y = row-1; y >= 0; y--) {
        int pointer = forest[y][col] - '0';
        upScore++;
        if(pointer >= currNumber) break;
    }

    //Check left
    for(int x = col-1; x >= 0; x--) {
        int pointer = forest[row][x] - '0';
        leftScore++;
        if(pointer >= currNumber) break;
    }

    //Check right
    for(int x = col+1; x <= forest[row].length()-1; x++) {
        int pointer = forest[row][x] - '0';
        rightScore++;
        if(pointer >= currNumber) break;
    }
    //Check down
    for(int y = row+1; y <= forest.size()-1; y++) {
        int pointer = forest[y][col] - '0';
        downScore++;
        if(pointer >= currNumber) break;
    }
    return upScore*leftScore*rightScore*downScore;
}

int solve1(std::vector<std::string> input) {
    int visibleTrees = 0;
    for(int row = 0; row < input.size(); row++) {
        for (int col = 0; col < input[col].length(); col++) {
            //Top row
            if(row == 0) {
                visibleTrees++;
            }
            //Bottom Row
            else if(row == input.size()-1) {
                visibleTrees++;
            }
            //Leftmost number
            else if(col == 0) {
                visibleTrees++;
            }
            //Rightmost number
            else if(col == input[row].length()-1) {
                visibleTrees++;
            }
            //All other trees
            else {
                if(isHigh(input,col, row)) visibleTrees++;
            }
        }
    }
    return visibleTrees;
}

int solve2(std::vector<std::string> input) {
    int scenicScore = 0;
    int bestScenicScore = 0;
    for(int row = 0; row < input.size(); row++) {
        for (int col = 0; col < input[col].length(); col++) {
            scenicScore = calcScenicScore(input, col, row);
            bestScenicScore = scenicScore > bestScenicScore ? scenicScore : bestScenicScore;
        }
    }
    return bestScenicScore;
}

int main() {

    std::vector<std::string> input = read_input();

    std::cout << "C++" << std::endl;

    char* part = getenv("part");
    if (part == NULL) {
        printf("%d\n", solve1(input));
    } else if (std::string(part) == "part1") {
        printf("%d\n", solve1(input));
    } else if (std::string(part) == "part2") {
        printf("%d\n", solve2(input));
    } else {
        std::cout << "Unknown part" << std::endl;
    }

    return 0;
}