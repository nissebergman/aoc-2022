#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>

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

std::set<std::pair<int, int> > visitedCoords;
std::pair<long int, long int> tailCoords = std::make_pair(0,0);
std::pair<long int, long int> headCoords = std::make_pair(0,0);
std::pair<long int,long int> prevHeadCoords;

void updateRope(std::string instructions){
    char direction = instructions[0];
    bool horizontal = direction == 'R' || direction == 'L' ? true : false;
    int way;
    int distance = std::stoi(instructions.substr(2));
    way = direction == 'R' || direction == 'U' ? 1 : -1;

    for(int i = 0; i < distance; i++){
        prevHeadCoords = headCoords;
        if(horizontal) headCoords.first += (1 * way);
        else headCoords.second += (1 * way);
        if(abs(headCoords.first - tailCoords.first) > 0 || abs(headCoords.second - tailCoords.second) > 0) {
            if((abs(headCoords.first - tailCoords.first) == 1 && abs(headCoords.second - tailCoords.second) == 1)) {
                //Diagonal
            }
            else if((abs(headCoords.first - tailCoords.first) > 1 || abs(headCoords.second - tailCoords.second) > 1)) {
                tailCoords = prevHeadCoords;
                visitedCoords.insert(tailCoords);
            }
        }
    }
}

int solve1(std::vector<std::string> input){
    for (std::string s : input) {
        updateRope(s);
    }
    return visitedCoords.size();
}

int main() {

    std::vector<std::string> input = read_input();

    std::cout << "C++" << std::endl;

    visitedCoords.insert(std::make_pair(0,0));

    char* part = getenv("part");
    if (part == NULL) {
        printf("%d\n", solve1(input));
    } else if (std::string(part) == "part1") {
        printf("%d\n", solve1(input));
    } else if (std::string(part) == "part2") {
    } else {
        std::cout << "Unknown part" << std::endl;
    }

    return 0;
}
