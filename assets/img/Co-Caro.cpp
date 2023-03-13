#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;

char a[1000][1000], key;
int x, y, i, m, n, m1, n1, Select;

void beginning(int);
void humanVsHuman();
void quit();
void tutorial(int);
void drawTable(int);
void replay();

void Goto(int x, int y)
{
  COORD spot = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spot);
}

void TextColor(int x)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

//Noi dung game
int turn(int i = 0)
{
  if (i % 2 == 0)
    return 1;
  else
    return 0;
}

char OX(int i)
{
  if (turn(i) == 1)
    return 'O';
  else
    return 'X';
}

void drawOX(int x, int y)
{ //Ve X, O theo turn
  if (a[x][y] != 'X' && a[x][y] != 'O')
  {
    if (turn(i) == 1)
      TextColor(11);
    else
      TextColor(12);
    a[x][y] = OX(i);
    cout << a[x][y];
    i += 1;
  }
}

void left()
{
  x -= 2;
  if (x < 13)
    x = 13;
}

void right()
{
  x += 2;
  if (x >= 77)
    x = 77;
}

void up()
{
  y -= 1;
  if (y < 3)
    y = 3;
}

void down()
{
  y += 1;
  if (y >= 24)
    y = 24;
}

void pointer(int x, int y)
{
  Goto(x, y);
  n = x;
  m = y;
}

void gameInfo()
{
  TextColor(7);
  //Thong tin
  Goto(0, 0);
  cout << "<== B: Back          " << endl
       << "Luot thu: " << i + 1;
  //Trang tri
  cout << "     M, E: chon X/O.";
  TextColor(12);
  cout << "           DAU VOI NGUOI";
  Goto(0, 4);
  TextColor(11);
  cout << "Player 1" << endl
       << "A,D,W,S" << endl
       << endl;
  cout << "Player 2" << endl
       << "Phim di " << endl
       << "chuyen" << endl
       << endl;
  TextColor(14);
  cout << "p/s:" << endl
       << "Chan dau," << endl
       << "chan duoi " << endl;
  TextColor(12);
  cout << "khong";
  TextColor(14);
  cout << " tinh" << endl
       << endl;
  TextColor(9);
  cout << "R: Choi lai" << endl
       << "Q: Thoat" << endl;
  TextColor(10);
  cout << endl
       << "Luot: " << OX(i);
  TextColor(7);
}

int Owin()
{ //Dieu kien de ben O chien thang
  //Theo hang ngang
  m1 = m;
  n1 = n;
  while (a[n1][m] == 'O')
    n1++;
  n1--;

  if ((a[n1][m] == 'O') && (a[n1 + 2][m] == 'O') && (a[n1 + 4][m] == 'O') && (a[n1 + 6][m] == 'O') && (a[n1 + 8][m] == 'O') && ((a[n1 + 10][m] != 'X') && (a[n1 - 2][m] != 'X')))
    return 1;
  else if ((a[n1][m] == 'O') && (a[n1 - 2][m] == 'O') && (a[n1 - 4][m] == 'O') && (a[n1 - 6][m] == 'O') && (a[n1 - 8][m] == 'O') && ((a[n1 - 10][m] != 'X') && (a[n1 + 2][m] != 'X')))
    return 1;
  //Theo hang doc
  m1 = m;
  n1 = n;
  while (a[n][m1] == 'O')
    m1++;
  m1--;

  if ((a[n][m1] == 'O') && (a[n][m1 + 1] == 'O') && (a[n][m1 + 2] == 'O') && (a[n][m1 + 3] == 'O') && (a[n][m1 + 4] == 'O') && ((a[n][m1 + 5] != 'X') && (a[n][m1 - 1] != 'X')))
    return 1;
  else if ((a[n][m1] == 'O') && (a[n][m1 - 1] == 'O') && (a[n][m1 - 2] == 'O') && (a[n][m1 - 3] == 'O') && (a[n][m1 - 4] == 'O') && ((a[n][m1 - 5] != 'X') && (a[n][m1 + 1] != 'X')))
    return 1;
  //Theo duong cheo
  m1 = m;
  n1 = n;
  while (a[n1][m1] == 'O')
  {
    m1++;
    n1++;
  }
  m1--;
  n1--;
  if ((a[n1][m1] == 'O') && (a[n1 + 2][m1 + 1] == 'O') && (a[n1 + 4][m1 + 2] == 'O') && (a[n1 + 6][m1 + 3] == 'O') && (a[n1 + 8][m1 + 4] == 'O') && ((a[n1 + 10][m1 + 5] != 'X') && (a[n1 - 2][m1 - 1] != 'X')))
    return 1;
  else if ((a[n1][m1] == 'O') && (a[n1 - 2][m1 - 1] == 'O') && (a[n1 - 4][m1 - 2] == 'O') && (a[n1 - 6][m1 - 3] == 'O') && (a[n1 - 8][m1 - 4] == 'O') && ((a[n1 - 10][m1 - 5] != 'X') && (a[n1 + 2][m1 + 1] != 'X')))
    return 1;
  m1 = m;
  n1 = n;
  while (a[n1][m1] == 'O')
  {
    n1++;
    m1--;
  }
  n1--;
  m1++;
  if ((a[n1][m1]) == 'O' && (a[n1 + 2][m1 - 1]) == 'O' && (a[n1 + 4][m1 - 2]) == 'O' && (a[n1 + 6][m1 - 3]) == 'O' && (a[n1 + 8][m1 - 4] == 'O') && ((a[n1 + 10][m1 - 5] != 'X') && (a[n1 - 2][m1 + 1] != 'X')))
    return 1;
  else if ((a[n1][m1]) == 'O' && (a[n1 - 2][m1 + 1]) == 'O' && (a[n1 - 4][m1 + 2]) == 'O' && (a[n1 - 6][m1 + 3]) == 'O' && (a[n1 - 8][m1 + 4] == 'O') && ((a[n1 - 10][m1 + 5] != 'X') && (a[n1 + 2][m1 - 1] != 'X')))
    return 1;

  return 0;
}

int Xwin()
{ //Dieu kien de ben X chien thang
  //THeo hang ngang
  m1 = m;
  n1 = n;
  while (a[n1][m] == 'X')
  {
    n1++;
  }
  n1--;
  //Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet duoc
  if ((a[n1][m] == 'X') && (a[n1 + 2][m] == 'X') && (a[n1 + 4][m] == 'X') && (a[n1 + 6][m] == 'X') && (a[n1 + 8][m] == 'X') && ((a[n1 + 10][m] != 'O') || (a[n1 - 2][m] != 'O')))
    return 1;
  else //Theo Hang ngang
      if ((a[n1][m] == 'X') && (a[n1 - 2][m] == 'X') && (a[n1 - 4][m] == 'X') && (a[n1 - 6][m] == 'X') && (a[n1 - 8][m] == 'X') && ((a[n1 - 10][m] != 'O') || (a[n1 + 2][m] != 'O')))
    return 1;
  //Theo hang doc
  m1 = m;
  n1 = n;
  while (a[n][m1] == 'X')
  {
    m1++;
  }
  m1--;
  if ((a[n][m1] == 'X') && (a[n][m1 + 1] == 'X') && (a[n][m1 + 2] == 'X') && (a[n][m1 + 3] == 'X') && (a[n][m1 + 4] == 'X') && ((a[n][m1 + 5] != 'O') || (a[n][m1 - 1] != 'O')))
    return 1;
  else //Theo Hang doc
      if ((a[n][m1] == 'X') && (a[n][m1 - 1] == 'X') && (a[n][m1 - 2] == 'X') && (a[n][m1 - 3] == 'X') && (a[n][m1 - 4] == 'X') && ((a[n][m1 - 5] != 'O') || (a[n][m1 + 1] != 'O')))
    return 1;
  //Theo duong cheo chinh
  m1 = m;
  n1 = n;
  while (a[n1][m1] == 'X')
  {
    m1++;
    n1++;
  }
  m1--;
  n1--;
  if ((a[n1][m1] == 'X') && (a[n1 + 2][m1 + 1] == 'X') && (a[n1 + 4][m1 + 2] == 'X') && (a[n1 + 6][m1 + 3] == 'X') && (a[n1 + 8][m1 + 4] == 'X') && ((a[n1 + 10][m1 + 5] != 'O') || (a[n1 - 2][m1 - 1] != 'O')))
    return 1;
  else //Theo Duong cheo chinh
      if ((a[n1][m1] == 'X') && (a[n1 - 2][m1 - 1] == 'X') && (a[n1 - 4][m1 - 2] == 'X') && (a[n1 - 6][m1 - 3] == 'X') && (a[n1 - 8][m1 - 4] == 'X') && ((a[n1 - 10][m1 - 5] != 'O') || (a[n1 + 2][m1 + 1] != 'O')))
    return 1;
  //Theo duong cheo phu
  m1 = m;
  n1 = n;
  while (a[n1][m1] == 'X')
  {
    n1++;
    m1--;
  }
  n1--;
  m1++;
  if ((a[n1][m1]) == 'X' && (a[n1 + 2][m1 - 1]) == 'X' && (a[n1 + 4][m1 - 2]) == 'X' && (a[n1 + 6][m1 - 3]) == 'X' && (a[n1 + 8][m1 - 4] == 'X') && ((a[n1 + 10][m1 - 5] != 'O') || (a[n1 + 2][m1 + 1] != 'O')))
    return 1;
  else //Theo Duong cheo phu
      if ((a[n1][m1]) == 'X' && (a[n1 - 2][m1 + 1]) == 'X' && (a[n1 - 4][m1 + 2]) == 'X' && (a[n1 - 6][m1 + 3]) == 'X' && (a[n1 - 8][m1 + 4] == 'X') && ((a[n1 - 10][m1 + 5] != 'O') || (a[n1 - 2][m1 - 1] != 'O')))
    return 1;

  return 0;
}
// Hien nguoi chien thang
void win()
{
  TextColor(12);
  if ((Owin() == 1))
  {
    Goto(27, 3);
    TextColor(11);
    cout << "O chien thang. An R de choi lai. Q de quit";
    key = getch();
    if (key == 'r' || key == 'R')
      replay();
    else if (key == 'q' || key == 'Q')
      quit();
    else
      beginning(50);
  }
  else if ((Xwin() == 1))
  {
    Goto(27, 3);
    TextColor(12);
    cout << "X Chien Thang. An R de choi lai. Q de quit";
    key = getch();
    if (key == 'r' || key == 'R')
      replay();
    else if (key == 'q' || key == 'Q')
      quit();
    else
      beginning(50);
  }
  TextColor(7);
}

void replay()
{ //choi lai
  //background();
  i = 0;
  x = 13;
  y = 3;
  system("cls");
  gameInfo();
  drawTable(0);
}

void keybroad()
{ //Nhan thong tin tu ban phim
  key = getch();
  if (key == 'a' || key == 'A' || int(key == 75))
    left();
  else if (key == 'd' || key == 'D' || int(key == 77))
    right();
  else if (key == 'w' || key == 'W' || int(key == 72))
    up();
  else if (key == 's' || key == 'S' || int(key == 80))
    down();
  else if (key == 'e' || key == 'E' || key == 'm' || key == 'M')
    drawOX(n, m);
  else if (key == 'r' || key == 'R')
    replay();
  if (key == 'b' || key == 'B')
    beginning(50);
}

int main()
{
  // background();
  beginning(100);
  return 0;
}

void beginning(int n)
{
  system("cls");

  Goto(0, 0);
  TextColor(12);
  cout << "                  __                      " << endl
       << "                  \\_\\     __        " << endl
       << " _________     __________/_/        " << endl
       << "//    ____\\   //    __   \\" << endl
       << "\\\\   \\        \\\\   /  \\   \\" << endl
       << " \\\\   \\        \\\\  \\   \\   \\" << endl
       << "  \\\\   \\_____   \\\\  \\___/   \\" << endl
       << "   \\\\________\\   \\\\ ________/" << endl
       << "     ---------      ---------" << endl;
  TextColor(10);
  cout << endl
       << " _________        _______     " << endl
       << "//    ____\\      |  __   \\   " << endl
       << "\\\\   \\           | |  \\   \\  " << endl
       << " \\\\   \\	        |  |___\\   \\  " << endl
       << "  \\\\   \\_____   |   ______  \\  " << endl
       << "   \\\\________\\  |__|      \\__\\  " << endl
       << "     ---------  ----       ---    " << endl;
  TextColor(9);
  cout << "                 _______" << endl
       << "                /__/ \\__\\" << endl
       << "_____  ______    __________" << endl
       << "\\\\   \\/ _____\\  //    __   \\" << endl
       << " \\\\    /-----   \\\\   /  \\   \\" << endl
       << "  \\\\   \\         \\\\  \\   \\   \\" << endl
       << "   \\\\   \\         \\\\  \\___/   \\" << endl
       << "    \\\\___\\         \\\\ ________/" << endl
       << "     -----           ---------" << endl;

  TextColor(11);
  Goto(45, 10);
  cout << "1. CHOI" << endl;
  Sleep(n);
  Goto(45, 11);
  cout << "2. HUONG DAN" << endl;
  Sleep(n);
  Goto(45, 12);
  cout << "3. THOAT" << endl;
  Sleep(n);
  Goto(45, 13);
  cout << "Menu ";
  Select = getch();
  cout << char(Select);
  Sleep(200);
  if (Select == '1')
    humanVsHuman();
  else if (Select == '2')
    tutorial(1);
  else if (Select == '3')
    quit();
  else
    beginning(0);
  TextColor(7);
}

void drawTable(int n)
{
  int i, j;
  TextColor(8);
  Goto(12, 2);
  for (i = 0; i <= 66; i++)
  {
    cout << "_";
    Sleep(n); //canh tren
  }
  for (i = 0; i <= 21; i++)
  {
    Goto(12, i + 3); //canh trai
    Sleep(n);
    cout << "|";
  }
  Goto(13, 24);
  for (i = 0; i <= 64; i++)
  {
    cout << "_";
    Sleep(n); //canh duoi
  }

  for (i = 0; i <= 21; i++)
  {
    Goto(78, i + 3); //canh phai
    Sleep(n);
    cout << "|";
  }

  for (j = 0; j <= 21; j++)
  {
    for (i = 0; i <= 62; i += 2)
    {
      Goto(i + 14, j + 3);
      cout << "|";
    }
  }

  for (j = 0; j <= 20; j++)
  {
    for (i = 0; i <= 64; i += 2)
    {
      Goto(i + 13, j + 3);
      cout << "_";
    }
  }
}

void start()
{
  system("cls");
  tutorial(2);
  system("cls");
  drawTable(3);
}

void humanVsHuman()
{
  start();
  x = n = 13;
  y = m = 3;
  i = 0;
  do
  {
    gameInfo();
    pointer(x, y);
    win();
    keybroad();
  } while (key != 'q' && key != 'Q');
  quit();
}

void tutorial(int k)
{
  cout << endl
       << endl
       << "                  <<<           HUONG DAN           >>>" << endl
       << endl
       << endl;
  cout << "Dung";
  TextColor(12);
  cout << " phim di chuyen";
  TextColor(7);
  cout << " va";
  TextColor(12);
  cout << " A,D,W,S";
  TextColor(7);
  cout << " de di chuyen. Dung phim";
  TextColor(12);
  cout << " E";
  TextColor(7);
  cout << " va";
  TextColor(12);
  cout << " M";
  TextColor(7);
  cout << " de chon." << endl
       << endl
       << "HAVE FUN! :) " << endl;
  ;
  system("pause");
  if (k == 1)
    beginning(0);
}

void quit()
{
  TextColor(10);
  Goto(31, 11);
  cout << "Xin Chao! Hen Gap lai!";
  getch();
}
