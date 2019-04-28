#include <fstream>
#include <iostream>
#include <cmath>
#include <math.h>
#include <ctime>


int cityamount;
int **distances;


bool fileread();
void writetab(int**);
void TabuSearch();

int  main()
{
    srand(time(NULL));
    fileread();
    TabuSearch();
}



bool fileread()         // funkcja do odczytywania danych z pliku
{
    std::string filename = "ftv47.atsp";
    std::fstream plik;
    plik.open(filename,std::ios::in);
    if(plik.good())                         // sprawdzenie poprawnosci wczytania pliku, w razie niepowodzenia zwracamy blad
    {
        plik>>cityamount;
        distances = new int* [cityamount];   // dwuwymiarowa tablica dynamiczna
        for(int i=0;i<cityamount;++i)
            distances[i]=new int[cityamount];
        for(int i=0;i<cityamount;++i)       // zapelnianie tablicy danymi z pliku
            for(int j=0;j<cityamount;++j)
                plik>>distances[i][j];
        return 1;
    }
    return 0;
}

void writetab(int** cities)                 // wypisywanie aktualnej macierzy przejsc miedzy miastami
{
    std::cout << "\n\n";
    std::cout << cityamount << '\n';
    for(int i=0;i<cityamount;++i)
    {
        for(int j=0;j<cityamount;++j)
            std::cout<<cities[i][j]<<" ";
        std::cout<<"\n";
    }
}

void TabuSearch()
{
    int iterationWoImprovement, maxIterationWoImprovement = 10;    //okreslenie maksymalnej ilosci iteracji bez poprawy, po osiagnieciu ktorej program skonczy prace, jak rowniez deklaracja iteratora
    int tabuSize = cityamount;      // ilosc przejsc zapamietanych w tabu
    int iteration = 0;      // iterator trzymajacy informacje o tym ile razy program wykonal algorytm

    int** tabuList = new int*[cityamount];             // inicjalizacja tablicy Tabu w rozmiarze x*x
    for(int i = 1; i < cityamount; i++)
        tabuList[i] = new int[cityamount];

    for(int i = 1; i < cityamount; i++)                 // pierwotne zerowanie tabu
        for(int j = 1; j < cityamount; j++)
            tabuList[i][j] = 0;

	int* bestPath = new int[cityamount + 1];      //sciezka i waga optymalnego rozwiazania
	int bestCost = INT_MAX;

	int* tempBestPath = new int[cityamount + 1];  //sciezka i waga optymalnego rozwiazania tymczasowego
	int tempBestCost = INT_MAX;
    tempBestPath[0] = tempBestPath[cityamount] = iterationWoImprovement = 0;

    int* tempPath = new int [2];                    // miasta aktualnie badanego sasiedztwa

    int tempCost = INT_MAX;
    int bestResult = INT_MAX;
    int temp = 0;

    bool* cityB = new bool[cityamount + 1];            //stworzenie tablicy mowiacej czy dana liczba juz wystapila w sekwencji
    cityB[0] = cityB[cityamount] = true;              //podpisanie pierwszego i ostatniego elementu jako juz wykonanego
    for(int i = 1; i < cityamount; i++)                 //podpisanie pozostalych jako niewykonanych
        cityB[i] = false;


    for(int i = 1; i < cityamount; ++i)                // tworzenie pierwszej sekwencji, ustawienie pierwszego miasta jako poczatkowego i koncowego zostalo juz wykonane dlatego pomijamy
    {
        if(i < 2) // poczatkowa sekwencja miast (i + nr_pierwszego_arg_w_argv - 1) ##############################################################################################
        {
            tempBestPath[i] = 3;  // 3 -> atoi(argv[i+x])
            cityB[3] = true;    // 3 -> atoi(argv[i+x])
        }
        else
        {

        }


    delete[] cityB;


    for(int i = 0; i < cityamount; i++)
        delete[] tabuList[i];
    delete[] tabuList;
    delete[] tempBestPath;
	  delete[] bestPath;
    delete[] tempPath;
}

