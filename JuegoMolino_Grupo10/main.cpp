#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

int filas = 50, columnas = 44;
struct Jugador {
	char nombre[9];
	int color = 0;
	int fichas = 0;
	int movimientos = 0;
};

void Iniciar_Arreglos_Menu(int**& pMenu) {
	/* Inicializamos el arreglo llen�ndolo de ceros */
	pMenu = new int* [filas];

	for (int i = 0; i < filas; i++) {
		pMenu[i] = new int[columnas];
	}

	for (int i = 0;i < filas;i++) {
		for (int j = 0;j < columnas;j++) {
			pMenu[i][j] = 0;
		}
	}

	/* Bordes */
	for (int i = 1; i < filas - 1; i++) {
		for (int j = 1; j < columnas - 1; j++) {
			if (i == 1 || i == 48 || j == 1 || j == 42)
				pMenu[i][j] = 1;
		}
	}

	/* 0: Menu */
	/* 0.1: Molino (Base) */
	pMenu[10][10] = 2; pMenu[10][11] = 2;
	pMenu[10][12] = 2; pMenu[11][11] = 2;
	pMenu[17][8] = 2; pMenu[17][9] = 2;
	pMenu[17][10] = 2; pMenu[17][12] = 2;
	pMenu[18][7] = 2; pMenu[18][8] = 2;
	pMenu[18][9] = 2; pMenu[18][10] = 2;
	pMenu[18][11] = 2; pMenu[18][12] = 2;
	pMenu[18][13] = 2; pMenu[18][14] = 2;
	pMenu[19][7] = 2; pMenu[19][8] = 2;
	pMenu[19][9] = 2; pMenu[19][13] = 2;
	pMenu[19][14] = 2;	pMenu[20][7] = 2;
	pMenu[20][8] = 2;	pMenu[20][9] = 2;
	pMenu[20][13] = 2;	pMenu[20][14] = 2;
	pMenu[21][7] = 2;	pMenu[21][8] = 2;
	pMenu[21][9] = 2; 	pMenu[21][13] = 2;
	pMenu[21][14] = 2;

	/* 0.2: Molino (Elices) */
	pMenu[9][8] = 3; pMenu[10][8] = 3;
	pMenu[10][9] = 3; pMenu[11][9] = 3;
	pMenu[11][10] = 3; pMenu[12][10] = 3;
	pMenu[12][11] = 3; pMenu[12][12] = 3;
	pMenu[11][12] = 3; pMenu[11][12] = 3;
	pMenu[11][13] = 3; pMenu[10][13] = 3;
	pMenu[13][10] = 3; pMenu[13][11] = 3;
	pMenu[13][9] = 3;  pMenu[14][8] = 3;
	pMenu[14][9] = 3;  pMenu[14][11] = 3;
	pMenu[14][12] = 3; pMenu[15][7] = 3;
	pMenu[15][8] = 3; pMenu[15][12] = 3;
	pMenu[15][13] = 3; pMenu[16][13] = 3;
	pMenu[10][14] = 3;

	/* 0.3: Molino (Sombras) */
	pMenu[11][8] = 4; pMenu[12][8] = 4;
	pMenu[12][9] = 4; pMenu[12][13] = 4;
	pMenu[13][8] = 4; pMenu[13][12] = 4;
	pMenu[13][13] = 4; pMenu[14][10] = 4;
	pMenu[14][13] = 4; pMenu[15][9] = 4;
	pMenu[15][10] = 4; pMenu[16][8] = 4;
	pMenu[16][9] = 4; pMenu[17][13] = 4;

	/* 0.4: Molino (Puerta y Ventana) */
	pMenu[15][11] = 5; pMenu[16][10] = 5;
	pMenu[16][11] = 5; pMenu[16][12] = 5;
	pMenu[17][11] = 5; pMenu[19][10] = 5;
	pMenu[19][11] = 5; pMenu[19][12] = 5;
	pMenu[20][10] = 5; pMenu[20][11] = 5;
	pMenu[20][12] = 5; pMenu[21][10] = 5;
	pMenu[21][11] = 5; pMenu[21][12] = 5;

	/* 0.5: Techo*/
	pMenu[6][10] = 6; pMenu[6][11] = 6;
	pMenu[7][9] = 6; pMenu[7][10] = 6;
	pMenu[7][11] = 6; pMenu[7][12] = 6;
	pMenu[8][8] = 6; pMenu[8][9] = 6;
	pMenu[8][10] = 6; pMenu[8][11] = 6;
	pMenu[8][12] = 6; pMenu[8][13] = 6;
	pMenu[9][7] = 6; pMenu[9][9] = 6;
	pMenu[9][10] = 6; pMenu[9][11] = 6;
	pMenu[9][12] = 6; pMenu[9][13] = 6;
	pMenu[9][14] = 6;

	/* 0.6: Nubes*/
	pMenu[8][20] = 7; pMenu[8][21] = 7;
	pMenu[8][30] = 7; pMenu[8][31] = 7;
	pMenu[8][32] = 7; pMenu[9][19] = 7;
	pMenu[9][20] = 7; pMenu[9][21] = 7;
	pMenu[9][26] = 7; pMenu[9][27] = 7;
	pMenu[9][28] = 7; pMenu[9][30] = 7;
	pMenu[9][31] = 7; pMenu[9][32] = 7;
	pMenu[9][33] = 7; pMenu[9][36] = 7;
	pMenu[9][37] = 7; pMenu[10][18] = 7;
	pMenu[10][19] = 7; pMenu[10][20] = 7;
	pMenu[10][21] = 7; pMenu[10][22] = 7;
	pMenu[10][25] = 7; pMenu[10][26] = 7;
	pMenu[10][27] = 7; pMenu[10][28] = 7;
	pMenu[10][32] = 7; pMenu[10][33] = 7;
	pMenu[10][36] = 7; pMenu[10][37] = 7;
	pMenu[10][38] = 7; pMenu[11][24] = 7;
	pMenu[11][25] = 7; pMenu[11][26] = 7;
	pMenu[11][27] = 7; pMenu[11][35] = 7;
	pMenu[11][36] = 7; pMenu[11][37] = 7;
	pMenu[11][38] = 7; pMenu[11][39] = 7;

	/* 0.7: Texto*/
	pMenu[13][18] = 3; pMenu[13][20] = 3;
	pMenu[13][26] = 3; pMenu[14][18] = 3;
	pMenu[14][19] = 3; pMenu[14][20] = 3;
	pMenu[14][26] = 3; pMenu[14][28] = 3;
	pMenu[15][18] = 3; pMenu[15][20] = 3;
	pMenu[15][26] = 3; pMenu[16][18] = 3;
	pMenu[16][20] = 3; pMenu[16][23] = 3;
	pMenu[16][26] = 3; pMenu[16][28] = 3;
	pMenu[16][30] = 3; pMenu[16][31] = 3;
	pMenu[16][32] = 3; pMenu[16][35] = 3;
	pMenu[17][18] = 3; pMenu[17][20] = 3;
	pMenu[17][22] = 3; pMenu[17][24] = 3;
	pMenu[17][26] = 3; pMenu[17][28] = 3;
	pMenu[17][30] = 3; pMenu[17][32] = 3;
	pMenu[17][34] = 3; pMenu[17][36] = 3;
	pMenu[18][18] = 3; pMenu[18][20] = 3;
	pMenu[18][23] = 3; pMenu[18][26] = 3;
	pMenu[18][28] = 3; pMenu[18][30] = 3;
	pMenu[18][32] = 3; pMenu[18][35] = 3;

	/* 0.8: Pasto */
	pMenu[20][18] = 8; pMenu[20][19] = 8;
	pMenu[20][20] = 8; pMenu[20][21] = 8;
	pMenu[20][22] = 8; pMenu[20][23] = 8;
	pMenu[20][24] = 8; pMenu[20][25] = 8;
	pMenu[20][26] = 8; pMenu[20][27] = 8;
	pMenu[20][28] = 8; pMenu[20][29] = 8;
	pMenu[20][30] = 8; pMenu[20][31] = 8;
	pMenu[20][32] = 8; pMenu[20][33] = 8;
	pMenu[20][34] = 8; pMenu[20][35] = 8;
	pMenu[20][36] = 8;

	/* 0.9: Logo UPC*/
	pMenu[36][17] = 4; pMenu[36][19] = 4;
	pMenu[36][21] = 4; pMenu[36][22] = 4;
	pMenu[36][26] = 4; pMenu[36][27] = 4;
	pMenu[37][17] = 4; pMenu[37][19] = 4;
	pMenu[37][21] = 4; pMenu[37][23] = 4;
	pMenu[37][25] = 4; pMenu[38][17] = 4;
	pMenu[38][19] = 4; pMenu[38][21] = 4;
	pMenu[38][22] = 4; pMenu[38][25] = 4;
	pMenu[39][17] = 4; pMenu[39][19] = 4;
	pMenu[39][21] = 4; pMenu[39][25] = 4;
	pMenu[40][18] = 4; pMenu[40][21] = 4;
	pMenu[40][26] = 4; pMenu[40][27] = 4;
}

void Iniciar_Arreglos_Configuracion(int**& pConfiguracion, int jugador) {
	/* Inicializamos el arreglo llen�ndolo de ceros */
	pConfiguracion = new int*[filas];

	for (int i = 0; i < filas; i++) {
		pConfiguracion[i] = new int[columnas];
	}

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			pConfiguracion[i][j] = 0;
		}
	}
	/* Letra J */
	pConfiguracion[9][18] = 1; pConfiguracion[9][19] = 1;
	pConfiguracion[10][18] = 1; pConfiguracion[10][19] = 1;
	pConfiguracion[11][18] = 1; pConfiguracion[11][19] = 1;
	pConfiguracion[12][18] = 1; pConfiguracion[12][19] = 1;
	pConfiguracion[13][18] = 1; pConfiguracion[13][19] = 1;
	pConfiguracion[14][18] = 1; pConfiguracion[14][19] = 1;
	pConfiguracion[15][18] = 1; pConfiguracion[15][19] = 1;
	pConfiguracion[16][18] = 1; pConfiguracion[16][19] = 1;
	pConfiguracion[17][18] = 1; pConfiguracion[17][19] = 1;
	pConfiguracion[18][18] = 1; pConfiguracion[18][19] = 1;
	pConfiguracion[19][18] = 1; pConfiguracion[19][19] = 1;
	pConfiguracion[20][14] = 1; pConfiguracion[20][15] = 1;
	pConfiguracion[20][18] = 1; pConfiguracion[20][19] = 1;
	pConfiguracion[21][14] = 1; pConfiguracion[21][15] = 1;
	pConfiguracion[21][16] = 1; pConfiguracion[21][17] = 1;
	pConfiguracion[21][18] = 1; pConfiguracion[22][16] = 1;
	pConfiguracion[22][17] = 1;

	if (jugador == 0) {
		/* N�mero 1 */
		pConfiguracion[9][25] = 1; pConfiguracion[9][26] = 1;
		pConfiguracion[10][25] = 1; pConfiguracion[10][26] = 1;
		pConfiguracion[11][25] = 1; pConfiguracion[11][26] = 1;
		pConfiguracion[12][25] = 1; pConfiguracion[12][26] = 1;
		pConfiguracion[13][25] = 1; pConfiguracion[13][26] = 1;
		pConfiguracion[14][25] = 1; pConfiguracion[14][26] = 1;
		pConfiguracion[15][25] = 1; pConfiguracion[15][26] = 1;
		pConfiguracion[16][25] = 1; pConfiguracion[16][26] = 1;
		pConfiguracion[17][25] = 1; pConfiguracion[17][26] = 1;
		pConfiguracion[18][25] = 1; pConfiguracion[18][26] = 1;
		pConfiguracion[19][25] = 1; pConfiguracion[19][26] = 1;
		pConfiguracion[20][25] = 1; pConfiguracion[20][26] = 1;
		pConfiguracion[21][25] = 1; pConfiguracion[21][26] = 1;
		pConfiguracion[22][25] = 1; pConfiguracion[22][26] = 1;

		pConfiguracion[10][24] = 1;
		pConfiguracion[11][24] = 1;
		pConfiguracion[11][23] = 1;
		pConfiguracion[12][22] = 1;
		pConfiguracion[12][23] = 1;
	}
	else {
		/* N�mero 2 */
		pConfiguracion[9][23] = 1; pConfiguracion[9][24] = 1;
		pConfiguracion[9][25] = 1; pConfiguracion[9][26] = 1;
		pConfiguracion[10][22] = 1; pConfiguracion[10][23] = 1;
		pConfiguracion[10][24] = 1; pConfiguracion[10][25] = 1; pConfiguracion[10][26] = 1;
		pConfiguracion[11][22] = 1; pConfiguracion[11][23] = 1;
		pConfiguracion[11][25] = 1; pConfiguracion[11][26] = 1;
		pConfiguracion[12][25] = 1; pConfiguracion[12][26] = 1;
		pConfiguracion[13][25] = 1; pConfiguracion[13][26] = 1;
		pConfiguracion[14][25] = 1; pConfiguracion[14][26] = 1;
		pConfiguracion[15][25] = 1; pConfiguracion[15][26] = 1;
		pConfiguracion[16][24] = 1; pConfiguracion[16][25] = 1;
		pConfiguracion[17][23] = 1; pConfiguracion[17][24] = 1;
		pConfiguracion[18][22] = 1; pConfiguracion[18][23] = 1;
		pConfiguracion[19][22] = 1; pConfiguracion[19][23] = 1;
		pConfiguracion[20][22] = 1; pConfiguracion[20][23] = 1;
		pConfiguracion[21][22] = 1; pConfiguracion[21][23] = 1;
		pConfiguracion[21][24] = 1; pConfiguracion[21][25] = 1; pConfiguracion[21][26] = 1;
		pConfiguracion[22][22] = 1; pConfiguracion[22][23] = 1;
		pConfiguracion[22][24] = 1; pConfiguracion[22][25] = 1; pConfiguracion[22][26] = 1;
	}
}

void Iniciar_Arreglos_Creditos(int**& pCreditos) {
	pCreditos = new int* [filas];
	for (int i = 0; i < filas; i++) {
		pCreditos[i] = new int[columnas];
	}

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			pCreditos[i][j] = 0;
		}
	}

	/* 1: Bordes */
	for (int i = 1; i < filas - 1; i++) {
		for (int j = 1; j < columnas - 1; j++) {
			if (i == 1 || i == 48 || j == 1 || j == 42)
				pCreditos[i][j] = 1;
		}
	}

	/* 2: Nubes*/
	pCreditos[2][4] = 2;	pCreditos[2][5] = 2;
	pCreditos[2][14] = 2;	pCreditos[2][15] = 2;
	pCreditos[2][16] = 2;	pCreditos[2][27] = 2;
	pCreditos[2][28] = 2;	pCreditos[2][37] = 2;
	pCreditos[2][38] = 2;	pCreditos[2][39] = 2;
	pCreditos[3][3] = 2;	pCreditos[3][4] = 2;
	pCreditos[3][5] = 2;	pCreditos[3][10] = 2;
	pCreditos[3][11] = 2;	pCreditos[3][12] = 2;
	pCreditos[3][14] = 2;	pCreditos[3][15] = 2;
	pCreditos[3][16] = 2;	pCreditos[3][17] = 2;
	pCreditos[3][20] = 2;	pCreditos[3][21] = 2;
	pCreditos[3][26] = 2;	pCreditos[3][27] = 2;
	pCreditos[3][28] = 2;	pCreditos[3][33] = 2;
	pCreditos[3][34] = 2;	pCreditos[3][35] = 2;
	pCreditos[3][37] = 2;	pCreditos[3][38] = 2;
	pCreditos[3][39] = 2;	pCreditos[3][40] = 2;
	pCreditos[4][3] = 2;	pCreditos[4][4] = 2;
	pCreditos[4][5] = 2;	pCreditos[4][6] = 2;
	pCreditos[4][9] = 2;	pCreditos[4][10] = 2;
	pCreditos[4][11] = 2;	pCreditos[4][12] = 2;
	pCreditos[4][16] = 2;	pCreditos[4][17] = 2;
	pCreditos[4][20] = 2;	pCreditos[4][21] = 2;
	pCreditos[4][22] = 2;	pCreditos[4][25] = 2;
	pCreditos[4][26] = 2;	pCreditos[4][27] = 2;
	pCreditos[4][28] = 2;	pCreditos[4][29] = 2;
	pCreditos[4][32] = 2;	pCreditos[4][33] = 2;
	pCreditos[4][34] = 2;	pCreditos[4][35] = 2;
	pCreditos[4][39] = 2;	pCreditos[4][40] = 2;
	pCreditos[5][8] = 2;	pCreditos[5][9] = 2;
	pCreditos[5][10] = 2;	pCreditos[5][11] = 2;
	pCreditos[5][19] = 2;	pCreditos[5][20] = 2;
	pCreditos[5][21] = 2;	pCreditos[5][22] = 2;
	pCreditos[5][23] = 2;	pCreditos[5][31] = 2;
	pCreditos[5][32] = 2;	pCreditos[5][33] = 2;
	pCreditos[5][34] = 2;

	/*2.1: "Creditos" */
	pCreditos[8][8] = 3; pCreditos[8][9] = 3;
	pCreditos[8][11] = 3; pCreditos[8][12] = 3;
	pCreditos[8][15] = 3; pCreditos[8][16] = 3;
	pCreditos[8][18] = 3; pCreditos[8][19] = 3;
	pCreditos[8][22] = 3; pCreditos[8][24] = 3;
	pCreditos[8][25] = 3; pCreditos[8][26] = 3;
	pCreditos[8][29] = 3; pCreditos[8][32] = 3;
	pCreditos[8][33] = 3; pCreditos[8][34] = 3;
	pCreditos[9][7] = 3; pCreditos[9][11] = 3;
	pCreditos[9][13] = 3; pCreditos[9][15] = 3;
	pCreditos[9][18] = 3; pCreditos[9][20] = 3;
	pCreditos[9][22] = 3; pCreditos[9][25] = 3;
	pCreditos[9][28] = 3; pCreditos[9][30] = 3;
	pCreditos[9][32] = 3; pCreditos[9][36] = 3;
	pCreditos[10][7] = 3; pCreditos[10][11] = 3;
	pCreditos[10][12] = 3; pCreditos[10][15] = 3;
	pCreditos[10][16] = 3; pCreditos[10][11] = 3;
	pCreditos[10][18] = 3; pCreditos[10][20] = 3;
	pCreditos[10][22] = 3; pCreditos[10][25] = 3;
	pCreditos[10][28] = 3; pCreditos[10][30] = 3;
	pCreditos[10][32] = 3; pCreditos[10][33] = 3;
	pCreditos[10][34] = 3; pCreditos[11][7] = 3;
	pCreditos[11][11] = 3; pCreditos[11][13] = 3;
	pCreditos[11][15] = 3; pCreditos[11][18] = 3;
	pCreditos[11][20] = 3; pCreditos[11][22] = 3;
	pCreditos[11][25] = 3; pCreditos[11][28] = 3;
	pCreditos[11][30] = 3; pCreditos[11][34] = 3;
	pCreditos[11][36] = 3; pCreditos[12][8] = 3;
	pCreditos[12][9] = 3; pCreditos[12][11] = 3;
	pCreditos[12][13] = 3; pCreditos[12][15] = 3;
	pCreditos[12][16] = 3; pCreditos[12][18] = 3;
	pCreditos[12][19] = 3; pCreditos[12][22] = 3;
	pCreditos[12][25] = 3; pCreditos[12][29] = 3;
	pCreditos[12][32] = 3; pCreditos[12][33] = 3;
	pCreditos[12][34] = 3;

	/*2.2: Logo UPC */
	pCreditos[38][17] = 4; pCreditos[38][19] = 4;
	pCreditos[38][21] = 4; pCreditos[38][22] = 4;
	pCreditos[38][26] = 4; pCreditos[38][27] = 4;
	pCreditos[39][17] = 4; pCreditos[39][19] = 4;
	pCreditos[39][21] = 4; pCreditos[39][23] = 4;
	pCreditos[39][25] = 4; pCreditos[40][17] = 4;
	pCreditos[40][19] = 4; pCreditos[40][21] = 4;
	pCreditos[40][22] = 4; pCreditos[40][25] = 4;
	pCreditos[41][17] = 4; pCreditos[41][19] = 4;
	pCreditos[41][21] = 4; pCreditos[41][25] = 4;
	pCreditos[42][18] = 4; pCreditos[42][21] = 4;
	pCreditos[42][26] = 4; pCreditos[42][27] = 4;
}

void Iniciar_Arreglos_Tablero(int**& pTablero, int**& pFicha) {
	/* Inicializamos el arreglo llen�ndolo de ceros */
	pTablero = new int* [filas];

	for (int i = 0; i < filas; i++) {
		pTablero[i] = new int[columnas];
	}

	for (int i = 0;i < filas;i++) {
		for (int j = 0;j < columnas;j++) {
			pTablero[i][j] = 0;
		}
	}

	/* 1: Bordes */
	for (int i = 1; i < 43; i++) {
		for (int j = 1;j < columnas - 1; j++) {
			if (i == 1 || i == 42 || j == 1 || j == 42)
				pTablero[i][j] = 1;
		}
	}

	/* 2: Casillas */
	pTablero[3][3] = 2; pTablero[3][4] = 2;
	pTablero[4][3] = 2; pTablero[4][4] = 2;

	pTablero[3][21] = 2; pTablero[3][22] = 2;
	pTablero[4][21] = 2; pTablero[4][22] = 2;

	pTablero[3][39] = 2; pTablero[3][40] = 2;
	pTablero[4][39] = 2; pTablero[4][40] = 2;

	pTablero[9][9] = 2; pTablero[9][10] = 2;
	pTablero[10][9] = 2; pTablero[10][10] = 2;

	pTablero[9][21] = 2; pTablero[9][22] = 2;
	pTablero[10][21] = 2; pTablero[10][22] = 2;

	pTablero[9][33] = 2; pTablero[9][34] = 2;
	pTablero[10][33] = 2; pTablero[10][34] = 2;

	pTablero[15][15] = 2; pTablero[15][16] = 2;
	pTablero[16][15] = 2; pTablero[16][16] = 2;

	pTablero[15][21] = 2; pTablero[15][22] = 2;
	pTablero[16][21] = 2; pTablero[16][22] = 2;

	pTablero[15][27] = 2; pTablero[15][28] = 2;
	pTablero[16][27] = 2; pTablero[16][28] = 2;

	pTablero[21][3] = 2; pTablero[21][4] = 2;
	pTablero[22][3] = 2; pTablero[22][4] = 2;

	pTablero[21][9] = 2; pTablero[21][10] = 2;
	pTablero[22][9] = 2; pTablero[22][10] = 2;

	pTablero[21][15] = 2; pTablero[21][16] = 2;
	pTablero[22][15] = 2; pTablero[22][16] = 2;

	pTablero[21][27] = 2; pTablero[21][28] = 2;
	pTablero[22][27] = 2; pTablero[22][28] = 2;

	pTablero[21][33] = 2; pTablero[21][34] = 2;
	pTablero[22][33] = 2; pTablero[22][34] = 2;

	pTablero[21][39] = 2; pTablero[21][40] = 2;
	pTablero[22][39] = 2; pTablero[22][40] = 2;

	pTablero[27][15] = 2; pTablero[27][16] = 2;
	pTablero[28][15] = 2; pTablero[28][16] = 2;

	pTablero[27][21] = 2; pTablero[27][22] = 2;
	pTablero[28][21] = 2; pTablero[28][22] = 2;

	pTablero[27][27] = 2; pTablero[27][28] = 2;
	pTablero[28][27] = 2; pTablero[28][28] = 2;

	pTablero[33][9] = 2; pTablero[33][10] = 2;
	pTablero[34][9] = 2; pTablero[34][10] = 2;

	pTablero[33][21] = 2; pTablero[33][22] = 2;
	pTablero[34][21] = 2; pTablero[34][22] = 2;

	pTablero[33][33] = 2; pTablero[33][34] = 2;
	pTablero[34][33] = 2; pTablero[34][34] = 2;

	pTablero[39][3] = 2; pTablero[39][4] = 2;
	pTablero[40][3] = 2; pTablero[40][4] = 2;

	pTablero[39][21] = 2; pTablero[39][22] = 2;
	pTablero[40][21] = 2; pTablero[40][22] = 2;

	pTablero[39][39] = 2; pTablero[39][40] = 2;
	pTablero[40][39] = 2; pTablero[40][40] = 2;

	/* 3: ficha */
	pFicha = new int* [2];
	pFicha[0] = new int[2];
	pFicha[1] = new int[2];

	pFicha[0][0] = 3;
	pFicha[0][1] = 3;
	pFicha[1][0] = 3;
	pFicha[1][1] = 3;
}

void Iniciar_Arreglos_Ganador(int**& pGanador) {
	pGanador = new int* [filas];
	for (int i = 0; i < filas; i++) {
		pGanador[i] = new int[columnas];
	}

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			pGanador[i][j] = 0;
		}
	}

	/* 1: Bordes */
	for (int i = 1; i < filas - 1; i++) {
		for (int j = 1; j < columnas - 1; j++) {
			if (i == 1 || i == 46 || j == 1 || j == 42) {
				pGanador[i][j] = 1;
			}
		}
	}

	/* 2: Texto*/
	pGanador[2][11] = 2;	pGanador[2][15] = 2;
	pGanador[2][18] = 2;	pGanador[2][20] = 2;
	pGanador[2][23] = 2;	pGanador[2][26] = 2;
	pGanador[2][27] = 2;	pGanador[2][31] = 2;
	pGanador[2][34] = 2;	pGanador[2][35] = 2;
	pGanador[3][10] = 2;	pGanador[3][14] = 2;
	pGanador[3][16] = 2;	pGanador[3][18] = 2;
	pGanador[3][19] = 2;	pGanador[3][20] = 2;
	pGanador[3][22] = 2;	pGanador[3][24] = 2;
	pGanador[3][26] = 2;	pGanador[3][28] = 2;
	pGanador[3][30] = 2;	pGanador[3][32] = 2;
	pGanador[3][34] = 2;	pGanador[3][36] = 2;
	pGanador[4][10] = 2;	pGanador[4][12] = 2;
	pGanador[4][14] = 2;	pGanador[4][16] = 2;
	pGanador[4][18] = 2;	pGanador[4][20] = 2;
	pGanador[4][22] = 2;	pGanador[4][24] = 2;
	pGanador[4][26] = 2;	pGanador[4][28] = 2;
	pGanador[4][30] = 2;	pGanador[4][32] = 2;
	pGanador[4][34] = 2;	pGanador[4][35] = 2;
	pGanador[5][10] = 2;	pGanador[5][12] = 2;
	pGanador[5][14] = 2;	pGanador[5][15] = 2;
	pGanador[5][16] = 2;	pGanador[5][18] = 2;
	pGanador[5][20] = 2;	pGanador[5][22] = 2;
	pGanador[5][23] = 2;	pGanador[5][24] = 2;
	pGanador[5][26] = 2;	pGanador[5][28] = 2;
	pGanador[5][30] = 2;	pGanador[5][32] = 2;
	pGanador[5][34] = 2;	pGanador[5][36] = 2;
	pGanador[6][11] = 2;	pGanador[6][12] = 2;
	pGanador[6][14] = 2;	pGanador[6][16] = 2;
	pGanador[6][18] = 2;	pGanador[6][20] = 2;
	pGanador[6][22] = 2;	pGanador[6][24] = 2;
	pGanador[6][26] = 2;	pGanador[6][27] = 2;
	pGanador[6][31] = 2;	pGanador[6][34] = 2;
	pGanador[6][36] = 2;

	/*2.1: Trofeo*/
	pGanador[13][17] = 3;	pGanador[13][18] = 3;
	pGanador[13][19] = 3;	pGanador[13][20] = 3;
	pGanador[13][21] = 3;	pGanador[13][22] = 3;
	pGanador[13][23] = 3;	pGanador[13][24] = 3;
	pGanador[13][25] = 3;	pGanador[13][26] = 3;
	pGanador[13][27] = 3;	pGanador[13][28] = 3;
	pGanador[15][9] = 3; pGanador[15][10] = 3;
	pGanador[15][11] = 3;	pGanador[15][12] = 3;
	pGanador[15][14] = 3;	pGanador[15][32] = 3;
	pGanador[15][33] = 3;	pGanador[15][34] = 3;
	pGanador[15][35] = 3;	pGanador[15][36] = 3;
	pGanador[16][9] = 3;	pGanador[16][9] = 3;
	pGanador[16][9] = 3;	pGanador[16][14] = 3;
	pGanador[16][15] = 3; pGanador[16][36] = 3;
	pGanador[17][10] = 3; pGanador[17][14] = 3;
	pGanador[17][15] = 3; pGanador[17][35] = 3;
	pGanador[18][11] = 3; pGanador[18][15] = 3;
	pGanador[18][16] = 3; pGanador[18][34] = 3;
	pGanador[19][12] = 3; pGanador[19][15] = 3;
	pGanador[19][16] = 3; pGanador[19][33] = 3;
	pGanador[20][13] = 3; pGanador[20][14] = 3;
	pGanador[20][15] = 3; pGanador[20][16] = 3;
	pGanador[20][31] = 3; pGanador[20][32] = 3;
	pGanador[21][16] = 3; pGanador[21][17] = 3;
	pGanador[22][16] = 3; pGanador[22][17] = 3;
	pGanador[23][17] = 3; pGanador[23][18] = 3;
	pGanador[24][17] = 3; pGanador[24][18] = 3;
	pGanador[25][18] = 3; pGanador[25][19] = 3;
	pGanador[26][19] = 3; pGanador[26][20] = 3;
	pGanador[27][20] = 3; pGanador[27][21] = 3;
	pGanador[27][22] = 3; pGanador[27][23] = 3;
	pGanador[28][22] = 3; pGanador[29][22] = 3;
	pGanador[30][22] = 3; pGanador[31][22] = 3;
	pGanador[32][22] = 3; pGanador[33][21] = 3;
	pGanador[33][22] = 3;  pGanador[33][23] = 3;
	pGanador[34][19] = 3;  pGanador[34][20] = 3;
	pGanador[34][21] = 3;  pGanador[34][22] = 3;
	pGanador[34][23] = 3;  pGanador[34][24] = 3;
	pGanador[35][18] = 3;  pGanador[35][19] = 3;
	pGanador[35][20] = 3;  pGanador[35][21] = 3;
	pGanador[35][22] = 3;  pGanador[35][23] = 3;
	pGanador[35][24] = 3;  pGanador[35][25] = 3;

	/*2.2: Sombra*/
	pGanador[13][29] = 4;  pGanador[13][30] = 4;
	pGanador[13][31] = 4;  pGanador[13][32] = 4;
	pGanador[13][33] = 4;  pGanador[14][31] = 4;
	pGanador[14][32] = 4; pGanador[14][33] = 4;
	pGanador[15][31] = 4; pGanador[16][30] = 4;
	pGanador[16][31] = 4; pGanador[17][30] = 4;
	pGanador[17][31] = 4; pGanador[18][29] = 4;
	pGanador[18][30] = 4; pGanador[19][29] = 4;
	pGanador[19][30] = 4; pGanador[20][29] = 4;
	pGanador[20][30] = 4; pGanador[21][28] = 4;
	pGanador[21][29] = 4; pGanador[22][28] = 4;
	pGanador[22][29] = 4; pGanador[23][27] = 4;
	pGanador[23][28] = 4; pGanador[24][27] = 4;
	pGanador[23][28] = 4; pGanador[25][26] = 4;
	pGanador[25][27] = 4; pGanador[26][25] = 4;
	pGanador[26][26] = 4; pGanador[27][24] = 4;
	pGanador[27][25] = 4; pGanador[28][23] = 4;
	pGanador[29][23] = 4; pGanador[30][23] = 4;
	pGanador[31][23] = 4; pGanador[32][23] = 4;
	pGanador[33][24] = 4; pGanador[34][25] = 4;
	pGanador[34][26] = 4; pGanador[35][26] = 4;
	pGanador[35][27] = 4;

	/*2.3: Brillos */

	pGanador[9][16] = 5; pGanador[10][13] = 5;
	pGanador[10][15] = 5; pGanador[10][16] = 5;
	pGanador[10][17] = 5; pGanador[11][13] = 5;
	pGanador[11][16] = 5; pGanador[12][12] = 5;
	pGanador[12][13] = 5; pGanador[12][14] = 5;
	pGanador[13][10] = 5; pGanador[13][11] = 5;
	pGanador[13][12] = 5; pGanador[13][13] = 5;
	pGanador[13][14] = 5; pGanador[13][15] = 5;
	pGanador[13][16] = 5; pGanador[14][12] = 5;
	pGanador[14][13] = 5; pGanador[14][14] = 5;
	pGanador[15][13] = 5; pGanador[16][13] = 5;
}

int Aleatorio_Entre(int limite_inferior, int limite_superior) {
	int numero;
	numero = limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
	return numero;
}

void Configurar_Ficha(int color) {
	switch (color)
	{
		case 1: Console::ForegroundColor = ConsoleColor::Blue; break;
		case 2: Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 3: Console::ForegroundColor = ConsoleColor::Green; break;
		case 4: Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 5: Console::ForegroundColor = ConsoleColor::Red; break;
	}
}

void Mostrar_configuracion(Jugador*& pJugador) {
	int i = 0;
	if (pJugador[i].color != 0) i = 1;

	/* Inicializamos matriz */
	int** pConfiguracion;
	Iniciar_Arreglos_Configuracion(pConfiguracion, i);

	/* Limpieza de la consola */
	Console::Clear();

	/* Cargamos datos de Men� */
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pConfiguracion[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::White;
				cout << (char)219;
			}
			else {
				cout << ' ';
			}
		}

		cout << endl;
	}

	Console::CursorVisible = true;
	Console::SetCursorPosition(13, 28);
	cout << "Nombre: ";
	cin >> pJugador[i].nombre;

	Console::CursorVisible = false;
	Console::SetCursorPosition(13, 30);
	cout << "Color : " << char(174);
	Console::SetCursorPosition(26, 30);
	cout << char(175);

	/* Tecla */
	Console::SetCursorPosition(23, 30);
	int tecla, posicion_color = 1;

	Configurar_Ficha(posicion_color);
	cout << char(219) << char(219);

	while (true) {
		if (kbhit()) {
			tecla = getch();
			switch (tecla)
			{
				case 13: // Enter
					pJugador[i].color = posicion_color;

					if (i == 1) return;
					else return Mostrar_configuracion(pJugador);
				case 75: // Izquierda
					posicion_color--;
					if (posicion_color == 0) posicion_color = 5;
					break;
				case 77: // Derecha
					posicion_color++;
					if (posicion_color == 5) posicion_color = 1;
					break;
			}

			Console::SetCursorPosition(23, 30);
			Configurar_Ficha(posicion_color);
			cout << char(219) << char(219);
		}
	}
}

void Mostrar_Turno(Jugador*& pJugador, int turno) {
	Console::SetCursorPosition(13, 46);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Turno de " << pJugador[turno].nombre;
}

void Cambiar_Turno(Jugador*& pJugador, int& turno) {
	if (turno == 0) turno = 1;
	else turno = 0;

	Mostrar_Turno(pJugador, turno);
}

int Definir_Turno() {
	srand(time(NULL));
	int d1, d2, t;
	do {
		d1 = Aleatorio_Entre(1, 6);
		d2 = Aleatorio_Entre(1, 6);
	} while (d1 == d2);

	(d1 > d2) ? t = 0 : t = 1;
	return t;
}

bool Verificar_Posicion(int posicion, int tipo, int turno) {
	// Borramos el mensaje de bloqueo
	for (int i = 48; i < 50; i++) {
		for (int j = 1; j < 42; j++) {
			Console::SetCursorPosition(j, i);
			cout << ' ';
		}
	}

	Console::SetCursorPosition(4, 49);
	Console::ForegroundColor = ConsoleColor::White;

	if (tipo == 1) { // No puedas colocar una ficha encima de otra
		if (posicion == 8 || posicion == 9) {
			cout << "Ya existe una ficha en esta posici�n.";
			return false;
		}
	}
	else if (tipo == 2) { // No puedas eliminar tu propia ficha
		if (turno == 0) {
			if (posicion == 8) {
				cout << "No puedes eliminar tu propia ficha.";
				return false;
			}
		}
		else {
			if (posicion == 9) {
				cout << "No puedes eliminar tu propia ficha.";
				return false;
			}
		}
	}
	else if (tipo == 3) { // Verifica si en la casilla existe una ficha
		if (posicion != 8 && posicion != 9) {
			Console::SetCursorPosition(6, 49);
			cout << "No hay una ficha en esta posici" << char(162) << "n.";
			return false;
		}
	}
	else if(tipo == 4) { // Evita que puedas mover una ficha que no es tuya
		Console::SetCursorPosition(6, 49);
		if (turno == 0) {
			if (posicion == 9) {
				cout << "No puedes mover la ficha del J2.";
				return false;
			}
		}
		else {
			if (posicion == 8) {
				cout << "No puedes mover la ficha del J1.";
				return false;
			}
		}
	}

	return true;
}

bool Verificar_Linea(int** pTablero, Jugador*& pJugador, int turno, int& x, int& y) {
	int casillas_vertical = 0;
	int casillas_horizontal = 0;

	// For filas arriba
	for (int i = x - 1; i > 1; i--) {
		if (pTablero[i][y] == 2) break;

		if (pTablero[i][y] == 8 && turno == 0) {
			i = i - 2;
			casillas_vertical++;
		}

		if (pTablero[i][y] == 9 && turno == 1) {
			i = i - 2;
			casillas_vertical++;
		}

		if (y == 21 && i == 26) break;
	}

	// For filas abajo
	for (int i = x + 2; i < 42; i++) {
		if (pTablero[i][y] == 2) break;

		if (pTablero[i][y] == 8 && turno == 0) {
			i = i + 2;
			casillas_vertical++;
		}

		if (pTablero[i][y] == 9 && turno == 1) {
			i = i + 2;
			casillas_vertical++;
		}

		if (y == 21 && i == 17) break;
	}

	// For columas izq
	for (int j = y - 1; j > 1; j--) {
		if (pTablero[x][j] == 2) break;

		if (pTablero[x][j] == 8 && turno == 0) {
			j = j - 2;
			casillas_horizontal++;
		}

		if (pTablero[x][j] == 9 && turno == 1) {
			j = j - 2;
			casillas_horizontal++;
		}

		if (x == 21 && j == 26) break;
	}

	// For columnas der
	for (int j = y + 2; j < 42; j++) {
		if (pTablero[x][j] == 2) break;

		if (pTablero[x][j] == 8 && turno == 0) {
			j = j + 2;
			casillas_horizontal++;
		}

		if (pTablero[x][j] == 9 && turno == 1) {
			j = j + 2;
			casillas_horizontal++;
		}

		if (x == 21 && j == 17) break;
	}

	if (casillas_vertical == 2 || casillas_horizontal == 2) return true;
	else return false;
}

void Actualizar_Valor_Fichas(Jugador*& pJugador, int turno, bool aumentar) {
	int cantidad = 0;
	if (!aumentar) {
		(turno == 0) ? turno = 1 : turno = 0;
		cantidad = pJugador[turno].fichas - 1;
	}
	else {
		cantidad = pJugador[turno].fichas + 1;
	}

	if (turno == 0) Console::SetCursorPosition(8, 45);
	else Console::SetCursorPosition(40, 45);

	Console::ForegroundColor = ConsoleColor::White;

	pJugador[0].fichas = cantidad;
	cout << pJugador[turno].fichas;
}

void Actualizar_Valor_Movimientos(Jugador*& pJugador, int turno) {
	if (turno == 0) Console::SetCursorPosition(8, 46);
	else Console::SetCursorPosition(40, 46);

	Console::ForegroundColor = ConsoleColor::White;
	pJugador[turno].movimientos = pJugador[turno].movimientos + 1;
	cout << pJugador[turno].movimientos;
}

void Mostrar_Cursor_Saltar(int posicion, Jugador* pJugador, bool mostrar, int& x, int& y, int turno) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Console::SetCursorPosition(i + y, j + x);
			if (mostrar) {
				Configurar_Ficha(pJugador[turno].color);
				cout << char(219);
			}
			else {
				if (posicion == 8) {
					Configurar_Ficha(pJugador[0].color);
					cout << (char)219;
				}
				else if (posicion == 9) {
					Configurar_Ficha(pJugador[1].color);
					cout << (char)219;
				}
				else {
					Console::ForegroundColor = ConsoleColor::Gray;
					cout << char(177);
				}
			}
		}
	}
}

void Mostrar_Cursor_Adyacente(Jugador* pJugador, bool mostrar, int& x, int& y, int turno) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Console::SetCursorPosition(i + y, j + x);
			if (mostrar) {
				Configurar_Ficha(pJugador[turno].color);
				cout << char(219);
			}
			else {
				Console::ForegroundColor = ConsoleColor::Gray;
				cout << char(177);
			}
		}
	}
}

void Mostrar_Cursor(int posicion, Jugador* pJugador, bool mostrar, int& x, int &y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Console::SetCursorPosition(i + y, j + x);
			if (mostrar) {
				Console::ForegroundColor = ConsoleColor::DarkYellow;
				cout << char(219);
			}
			else {
				if (posicion == 8) {
					Configurar_Ficha(pJugador[0].color);
					cout << (char)219;
				}
				else if (posicion == 9) {
					Configurar_Ficha(pJugador[1].color);
					cout << (char)219;
				}
				else {
					Console::ForegroundColor = ConsoleColor::Gray;
					cout << char(177);
				}
			}
		}
	}
}

void Escapar_Juego() {
	int tecla = 0;
	Console::SetCursorPosition(0, 0);
	do {
		if (kbhit()) tecla = getch();
	} while (tecla != 27);
}

void Mostrar_Ganador(Jugador *pJugador, int turno) {
	int** pGanador;
	Iniciar_Arreglos_Ganador(pGanador);

	/* Limpieza de la consola */
	Console::Clear();

	/* Cargamos datos al tablero */
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pGanador[i][j] == 1) {
				//Console::ForegroundColor = ConsoleColor::Yellow;
				//cout << (char)219;
			}
			else if (pGanador[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cout << (char)219;
			}
			else if (pGanador[i][j] == 3) {
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << (char)219;
			}
			else if (pGanador[i][j] == 4) {
				Console::ForegroundColor = ConsoleColor::DarkYellow;
				cout << (char)219;
			}
			else if (pGanador[i][j] == 5) {
				Console::ForegroundColor = ConsoleColor::White;
				cout << (char)219;
			}
			else if (i == 18) {
				Console::SetCursorPosition(j, i);
				if (j == 18) cout << pJugador[turno].nombre;
				else if (j > 26 && j < 28) cout << ' ';
			}
			else if (i == 19) {
				Console::SetCursorPosition(j, i);
				if (j == 18) cout << "      ";
			}
			else if (i == 40) {
				Console::SetCursorPosition(j, i);
				if (j == 18) cout << "REGRESAR";
			}

			else {
				cout << ' ';
			}
		}

		cout << endl;
	}

	Console::SetCursorPosition(16, 40);
	cout << char(232);

	Escapar_Juego();
}

void Mostrar_Tablero(int **&pTablero, int **&pFicha, Jugador*& pJugador, int& turno) {
	/* Inicializamos matrices */
	Iniciar_Arreglos_Tablero(pTablero, pFicha);

	/* Limpieza de la consola */
	Console::Clear();

	/* Cargamos datos al tablero */
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pTablero[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << (char)195;
			}
			else if (pTablero[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Gray;
				cout << (char)177;
			}
			else if (i == 44) {
				Console::SetCursorPosition(j, i);
				if (j == 2) cout << pJugador[0].nombre;
				if (j == 21) cout << "VS";
				if (j == 34) cout << pJugador[1].nombre;
			}
			else if (i == 45) {
				Console::ForegroundColor = ConsoleColor::Gray;
				Console::SetCursorPosition(j, i);
				if (j == 2) cout << "Fchs: " << pJugador[0].fichas;
				if (j == 34) cout << "Fchs: " << pJugador[1].fichas;
			}
			else if (i == 46) {
				Console::ForegroundColor = ConsoleColor::Gray;
				Console::SetCursorPosition(j, i);
				if (j == 2) cout << "Movs: " << pJugador[0].movimientos;
				if (j == 13) {
					//cout << "Turno de " << pJugador[turno].nombre;
					Mostrar_Turno(pJugador, turno);
				}
				if (j == 34) cout << "Movs: " << pJugador[1].movimientos;
			}
			else if (i == 47) {
				Console::SetCursorPosition(j, i);
				if (j == 3) {
					Configurar_Ficha(pJugador[0].color);
					cout << char(219) << char(219) << char(219) << char(219);
				}
				if (j == 35) {
					Configurar_Ficha(pJugador[1].color);
					cout << char(219) << char(219) << char(219) << char(219);
				}
			}
			else {
				cout << ' ';
			}
		}

		cout << endl;
	}
}

void Borrar_Ficha(int** pTablero, Jugador*& pJugador, int turno, int& x, int& y) {
	int tecla;
	Mostrar_Cursor(NULL, NULL, true, x, y);

	while (true) {
		if (kbhit()) {
			Mostrar_Cursor(pTablero[x][y], pJugador, false, x, y);
			tecla = getch();

			switch (tecla) {
			case 13:
				if (!Verificar_Posicion(pTablero[x][y], 2, turno))
					return Borrar_Ficha(pTablero, pJugador, turno, x, y);

				pTablero[x][y] = 2;
				pTablero[x][y + 1] = 2;
				pTablero[x + 1][y] = 2;
				pTablero[x + 1][y + 1] = 2;

				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						Console::SetCursorPosition(i + y, j + x);
						Console::ForegroundColor = ConsoleColor::Gray;
						cout << char(176);
					}
				}

				Actualizar_Valor_Fichas(pJugador, turno, false);
				return;
			case 72: // arriba: mueve entre filas
				for (int i = x - 1; i > 1; i--) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i - 1;
						break;
					}
				}
				break;
			case 75: // izquierda: mueve entre columnas
				for (int j = y - 1; j > 1; j--) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j - 1;
						break;
					}
				}
				break;
			case 77: // derecha: mueve entre columnas
				for (int j = y + 2; j < 42; j++) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j;
						break;
					}
				}
				break;
			case 80: // abajo: mueve entre filas
				for (int i = x + 2; i < 42; i++) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i;
						break;
					}
				}
				break;
			}

			Mostrar_Cursor(NULL, NULL, true, x, y);
		}
	}
}

void Proceso_Linea(int** pTablero, Jugador*& pJugador, int turno, int& x, int& y) {
	if (Verificar_Linea(pTablero, pJugador, turno, x, y)) {
		Console::ForegroundColor = ConsoleColor::White;

		Console::SetCursorPosition(12, 48);
		cout << char(173) << "Formaste un molino!";

		Console::SetCursorPosition(9, 49);
		cout << char(173) << "Quitale una ficha al J" << ((turno == 0) ? 2 : 1) << "!";

		Borrar_Ficha(pTablero, pJugador, turno, x, y);
	}
}

bool Colocar_Ficha(int**& pTablero, Jugador*& pJugador, int& x, int& y, int turno) {
	if (!Verificar_Posicion(pTablero[x][y], 1, NULL)) return false;

	if (turno == 0) { // Jugador 1
		pTablero[x][y] = 8;
		pTablero[x][y + 1] = 8;
		pTablero[x + 1][y] = 8;
		pTablero[x + 1][y + 1] = 8;
	}
	else { // Jugador 2
		pTablero[x][y] = 9;
		pTablero[x][y + 1] = 9;
		pTablero[x + 1][y] = 9;
		pTablero[x + 1][y + 1] = 9;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Configurar_Ficha(pJugador[turno].color);
			Console::SetCursorPosition(i + y, j + x);
			cout << (char)219;
		}
	}

	Actualizar_Valor_Fichas(pJugador, turno, true);
	Proceso_Linea(pTablero, pJugador, turno, x, y);

	return true;
}

bool Mover_Ficha_Adyacente(int**& pTablero, Jugador* pJugador, int& x, int& y, int turno) {
	if (!Verificar_Posicion(pTablero[x][y], 3, NULL)) return false;
	if (!Verificar_Posicion(pTablero[x][y], 4, turno)) return false;

	pTablero[x][y] = 6;
	pTablero[x][y + 1] = 6;
	pTablero[x + 1][y] = 6;
	pTablero[x + 1][y + 1] = 6;

	int tecla, inicial_x = x, inicial_y = y, contador = 0;
	Mostrar_Cursor_Adyacente(pJugador, true, x, y, turno);
	while (true) {
		if (kbhit()) {
			Mostrar_Cursor_Adyacente(pJugador, false, x, y, turno);
			tecla = getch();
			switch (tecla)
			{
				case 13: // Enter
					if (pTablero[x][y] == 6) {
						if (turno == 0) {
							pTablero[inicial_x][inicial_y] = 8;
							pTablero[inicial_x][inicial_y + 1] = 8;
							pTablero[inicial_x + 1][inicial_y] = 8;
							pTablero[inicial_x + 1][inicial_y + 1] = 8;
						}
						else {
							pTablero[inicial_x][inicial_y] = 9;
							pTablero[inicial_x][inicial_y + 1] = 9;
							pTablero[inicial_x + 1][inicial_y] = 9;
							pTablero[inicial_x + 1][inicial_y + 1] = 9;
						}

						for (int i = 0; i < 2; i++) {
							for (int j = 0; j < 2; j++) {
								Console::SetCursorPosition(i + inicial_y, j + inicial_x);
								Configurar_Ficha(pJugador[turno].color);
								cout << char(219);
							}
						}

						return false;
					};

					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							Console::SetCursorPosition(i + y, j + x);
							Configurar_Ficha(pJugador[turno].color);
							cout << char(219);
						}
					}

					if (turno == 0) {
						pTablero[x][y] = 8;
						pTablero[x][y + 1] = 8;
						pTablero[x + 1][y] = 8;
						pTablero[x + 1][y + 1] = 8;
					}
					else {
						pTablero[x][y] = 9;
						pTablero[x][y + 1] = 9;
						pTablero[x + 1][y] = 9;
						pTablero[x + 1][y + 1] = 9;
					}

					pTablero[inicial_x][inicial_y] = 2;
					pTablero[inicial_x][inicial_y + 1] = 2;
					pTablero[inicial_x + 1][inicial_y] = 2;
					pTablero[inicial_x + 1][inicial_y + 1] = 2;

					Proceso_Linea(pTablero, pJugador, turno, x, y);
					return true;
				case 27: // Escape
					if (turno == 0) {
						pTablero[inicial_x][inicial_y] = 8;
						pTablero[inicial_x][inicial_y + 1] = 8;
						pTablero[inicial_x + 1][inicial_y] = 8;
						pTablero[inicial_x + 1][inicial_y + 1] = 8;
					}
					else {
						pTablero[inicial_x][inicial_y] = 9;
						pTablero[inicial_x][inicial_y + 1] = 9;
						pTablero[inicial_x + 1][inicial_y] = 9;
						pTablero[inicial_x + 1][inicial_y + 1] = 9;
					}

					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							Console::SetCursorPosition(i + inicial_y, j + inicial_x);
							Configurar_Ficha(pJugador[turno].color);
							cout << char(219);
						}
					}

					return false;
				case 72: // arriba
					for (int i = x - 1; i > 1; i--) {
						if (pTablero[i][y] == 2) {
							if (contador == 0) {
								x = i - 1;
								contador++;
							}
							break;
						}
						else if (pTablero[i][y] == 6) {
							x = i - 1;
							contador = 0;
							break;
						}
						else if (pTablero[i][y] == 8 || pTablero[i][y] == 9) break;
					}
					break;
				case 75: // izquierda
					for (int j = y - 1; j > 1; j--) {
						if (pTablero[x][j] == 2) {
							if (contador == 0) {
								y = j - 1;
								contador++;
							}
							break;
						}
						else if (pTablero[x][j] == 6) {
							y = j - 1;
							contador = 0;
							break;
						}
						else if (pTablero[x][j] == 8 || pTablero[x][j] == 9) break;
					}
					break;
				case 77: // derecha
					for (int j = y + 2; j < 42; j++) {
						if (pTablero[x][j] == 2) {
							if (contador == 0) {
								y = j;
								contador++;
							}
							break;
						}
						else if (pTablero[x][j] == 6) {
							y = j;
							contador = 0;
							break;
						}
						else if (pTablero[x][j] == 8 || pTablero[x][j] == 9) break;
					}
					break;
				case 80: // abajo
					for (int i = x + 2; i < 42; i++) {
						if (pTablero[i][y] == 2) {
							if (contador == 0) {
								x = i;
								contador++;
							}
							break;
						}
						else if (pTablero[i][y] == 6) {
							x = i;
							contador = 0;
							break;
						}
						else if (pTablero[i][y] == 8 || pTablero[i][y] == 9) break;
					}
					break;
			}

			Mostrar_Cursor_Adyacente(pJugador, true, x, y, turno);
		}
	}
}

bool Mover_Ficha_Saltar(int**& pTablero, Jugador* pJugador, int& x, int& y, int turno) {
	if (!Verificar_Posicion(pTablero[x][y], 3, NULL)) return false;
	if (!Verificar_Posicion(pTablero[x][y], 4, turno)) return false;

	pTablero[x][y] = 6;
	pTablero[x][y + 1] = 6;
	pTablero[x + 1][y] = 6;
	pTablero[x + 1][y + 1] = 6;

	int tecla, inicial_x = x, inicial_y = y;
	Mostrar_Cursor_Saltar(NULL, pJugador, true, x, y, turno);
	while (true) {
		if (kbhit()) {
			Mostrar_Cursor_Saltar(pTablero[x][y], pJugador, false, x, y, turno);
			tecla = getch();
			switch (tecla)
			{
				case 13:
					if (pTablero[x][y] == 6) {
						if (turno == 0) {
							pTablero[inicial_x][inicial_y] = 8;
							pTablero[inicial_x][inicial_y + 1] = 8;
							pTablero[inicial_x + 1][inicial_y] = 8;
							pTablero[inicial_x + 1][inicial_y + 1] = 8;
						}
						else {
							pTablero[inicial_x][inicial_y] = 9;
							pTablero[inicial_x][inicial_y + 1] = 9;
							pTablero[inicial_x + 1][inicial_y] = 9;
							pTablero[inicial_x + 1][inicial_y + 1] = 9;
						}

						for (int i = 0; i < 2; i++) {
							for (int j = 0; j < 2; j++) {
								Console::SetCursorPosition(i + inicial_y, j + inicial_x);
								Configurar_Ficha(pJugador[turno].color);
								cout << char(219);
							}
						}

						return false;
					};

					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							Console::SetCursorPosition(i + y, j + x);
							Configurar_Ficha(pJugador[turno].color);
							cout << char(219);
						}
					}

					if (turno == 0) {
						pTablero[x][y] = 8;
						pTablero[x][y + 1] = 8;
						pTablero[x + 1][y] = 8;
						pTablero[x + 1][y + 1] = 8;
					}
					else {
						pTablero[x][y] = 9;
						pTablero[x][y + 1] = 9;
						pTablero[x + 1][y] = 9;
						pTablero[x + 1][y + 1] = 9;
					}

					pTablero[inicial_x][inicial_y] = 2;
					pTablero[inicial_x][inicial_y + 1] = 2;
					pTablero[inicial_x + 1][inicial_y] = 2;
					pTablero[inicial_x + 1][inicial_y + 1] = 2;

					Proceso_Linea(pTablero, pJugador, turno, x, y);
					return true;
				case 27:
					if (turno == 0) {
						pTablero[inicial_x][inicial_y] = 8;
						pTablero[inicial_x][inicial_y + 1] = 8;
						pTablero[inicial_x + 1][inicial_y] = 8;
						pTablero[inicial_x + 1][inicial_y + 1] = 8;
					}
					else {
						pTablero[inicial_x][inicial_y] = 9;
						pTablero[inicial_x][inicial_y + 1] = 9;
						pTablero[inicial_x + 1][inicial_y] = 9;
						pTablero[inicial_x + 1][inicial_y + 1] = 9;
					}

					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							Console::SetCursorPosition(i + inicial_y, j + inicial_x);
							Configurar_Ficha(pJugador[turno].color);
							cout << char(219);
						}
					}

					return false;
				case 72: // arriba: mueve entre filas
					for (int i = x - 1; i > 1; i--) {
						if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9 || pTablero[i][y] == 6) {
							x = i - 1;
							break;
						}
					}
					break;
				case 75: // izquierda: mueve entre columnas
					for (int j = y - 1; j > 1; j--) {
						if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9 || pTablero[x][j] == 6) {
							y = j - 1;
							break;
						}
					}
					break;
				case 77: // derecha: mueve entre columnas
					for (int j = y + 2; j < 42; j++) {
						if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9 || pTablero[x][j] == 6) {
							y = j;
							break;
						}
					}
					break;
				case 80: // abajo: mueve entre filas
					for (int i = x + 2; i < 42; i++) {
						if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9 || pTablero[i][y] == 6) {
							x = i;
							break;
						}
					}
					break;
			}

			Mostrar_Cursor_Saltar(NULL, pJugador, true, x, y, turno);
		}
	}
}

void Primera_Fase(int** pTablero, Jugador*& pJugador, int& x, int& y, int &t) {
	int tecla, fichas_general = 0;
	Mostrar_Cursor(NULL, NULL, true, x, y);

	while (true) {
		if (kbhit()) {
			Mostrar_Cursor(pTablero[x][y], pJugador, false, x, y);
			tecla = getch();

			switch (tecla) {
			case 13: // Enter
				if (Colocar_Ficha(pTablero, pJugador, x, y, t)) {
					Cambiar_Turno(pJugador, t);
					fichas_general = fichas_general + 1;
				}
				break;
			case 72: // arriba: mueve entre filas
				for (int i = x - 1; i > 1; i--) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i - 1;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 75: // izquierda: mueve entre columnas
				for (int j = y - 1; j > 1; j--) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j - 1;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 77: // derecha: mueve entre columnas
				for (int j = y + 2; j < 42; j++) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 80: // abajo: mueve entre filas
				for (int i = x + 2; i < 42; i++) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			}

			if (fichas_general == 18) break;

			Mostrar_Cursor(NULL, NULL, true, x, y);
		}
	}
}

void Segunda_Tercera_Fase(int** pTablero, Jugador*& pJugador, int& x, int& y, int& t) {
	int tecla;
	Mostrar_Cursor(NULL, NULL, true, x, y);
	while (true) {
		if (kbhit()) {
			Mostrar_Cursor(pTablero[x][y], pJugador, false, x, y);
			tecla = getch();

			switch (tecla) {
			case 13: // Enter
				if (pJugador[t].fichas == 3) {
					if (Mover_Ficha_Saltar(pTablero, pJugador, x, y, t)) {
						/*if (pJugador[0].fichas == 2) {
							Mostrar_Ganador(pJugador, 1);
							return;
						}
						else if (pJugador[1].fichas == 2) {
							Mostrar_Ganador(pJugador, 0);
							return;
						}*/

						Cambiar_Turno(pJugador, t);
					}
				}
				else {
					if (Mover_Ficha_Adyacente(pTablero, pJugador, x, y, t)) {
						if (pJugador[0].fichas == 2) {
							Mostrar_Ganador(pJugador, 1);
							return;
						}
						else if (pJugador[1].fichas == 2) {
							Mostrar_Ganador(pJugador, 0);
							return;
						}

						Cambiar_Turno(pJugador, t);
					}
				}
				break;
			case 72: // arriba: mueve entre filas
				for (int i = x - 1; i > 1; i--) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i - 1;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 75: // izquierda: mueve entre columnas
				for (int j = y - 1; j > 1; j--) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j - 1;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 77: // derecha: mueve entre columnas
				for (int j = y + 2; j < 42; j++) {
					if (pTablero[x][j] == 2 || pTablero[x][j] == 8 || pTablero[x][j] == 9) {
						y = j;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			case 80: // abajo: mueve entre filas
				for (int i = x + 2; i < 42; i++) {
					if (pTablero[i][y] == 2 || pTablero[i][y] == 8 || pTablero[i][y] == 9) {
						x = i;
						Actualizar_Valor_Movimientos(pJugador, t);
						break;
					}
				}
				break;
			}
			Mostrar_Cursor(NULL, NULL, true, x, y);
		}
	}
}

void Jugar(int**& pTablero, Jugador*& pJugador, int& t) {
	int x = 3, y = 3;
	
	Primera_Fase(pTablero, pJugador, x, y, t);
	Segunda_Tercera_Fase(pTablero, pJugador, x, y, t);
}

void Iniciar_Juego() {
	/* Inicializamos punteros */
	int** pTablero, ** pFicha, t;
	Jugador* pJugador = new Jugador[2];

	/* Registrar Jugadores */
	Mostrar_configuracion(pJugador);

	/* Definir turno del jugador */
	t = Definir_Turno();

	/* Mostramos el tablero */
	Mostrar_Tablero(pTablero, pFicha, pJugador, t);

	/* Jugamos! */
	Jugar(pTablero, pJugador, t);
}

void Mostrar_Instrucciones() {
	Console::Clear();
	cout << "Mis instrucciones";

	// Tecla
	int tecla = 0;
	Console::SetCursorPosition(0, 0);
	do {
		if (kbhit()) tecla = getch();
	} while (tecla != 27);
}

void Mostrar_Creditos() {
	/* Inicializamos matriz */
	int** pCreditos;
	Iniciar_Arreglos_Creditos(pCreditos);

	/* Limpieza de la consola */
	Console::Clear();

	/* Cargamos datos al tablero */
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pCreditos[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << (char)195;
			}
			else if (pCreditos[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << (char)219;
			}
			else if (pCreditos[i][j] == 3) {
				Console::ForegroundColor = ConsoleColor::White;
				cout << (char)219;
			}
			else if (pCreditos[i][j] == 4) {
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cout << (char)219;
			}
			else if (i == 16) {
				if (j == 14) cout << "DESARROLLADO POR:";
				else if (j < 26) cout << ' ';
			}
			else if (i == 19) {
				if (j == 14) cout << "GIANPAUL  ALONSO";
				else if (j < 27) cout << ' ';
			}
			else if (i == 20) {
				if (j == 15) cout << "BERNAL SARAVIA";
				else if (j < 29) cout << ' ';
			}
			else if (i == 22) {
				if (j == 14) cout << "MELANIE  XIOMARA";
				else if (j < 27) cout << ' ';
			}
			else if (i == 23) {
				if (j == 15) cout << "PUCHOC BARZOLA";
				else if (j < 29) cout << ' ';
			}
			else if (i == 25) {
				if (j == 13) cout << "JOAQUIN  SEBASTIAN";
				else if (j < 25) cout << ' ';
			}
			else if (i == 26) {
				if (j == 16) cout << "RUIZ RAMIREZ";
				else if (j < 31) cout << ' ';
			}
			else if (i == 32) {
				if (j == 8) cout << "PRESIONE 'ESC' PARA REGRESAR";
				else if (j < 15) cout << ' ';
			}
			else if (i == 33) {
				if (j == 18) cout << "AL MENU";
				else if (j < 36) cout << ' ';
			}
			else {
				cout << ' ';
			}
		}

		cout << endl;
	}

	// Tecla
	Escapar_Juego();
}

void Mostrar_Cursor_Menu(int x, int y, bool mostrar) {
	Console::SetCursorPosition(y, x);
	if (mostrar) cout << char(232);
	else cout << ' ';
}

void Mostrar_Menu() {
	/* Inicializamos matriz */
	int **pMenu;
	Iniciar_Arreglos_Menu(pMenu);

	/* Limpieza de la consola */
	Console::Clear();

	/* Cargamos datos de Men� */
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (pMenu[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << (char)195;
			}
			else if (pMenu[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Red;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 3) {
				Console::ForegroundColor = ConsoleColor::DarkYellow;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 4) {
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 5) {
				Console::ForegroundColor = ConsoleColor::DarkCyan;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 6) {
				Console::ForegroundColor = ConsoleColor::Gray;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 7) {
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << (char)219;
			}
			else if (pMenu[i][j] == 8) {
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				cout << (char)254;
			}
			else if (i == 25) {
				if (j == 16) cout << "INICIAR JUEGO";
				else if (j < 30) cout << ' ';
			}
			else if (i == 27) {
				if (j == 16) cout << "INSTRUCCIONES";
				else if (j < 30) cout << ' ';
			}
			else if (i == 29) {
				if (j == 16) cout << "CREDITOS";
				else if (j < 35) cout << ' ';
			}
			else if (i == 31) {
				if (j == 16) cout << "SALIR";
				else if (j < 38) cout << ' ';
			}
			else {
				cout << ' ';
			}
		}

		cout << endl;
	}

	/* Teclas */
	int tecla, x = 25, y = 14;
	Mostrar_Cursor_Menu(x, y, true);
	while (true) {
		if (kbhit()) {
			Mostrar_Cursor_Menu(x, y, false);

			tecla = getch();
			switch (tecla) {
				case 13: // Enter
					if (x == 25) Iniciar_Juego();
					if (x == 27) Mostrar_Instrucciones();
					if (x == 29) Mostrar_Creditos();
					if (x == 31) exit(0);

					Mostrar_Menu();
					break;
				case 72: // Arriba
					if (x > 25) x = x - 2; 
					break;
				case 80: // Abajo
					if(x < 31) x = x + 2;
					break;
			}

			Mostrar_Cursor_Menu(x, y, true);
		}
	}
}

void main()
{
	/* Configuramos la ventana */
	Console::SetWindowSize(columnas, filas);
	Console::CursorVisible = false;

	/* Mostramos el men� */
	Mostrar_Menu();

	system("pause>NULL");
}