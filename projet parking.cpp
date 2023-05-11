#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  /*Dans le code fourni, la fonction "is_valid_vehicle_type" utilise la fonction "isalpha" de la bibliothèque ctype.h 
pour vérifier si chaque caractère dans le type de véhicule fourni est une lettre alphabétique ou non.*/

#define MAX_SPOTS 100 /* le nombre maximal de places de stationnement disponibles.*/

struct Vehicle {
    char type[10];
    char plate[10];
};
/*vérifie si le type de véhicule donné est valide */
int is_valid_vehicle_type(char* type) {
    for (int i = 0; type[i] != '\0'; i++) {
        if (!isalpha(type[i])) {
            return 0;
        } 
    }
    if (strcmp(type, "voiture") == 0 || strcmp(type, "scooter") == 0) {
        return 1;
    }
    return 0;
}
/*La fonction commence par boucler à travers chaque caractère de la chaîne "type". Si le caractère n'est pas une lettre alphabétique, 
la fonction renvoie immédiatement 0 (ce qui signifie que la chaîne n'est pas valide).
Si la boucle se termine sans renvoyer 0, cela signifie que tous les caractères de la chaîne "type" sont alphabétiques. 
Ensuite, la fonction compare la chaîne "type" avec les chaînes "voiture" et "scooter" à l'aide de la fonction "strcmp". 
Si la comparaison indique que la chaîne "type" est égale à l'une des deux chaînes, la fonction renvoie 1 pour indiquer que la chaîne est valide. 
Sinon, la fonction renvoie 0 pour indiquer que la chaîne est invalide.*/
int main() {
    int num_spots = MAX_SPOTS;
    struct Vehicle parking_spots[MAX_SPOTS];
    int num_vehicles = 0;

    while (1) {
        printf("\n\nApplication de système de stationnement\n");
        printf("1. Arrivée d'un véhicule\n");
        printf("2. Nombre total de véhicules stationnés\n");
        printf("3. Afficher l'ordre dans lequel les véhicules sont stationnés\n");
        printf("4. Supprimer un véhicule\n");
        printf("5. Quitter\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_vehicles < num_spots) {  
                    struct Vehicle vehicle;
                    char type[10];
                    do {
                        printf("Entrez le type de véhicule (voiture/scooter): ");
                        scanf("%s", type);
                        if (!is_valid_vehicle_type(type)) {
                            printf("Type de véhicule invalide. Veuillez réessayer.\n");
                        }
                    } while (!is_valid_vehicle_type(type));
                    strcpy(vehicle.type, type);
                    printf("Entrez le numéro de plaque: ");
                    scanf("%s", vehicle.plate);
                    parking_spots[num_vehicles] = vehicle;
                    num_vehicles++;  
                    printf("Véhicule stationné sur la place numéro %d.\n", num_vehicles);  /*Si une place de stationnement est disponible, le véhicule est ajouté au tableau parking_spots et num_vehicles est incrémenté */
                } else {
                    printf("Désolé, aucune place de stationnement disponible.\n");
                }
                break;
            }
            case 2: {
                printf("Nombre total de véhicules stationnés: %d\n", num_vehicles);
                break;
            }
            case 3: {
                printf("Ordre dans lequel les véhicules sont stationnés:\n");
                for (int i = 0; i < num_vehicles; i++) {
                    printf("Place numéro %d: %s avec plaque %s\n", i+1, parking_spots[i].type, parking_spots[i].plate);
                }
                break;  /* en affichant pour chaque véhicule sa place dans le tableau parking_spots, son type et son numéro de plaque.*/
            }
            case 4: {
                printf("Entrez le numéro de place du véhicule à supprimer: ");
                int spot_num;
                scanf("%d", &spot_num);
                if (spot_num < 1 || spot_num > num_vehicles) {
                    printf("Place invalide. Veuillez réessayer.\n"); 
                } else {
                    for (int i = spot_num-1; i < num_vehicles-1; i++) {
                        parking_spots[i] = parking_spots[i+1];
                    }
                    num_vehicles--;
                    printf("Véhicule supprimé de la place numéro %d.\n", spot_num); /*la place est valide, le véhicule est supprimé du tableau parking_spots et num_vehicles est décrémenté.*/
                }
                break;
            }
            case 5: {
                printf("Au revoir!\n");
                exit(0);
            }
            default: {
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
            }
        }
    }

    return 0;
}


