#include <stdio.h>
#include <stdlib.h>
void affTab(int* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", tab[i]);
    }
  printf("\n");
} 

void test()
{
    int t[] = {2,3,7,11,19};
    affTab(t,3);
    affTab(t+2,2);
}
void rempliTab(int* tab, int n, int val)
{
    for(int i=0; i<n; i++)
    {
        tab[i] = val;
    }
}
void fct(int* tab)
{
     rempliTab(tab,4,1);
     rempliTab(tab+4,4,2);
     rempliTab(tab+8,4,3);
}
void test2()
{
    int t[12];
    fct(t);
    affTab(t, 12);
}
void randTab(int* tab,int n,int min, int max)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=min+rand()%(max+1-min);
    }

}
void test3()
{
    int t[10];
    randTab(t,10,3,20);
    affTab(t,10);
}

double moyMinMax(const double tab[], int n, double* pmin, double* pmax)
{
    double s=0;
    double moy=0;
    double v_min,v_max;
    v_min = tab[0];
    v_max = tab[0];
    for(int i=1;i<n;i++)
    {
        
        if(v_min>tab[i])
        {
            v_min = tab[i];
        }
        else if(v_max<tab[i])
        {
            v_max = tab[i];
        }
        s+=tab[i]; 
    }
    moy=s/n;
    *pmin = v_min;
    *pmax = v_max;
    return moy;
}
void test4()
{
    double data[] = {10.0, 9.5, 13.0, 12.5};
    double min;
    double max;
    double moy = moyMinMax(data, 4, &min, &max);
    printf("%.02f %.02f %.02f\n", moy, min, max);
}
void insert(int tab[], int* n, int val)
{  
    int i=(*n)-1;//indice du dernier élément dans le tableau
    while(i>=0 && tab[i]>val)
    {   
        tab[i+1]=tab[i];
        i--;
    }
    //On va utiliser la dernière valeur initialiser de i dans la boucle while
    tab[i+1]=val;
    (*n)++;
}
void test5()
{
    int nVals = 0;
    int tab[100];
    insert(tab, &nVals, 12);
    insert(tab, &nVals, 9);
    insert(tab, &nVals, 10);
    affTab(tab, nVals);
}
int seek(int tab[], int posMin, int posMax, int val)
{
        int a = (posMin+posMax)/2;
        while(tab[a]!=val)
        {
            if(tab[a]==val)
            {
                continue;
            }
            else if(tab[a]<val)
            {
                posMin = a;
            }
            else if(tab[a]>val)
            {
                posMax = a;
            }
            else
            {
                return -1;
            }
        }
        return a;
}


int main()
{   

    test2();
    printf("\n");
    test3();
    printf("\n");
    test4();
    printf("\n");
    test5();
    int t[]={2, 3, 5, 7, 9, 12, 33, 34, 37, 52};
    //printf("%d",seek(t,0,9,9));
    printf("%02x\n", 0b111100 & 0b101);
    return 0;
}
