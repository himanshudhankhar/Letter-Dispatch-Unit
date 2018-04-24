#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
//#include<conio.h>
#include<termios.h>
#include<unistd.h>
//using namespace std;

class passwd{

public:
static int
getch ()
{				// copied code 
  struct termios oldt, newt;	// as getch was not working in linux beacuse it does not support conio.h
  int ch;
  tcgetattr (STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr (STDIN_FILENO, TCSANOW, &newt);
  ch = getchar ();
  tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
  return ch;
};				//------  // function for get_ch


static string getpasswd(){


termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	//cin.ignore();
    string s;
    getline(cin, s);
tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	
return s;
}



};
