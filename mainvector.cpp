#include "pagalbinesvector.h"
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;

std::vector<Pazymiai> S, P, Z;


int main ()
{


    while (true){
        cout << "Pasirinkite norima veiksma vector: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Failu generavimas" << endl;
        cout << "6. Sugeneruotu failu skaiciavimas" << endl;
        cout << "7. Klases testavimas" << endl;
        cout << "8. Programa baigta" << endl;
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki 7. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pasirinkimas){
            case 1:{

                Pazymiai C;
                string xx, y;
                int eg;
                C.setVid(0.0);
                do{

                    double suma=0.0;

                    cout<<"Iveskite "<<i+1<<" pavarde (noredami baigti spauskite 4):   "<<endl;

                    cin>>xx;
                    C.setPav(xx);

                    if(C.getPav()=="4" || C.getVar()=="4"){
                        break;
                    }

                    cout<<"Iveskite "<<i+1<<" varda (noredami baigti spauskite 4):   "<<endl;
                    cin>>y;
                    C.setVar(y);

                    if(C.getPav()=="4" || C.getVar()=="4"){
                        break;
                    }

                    int j=0;

                    do{
                        cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                        cin>>x;

                        if(x==11){
                            break;
                        }

                        while (cin.fail() || x < 1 || x > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                                cin >> x;
                                if(x==11){
                                    break;
                                }
                        }

                        C.setOnePaz(x);
                        suma = suma + x;
                        j++;
                    } while(x!=11);

                    C.setVid(suma/j);

                    cout << "Iveskite egzamino rezultata: " << endl;

                    try {
                        cin>> eg;
                        C.setEgz(eg);

                        while (cin.fail() || eg < 1 || eg > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                            cin>> eg;
                            C.setEgz(eg);
                        }
                    } catch (const std::exception& e) {

                        cerr << "Exception: " << e.what() << endl;

                    }

                    C.setGalutinis((C.getVid()*0.4)+(0.6*C.getEgz()));
                    C.sortPaz(C);

                    C.setMed(mediana(j,C));

                    P.push_back(C);
                    i++;
                } while(C.getPav()!="4" || C.getVar()!="4");

                rezultatai(P);
                break;
            }

            case 2:{

                Pazymiai C;
                string xx, yy;
                int egg;
                do  {
                    double suma = 0.0;

                    cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
                    cin >> xx;
                    C.setPav(xx);
                    if (C.getPav() == "4" || C.getVar() == "4") {
                        break;
                    }

                    cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
                    cin >> yy;
                    C.setVar(yy);
                    if (C.getPav() == "4" || C.getVar() == "4") {
                        break;
                    }

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (x == 1) {
                        string y;
                        int h = 0;
                        while (y != "ne") {
                            //C.paz.push_back((rand() % 10) + 1);
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                            cout << "Ar norite testi generavima? taip arba ne: ";
                            cin >> y;
                            if (y != "taip" && y != "ne") {
                                cout << "Klaida. Prasome ivesti taip arba ne: ";
                                cin>>y;
                            }
                            suma = suma + C.getPazN(C.getPaz(),h);
                            h++;
                        }
                        C.setVid(suma / h);

                        C.setMed(mediana(h,C));
                    }

                    if (x == 2) {
                        int k;
                        cout << "Iveskite pazymiu kieki: ";

                        while (!(cin >> k) || (k < 1)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1: ";
                        }
                        for (int l = 0; l < k; l++) {
                            //C.paz.push_back((rand() % 10) + 1);
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                            suma = suma + C.getPazN(C.getPaz(),l);
                        }
                        C.setVid(suma / k);
                        C.sortPaz(C);

                        C.setMed(mediana(k,C));
                    }

                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (w == 1) {
                        C.setEgz((rand() % 10) + 1);
                        cout << "Egzamino rezultatas: " << C.getEgz() << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;

                        try {
                            cin >> egg;
                            C.setEgz(egg);

                            while (cin.fail() || egg < 1 || egg > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> egg;
                                C.setEgz(egg);
                            }
                        } catch (const std::exception& e) {
                            cerr << "Exception: " << e.what() << endl;
                            }
                        cout << endl;
                    }

                    C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));
                    P.push_back(C);
                    i++;
                } while (C.getPav() != "4" || C.getVar() != "4");

                rezultatai(P);
                break;
            }

            case 3:{
                int qq = 0;
                int egg;
                string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"};
                string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"};
                string xx, yy;
                while (qq != 1) {
                    Pazymiai C;

                    xx = pavardes[rand() % 10];
                    C.setPav(xx);

                    yy = vardai[rand() % 10];
                    C.setVar(yy);
                    cout << "Pavarde ir vardas: " << C.getPav() << " " << C.getVar() << endl;

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout<< "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (x == 1) {
                        string y;
                        int h = 0;
                        double suma = 0.0;

                        while (y != "Ne") {
                            //C.paz.push_back((rand() % 10) + 1);
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + C.getPazN(C.getPaz(),h);
                            h++;
                        }
                        C.setVid(suma / h);

                        C.sortPaz(C);

                        C.setMed(mediana(h,C));
                    }

                    if (x == 2) {
                        double suma = 0.0;
                        int k;
                        cout << "Iveskite pazymiu kieki: ";

                        while (!(cin >> k) || (k < 1 )) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1 : ";
                        }

                        for (int l = 0; l < k; l++) {
                            //C.paz.push_back((rand() % 10) + 1);
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                            suma = suma + C.getPazN(C.getPaz(),l);
                        }

                        C.setVid(suma / k);

                        C.sortPaz(C);

                        C.setMed(mediana(k,C));
                    }

                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (w == 1) {
                        C.setEgz((rand() % 10) + 1);
                        cout << "Egzamino rezultatas: " << C.getEgz() << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;

                        try {
                            cin >> egg;
                            C.setEgz(egg);

                            while (cin.fail() || egg < 1 || egg > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> egg;
                                C.setEgz(egg);
                            }
                        } catch (const std::exception& e) {
                            cerr << "Exception: " << e.what() << endl;
                        }
                        cout << endl;
                    }

                    C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

                    cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> qq) || (qq != 1 && qq != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    P.push_back(C);
                }

                rezultatai(P);

                break;
            }

            case 4:{

                Pazymiai C;

                int z;
                int o;
                int stud;
                string zodziai;
                int xyz;
                int pv=0;
                int numeris;
                string wp;
                string xx, yy;
                int egg;
                cout<<"Pasirinkite is kurio failo norite nuskaityti: "<<endl;
                cout<<"1. studentai10000 "<<"2. studentai100000 "<<"3. studentai1000000 "<<"4. kursiokai5 "<<endl;

                while (!(cin >> numeris) || numeris < 1 || numeris > 4) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (numeris) {
                        case 1:
                            wp = "studentai10000.txt";
                            break;
                        case 2:
                            wp = "studentai100000.txt";
                            break;
                        case 3:
                            wp = "studentai1000000.txt";
                            break;
                        case 4:
                            wp = "kursiokai.txt";
                            break;
                        default:
                            break;

                    }

                    ifstream file(wp);
                    if (!file.is_open()) {
                        cout << "Failas " << wp << " neegzistuoja!" << endl;
                        break;
                    }
                    file.close();


                    int lineCount = 0;
                    string line;
                    file.open(wp);
                    while (getline(file, line)) {
                        lineCount++;
                    }
                    file.close();

                    do {
                        cout << "Kiek nuskaityti studentu? " << endl;

                        while (!(cin >> stud) || stud <= 0 || stud > lineCount) {
                            cout << "Klaida. Iveskite skaiciu nuo 1 iki " << lineCount << "." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    } while (stud <= 0 || stud > lineCount);
                                ifstream F(wp);

                                auto start = chrono::steady_clock::now();

                                while( zodziai != "Egz."){
                                    F>>zodziai;
                                    pv++;
                                }

                                pv=pv-3;

                                for(int l=0; l<stud; l++){
                                    double suma=0.0;
                                    F>>xx>>yy;
                                    C.setPav(xx);
                                    C.setVar(yy);
                                    for(int i=0; i<pv; i++){
                                        F>>z;
                                        C.setOnePaz(z);
                                        //cout<<"paz "<<C.getPazN(C.getPaz(),l++)<<endl;
                                        suma=suma+z;
                                    }

                                    //sort(C.paz.begin(), C.paz.end());
                                    C.sortPaz(C);

                                    C.setVid(suma/pv);

                                    F>>egg;
                                    C.setEgz(egg);

                                    C.setGalutinis((C.getVid()*0.4)+(0.6*C.getEgz()));

                    C.setMed(mediana(pv,C));

                    P.push_back(C);

                }

                vector<double> laikai;

                F.close();
                auto end = chrono::steady_clock::now();
                double laikas=chrono::duration <double> (end - start).count();
                laikai.push_back(laikas);
                cout<<"Trukme: "<< laikas << " s"<<endl;



                cout<<"Jeigu norite rusiuoti pagal pavarde spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal varda spauskite 2: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 4: "<<endl;

                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(xyz==1){
                    sort(C.getPav().begin(),C.getPav().end());
                }
                if(xyz==2){
                    sort(C.getVar().begin(),C.getVar().end());
                }
                if(xyz==3){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                }
                if(xyz==4){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                }

                cout<<"Jeigu norite isvesti i ekrana- spauskite 1: "<<endl;
                cout<<"Jeigu norite isvesti i faila- spauskite 2: "<<endl;
                cout<<"Jusu pasirinkimas: ";

                while (!(cin >> o)) {
                    cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(o==1){
                    rezultatai(P);
                }
                if(o==2){
                    rezultataifailas(P, "isvestis.txt");
                }

                break;
            }

            case 5:{
                Pazymiai C;
                cout<<"1k :"<<endl;
                generuojam(1000, "1k.txt");
                cout<<"10k :"<<endl;
                generuojam(10000, "10k.txt");
                cout<<"100k :"<<endl;
                generuojam(100000, "100k.txt");
                cout<<"1mln :"<<endl;
                generuojam(1000000, "1kk.txt");
                cout<<"10mln :"<<endl;
                generuojam(10000000, "10kk.txt");
                cout<<"Failai sugeneruoti! "<<endl;
                cout<<endl;
            }

            case 6:{
                Pazymiai C;
                cout << "Pasirinkite strategija 1, 2, 3, 4: ";
                int strategy;
                cin >> strategy;

                const vector<string> filenames = {"1k.txt", "10k.txt", "100k.txt", "1kk.txt", "10kk.txt"};
                const vector<string> lopukaiFilenames = {"lopukai1.txt", "lopukai2.txt", "lopukai3.txt", "lopukai4.txt", "lopukai5.txt"};
                const vector<string> saunuoliukaiFilenames = {"saunuoliukai1.txt", "saunuoliukai2.txt", "saunuoliukai3.txt", "saunuoliukai4.txt", "saunuoliukai5.txt"};

                for (size_t i = 0; i < filenames.size(); ++i) {
                    cout << filenames[i] << " :" << endl;
                    switch (strategy) {
                        case 1:
                            failuskaickstrategija1(filenames[i], C, S, P, Z);
                            break;
                        case 2:
                            failuskaickstrategija2(filenames[i], C, P, Z);
                            break;
                        case 3:
                            failuskaickstrategija3(filenames[i], C, S, P, Z);
                            break;
                        case 4:
                            failuskaick(filenames[i], C, P, Z);
                            break;
                        default:
                            cout << "Tokia strategija neegzistuoja!" << endl;
                            break;
                    }
                    spausdintuvas(lopukaiFilenames[i], saunuoliukaiFilenames[i], P, Z);
                }
                break;
            }

            case 7:{
                testai();
                break;
            }
            case 8:{
                cout<<"Programa baigta."<<endl;
                return 0;
                break;
            }
        }
    }
    return 0;
}
