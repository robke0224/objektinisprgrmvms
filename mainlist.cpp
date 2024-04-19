#include "pagalbineslist.h"
using namespace std;
    int pasirinkimas;
    int c;
    int x;
    int s;
    int i=0;

    list<Pazymiai> S, P, Z;

int main ()
{


    while (true){
        cout << "Pasirinkite norima veiksma list: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Failu generavimas" << endl;
        cout << "6. Sugeneruotu failu skaiciavimas"<<endl;
        cout << "7. Baigti programa" << endl;
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki 5. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pasirinkimas){
            case 1:{

                Pazymiai C;
                //auto it=C.paz.begin();
                do{

                    double suma=0.0;

                    cout<<"Iveskite "<<i+1<<" pavarde (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.pav;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }
                    cout<<"Iveskite "<<i+1<<" varda (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.var;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }

                    int j=0;

                    do{
                        cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                        cin>>x;

                        if(x==11){
                            break;
                        }

                        while (cin.fail() || x < 1 || x > 10 ) {

                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                                cin >> x;
                                if(x==11){
                                    break;
                                }

                        }

                        C.paz.push_back(x);
                        suma = suma + x;
                        j++;
                    } while(x!=11);

                    C.vid=suma/j;

                    cout << "Iveskite egzamino rezultata: " << endl;

                    try {
                        cin >> C.egz;

                        while (cin.fail() || C.egz < 1 || C.egz > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                            cin >> C.egz;
                        }
                    } catch (const std::exception& e) {

                        cerr << "Exception: " << e.what() << endl;

                    }

                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);
                    C.paz.sort();
                    //sort(C.paz.begin(), C.paz.end());

                    C.med=mediana(j,C);

                    P.push_back(C);
                    i++;
                } while(C.pav!="4" || C.var!="4");

                rezultatai(P);
                P.clear();
                break;
            }

            case 2:{

                Pazymiai C;
                auto it=C.paz.begin();
                do  {
                    double suma = 0.0;

                    cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.pav;
                    if (C.pav == "4" || C.var == "4") {
                        break;
                    }

                    cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.var;
                    if (C.pav == "4" || C.var == "4") {
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
                            C.paz.push_back((rand() % 10) + 1);
                            advance(it, h);
                            cout << "Pazymis " << h + 1 << " : " << *it << endl;
                            cout << "Ar norite testi generavima? taip arba ne: ";
                            cin >> y;
                            if (y != "taip" && y != "ne") {
                                cout << "Klaida. Prasome ivesti taip arba ne: ";
                                cin>>y;
                            }
                            suma = suma + *it;
                            h++;
                        }
                        C.vid = suma / h;

                        //sort(C.paz.begin(), C.paz.end());
                        C.paz.sort();
                        C.med=mediana(h,C);
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
                            C.paz.push_back((rand() % 10) + 1);
                            advance(it, l);
                            cout << "Pazymis " << l + 1 << " : " << *it << endl;
                            suma = suma + *it;
                        }

                        C.vid = suma / k;
                        C.paz.sort();
                        //sort(C.paz.begin(), C.paz.end());

                        C.med=mediana(k,C);
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
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;

                    try {
                        cin >> C.egz;
                        while (cin.fail() || C.egz < 1 || C.egz > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                            cin >> C.egz;
                        }
                        } catch (const std::exception& e) {
                            cerr << "Exception: " << e.what() << endl;
                            }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);
                    P.push_back(C);
                    i++;
                } while (C.pav != "4" || C.var != "4");

                rezultatai(P);
                P.clear();
                break;
            }

            case 3:{
                int qq = 0;

                string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"};
                string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"};

                while (qq != 1) {
                    Pazymiai C;
                    auto it=C.paz.begin();
                    C.pav = pavardes[rand() % 10];
                    C.var = vardai[rand() % 10];
                    cout << "Pavarde ir vardas: " << C.pav << " " << C.var << endl;

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
                            C.paz.push_back((rand() % 10) + 1);
                            advance(it, h);
                            cout << "Pazymis " << h + 1 << " : " << *it << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + *it;
                            h++;
                        }
                        C.vid = suma / h;

                        //sort(C.paz.begin(), C.paz.end());
                        C.paz.sort();

                        C.med=mediana(h,C);
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
                            C.paz.push_back((rand() % 10) + 1);
                            advance(it, l);
                            cout << "Pazymis " << l + 1 << " : " << *it << endl;
                            suma = suma + *it;
                        }

                        C.vid = suma / k;

                        //sort(C.paz.begin(), C.paz.end());
                        C.paz.sort();

                        C.med=mediana(k,C);
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
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: ";

                        while (!(cin >> C.egz) || (C.egz < 1 || C.egz > 10)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                        }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);

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
                P.clear();
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

                cout<<"Pasirinkite is kurio failo norite nuskaityti: "<<endl;
                cout<<"1. studentai10000 "<<"2. studentai100000 "<<"3. studentai1000000 "<<"4. kursiokai5 "<<endl;

                while (!(cin >> numeris) || numeris < 1 || numeris > 5) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (numeris) {
                    case 1:
                        wp = "1k.txt";
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
                    case 5:
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
                    C.paz.clear();
                    F>>C.pav>>C.var;

                    for(int i=0; i<pv; i++){
                        F>>z;
                        C.paz.push_back(z);
                        suma=suma+z;
                    }

                    //sort(C.paz.begin(), C.paz.end());
                    C.paz.sort();
                    C.vid=suma/pv;
                    F>>C.egz;
                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);
                    C.med=mediana(pv,C);
                    P.push_back(C);

                }

                deque<double> laikai;

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
                    P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.pav < b.pav;
                    });

                }
                if(xyz==2){
                    P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.var < b.var;
                    });
                }
                if(xyz==3){
                    P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.galutinis < b.galutinis;
                    });
                }
                if(xyz==4){
                    P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
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
                P.clear();
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
                cout<<"1k :"<<endl;
                //failuskaick("1k.txt", C, P, Z);
                //failuskaickstrategija1("1k.txt", C, S, P, Z);
                //failuskaickstrategija2("1k.txt", C,  P, Z);
                failuskaickstrategija3("1k.txt", C, S, P, Z);
                cout<<"Zsize "<< Z.size()<<endl;
                spausdintuvas("lopukai1.txt", "saunuoliukai1.txt", P, Z);
                cout<<"10k :"<<endl;
                //failuskaick("10k.txt", C, P, Z);
                //failuskaickstrategija1("10k.txt", C, S, P, Z);
                //failuskaickstrategija2("10k.txt", C, P, Z);
                failuskaickstrategija3("10k.txt", C, S, P, Z);
                spausdintuvas("lopukai2.txt", "saunuoliukai2.txt",P, Z);
                cout<<"100k :"<<endl;
                //failuskaick("100k.txt", C, P, Z);
                //failuskaickstrategija1("100k.txt", C, S, P, Z);
                //failuskaickstrategija2("100k.txt", C, P, Z);
                failuskaickstrategija3("100k.txt", C, S, P, Z);
                spausdintuvas("lopukai3.txt", "saunuoliukai3.txt",P, Z);
                cout<<"1mln :"<<endl;
                //failuskaick("1kk.txt", C, P, Z);
                //failuskaickstrategija1("1kk.txt", C, S, P, Z);
                //failuskaickstrategija2("1kk.txt", C, P, Z);
                failuskaickstrategija3("1kk.txt", C, S, P, Z);
                spausdintuvas("lopukai4.txt", "saunuoliukai4.txt",P, Z);
                cout<<"10mln :"<<endl;
                //failuskaick("10kk.txt", C, P, Z);
                //failuskaickstrategija1("10kk.txt", C, S, P, Z);
                //failuskaickstrategija2("10kk.txt",C, P, Z);
                failuskaickstrategija3("10kk.txt", C, S, P, Z);
                spausdintuvas("lopukai5.txt", "saunuoliukai5.txt", P, Z);
                break;
            }
            case 7:{
                cout<<"Programa baigta."<<endl;
                return 0;
                break;
            }
        }
    }
    return 0;
}
