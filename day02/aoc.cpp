#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read_input() {

    std::vector<std::string> result;
    std::ifstream input_file("input.txt");
    std::string line;

    while (std::getline(input_file, line)) {
        result.push_back(line);
    }
    return result;
}

int solve1(std::vector<int> playerValues, std::vector<int> elfValues) {
    int points = 0;
    for (int i = 0; i < elfValues.size(); i++) {

        int p = playerValues[i];
        int e = elfValues[i];
        if(e != p) {
            if(p == 1 && e == 3 || p == 2 && e == 1 || p == 3 && e == 2) {
                points += 6;
            }
        }
        else points += 3;
        points += playerValues[i];
    }
    return points;
}

int solve2(std::vector<int> playerValues, std::vector<int> elfValues) {
    int points = 0;

    for (int i = 0; i < elfValues.size(); i++) {
        if (playerValues[i] == 1) {
            if (elfValues[i] == 1) points += 3;
            else if (elfValues[i] == 2) points += 1;
            else if (elfValues[i] == 3) points += 2; 
        }
        else if (playerValues[i] == 2) {
            points += elfValues[i] + 3;
        }

        else if (playerValues[i] == 3) {
            if (elfValues[i] == 1) points += 2;
            else if (elfValues[i] == 2) points += 3;
            else if (elfValues[i] == 3) points += 1; 
            points += 6;
        }
    }

    return points;
}


int main() {

    std::vector<std::string> res = read_input();
    
    std::vector<char> elf;
    std::vector<char> player;

    std::vector<int> elfValues;
    std::vector<int> playerValues;


    for (std::string s : res) {
        elf.push_back(s[0]);
        player.push_back(s[2]);
    }

    for (int i = 0; i < elf.size(); i++) {
        if(elf[i] == 'A') elfValues.push_back(1);
        if(elf[i] == 'B') elfValues.push_back(2);
        if(elf[i] == 'C') elfValues.push_back(3);

        if(player[i] == 'X') playerValues.push_back(1);
        if(player[i] == 'Y') playerValues.push_back(2);
        if(player[i] == 'Z') playerValues.push_back(3);
    }

    std::cout << "C++" << std::endl;

    char* part = getenv("part");
    if (part == NULL) {
        printf("%d\n", solve1(playerValues, elfValues));
    } else if (std::string(part) == "part1") {
        printf("%d\n", solve1(playerValues, elfValues));
    } else if (std::string(part) == "part2") {
        printf("%d\n", solve2(playerValues, elfValues));
    } else {
        std::cout << "Unknown part" << std::endl;
    }

    return 0;
}