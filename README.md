# objektinis_programavimas

# Programos veikimas panaudojant vector konteinerį

Paleidus programą vartotojas mato meniu:

1. Įvesti duomenis ranka
2. Įvesti vardus ir pavardes ranka, o pažymius generuoti atsitiktinai
3. Atsitiktinai generuoti viską
4. Nuskaityti duomenis iš failo ir duomenis išvesti terminale
5. Nuskaityti duomenis iš failo ir duomenis išvesti atskirame faile
6. Įveskite kiekį studentų, kurį norite sugeneruoti
7. Vector konteinerio testavimas
8. Klases testavimas
9. Baigti programą
Pasirinkus pirmą variantą vartotojas pasirenka, kokį kiekį studentų nori įvesti ,tada atitinkamam kiekiui studentų prašoma įvesti ir vardus, pavardes, paklausiama, kokį kiekį namų darbų vartotojas nori įvesti, jį įvedus programa išveda įvestus duomenis terminale.

Pasirinkus antrą variantą pradžia išlieka tokia pat, tačiau įvedus norimą namų darbų pažymių kiekį, programa juos sugeneruoja atsitiktinai.

Pasirinkus trečią variantą programa atsitiktinai generuoja vardus, pavardes, ir pažymius, galima pasirinkti norima matyti medianą ar vidurkį.

Pasirinkus ketvirtą variantą programa nuskaito jau esamus failus, įvedus skaičių duomenų, kurį norima nuskaityti, programa klausia, ar norima matyti medianą ar vidurkį. Tada galima uždėti pasitinktiną filtrą – duomenis rūšiuoti pagal vardą, pavardę, medianą ar vidurkį. Po atliktų pasirinkimų duomenys išvedami terminale.

Pasirinkus penktą variantą pradžia išlieka identiška ketvirto pasirinkimo atveju, tačiau duomenys išvedami į atskirą, naujai sukuriamą failą.

Šeštas pasirinkimas vartotojo reikalauja pasirinkti kiekį studentų, kurį norima sugeneruoti. (Testavimai atlikti su 1000, 10000, 100000, 1000000, 10000000 duomenų įrašų faile.) Įvedus pasirinkimą programa praneša vartotojui, jei duomenys sugeneruoti sėkmingai. (Duomenys generuojami atskirame faile „studentai.txt“) Programa skaičiuoja laiką, kiek užtruko sugeneruoti failą, bei kiek užtruko failą nuskaityti. Po pranešimo vartotojas gali pasirinkti, kaip nori rūšiuoti duomenis – pagal vidurkį ar pagal medianą. Po vartotojo pasirinkimo atitinkamai apskaičiuojamas kiekivieno studento vidurkis arba mediana, tada studentai rūšiuojami į „gerus“ (kurių vidurkis 5 ir daugiau) bei į „blogus“ (kurių vidurkis mažiau nei 5). Pateikiamas laikas, kiek užtruko studentų rūšiavimas bei įrašymas į failus.

Septintas ir astuntas pasirinkimai paleidžia testavimą.

Devintas pasirinkimas užbaigia programą bei išveda bendrą visos programos veikimo laiką.

# class vs bazine ir derived 

| class | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 6,012 s | 0,830 s | 2,518 s |
| 10000000 | 45,833 s | 4,850 s | 20,175 s |

| b ir d | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 9,213 s | 1,289 s | 0,973 s |
| 10000000 | 71,866 s | 7,818 s | 15,619 s |



-----------------------------------------------------------------------------------------------------------------------------------------

# DOKUMENTACIJA

Dokumentacijai padaryti naudojau doxygen. Pirmiausiai instaliavau programa, kaip tai padaryti placiau aiskinama cia: https://www.doxygen.nl/manual/install.html

Suinstaliavus doxygen reikejo kode sudelioti komentarus, kuriuos doxygen identifikuoja naudodamas bloko (/** ... /), vienos eilutes (/// ...) arba Qt stiliaus (/! ... */) formatus. Siuose komentaruose specialiomis zymemis, tokiomis kaip @brief, @param ir @return, pateikiama konkreti informacija apie klases, funkcijas ir parametrus. Norint sukurti dokumentacija, sukuriamas ir pritaikomas Doxyfile konfiguracijos failas ir paleidziamas doxygen, kad isvestis butu parengta tokiais formatais kaip HTML arba LaTeX, taip paverciant eilutes kodo komentarus strukturizuotais issamiais dokumentais.

Kad sugeneruociau PDF dokumentacijos faila instaliavau MiKTeX, kaip ta padaryti placiau rasoma cia: https://miktex.org/download


Instaliavus MiKTeX, komandineje eiluteje darbas atrode taip:

1. naudodama cd komanda atsidariau jau padaryta latex aplanka
   
    1.1. cd desktop/du/latex
2. tam, kad sugeneruotu pdf faila is latex, rasiau tokias komandas
   
    2.1.  pdflatex refman.tex
   
          makeindex refman.idx
   
          pdflatex refman.tex
   
          pdflatex refman.tex
   

REZULTATAS: latex aplanke sugeneruojamas pdf failas refman.pdf, kuris ir yra dokumentacija pdf formatu

---------------------------------------------------------------------------------------------------------------------------------------------

# TESTAVIMAS

Testavimui ivykdyti naudojau catch2 testus, juos parsisiunciau is cia: https://github.com/catchorg/Catch2

Siunciausi naujausia v2.13.10 releasa, kad veiktu su macOS operacine sistema.

testavimo rezultatai:
![image](https://github.com/robke0224/objektinisprgrmvms/assets/154459735/289da611-d71f-47d5-8ed5-7c26cfecc100)


-----------------------------------------------------------------------------------------------------------------------------------------------

# v3.0

Testavimai, palyginimas kiek vidutiniškai laiko užtrunka std::vector tipo ir mano Vector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją.
<img width="634" alt="Screenshot 2024-05-29 at 08 26 31" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/00035d65-8e0e-469e-ba3a-29ffedc0f4f2">

<img width="799" alt="Screenshot 2024-05-29 at 08 25 43" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/c23815b6-da9d-4308-bd5b-dbb5377e7ad1">

----------------------------------------------------------------------------------------------------------------------------------------------

push back

<img width="634" alt="Screenshot 2024-05-29 at 08 31 18" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/d4f0c535-2350-4115-b027-c4473d2f54c4">

pop back

<img width="634" alt="Screenshot 2024-05-29 at 08 31 33" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/29e3f196-eddd-4091-91a8-b191fdf768f1">

resize

<img width="634" alt="Screenshot 2024-05-29 at 08 34 43" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/9018efc2-fece-44e8-a8b8-3690d7c2235b">

insert

<img width="634" alt="Screenshot 2024-05-29 at 08 36 17" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/a5e2aa02-eb26-4117-adfa-f7189a3c517c">

------------------------------------------------------------------------------------------------------------------------------------------------
Palyginu kiek kartų įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100 000 000 elementų.

        unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
        std::vector<int> v1;
        int std_vector_perskirstymas = 0;
        for (int i = 1; i <= sz; ++i) {
            v1.push_back(i);
            if (v1.capacity() == v1.size()) {
                ++std_vector_perskirstymas;
            }
        }
        cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

        Vector<int> v2;
        int vector_perskirstymas = 0;
        for (int i = 1; i <= sz; ++i) {
            v2.push_back(i);
            if (v2.capacity() == v2.size()) {
                ++vector_perskirstymas;
            }
        } 
        cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;



--------------------------------------------------------------------------------------------------------------------------------------------------

# Spartos analize


| Vector Size | Nuskaitymas | Skirstymas | Rūšiavimas | Išvedimas | 
|-------------|-------------|------------|------------|-----------|
| 100,000     | 0.147 s     | 0.026 s    | 0.078 s    | 0.300 s   |
| 1,000,000   | 2.972 s     | 0.368 s    | 0.899 s    | 3.081 s   | 
| 10,000,000  | 25.211 s    | 3.701 s    | 11.602 s   | 48,204 s  |


| std::vector Size | Nuskaitymas | Skirstymas | Rūšiavimas | Išvedimas |
|------------------|-------------|------------|------------|-----------|
| 100,000          | 0.141 s     | 0.013 s    | 0.030 s    | 0.356 s   |
| 1,000,000        | 3.828 s     | 0.368 s    | 0.326 s    | 4.011 s   |
| 10,000,000       | 26.233 s    | 2.962 s    | 3.555 s    | 38.314 s  |

----------------------------------------------------------------------------------------------------------------------------------------------------







