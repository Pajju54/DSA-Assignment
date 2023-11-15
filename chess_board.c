#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int pwstatus[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int pbstatus[8] = {0, 0, 0, 0, 0, 0, 0, 0};
char board[8][8] = {
    {'R', 'H', 'C', 'K', 'Q', 'C', 'H', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'h', 'c', 'k', 'q', 'c', 'h', 'r'}};

void display();
void player1();
void player2();

int elephant(int, int);
int horse(int, int);
int queen(int, int);
int change1(int, int, int, int);
int change2(int, int, int, int);

int camel(int, int);
int pawn(int, int);
int pawnb(int, int);
int king(int, int);

int check(int, int);
int check2(int, int);

int main()
{
    int x = 0;
    char ch;

    printf("\n\tWELCOME TO CHESS GAME");
    getch();
    system("cls");

    do
    {
        x++;
        system("cls");
        display();

        if ((x % 2) == 0)
        {
            player2();
        }
        else
        {
            player1();
        }

        printf(" \n\nPress Enter To Continue ! \n\n ");

        ch = getch();
    } while (ch == 13);
}

void display()
{
    int i, j, k;

    printf(" ");
    for (i = 0; i < 8; i++)
        printf("    %d", i);
    printf("\n");

    for (k = 0; k < 8; k++)
    {
        printf("  ");
        for (i = 0; i < 42; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("%d ", k);

        for (j = 0; j < 8; j++)
        {
            printf("|| %c ", board[k][j]);
        }
        printf("|| \n");
    }

    printf("  ");
    for (i = 0; i < 42; i++)
    {
        printf("-");
    }
    printf("\n");
}

void player1()
{
    int p1, p2, c1, r1, c2, r2, invalid;
    // 13
    printf("\nPLAYER 1 - Big Case\n");
again1:
    printf("\nEnter Position of Element to change ( RC ): ");
    scanf("%d", &p1);

    r1 = p1 / 10;
    c1 = p1 % 10;

    switch (board[r1][c1])
    {
    case 'P':
        invalid = pawn(r1, c1);
        break;
    case 'R':
        invalid = elephant(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again1;
        }
        break;
    case 'H':
        invalid = horse(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again1;
        }
        break;
    case 'C':
        invalid = camel(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again1;
        }
        break;
    case 'K':
        invalid = king(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again1;
        }
        break;
    case 'Q':
        invalid = queen(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again1;
        }
        break;
    default:
        printf("Invalid Position ! ");
        goto again1;
    }

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    r2 = p2 / 10;

    c2 = p2 % 10;

    int i = change1(r1, c1, r2, c2);
    if (i == 0)
    {
        printf("Invalid move");
        goto again1;
    }
}

void player2()
{
    int p1, p2, c1, r1, c2, r2, invalid;

    printf("\nPLAYER 2 - Small Case \n");
again2:
    printf("\nEnter Position of Element to change ( RC ): ");
    scanf("%d", &p1);

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch (board[r1][c1])
    {
    case 'p':
        invalid = pawnb(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    case 'r':
        invalid = elephant(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    case 'h':
        invalid = horse(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    case 'c':
        invalid = camel(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    case 'k':
        invalid = king(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    case 'q':
        invalid = queen(r1, c1);
        if (invalid == 0)
        {
            printf("\nInvalid Move\n");
            goto again2;
        }
        break;
    default:
        printf("Invalid Position ! ");
        goto again2;
    }

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;

    int j = change2(r1, c1, r2, c2);
    if (j == 0)
    {
        printf("Invalid move");
        goto again2;
    }
}

int elephant(int r1, int c1)
{
    int i, j, n;
    int k = 0, l = 0, pk;

    printf("Available are: \n");

    n = c1;

    printf("Horizontally: \n");

    while (board[r1][n - 1] == ' ')
    {
        if (n == 0)
        {
            break;
        }
        k++;
        printf("%d%d , ", r1, n - 1);
        n--;
    }

    n = c1;

    while (board[r1][n + 1] == ' ' && (n + 1) <= 7)
    {
        k++;
        printf("%d%d , ", r1, n + 1);
        ++n;
    }

    printf("\nVertically:\n");

    n = r1;

    while (board[n - 1][c1] == ' ' && n > -1)
    {
        l++;
        printf("%d%d , ", n - 1, c1);
        --n;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ') && ((n) <= 7))
    {
        l++;
        printf("%d%d , ", n + 1, c1);
        ++n;
    }
    if (k == 0 && l == 0)
    {

        return 0;
    }
    else
    {
        return 1;
    }
}

int horse(int r1, int c1)
{
    int i = 0;
    printf("Available are: ");

    if (board[r1 + 2][c1 + 1] == ' ' || check(r1 + 2, c1 + 1))
    {
        i++;
        printf("%d%d, ", r1 + 2, c1 + 1);
    }

    if (board[r1 + 2][c1 - 1] == ' ' || check(r1 + 2, c1 - 1))
    {
        if ((c1 - 1) > -1)
        {
            i++;
            printf("%d%d, ", r1 + 2, c1 - 1);
        }
    }

    if (board[r1 + 1][c1 + 2] == ' ' || check(r1 + 1, c1 + 2))
    {
        if ((c1 + 2) != 8)
        {
            i++;
            printf("%d%d, ", r1 + 1, c1 + 2);
        }
    }

    if (board[r1 - 1][c1 + 2] == ' ' || check(r1 - 1, c1 + 2))
    {
        i++;
        printf("%d%d, ", r1 - 1, c1 + 2);
    }

    if (board[r1 - 2][c1 - 1] == ' ' || check(r1 - 2, c1 - 1))
    {
        if ((c1 - 1) != -1)
        {
            i++;
            printf("%d%d, ", r1 - 2, c1 - 1);
        }
    }

    if (board[r1 - 2][c1 + 1] == ' ' || check(r1 - 2, c1 + 1))
    {
        i++;
        printf("%d%d, ", r1 - 2, c1 + 1);
    }

    if (board[r1 + 1][c1 - 2] == ' ' || check(r1 + 1, c1 - 2))
    {
        i++;
        printf("%d%d, ", r1 + 1, c1 - 2);
    }

    if (board[r1 - 1][c1 - 2] == ' ' || check(r1 - 1, c1 - 2))
    {
        if ((c1 - 2) != -1)
        {
            i++;
            printf("%d%d, ", r1 - 1, c1 - 2);
        }
    }

    if (i == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int queen(int r1, int c1)
{
    int x = 1, y = 1, a, b, k = 0, l = 0, m = 0;
    printf("Available are: ");

    printf("Horizontal: ");

    while (board[r1][c1 - y] == ' ')
    {
        if ((c1 - y) == -1)
            break;
        k++;
        printf("%d%d , ", r1, c1 - y);
        y++;
    }

    y = 1;

    while (board[r1][c1 + y] == ' ')
    {
        if ((c1 + y) == 8)
            break;
        k++;
        printf("%d%d , ", r1, c1 + y);
        y++;
    }

    printf("Vertical: ");

    x = 1;

    while (board[r1 - x][c1] == ' ')
    {
        if ((r1 - x) == -1)
            break;
        l++;
        printf("%d%d , ", r1 - x, c1);
        x++;
    }

    x = 1;

    while (board[r1 + x][c1] == ' ')
    {
        if ((r1 + x) == 8)
            break;
        l++;
        printf("%d%d , ", r1 + x, c1);
        x++;
    }

    printf("Diagonally: ");

    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        m++;
        printf("%d%d , ", r1 - a, c1 + b);
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        m++;
        printf("%d%d , ", r1 + a, c1 - b);
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        m++;
        printf("%d%d , ", r1 + a, c1 + b);
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        m++;
        printf("%d%d , ", r1 - a, c1 - b);
        a++;
        b++;
    }
    if (k == 0 && l == 0 && m == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int change1(int r1, int c1, int r2, int c2)
{
    char temp;
    if (board[r2][c2] == ' ' || check(r2, c2))
    {
        temp = board[r1][c1];
        board[r1][c1] = ' ';
        board[r2][c2] = temp;
    }
    else
    {
        return 0;
    }
}

int change2(int r1, int c1, int r2, int c2)
{
    char temp;
    if (board[r2][c2] == ' ' || check2(r2, c2))
    {
        temp = board[r1][c1];
        board[r1][c1] = ' ';
        board[r2][c2] = temp;
    }
    else
    {
        return 0;
    }
}

int camel(int r1, int c1)
{
    int a, b, c, d, k = 0;
    printf("Available are: \n");

    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8)
            break;
        k++;
        printf("%d%d , ", r1 - a, c1 + b);
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1)
            break;
        k++;
        printf("%d%d , ", r1 + a, c1 - b);
        a++;
        b++;
    }

    a = 1, b = 1;

    while (board[r1 + a][c1 + b] == ' ')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8)
            break;
        k++;
        printf("%d%d , ", r1 + a, c1 + b);
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1)
            break;
        k++;
        printf("%d%d , ", r1 - a, c1 - b);
        a++;
        b++;
    }
    if (k == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int king(int r1, int c1)
{
    int k = 0;
    printf("Available are: ");
    if (board[r1][c1 + 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1, c1 + 1);
    }

    if (board[r1][c1 - 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1, c1 - 1);
    }

    if (board[r1 + 1][c1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 + 1, c1);
    }

    if (board[r1 - 1][c1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 - 1, c1);
    }

    if (board[r1 + 1][c1 + 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 + 1, c1 + 1);
    }

    if (board[r1 - 1][c1 - 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 - 1, c1 - 1);
    }

    if (board[r1 - 1][c1 + 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 - 1, c1 + 1);
    }

    if (board[r1 + 1][c1 - 1] == ' ')
    {
        k++;
        printf("%d%d , ", r1 + 1, c1 - 1);
    }
    if (k == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pawn(int r1, int c1)
{
    int k = 0;
    pwstatus[c1]++;

    printf("Available are: \n");

    if (pwstatus[c1] == 1)
    {
        if (board[r1 + 1][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 + 1, c1);
        }

        if (board[r1 + 2][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 + 2, c1);
        }
    }
    else
    {
        if (board[r1 + 1][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 + 1, c1);
        }

        if (check(r1 + 1, c1 + 1) == 1)
        {
            k++;
            printf("%d%d* , ", r1 + 1, c1 + 1);
        }

        if (check(r1 + 1, c1 - 1) == 1)
        {
            k++;
            printf("%d%d* , ", r1 + 1, c1 - 1);
        }
    }
    if (k == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pawnb(int r1, int c1)
{
    int k = 0;
    pbstatus[c1]++;

    printf("Available are: \n");

    if (pbstatus[c1] == 1)
    {
        if (board[r1 - 1][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 - 1, c1);
        }

        if (board[r1 - 2][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 - 2, c1);
        }
    }
    else
    {
        if (board[r1 - 1][c1] == ' ')
        {
            k++;
            printf("%d%d , ", r1 - 1, c1);
        }

        if (check2(r1 - 1, c1 - 1) == 1)
        {
            k++;
            printf("%d%d* , ", r1 - 1, c1 - 1);
        }

        if (check2(r1 - 1, c1 + 1) == 1)
        {
            k++;
            printf("%d%d* , ", r1 - 1, c1 + 1);
        }
    }
    if (k == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int check(int x, int y)
{
    switch (board[x][y])
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q':
        return 1;
        break;
    default:
        return 0;
    }
}

int check2(int x, int y)
{
    switch (board[x][y])
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q':
        return 1;
        break;
    default:
        return 0;
    }
}
