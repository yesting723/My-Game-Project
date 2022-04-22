#include <SDL.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

int p_r,p_l,bomb,goal;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
char map0101[8][10];
char map0102[10][10];
char map0103[10][10];


char map0201[10][10];
char map0202[10][10];
char map0203[10][10];


char map0301[10][10];
char map0302[10][10];
char map0303[10][10];


char map0401[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ','w','w','w','e'},
{'e',' ','w',' ',' ','b','w',' ',' ','e'},
{'e',' ','w','w','w','w','w','w',' ','e'},
{'e',' ',' ','w',' ',' ',' ','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','m',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};
	
char map0402[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ','m',' ',' ','b','e'},
{'e','b',' ',' ',' ','w','b',' ',' ','e'},
{'e','w','m','w','w','w','w','w','w','e'},
{'e',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ',' ','w','w','w','w','w','w','e'},
{'e',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ',' ','m',' ',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};
	
char map0403[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','m',' ',' ',' ',' ','e'},
{'e','b',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ','w',' ',' ',' ','b','e'},
{'e','w','m','w','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ','w','w','w','m','w','e'},
{'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ','w',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};

char map0501[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ','b',' ','m',' ',' ',' ',' ','e'},
{'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ','w',' ',' ',' ','e'},
{'e',' ',' ',' ',' ','w',' ',' ',' ','e'},
{'e','w','m','w','w','w','w','b',' ','e'},
{'e',' ',' ',' ',' ','w',' ','w','m','e'},
{'e','b',' ',' ','w',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};
	
char map0502[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*','w',' ','w',' ','b',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ','e'},
{'e',' ','w',' ','m',' ','w',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ','m','e'},
{'e',' ',' ',' ','w',' ',' ','w',' ','e'},
{'e',' ','b',' ','w',' ','w','w',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};
	
char map0503[11][11] = {
{'e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ',' ',' ',' ','b','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e','w','w',' ','w','w','w','w','w','e'},
{'e','b','w',' ',' ','w',' ','w',' ','e'},
{'e',' ','w',' ',' ','w',' ','w',' ','e'},
{'e',' ','w',' ',' ','w','w','w',' ','e'},
{'e',' ','m',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w',' ',' ','m',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e'}
};

char map0601[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','w','w',' ','w','w','w','w',' ',' ',' ','e'},
{'e',' ','w',' ','w',' ',' ',' ',' ','w','w',' ',' ',' ','e'},
{'e',' ','w',' ','w',' ','w','w','m','w','w',' ',' ',' ','e'},
{'e','b','w',' ',' ',' ','w',' ',' ',' ','m',' ',' ',' ','e'},
{'e','w','w','w','w','m','w',' ','w','w','w',' ',' ',' ','e'},
{'e','b','w',' ',' ',' ','w',' ',' ','w','w',' ',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w',' ','w','w','w','w','w','m','w','w',' ',' ','e'},
{'e',' ','w',' ',' ',' ','w',' ',' ',' ',' ','w',' ',' ','e'},
{'e',' ','w','w','w',' ','w',' ','w','w','w','w',' ',' ','e'},
{'e',' ','w','b','w',' ','w',' ','w',' ',' ','w','w',' ','e'},
{'e',' ',' ',' ',' ',' ','w',' ',' ',' ','w','w',' ',' ','e'},
{'e',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0602[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*','w',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w',' ','w','w',' ',' ',' ',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w','w',' ','w','w','w','w',' ','w',' ','e'},
{'e',' ','w',' ','b','w',' ','w',' ',' ',' ',' ','w',' ','e'},
{'e',' ','w',' ',' ','w',' ','w',' ','w','w','w','w',' ','e'},
{'e',' ','w','w','w','w',' ','w',' ','w','b','w',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','w',' ',' ','e'},
{'e',' ','w','w','w','w','w','w','w','w',' ','w','w','m','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ','w',' ',' ',' ',' ','e'},
{'e',' ','w','w','w','w',' ','w',' ','w',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w',' ','w','w','w','w','w','e'},
{'e',' ',' ',' ',' ',' ',' ','m',' ',' ',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0603[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ','w','w','w','w','m','w','w','w',' ','e'},
{'e',' ',' ','w',' ','w',' ',' ',' ',' ','w',' ','w',' ','e'},
{'e',' ',' ','w',' ','w',' ','w','w','w','w',' ','w',' ','e'},
{'e','w',' ','w',' ','w',' ','w','w',' ',' ',' ','w',' ','e'},
{'e',' ',' ',' ',' ','w',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','w','w','w','w','w',' ','w','w','w','b','w',' ','e'},
{'e',' ',' ',' ',' ','b','w',' ',' ',' ',' ','w','w',' ','e'},
{'e','w',' ','w','w',' ','w','w',' ','w',' ',' ','w',' ','e'},
{'e',' ',' ','w',' ',' ','w',' ',' ','w',' ','w','w',' ','e'},
{'e',' ','w','w',' ','w','w',' ','b','w',' ',' ','w',' ','e'},
{'e',' ',' ','w',' ',' ','w','w','w','w','m','w','w','m','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0701[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','b','w',' ','w',' ',' ','w','w',' ',' ','w',' ','e'},
{'e',' ','w',' ',' ',' ','w',' ',' ',' ','w','b','w',' ','e'},
{'e',' ','w','w',' ','w',' ','w',' ',' ',' ','w',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ',' ','w','w',' ','w','w',' ','e'},
{'e',' ','w',' ','w','w','w',' ','w',' ',' ','m',' ',' ','e'},
{'e',' ',' ',' ','w','b','w',' ','w',' ','w','w','w','w','e'},
{'e',' ','w',' ',' ',' ','w',' ','w',' ','w',' ','w','w','e'},
{'e',' ','w',' ',' ','w','w',' ','w',' ','w',' ',' ',' ','e'},
{'e',' ','w','w','w',' ','m',' ','w',' ',' ',' ','w',' ','e'},
{'e',' ','w',' ',' ',' ','w','w','w','w',' ','w','m',' ','e'},
{'e',' ',' ',' ','w','w',' ',' ','w',' ','w','w',' ','w','e'},
{'e',' ','w','w',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0702[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*','w','b',' ','w',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e',' ','m',' ',' ','w',' ',' ','w','w','w','w',' ',' ','e'},
{'e',' ','w',' ',' ','m','w','w','w',' ',' ','w','w',' ','e'},
{'e',' ','w','w','w','w',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ','b','w',' ','w','m',' ',' ','w',' ','w','e'},
{'e',' ','m',' ',' ','w','w',' ',' ','w','w','w',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ',' ','w',' ',' ','w','w',' ','e'},
{'e',' ','w','b',' ','m',' ',' ','w','w','w','w',' ',' ','e'},
{'e',' ','w','w','w','w',' ',' ','m',' ',' ','w',' ','w','e'},
{'e',' ','w',' ',' ','w','w','w','w',' ',' ',' ',' ',' ','e'},
{'e',' ','m',' ',' ','w',' ',' ','w','w','w','w','w',' ','e'},
{'e',' ','w',' ',' ','w',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e','b','w',' ',' ',' ',' ',' ','w',' ',' ','w',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0703[16][16] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','m','d'},
{'e',' ','w',' ','w','w','w','w','w','w',' ',' ','w',' ','e'},
{'e',' ','w',' ','b','w',' ',' ',' ','w',' ','w',' ',' ','e'},
{'e',' ','w','w','w','w',' ','w',' ','w',' ','w','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w',' ','w',' ',' ',' ',' ','e'},
{'e',' ','w','w','w','w','w','w',' ','w','m','w','w',' ','e'},
{'e',' ','w','b',' ',' ',' ',' ',' ',' ',' ',' ','w','w','e'},
{'e',' ','w','w','w',' ','w','w','w',' ','w',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ',' ','w','w','w',' ','e'},
{'e',' ','w','w','w','w',' ','w','w','w','b',' ','w',' ','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ','e'},
{'e',' ','w',' ','w','w','w','w',' ',' ',' ',' ','w',' ','e'},
{'e',' ','w',' ',' ',' ','b','w','b',' ',' ',' ','m',' ','e'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
};

char map0801[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*','w','b',' ','w',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ',' ',' ','w',' ','m',' ',' ',' ',' ',' ','e'},
{'e',' ','w','w',' ','w','w','w','w','w','w','w','w','w','w','w','w','w',' ','e'},
{'e',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ','w','w',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ','w','w','w','w','w',' ','w','w',' ','w','w','w','w','e'},
{'e',' ','w','w','w','w',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ','w',' ','w','w','m','w','w','w','w','w','w','w','w',' ','e'},
{'e',' ','w',' ',' ','w',' ','w',' ',' ',' ','m',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ','m',' ','w',' ','w',' ','w','w','w','w','w',' ',' ',' ','e'},
{'e',' ','w','w',' ','w',' ','w',' ','w',' ',' ',' ',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w','w','w','w',' ','w',' ','w','w','w','w','w',' ','w','m','w','w','e'},
{'e',' ','w',' ','w',' ',' ','w',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ','w','w','w',' ',' ','w','w','w','w','w',' ','w',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','w','w','w','m','e'},
{'e',' ','w','w','w','w',' ','w','w','w',' ','w','w','w',' ','w',' ',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ','w',' ',' ',' ',' ','w',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w',' ',' ','w','m','w',' ',' ',' ',' ','w',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w','b',' ',' ',' ',' ',' ',' ',' ','b','w',' ',' ','m',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};

char map0802[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ',' ',' ','w','w',' ',' ',' ',' ','w','w','w',' ','b',' ','w','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ','w','w',' ',' ',' ',' ',' ','w',' ',' ','e'},
{'e','w','w',' ','w','w','w','w','w','w','w','w','w','w',' ','w','w','w','w','e'},
{'e',' ',' ',' ',' ',' ','w','b',' ',' ',' ',' ','m',' ',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ','m',' ',' ',' ',' ','b','w',' ',' ',' ',' ',' ',' ','e'},
{'e','w','w','w','m','w','w','w','w','m','w','w','w','w','w','m','w','w','w','e'},
{'e',' ','w','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w','e'},
{'e','w',' ',' ',' ',' ',' ',' ','w','b',' ',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e','w','m','w','w','w','w','w','w','w','w','m','w','w','w','w','w','w','w','e'},
{'e',' ',' ',' ','w','w',' ',' ',' ',' ','w',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w',' ','b','w',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e','w','w','m','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','e'},
{'e',' ',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','w',' ',' ',' ',' ','w','e'},
{'e',' ','w','w','w','w',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w','b',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','e'},
{'e','w','w','w','m','w','w','w','w','w','w','w','w','w','w','w','w','w','m','e'},
{'e',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ',' ',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};

char map0803[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','w','w',' ',' ',' ','w','w',' ',' ',' ','w','w',' ',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ','e'},
{'e',' ',' ','w','w','w','w','w','w','m','w','w','w','w','w','w','w',' ',' ','e'},
{'e','w',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ',' ',' ',' ','w',' ','w','e'},
{'e','w',' ','w',' ','w','w',' ','w',' ',' ','w','w','w','w',' ','w',' ','w','e'},
{'e','w',' ','w',' ',' ','w',' ','w',' ',' ','w',' ',' ','w',' ','w',' ','w','e'},
{'e',' ',' ','w',' ','w','w',' ',' ',' ',' ','w',' ',' ','w',' ','w',' ',' ','e'},
{'e',' ','w','w',' ','w','w','w','w','w','w','w','w',' ','w',' ','w','w',' ','e'},
{'e',' ','w','w',' ','w',' ',' ',' ',' ',' ',' ','w','w','w',' ','w','w',' ','e'},
{'e',' ','w','w',' ','w',' ','w','w','w','w',' ','w',' ','m',' ','w','w',' ','e'},
{'e',' ','w','w',' ','w',' ',' ',' ',' ','w','b','w',' ','w',' ','w','w',' ','e'},
{'e',' ',' ','w',' ','w',' ','w','w',' ','w','w','w',' ','w',' ','w',' ',' ','e'},
{'e','w',' ','w',' ','w',' ',' ','w',' ',' ',' ',' ',' ','w',' ','w',' ','w','e'},
{'e','w',' ','w',' ','w',' ',' ','w','w','w','w','w','w','w',' ','w',' ','w','e'},
{'e','w',' ','w','d','w',' ','b','w',' ',' ',' ',' ',' ',' ',' ','w',' ','w','e'},
{'e',' ',' ','w','w','w','w','w','w','w','m','w','w','w','w','w','w',' ',' ','e'},
{'e',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ',' ',' ',' ','w',' ','e'},
{'e',' ',' ',' ','w','w',' ',' ',' ','w','w',' ',' ',' ','w','w',' ',' ','b','e'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};

char map0901[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*','w',' ',' ','w',' ',' ','w',' ','b','w',' ',' ','w',' ',' ',' ','b','e'},
{'e','b','w',' ',' ','w','w','w','w',' ',' ','w',' ',' ','w',' ',' ',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ','w','w',' ',' ','w',' ',' ','w','m','w',' ',' ','e'},
{'e',' ','w','w','w','w',' ',' ','m',' ',' ','w',' ',' ',' ',' ','w',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ',' ','w',' ',' ','w',' ','w',' ',' ','w',' ',' ','e'},
{'e','m','w',' ',' ','w','w',' ','w',' ',' ',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ',' ','w','w','w',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e',' ','w',' ',' ','w',' ',' ',' ',' ','w',' ','b','w',' ',' ','w','w','w','e'},
{'e',' ','w',' ',' ','w',' ','w',' ','b','w','w','w','w',' ',' ','w',' ',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','w','w','w','w',' ','b','w',' ',' ','w',' ','w','e'},
{'e',' ','w','w','w',' ',' ','w',' ',' ','w',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e',' ',' ',' ','w','w','w','w',' ',' ','w','b',' ','w',' ',' ','w','w',' ','e'},
{'e',' ',' ','b','w','w',' ','m',' ',' ','w','w','w','w',' ',' ','w',' ',' ','e'},
{'e','w','m','w','w','b',' ','w',' ',' ','w',' ',' ','m',' ',' ',' ',' ',' ','e'},
{'e',' ',' ','b','w',' ','w','w','w','w','w',' ',' ','w',' ',' ','w',' ',' ','e'},
{'e',' ',' ',' ','w',' ',' ','w',' ',' ','w',' ',' ','w','w','w','w','w',' ','e'},
{'e',' ',' ',' ','w',' ',' ','m',' ',' ','w',' ',' ','m',' ',' ','w','w',' ','e'},
{'e','b',' ',' ','m',' ','w','w',' ',' ',' ',' ',' ','w',' ',' ','w',' ',' ','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};

char map0902[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*','m',' ',' ','w',' ','w',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ','e'},
{'e',' ','m','m',' ','w',' ','w',' ','w',' ','w',' ','w',' ','w',' ','w',' ','e'},
{'e',' ',' ','m','m','w',' ',' ',' ','w',' ',' ',' ','w',' ','b',' ','w','b','e'},
{'e',' ',' ',' ','m','m',' ','w','w','w','w','w','w','w','w','w','w','w','w','e'},
{'e',' ','b',' ',' ','m','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','e'},
{'e','w','w','w','w',' ','m','m',' ',' ','w','w','w','w','w','w','w','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ','m','m',' ',' ',' ',' ',' ',' ',' ',' ','w','b','e'},
{'e','b',' ','w','w',' ',' ',' ','m','m',' ','w','w','w','w','w','w','w','w','e'},
{'e',' ',' ',' ',' ','b',' ',' ',' ','m','m',' ',' ','w',' ',' ',' ','w','b','e'},
{'e','w','w','w','w','w','w','w','w',' ','m','m',' ',' ',' ','w',' ','w',' ','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','m','m',' ',' ','w',' ',' ',' ','e'},
{'e',' ','w','w','b','w','w','w','w',' ',' ',' ','m','m',' ','w','w','w','w','e'},
{'e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','m','m',' ',' ',' ',' ','e'},
{'e','w','w','w','w','w','w','w','w','w','w','w','w','w','m','m',' ',' ',' ','e'},
{'e',' ','w','b',' ',' ','w',' ',' ',' ','w',' ',' ',' ',' ','m','m',' ',' ','e'},
{'e',' ','w',' ','w',' ','w',' ','w',' ','w',' ','w',' ',' ','w','m','m',' ','e'},
{'e',' ','w',' ','w',' ','w',' ','w',' ','w',' ','w',' ',' ','w',' ','m','m','e'},
{'e',' ',' ',' ','w',' ','b',' ','w',' ',' ',' ','w',' ',' ','w',' ',' ','m','d'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};

char map0903[21][21] = {
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
{'e','*',' ',' ','m',' ',' ',' ','w','b',' ','m',' ',' ','w',' ',' ',' ','w','e'},
{'e',' ','w','w',' ','w','w','w','w','w','w',' ','w','w','w','w','w','w',' ','e'},
{'e',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','e'},
{'e','b','w',' ',' ','w','w','w','w','w','w','w','w','w','w',' ',' ','w',' ','e'},
{'e',' ','w',' ','w',' ',' ',' ',' ',' ',' ','b',' ',' ','w','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ','w','w','w','w','w','w','w','w',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ',' ',' ',' ','b','w',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ','w',' ','w','w','w','w',' ','w',' ','m',' ','w',' ','e'},
{'e','b','w',' ','w',' ','w',' ','w',' ',' ','w','w','w',' ','w',' ','w',' ','e'},
{'e','w','w',' ','w',' ','m',' ','w',' ','d','w',' ','w',' ','w',' ','w','w','e'},
{'e',' ','w',' ','w',' ','w',' ','w',' ','w','w',' ','w',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ','w',' ',' ','m',' ',' ',' ','w',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ','w','w','w','w','w','w','w','w',' ','w',' ','w',' ','e'},
{'e',' ','w',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','w',' ','e'},
{'e',' ','w',' ',' ','w','w','w','w','w','w','w','w','w','w',' ',' ','w',' ','e'},
{'e',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w',' ','e'},
{'e',' ','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','e'},
{'e',' ',' ',' ','w',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ','e'},
{'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'}
};


//绘制函数区 
void SDL_RenderDrawFilledRect(SDL_Renderer * renderer,int x,int y,int w,int h)
{
	SDL_Rect rect;
	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;
	SDL_RenderFillRect(renderer,&rect);
} 

void SDL_DrawGameEdge(SDL_Renderer * renderer,int x,int y,int w,int h)
{
	for(int a = 0; a <= 55; a += 5)
	{
		for(int b = 0; b <= 54; b += 6)
		{
			SDL_RenderDrawFilledRect(renderer,x+b,y+a,5,4);
		}
	}
}
void SDL_DrawGameEdge2(SDL_Renderer * renderer,int x,int y,int w,int h)
{
	for(int a = 0; a <= 25; a += 5)
	{
		for(int b = 0; b <= 24; b += 6)
		{
			SDL_RenderDrawFilledRect(renderer,x+b,y+a,5,4);
		}
	}
}

void SDL_DrawGameBomb(SDL_Renderer * renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,153,0,204,255);
	SDL_RenderDrawFilledRect(renderer,x+10,y+15,40,40);
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	//左上角 
	SDL_RenderDrawFilledRect(renderer,x+10,y+15,6,6);
	SDL_RenderDrawFilledRect(renderer,x+10,y+21,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10,y+23,2,2);
	SDL_RenderDrawFilledRect(renderer,x+16,y+15,4,2);
	SDL_RenderDrawFilledRect(renderer,x+16,y+17,2,2); 
	//右上角 
	SDL_RenderDrawFilledRect(renderer,x+10+34,y+15,6,6);
	SDL_RenderDrawFilledRect(renderer,x+10+30,y+15,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10+32,y+17,2,2);
	SDL_RenderDrawFilledRect(renderer,x+10+36,y+21,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10+38,y+23,2,2);
	//左下角 
	SDL_RenderDrawFilledRect(renderer,x+10,y+15+34,6,6);
	SDL_RenderDrawFilledRect(renderer,x+10,y+15+32,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10,y+15+30,2,2);
	SDL_RenderDrawFilledRect(renderer,x+16,y+15+38,4,2);
	SDL_RenderDrawFilledRect(renderer,x+16,y+15+36,2,2);
	//右下角 
	SDL_RenderDrawFilledRect(renderer,x+10+40-6,y+15+40-6,6,6);
	SDL_RenderDrawFilledRect(renderer,x+10+40-6+2,y+15+40-6-2,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10+40-6+4,y+15+40-6-4,2,2);
	SDL_RenderDrawFilledRect(renderer,x+10+40-6-4,y+15+40-6+4,4,2);
	SDL_RenderDrawFilledRect(renderer,x+10+40-6-2,y+15+40-6+2,2,2);
	
	SDL_SetRenderDrawColor(renderer,153,0,204,255);
	SDL_RenderDrawFilledRect(renderer,x+26,y+12,8,3);
	
	SDL_SetRenderDrawColor(renderer,102,0,0,255);
	SDL_RenderDrawPoint(renderer,x+27,y+11);
	SDL_RenderDrawPoint(renderer,x+28,y+11);
	SDL_RenderDrawLine(renderer,x+28,y+10,x+30,y+10);
	SDL_RenderDrawPoint(renderer,x+30,y+9);
	SDL_RenderDrawPoint(renderer,x+31,y+9);
	SDL_RenderDrawLine(renderer,x+31,y+8,x+33,y+8);
	SDL_RenderDrawLine(renderer,x+33,y+7,x+37,y+7);
	SDL_RenderDrawLine(renderer,x+34,y+6,x+36,y+6);
	SDL_RenderDrawLine(renderer,x+37,y+8,x+39,y+8);
	SDL_RenderDrawLine(renderer,x+39,y+9,x+41,y+9);
	SDL_RenderDrawLine(renderer,x+41,y+10,x+44,y+10);
	
	SDL_SetRenderDrawColor(renderer,255,255,0,255);
	SDL_RenderDrawLine(renderer,x+43,y+9,x+49,y+9);
	SDL_RenderDrawLine(renderer,x+46,y+6,x+46,y+12);
	SDL_RenderDrawFilledRect(renderer,x+45,y+8,3,3);
}

void SDL_DrawGameBomb2(SDL_Renderer * renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,153,0,204,255);
	SDL_RenderDrawFilledRect(renderer,x+5,y+7,20,20);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderDrawLine(renderer,x+5,y+7,x+10,y+7);
	SDL_RenderDrawLine(renderer,x+5,y+8,x+9,y+8);
	SDL_RenderDrawLine(renderer,x+5,y+9,x+8,y+9);
	SDL_RenderDrawLine(renderer,x+5,y+10,x+7,y+10);
	SDL_RenderDrawLine(renderer,x+5,y+11,x+6,y+11);
	SDL_RenderDrawPoint(renderer,x+5,y+12);
	
	SDL_RenderDrawLine(renderer,x+19,y+7,x+24,y+7);
	SDL_RenderDrawLine(renderer,x+20,y+8,x+24,y+8);
	SDL_RenderDrawLine(renderer,x+21,y+9,x+24,y+9);
	SDL_RenderDrawLine(renderer,x+22,y+10,x+24,y+10);
	SDL_RenderDrawLine(renderer,x+23,y+11,x+24,y+11);
	SDL_RenderDrawPoint(renderer,x+24,y+12);
	
	SDL_RenderDrawLine(renderer,x+5,y+26,x+10,y+26);
	SDL_RenderDrawLine(renderer,x+5,y+25,x+9,y+25);
	SDL_RenderDrawLine(renderer,x+5,y+24,x+8,y+24);
	SDL_RenderDrawLine(renderer,x+5,y+23,x+7,y+23);
	SDL_RenderDrawLine(renderer,x+5,y+22,x+6,y+22);
	SDL_RenderDrawPoint(renderer,x+5,y+21);
	
	SDL_RenderDrawLine(renderer,x+19,y+26,x+24,y+26);
	SDL_RenderDrawLine(renderer,x+20,y+25,x+24,y+25);
	SDL_RenderDrawLine(renderer,x+21,y+24,x+24,y+24);
	SDL_RenderDrawLine(renderer,x+22,y+23,x+24,y+23);
	SDL_RenderDrawLine(renderer,x+23,y+22,x+24,y+22);
	SDL_RenderDrawPoint(renderer,x+24,y+21);
	
	SDL_SetRenderDrawColor(renderer,102,0,0,255);
	SDL_RenderDrawLine(renderer,x+14,y+6,x+19,y+4);
	SDL_RenderDrawLine(renderer,x+19,y+4,x+21,y+6);
	SDL_RenderDrawLine(renderer,x+22,y+6,x+24,y+4);
	
	SDL_SetRenderDrawColor(renderer,255,255,0,255);
	SDL_RenderDrawLine(renderer,x+24,y+3,x+26,y+3);
	SDL_RenderDrawLine(renderer,x+25,y+2,x+25,y+4);
}

void SDL_DrawGameMonster(SDL_Renderer * renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	//头部 
	SDL_RenderDrawLine(renderer,x+25,y+4,x+25,y+5);
	SDL_RenderDrawLine(renderer,x+26,y+5,x+26,y+6);
	SDL_RenderDrawLine(renderer,x+34,y+4,x+34,y+5);
	SDL_RenderDrawLine(renderer,x+33,y+5,x+33,y+6);
	SDL_RenderDrawFilledRect(renderer,x+27,y+6,6,6);
	SDL_RenderDrawFilledRect(renderer,x+28,y+12,4,2);
	
	//身体 
	SDL_RenderDrawFilledRect(renderer,x+26,y+14,8,4);
	SDL_RenderDrawFilledRect(renderer,x+27,y+18,6,10);
	SDL_RenderDrawFilledRect(renderer,x+24,y+28,12,5);
	
	//左手臂
	SDL_RenderDrawFilledRect(renderer,x+22,y+15,4,3);
	SDL_RenderDrawFilledRect(renderer,x+17,y+16,5,3);
	SDL_RenderDrawFilledRect(renderer,x+14,y+17,3,6);
	
	//右手臂
	SDL_RenderDrawFilledRect(renderer,x+34,y+15,4,3);
	SDL_RenderDrawFilledRect(renderer,x+38,y+16,5,3);
	SDL_RenderDrawFilledRect(renderer,x+43,y+17,3,6);
	
	//左腿
	SDL_RenderDrawFilledRect(renderer,x+19,y+33,6,4);
	SDL_RenderDrawFilledRect(renderer,x+19,y+37,4,8);
	SDL_RenderDrawFilledRect(renderer,x+18,y+45,4,6); 
	SDL_RenderDrawFilledRect(renderer,x+13,y+51,9,4);
	
	//右腿 
	SDL_RenderDrawFilledRect(renderer,x+35,y+33,6,4);
	SDL_RenderDrawFilledRect(renderer,x+37,y+37,4,8);
	SDL_RenderDrawFilledRect(renderer,x+38,y+45,4,6); 
	SDL_RenderDrawFilledRect(renderer,x+38,y+51,9,4);
	
	//武器
	SDL_SetRenderDrawColor(renderer,253,77,79,255);
	SDL_RenderDrawLine(renderer,x+44,y+23,x+44,y+27);
	SDL_RenderDrawLine(renderer,x+44,y+11,x+44,y+16);
	SDL_RenderDrawLine(renderer,x+43,y+6,x+43,y+10);
	SDL_RenderDrawLine(renderer,x+44,y+4,x+44,y+5);
	SDL_RenderDrawLine(renderer,x+45,y+4,x+47,y+6); 
}

void SDL_DrawGameMonster2(SDL_Renderer * renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	//头部 
	SDL_RenderDrawLine(renderer,x+11,y+1,x+11,y+2);
	SDL_RenderDrawLine(renderer,x+19,y+1,x+19,y+2);
	SDL_RenderDrawFilledRect(renderer,x+12,y+2,7,2);
	SDL_RenderDrawFilledRect(renderer,x+13,y+4,5,3);
	SDL_RenderDrawFilledRect(renderer,x+14,y+7,3,1);
	
	//身体 
	SDL_RenderDrawFilledRect(renderer,x+8,y+8,15,3);
	SDL_RenderDrawFilledRect(renderer,x+13,y+11,5,4);
	SDL_RenderDrawFilledRect(renderer,x+12,y+15,7,2);
	
	//手臂
	SDL_RenderDrawFilledRect(renderer,x+4,y+9,4,3);
	SDL_RenderDrawFilledRect(renderer,x+23,y+9,4,3);
	
	//左腿
	SDL_RenderDrawFilledRect(renderer,x+10,y+17,4,3);
	SDL_RenderDrawFilledRect(renderer,x+8,y+20,4,6);
	SDL_RenderDrawFilledRect(renderer,x+5,y+26,6,3); 
	
	//右腿 
	SDL_RenderDrawFilledRect(renderer,x+17,y+17,4,3);
	SDL_RenderDrawFilledRect(renderer,x+19,y+20,4,6);
	SDL_RenderDrawFilledRect(renderer,x+20,y+26,6,3);
	
	//武器
	SDL_SetRenderDrawColor(renderer,253,77,79,255);
	SDL_RenderDrawLine(renderer,x+25,y+12,x+25,y+16);
	SDL_RenderDrawLine(renderer,x+25,y+7,x+25,y+8);
	SDL_RenderDrawLine(renderer,x+24,y+5,x+24,y+6);
	SDL_RenderDrawLine(renderer,x+25,y+4,x+26,y+4); 
}



void SDL_DrawGamePlayer(SDL_Renderer * renderer,int x,int y)
{
	//头部
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawFilledRect(renderer,x+26,y+4,8,4);
	SDL_RenderDrawLine(renderer,x+25,y+6,x+25,y+7);
	SDL_RenderDrawLine(renderer,x+34,y+6,x+34,y+7);
	SDL_RenderDrawLine(renderer,x+24,y+7,x+24,y+12);
	SDL_RenderDrawLine(renderer,x+24,y+12,x+26,y+14);
	SDL_RenderDrawLine(renderer,x+26,y+14,x+33,y+14);
	SDL_RenderDrawLine(renderer,x+35,y+7,x+35,y+12);
	SDL_RenderDrawLine(renderer,x+35,y+12,x+33,y+14);
	SDL_RenderDrawLine(renderer,x+25,y+9,x+34,y+9);
	SDL_RenderDrawFilledRect(renderer,x+26,y+10,3,2);
	SDL_RenderDrawFilledRect(renderer,x+31,y+10,3,2);
	
	SDL_SetRenderDrawColor(renderer,255,183,162,255);
	SDL_RenderDrawLine(renderer,x+25,y+8,x+34,y+8);
	SDL_RenderDrawLine(renderer,x+25,y+12,x+34,y+12);
	SDL_RenderDrawLine(renderer,x+26,y+13,x+33,y+13);
	SDL_RenderDrawLine(renderer,x+25,y+10,x+25,y+11);
	SDL_RenderDrawLine(renderer,x+34,y+10,x+34,y+11);
	SDL_RenderDrawFilledRect(renderer,x+29,y+10,2,2);
	
	//上身
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+27,y+15,x+27,y+16);
	SDL_RenderDrawLine(renderer,x+23,y+16,x+27,y+16);
	SDL_RenderDrawLine(renderer,x+21,y+17,x+23,y+17);
	SDL_RenderDrawLine(renderer,x+18,y+18,x+21,y+18);
	SDL_RenderDrawLine(renderer,x+18,y+18,x+18,y+28);
	SDL_RenderDrawLine(renderer,x+18,y+28,x+21,y+28);
	SDL_RenderDrawLine(renderer,x+21,y+25,x+21,y+28);
	SDL_RenderDrawFilledRect(renderer,x+19,y+25,2,2);
	SDL_RenderDrawPoint(renderer,x+22,y+25);
	SDL_RenderDrawFilledRect(renderer,x+23,y+21,2,5);
	SDL_RenderDrawPoint(renderer,x+24,y+20);
	SDL_RenderDrawLine(renderer,x+24,y+26,x+35,y+26);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+32,y+15,x+32,y+16);
	SDL_RenderDrawLine(renderer,x+32,y+16,x+36,y+16);
	SDL_RenderDrawLine(renderer,x+36,y+17,x+38,y+17);
	SDL_RenderDrawLine(renderer,x+38,y+18,x+41,y+18);
	SDL_RenderDrawLine(renderer,x+41,y+18,x+41,y+28);
	SDL_RenderDrawLine(renderer,x+38,y+28,x+41,y+28);
	SDL_RenderDrawLine(renderer,x+38,y+25,x+38,y+28);
	SDL_RenderDrawFilledRect(renderer,x+39,y+25,2,2);
	SDL_RenderDrawPoint(renderer,x+37,y+25);
	SDL_RenderDrawFilledRect(renderer,x+35,y+21,2,5);
	SDL_RenderDrawPoint(renderer,x+35,y+20);
	
	SDL_SetRenderDrawColor(renderer,255,0,0,255);
	SDL_RenderDrawFilledRect(renderer,x+28,y+15,4,2);
	SDL_RenderDrawFilledRect(renderer,x+25,y+17,10,9);
	SDL_RenderDrawFilledRect(renderer,x+19,y+19,4,6);
	SDL_RenderDrawFilledRect(renderer,x+22,y+18,2,3);
	SDL_RenderDrawFilledRect(renderer,x+24,y+17,1,3);
	SDL_RenderDrawFilledRect(renderer,x+37,y+19,4,6);
	SDL_RenderDrawFilledRect(renderer,x+36,y+18,2,3);
	SDL_RenderDrawFilledRect(renderer,x+35,y+17,1,3);
	
	SDL_SetRenderDrawColor(renderer,255,183,162,255);
	SDL_RenderDrawFilledRect(renderer,x+19,y+27,2,1);
	SDL_RenderDrawFilledRect(renderer,x+39,y+27,2,1);
	
	//下身
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+23,y+27,x+36,y+27);
	SDL_RenderDrawLine(renderer,x+23,y+27,x+23,y+33);
	SDL_RenderDrawLine(renderer,x+21,y+33,x+23,y+33);
	SDL_RenderDrawLine(renderer,x+21,y+33,x+21,y+43);
	SDL_RenderDrawLine(renderer,x+21,y+43,x+27,y+43);
	SDL_RenderDrawLine(renderer,x+27,y+32,x+27,y+43);
	SDL_RenderDrawLine(renderer,x+27,y+32,x+32,y+32);
	SDL_RenderDrawLine(renderer,x+32,y+32,x+32,y+43);
	SDL_RenderDrawLine(renderer,x+32,y+43,x+38,y+43);
	SDL_RenderDrawLine(renderer,x+38,y+33,x+38,y+43);
	SDL_RenderDrawLine(renderer,x+36,y+33,x+38,y+33);
	SDL_RenderDrawLine(renderer,x+36,y+27,x+36,y+33);
	
	SDL_SetRenderDrawColor(renderer,27,2,218,255);
	SDL_RenderDrawFilledRect(renderer,x+24,y+28,12,4);
	SDL_RenderDrawFilledRect(renderer,x+24,y+32,3,2);
	SDL_RenderDrawFilledRect(renderer,x+22,y+34,5,9);
	SDL_RenderDrawFilledRect(renderer,x+33,y+32,3,2);
	SDL_RenderDrawFilledRect(renderer,x+33,y+34,5,9);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+19,y+44,x+27,y+44);
	SDL_RenderDrawLine(renderer,x+27,y+44,x+27,y+49);
	SDL_RenderDrawLine(renderer,x+19,y+44,x+19,y+49);
	SDL_RenderDrawLine(renderer,x+19,y+49,x+27,y+49);
	SDL_RenderDrawLine(renderer,x+32,y+44,x+40,y+44);
	SDL_RenderDrawLine(renderer,x+40,y+44,x+40,y+49);
	SDL_RenderDrawLine(renderer,x+32,y+44,x+32,y+49);
	SDL_RenderDrawLine(renderer,x+32,y+49,x+40,y+49);
	
	SDL_SetRenderDrawColor(renderer,153,99,67,255);
	SDL_RenderDrawFilledRect(renderer,x+20,y+45,7,4);
	SDL_RenderDrawFilledRect(renderer,x+33,y+45,7,4);
} 

void SDL_DrawGamePlayer2(SDL_Renderer * renderer,int x,int y)
{
	//头部
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawFilledRect(renderer,x+13,y+2,4,2);
	SDL_RenderDrawLine(renderer,x+12,y+3,x+11,y+4); 
	SDL_RenderDrawLine(renderer,x+11,y+4,x+11,y+8);
	SDL_RenderDrawLine(renderer,x+12,y+9,x+17,y+9);
	SDL_RenderDrawLine(renderer,x+18,y+4,x+18,y+8);
	SDL_RenderDrawLine(renderer,x+12,y+5,x+17,y+5);
	SDL_RenderDrawPoint(renderer,x+13,y+6);
	SDL_RenderDrawPoint(renderer,x+16,y+6);
	
	SDL_SetRenderDrawColor(renderer,255,183,162,255);
	SDL_RenderDrawLine(renderer,x+12,y+4,x+17,y+4);
	SDL_RenderDrawLine(renderer,x+12,y+6,x+12,y+8);
	SDL_RenderDrawLine(renderer,x+13,y+7,x+13,y+8);
	SDL_RenderDrawLine(renderer,x+16,y+7,x+16,y+8);
	SDL_RenderDrawLine(renderer,x+17,y+6,x+17,y+8);
	SDL_RenderDrawFilledRect(renderer,x+14,y+6,2,3);
	
	//上身
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+9,y+10,x+12,y+10);
	SDL_RenderDrawLine(renderer,x+9,y+10,x+7,y+12);
	SDL_RenderDrawLine(renderer,x+7,y+13,x+7,y+14);
	SDL_RenderDrawLine(renderer,x+8,y+14,x+10,y+12);
	SDL_RenderDrawLine(renderer,x+11,y+12,x+11,y+16);
	SDL_RenderDrawLine(renderer,x+11,y+16,x+18,y+16);
	SDL_RenderDrawLine(renderer,x+18,y+12,x+18,y+16);
	SDL_RenderDrawLine(renderer,x+19,y+12,x+21,y+14);
	SDL_RenderDrawLine(renderer,x+22,y+12,x+22,y+14);
	SDL_RenderDrawLine(renderer,x+17,y+10,x+20,y+10);
	
	SDL_SetRenderDrawColor(renderer,255,0,0,255);
	SDL_RenderDrawFilledRect(renderer,x+12,y+11,6,5);
	SDL_RenderDrawLine(renderer,x+13,y+10,x+16,y+10);
	SDL_RenderDrawLine(renderer,x+9,y+11,x+11,y+11);
	SDL_RenderDrawLine(renderer,x+10,y+11,x+8,y+13);
	SDL_RenderDrawLine(renderer,x+9,y+11,x+8,y+12);
	
	SDL_RenderDrawLine(renderer,x+18,y+11,x+20,y+11);
	SDL_RenderDrawLine(renderer,x+19,y+11,x+21,y+13);
	SDL_RenderDrawLine(renderer,x+20,y+11,x+21,y+12);
	
	//下身
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawLine(renderer,x+10,y+11,x+19,y+11);
	SDL_RenderDrawLine(renderer,x+10,y+11,x+10,y+20);
	SDL_RenderDrawLine(renderer,x+9,y+20,x+9,y+24);
	SDL_RenderDrawLine(renderer,x+9,y+24,x+13,y+24);
	SDL_RenderDrawLine(renderer,x+13,y+19,x+13,y+24);
	SDL_RenderDrawLine(renderer,x+13,y+19,x+16,y+19);
	SDL_RenderDrawLine(renderer,x+16,y+19,x+16,y+24);
	SDL_RenderDrawLine(renderer,x+16,y+24,x+20,y+24);
	SDL_RenderDrawLine(renderer,x+20,y+20,x+20,y+24);
	SDL_RenderDrawLine(renderer,x+19,y+17,x+19,y+20);
	
	SDL_RenderDrawLine(renderer,x+8,y+25,x+13,y+25);
	SDL_RenderDrawLine(renderer,x+8,y+25,x+8,y+28);
	SDL_RenderDrawLine(renderer,x+8,y+28,x+13,y+28);
	SDL_RenderDrawLine(renderer,x+13,y+25,x+13,y+28);
	
	SDL_RenderDrawLine(renderer,x+16,y+25,x+21,y+25);
	SDL_RenderDrawLine(renderer,x+16,y+25,x+16,y+28);
	SDL_RenderDrawLine(renderer,x+16,y+28,x+21,y+28);
	SDL_RenderDrawLine(renderer,x+21,y+25,x+21,y+28);
	
	SDL_SetRenderDrawColor(renderer,27,2,218,255);
	SDL_RenderDrawFilledRect(renderer,x+10,y+21,3,3);
	SDL_RenderDrawFilledRect(renderer,x+17,y+21,3,3);
	SDL_RenderDrawFilledRect(renderer,x+11,y+19,2,2);
	SDL_RenderDrawFilledRect(renderer,x+17,y+19,2,2);
	SDL_RenderDrawLine(renderer,x+11,y+18,x+18,y+18);
	
	SDL_SetRenderDrawColor(renderer,153,99,67,255);
	SDL_RenderDrawFilledRect(renderer,x+9,y+26,4,2);
	SDL_RenderDrawFilledRect(renderer,x+17,y+26,4,2);
} 

void SDL_DrawGameMap1(SDL_Renderer * renderer,char map[10][10])
{
	//SDL_RenderDrawFilledRect(,,,);
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(map[i][j] == 'e' || map[i][j] == 'w') 
			{
				SDL_SetRenderDrawColor(renderer,150,50,50,255);
				SDL_DrawGameEdge(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map[i][j] == 'd') 
			{
				SDL_SetRenderDrawColor(renderer,245,222,179,255);
				SDL_RenderDrawFilledRect(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map[i][j] == 'b')
			{
				SDL_DrawGameBomb(renderer,100+j*60,100+i*60);
			}
			else if(map[i][j] == 'm')
			{
				SDL_DrawGameMonster(renderer,100+j*60,100+i*60);
			}
			else if(map[i][j] == '*')
			{
				SDL_DrawGamePlayer(renderer,100+j*60,100+i*60);
			}
		}
	}
}

void SDL_DrawGameMap2(SDL_Renderer * renderer,char map[11][11])
{
	//SDL_RenderDrawFilledRect(,,,);
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(map[i-1][j-1] == 'e' || map[i-1][j-1] == 'w') 
			{
				SDL_SetRenderDrawColor(renderer,150,50,50,255);
				SDL_DrawGameEdge(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map[i-1][j-1] == 'd') 
			{
				SDL_SetRenderDrawColor(renderer,245,222,179,255);
				SDL_RenderDrawFilledRect(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map[i-1][j-1] == 'b')
			{
				SDL_DrawGameBomb(renderer,100+j*60,100+i*60);
			}
			else if(map[i-1][j-1] == 'm')
			{
				SDL_DrawGameMonster(renderer,100+j*60,100+i*60);
			}
			else if(map[i-1][j-1] == '*')
			{
				SDL_DrawGamePlayer(renderer,100+j*60,100+i*60);
			}
		}
	}
}

void SDL_DrawGameMap3(SDL_Renderer * renderer,char map[16][16])
{
	//SDL_RenderDrawFilledRect(,,,);
	for(int i = 1; i <= 15; ++i)
	{
		for(int j = 1; j <= 15; ++j)
		{
			if(map[i-1][j-1] == 'e' || map[i-1][j-1] == 'w') 
			{
				SDL_SetRenderDrawColor(renderer,150,50,50,255);
				SDL_DrawGameEdge2(renderer,100+j*30,100+i*30,30,30);
			}
			else if(map[i-1][j-1] == 'd') 
			{
				SDL_SetRenderDrawColor(renderer,245,222,179,255);
				SDL_RenderDrawFilledRect(renderer,100+j*30,100+i*30,30,30);
			}
			else if(map[i-1][j-1] == 'b')
			{
				SDL_DrawGameBomb2(renderer,100+j*30,100+i*30);
			}
			else if(map[i-1][j-1] == 'm')
			{
				SDL_DrawGameMonster2(renderer,100+j*30,100+i*30);
			}
			else if(map[i-1][j-1] == '*')
			{
				SDL_DrawGamePlayer2(renderer,100+j*30,100+i*30);
			}
		}
	}
}

void SDL_DrawGameMap4(SDL_Renderer * renderer,char map[21][21])
{
	//SDL_RenderDrawFilledRect(,,,);
	for(int i = 1; i <= 20; ++i)
	{
		for(int j = 1; j <= 20; ++j)
		{
			if(map[i-1][j-1] == 'e' || map[i-1][j-1] == 'w') 
			{
				SDL_SetRenderDrawColor(renderer,150,50,50,255);
				SDL_DrawGameEdge2(renderer,50+j*30,50+i*30,30,30);
			}
			else if(map[i-1][j-1] == 'd') 
			{
				SDL_SetRenderDrawColor(renderer,245,222,179,255);
				SDL_RenderDrawFilledRect(renderer,50+j*30,50+i*30,30,30);
			}
			else if(map[i-1][j-1] == 'b')
			{
				SDL_DrawGameBomb2(renderer,50+j*30,50+i*30);
			}
			else if(map[i-1][j-1] == 'm')
			{
				SDL_DrawGameMonster2(renderer,50+j*30,50+i*30);
			}
			else if(map[i-1][j-1] == '*')
			{
				SDL_DrawGamePlayer2(renderer,50+j*30,50+i*30);
			}
		}
	}
}







//init区 



void init0101()
{
	for(int i = 1; i <= 8; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0101[i][j] = ' ';
			if(i == 1 || j == 1) map0101[i][j] = 'e';
			if(i == 8 || j == 10) map0101[i][j] = 'e';
			if(i == 7 && j == 10) map0101[i][j] = 'd';
		}
	map0101[2][2] = '*';
}

void init0102()
{
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0102[i][j] = ' ';
			if(i >= 3 && j == 4) map0102[i][j] = 'w';
			if(i <= 8 && j == 7) map0102[i][j] = 'w';
			if(i == 1 || j == 1) map0102[i][j] = 'e';
			if(i == 10 || j == 10) map0102[i][j] = 'e';
			if(i == 2 && j == 10) map0102[i][j] = 'd';
		}
	map0102[2][2] = '*';
}

void init0103()
{
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0103[i][j] = ' ';
			if(i == 4 && j >= 3) map0103[i][j] = 'w';
			if(i == 7 && j <= 8) map0103[i][j] = 'w';
			if(i == 1 || j == 1) map0103[i][j] = 'e';
			if(i == 10 || j == 10) map0103[i][j] = 'e';
			if(i == 9 && j == 1) map0103[i][j] = 'd';
		}
	map0103[2][2] = '*';
}

void init0201()
{
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0201[i][j] = ' ';
			if(i == j) map0201[i][j] = 'w';
			if(i == 6 && j <= 3) map0201[i][j] = 'w';
			if(i == 8 && j <= 5) map0201[i][j] = 'w';
			if(i == 1 || j == 1) map0201[i][j] = 'e';
			if(i == 10 || j == 10) map0201[i][j] = 'e';
			if(i == 9 && j == 10) map0201[i][j] = 'd';
			map0201[9][9] = ' ';
		}
	map0201[2][2] = '*';
}

void init0202()
{
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0202[i][j] = ' ';
			if(i == 3) 
			{
				if(j == 3 || j >= 5) map0202[i][j] = 'w';
			}
			if(i == 4) 
			{
				if(j == 3 || j >= 8) map0202[i][j] = 'w';
			}
			if(i == 5) 
			{
				if(j >= 3 && j <= 8) map0202[i][j] = 'w';
			}
			if(i == 6) 
			{
				if(j == 8) map0202[i][j] = 'w';
			}
			if(i == 7) 
			{
				if(j == 6 || j >= 8) map0202[i][j] = 'w';
				else if(j >= 2 && j <= 3) map0202[i][j] = 'w';
			}
			if(i == 8) 
			{
				if(j == 6 || j >= 8) map0202[i][j] = 'w';
			}
			if(i == 9) 
			{
				if(j >= 2 && j <= 6) map0202[i][j] = 'w';
			}
			if(i == 1 || j == 1) map0202[i][j] = 'e';
			if(i == 10 || j == 10) map0202[i][j] = 'e';
			if(i == 9 && j == 10) map0202[i][j] = 'd';
			map0202[9][9] = ' ';
		}
	map0202[2][2] = '*';
}

void init0203()
{
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
		{
			map0203[i][j] = ' ';
			if(i == j) map0203[i][j] = 'w';
			if(i + j == 11) map0203[i][j] = 'w';
			if(i == 8 && j == 9) map0203[i][j] = 'w';
			if(i == 2 && j == 2) map0203[i][j] = ' ';
			if(i == 2 && j == 9) map0203[i][j] = ' ';
			if(i == 6 && j == 6) map0203[i][j] = ' ';
			if(i == 9 && j == 9) map0203[i][j] = ' ';
			if(i == 1 || j == 1) map0203[i][j] = 'e';
			if(i == 10 || j == 10) map0203[i][j] = 'e';
			if(i == 9 && j == 10) map0203[i][j] = 'd';
		}
	map0203[2][2] = '*';
}

void init0301()
{
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			map0301[i][j] = ' ';
			if(i == 3) map0301[i][j] = 'w';
			if(i == 6) map0301[i][j] = 'w';
			if(j == 4) map0301[i][j] = 'w';
			if(i == 8 && j > 5) map0301[i][j] = 'w';
			if(i == 7 && j == 8) map0301[i][j] = 'w';
			if(i == 1 || j == 1) map0301[i][j] = 'e';
			if(i == 10 || j == 10) map0301[i][j] = 'e';
			if(i == 9 && j == 10) map0301[i][j] = 'd';
			if(i == 3 && j == 2) map0301[i][j] = ' ';
			if(i == 6 && j == 7) map0301[i][j] = ' ';
			if(i == 5 && j == 4) map0301[i][j] = ' ';
		}
	}
	map0301[2][2] = '*';
}

void init0302()
{
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			map0302[i][j] = ' ';
			if(i == 4) map0302[i][j] = 'w';
			if(i == 7) map0302[i][j] = 'w';
			if(j == 5) map0302[i][j] = 'w';
			if(j == 8) map0302[i][j] = 'w';
			if(i == 1 || j == 1) map0302[i][j] = 'e';
			if(i == 10 || j == 10) map0302[i][j] = 'e';
			if(i == 9 && j == 10) map0302[i][j] = 'd';
			if(i == 4 && j == 3) map0302[i][j] = ' ';
			if(i == 7 && j == 3) map0302[i][j] = ' ';
			if(i == 8 && j == 5) map0302[i][j] = ' ';
			if(i == 9 && j == 8) map0302[i][j] = ' ';
		}
	}
	map0302[2][2] = '*';
}

void init0303()
{
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			map0303[i][j] = ' ';
			if(i == 3 && j != 2 && j != 9) map0303[i][j] = 'w';
			if(j == 3 && i != 2 && i != 7) map0303[i][j] = 'w';
			if(i == 9 && j >= 2 && j <= 6) map0303[i][j] = 'w';
			if(j == 8 && i >= 2 && i <= 8) map0303[i][j] = 'w';
			if(i == 8 && j == 9) map0303[i][j] = 'w';
			if(i == 7 && j == 6) map0303[i][j] = 'w';
			if(i == 7 && j == 7) map0303[i][j] = 'w';
			if(i == 1 || j == 1) map0303[i][j] = 'e';
			if(i == 10 || j == 10) map0303[i][j] = 'e';
			if(i == 9 && j == 10) map0303[i][j] = 'd';
			if(i == 2 && j == 8) map0303[i][j] = ' ';
		}
	}
	map0303[2][2] = '*';
}








//主函数区 

void drawing0101()
{
	//SDL_RenderDrawFilledRect(,,,);
	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(map0101[i][j] == 'e' || map0101[i][j] == 'w') 
			{
				SDL_SetRenderDrawColor(renderer,150,50,50,255);
				SDL_DrawGameEdge(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map0101[i][j] == 'd') 
			{
				SDL_SetRenderDrawColor(renderer,245,222,179,255);
				SDL_RenderDrawFilledRect(renderer,100+j*60,100+i*60,60,60);
			}
			else if(map0101[i][j] == '*')
			{
				SDL_DrawGamePlayer(renderer,100+j*60,100+i*60);
			}
		}
	}
}
int main( int argc, char* args[]) 
{
	SDL_Event gp_event;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game",100,100,640,480,SDL_WINDOW_MAXIMIZED);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);
	while(goal!=27)
	{
		if(goal==0)
		{
			//map0101
			p_r = 2;
			p_l = 2;
			init0101();
			drawing0101();
			SDL_RenderPresent(renderer);
			while(map0101[7][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0101[7][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0101[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0101[p_r+1][p_l] == 'w' || map0101[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0101[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								drawing0101();
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0101[p_r-1][p_l] == 'w' || map0101[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0101[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								drawing0101();
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0101[p_r][p_l+1] == 'w' || map0101[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0101[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								drawing0101();
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0101[p_r][p_l-1] == 'w' || map0101[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0101[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								drawing0101();
								SDL_RenderPresent(renderer);
							}
					}
				} 
				drawing0101();
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==1)
		{
			//map0102
			p_r = 2;
			p_l = 2;
			init0102();
			SDL_DrawGameMap1(renderer,map0102);
			SDL_RenderPresent(renderer);
			while(map0102[2][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0102[2][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0102[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0102[p_r+1][p_l] == 'w' || map0102[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0102[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0102);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0102[p_r-1][p_l] == 'w' || map0102[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0102[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0102);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0102[p_r][p_l+1] == 'w' || map0102[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0102[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0102);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0102[p_r][p_l-1] == 'w' || map0102[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0102[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0102);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0102);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==2)
		{
			//map0103
			p_r = 2;
			p_l = 2;
			init0103();
			SDL_DrawGameMap1(renderer,map0103);
			SDL_RenderPresent(renderer);
			while(map0103[9][2]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0103[9][2]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0103[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0103[p_r+1][p_l] == 'w' || map0103[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0103[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0103);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0103[p_r-1][p_l] == 'w' || map0103[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0103[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0103);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0103[p_r][p_l+1] == 'w' || map0103[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0103[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0103);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0103[p_r][p_l-1] == 'w' || map0103[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0103[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0103);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0103);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==3)
		{
			//map0201
			p_r = 2;
			p_l = 2;
			init0201();
			SDL_DrawGameMap1(renderer,map0201);
			SDL_RenderPresent(renderer);
			while(map0201[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0201[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0201[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0201[p_r+1][p_l] == 'w' || map0201[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0201[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0201);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0201[p_r-1][p_l] == 'w' || map0201[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0201[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0201);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0201[p_r][p_l+1] == 'w' || map0201[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0201[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0201);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0201[p_r][p_l-1] == 'w' || map0201[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0201[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0201);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0201);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==4)
		{
			//map0202
			p_r = 2;
			p_l = 2;
			init0202();
			SDL_DrawGameMap1(renderer,map0202);
			SDL_RenderPresent(renderer);
			while(map0202[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0202[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0202[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0202[p_r+1][p_l] == 'w' || map0202[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0202[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0202);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0202[p_r-1][p_l] == 'w' || map0202[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0202[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0202);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0202[p_r][p_l+1] == 'w' || map0202[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0202[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0202);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0202[p_r][p_l-1] == 'w' || map0202[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0202[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0202);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0202);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer);
			goal++; 
		}
		else if(goal==5)
		{
			//map0203
			p_r = 2;
			p_l = 2;
			init0203();
			SDL_DrawGameMap1(renderer,map0203);
			SDL_RenderPresent(renderer);
			while(map0203[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0203[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0203[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0203[p_r+1][p_l] == 'w' || map0203[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0203[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0203);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0203[p_r-1][p_l] == 'w' || map0203[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0203[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0203);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0203[p_r][p_l+1] == 'w' || map0203[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0203[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0203);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0203[p_r][p_l-1] == 'w' || map0203[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0203[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0203);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0203);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==6)
		{
				//map0301
			p_r = 2;
			p_l = 2;
			init0301();
			SDL_DrawGameMap1(renderer,map0301);
			SDL_RenderPresent(renderer);
			while(map0301[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0301[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0301[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0301[p_r+1][p_l] == 'w' || map0301[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0301[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0301);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0301[p_r-1][p_l] == 'w' || map0301[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0301[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0301);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0301[p_r][p_l+1] == 'w' || map0301[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0301[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0301);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0301[p_r][p_l-1] == 'w' || map0301[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0301[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0301);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0301);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==7)
		{
			//map0302
			p_r = 2;
			p_l = 2;
			init0302();
			SDL_DrawGameMap1(renderer,map0302);
			SDL_RenderPresent(renderer);
			while(map0302[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0302[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0302[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0302[p_r+1][p_l] == 'w' || map0302[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0302[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0302);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0302[p_r-1][p_l] == 'w' || map0302[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0302[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0302);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0302[p_r][p_l+1] == 'w' || map0302[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0302[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0302);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0302[p_r][p_l-1] == 'w' || map0302[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0302[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0302);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0302);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==8)
		{
			//map0303
			p_r = 2;
			p_l = 2;
			init0303();
			SDL_DrawGameMap1(renderer,map0303);
			SDL_RenderPresent(renderer);
			while(map0303[9][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0303[9][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0303[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0303[p_r+1][p_l] == 'w' || map0303[p_r+1][p_l] == 'e') continue;
								else p_r+=1;
								map0303[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0303);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0303[p_r-1][p_l] == 'w' || map0303[p_r-1][p_l] == 'e') continue;
								else p_r--;
								map0303[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0303);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0303[p_r][p_l+1] == 'w' || map0303[p_r][p_l+1] == 'e') continue;
								else p_l++;
								map0303[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0303);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0303[p_r][p_l-1] == 'w' || map0303[p_r][p_l-1] == 'e') continue;
								else p_l--;
								map0303[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap1(renderer,map0303);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap1(renderer,map0303);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==9)
		{
			//map0401
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0401);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0401[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0401[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0401[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0401[p_r+1][p_l] == 'w' || map0401[p_r+1][p_l] == 'e') continue;
								else if(map0401[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0401[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0401[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0401);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0401[p_r-1][p_l] == 'w' || map0401[p_r-1][p_l] == 'e') continue;
								else if(map0401[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0401[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0401[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0401);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0401[p_r][p_l+1] == 'w' || map0401[p_r][p_l+1] == 'e') continue;
								else if(map0401[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0401[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0401[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0401);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0401[p_r][p_l-1] == 'w' || map0401[p_r][p_l-1] == 'e') continue;
								else if(map0401[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0401[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0401[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0401);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0401);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==10)
		{
			//map0402
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0402);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0402[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0402[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0402[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0402[p_r+1][p_l] == 'w' || map0402[p_r+1][p_l] == 'e') continue;
								else if(map0402[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0402[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0402[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0402);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0402[p_r-1][p_l] == 'w' || map0402[p_r-1][p_l] == 'e') continue;
								else if(map0402[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0402[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0402[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0402);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0402[p_r][p_l+1] == 'w' || map0402[p_r][p_l+1] == 'e') continue;
								else if(map0402[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0402[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0402[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0402);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0402[p_r][p_l-1] == 'w' || map0402[p_r][p_l-1] == 'e') continue;
								else if(map0402[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0402[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0402[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0402);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0402);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==11)
		{
			//map0403
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0403);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0403[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0403[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0403[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0403[p_r+1][p_l] == 'w' || map0403[p_r+1][p_l] == 'e') continue;
								else if(map0403[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0403[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0403[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0403);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0403[p_r-1][p_l] == 'w' || map0403[p_r-1][p_l] == 'e') continue;
								else if(map0403[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0403[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0403[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0403);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0403[p_r][p_l+1] == 'w' || map0403[p_r][p_l+1] == 'e') continue;
								else if(map0403[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0403[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0403[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0403);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0403[p_r][p_l-1] == 'w' || map0403[p_r][p_l-1] == 'e') continue;
								else if(map0403[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0403[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0403[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0403);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0403);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==12)
		{
			//map0501
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0501);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0501[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0501[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0501[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0501[p_r+1][p_l] == 'w' || map0501[p_r+1][p_l] == 'e') continue;
								else if(map0501[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0501[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0501[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0501);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0501[p_r-1][p_l] == 'w' || map0501[p_r-1][p_l] == 'e') continue;
								else if(map0501[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0501[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0501[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0501);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0501[p_r][p_l+1] == 'w' || map0501[p_r][p_l+1] == 'e') continue;
								else if(map0501[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0501[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0501[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0501);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0501[p_r][p_l-1] == 'w' || map0501[p_r][p_l-1] == 'e') continue;
								else if(map0501[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0501[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0501[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0501);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0501);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer);
			goal++; 
		}
		else if(goal==13)
		{
			//map0502
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0502);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0502[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0502[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0502[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0502[p_r+1][p_l] == 'w' || map0502[p_r+1][p_l] == 'e') continue;
								else if(map0502[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0502[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0502[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0502);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0502[p_r-1][p_l] == 'w' || map0502[p_r-1][p_l] == 'e') continue;
								else if(map0502[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0502[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0502[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0502);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0502[p_r][p_l+1] == 'w' || map0502[p_r][p_l+1] == 'e') continue;
								else if(map0502[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0502[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0502[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0502);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0502[p_r][p_l-1] == 'w' || map0502[p_r][p_l-1] == 'e') continue;
								else if(map0502[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0502[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0502[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0502);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0502);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==14)
		{
			//map0503
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap2(renderer,map0503);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0503[8][8]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0503[8][8]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0503[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0503[p_r+1][p_l] == 'w' || map0503[p_r+1][p_l] == 'e') continue;
								else if(map0503[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0503[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0503[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0503);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0503[p_r-1][p_l] == 'w' || map0503[p_r-1][p_l] == 'e') continue;
								else if(map0503[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0503[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0503[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0503);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0503[p_r][p_l+1] == 'w' || map0503[p_r][p_l+1] == 'e') continue;
								else if(map0503[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0503[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0503[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0503);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0503[p_r][p_l-1] == 'w' || map0503[p_r][p_l-1] == 'e') continue;
								else if(map0503[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0503[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0503[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap2(renderer,map0503);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap2(renderer,map0503);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==15)
		{
			//map0601
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0601);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0601[13][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0601[13][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0601[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0601[p_r+1][p_l] == 'w' || map0601[p_r+1][p_l] == 'e') continue;
								else if(map0601[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0601[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0601[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0601);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0601[p_r-1][p_l] == 'w' || map0601[p_r-1][p_l] == 'e') continue;
								else if(map0601[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0601[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0601[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0601);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0601[p_r][p_l+1] == 'w' || map0601[p_r][p_l+1] == 'e') continue;
								else if(map0601[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0601[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0601[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0601);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0601[p_r][p_l-1] == 'w' || map0601[p_r][p_l-1] == 'e') continue;
								else if(map0601[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0601[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0601[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0601);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0601);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==16)
		{
			//map0602
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0602);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0602[13][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0602[13][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0602[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0602[p_r+1][p_l] == 'w' || map0602[p_r+1][p_l] == 'e') continue;
								else if(map0602[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0602[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0602[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0602);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0602[p_r-1][p_l] == 'w' || map0602[p_r-1][p_l] == 'e') continue;
								else if(map0602[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0602[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0602[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0602);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0602[p_r][p_l+1] == 'w' || map0602[p_r][p_l+1] == 'e') continue;
								else if(map0602[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0602[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0602[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0602);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0602[p_r][p_l-1] == 'w' || map0602[p_r][p_l-1] == 'e') continue;
								else if(map0602[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0602[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0602[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0602);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0602);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==17)
		{
			//map0603
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0603);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0603[13][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0603[13][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0603[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0603[p_r+1][p_l] == 'w' || map0603[p_r+1][p_l] == 'e') continue;
								else if(map0603[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0603[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0603[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0603);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0603[p_r-1][p_l] == 'w' || map0603[p_r-1][p_l] == 'e') continue;
								else if(map0603[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0603[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0603[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0603);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0603[p_r][p_l+1] == 'w' || map0603[p_r][p_l+1] == 'e') continue;
								else if(map0603[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0603[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0603[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0603);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0603[p_r][p_l-1] == 'w' || map0603[p_r][p_l-1] == 'e') continue;
								else if(map0603[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0603[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0603[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0603);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0603);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer);
			goal++; 
		}
		else if(goal==18)
		{
			//map0701
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0701);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0701[13][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0701[13][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0701[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0701[p_r+1][p_l] == 'w' || map0701[p_r+1][p_l] == 'e') continue;
								else if(map0701[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0701[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0701[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0701);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0701[p_r-1][p_l] == 'w' || map0701[p_r-1][p_l] == 'e') continue;
								else if(map0701[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0701[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0701[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0701);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0701[p_r][p_l+1] == 'w' || map0701[p_r][p_l+1] == 'e') continue;
								else if(map0701[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0701[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0701[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0701);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0701[p_r][p_l-1] == 'w' || map0701[p_r][p_l-1] == 'e') continue;
								else if(map0701[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0701[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0701[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0701);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0701);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==19)
		{
			
			//map0702
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0702);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0702[13][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0702[13][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0702[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0702[p_r+1][p_l] == 'w' || map0702[p_r+1][p_l] == 'e') continue;
								else if(map0702[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0702[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0702[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0702);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0702[p_r-1][p_l] == 'w' || map0702[p_r-1][p_l] == 'e') continue;
								else if(map0702[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0702[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0702[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0702);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0702[p_r][p_l+1] == 'w' || map0702[p_r][p_l+1] == 'e') continue;
								else if(map0702[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0702[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0702[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0702);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0702[p_r][p_l-1] == 'w' || map0702[p_r][p_l-1] == 'e') continue;
								else if(map0702[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0702[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0702[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0702);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0702);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==20)
		{
			//map0703
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap3(renderer,map0703);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0703[1][13]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0703[1][13]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0703[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0703[p_r+1][p_l] == 'w' || map0703[p_r+1][p_l] == 'e') continue;
								else if(map0703[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0703[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0703[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0703);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0703[p_r-1][p_l] == 'w' || map0703[p_r-1][p_l] == 'e') continue;
								else if(map0703[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0703[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0703[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0703);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0703[p_r][p_l+1] == 'w' || map0703[p_r][p_l+1] == 'e') continue;
								else if(map0703[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0703[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0703[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0703);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0703[p_r][p_l-1] == 'w' || map0703[p_r][p_l-1] == 'e') continue;
								else if(map0703[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0703[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0703[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap3(renderer,map0703);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap3(renderer,map0703);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==21)
		{
			//map0801
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0801);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0801[18][18]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0801[18][18]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0801[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0801[p_r+1][p_l] == 'w' || map0801[p_r+1][p_l] == 'e') continue;
								else if(map0801[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0801[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0801[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0801);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0801[p_r-1][p_l] == 'w' || map0801[p_r-1][p_l] == 'e') continue;
								else if(map0801[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0801[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0801[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0801);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0801[p_r][p_l+1] == 'w' || map0801[p_r][p_l+1] == 'e') continue;
								else if(map0801[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0801[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0801[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0801);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0801[p_r][p_l-1] == 'w' || map0801[p_r][p_l-1] == 'e') continue;
								else if(map0801[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0801[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0801[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0801);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0801);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==22)
		{
			//map0802
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0802);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0802[18][18]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0802[18][18]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0802[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0802[p_r+1][p_l] == 'w' || map0802[p_r+1][p_l] == 'e') continue;
								else if(map0802[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0802[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0802[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0802);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0802[p_r-1][p_l] == 'w' || map0802[p_r-1][p_l] == 'e') continue;
								else if(map0802[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0802[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0802[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0802);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0802[p_r][p_l+1] == 'w' || map0802[p_r][p_l+1] == 'e') continue;
								else if(map0802[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0802[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0802[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0802);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0802[p_r][p_l-1] == 'w' || map0802[p_r][p_l-1] == 'e') continue;
								else if(map0802[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0802[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0802[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0802);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0802);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==23)
		{
			//map0803
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0803);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0803[15][4]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0803[15][4]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0803[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0803[p_r+1][p_l] == 'w' || map0803[p_r+1][p_l] == 'e') continue;
								else if(map0803[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0803[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0803[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0803);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0803[p_r-1][p_l] == 'w' || map0803[p_r-1][p_l] == 'e') continue;
								else if(map0803[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0803[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0803[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0803);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0803[p_r][p_l+1] == 'w' || map0803[p_r][p_l+1] == 'e') continue;
								else if(map0803[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0803[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0803[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0803);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0803[p_r][p_l-1] == 'w' || map0803[p_r][p_l-1] == 'e') continue;
								else if(map0803[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0803[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0803[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0803);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0803);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==24)
		{
			//map0901
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0901);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0901[18][18]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0901[18][18]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0901[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0901[p_r+1][p_l] == 'w' || map0901[p_r+1][p_l] == 'e') continue;
								else if(map0901[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0901[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0901[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0901);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0901[p_r-1][p_l] == 'w' || map0901[p_r-1][p_l] == 'e') continue;
								else if(map0901[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0901[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0901[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0901);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0901[p_r][p_l+1] == 'w' || map0901[p_r][p_l+1] == 'e') continue;
								else if(map0901[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0901[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0901[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0901);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0901[p_r][p_l-1] == 'w' || map0901[p_r][p_l-1] == 'e') continue;
								else if(map0901[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0901[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0901[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0901);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0901);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==25)
		{
			//map0902
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0902);
			SDL_RenderPresent(renderer);
			bomb = 0;
			while(map0902[18][18]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0902[18][18]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0902[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								if(map0902[p_r+1][p_l] == 'w' || map0902[p_r+1][p_l] == 'e') continue;
								else if(map0902[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0902[p_r+1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r++;
									}
									else continue;
								}
								else p_r+=1;
								map0902[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0902);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0902[p_r-1][p_l] == 'w' || map0902[p_r-1][p_l] == 'e') continue;
								else if(map0902[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0902[p_r-1][p_l] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_r--;
									}
									else continue;
								}
								else p_r--;
								map0902[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0902);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0902[p_r][p_l+1] == 'w' || map0902[p_r][p_l+1] == 'e') continue;
								else if(map0902[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0902[p_r][p_l+1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l++;
									}
									else continue;
								}
								else p_l++;
								map0902[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0902);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0902[p_r][p_l-1] == 'w' || map0902[p_r][p_l-1] == 'e') continue;
								else if(map0902[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0902[p_r][p_l-1] == 'm')
								{
									if(bomb >= 1)
									{
										bomb--;
										p_l--;
									}
									else continue;
								}
								else p_l--;
								map0902[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0902);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0902);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
		else if(goal==26)
		{
			//map0903
			bomb = 0; 
			p_r = 1;
			p_l = 1;
			SDL_DrawGameMap4(renderer,map0903);
			SDL_RenderPresent(renderer);
			while(map0903[10][9]!='*')
			{
				while(SDL_WaitEvent(&gp_event))
				{
					if(map0903[10][9]=='*') break;
					SDL_RenderPresent(renderer);
					switch(gp_event.type)
					{
						case SDL_KEYDOWN:
							map0903[p_r][p_l] = ' ';
							if(gp_event.key.keysym.sym == SDLK_s)
							{
								map0903[p_r][p_l] = ' ';
								if(map0903[p_r+1][p_l] == 'w' || map0903[p_r+1][p_l] == 'e') continue;
								else if(map0903[p_r+1][p_l] == 'b') 
								{
									bomb++;
									p_r++;
								}
								else if(map0903[p_r+1][p_l] == 'm')
								{
									if(bomb == 0) continue;
									else
									{
										bomb--;
										map0601[p_r+1][p_l] = ' ';
										p_r++;
									}
								}
								else p_r+=1;
								map0903[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0903);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_w)
							{
								if(map0903[p_r-1][p_l] == 'w' || map0903[p_r-1][p_l] == 'e') continue;
								else if(map0903[p_r-1][p_l] == 'b') 
								{
									bomb++;
									p_r--;
								}
								else if(map0903[p_r-1][p_l] == 'm')
								{
									if(bomb == 0) continue;
									else
									{
										bomb--;
										map0601[p_r-1][p_l] = ' ';
										p_r--;
									}
								}
								else p_r--;
								map0903[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0903);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_d)
							{
								if(map0903[p_r][p_l+1] == 'w' || map0903[p_r][p_l+1] == 'e') continue;
								else if(map0903[p_r][p_l+1] == 'b') 
								{
									bomb++;
									p_l++;
								}
								else if(map0903[p_r][p_l+1] == 'm')
								{
									if(bomb == 0) continue;
									else
									{
										bomb--;
										map0601[p_r][p_l+1] = ' ';
										p_l++;
									}
								}
								else p_l++;
								map0903[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0903);
								SDL_RenderPresent(renderer);
								break;
							}
							else if(gp_event.key.keysym.sym == SDLK_a)
							{
								if(map0903[p_r][p_l-1] == 'w' || map0903[p_r][p_l-1] == 'e') continue;
								else if(map0903[p_r][p_l-1] == 'b') 
								{
									bomb++;
									p_l--;
								}
								else if(map0903[p_r][p_l-1] == 'm')
								{
									if(bomb == 0) continue;
									else
									{
										bomb--;
										map0601[p_r][p_l-1] = ' ';
										p_l--;
									}
								}
								else p_l--;
								map0903[p_r][p_l] = '*';
								SDL_SetRenderDrawColor(renderer,0,0,0,0);
								SDL_RenderClear(renderer);
								SDL_DrawGameMap4(renderer,map0903);
								SDL_RenderPresent(renderer);
							}
					}
				} 
				SDL_DrawGameMap4(renderer,map0903);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
			SDL_RenderClear(renderer); 
			goal++;
		}
	}
		
		
	
	//退出 
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
    return 0;
} 
