
#include <stdio.h>
#include <stdbool.h>

int N = 8;

bool SolveNQ(int board[N][N], int column);
bool UnderAttackCheck(int board[N][N], int row, int column);

int main(int argc, char *argv[]) {

  int a = N, b = N;

  int board[a][b];

  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      board[a][b] = 0;
    }
  }
  
  if (SolveNQ(board, 0) == false) {
    printf("No solution available");
    return 1;
  }

  for (int c = 0; c < N; c++) {
    for (int d = 0; d < N; d++) {
      printf("%d ", board[c][d]);
    }
    printf("\n");
  }
}

bool SolveNQ(int board[N][N], int column) {
  
  if (column >= N) {
    return true;
  }

  for (int a = 0; a < N; a++) {

    if (UnderAttackCheck(board, a, column)) {
      board[a][column] = 1;

      if (SolveNQ(board, column + 1)) {
        return true;
      }

      board[a][column] = 0;
    }  
  }

  return false;
}

bool UnderAttackCheck(int board[N][N], int row, int column) {

  for (int a = 0; a < column; a++) {
    if (board[row][a] == 1) {
      return false;
    }
  }

  for (int b = row, c = column; b >= 0 && c >= 0; b--, c--) {
    if (board[b][c] == 1) {
      return false;
    }
  }

  for (int d = row, e = column; d < N && e >= 0; d++, e--) {
    if (board[d][e] == 1) {
      return false;
    }
  }

  return true;
}


