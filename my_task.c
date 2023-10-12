#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void signupFun(struct User users[], int *userCount) {
    printf("Enter username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter password: ");
    scanf("%s", users[*userCount].password);
    (*userCount)++;
    printf("Account created successfully!\n");
}

int loginFun(struct User users[], int userCount, char username[], char password[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    struct User users[100]; 
    int userCount = 0; 

    int choice;
    char username[50];
    char password[50];

    do {
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice==1){
            signupFun(users, &userCount);
        }else if(choice==2){
            printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (loginFun(users, userCount, username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. username or password is incorrect.\n");
                }
        }else if(choice==3){
            printf("Exit successfully \n");
        }else{
            printf("Enter choice between [1, 3].\n");
        }

    } while (choice != 3);

    return 0;
}
