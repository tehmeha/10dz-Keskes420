#include<iostream>
using namespace std;
#include<fstream>

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
    int i, n = filesize()) / VELICINA_STRUKTURE;
   korisnik *ts = new korisnik[n];
   ifstream in("imenik1.dat");
   i=0;
   while (i<n)
   {
        in.read((char *)(&ts[i]), sizeof(ts[n]));
        i++;
   }
   in.close();
   void bsort(korisnik niz[], int duzinaNiza)
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
                   {zamjeni(niz[j], niz[j+1]);
               }
           }
       }
   }
   }
    return 0;
}
