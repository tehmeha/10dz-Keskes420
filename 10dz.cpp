#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;


struct korisnik
{
    int id;
     char Ime[20];
     char Prezime[20];
};
#define VELICINA_STRUKTURE 64

int filesize();
void zamjeni(korisnik& x, korisnik& y);
void bsort(korisnik niz[], int duzinaNiza);
main()
{
    int i, n = filesize() / VELICINA_STRUKTURE ;
   korisnik *ts = new korisnik[n];
   ifstream in("imenik1.dat");
   i=0;
   while (i<n)
   {
        in.read((char *)(&ts[i]), sizeof(ts[n]));
        i++;
   }
   in.close();
   bsort(ts, n);
   cout << endl << "Izgled zapisa nakon sortiranja po prezimenu: " << endl ;
   for (int i=0; i<n; i++)
   {
       cout << ts[i].Prezime << endl;
       cout << ts[i].Ime << endl;
       cout << ts[i].id << endl;
   }
   }
   int filesize()
   {
       ifstream in;
       in.open ("imenik1.dat", ios::binary );
       if (in.good()==false)
        {
            cout << "GRESKA: Datoteka se ne moze otvoriti!\n";
       }
       in.seekg (0, ios::end);
       int bajtova = in.tellg();
       in.close ();
       if (in.good()==false)
        {
            cout << "GRESKA: Datoteka se ne moze zatvoriti!\n";
       }
       return bajtova;
   }

   void bsort(int duzinaNiza, korisnik niz[])
   {
       int i, j, k;
       for (i=duzinaNiza-1; i>0; i--)
       {
           for (j=0; j<i; j++)
           {
               k=0;
               while (niz[j].Prezime[k] == niz[j+1].Prezime[k])
               {
                    k++;
               }
               if (niz[j].Prezime[k] > niz[j+1].Prezime[k])
               {
                   zamjeni(niz[j], niz[j+1]);
               }
           }
       }
   }

