#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define BROD '#'
#define MORE '~'


char A[11][12];
char B[11][12];
void ispisA() {
    int i, j;
    printf("\n");
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 12; j++) {
            putchar(A[i][j]);
        }
        puts("");
    }
}

void ispisB() {
    int i, j;
    printf("\n");
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 12; j++) {
            putchar(B[i][j]);
        }
        puts("");
    }
}

void dodaj(int d) {
    int x, y, i, moze, dir;
    while (1) {
        x = rand() % 11;
        y = rand() % 11;
        dir = rand() % 2;
        if (A[x][y] != MORE) continue;
        if (x + 1 < 11 && A[x + 1][y] == BROD) continue;
        if (x - 1 >= 1 && A[x - 1][y] == BROD) continue;
        if (y + 1 < 11 && A[x][y + 1] == BROD) continue;
        if (y - 1 >= 1 && A[x][y - 1] == BROD) continue;
        if (x + 1 < 11 && y + 1 < 11 && A[x + 1][y + 1] == BROD) continue;
        if (x + 1 < 11 && y - 1 >= 1 && A[x + 1][y - 1] == BROD) continue;
        if (x - 1 >= 1 && y - 1 >= 1 && A[x - 1][y - 1] == BROD) continue;
        if (x - 1 >= 1 && y + 1 < 11 && A[x - 1][y + 1] == BROD) continue;
        //printf("brod=%d, x=%d, y=%d, dir=%d\n",d,x,y,dir);
        moze = 1;
        if (dir == 0)
            for (i = 0; i < d; i++) {
                if (x + i >= 11) { moze = 0; break; }
                if (y - 1 >= 1 && A[x + i][y - 1] == BROD) { moze = 0; break; }
                if (y + 1 < 11 && A[x + i][y + 1] == BROD) { moze = 0; break; }
                if (x + i + 1 < 11 && A[x + i + 1][y] == BROD) { moze = 0; break; }
                if (x + i + 1 < 11 && y - 1 >= 1 && A[x + i + 1][y - 1] == BROD) { moze = 0; break; }
                if (x + i + 1 < 11 && y + 1 < 11 && A[x + i + 1][y + 1] == BROD) { moze = 0; break; }
            }
        if (dir == 1)
            for (i = 0; i < d; i++) {
                if (y + i >= 11) { moze = 0; break; }
                if (x - 1 >= 1 && A[x - 1][y + i] == BROD) { moze = 0; break; }
                if (x + 1 < 11 && A[x + 1][y + i] == BROD) { moze = 0; break; }
                if (y + i + 1 < 11 && A[x][y + i + 1] == BROD) { moze = 0; break; }
                if (y + i + 1 < 11 && x - 1 >= 1 && A[x - 1][y + i + 1] == BROD) { moze = 0; break; }
                if (y + i + 1 < 11 && x + 1 < 11 && A[x + 1][y + i + 1] == BROD) { moze = 0; break; }
            }
        if (moze == 0) continue;
        if (dir == 0)
            for (i = 0; i < d; i++) A[x + i][y] = BROD;
        if (dir == 1)
            for (i = 0; i < d; i++) A[x][y + i] = BROD;
        break;
    }

}


int provjera() {
    int i, j, br=0;
    for (i = 1; i < 11; i++)
        for (j = 1; j < 11; j++) {
            if (A[i][j] == '#') return 0;
        }
    if (br == 0) return 1;
}

int main()
{
    int i, j, sl = 'A', br = '1', x, brojac = 0;
    float brpog = 0, pos;
    char Y, bin;
    srand(time(NULL));
    A[0][0] = ' ';
    A[0][10] = '1';
    A[0][11] = '0';
    for (i = 1; i < 11; i++) {
        A[i][0] = sl;
        sl++;
    }
    for (j = 1; j < 10; j++) {
        A[0][j] = br;
        br++;
    }
    sl = 'A', br = '1';
    for (i = 1; i < 11; i++)
        for (j = 1; j < 11; j++) A[i][j] = MORE;
    B[0][0] = ' ';
    B[0][10] = '1';
    B[0][11] = '0';
    for (i = 1; i < 11; i++) {
        B[i][0] = sl;
        sl++;
    }
    for (j = 1; j < 10; j++) {
        B[0][j] = br;
        br++;
    }
    for (i = 1; i < 11; i++)
        for (j = 1; j < 11; j++) B[i][j] = MORE;
    dodaj(5);  // 1 X NOSAÈ AVION
    dodaj(4);  // 2 X KRSTARICE
    dodaj(4);
    dodaj(3);  // 3 X RAZARAÈ
    dodaj(3);
    dodaj(3);
    dodaj(2);  // 4 X PODMORNICE
    dodaj(2);
    dodaj(2);
    dodaj(2);
    printf("\nPOTAPANJE BRODOVA\n\n");
    //ispisA();
    ispisB();
    printf("\nUpute za igranje:\n\nOdaberite jedno polje, prvo odaberite vrijednost Y-a od A do J, pa vrijednost X-a od 1 do 10.\nUkoliko se na odabranom polju pojavi 'x' pogodili ste brod, ali ako se pojavi '.' pogodili ste samo vodu.\nKada kada zelite zapoceti igru stisnite enter.\n");
    do {
        int pv = 65, y = 1;
        do {
            scanf("%c", &bin);
            printf("Y=");
            scanf("%c", &Y);
        } while (Y < 'A' || Y > 'J');
        do {
            scanf("%c", &bin);
            printf("X=");
            scanf("%d", &x);
        } while ((x < 1) || (x > 10));
        printf("Odabrali ste polje: %c%d \n", Y, x);
        if (pv == Y) y = 1;
        else {
            do {
                pv++;
                y++;
            } while (pv != Y);
        }
        if (A[y][x] == '#') {
            A[y][x] = 'x';
            B[y][x] = 'x';
            printf("\nPOGODAK!\n");
            brpog++;
        }
        if (A[y][x] == '~') {
            A[y][x] = '.';
            B[y][x] = '.';
            printf("\nPromasaj.\n");
        }
        ispisB();
        printf("\n");
        brojac++;
    } while (provjera() == 0);
    pos = (brpog/brojac)*100;
    printf("\nPOBJEDA!\n\nBroj pokusaja: %d\nPostotak pogodaka: %.2f\n", brojac,pos );
    return 0;
}

