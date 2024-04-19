#include "pagalbinesvector.h"
using namespace std;

void rezultatai(std::vector<Pazymiai> hh){
    std::cout << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
              << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for(const auto &studentas : hh){
        std::cout << std::left << std::setw(15) << studentas.getPav() << std::setw(15) << studentas.getVar() << std::setw(17)
                  << std::fixed << std::setprecision(2) << studentas.getGalutinis() << std::setw(17) << std::fixed
                  << std::setprecision(2) << studentas.getMed() << std::endl;
    }
}

void rezultataifailas(std::vector<Pazymiai> hh, std::string failiukas){
    std::ofstream R(failiukas);

    R << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
      << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    R << "--------------------------------------------------------" << std::endl;

    for (const auto &studentas : hh) {
        R << std::left << std::setw(15) << studentas.getPav() << std::setw(15) << studentas.getVar() << std::setw(17)
          << std::fixed << std::setprecision(2) << studentas.getGalutinis() << std::setw(17) << std::fixed
          << std::setprecision(2) << studentas.getMed() << std::endl;
    }
    R.close();
}

double mediana(int u, Pazymiai h){
    int vidurys = u / 2;

    if (u % 2 == 0){
        h.setMed( double((h.getPazN( h.getPaz(),vidurys - 1) + h.getPazN(h.getPaz(),vidurys)) / 2.0));
    }
    else{
        h.setMed ( double(h.getPazN(h.getPaz(),vidurys)));
    }

    return h.getMed();
}

void generuojam(int studentusk, std::string failopav){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ofstream V(failopav);
    std::stringstream laik;
    laik <<"Pavarde "<<" "<< "Vardas "<<" ";
    int pazymiusk;
    pazymiusk = (rand() % 15) + 5;
    for(int i=0; i<pazymiusk; i++){
    laik<< "ND"<<i+1<<" ";
    }
    laik<< "Egz."<<std::endl;

    for(int i=0; i<studentusk; i++){

        laik<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<pazymiusk+1; j++){
            int nd=(rand() % 10) + 1;
            laik<<nd<<" ";
        }
        laik<<std::endl;
    }
    V<<laik.str();
    V.close();
    laik.clear();
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();


    std::cout << "Generavimo trukme: " << duration << " milisekundes." << std::endl;

}

void failuskaick(std::string wp, Pazymiai hi, vector<Pazymiai>& P, vector<Pazymiai>& Z ){

    int z;
    float suml=0;
    double laikassum=0;
    string xx, yy;
    int egg;
    ifstream file(wp);

    if (!file.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    file.close();
    int lineCount = 0;
    std::string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    std::string zodziai;
    int pv=0;


    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        //hi.paz.clear();
        F>>xx>>yy;
        hi.setPav(xx);
        hi.setVar(yy);

        vector<int> nauji_pazymiai;
        for(int i=0; i<pv; i++){
            F>>z;
            //hi.paz.push_back(z);
            //hi.setOnePaz(z);
            nauji_pazymiai.push_back(z);
            suma=suma+z;
        }
        hi.setPazymiai(nauji_pazymiai);
        //sort(hi.paz.begin(), hi.paz.end());
        hi.sortPaz(hi);
        hi.setVid(suma/pv);

        F>>egg;
        hi.setEgz(egg);

        hi.setGalutinis((hi.getVid()*0.4)+(0.6*hi.getEgz()));
        hi.setMed(mediana(pv,hi));
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikassum=laikassum+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.getGalutinis()>=5){
            P.push_back(hi);
        }
        else {Z.push_back(hi);}
        auto naujasp = std::chrono::high_resolution_clock::now();
        auto naujaslaikas = std::chrono::duration_cast<std::chrono::milliseconds>(naujasp - naujas).count();
        suml=suml+naujaslaikas;
    }

    cout<< "Z funkcija size: "<<Z.size()<<endl;
    cout<< "P funkcija size: "<<P.size()<<endl;
    F.close();


    std::cout << "Nuskaitymo trukme: " << laikassum << " milisekundes." << std::endl;


    std::cout << "Skirtymo i naujus konteinerius trukme: " << suml << " milisekundes." << std::endl;

    int xyz;
    std::cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<std::endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<std::endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                 auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getGalutinis() < bb.getGalutinis();
                    });

                }
                if(xyz==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getMed() < bb.getMed();
                    });
                }
                auto pab = std::chrono::high_resolution_clock::now();

                float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                suum=suum+trukme;
                std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}

void failuskaickstrategija1(string wp, Pazymiai hi,std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z){

    int z;
    string xx, yy;
    int egg;
    double laikassum=0;
    float naujaslaikassum=0;
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas  neegzistuoja!" << endl;
    }
    file.close();
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    string zodziai;
    int pv=0;


    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        //hi.paz.clear();
        F>>xx>>yy;
        hi.setPav(xx);
        hi.setVar(yy);

        for(int i=0; i<pv; i++){
            F>>z;
            //hi.paz.push_back(z);
            hi.setOnePaz(z);
            suma=suma+z;
        }

        //sort(hi.paz.begin(), hi.paz.end());
        hi.sortPaz(hi);

        hi.setVid(suma/pv);

        F>>egg;
        hi.setEgz(egg);

        hi.setGalutinis((hi.getVid()*0.4)+(0.6*hi.getEgz()));
        hi.setMed(mediana(pv,hi));
        S.push_back(hi);
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikassum=laikassum+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.getGalutinis()>=5){
            P.push_back(hi);
        }
        else {Z.push_back(hi);}
        auto naujasp = std::chrono::high_resolution_clock::now();
        auto naujaslaikas = std::chrono::duration_cast<std::chrono::milliseconds>(naujasp - naujas).count();
        naujaslaikassum=naujaslaikassum+naujaslaikas;
    }
cout<< "Z funkcija size: "<<Z.size()<<endl;
    cout<< "P funkcija size: "<<P.size()<<endl;
    F.close();

    std::cout << "Nuskaitymo trukme: " << laikassum << " milisekundes." << std::endl;

    std::cout << "Skirtymo i naujus konteinerius trukme: " << naujaslaikassum << " milisekundes." << std::endl;
    int xyz;
    cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
    cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getGalutinis() < bb.getGalutinis();

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getMed() < bb.getMed();
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo (sort) trukme: " << suum << " milisekundes." << std::endl;


}

void failuskaickstrategija2(string wp, Pazymiai hi, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z){

    int z;
    string xx, yy;
    int egg;
    double laikass=0;
    float naujaslaikass=0;
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas  neegzistuoja!" << endl;
    }
    file.close();
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    string zodziai;
    int pv=0;


    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        //hi.paz.clear();
        F>>xx>>yy;
        hi.setPav(xx);
        hi.setVar(yy);

        for(int i=0; i<pv; i++){
            F>>z;
            //hi.paz.push_back(z);
            hi.setOnePaz(z);
            suma=suma+z;
        }

        //sort(hi.paz.begin(), hi.paz.end());
        hi.sortPaz(hi);

        hi.setVid(suma/pv);

        F>>egg;
        hi.setEgz(egg);

        hi.setGalutinis((hi.getVid()*0.4)+(0.6*hi.getEgz()));
        hi.setMed(mediana(pv,hi));
        P.push_back(hi);
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikass=laikass+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.getGalutinis()<5){
            Z.push_back(hi);
            P.pop_back();
            //P.erase(P.begin()+l);
        }
        auto naujasp = std::chrono::high_resolution_clock::now();
        auto naujaslaikas = std::chrono::duration_cast<std::chrono::milliseconds>(naujasp - naujas).count();
        naujaslaikass=naujaslaikass+naujaslaikas;
    }

    F.close();

    std::cout << "Nuskaitymo i konteineri trukme: " << laikass << " milisekundes." << std::endl;


    std::cout << "Skirtymo i naujus konteinerius trukme: " << naujaslaikass << " milisekundes." << std::endl;
    int xyz;
    cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getGalutinis() < bb.getGalutinis();

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getMed() < bb.getMed();
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}

void failuskaickstrategija3(string wp, Pazymiai hi, std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z){

    int z;
    double laikass;
    string xx,yy;
    int egg;
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas  neegzistuoja!" << endl;
    }
    file.close();
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    string zodziai;
    int pv=0;


    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }
    S.clear();
    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        //hi.paz.clear();
        F>>xx>>yy;
        hi.setPav(xx);
        hi.setVar(yy);

        vector<int> nauji_pazymiai;
        for(int i=0; i<pv; i++){
            F>>z;
            //hi.setOnePaz(z);
            nauji_pazymiai.push_back(z);
            suma=suma+z;
        }
        hi.setPazymiai(nauji_pazymiai);

        //sort(hi.paz.begin(), hi.paz.end());
        hi.sortPaz(hi);

        hi.setVid(suma/pv);

        F>>egg;
        hi.setEgz(egg);

        hi.setGalutinis((hi.getVid()*0.4)+(0.6*hi.getEgz()));

        hi.setMed(mediana(pv,hi));
        S.push_back(hi);

        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikass=laikass+laikas;


    }
        F.close();
        auto naujas = std::chrono::high_resolution_clock::now();

        auto partition_point = std::partition(S.begin(), S.end(), [](const Pazymiai& s) {
        return s.getGalutinis() >= 5;
    });

    std::copy(S.begin(), partition_point, std::back_inserter(P));

    std::copy(partition_point, S.end(), std::back_inserter(Z));
    S.clear();
    auto naujasp = std::chrono::high_resolution_clock::now();
    auto naujaslaikas = std::chrono::duration_cast<std::chrono::milliseconds>(naujasp - naujas).count();
    cout<<" S size "<<S.size()<<endl;
    cout<<" P size "<< P.size()<<endl;
    cout<<" Z size "<< Z.size()<<endl;
    std::cout << "Nuskaitymo trukme: " << laikass << " milisekundes." << std::endl;
    std::cout << "Skirtymo i naujus konteinerius trukme: " << naujaslaikas << " milisekundes." << std::endl;

    int xyz;
    cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getGalutinis() < bb.getGalutinis();

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getMed() < bb.getMed();
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}
/*
void failuskaickstrategija3(string wp, Pazymiai hi, std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z){

    int z;
    double laikass;
    string xx,yy;
    int egg;
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas  neegzistuoja!" << endl;
    }
    file.close();
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    string zodziai;
    int pv=0;


    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }
    S.clear();
    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        //hi.paz.clear();
        F>>xx>>yy;
        hi.setPav(xx);
        hi.setVar(yy);

        for(int i=0; i<pv; i++){
            F>>z;
            //hi.paz.push_back(z);
            hi.setOnePaz(z);
            suma=suma+z;
        }

        //sort(hi.paz.begin(), hi.paz.end());
        hi.sortPaz(hi);

        hi.setVid(suma/pv);

        F>>egg;
        hi.setEgz(egg);

        hi.setGalutinis((hi.getVid()*0.4)+(0.6*hi.getEgz()));

        hi.setMed(mediana(pv,hi));
        S.push_back(hi);

        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikass=laikass+laikas;


    }
        F.close();
        auto naujas = std::chrono::high_resolution_clock::now();

        auto partition_point = std::partition(S.begin(), S.end(), [](const Pazymiai& s) {
        return s.getGalutinis() >= 5;
    });

    P.assign(S.begin(), partition_point);
    Z.assign(partition_point, S.end());
    S.clear();
    auto naujasp = std::chrono::high_resolution_clock::now();
    auto naujaslaikas = std::chrono::duration_cast<std::chrono::milliseconds>(naujasp - naujas).count();
    cout<<" S size "<<S.size()<<endl;
    cout<<" P size "<< P.size()<<endl;
    cout<<" Z size "<< Z.size()<<endl;
    std::cout << "Nuskaitymo trukme: " << laikass << " milisekundes." << std::endl;
    std::cout << "Skirtymo i naujus konteinerius trukme: " << naujaslaikas << " milisekundes." << std::endl;

    int xyz;
    cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getGalutinis() < bb.getGalutinis();

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.getMed() < bb.getMed();
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}
*/
void spausdintuvas(std::string zekai, std::string malaciai, vector<Pazymiai> P, vector<Pazymiai> Z ){
    auto p = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, zekai);
    rezultataifailas(P, malaciai);
    auto b = std::chrono::high_resolution_clock::now();

    auto isvestis = std::chrono::duration_cast<std::chrono::milliseconds>(b - p).count();


    std::cout << "Isvedimo trukme: " << isvestis << " milisekundes." << std::endl;

}


