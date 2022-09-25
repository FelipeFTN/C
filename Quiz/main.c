#include <stdio.h>
#include <stdlib.h>

int startGame();
void results(int pontuation);

int main() {
    int i;
    int pontuation;

    printf("\tWelcome to the Quiz\n\n");

    printf("> Press 1 to start the game\n");
    printf("> Press 2 to quit the game\n\n\n");

    scanf("%d", &i);

    if (i != 1) {
        printf("The game has ended.");
        exit(1);
    }

    pontuation = startGame();

    results(pontuation);

    return 0;
}

int startGame() {
    int answer;
    int points = 0;

    printf("The game has started!\n\n");

    printf("1. Which one is the first search engine in internet?\n\n");
    printf("1) Google\n");
    printf("2) Archie\n");
    printf("3) Wais\n");
    printf("4) Altavista\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        points++;
    } else {
        points--;
    }

    printf("2. Which one is the first web browser invented in 1990?\n\n");
    printf("1) Internet Explorer\n");
    printf("2) Mosaic\n");
    printf("3) Mozilla\n");
    printf("4) Nexus\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 4) {
        points++;
    } else {
        points--;
    }

    printf("3. The first computer virus is known as?\n\n");
    printf("1) Rabbit\n");
    printf("2) Creeper Virus\n");
    printf("3) Elk Cloner\n");
    printf("4) SCA Virus\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        points++;
    } else {
        points--;
    }

    printf("4. Firewall in computer is used for?\n\n");
    printf("1) Security\n");
    printf("2) Data Transmission\n");
    printf("3) Monitoring\n");
    printf("4) Authentication\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 1) {
        points++;
    } else {
        points--;
    }

    printf("5. Which of the following is not a database management software?\n\n");
    printf("1) MySQL\n");
    printf("2) Oracle\n");
    printf("3) Cobal\n");
    printf("4) Sybase\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        points++;
    } else {
        points--;
    }

    return points;
}

void results(int pontuation) {
    printf("\t====== RESULTS ======\n");
    if (pontuation >= 4) {
        printf("\t   Congratulations!\n");
        printf("\tYou scored %d out of 5!\n", pontuation);
    } else {
        printf("\t  Bad Results! :(\n");
        printf("\tDon't give up, try again at any time!\n");
    }
}