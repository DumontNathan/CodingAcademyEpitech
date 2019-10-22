#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
void print_tree(int etages);
int *draw_last_triangle(int etages);


void tree(int etages)
{
    for (int i = 1; i <= etages; i++)
    {
        draw_last_triangle(i);
        print_tree(i);
    }
    
}

int *draw_last_triangle(int etages)
{
    int *init = malloc(2*sizeof(int));
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
    
    return (init);
}


void print_tree(int etages)
{
    int *init = draw_last_triangle(etages); 
    int debut = init[0];
    int lignes = init[1];   


    for (int i = 0; i < lignes; i++)
       {
           for (int k = 0; k < lignes - i; k++) // nb d'espaces (- i a chaque etage pour reduire le nombre d'espace a chaque iteration)
            {
                my_putchar(' ');
            }

           for (int j = 0; j < debut; j++)  // afficher une etoile autant que la taille du debut
           {
               my_putchar('*');
           }
           my_putchar('\n');
           debut += 2; // incrementer début de 2 a chaque itération pour mettre 2 etoiles de plus a chaque etage
       }
}