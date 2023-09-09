#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBMAX 52

const char* Enseigne[] = 
{
    "", "Carreau", "Coeur", "Pique", "Trefle"
};

const char* ValFig[] = 
{
    "", "1", "2", "3", "4", "5", "6", "7", "8", 
    "9", "10", "Valet", "Dame", "Roi"
};
typedef struct
{
    int enseigne;
    int valoufig;
} carte;
typedef struct
{
    int nbr;
    carte tab[NBMAX];
} paquet;
typedef struct
{
    int capa;
    int nbr;
    carte* tab;
} paquext;
void afficheCarte(carte c)
{
    printf("%s de %s\n",ValFig[c.valoufig],Enseigne[c.enseigne]);
}
void produitJeu52(paquet* p)
{

    p->nbr = 0;
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            carte c = {j,i};
            p->tab[p->nbr]=c;
            p->nbr++;
        }
    }
}
void videPaquet(paquet* p)
{
    p->nbr=0;
}
void affichePaquet(paquet* p)
{
    for(int i=0;i<p->nbr;i++)
    {
        afficheCarte((*p).tab[i]);
    }
}
void melangePaquet(paquet* p)
{
    int r;
    carte c={0,0};
    for(int i=0;i<p->nbr;i++)
    {
        r=rand()%(p->nbr);
        c=p->tab[i];
        p->tab[i]=p->tab[r];
        p->tab[r]=c;
    }
}
carte tireCarte(paquet* p)
{
    p->nbr = p->nbr - 1;
    carte carteRetiree = p->tab[p->nbr];
    p->nbr--;
    return carteRetiree;
}
void ajouteCarte(paquet* p, carte c)
{
    for(int i=0;i<p->nbr;i++)
    {
        if(p->tab[i].enseigne == c.enseigne && p->tab[i].valoufig ==c.valoufig) return; 
    }
    p->tab[p->nbr] = c;
    p->nbr++;
   
}
void initPaquext(paquext* p, int capacite)
{
    p->capa=capacite;
    p->nbr=0;
    p->tab = (carte*)malloc((p->capa)*sizeof(carte));
}
void liberePaquext(paquext* p)
{
    free(p->tab);
}
int main()
{
  carte c1 = {3,13};
  carte c2 = {2,6};
  afficheCarte(c1);
  afficheCarte(c2);
  printf("\n");
  printf("\n");
  paquet p;
  produitJeu52(&p);
  affichePaquet(&p);
  printf("\n");
  printf("\n");
  melangePaquet(&p);
  ajouteCarte(&p,c1);
  //tireCarte(&p);
  affichePaquet(&p);
  printf("\n");
  printf("\n");
  return 0;
}