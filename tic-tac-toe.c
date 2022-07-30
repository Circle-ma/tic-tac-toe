/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  :MA Yu Ying
 * Student ID    :1155157879
 * Class/Section :ENGG1110C
 * Date          :13/11/2020
 */

#include <stdio.h>

/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2

/* Initialize the game board by setting all nine squares to EMPTY */
void initGameBoard(int gameBoard[3][3])
{
  int i, j;

  for (i = 0; i <= 2; i++)
  {

    for (j = 0; j <= 2; j++)
    {

      gameBoard[i][j] = EMPTY;
    }
  }
}

/* Display the game board on the screen
   In Part 1, you are required to follow exactly the output format stated in the project specification
   You are welcome to design and implement a better one in Part 2
   IMPORTANT: Using other output format in Part 1 will result in mark deduction
              If you have a better one, please use them in Part 2 instead */

// TODO: Complete the printGameBoard(...) function here
void printGameBoard(int gameBoard[3][3])
{
  int i, j, k, viewGameBoard[3][3];
  k = 7;
  for (i = 0; i <= 2; i++)
  {
    for (j = 0; j <= 2; j++)
    {
      if (gameBoard[i][j] == CIRCLE)
      {
        viewGameBoard[i][j] = 'O';
      }
      if (gameBoard[i][j] == CROSS)
      {
        viewGameBoard[i][j] = 'X';
      }
      if (gameBoard[i][j] == EMPTY)
      {
        viewGameBoard[i][j] = k + 48;
      }
      k++;
    }
    k = k - 6;
  }

  printf("=========\n");
  printf("|%c||%c||%c|\n", viewGameBoard[0][0], viewGameBoard[0][1], viewGameBoard[0][2]);
  printf("|%c||%c||%c|\n", viewGameBoard[1][0], viewGameBoard[1][1], viewGameBoard[1][2]);
  printf("|%c||%c||%c|\n", viewGameBoard[2][0], viewGameBoard[2][1], viewGameBoard[2][2]);
  printf("=========\n");
}

int invalidInputChecking(int gameBoard[3][3], int choice)
{ // function to check if the location is occupied
  int invalid = 0;
  int i, j;

  if (choice == 7 || choice == 8 || choice == 9)
  { // locate the position
    i = 0;
  }
  if (choice == 4 || choice == 5 || choice == 6)
  {
    i = 1;
  }
  if (choice == 1 || choice == 2 || choice == 3)
  {
    i = 2;
  }
  if (choice == 7 || choice == 4 || choice == 1)
  {
    j = 0;
  }
  if (choice == 8 || choice == 5 || choice == 2)
  {
    j = 1;
  }
  if (choice == 9 || choice == 6 || choice == 3)
  {
    j = 2;
  }

  if (gameBoard[i][j] != EMPTY)
  { // if to check if the position is empty,if not empty,invalid=1
    invalid = 1;
  }

  return invalid; // return the value of invalid to the invalidInputChecking function
}

/* Ask the human player to place the mark.
   In Part 1, you can assume that the user input must be valid (i.e, an empty space between 1 and 9).
   You are welcome to perform error checking in Part 2. */
void placeMarkByHumanPlayer(int gameBoard[3][3], int mark)
{

  int i, j, choice;
  char check[1000];          // string to store user input
  fgets(check, 1000, stdin); // get user input

  int stringlength; // variable to indicate string length
  for (stringlength = 0; check[stringlength] != '\0'; ++stringlength)
    ; // for loop to count the string length

  while (stringlength > 2 || check[0] < '1' || check[0] > '9')
  { // while loop to check if the input is within 1-9
    printf("You have entered an invalid input!\nPlease re-enter a valid number:\n");
    fgets(check, 1000, stdin);
    for (stringlength = 0; check[stringlength] != '\0'; ++stringlength)
      ;
  }

  choice = check[0] - 48; // change ASCII code to a corresponding integer

  while (invalidInputChecking(gameBoard, choice) == 1)
  { // using while loop to call invalidInputChecking function  until the input location is valid

    printf("You have entered an invalid input!\nPlease re-enter a valid number:\n"); // repeat the above code
    fgets(check, 1000, stdin);
    for (stringlength = 0; check[stringlength] != '\0'; ++stringlength)
      ;
    while (stringlength > 2 || check[0] < '1' || check[0] > '9')
    {
      printf("You have entered an invalid input!\nPlease re-enter a valid number:\n");
      fgets(check, 1000, stdin);
      for (stringlength = 0; check[stringlength] != '\0'; ++stringlength)
        ;
    }
    choice = check[0] - 48;
  }

  if (mark == 1)
  {
    if (choice == 7 || choice == 8 || choice == 9)
    {
      i = 0;
    }
    if (choice == 4 || choice == 5 || choice == 6)
    {
      i = 1;
    }
    if (choice == 1 || choice == 2 || choice == 3)
    {
      i = 2;
    }
    if (choice == 7 || choice == 4 || choice == 1)
    {
      j = 0;
    }
    if (choice == 8 || choice == 5 || choice == 2)
    {
      j = 1;
    }
    if (choice == 9 || choice == 6 || choice == 3)
    {
      j = 2;
    }
    gameBoard[i][j] = CIRCLE;
  }

  if (mark == 2)
  {
    if (choice == 7 || choice == 8 || choice == 9)
    {
      i = 0;
    }
    if (choice == 4 || choice == 5 || choice == 6)
    {
      i = 1;
    }
    if (choice == 1 || choice == 2 || choice == 3)
    {
      i = 2;
    }
    if (choice == 7 || choice == 4 || choice == 1)
    {
      j = 0;
    }
    if (choice == 8 || choice == 5 || choice == 2)
    {
      j = 1;
    }
    if (choice == 9 || choice == 6 || choice == 3)
    {
      j = 2;
    }
    gameBoard[i][j] = CROSS;
  }
}

/* Return 1 if there is a winner in the game, otherwise return 0 */
/* Note: the winner is the current player indicated in main() */
int hasWinner(int gameBoard[3][3])
{
  int win = 0;
  for (int a = 0; a < 3; a++)
  {
    if (gameBoard[a][0] == gameBoard[a][1] && gameBoard[a][1] == gameBoard[a][2] && gameBoard[a][0] != EMPTY)
    {
      win = 1;
    }
  }
  for (int b = 0; b < 3; b++)
  {
    if (gameBoard[0][b] == gameBoard[1][b] && gameBoard[1][b] == gameBoard[2][b] && gameBoard[0][b] != EMPTY)
    {
      win = 1;
    }
  }
  if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != EMPTY)
  {
    win = 1;
  }
  if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != EMPTY)
  {
    win = 1;
  }

  return win;
}

/* Return 1 if the game board is full, otherwise return 0 */

// TODO: Complete the isFull(...) function here
int isFull(int gameBoard[3][3])
{
  int e = 0;
  for (int c = 0; c < 3; c++)
  {
    for (int d = 0; d < 3; d++)
    {
      if (gameBoard[c][d] == CIRCLE || gameBoard[c][d] == CROSS)
      {
        e++;
      }
    }
  }
  if (e == 9)
  {
    return 1;
  }
  return 0;
}

/* Determine the next move of the computer player.
   In Part 1, you are required to implement the following naive strategy:
   place the mark in the first empty space scanning from 1 to 9.
   You are welcome to design and implement better strategies in Part 2.
   IMPORTANT: Using other strategies in Part 1 will result in mark deduction.
              If you have better strategies, please use them in Part 2 instead. */

// TODO: Complete the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[3][3])
{
  int f = 0;
  if (gameBoard[1][1] == EMPTY)
  { // Preferably with pieces placed in the centre
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  // Check if computer can win
  // for column X
  if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[0][2] && gameBoard[0][1] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[0][2] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[0][1] == EMPTY)
  {
    gameBoard[0][1] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][0] == CROSS && f == 0 && gameBoard[1][2] == EMPTY)
  {
    gameBoard[1][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[1][2] && gameBoard[1][1] == CROSS && f == 0 && gameBoard[1][0] == EMPTY)
  {
    gameBoard[1][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[1][2] && gameBoard[1][0] == CROSS && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][0] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[2][1] == gameBoard[2][2] && gameBoard[2][1] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[2][2] && gameBoard[2][0] == CROSS && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }
  // for row X
  if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[2][0] && gameBoard[1][0] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[2][0] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[1][0] == EMPTY)
  {
    gameBoard[1][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[0][1] == CROSS && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[2][1] && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][1] == EMPTY)
  {
    gameBoard[0][1] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[2][1] && gameBoard[0][1] == CROSS && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[0][2] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][2] == gameBoard[2][2] && gameBoard[1][2] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[2][2] && gameBoard[0][2] == CROSS && f == 0 && gameBoard[1][2] == EMPTY)
  {
    gameBoard[1][2] = CROSS;
    f = 1;
  }
  // for Diagonal 951 X
  if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[2][0] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[2][0] && gameBoard[0][2] == CROSS && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  // for Diagonal 753 X
  if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[2][2] && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0] == CROSS && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }

  // Check if computer will lose

  // for column O
  if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[0][2] && gameBoard[0][1] == CIRCLE && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[0][2] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[0][1] == EMPTY)
  {
    gameBoard[0][1] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][0] == CIRCLE && f == 0 && gameBoard[1][2] == EMPTY)
  {
    gameBoard[1][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[1][2] && gameBoard[1][1] == CIRCLE && f == 0 && gameBoard[1][0] == EMPTY)
  {
    gameBoard[1][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[1][2] && gameBoard[1][0] == CIRCLE && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][0] == CIRCLE && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[2][1] == gameBoard[2][2] && gameBoard[2][1] == CIRCLE && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[2][2] && gameBoard[2][0] == CIRCLE && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }
  // for row O
  if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[2][0] && gameBoard[1][0] == CIRCLE && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[2][0] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[1][0] == EMPTY)
  {
    gameBoard[1][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[0][1] == CIRCLE && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[2][1] && gameBoard[1][1] == CIRCLE && f == 0 && gameBoard[0][1] == EMPTY)
  {
    gameBoard[0][1] = CROSS;
    f = 1;
  }
  if (gameBoard[0][1] == gameBoard[2][1] && gameBoard[0][1] == CIRCLE && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[0][2] == CIRCLE && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][2] == gameBoard[2][2] && gameBoard[1][2] == CIRCLE && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[2][2] && gameBoard[0][2] == CIRCLE && f == 0 && gameBoard[1][2] == EMPTY)
  {
    gameBoard[1][2] = CROSS;
    f = 1;
  }
  // for Diagonal 951 O
  if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == CIRCLE && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[2][0] == CIRCLE && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[2][0] && gameBoard[0][2] == CIRCLE && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  // for Diagonal 753 O
  if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][1] == gameBoard[2][2] && gameBoard[1][1] == CIRCLE && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0] == CIRCLE && f == 0 && gameBoard[1][1] == EMPTY)
  {
    gameBoard[1][1] = CROSS;
    f = 1;
  }
  // For different Forks
  // FOR 593 to 3
  if (gameBoard[1][1] == gameBoard[0][2] && gameBoard[1][1] != EMPTY && gameBoard[2][0] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }

  // for 73 to 2
  if (gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }

  // FOR 19 to 2
  if (gameBoard[2][0] == gameBoard[0][2] && gameBoard[2][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][1] == EMPTY)
  {
    gameBoard[2][1] = CROSS;
    f = 1;
  }

  // FOR 42 43 72 to 1
  if (gameBoard[1][0] == gameBoard[2][1] && gameBoard[1][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[2][2] && gameBoard[1][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }
  if (gameBoard[0][0] == gameBoard[2][1] && gameBoard[0][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][0] == EMPTY)
  {
    gameBoard[2][0] = CROSS;
    f = 1;
  }

  // FOR 62 61 92 to 3
  if (gameBoard[1][2] == gameBoard[2][1] && gameBoard[1][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][2] == gameBoard[2][0] && gameBoard[1][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }
  if (gameBoard[0][2] == gameBoard[2][1] && gameBoard[0][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[2][2] == EMPTY)
  {
    gameBoard[2][2] = CROSS;
    f = 1;
  }

  // FOR 48 18 49 to 7
  if (gameBoard[1][0] == gameBoard[0][1] && gameBoard[1][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[2][0] == gameBoard[0][1] && gameBoard[2][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }
  if (gameBoard[1][0] == gameBoard[0][2] && gameBoard[1][0] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][0] == EMPTY)
  {
    gameBoard[0][0] = CROSS;
    f = 1;
  }

  // FOR 68 38 67 to 9
  if (gameBoard[1][2] == gameBoard[0][1] && gameBoard[1][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[2][2] == gameBoard[0][1] && gameBoard[2][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }
  if (gameBoard[1][2] == gameBoard[0][0] && gameBoard[1][2] != EMPTY && gameBoard[1][1] == CROSS && f == 0 && gameBoard[0][2] == EMPTY)
  {
    gameBoard[0][2] = CROSS;
    f = 1;
  }

  // If none of the above happens
  int x, y, z;
  if (!f)
  {
    for (x = 2; x >= 0; x--)
    {
      z = 0;
      for (y = 0; y <= 2; y++)
      {
        if (gameBoard[x][y] == EMPTY)
        {
          gameBoard[x][y] = CROSS;
          break;
        }
        z++;
      }
      if (z != 3)
      {
        break;
      }
    }
  }
  f = 0;
}

/* The main function */
int main()
{
  /* Local variables */
  int gameBoard[3][3];   // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
  int currentPlayer;     // 1: Player 1 (Human)   2: Player 2 (Human) or Computer Player
  int gameEnds;          // 0: The game continues   1: The game ends
  int numOfHumanPlayers; // 1 or 2
  char ckvalid[1000];    // string to store user input
  /* Initialize the local variables by invoking a function, using assignment statements, and reading the user input */
  initGameBoard(gameBoard);
  currentPlayer = 1;
  gameEnds = 0;
  printf("How many human players [1-2]?\n");
  fgets(ckvalid, 1000, stdin); // get input from user
  int stringlength;            // variable to indicate the string length

  for (stringlength = 0; ckvalid[stringlength] != '\0'; ++stringlength)
    ; // using for loop to count the string length

  while (stringlength > 2 || ckvalid[0] < '1' || ckvalid[0] > '2')
  { // while loop to check user input validity
    printf("You have entered an invalid number!\nPlease input a integer[1/2]:\n");
    fgets(ckvalid, 1000, stdin);
    for (stringlength = 0; ckvalid[stringlength] != '\0'; ++stringlength)
      ;
  }

  numOfHumanPlayers = ckvalid[0] - 48; // change ASCII code to a corresponding integer
  printGameBoard(gameBoard);

  while (numOfHumanPlayers == 1)
  {

    printf("Player 1, please place your mark [1-9]:\n");

    placeMarkByHumanPlayer(gameBoard, 1);

    printGameBoard(gameBoard);

    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1)
    {
      printf("Player 1 wins! Congratulations!\n");
      break;
    }

    isFull(gameBoard);
    if (isFull(gameBoard) == 1)
    {
      printf("Draw game!\n");
      break;
    }

    printf("Computer places the mark:\n");
    placeMarkByComputerPlayer(gameBoard);

    printGameBoard(gameBoard);

    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1)
    {
      printf("Computer wins!");
      break;
    }

    isFull(gameBoard);
    if (isFull(gameBoard) == 1)
    {
      printf("Draw game!\n");
      break;
    }
  }

  while (numOfHumanPlayers == 2)
  {

    printf("Player 1, please place your mark [1-9]:\n");

    placeMarkByHumanPlayer(gameBoard, 1);

    printGameBoard(gameBoard);

    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1)
    {
      printf("Player 1 wins! Congratulations!\n");
      break;
    }

    isFull(gameBoard);
    if (isFull(gameBoard) == 1)
    {
      printf("Draw game!\n");
      break;
    }

    printf("Player 2, please place your mark [1-9]:\n");

    placeMarkByHumanPlayer(gameBoard, 2);

    printGameBoard(gameBoard);

    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1)
    {
      printf("Player 2 wins! Congratulations!\n");
      break;
    }

    isFull(gameBoard);
    if (isFull(gameBoard) == 1)
    {
      printf("Draw game!\n");
      break;
    }
  }
  int end;
  scanf("%d", &end);
  return 0;
}
