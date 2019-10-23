#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
void print_tree(int etages, int* ptraxe);
int *draw_last_triangle(int etages);
int get_axe(int etages);
void print_trunk(int etages, int *ptraxe);
int error_messages(int etages);

void tree(int etages)
{
    error_messages(etages);

    int axe = get_axe(etages);
    int *ptraxe = &axe;
    for (int i = 1; i <= etages; i++)
    {
        draw_last_triangle(i);
        print_tree(i, ptraxe);
    }
    print_trunk(etages, ptraxe);
}

int *draw_last_triangle(int etages)
{
    int *init = malloc(4*sizeof(int));
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
    init[3] = compteur;
    
    return (init);
}


void print_tree(int etages, int* ptraxe)
{
    int *init = draw_last_triangle(etages); 
    int debut = init[0];
    int lignes = init[1];  

    for (int i = 0; i < lignes; i++)
       {
           for (int k = 0; k < *ptraxe - (debut/2) + 1; k++) // ptraxe = axe central (base/2) - nb d'étoiles (debut)/2
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

int get_axe(int etages)
{
    int *init = draw_last_triangle(etages); 
    int base = init[2];
    int axe = (base/2);

    return axe;
}

void print_trunk(int etages, int *ptraxe)
{
    int *init = draw_last_triangle(etages); 
    int compteur = 1;

    for (int i = 1; i <= etages; i++) // en fonction du nombre d'étages
    {
        if ((i%2) == 0) // utilise le compteur pour ajouter 2 pipe a chaque fois que l'étage est pair
        {
            compteur += 2;
        }
    }
    
    for (int i = 1; i <= etages; i++)
    {

        for (int j = 0; j < (*ptraxe +1) - compteur/2; j++) // afficher autant d'espaces que la moitié de l'axe 
        {
            my_putchar(' ');
        }   

        for (int l = 0; l < compteur; l++) 
        {
            my_putchar('|');
        }
        my_putchar('\n');     
    }
}

int error_messages(int etages)
{
    if(etages < 0)
    {
        printf("Erreur ! Essayez avec une valeur positive (supérieure à 0) !\n");
        return(84);
    }
    if(etages == 0)
    {
        printf("Erreur ! Essayez avec une valeur supérieure à 0 !\n");
        return(84);
    }
}