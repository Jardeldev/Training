#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int choice;
int size;
int i;

struct CineManager
{
    char clientName[50];
    int movieCode[50];
};

struct CineMovies
{
    char addTitleMovie[50];
    int addMovieCode[50];
    int addExpirationDay[50];
};


struct CineRegister
{
    char addClientName[50];
    int codeUser[50];
};

bool verifyCodeUser(int codeUser, int size, int database[]) {
    for (int i = 0; i < size; i++) {
        if (database[i] == codeUser) {
            return true;
        }
    }
    return false;   
}

void option1(struct CineManager *manager, char *clientName, struct CineRegister *database, int size) {
    int codeUser;
    printf("Type the code user: \n");
    scanf("%d", &codeUser);
    if (verifyCodeUser(codeUser, size, database->codeUser))
        {
           printf("Client Found!\n");
            printf("Name: %s\n, Code User: %d\n", clientName, codeUser);
        } else {
            printf("Invalid code, register a new user.");
        }
}

void option2(struct CineMovies movies, char *addTitleMovie, int *addMovieCode, int *addExpirationDay) {
    printf("1 - Add new movie \n");
    scanf("%d", &choice);
    printf("2 - List all movies \n");
    scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Type the title movie: \n");
            scanf("%s", addTitleMovie);
            while (1)
            {
            printf("Type the movie code: \n");
            if (scanf("%d", addMovieCode) != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n');
                continue;
            }
            printf("Type the expiration day: \n");
            if (scanf("%d", addExpirationDay) != 1) {
            printf("Invalid input. Please enter an integer. \n");
            while (getchar() != '\n');
            continue; 
            } 
            else {
                scanf("%d", &choice);
                if (choice == 2)
                    printf("Movie: %s | Movie Code: %d | Expiration Day: %d", addTitleMovie, *addMovieCode, *addExpirationDay);
            else {
                printf("Invalid choise! Try again.");
            }
        }
}
        }
}

void option3(struct CineRegister *database, char *addClientName) {
    int codeUser;
    printf("Type the client name: \n");
    scanf("%s", addClientName);
    while (1)
    {
        printf("Type the code client: \n");
        if (scanf("%d", &codeUser) == 1)
        {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
        
    }
}

void showMenu() {
    printf("\nMenu\n");
    printf("1 - Rent Movies\n");
    printf("2 - Manager Movies\n");
    printf("3 - Manager Clients\n");
    printf("4 - Exit\n");
    printf("\nEnter your choice: \n");
    }

int main () {

    struct CineManager manager;
    struct CineMovies movies;
    struct CineRegister database;

    do
    {
        showMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            option1(&manager, manager.clientName, &database, size);
            break;
        case 2:
            option2(movies, movies.addTitleMovie, movies.addMovieCode, movies.addExpirationDay);
            break;
        case 3:
            option3(&database, database.addClientName);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choise! Please try again.");
        }
    } while (choice != 4);

    return 0;
}