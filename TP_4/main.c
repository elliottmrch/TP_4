#include <stdio.h>

void InitGrille(int grille[9][9], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grille[i][j] = 0;
		}
	}
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("%d ", grille[x][y]);
		}
		printf("\n");
	}
}

void ModifGrille(int grille[9][9], int n) {
	char continuer;
	int stop = 0;
	int ligne = 0;
	int colonne = 0;
	int nbr = 0;

	while (stop == 0) {
		printf("Voulez vous modifier la grille ? (O = Oui / N = Non) : ");
		scanf_s("%c", &continuer);
		getchar();
		if (continuer == 'O') {
			stop = 0;
		}
		else {
			stop = 1;
			break;
		}

		printf("Numero de la LIGNE a modifier : ");
		scanf_s("%d", &ligne);
		getchar();
		while (ligne < 0 || ligne >= n) {
			if (ligne < 0 || ligne>= n) {
				printf("Numero hors de la grille !\nNumero de la LIGNE a modifier : ");
				scanf_s("%d", &ligne);
				getchar();
			}
		}
		

		printf("Numero de la COLONNE a modifier : ");
		scanf_s("%d", &colonne);
		getchar();
		while (colonne < 0 || colonne >= n) {
			if (colonne < 0 || colonne >= n) {
				printf("Numero hors de la grille !\nNumero de la COLONNE a modifier : ");
				scanf_s("%d", &colonne);
				getchar();
			}
		}
		

		printf("Numero a modifier : ");
		scanf_s("%d", &nbr);
		getchar();
		while (nbr < 0 || nbr > 9) {
			if (nbr < 0 || nbr > 9) {
				printf("Numero non valide !\nNumero a modifier : ");
				scanf_s("%d", &nbr);
				getchar();
			}
		}
		

		grille[ligne][colonne] = nbr;

		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				printf("%d ", grille[x][y]);
			}
			printf("\n");
		}
	}
	
}

int main()
{
	int grille_facile[9][9] = {
		{6, 0, 4, 9, 0, 0, 3, 0, 8},
		{3, 2, 0, 8, 0, 0, 4, 0, 0},
		{0, 0, 0, 6, 0, 4, 5, 2, 1},
		{1, 0, 2, 7, 4, 3, 8, 9, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{9, 4, 7, 5, 8, 0, 0, 0, 0},
		{4, 9, 0, 2, 0, 8, 6, 0, 3},
		{0, 3, 6, 4, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 6, 9, 0, 0, 4}
	};

	int grille_moyenne[9][9] = {
		{1, 0, 0, 7, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 0, 8, 5, 6, 0},
		{6, 0, 8, 0, 5, 3, 4, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 0, 0, 0},
		{8, 4, 0, 3, 0, 1, 0, 5, 9}
	};

	InitGrille(grille_moyenne, 8);
	ModifGrille(grille_moyenne, 8);

	return 0;
}