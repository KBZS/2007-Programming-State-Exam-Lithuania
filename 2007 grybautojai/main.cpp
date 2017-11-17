#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct gtipai
{
    string gvardas;
    int bar=0;
    int rau=0;
    int lep=0;
};

void nuskaitymas();
void skaiciavimai();
void spausdinimas();

int n, sk=0;
int bar=0, rau=0, lep=0;
int maxn = 0, laik = 0, nr;

gtipai G[100];

int main()
{
    nuskaitymas();
    skaiciavimai();
    spausdinimas();
    /*for(int i = 0; i<n; i++)
    {
        cout << G[i].bar << endl;
    }*/
    return 0;
}

void nuskaitymas()
{
    char eil[15];
    ifstream fd("U1.txt");
    fd >> n;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 15);
        G[i].gvardas = eil;
        fd >> sk;
        fd.ignore();
        for(int j=0; j<sk; j++)
        {
            fd >> bar;
            G[i].bar = G[i].bar + bar;
            fd >> rau;
            G[i].rau = G[i].rau + rau;
            fd >> lep;
            G[i].lep = G[i].lep + lep;
            fd.ignore();
        }
    }
    fd.close();
}

void skaiciavimai()
{
    for(int i=0; i<n; i++)
    {
        laik = G[i].bar + G[i].rau + G[i].lep;
        if(laik>maxn)
        {
            maxn = laik;
            nr=i;
        }
    }
}

void spausdinimas()
{
    ofstream fr("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        fr << G[i].gvardas << G[i].bar << '\t' << G[i].rau << '\t' << G[i].lep << endl;
    }
    fr << G[nr].gvardas << maxn << endl;
    fr.close();
}

