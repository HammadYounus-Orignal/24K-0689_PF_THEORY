//  NAME HAMMAD YOUNUS
//  ID   24K-0689



#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[100];
    int totalScore;
};

void playGame(struct Player *player) {
    printf("Enter the name of the player: ");
    fgets(player->playerName, 100, stdin);
    player->playerName[strcspn(player->playerName, "\n")] = 0;
    
    printf("Enter the score for each of the 12 balls (between 0 and 6):\n");
    for (int i = 0; i < 12; i++) {
        int score;
        printf("Ball %d: ", i + 1);
        scanf("%d", &score);
        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score entered. Ball %d is disregarded.\n", i + 1);
            player->ballScores[i] = 0;
        }
    }
}

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("\nWinner: %s\n", player1.playerName);
    } else if (player1.totalScore < player2.totalScore) {
        printf("\nWinner: %s\n", player2.playerName);
    } else {
        printf("\nIt's a tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");
    
    printf("\n%s's Performance:\n", player1.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d runs\n", i + 1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / 12.0);
    
    printf("\n%s's Performance:\n", player2.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d runs\n", i + 1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / 12.0);
}

int main() {
    struct Player player1, player2;
    
    printf("Welcome to the Cricket Showdown!\n");
    
    printf("\nPlayer 1, it's your turn:\n");
    playGame(&player1);
    
    printf("\nPlayer 2, it's your turn:\n");
    playGame(&player2);
    
    displayMatchScoreboard(player1, player2);
    
    findWinner(player1, player2);

    return 0;
}
