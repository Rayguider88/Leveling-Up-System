#include <iostream>

class LevelSystem {
private:
    int level;
    int experience;
    int experienceToNextLevel;

    // Stats
    int strength;
    int agility;
    int health;

    int skillPoints;  // Points to allocate on level up

    int calculateExperienceToNextLevel(int lvl) {
        return 100 * lvl;
    }

    void levelUp() {
        level++;
        experienceToNextLevel = calculateExperienceToNextLevel(level);
        skillPoints += 5;  // Give 5 skill points per level
        std::cout << "Congratulations! You reached level " << level << "!" << std::endl;
        std::cout << "You have " << skillPoints << " skill points to allocate." << std::endl;
        allocateSkillPoints();
    }

    void allocateSkillPoints() {
        while (skillPoints > 0) {
            std::cout << "\nCurrent Stats - Strength: " << strength
                      << ", Agility: " << agility
                      << ", Health: " << health << std::endl;
            std::cout << "Skill Points left: " << skillPoints << std::endl;
            std::cout << "Allocate points to (1) Strength, (2) Agility, (3) Health: ";

            int choice, points;
            std::cin >> choice;

            if (choice < 1 || choice > 3) {
                std::cout << "Invalid choice. Try again." << std::endl;
                continue;
            }

            std::cout << "How many points to allocate? ";
            std::cin >> points;

            if (points < 0 || points > skillPoints) {
                std::cout << "Invalid amount. You only have " << skillPoints << " points." << std::endl;
                continue;
            }

            switch (choice) {
                case 1: strength += points; break;
                case 2: agility += points; break;
                case 3: health += points * 5; break;  // Each health point worth 5 per skill point
            }

            skillPoints -= points;
        }
        std::cout << "Allocation complete! Final Stats:" << std::endl;
        printStats();
    }

public:
    LevelSystem() 
        : level(1), experience(0), strength(10), agility(5), health(100), skillPoints(0) {
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

    void printStats() const {
        std::cout << "Stats - Strength: " << strength
                  << ", Agility: " << agility
                  << ", Health: " << health << std::endl;
    }
};

int main() {
    LevelSystem player;

    player.gainExperience(120);  // Level up once
    player.gainExperience(250);  // Possibly multiple level ups

    return 0;
}
