#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

std::vector<std::string> read_input() {

    std::vector<std::string> result;
    std::ifstream input_file("input.txt");
    std::string line;
    std::string sections;

    while (std::getline(input_file, line)) {
        std::stringstream ss(line);

        while(getline(ss, sections, ',')) {
            result.push_back(sections);
        }

    }
    return result;
}

std::set<int> createSet(std::string in) {
    std::set<int> range;
    std::string delimiter = "-";

    int first = stoi(in.substr(0, in.find(delimiter)));
    int last = stoi(in.substr(in.find(delimiter)+1, in.length()));

    for (int i = first; i <= last; i++) {
        range.insert(i);
    }

    return range;
}

int findNrOfIntersections(std::set<int> first, std::set<int> second) {
    std::vector<int> intersections;
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(intersections));
    return intersections.size();
}

bool doesOverlap(std::set<int> first, std::set<int> second) {
    std::vector<int> intersections;
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(intersections));
    return intersections.size() > 0 ? true : false;
}

int solve1(std::vector<std::string> input) {
    std::set<int> elf1;
    std::set<int> elf2;
    int intersections;
    int smallestSet;
    int nrOfFullyContained = 0;
    for (int i = 0; i < input.size(); i +=2 ){
        elf1 = createSet(input[i]);
        elf2 = createSet(input[i+1]);
        smallestSet = elf1.size() < elf2.size() ? elf1.size() : elf2.size();
        if (findNrOfIntersections(elf1, elf2) == smallestSet) nrOfFullyContained++;
    }
    return nrOfFullyContained;
}

int solve2(std::vector<std::string> input) {
    std::set<int> elf1;
    std::set<int> elf2;
    int intersections;
    int smallestSet;
    int nrOfOverlaps = 0;
    for (int i = 0; i < input.size(); i +=2 ){
        elf1 = createSet(input[i]);
        elf2 = createSet(input[i+1]);
        if (doesOverlap(elf1, elf2)) nrOfOverlaps++;
    }

    return nrOfOverlaps;
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