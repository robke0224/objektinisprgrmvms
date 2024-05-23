# objektinis_programavimas

# Programos veikimas panaudojant vector konteinerį

Paleidus programą vartotojas mato meniu:

1. Įvesti duomenis ranka
2. Įvesti vardus ir pavardes ranka, o pažymius generuoti atsitiktinai
3. Atsitiktinai generuoti viską
4. Nuskaityti duomenis iš failo ir duomenis išvesti terminale
5. Nuskaityti duomenis iš failo ir duomenis išvesti atskirame faile
6. Įveskite kiekį studentų, kurį norite sugeneruoti
7. Testavimas
8. Baigti programą
Pasirinkus pirmą variantą vartotojas pasirenka, kokį kiekį studentų nori įvesti ,tada atitinkamam kiekiui studentų prašoma įvesti ir vardus, pavardes, paklausiama, kokį kiekį namų darbų vartotojas nori įvesti, jį įvedus programa išveda įvestus duomenis terminale.

Pasirinkus antrą variantą pradžia išlieka tokia pat, tačiau įvedus norimą namų darbų pažymių kiekį, programa juos sugeneruoja atsitiktinai.

Pasirinkus trečią variantą programa atsitiktinai generuoja vardus, pavardes, ir pažymius, galima pasirinkti norima matyti medianą ar vidurkį.

Pasirinkus ketvirtą variantą programa nuskaito jau esamus failus, įvedus skaičių duomenų, kurį norima nuskaityti, programa klausia, ar norima matyti medianą ar vidurkį. Tada galima uždėti pasitinktiną filtrą – duomenis rūšiuoti pagal vardą, pavardę, medianą ar vidurkį. Po atliktų pasirinkimų duomenys išvedami terminale.

Pasirinkus penktą variantą pradžia išlieka identiška ketvirto pasirinkimo atveju, tačiau duomenys išvedami į atskirą, naujai sukuriamą failą.

Šeštas pasirinkimas vartotojo reikalauja pasirinkti kiekį studentų, kurį norima sugeneruoti. (Testavimai atlikti su 1000, 10000, 100000, 1000000, 10000000 duomenų įrašų faile.) Įvedus pasirinkimą programa praneša vartotojui, jei duomenys sugeneruoti sėkmingai. (Duomenys generuojami atskirame faile „studentai.txt“) Programa skaičiuoja laiką, kiek užtruko sugeneruoti failą, bei kiek užtruko failą nuskaityti. Po pranešimo vartotojas gali pasirinkti, kaip nori rūšiuoti duomenis – pagal vidurkį ar pagal medianą. Po vartotojo pasirinkimo atitinkamai apskaičiuojamas kiekivieno studento vidurkis arba mediana, tada studentai rūšiuojami į „gerus“ (kurių vidurkis 5 ir daugiau) bei į „blogus“ (kurių vidurkis mažiau nei 5). Pateikiamas laikas, kiek užtruko studentų rūšiavimas bei įrašymas į failus.

Septintas pasirinkimas paleidžia testavimą.

Aštuntas pasirinkimas užbaigia programą bei išveda bendrą visos programos veikimo laiką.

# class vs bazine ir derived 

| class | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 6,012 s | 0,830 s | 2,518 s |
| 10000000 | 45,833 s | 4,850 s | 20,175 s |

| b ir d | Nuskaitymas | Skirstymas | Rūšiavimas |
|----------|----------|----------|----------|
| 1000000  | 9,213 s | 1,289 s | 0,973 s |
| 10000000 | 71,866 s | 7,818 s | 15,619 s |
