# objektinis_programavimas

# Programos veikimas panaudojant vector konteinerį

Paleidus programą vartotojas mato meniu:
1.	Įvesti duomenis ranka
2.	Įvesti vardus ir pavardes ranka, o pažymius generuoti atsitiktinai
3.	Atsitiktinai generuoti viską
4.	Nuskaityti duomenis iš failo ir duomenis išvesti terminale
5.	Nuskaityti duomenis iš failo ir duomenis išvesti atskirame faile
6.	Įveskite kiekį studentų, kurį norite sugeneruoti 
7.	Baigti programą

   
*Pasirinkus* pirmą variantą vartotojas pasirenka, kokį kiekį studentų nori įvesti ,tada atitinkamam kiekiui studentų prašoma įvesti ir vardus, pavardes, paklausiama, kokį kiekį namų darbų vartotojas nori įvesti, jį įvedus programa išveda įvestus duomenis terminale.

*Pasirinkus* antrą variantą pradžia išlieka tokia pat, tačiau įvedus norimą namų darbų pažymių kiekį, programa juos sugeneruoja atsitiktinai.

*Pasirinkus* trečią variantą programa atsitiktinai generuoja vardus, pavardes, ir pažymius, galima pasirinkti norima matyti medianą ar vidurkį.

*Pasirinkus* ketvirtą variantą programa nuskaito jau esamus failus, įvedus skaičių duomenų, kurį norima nuskaityti, programa klausia, ar norima matyti medianą ar vidurkį. Tada galima uždėti pasitinktiną filtrą – duomenis rūšiuoti pagal vardą, pavardę, medianą ar vidurkį. Po atliktų pasirinkimų duomenys išvedami terminale.

*Pasirinkus* penktą variantą pradžia išlieka identiška ketvirto pasirinkimo atveju, tačiau duomenys išvedami į atskirą, naujai sukuriamą failą.

*Šeštas* pasirinkimas vartotojo reikalauja pasirinkti kiekį studentų, kurį norima sugeneruoti. (Testavimai atlikti su  1000, 10000, 100000, 1000000, 10000000 duomenų įrašų faile.) Įvedus pasirinkimą programa praneša vartotojui, jei duomenys sugeneruoti sėkmingai. (Duomenys generuojami atskirame faile „studentai.txt“) Programa skaičiuoja laiką, kiek užtruko sugeneruoti failą,  bei kiek užtruko failą nuskaityti. Po pranešimo vartotojas gali pasirinkti, kaip nori rūšiuoti duomenis – pagal vidurkį ar pagal medianą. Po vartotojo pasirinkimo atitinkamai apskaičiuojamas kiekivieno studento vidurkis arba mediana, tada studentai rūšiuojami į „gerus“ (kurių vidurkis 5 ir daugiau) bei į „blogus“ (kurių vidurkis mažiau nei 5). Pateikiamas laikas, kiek užtruko studentų rūšiavimas bei įrašymas į failus.

*Septintas* pasirinkimas užbaigia programą bei išveda bendrą visos programos veikimo laiką.


# 	Repozitorijos klonavimas

Repozitoriją „objektinis_programavimas“ nuklonavau į savo kompiuterį. Tam terminale panaudojau komandą 

git clone https://github.com/robke0224/objektinis_programavimas.git

Tada sukūriau naują repozitoriją „objektinisprgrmvms“, toliau naudojau atitinkamas komandas:

git remote set-url origin https://github.com/robke0224/objektinisprgrmvms.git

git push -u origin master


# Testavimo sistemos parametrai

<img width="445" alt="image" src="https://github.com/robke0224/objektinisprgrmvms/assets/154459735/c7d8af55-d8b1-4383-a09a-09296d8d0dee">


# Testavimai
*Pirmuoju testavimo atveju palyginsime dviejų programų, atitinkamai naudojančių **struct** ir **class**, veikimo spartą su 1000000 ir 10000000 dydžio failais.*

*struct*

|         | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 7,845 s | 5,734 s | 0,223 s |
| 10000000 | 40,024 s | 43,167 s | 2,752 s |

----------------------------------------------------------------------------------------------------------------------------

*class*

|         | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 8,847 s | 11,127 s | 0,529 s |
| 10000000 | 62,001 s | 50,230 s | 5,753 s |


----------------------------------------------------------------------------------------------------------------------------

*Antruoju testavimu atveju palyginsime, kaip keičiasi programos sparta priklausomai nuo kompiliatoriaus optimizavimo lygio (kuris nurodomas per flag'us (-O, -O1, -O2, -O3). Papildomai stebėsime, kaip kinta programos dydis (KB), priklausomai nuo naudojamų flag'ų.*

*struct*

| -O | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 7,845 s | 5,734 s | 0,223 s |
| 10000000 | 40,024 s | 43,167 s | 2,752 s |


| -O1 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,581 s | 2,975 s | 0,078 s |
| 10000000 | 17,125 s | 35,136 s | 1,192 s |

| -O2 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,522 s | 2,892 s | 0,068 s |
| 10000000 | 17,157 s | 35,302 s | 1,283 s |

| -O3 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,552 s | 3,092 s | 0,071 s |
| 10000000 | 17,218 s | 40,561 s | 1,388 s |

------------------------------------------------------------------------------------------------------------

*class*

|   -O  | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 8,847 s | 11,127 s | 0,529 s |
| 10000000 | 62,001 s | 50,230 s | 5,753 s |

| -O1 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,672 s | 3,619 s | 0,108 s |
| 10000000 | 18,038 s | 40,592 s | 1,358 s |

| -O2 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,608 s | 3,584 s | 0,106 s |
| 10000000 | 17,487 s | 45,903 s | 1,470 s |

| -O3 | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 1,558 s | 3,591 s | 0,108 s |
| 10000000 | 16,992 s | 40,142 s | 1,497 s |

-----------------------------------------------------------------------------------------------------------

# Unix Executable File dydis 

|       | -O   | -O1  | -O2  | -O3  |
|------|------|------|------|------|
| *struct* | 189 KB | 201 KB | 217 KB | 226 KB |
| *class*  | 197 KB | 214 KB | 226 KB | 257 KB |

