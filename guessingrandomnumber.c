#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int secretNumber = (rand() % 100) + 1;
    int userGuess = 0;
    int attempts = 0;
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");
    while (userGuess != secretNumber) {
        printf("Enter your guess: ");
        if (scanf("%d", &userGuess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
              while (getchar() != '\n');
              continue;
        }
        attempts++;
        if (userGuess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (userGuess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed number was right!\n");
            printf("The correct number was: %d\n", secretNumber);
            printf("Total attempts: %d\n", attempts);
        }
    }
    return 0;
}
