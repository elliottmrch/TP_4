// NOTE : 10/20

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

void Afficher(int grille[9][9], int n) {
	for (int x = 0; x < n; x++)
	{
		printf("|");
		for (int y = 0; y < n; y++)
		{
			if (grille[x][y] == 0) {
				printf(" |");
			}
			else {
				printf("%d|", grille[x][y]);
			}
		}
		printf("\n");
		printf(" ");
		for (int f = 0; f < n; f++) {
			printf("- ");
		}
		printf("\n");
	}
}

void Verification(int grille[9][9], int n) { 
	int verifier = 0;
	int present = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (grille[x][y] < 1 || grille[x][y] > n) {
				verifier = 1;
			}
			if (grille[x][y] == x + 1) { // il ne faut pas comparer une valeur dans la grille avec un indice, ils n'ont pas de rapport
				present = 1; // tu n'en fais rien
			}
			if (grille[x][y] == (x + 1) && present == 1) {
				verifier = 1;
			}
		}
		
	}
	if (verifier == 1) {
		printf("La grille a un probleme, reverifiez la !");
	}
	else {
		printf("La grille est bonne !");
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

	InitGrille(grille_moyenne, 4);
	ModifGrille(grille_moyenne, 4);
	Afficher(grille_moyenne, 4);

	return 0;
}