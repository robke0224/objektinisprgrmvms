#ifndef PAGALBINESDEQUE_H_INCLUDED
#define PAGALBINESDEQUE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
#include <deque>
struct Pazymiai{
    std::string var;
    std::string pav;
    double vid=0.0;
    int egz;
    std::deque<int> paz;
    double galutinis;
    double med;
    };


void rezultatai(std::deque<Pazymiai> hh);

void rezultataifailas(std::deque<Pazymiai> hh, std::string failiukas);

double mediana(int u, Pazymiai h);

void generuojam(int studentusk, std::string failopav);

void failuskaick(std::string wp, Pazymiai hi, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z);

void failuskaickstrategija1(std::string wp, Pazymiai hi,std::deque<Pazymiai>& S, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z);

void failuskaickstrategija2(std::string wp, Pazymiai hi, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z);

void failuskaickstrategija3(std::string wp, Pazymiai hi,std::deque<Pazymiai>& S, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z);

void spausdintuvas(std::string zekai, std::string malaciai, std::deque<Pazymiai> P, std::deque<Pazymiai> Z );

#endif // PAGALBINES_H_INCLUDED
