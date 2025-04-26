#ifndef BOWLINGGAME_HPP
#define BOWLINGGAME_HPP

#include <vector>

// BowlingGame class definition
class BowlingGame {
public:
    BowlingGame();
    void addRoll(int pins);          // Function to add a roll
    int calculateScore() const;     // Function to calculate the total score
    const std::vector<int>& getRolls() const; // Function to access rolls (renamed to avoid conflict)

private:
    std::vector<int> rolls;         // Stores pins knocked down for each roll
};

#endif // BOWLINGGAME_HPP
