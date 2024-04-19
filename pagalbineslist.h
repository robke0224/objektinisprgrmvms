#ifndef PAGALBINESLIST_H_INCLUDED
#define PAGALBINESLIST_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
#include <list>
struct Pazymiai{
    std::string var;
    std::string pav;
    double vid;
    int egz;
    std::list<int> paz;
    double galutinis;
    double med;
};

void rezultatai(std::list<Pazymiai> hh);

void rezultataifailas(std::list<Pazymiai> hh, std::string failiukas);

double mediana(int u, Pazymiai h);

void generuojam(int studentusk, std::string failopav);

void failuskaick(std::string wp, Pazymiai hi, std::list<Pazymiai>& P, std::list<Pazymiai>& Z);

void failuskaickstrategija1(std::string wp, Pazymiai hi,std::list<Pazymiai>& S, std::list<Pazymiai>& P, std::list<Pazymiai>& Z);

void failuskaickstrategija2(std::string wp, Pazymiai hi, std::list<Pazymiai>& P, std::list<Pazymiai>& Z);

void failuskaickstrategija3(std::string wp, Pazymiai hi,std::list<Pazymiai>& S, std::list<Pazymiai>& P, std::list<Pazymiai>& Z);

void spausdintuvas(std::string zekai, std::string malaciai, std::list<Pazymiai> P, std::list<Pazymiai> Z );

void spausdintuvas(std::string zekai, std::string malaciai, std::list<Pazymiai> P, std::list<Pazymiai> Z );

#endif // PAGALBINES_H_INCLUDED
