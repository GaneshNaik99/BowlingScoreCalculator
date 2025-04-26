#include "bowlingGame.hpp"

BowlingGame::BowlingGame() {}

void BowlingGame::addRoll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::calculateScore() const {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (rolls[rollIndex] == 10) { // Strike
            totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex++; // Move to the next frame
        } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) { // Spare
            totalScore += 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        } else { // Open frame
            totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }

    return totalScore;
}

const std::vector<int>& BowlingGame::getRolls() const {
    return rolls;
}
