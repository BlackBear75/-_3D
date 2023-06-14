#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include<iostream>
#include<chrono>
#include"gl/glut.h"
class TimeRecord {

public:
void saveTimeRecord(const TimeRecord& record);
void printTopRecords();


 double timeInSeconds;
 std::string playerName;

 void PrintTime(std::chrono::steady_clock::time_point& startime);
 void TextWrite(std::string text, int positionx, int positiony);

};



