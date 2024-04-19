#ifndef PAGALBINESVECTOR_H_INCLUDED
#define PAGALBINESVECTOR_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
class Pazymiai{
    private:
    std::string var_;
    std::string pav_;
    double vid_;
    int egz_;
    std::vector<int> paz_;
    double galutinis_;
    double med_;

public:
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}
    Pazymiai(std::string var,std::string pav, double vid, int egz, const std::vector<int>& paz, double galutinis, double med)
        : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}
    ~Pazymiai() {}


    void setVar(const std::string& newVar) { var_ = newVar; }
    void setPav(const std::string& newPav) { pav_ = newPav; }
    void setVid(double newVid) { vid_ = newVid; }
    void setEgz(int newEgz) { egz_ = newEgz; }
    //void setPaz(const std::vector<int>& newPaz) { paz_ = newPaz; std::push_back}
    void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
    void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
    //void setPazR(int newPaz) {paz_.push_back((rand() % 10) + 1)}
    void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
    void setMed(double newMed) { med_ = newMed; }
    void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}

    std::string getVar() const { return var_; }
    std::string getPav() const { return pav_; }
    double getVid() const { return vid_; }
    int getEgz() const { return egz_; }
    std::vector<int> getPaz() const { return paz_; }
    int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
    double getGalutinis() const { return galutinis_; }
    double getMed() const { return med_; }
};
/*
class Pazymiai{
    public:
    std::string var;
    std::string pav;
    double vid;
    int egz;
    std::vector<int> paz;
    double galutinis;
    double med;

    Pazymiai() : vid(0), egz(0), galutinis(0), med(0) {}
    Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz, double galutinis, double med)
        : var(var), pav(pav), vid(vid), egz(egz), paz(paz), galutinis(galutinis), med(med) {}
    ~Pazymiai() {}
};
*/

void rezultatai(std::vector<Pazymiai> hh);

void rezultataifailas(std::vector<Pazymiai> hh, std::string failiukas);

double mediana(int u, Pazymiai h);

void generuojam(int studentusk, std::string failopav);

void failuskaick(std::string wp, Pazymiai hi, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija1(std::string wp, Pazymiai hi,std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija2(std::string wp, Pazymiai hi, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija3(std::string wp, Pazymiai hi,std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void spausdintuvas(std::string zekai, std::string malaciai, std::vector<Pazymiai> P, std::vector<Pazymiai> Z );

#endif // PAGALBINES_H_INCLUDED
