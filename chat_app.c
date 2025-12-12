#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200


int main() {
    FILE *file = fopen("chat_history.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    char user1[50], user2[50];
    char message[MAX_LEN];
    int turn = 1;

    // Welcome screen
    for(int i = 0; i<=50; i++)
    {
    printf("*");
    }
    printf("\n*            WELCOME TO C CHAT APP           *\n");
   for(int i = 0; i<=50; i++)
    {
    printf("*");
    }
    printf("\n\nType 'exit' anytime to stop chatting!\n\n");

    // Get user names
    printf("Enter name of User 1: ");
    fgets(user1, sizeof(user1), stdin);
    user1[strcspn(user1, "\n")] = '\0';

    printf("Enter name of User 2: ");
    fgets(user2, sizeof(user2), stdin);
    user2[strcspn(user2, "\n\n")] = '\0';
    
    for(int i = 0; i<=50; i++)
    {
    printf("-");
    }
    printf("\nChat started between %s and %s!\n", user1, user2);
    for(int i = 0; i<=50; i++)
    {
    printf("-");
    }
     
     printf("\n\n");
    

    while (1) {
        if (turn == 1)
            printf("%s: ", user1);
        else
            printf("%s: ", user2);

        fgets(message, MAX_LEN, stdin);
        message[strcspn(message, "\n")] = '\0';

        if (strcmp(message, "exit") == 0)
            break;

        fprintf(file, "%s: %s\n", turn == 1 ? user1 : user2, message);

        turn = 3 - turn; 
    }

    fclose(file);

    for(int i = 0; i<=50; i++)
    {
    printf("-");
    }
    printf("\nChat saved to 'chat_history.txt'\n");
    for(int i = 0; i<=50; i++)
    {
    printf("-");
    }
    

    return 0;
}
