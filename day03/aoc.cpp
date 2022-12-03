#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> read_input() {

    std::vector<std::string> result;
    std::ifstream input_file("input.txt");
    std::string line;

    while (std::getline(input_file, line)) {
        result.push_back(line);
    }
    return result;
}


std::string findSplitIntersection(std::string in) {

    std::string string1 = in.substr(0, in.length()/2);
    std::string string2 = in.substr(in.length()/2);

    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());

    std::string string_intersection;

    std::set_intersection(string1.begin(), string1.end(), string2.begin(), string2.end(), std::back_inserter(string_intersection));

    return string_intersection;
}

std::string findIntersectionBetween3(std::vector<std::string> in) {
    std::string string1 = in[0];
    std::string string2 = in[1];
    std::string string3 = in[2];

    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());
    std::sort(string3.begin(), string3.end());

    std::string string_intersection_of_2;
    std::string string_intersection_of_3;

    std::set_intersection(string1.begin(), string1.end(), string2.begin(), string2.end(), std::back_inserter(string_intersection_of_2));
    std::set_intersection(string_intersection_of_2.begin(), string_intersection_of_2.end(), string3.begin(), string3.end(), std::back_inserter(string_intersection_of_3));

    return string_intersection_of_3;
}


int calcPoints(char symbol){
    if (std::islower(symbol)){
        return static_cast<int>(symbol) - 96;
    }
    else {
        return static_cast<int>(symbol) - 64 + 26;
    }
}

int solve1(std::vector<std::string> input) {
    int points = 0;

    for (std::string s : input) {
        char intersect = findSplitIntersection(s)[0];
        points += calcPoints(intersect);
    }
    return points;
}

int solve2(std::vector<std::string> input) {
    int points = 0;

    for (int i = 0; i < input.size(); i += 3) {
        auto it_first = input.cbegin() + i;
        auto it_last = input.cbegin() + i + 3;
        std::vector<std::string> part (it_first, it_last);
        points += calcPoints(findIntersectionBetween3(part)[0]);
    }
    return points;
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