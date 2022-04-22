#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int p_r,p_l,bomb;
int choice;
char map0101[9][11], map0102[11][11], map0103[11][11];
char map0201[11][11], map0202[11][11], map0203[11][11];
char map0301[11][11], map0302[11][11], map0303[11][11];

void act1()
{
       for(int i = 1; i <= 8; ++i)
              for(int j = 1; j <= 10; ++j)
              {
                     map0101[i][j] = ' ';
                     if(i == 1 || j == 1) map0101[i][j] = 'e';
                     if(i == 8 || j == 10) map0101[i][j] = 'e';
                     if(i == 7 && j == 10) map0101[i][j] = 'd';
              }
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
       p_r = 2;
       p_l = 2;
       
       while(p_r+1 != 8 || p_l+1 != 10)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl; 
              map0101[p_r][p_l] = '*';
              for(int i = 1; i <= 8; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0101[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0101[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0101[p_r+1][p_l] == 'w' || map0101[p_r+1][p_l] == 'e') continue;
                     else p_r+=1;
              }
              else if(choice == 119)
              {
                     if(map0101[p_r-1][p_l] == 'w' || map0101[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0101[p_r][p_l+1] == 'w' || map0101[p_r][p_l+1] == 'e') continue;
                     else p_l+=1;
              }
              else if(choice == 97)
              {
                     if(map0101[p_r][p_l-1] == 'w' || map0101[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act1();
              else continue;
       }
       cout << "恭喜通过1-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 2 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl; 
              map0102[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0102[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0102[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0102[p_r+1][p_l] == 'w' || map0102[p_r+1][p_l] == 'e') continue;
                     else p_r+=1;
              }
              else if(choice == 119)
              {
                     if(map0102[p_r-1][p_l] == 'w' || map0102[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0102[p_r][p_l+1] == 'w' || map0102[p_r][p_l+1] == 'e') continue;
                     else p_l+=1;
              }
              else if(choice == 97)
              {
                     if(map0102[p_r][p_l-1] == 'w' || map0102[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act1();
              else continue;
       }
       cout << "恭喜通过1-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 9 || p_l != 2)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl; 
              map0103[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0103[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0103[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0103[p_r+1][p_l] == 'w' || map0103[p_r+1][p_l] == 'e') continue;
                     else p_r+=1;
              }
              else if(choice == 119)
              {
                     if(map0103[p_r-1][p_l] == 'w' || map0103[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0103[p_r][p_l+1] == 'w' || map0103[p_r][p_l+1] == 'e') continue;
                     else p_l+=1;
              }
              else if(choice == 97)
              {
                     if(map0103[p_r][p_l-1] == 'w' || map0103[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act1();
              else continue;
       }
       cout << "恭喜通过1-3关，进入World2" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act2()
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
                     map0201[2][2] = ' ';
                     map0201[9][9] = ' ';
              }
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
       p_r = 2;
       p_l = 2;
       while(p_r+1 != 10 || p_l+1 != 10)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl; 
              map0201[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0201[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0201[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0201[p_r+1][p_l] == 'w' || map0201[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0201[p_r-1][p_l] == 'w' || map0201[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0201[p_r][p_l+1] == 'w' || map0201[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0201[p_r][p_l-1] == 'w' || map0201[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act2();
              else continue;
       }
       cout << "恭喜通过2-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 9 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              map0202[p_r][p_l] = '*'; 
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0202[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0202[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0202[p_r+1][p_l] == 'w' || map0202[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0202[p_r-1][p_l] == 'w' || map0202[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0202[p_r][p_l+1] == 'w' || map0202[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0202[p_r][p_l-1] == 'w' || map0202[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act2();
              else continue;
       }
       cout << "恭喜通过2-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 9 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              map0203[p_r][p_l] = '*'; 
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0203[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0203[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0203[p_r+1][p_l] == 'w' || map0203[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0203[p_r-1][p_l] == 'w' || map0203[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0203[p_r][p_l+1] == 'w' || map0203[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0203[p_r][p_l-1] == 'w' || map0203[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act2();
              else continue;
       }
       cout << "恭喜通过2-3关，进入World3" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act3()
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
       p_r = 2;
       p_l = 2;
       while(p_r+1 != 10 || p_l+1 != 10)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              map0301[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0301[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0301[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0301[p_r+1][p_l] == 'w' || map0301[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0301[p_r-1][p_l] == 'w' || map0301[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0301[p_r][p_l+1] == 'w' || map0301[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0301[p_r][p_l-1] == 'w' || map0301[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act3();
              else continue;
       }
       cout << "恭喜通过3-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 9 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              map0302[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0302[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0302[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0302[p_r+1][p_l] == 'w' || map0302[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0302[p_r-1][p_l] == 'w' || map0302[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0302[p_r][p_l+1] == 'w' || map0302[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0302[p_r][p_l-1] == 'w' || map0302[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act3();
              else continue;
       }
       cout << "恭喜通过3-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       p_r = 2;
       p_l = 2;
       while(p_r != 9 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              map0303[p_r][p_l] = '*';
              for(int i = 1; i <= 10; ++i)
              {
                     for(int j = 1; j <= 10; ++j)
                     {
                            cout << map0303[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0303[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0303[p_r+1][p_l] == 'w' || map0303[p_r+1][p_l] == 'e') continue;
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0303[p_r-1][p_l] == 'w' || map0303[p_r-1][p_l] == 'e') continue;
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0303[p_r][p_l+1] == 'w' || map0303[p_r][p_l+1] == 'e') continue;
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0303[p_r][p_l-1] == 'w' || map0303[p_r][p_l-1] == 'e') continue;
                     else p_l--;
              }
              else if(choice == 27) return act3();
              else continue;
       }
       cout << "恭喜通过3-3关，进入World4" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act4()
{
       char map0401[11][11] = {
       {'e','e','e','e','e','e','e','e','e','e'},
       {'e',' ',' ',' ',' ',' ',' ',' ',' ','e'},
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
       {'e',' ',' ',' ',' ','m',' ',' ','b','e'},
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
       {'e',' ',' ',' ','m',' ',' ',' ',' ','e'},
       {'e','b',' ',' ','w',' ',' ',' ',' ','e'},
       {'e',' ',' ',' ','w',' ',' ',' ','b','e'},
       {'e','w','m','w','w',' ',' ',' ',' ','e'},
       {'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
       {'e',' ',' ',' ','w','w','w','m','w','e'},
       {'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
       {'e',' ',' ',' ','w',' ',' ',' ',' ','d'},
       {'e','e','e','e','e','e','e','e','e','e'}
       };
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r+1 != 9 || p_l+1 != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0401[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0401[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0401[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0401[p_r+1][p_l] == 'w' || map0401[p_r+1][p_l] == 'e') continue;
                     if(map0401[p_r+1][p_l] == 'b') bomb++;
                     if(map0401[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0401[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0401[p_r-1][p_l] == 'w' || map0401[p_r-1][p_l] == 'e') continue;
                     if(map0401[p_r-1][p_l] == 'b') bomb++;
                     if(map0401[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0401[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0401[p_r][p_l+1] == 'w' || map0401[p_r][p_l+1] == 'e') continue;
                     if(map0401[p_r][p_l+1] == 'b') bomb++;
                     if(map0401[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0401[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0401[p_r][p_l-1] == 'w' || map0401[p_r][p_l-1] == 'e') continue;
                     if(map0401[p_r][p_l-1] == 'b') bomb++;
                     if(map0401[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0401[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act4();
              else continue;
       }
       cout << "恭喜通过4-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 8 || p_l != 8)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0402[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0402[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0402[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0402[p_r+1][p_l] == 'w' || map0402[p_r+1][p_l] == 'e') continue;
                     if(map0402[p_r+1][p_l] == 'b') bomb++;
                     if(map0402[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0402[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0402[p_r-1][p_l] == 'w' || map0402[p_r-1][p_l] == 'e') continue;
                     if(map0402[p_r-1][p_l] == 'b') bomb++;
                     if(map0402[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0402[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0402[p_r][p_l+1] == 'w' || map0402[p_r][p_l+1] == 'e') continue;
                     if(map0402[p_r][p_l+1] == 'b') bomb++;
                     if(map0402[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0402[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0402[p_r][p_l-1] == 'w' || map0402[p_r][p_l-1] == 'e') continue;
                     if(map0402[p_r][p_l-1] == 'b') bomb++;
                     if(map0402[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0402[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act4();
              else continue;
       }
       cout << "恭喜通过4-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 8 || p_l != 8)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0403[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0403[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0403[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0403[p_r+1][p_l] == 'w' || map0403[p_r+1][p_l] == 'e') continue;
                     if(map0403[p_r+1][p_l] == 'b') bomb++;
                     if(map0403[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0403[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0403[p_r-1][p_l] == 'w' || map0403[p_r-1][p_l] == 'e') continue;
                     if(map0403[p_r-1][p_l] == 'b') bomb++;
                     if(map0403[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0403[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0403[p_r][p_l+1] == 'w' || map0403[p_r][p_l+1] == 'e') continue;
                     if(map0403[p_r][p_l+1] == 'b') bomb++;
                     if(map0403[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0403[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0403[p_r][p_l-1] == 'w' || map0403[p_r][p_l-1] == 'e') continue;
                     if(map0403[p_r][p_l-1] == 'b') bomb++;
                     if(map0403[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0403[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act4();
              else continue;
       }
       cout << "恭喜通过4-3关，进入World5" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act5()
{
       char map0501[11][11] = {
       {'e','e','e','e','e','e','e','e','e','e'},
       {'e',' ',' ',' ','w',' ',' ',' ',' ','e'},
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
       {'e',' ','w',' ','w',' ','b',' ',' ','e'},
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
       {'e',' ',' ',' ',' ',' ',' ',' ','b','e'},
       {'e',' ',' ',' ',' ',' ',' ',' ',' ','e'},
       {'e','w','w',' ','w','w','w','w','w','e'},
       {'e','b','w',' ',' ','w',' ','w',' ','e'},
       {'e',' ','w',' ',' ','w',' ','w',' ','e'},
       {'e',' ','w',' ',' ','w','w','w',' ','e'},
       {'e',' ','m',' ',' ','w',' ',' ',' ','e'},
       {'e',' ','w',' ',' ','m',' ',' ',' ','d'},
       {'e','e','e','e','e','e','e','e','e','e'}
       };
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 8 || p_l != 8)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0501[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0501[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0501[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0501[p_r+1][p_l] == 'w' || map0501[p_r+1][p_l] == 'e') continue;
                     if(map0501[p_r+1][p_l] == 'b') bomb++;
                     if(map0501[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0501[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0501[p_r-1][p_l] == 'w' || map0501[p_r-1][p_l] == 'e') continue;
                     if(map0501[p_r-1][p_l] == 'b') bomb++;
                     if(map0501[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0501[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0501[p_r][p_l+1] == 'w' || map0501[p_r][p_l+1] == 'e') continue;
                     if(map0501[p_r][p_l+1] == 'b') bomb++;
                     if(map0501[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0501[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0501[p_r][p_l-1] == 'w' || map0501[p_r][p_l-1] == 'e') continue;
                     if(map0501[p_r][p_l-1] == 'b') bomb++;
                     if(map0501[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0501[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act5();
              else continue;
       }
       cout << "恭喜通过5-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 8 || p_l != 8)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0502[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0502[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0502[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0502[p_r+1][p_l] == 'w' || map0502[p_r+1][p_l] == 'e') continue;
                     if(map0502[p_r+1][p_l] == 'b') bomb++;
                     if(map0502[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0502[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0502[p_r-1][p_l] == 'w' || map0502[p_r-1][p_l] == 'e') continue;
                     if(map0502[p_r-1][p_l] == 'b') bomb++;
                     if(map0502[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0502[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0502[p_r][p_l+1] == 'w' || map0502[p_r][p_l+1] == 'e') continue;
                     if(map0502[p_r][p_l+1] == 'b') bomb++;
                     if(map0502[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0502[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0502[p_r][p_l-1] == 'w' || map0502[p_r][p_l-1] == 'e') continue;
                     if(map0502[p_r][p_l-1] == 'b') bomb++;
                     if(map0502[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0502[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act5();
              else continue;
       }
       cout << "恭喜通过5-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 8 || p_l != 8)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0503[p_r][p_l] = '*';
              for(int i = 0; i < 10; ++i)
              {
                     for(int j = 0; j < 10; ++j)
                     {
                            cout << map0503[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0503[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0503[p_r+1][p_l] == 'w' || map0503[p_r+1][p_l] == 'e') continue;
                     if(map0503[p_r+1][p_l] == 'b') bomb++;
                     if(map0503[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0503[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0503[p_r-1][p_l] == 'w' || map0503[p_r-1][p_l] == 'e') continue;
                     if(map0503[p_r-1][p_l] == 'b') bomb++;
                     if(map0503[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0503[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0503[p_r][p_l+1] == 'w' || map0503[p_r][p_l+1] == 'e') continue;
                     if(map0503[p_r][p_l+1] == 'b') bomb++;
                     if(map0503[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0503[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0503[p_r][p_l-1] == 'w' || map0503[p_r][p_l-1] == 'e') continue;
                     if(map0503[p_r][p_l-1] == 'b') bomb++;
                     if(map0503[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0503[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27) return act5();
              else continue;
       }
       cout << "恭喜通过5-3关，进入World6" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act6()
{
       char map0601[16][16] = {
       {'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
       {'e',' ',' ',' ','w','w',' ','w','w','w','w',' ',' ',' ','e'},
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
       {'e',' ','w',' ',' ',' ',' ',' ',' ',' ','w',' ',' ',' ','e'},
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
       {'e',' ',' ',' ','w',' ',' ',' ',' ',' ',' ',' ',' ',' ','e'},
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
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 13 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0601[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0601[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0601[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0601[p_r+1][p_l] == 'w' || map0601[p_r+1][p_l] == 'e') continue;
                     if(map0601[p_r+1][p_l] == 'b') bomb++;
                     if(map0601[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0601[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0601[p_r-1][p_l] == 'w' || map0601[p_r-1][p_l] == 'e') continue;
                     if(map0601[p_r-1][p_l] == 'b') bomb++;
                     if(map0601[p_r-1][p_l] == 'm')
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
              }
              else if(choice == 100)
              {
                     if(map0601[p_r][p_l+1] == 'w' || map0601[p_r][p_l+1] == 'e') continue;
                     if(map0601[p_r][p_l+1] == 'b') bomb++;
                     if(map0601[p_r][p_l+1] == 'm')
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
              }
              else if(choice == 97)
              {
                     if(map0601[p_r][p_l-1] == 'w' || map0601[p_r][p_l-1] == 'e') continue;
                     if(map0601[p_r][p_l-1] == 'b') bomb++;
                     if(map0601[p_r][p_l-1] == 'm')
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
              }
              else if(choice == 27)
              {
                     return act6();
              }
              else continue;
       }
       cout << "恭喜通过6-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 13 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0602[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0602[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0602[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0602[p_r+1][p_l] == 'w' || map0602[p_r+1][p_l] == 'e') continue;
                     if(map0602[p_r+1][p_l] == 'b') bomb++;
                     if(map0602[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0602[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0602[p_r-1][p_l] == 'w' || map0602[p_r-1][p_l] == 'e') continue;
                     if(map0602[p_r-1][p_l] == 'b') bomb++;
                     if(map0602[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0602[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0602[p_r][p_l+1] == 'w' || map0602[p_r][p_l+1] == 'e') continue;
                     if(map0602[p_r][p_l+1] == 'b') bomb++;
                     if(map0602[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0602[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0602[p_r][p_l-1] == 'w' || map0602[p_r][p_l-1] == 'e') continue;
                     if(map0602[p_r][p_l-1] == 'b') bomb++;
                     if(map0602[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0602[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act6();
              }
              else continue;
       }
       cout << "恭喜通过6-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 13 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0603[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0603[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0603[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0603[p_r+1][p_l] == 'w' || map0603[p_r+1][p_l] == 'e') continue;
                     if(map0603[p_r+1][p_l] == 'b') bomb++;
                     if(map0603[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0603[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0603[p_r-1][p_l] == 'w' || map0603[p_r-1][p_l] == 'e') continue;
                     if(map0603[p_r-1][p_l] == 'b') bomb++;
                     if(map0603[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0603[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0603[p_r][p_l+1] == 'w' || map0603[p_r][p_l+1] == 'e') continue;
                     if(map0603[p_r][p_l+1] == 'b') bomb++;
                     if(map0603[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0603[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0603[p_r][p_l-1] == 'w' || map0603[p_r][p_l-1] == 'e') continue;
                     if(map0603[p_r][p_l-1] == 'b') bomb++;
                     if(map0603[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0603[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act6();
              }
              else continue;
       }
       cout << "恭喜通过6-3关，进入World7" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act7()
{
       char map0701[16][16] = {
       {'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
       {'e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','e'},
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
       {'e',' ','w','b',' ','w',' ',' ','w',' ',' ','w',' ',' ','e'},
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
       {'e',' ',' ',' ',' ',' ',' ','w',' ',' ',' ',' ',' ','m','d'},
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
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 13 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0701[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0701[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0701[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0701[p_r+1][p_l] == 'w' || map0701[p_r+1][p_l] == 'e') continue;
                     if(map0701[p_r+1][p_l] == 'b') bomb++;
                     if(map0701[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0701[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0701[p_r-1][p_l] == 'w' || map0701[p_r-1][p_l] == 'e') continue;
                     if(map0701[p_r-1][p_l] == 'b') bomb++;
                     if(map0701[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0701[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0701[p_r][p_l+1] == 'w' || map0701[p_r][p_l+1] == 'e') continue;
                     if(map0701[p_r][p_l+1] == 'b') bomb++;
                     if(map0701[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0701[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0701[p_r][p_l-1] == 'w' || map0701[p_r][p_l-1] == 'e') continue;
                     if(map0701[p_r][p_l-1] == 'b') bomb++;
                     if(map0701[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0701[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act7();
              }
              else continue;
       }
       cout << "恭喜通过7-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 13 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0702[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0702[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0702[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0702[p_r+1][p_l] == 'w' || map0702[p_r+1][p_l] == 'e') continue;
                     if(map0702[p_r+1][p_l] == 'b') bomb++;
                     if(map0702[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0702[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0702[p_r-1][p_l] == 'w' || map0702[p_r-1][p_l] == 'e') continue;
                     if(map0702[p_r-1][p_l] == 'b') bomb++;
                     if(map0702[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0702[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0702[p_r][p_l+1] == 'w' || map0702[p_r][p_l+1] == 'e') continue;
                     if(map0702[p_r][p_l+1] == 'b') bomb++;
                     if(map0702[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0702[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0702[p_r][p_l-1] == 'w' || map0702[p_r][p_l-1] == 'e') continue;
                     if(map0702[p_r][p_l-1] == 'b') bomb++;
                     if(map0702[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0702[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act7();
              }
              else continue;
       }
       cout << "恭喜通过7-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 1 || p_l != 13)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0703[p_r][p_l] = '*';
              for(int i = 0; i < 15; ++i)
              {
                     for(int j = 0; j < 15; ++j)
                     {
                            cout << map0703[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0703[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0703[p_r+1][p_l] == 'w' || map0703[p_r+1][p_l] == 'e') continue;
                     if(map0703[p_r+1][p_l] == 'b') bomb++;
                     if(map0703[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0703[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0703[p_r-1][p_l] == 'w' || map0703[p_r-1][p_l] == 'e') continue;
                     if(map0703[p_r-1][p_l] == 'b') bomb++;
                     if(map0703[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0703[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0703[p_r][p_l+1] == 'w' || map0703[p_r][p_l+1] == 'e') continue;
                     if(map0703[p_r][p_l+1] == 'b') bomb++;
                     if(map0703[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0703[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0703[p_r][p_l-1] == 'w' || map0703[p_r][p_l-1] == 'e') continue;
                     if(map0703[p_r][p_l-1] == 'b') bomb++;
                     if(map0703[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0703[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act7();
              }
              else continue;
       }
       cout << "恭喜通过7-3关，进入World8" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act8()
{
       char map0801[21][21] = {
       {'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
       {'e',' ','w','b',' ','w',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ',' ',' ','e'},
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
       {'e',' ',' ',' ',' ',' ','w','w',' ',' ',' ',' ','w','w','w',' ','b',' ','w','e'},
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
       {'e',' ',' ',' ','w','w',' ',' ',' ','w','w',' ',' ',' ','w','w',' ',' ',' ','e'},
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
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 18 || p_l != 18)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0801[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0801[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0801[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0801[p_r+1][p_l] == 'w' || map0801[p_r+1][p_l] == 'e') continue;
                     if(map0801[p_r+1][p_l] == 'b') bomb++;
                     if(map0801[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0801[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0801[p_r-1][p_l] == 'w' || map0801[p_r-1][p_l] == 'e') continue;
                     if(map0801[p_r-1][p_l] == 'b') bomb++;
                     if(map0801[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0801[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0801[p_r][p_l+1] == 'w' || map0801[p_r][p_l+1] == 'e') continue;
                     if(map0801[p_r][p_l+1] == 'b') bomb++;
                     if(map0801[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0801[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0801[p_r][p_l-1] == 'w' || map0801[p_r][p_l-1] == 'e') continue;
                     if(map0801[p_r][p_l-1] == 'b') bomb++;
                     if(map0801[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0801[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act8();
              }
              else continue;
       }
       cout << "恭喜通过8-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 18 || p_l != 18)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0802[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0802[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0802[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0802[p_r+1][p_l] == 'w' || map0802[p_r+1][p_l] == 'e') continue;
                     if(map0802[p_r+1][p_l] == 'b') bomb++;
                     if(map0802[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0802[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0802[p_r-1][p_l] == 'w' || map0802[p_r-1][p_l] == 'e') continue;
                     if(map0802[p_r-1][p_l] == 'b') bomb++;
                     if(map0802[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0802[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0802[p_r][p_l+1] == 'w' || map0802[p_r][p_l+1] == 'e') continue;
                     if(map0802[p_r][p_l+1] == 'b') bomb++;
                     if(map0802[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0802[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0802[p_r][p_l-1] == 'w' || map0802[p_r][p_l-1] == 'e') continue;
                     if(map0802[p_r][p_l-1] == 'b') bomb++;
                     if(map0802[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0802[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act8();
              }
              else continue;
       }
       cout << "恭喜通过8-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 14 || p_l != 4)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0803[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0803[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0803[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0803[p_r+1][p_l] == 'w' || map0803[p_r+1][p_l] == 'e') continue;
                     if(map0803[p_r+1][p_l] == 'b') bomb++;
                     if(map0803[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0803[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0803[p_r-1][p_l] == 'w' || map0803[p_r-1][p_l] == 'e') continue;
                     if(map0803[p_r-1][p_l] == 'b') bomb++;
                     if(map0803[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0803[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0803[p_r][p_l+1] == 'w' || map0803[p_r][p_l+1] == 'e') continue;
                     if(map0803[p_r][p_l+1] == 'b') bomb++;
                     if(map0803[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0803[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0803[p_r][p_l-1] == 'w' || map0803[p_r][p_l-1] == 'e') continue;
                     if(map0803[p_r][p_l-1] == 'b') bomb++;
                     if(map0803[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0803[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act8();
              }
              else continue;
       }
       cout << "恭喜通过8-3关，进入World9" << endl;
       cout << endl << endl;
       Sleep(2000);
}

void act9()
{
       char map0901[21][21] = {
       {'e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e'},
       {'e',' ','w',' ',' ','w',' ',' ','w',' ','b','w',' ',' ','w',' ',' ',' ','b','e'},
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
       {'e',' ','m',' ',' ','w',' ','w',' ',' ',' ','w',' ',' ',' ','w',' ',' ',' ','e'},
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
       {'e',' ',' ',' ','m',' ',' ',' ','w','b',' ','m',' ',' ','w',' ',' ',' ','w','e'},
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
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 18 || p_l != 18)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0901[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0901[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0901[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0901[p_r+1][p_l] == 'w' || map0901[p_r+1][p_l] == 'e') continue;
                     if(map0901[p_r+1][p_l] == 'b') bomb++;
                     if(map0901[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0901[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0901[p_r-1][p_l] == 'w' || map0901[p_r-1][p_l] == 'e') continue;
                     if(map0901[p_r-1][p_l] == 'b') bomb++;
                     if(map0901[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0901[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0901[p_r][p_l+1] == 'w' || map0901[p_r][p_l+1] == 'e') continue;
                     if(map0901[p_r][p_l+1] == 'b') bomb++;
                     if(map0901[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0901[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0901[p_r][p_l-1] == 'w' || map0901[p_r][p_l-1] == 'e') continue;
                     if(map0901[p_r][p_l-1] == 'b') bomb++;
                     if(map0901[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0901[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act9();
              }
              else continue;
       }
       cout << "恭喜通过9-1关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 18 || p_l != 18)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0902[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0902[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0902[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0902[p_r+1][p_l] == 'w' || map0902[p_r+1][p_l] == 'e') continue;
                     if(map0902[p_r+1][p_l] == 'b') bomb++;
                     if(map0902[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0902[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0902[p_r-1][p_l] == 'w' || map0902[p_r-1][p_l] == 'e') continue;
                     if(map0902[p_r-1][p_l] == 'b') bomb++;
                     if(map0902[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0902[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0902[p_r][p_l+1] == 'w' || map0902[p_r][p_l+1] == 'e') continue;
                     if(map0902[p_r][p_l+1] == 'b') bomb++;
                     if(map0902[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0902[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0902[p_r][p_l-1] == 'w' || map0902[p_r][p_l-1] == 'e') continue;
                     if(map0902[p_r][p_l-1] == 'b') bomb++;
                     if(map0902[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0902[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act9();
              }
              else continue;
       }
       cout << "恭喜通过9-2关" << endl;
       cout << endl << endl;
       Sleep(2000);
       bomb = 0;
       p_r = 1;
       p_l = 1;
       while(p_r != 10 || p_l != 9)
       {
              system("cls");
              cout << "你的位置：" << p_r << "行" << p_l << "列" << endl;
              cout << "炸弹数：" << bomb << endl;
              map0903[p_r][p_l] = '*';
              for(int i = 0; i < 20; ++i)
              {
                     for(int j = 0; j < 20; ++j)
                     {
                            cout << map0903[i][j] << " ";
                     }
                     cout << endl;
              }
              choice = _getch();
              map0903[p_r][p_l] = ' ';
              if(choice == 115)
              {
                     if(map0903[p_r+1][p_l] == 'w' || map0903[p_r+1][p_l] == 'e') continue;
                     if(map0903[p_r+1][p_l] == 'b') bomb++;
                     if(map0903[p_r+1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0903[p_r+1][p_l] = ' ';
                                   p_r++;
                            }
                     }
                     else p_r++;
              }
              else if(choice == 119)
              {
                     if(map0903[p_r-1][p_l] == 'w' || map0903[p_r-1][p_l] == 'e') continue;
                     if(map0903[p_r-1][p_l] == 'b') bomb++;
                     if(map0903[p_r-1][p_l] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0903[p_r-1][p_l] = ' ';
                                   p_r--;
                            }
                     }
                     else p_r--;
              }
              else if(choice == 100)
              {
                     if(map0903[p_r][p_l+1] == 'w' || map0903[p_r][p_l+1] == 'e') continue;
                     if(map0903[p_r][p_l+1] == 'b') bomb++;
                     if(map0903[p_r][p_l+1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0903[p_r][p_l+1] = ' ';
                                   p_l++;
                            }
                     }
                     else p_l++;
              }
              else if(choice == 97)
              {
                     if(map0903[p_r][p_l-1] == 'w' || map0903[p_r][p_l-1] == 'e') continue;
                     if(map0903[p_r][p_l-1] == 'b') bomb++;
                     if(map0903[p_r][p_l-1] == 'm')
                     {
                            if(bomb == 0) continue;
                            else
                            {
                                   bomb--;
                                   map0903[p_r][p_l-1] = ' ';
                                   p_l--;
                            }
                     }
                     else p_l--;
              }
              else if(choice == 27)
              {
                     return act9();
              }
              else continue;
       }
       cout << "恭喜通过9-3关，进入...等等，你已经通关了！" << endl;
       cout << endl << endl;
       Sleep(2000);
}

int main()
{
       act1();
       act2();
       act3();
       act4();
       act5();
       act6();
       act7();
       act8();
       act9();
       return 0;
}
