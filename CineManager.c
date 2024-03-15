#include <stdio.h>
#include <stdlib.h>

struct CineManager
{
    char clientName[50];
    int codeUser;
    int movieCode;
};

int main () {
    struct CineManager database;
    printf("Type the client name:\n");
    scanf(" %[^\n]", database.clientName);
    printf("Type the code user:\n");
    scanf("%d", &database.codeUser);
    printf("Type the movie code:\n");
    scanf("%d", &database.movieCode);

}