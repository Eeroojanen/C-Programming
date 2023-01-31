#include <stdio.h>
#include <ncurses.h>
#include <math.h>


 struct cell
    {
    int current;
    int future;
    };

int game(struct cell board [15][15]);
int print_board(struct cell board [15][15]);
int calculate_game(struct cell board [15][15]);
int current_game(struct cell board [15][15]);
int count_neightbours(int i, int j, struct cell board [15][15]);

int main()
{
    int i,j;
    struct cell board [15] [15] = {0, 0};



    game(board);

    for (i = 0; i < 5; i++)
    {
        print_board(board);
        calculate_game(board);
        current_game(board);
        printf("\n");
    }
    
}

int game(struct cell board [15][15])
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
        board[i][j].current=0;
        }
    }
    board[4][4].current = 1;
    board[4][3].current = 1;
    board[3][4].current = 1;
    board[3][2].current = 1;
    board[5][3].current = 1;
}

int print_board(struct cell board [15][15])
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(board[i][j].current==1)
            {
            printf("o");
            }
            else if(board[i][j].current==0)
            {
            printf(".");
            }
        }
        printf("\n");
    }
}



int calculate_game(struct cell board [15][15])
{
    int i; 
    int j;
     for(i = 0; i < 15; i++)
    {
        for(j = 0; j < 15; j++)
        {
            count_neightbours(i,j,board);
        }

    }
} 

int count_neightbours(int i, int j, struct cell board [15][15])
{
    int neig = 0;
    if(board[i][j - 1].current == 1)
    {
        neig++;
    }
    if(board[i][j + 1].current == 1)
    {
        neig++;
    } 
    if(board[i - 1][j - 1].current == 1)
    {
        neig++;
    } 
    if(board[i - 1][j].current == 1) 
    {
        neig++;
    }
    if(board[i - 1][j + 1].current == 1)
    { 
        neig++;
    }
    if(board[i + 1][j - 1].current == 1) 
    {
        neig++;
    }
    if(board[i + 1][j].current == 1) 
    {
        neig++;
    }
    if(board[i + 1][j + 1].current == 1)
    {
        neig++;
    } 
    else if(board[i][j].current == 1 && (neig < 2))
    {
         board[i][j].future = 0;
    }
    else if(board[i][j].current == 1 && (neig >= 4))
    {
        board[i][j].future = 0;
    }
    else if((board[i][j].current == 1) && (neig == 2 || neig == 3))
    {
        board[i][j].future = 1;
    }
    else if((board[i][j].current == 0 && neig == 3))
    {
        board[i][j].future = 1;
    }
}

int current_game(struct cell board [15][15])
{
   for(int i = 0; i < 15; i++)
   {
       for(int j = 0; j < 15; j++)
       {
           board[i][j].current = board[i][j].future;
       }
   }
}