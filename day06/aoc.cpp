#include <iostream>
#include <fstream>
#include <vector>
#include <set>

std::string read_input() {
    std::string result;
    std::ifstream input_file("input.txt");
    std::string line;
    std::string sections;

    while (std::getline(input_file, line)) {
        result = line;
    }
    return result;
}

int iterateNumbers(std::string numbers, int bufferSize){
    std::vector<char> buffer;
    int marker = 0;
    for(int i = 0; i < numbers.length(); i++) {
        buffer.insert(buffer.begin(), numbers[i]);
        if(buffer.size() >= bufferSize ) {
            std::set<char> sets(buffer.begin(), buffer.end());
            if(sets.size() == buffer.size()) {
                marker = i+1;
                break;
            }
            else buffer.pop_back();
        }
    }

    return marker;
}

int solve1(std::string input) {
    return iterateNumbers(input, 4);
}

int solve2(std::string input) {
    return iterateNumbers(input, 14);
}

int main() {
    std::string input = read_input();

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