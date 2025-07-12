#include <iostream>

class LevelSystem {
private:
    int level;
    int experience;
    int experienceToNextLevel;

    // You can customize the XP needed to level up. For example:
    int calculateExperienceToNextLevel(int lvl) {
        // Simple formula: 100 * level (can be changed to any formula)
        return 100 * lvl;
    }

public:
    LevelSystem() : level(1), experience(0) {
        experienceToNextLevel = calculateExperienceToNextLevel(level);
    }

    void gainExperience(int amount) {
        experience += amount;
        std::cout << "Gained " << amount << " XP." << std::endl;

        while (experience >= experienceToNextLevel) {
            experience -= experienceToNextLevel;
            levelUp();
        }
    }

    void levelUp() {
        level++;
        experienceToNextLevel = calculateExperienceToNextLevel(level);
        std::cout << "Congratulations! You reached level " << level << "!" << std::endl;
    }

    int getLevel() const {
        return level;
    }

    int getExperience() const {
        return experience;
    }

    int getExperienceToNextLevel() const {
        return experienceToNextLevel;
    }
};

int main() {
    LevelSystem player;

    player.gainExperience(50);
    std::cout << "Level: " << player.getLevel() << ", XP: " << player.getExperience() << "/" << player.getExperienceToNextLevel() << "\n";

    player.gainExperience(70);  // This should trigger level up
    std::cout << "Level: " << player.getLevel() << ", XP: " << player.getExperience() << "/" << player.getExperienceToNextLevel() << "\n";

    player.gainExperience(250);  // Potential multiple level ups
    std::cout << "Level: " << player.getLevel() << ", XP: " << player.getExperience() << "/" << player.getExperienceToNextLevel() << "\n";

    return 0;
}
