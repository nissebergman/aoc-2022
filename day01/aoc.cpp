#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> read_input() {
    std::vector<int> result;

    std::ifstream input_file("input.txt");
    std::string line;
    int sum = 0;
    
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);

        int a;
        if (iss >> a) sum += a;
        else {
            result.push_back(sum);
            sum = 0;
        }
    }

    return result;
}

int solve1(std::vector<int> input) {
    int max = *std::max_element(input.begin(), input.end());

    return max;
}

int solve2(std::vector<int> input) {
    std::vector<int> numbers = input;
    int nrOfElves = 3;
    int total = 0;
    int index = 0;
    for (int i = 0; i < nrOfElves; i++) {
        total += solve1(numbers);
        int index = std::max_element(numbers.begin(), numbers.end()) - numbers.begin();
        numbers.erase(numbers.begin() + index);
    }
    return total;
}

int main() {
    std::vector<int> input = read_input();

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