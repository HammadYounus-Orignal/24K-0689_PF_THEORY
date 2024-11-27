// NAME HAMMAD YOUNUS
// ID   24K-0689





#include <stdio.h>
#include <string.h>

typedef struct
{
    int ballScores[12];
    char playerName[30];
    int totalScore;
} Player;

void playGame(Player *ptr);
int validateScore(int score);
void findWinner(Player *ptr1, Player *ptr2);
void displayMatchScoreboard(Player player1, Player player2);

int main()
{
    Player player1, player2;
    printf("Welcome to Cricket Showdown!\n");

    printf("Enter the name of Player 1: ");
    fgets(player1.playerName, 30, stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = '\0';

    printf("Enter the name of Player 2: ");
    fgets(player2.playerName, 30, stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = '\0';

    printf("\nLet the game begin!\n");
    playGame(&player1);
    playGame(&player2);

    findWinner(&player1, &player2);
    displayMatchScoreboard(player1, player2);

    return 0;
}

void playGame(Player *ptr)
{
    printf("%s, enter your scores ranging from 0 to 6 inclusive.\n", (*ptr).playerName);
    for (int i = 0; i < 12; i++)
    {
        printf("Ball %d: ", i + 1);
        scanf("%d", &((*ptr).ballScores[i]) );
        if (validateScore((*ptr).ballScores[i]) == -1)
        {
            (*ptr).ballScores[i] = 0;
            printf("Invalid score! Your score for ball %d will be marked as 0.\n", i + 1);
        }
    }
}

int validateScore(int score)
{
    if (score >= 0 && score <= 6)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void findWinner(Player *ptr1, Player *ptr2)
{
    (*ptr1).totalScore = 0;
    (*ptr2).totalScore = 0;

    for (int i = 0; i < 12; i++)
    {
        (*ptr1).totalScore += (*ptr1).ballScores[i];
    }

    for (int i = 0; i < 12; i++)
    {
        (*ptr2).totalScore += (*ptr2).ballScores[i];
    }

    if ((*ptr1).totalScore > (*ptr2).totalScore)
    {
        printf("\n%s is the WINNER with a total score of %d runs!\n", (*ptr1).playerName, (*ptr1).totalScore);
    }
    else if ((*ptr1).totalScore < (*ptr2).totalScore)
    {
        printf("\n%s is the WINNER with a total score of %d runs!\n", (*ptr2).playerName, (*ptr2).totalScore);
    }
    else
    {
        printf("\nIt is a TIE between %s and %s with a joint total score of %d runs!\n", (*ptr1).playerName, (*ptr2).playerName, (*ptr1).totalScore);
    }
}

void displayMatchScoreboard(Player player1, Player player2)
{
    printf("\nMATCH SCOREBOARD\n");

    printf("\nPlayer 1: %s\n", player1.playerName);
    printf("Ball scores: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", (float) player1.totalScore/12.0);

    printf("\nPlayer 2: %s\n", player2.playerName);
    printf("Ball scores: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", (float) player2.totalScore/12.0);
}}