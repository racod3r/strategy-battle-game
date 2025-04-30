
#include <iostream>
#include <cstdlib>  
#include <ctime>

int main()
{
    bool play = true;  // Main game loop control flag

    while (play == true) {  // Continue running the game loop as long as the player wants to play

        // Initialization of user and computer (boss) health
        int userHealth = 100;
        int compHealth = 0;
        // Initialization of user and computer (boss) damage
        int userDamage = 20;
        int compDamage = 0;

        std::string compDifficulty;  // Difficulty level for the boss

        bool userTurn = false;  // Boolean flag to check if it's the user's turn
        bool wentFirst = true;  // Flag to check if the player went first

        int userTurnCount = 1;  // Counter for user’s turn number
        int compTurnCount = 1;  // Counter for computer’s turn number

        int userTurnAmount = 1;  // Number of turns the user gets in one round
        int compTurnAmount = 1;  // Number of turns the computer gets in one round

        int calcUserDamage = 0;  // Calculated damage the user inflicts
        int calcCompDamage = 0;  // Calculated damage the computer inflicts

        int userAttackCount = 0;  // Number of attacks made by the user
        int compAttackCount = 0;  // Number of attacks made by the computer

        int userAttack = 0;  // Amount of user attacks landed during a turn
        int compAttack = 0;  // Amount of computer landed during a turn

        int userProtection = 0;  // Amount of protection blocks by the user
        int compProtection = 0;  // Amount of protection blocks by the computer

        int userReserve = 0;  // Reserve turns for the user
        int compReserve = 0;  // Reserve turns for the computer

        std::string userAction;  // Variable to store the user's action input

        // Display starting message
        std::cout << "=====================" << std::endl;
        std::cout << "Welcome to the battle" << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << "" << std::endl;

        // Display initial stats for the user
        std::cout << "User Strength: " << std::endl;
        std::cout << "HP: " << userHealth << std::endl;
        std::cout << "Damage: " << userDamage << std::endl;
        std::cout << "" << std::endl;

        // Prompt the user to set the difficulty of the boss
        std::cout << "Set Boss Difficulty: ";
        std::cout << "Type E for easy, M for medium or H for hard ";
        std::cin >> compDifficulty;

        // Validate user input for difficulty choice
        while (compDifficulty != "E" && compDifficulty != "M" && compDifficulty != "H") {
            std::cout << "Invalid input. Please choose E, M, or H: ";
            std::cin >> compDifficulty;
        }

        // Set boss's health and damage based on difficulty
        if (compDifficulty == "E") {
            compHealth = 100;
            compDamage = 10;
        }
        else if (compDifficulty == "M") {
            compHealth = 200;
            compDamage = 15;
        }
        else if (compDifficulty == "H") {
            compHealth = 300;
            compDamage = 20;
        }

        // Display boss stats
        std::cout << "Boss Difficulty:" << compDifficulty << std::endl;
        std::cout << "HP: " << compHealth << std::endl;
        std::cout << "Damage: " << compDamage << std::endl;
        std::cout << "" << std::endl;

        // Randomly determine who goes first
        srand(static_cast<unsigned int>(time(0)));
        int chance = rand() % 2;  // 50% chance to determine the first turn

        if (chance == 0) {
            std::cout << "You are going first!" << std::endl;
            userTurn = true;
            wentFirst = true;
            compTurnAmount = 2;  // Computer starts with 2 actions if the user goes first
        }
        else {
            std::cout << "You are going second!" << std::endl;
            userTurn = false;
            wentFirst = false;
            userTurnAmount = 2;  // User starts with 2 actions if the computer goes first
        }

        // Main game loop where turns alternate between user and computer until one of them runs out of health
        while (compHealth > 0 && userHealth > 0) {

            // User's turn 
            if (userTurn) {
                std::cout << "User Turn " << userTurnCount << ": You have " << userTurnAmount << " turn/s this go" << std::endl;

                // User chooses actions for their turn
                for (int i = 0; i < userTurnAmount; ++i) {
                   
                    // Maximum 4 reserves per turn
                    if (userReserve == 4) {
                        std::cout << "Type A to attack or D to defend ";
                    }
                    else {
                        std::cout << "Type A to attack, D to defend or R to reserve ";
                    }

                    std::cin >> userAction;

                    // Validate user input for actions
                    while (userAction != "A" && userAction != "D" && userAction != "R") {
                        std::cout << "Invalid input. Please choose A, D, or R: ";
                        std::cin >> userAction;
                    }

                    // User chooses action based on input
                    if (userAction == "A") {
                        // increment attack variables
                        userAttack = userAttack + 1;
                        userAttackCount = userAttackCount + 1;
                    }
                    else if (userAction == "D") {
                        // increment protection variable
                        userProtection = userProtection + 1;
                    }
                    else if (userAction == "R") {
                        
                        if (userReserve == 4) {
                            // Reserve limit (4) hasnt been reached
                            std::cout << "Max 4 reserves. Type A to attack or D to defend ";
                            std::cin >> userAction;

                            // input validation for user actions
                            while (userAction != "A" && userAction != "D") {
                                std::cout << "Invalid input. Please choose A or D: ";
                                std::cin >> userAction;
                            }

                            if (userAction == "A") {
                                // increment attack variables
                                userAttack = userAttack + 1;
                                userAttackCount = userAttackCount + 1;
                            }
                            else if (userAction == "D") {
                                // increment protection variable
                                userProtection = userProtection + 1;
                            }
                        }
                        else {
                            // increment reserve variable if limit (4) hasn't been reached
                            userReserve = userReserve + 1;
                        }
                    }
                }

                // Calculating user damage if user has attacked
                if (userAttackCount > 0) {
                    if (userAttack > compProtection) {
                        // Calculating attacks that landed
                        userAttack = userAttack - compProtection;
                    }
                    else {
                        // Avoids negative value
                        userAttack = 0;
                    }

                    calcUserDamage = userAttack * userDamage;  // Total damage dealt by the user 
                }

                // Summary of users turn
                std::cout << "" << std::endl;
                std::cout << "User Turn " << userTurnCount << ": " << userAttackCount << "A   " << userProtection << "D   " << userReserve << "R" << std::endl;

                // Adjust turn amounts based on whether user goes first or second
                //Add any reserves onto for the next round
                if (wentFirst == true) {
                    // Maximum of 4 turns (without reserves)
                    if (userTurnCount > 3) {
                        userTurnAmount = 4 + userReserve;
                    }
                    else {
                        userTurnAmount = userTurnCount + 1 + userReserve; // Normal turn progression
                    }
                }
                else if (wentFirst == false) {
                    // Maximum of 4 turns (without reserves)
                    if (userTurnCount > 2) {
                        userTurnAmount = 4 + userReserve;
                    }
                    else {
                        userTurnAmount = userTurnCount + 2 + userReserve; // Normal turn progression
                    }
                }

                // Ensure user can't have more than 8 actions per turn (including reserves)
                if (userTurnAmount > 8) {
                    userTurnAmount = 8;
                }

                userTurnCount = userTurnCount + 1;

                // Apply damage to the boss
                if ((compHealth - calcUserDamage) > 0) {
                    compHealth = compHealth - calcUserDamage;
                }
                else {
                    compHealth = 0;
                }

                // Output the result of the user's actions
                if (userAttackCount > 0) {
                    if (compProtection > 0) {
                        std::cout << "You attacked " << userAttackCount << " times but the boss protected itself " << compProtection << " times" << std::endl;
                        std::cout << "You hit " << userAttack << " times" << std::endl;
                    }
                    else {
                        std::cout << "You attacked " << userAttackCount << " times" << std::endl;
                    }
                    std::cout << "You hit for " << calcUserDamage << "HP" << std::endl;
                }

                // Display boss's health after the user's turn
                std::cout << "Boss Health: " << compHealth << "HP" << std::endl;
                std::cout << "" << std::endl;

                // Check if the player has won
                if (compHealth == 0) {
                    std::cout << "========" << std::endl;
                    std::cout << "You Win!" << std::endl;
                    std::cout << "========" << std::endl;
                    std::cout << "" << std::endl;
                // Give the user the option to play again
                    std::cout << "Press R to retry or E to exit" << std::endl;
                    std::cin >> userAction;
                    while (userAction != "R" && userAction != "E") {
                        std::cout << "Invalid input. Please choose R or E ";
                        std::cin >> userAction;
                    }
                    if (userAction == "R") {   // Restart the game if the user presses R
                        play = true;
                    }
                    else if (userAction == "E") {   // Exit the game if the user presses E
                        play = false;
                        std::cout << "Thanks for playing!" << std::endl;
                    }
                }

                // Reset combat stats for the next round
                calcUserDamage = 0;
                userAttackCount = 0;
                userAttack = 0;
                userReserve = 0;
                compProtection = 0;
                userTurn = false;
            }
            else {
                // Computer's turn 
                // Display the boss's turn information
                std::cout << "Boss Turn " << compTurnCount << ": The boss has " << compTurnAmount << " turn/s this go" << std::endl;

                // Loop for the boss's turns
                for (int i = 0; i < compTurnAmount; ++i) {
                    // Randomly choose the boss's action: attack (0), protect (1), or reserve (2)
                    int compActionChoice = rand() % 3;

                    if (compActionChoice == 0) {
                        // If the boss chooses to attack, increment attack variables
                        compAttack = compAttack + 1;
                        compAttackCount = compAttackCount + 1;
                    }
                    else if (compActionChoice == 1) {
                        // If the boss chooses to protect, increment protection variables
                        compProtection = compProtection + 1;
                    }
                    else if (compActionChoice == 2) {
                        // If the boss chooses to reserve, check if max reserves (4) are reached
                        if (compReserve == 4) {
                            // If max reserves, re-randomize the boss's action to attack or protect
                            compActionChoice = rand() % 2;
                            if (compActionChoice == 0) {
                                compAttack = compAttack + 1;
                                compAttackCount = compAttackCount + 1;
                            }
                            else if (compActionChoice == 1) {
                                compProtection = compProtection + 1;
                            }
                        }
                        else {
                            // Otherwise, increase the boss's reserve
                            compReserve = compReserve + 1;
                        }
                    }
                }

                // If the boss has attacked, calculate damage after protection is applied
                if (compAttackCount > 0) {
                    if (compAttack > userProtection) {
                        compAttack = compAttack - userProtection;  // Subtract protection from the attack
                    }
                    else {
                        compAttack = 0;  // No attack if protection is higher
                    }

                    // Calculate the total damage dealt by the boss
                    calcCompDamage = compAttack * compDamage;
                }

                // Display the boss's attack results
                if (userProtection > 0) {
                    std::cout << "The boss attacked " << compAttackCount << " times but you blocked " << userProtection << std::endl;
                    std::cout << "The boss hit " << compAttack << " times" << std::endl;
                }
                else {
                    std::cout << "The boss hit " << compAttack << " times" << std::endl;
                }

                // Adjust the boss's turn amount based on whether the player went first and the turn count
                //Add any reserves onto for the next round
                if (wentFirst == false) {
                    // Maximum of 4 turns (without reserves)
                    if (compTurnCount > 3) {
                        compTurnAmount = 4 + compReserve;  
                    }
                    else {
                        compTurnAmount = compTurnCount + 1 + compReserve;  // Normal turn progression
                    }
                }
                else if (wentFirst == true) {
                    // Maximum of 4 turns (without reserves)
                    if (compTurnCount > 2) {
                        compTurnAmount = 4 + compReserve;  
                    }
                    else {
                        compTurnAmount = compTurnCount + 2 + compReserve;  // Normal turn progression
                    }
                }

                // Ensure the boss does not have more than 8 turns in a round
                if (compTurnAmount > 8) {
                    compTurnAmount = 8;
                }

                // Increment the boss's turn count for the next round
                compTurnCount = compTurnCount + 1;

                // Apply damage to the user's health
                if ((userHealth - calcCompDamage) > 0) {
                    userHealth = userHealth - calcCompDamage;
                }
                else {
                    userHealth = 0;  // Ensure health doesn't go below zero
                }

                // Display the damage dealt to the user
                if (compAttackCount > 0) {
                    std::cout << "The boss hit you for " << calcCompDamage << "HP" << std::endl;
                }

                // Display the user's current health
                std::cout << "Your health: " << userHealth << "HP" << std::endl;
                std::cout << "" << std::endl;

                // Check if the player has lost
                if (userHealth == 0) {
                    std::cout << "=========" << std::endl;
                    std::cout << "Game Over" << std::endl;
                    std::cout << "=========" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "Press R to retry or E to exit" << std::endl;

                    // Give the user the option to play again
                    std::cin >> userAction;
                    while (userAction != "R" && userAction != "E") {
                        std::cout << "Invalid input. Please choose R or E ";
                        std::cin >> userAction;
                    }

                    if (userAction == "R") {
                        play = true;  // Restart the game if the user presses R
                    }
                    else if (userAction == "E") {
                        play = false;  // Exit the game if the user presses E
                        std::cout << "Thanks for playing!" << std::endl;
                    }
                }

                // Reset variables for the next turn
                calcCompDamage = 0;
                compAttackCount = 0;
                compAttack = 0;
                compReserve = 0;
                userProtection = 0;

                // Switch the turn to the user
                userTurn = true;
            }
        }

    }
    }
   