#include <iostream>
#include "bowlingGame.hpp"

int main() {
    BowlingGame game;

    std::cout << "Welcome to the Bowling Score Calculator!\n";

    for (int frame = 1; frame <= 10; ++frame) {
        int pins1, pins2 = 0;

        // First roll
        std::cout << "Frame " << frame << ", Roll 1: ";
        std::cin >> pins1;

        if (pins1 < 0 || pins1 > 10) {
            std::cout << "Invalid input. Please enter a value between 0 and 10.\n";
            frame--; // Retry the same frame
            continue;
        }
        game.addRoll(pins1);

        // Second roll (if not a strike)
        if (pins1 < 10) {
            std::cout << "Frame " << frame << ", Roll 2: ";
            std::cin >> pins2;

            if (pins2 < 0 || pins1 + pins2 > 10) {
                std::cout << "Invalid input. Please ensure the total pins knocked down in one frame do not exceed 10.\n";
                frame--; // Retry the same frame
                continue;
            }
            game.addRoll(pins2);
        }

        // Handle 10th frame bonus logic
        if (frame == 10 && (pins1 == 10 || pins1 + pins2 == 10)) {
            int bonusRolls = (pins1 == 10) ? 2 : 1; // 2 bonus rolls for strike, 1 for spare
            for (int i = 0; i < bonusRolls; ++i) {
                int bonusPins;
                std::cout << "Bonus Roll " << (i + 1) << ": ";
                std::cin >> bonusPins;

                if (bonusPins < 0 || bonusPins > 10) {
                    std::cout << "Invalid input. Please enter a value between 0 and 10.\n";
                    i--; // Retry the same bonus roll
                    continue;
                }
                game.addRoll(bonusPins);
            }
        }
    }

    std::cout << "Total Score: " << game.calculateScore() << std::endl;
    return 0;
}
