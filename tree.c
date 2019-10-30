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
    error_messages(etages); // Affiche les messages d'erreur

    int axe = get_axe(etages);
    int *ptraxe = &axe;                  // Garde la valeur de l'axe en fonction du nombre d'étages (Base du dernier etage / 2)
    for (int i = 1; i <= etages; i++)   // Dessine chaque etage
    {
        draw_last_triangle(i);
        print_tree(i, ptraxe);
    }
    print_trunk(etages, ptraxe);  // Dessine le tronc
}

int *draw_last_triangle(int etages)
{
    int *init = malloc(4*sizeof(int)); // Tableau que la fonction return
    int debut = 1;                     // Nb d'* de la première ligne d'un étage
    int lignes = 4;                    // Nombre de lignes de l'étage
    int base = 7;                      // Nb d'* de la derniere ligne d'un étage
    int compteur = 4;                  // Nb d'* à rajouter à chaque première ligne (début)

    if (etages > 1)
    {
        for (int i = 1; i < etages; i++)  // Pour chaque etage
        {
            if ( (i%2) == 0)  // Si l'étage est paire, le nb d'* a rajouter sur la première ligne augmente (début) 
            {
                compteur += 2; 
            }
            debut = debut + compteur;  // Incrémente le nb d'* a rajouter sur la première ligne (début)
            lignes++;                  // Incrémente le nb de lignes (+1 ligne par étage)
            base = debut + ((lignes-1) * 2);  //Le nombre d'* de la base
        }
    }
    
    init[0] = debut;    // Place les valeurs de chaque variable dans le tableau à return
    init[1] = lignes;
    init[2] = base;
    init[3] = compteur;
    
    return (init);
}


void print_tree(int etages, int* ptraxe)  // affiche le sapin
{
    int *init = draw_last_triangle(etages); 
    int debut = init[0];  // Recupération des valeurs
    int lignes = init[1];  

    for (int i = 0; i < lignes; i++)  // Pour chaque lignes
       {
           for (int k = 0; k < *ptraxe - (debut/2) ; k++) // ptraxe = axe central (base/2) - nb d'étoiles (debut)/2
            {
                my_putchar(' ');    //Mettre autant d'espace que la position de l'axe - la taille de la ligne/2
            }
            

           for (int j = 0; j < debut; j++)  // afficher autant d'* que la taille de la ligne (-1 à chaque tour)
           {
               my_putchar('*');
           }
           my_putchar('\n');
           debut += 2; // incrementer début de 2 a chaque itération pour mettre 2 etoiles de plus a chaque etage
       }
}

int get_axe(int etages)  // récupère la taille de la base du dernier etage et la divise par 2 pour obtenir l'axe central (position de la premiere etoile)
{
    int *init = draw_last_triangle(etages); 
    int base = init[2];
    int axe = (base/2);

    return axe;
}

void print_trunk(int etages, int *ptraxe)  // affiche le tronc
{
    int *init = draw_last_triangle(etages); 
    int compteur = 1; // Représente le nb d'| (qui augmente de 2 a chaque etage impaire)

    for (int i = 1; i <= etages; i++) // en fonction du nombre d'étages
    {
        if ((i%2) == 0) // utilise le compteur pour ajouter 2 pipe a chaque fois que l'étage est pair
        {
            compteur += 2;
        }
    }
    
    for (int i = 1; i <= etages; i++) // une fois qu'on a le bon nombre d'| à afficher (compteur)
    {

        for (int j = 0; j < (*ptraxe) - compteur/2; j++) // afficher autant d'espaces que la moitié de l'axe - le nb d'| qui augmente /2
        {
            my_putchar(' ');
        }   

        for (int l = 0; l < compteur; l++)   // affiche autant d'etages de | que d'étages de sapin
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