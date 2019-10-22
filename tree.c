#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
void print_tree(int etages, int* ptraxe);
int *draw_last_triangle(int etages);
int get_axe(int etages);


void tree(int etages)
{
    int axe = get_axe(etages);
    int *ptraxe = &axe;
    
    for (int i = 1; i <= etages; i++)
    {
        draw_last_triangle(i);
       // print_spaces(i);
        print_tree(i, ptraxe);
    }
    
}

int *draw_last_triangle(int etages)
{
    int *init = malloc(3*sizeof(int));
    int debut = 1;
    int lignes = 4; 
    int base = 7;
    int compteur = 4;

    if (etages > 1)
    {
        for (int i = 1; i < etages; i++)  // pour chaque etage
        {
            if ( (i%2) == 0)  // si létage est paire, début = début + 2
            {
                compteur += 2; // compteur pour augmenter le nb d'étoile du debut a chaque nombre impaire
            }
            debut = debut + compteur;
            lignes++;
            base = debut + ((lignes-1) * 2);  //le nombre d'étoiles de la base
        }
    }
    
    init[0] = debut;
    init[1] = lignes;
    init[2] = base;
    
    return (init);
}


void print_tree(int etages, int* ptraxe)
{
    int *init = draw_last_triangle(etages); 
    int debut = init[0];
    int lignes = init[1];  

printf("%d", *ptraxe);
    for (int i = 0; i < lignes; i++)
       {
           for (int k = 0; k < *ptraxe + etages; k++) // 
            {
                my_putchar(' ');
            }
            (*ptraxe)--;

           for (int j = 0; j < debut; j++)  // afficher une etoile autant que la taille du debut
           {
               my_putchar('*');
           }
           my_putchar('\n');
           debut += 2; // incrementer début de 2 a chaque itération pour mettre 2 etoiles de plus a chaque etage
       }
}

int get_axe(int etages)
{
    int *init = draw_last_triangle(etages); 
    int base = init[2];
    int axe = (base/2);

    return axe;
}
