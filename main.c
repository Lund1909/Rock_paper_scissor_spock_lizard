// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the winning score constant
#define WINNING_SCORE 5

// Main function - program starts here
int main() {
  // Seed with current time = new numbers each run
  srand(time(NULL));

  // 2 Arrays of move symbols and move names as strings for display
  char *moves[] = {"🗿", "📜", "✂️", "🖖", "🦎"};
  char *names[] = {"rock", "paper", "scissors", "Spock", "lizard"};

  // 2D lookup table: wins[i][j] = 1 = i beats j, 0 = i loses
  int wins[5][5] = {{0, 0, 1, 0, 1},
                    {1, 0, 0, 1, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 1, 0, 0},
                    {0, 1, 0, 1, 0}};

  // Variables for game state
  char choice;
  int playerMove, agentMove;
  int playerScore = 0, agentScore = 0;

  printf("Welcome to 🗿 📜 ✂️ 🖖 🦎 !\n");

  // Main menu loop
  while (1) {
    // Display menu options
    printf("(s) Single player\n");
    printf("(e) Exit\n");
    printf("Select an item: ");

    // Read user choice and clear input buffer
    scanf(" %c", &choice);
    while (getchar() != '\n')
      ;

    // Menu selection
    if (choice == 's') {
      printf("Starting game 🎉\n\n");

      // Main game loop - continue until someone reaches WINNING_SCORE
      while (playerScore < WINNING_SCORE && agentScore < WINNING_SCORE) {
        printf("Make your choice!:\n");
        printf("0🗿 || 1📜 || 2✂️ || 3🖖 || 4🦎 : ");

        // Read and validate player move
        if (scanf("%d", &playerMove) != 1 || playerMove < 0 || playerMove > 4) {
          printf("❌Wrong input, please try again using 0🗿 || 1📜 || 2✂️ || "
                 "3🖖 || 4🦎 :\n");
          while (getchar() != '\n')
            ;
          continue;
        }

        // Generate random agent move (0-4)
        agentMove = rand() % 5;

        // Display both moves with numbers and names
        printf("You: %d%s (%s) || Agent: %d%s (%s)\n", playerMove,
               moves[playerMove], names[playerMove], agentMove,
               moves[agentMove], names[agentMove]);

        // Determine round winner and update scores
        if (playerMove == agentMove) {
          printf("It's a tie!\n");
        } else if (wins[playerMove][agentMove]) {
          playerScore++;
          printf("You win this round!\n");
        } else {
          agentScore++;
          printf("Agent wins this round!\n");
        }

        // Display current score using emojis
        printf("👤🤖 %d:%d\n\n", playerScore, agentScore);
      }

      // Game ended - output winner and exit program
      if (playerScore >= WINNING_SCORE) {
        printf("🏆 You won!\n");
      } else {
        printf("🏆 Agent won!\n");
      }
      break;

    } else if (choice == 'e') {
      break;
    } else {
      printf("Invalid choice. Please select 's' or 'e'.\n");
    }
  }
  return 0;
}
