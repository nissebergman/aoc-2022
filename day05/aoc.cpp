#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <cmath>

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

std::vector<int> organizeInstructions(std::vector<std::string> input, int i) {
    std::vector<int> instructions;

    for (int j = 0; j < input[i].length(); j++) {
        if(isdigit(input[i][j])) {
            if(isdigit(input[i][j+1])) {
                instructions.push_back(((input[i][j]- '0') * 10 + (input[i][j+1] - '0')));
                j++;
            }
            else {
                instructions.push_back(((input[i][j] - '0')));
            }
        }
    }

    return instructions;
}

std::vector<std::deque<char> > organizeContainers(std::vector<std::string> in) {

    std::vector<std::deque<char> > containerQueue;

    for (int i = 0; i < 9; i++) {
        containerQueue.push_back(std::deque<char>{});
    }

    int pos = 0;

    for (int i = 0; i < in.size(); i++) {
        if (i < 9) {
            for (int j = 0; j < in[i].length(); j++) {
                if (isalpha(in[i][j])) {
                    if(in[i][j] == 2) pos = j-1;
                    else pos = std::floor((j/4));
                    containerQueue[pos].push_back(in[i][j]);
                }
            }
        }
    }

    return containerQueue;
}

std::string solve1(std::vector<std::string> input) {

    std::vector<std::deque<char> > containers = organizeContainers(input);
    std::vector<int> instructions;
    std::string result;

    for (int i = 10; i < input.size(); i++) {

            instructions = organizeInstructions(input, i);

            int numberOfMoves = instructions[0];
            int sendingStack = instructions[1]-1;
            int receivingStack = instructions[2]-1;

            for (int n = 0; n < numberOfMoves; n++) {
                char moving = containers[sendingStack].front();
                containers[receivingStack].push_front(moving);
                containers[sendingStack].pop_front();
            }
            instructions.clear();
    }

    for (int i = 0; i < containers.size(); i++) {
        result.push_back(containers[i].front());
    }
    return result;
}

std::string solve2(std::vector<std::string> input) {

    std::vector<std::deque<char> > containers = organizeContainers(input);
    std::vector<int> instructions;
    std::deque<char> temp;
    std::string result;

    for (int i = 10; i < input.size(); i++) {

        instructions = organizeInstructions(input, i);

            int numberOfMoves = instructions[0];
            int sendingStack = instructions[1]-1;
            int receivingStack = instructions[2]-1;

            for (int n = 0; n < numberOfMoves; n++) {
                char moving = containers[sendingStack].front();
                temp.push_back(moving);
                containers[sendingStack].pop_front();
            }
            containers[receivingStack].insert(containers[receivingStack].begin(), temp.begin(), temp.end());
            instructions.clear();
            temp.clear();
        }

    for (int i = 0; i < containers.size(); i++) {
        result.push_back(containers[i].front());
    }
    return result;
}

int main() {

    std::vector<std::string> input = read_input();

    std::cout << "C++" << std::endl;

    char* part = getenv("part");
    if (part == NULL) {
        std::cout << (solve1(input));
    } else if (std::string(part) == "part1") {
        std::cout << (solve1(input));
    } else if (std::string(part) == "part2") {
        std::cout << (solve2(input));
    } else {
        std::cout << "Unknown part" << std::endl;
    }

    return 0;
}