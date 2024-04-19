#include "pagalbinesdeque.h"
using namespace std;

void rezultatai(std::deque<Pazymiai> hh){
    std::cout << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
              << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for(const auto &studentas : hh){
        std::cout << std::left << std::setw(15) << studentas.pav << std::setw(15) << studentas.var << std::setw(17)
                  << std::fixed << std::setprecision(2) << studentas.galutinis << std::setw(17) << std::fixed
                  << std::setprecision(2) << studentas.med << std::endl;
    }
}

void rezultataifailas(std::deque<Pazymiai> hh, std::string failiukas){
    std::ofstream R(failiukas);

    R << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
      << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    R << "--------------------------------------------------------" << std::endl;

    for (const auto &studentas : hh) {
        R << std::left << std::setw(15) << studentas.pav << std::setw(15) << studentas.var << std::setw(17)
          << std::fixed << std::setprecision(2) << studentas.galutinis << std::setw(17) << std::fixed
          << std::setprecision(2) << studentas.med << std::endl;
    }
    R.close();
}



double mediana(int u, Pazymiai h){
    int vidurys = u / 2;

    if (u % 2 == 0){
        h.med = double((h.paz[vidurys - 1] + h.paz[vidurys]) / 2.0);
    }
    else{
        h.med = double(h.paz[vidurys]);
    }

    return h.med;
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
/*
void failuskaick(std::string wp, Pazymiai hi,  deque<Pazymiai>& P, deque<Pazymiai>& Z ){

    int z;
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

    auto nus = std::chrono::high_resolution_clock::now();
    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;
    double suum=0;
    for(int l=0; l<lineCount-1; l++){
        double suma=0.0;
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);

        if(hi.galutinis>=5){
            P.push_back(hi);
        }
        else {Z.push_back(hi);}


    }
cout<< "Z funkcija size: "<<Z.size()<<endl;
cout<< "P funkcija size: "<<P.size()<<endl;
    F.close();
    auto nusk = std::chrono::high_resolution_clock::now();

    auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();


    std::cout << "Nuskaitymo trukme: " << laikas << " milisekundes." << std::endl;
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
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;
                    });

                }
                if(xyz==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }
                auto pab = std::chrono::high_resolution_clock::now();

                float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                suum=suum+trukme;
                std::cout << "Rusiavimo trukme: " << suum << " milisekundes." << std::endl;


}
*/
void failuskaick(string wp, Pazymiai hi, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z){

    int z;
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
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);

        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikassum=laikassum+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.galutinis>=5){
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
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo (sort) trukme: " << suum << " milisekundes." << std::endl;


}

void failuskaickstrategija1(string wp, Pazymiai hi,std::deque<Pazymiai>& S, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z){

    int z;
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
    //double suumq=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);
        S.push_back(hi);
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikassum=laikassum+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.galutinis>=5){
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
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo (sort) trukme: " << suum << " milisekundes." << std::endl;


}
/*
void failuskaickstrategija2(string wp, Pazymiai hi, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z){

    int z;
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
    //double suumq=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);
        P.push_back(hi);
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikass=laikass+laikas;
        auto naujas = std::chrono::high_resolution_clock::now();
        if(hi.galutinis<5){
            Z.push_back(hi);
            P.erase(P.begin()+l);
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
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }auto pab = std::chrono::high_resolution_clock::now();

                        float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                        suum=suum+trukme;
                        std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}
*/
void failuskaickstrategija2(string wp, Pazymiai hi, deque<Pazymiai>& P, deque<Pazymiai>& Z) {
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas neegzistuoja!" << endl;
        return; // Exit function if file cannot be opened
    }

    file.close(); // Close file after checking existence

    int lineCount = 0;
    string line;
    file.open(wp);

    while (getline(file, line)) {
        lineCount++;
    }

    file.close();

    ifstream F(wp);
    string zodziai;

    // Find the "Egz." keyword
    int pv = 0;
    while (zodziai != "Egz." && F >> zodziai) {
        pv++;
    }

    pv = pv - 3; // Adjust to the actual number of grades

    double laikass = 0;
    double naujaslaikass = 0;
    double suum = 0;

    for (int l = 0; l < lineCount - 1; l++) {
        auto nus = chrono::high_resolution_clock::now();
        double suma = 0.0;
        hi.paz.clear();
        F >> hi.pav >> hi.var;

        for (int i = 0; i < pv; i++) {
            F >> hi.paz[i];
            suma += hi.paz[i];
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid = suma / pv;

        F >> hi.egz;

        hi.galutinis = (hi.vid * 0.4) + (0.6 * hi.egz);
        hi.med = mediana(pv, hi);
        P.push_back(hi);
        auto nusk = chrono::high_resolution_clock::now();
        auto laikas = chrono::duration_cast<chrono::milliseconds>(nusk - nus).count();
        laikass += laikas;

        auto naujas = chrono::high_resolution_clock::now();

        if (hi.galutinis < 5) {
            Z.push_back(hi);
            P.erase(P.begin() + l); // Erase the current student from P
            // Since an element is erased, we decrement l to account for the shifted indices
            l--;
        }

        auto naujasp = chrono::high_resolution_clock::now();
        auto naujaslaikas = chrono::duration_cast<chrono::milliseconds>(naujasp - naujas).count();
        naujaslaikass += naujaslaikas;
    }

    F.close();

    cout << "Nuskaitymo i konteineri trukme: " << laikass << " milisekundes." << endl;
    cout << "Skirtymo i naujus konteinerius trukme: " << naujaslaikass << " milisekundes." << endl;

    int xyz;
    cout << "Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: " << endl;
    cout << "Jeigu norite rusiuoti pagal mediana spauskite 2: " << endl;

    while (!(cin >> xyz)) {
        cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    auto pra = chrono::high_resolution_clock::now();

    if (xyz == 1) {
        sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
            return a.galutinis < b.galutinis;
        });
        sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
            return aa.galutinis < bb.galutinis;
        });
    }

    if (xyz == 2) {
        sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
            return a.med < b.med;
        });
        sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
            return aa.med < bb.med;
        });
    }

    auto pab = chrono::high_resolution_clock::now();
    float trukme = chrono::duration_cast<chrono::milliseconds>(pab - pra).count();
    suum += trukme;

    cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << endl;
}
void failuskaickstrategija3(string wp, Pazymiai hi, std::deque<Pazymiai>& S, std::deque<Pazymiai>& P, std::deque<Pazymiai>& Z){

    int z;
    double laikass;
    //float suman;
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
    //double suumq=0;
    for(int l=0; l<lineCount-1; l++){
        auto nus = std::chrono::high_resolution_clock::now();
        double suma=0.0;
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }
        sort(hi.paz.begin(), hi.paz.end());
        hi.vid=suma/pv;
        F>>hi.egz;
        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);
        S.push_back(hi);
        auto nusk = std::chrono::high_resolution_clock::now();
        auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();
        laikass=laikass+laikas;
    }
    F.close();
    auto naujas = std::chrono::high_resolution_clock::now();
    auto partition_point = std::partition(S.begin(), S.end(), [](const Pazymiai& s) {
        return s.galutinis >= 5;
    });

    std::copy(S.begin(), partition_point, std::back_inserter(P));
    std::copy(partition_point, S.end(), std::back_inserter(Z));
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
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;

                    });
                }
                if(xyz==2){

                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }
                auto pab = std::chrono::high_resolution_clock::now();

                float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                suum=suum+trukme;
                std::cout << "Rusiavimo sort trukme: " << suum << " milisekundes." << std::endl;


}
void spausdintuvas(std::string zekai, std::string malaciai, deque<Pazymiai> P, deque<Pazymiai> Z ){
    auto p = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, zekai);
    rezultataifailas(P, malaciai);
    auto b = std::chrono::high_resolution_clock::now();

    auto isvestis = std::chrono::duration_cast<std::chrono::milliseconds>(b - p).count();


    std::cout << "Isvedimo trukme: " << isvestis << " milisekundes." << std::endl;

}
