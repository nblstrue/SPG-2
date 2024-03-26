#include <raylib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <src/date.h>

#define countof(x) (sizeof(x)/sizeof(x[0])) //Get the numbers of cases in a array (long long unsigned/signed int type)
#define screenWidth 800
#define screenHeight 600
#define fontsize 20

void music_init(int *size, std::vector<Music> *music);
void saving(std::string player_name);
std::string name_recup();
void framing();
void Shotscreen();
void Beginning(std::vector<Music> music);
void Menu();
