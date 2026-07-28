#include <stdio.h>
#include <string.h>

// Structure
struct Restaurant
{
    char name[50];
    char location[50];
    char owner[50];
};

struct Mall
{
    char name[50];
    char location[50];
    char owner[50];
};

struct User
{
    char name[50];
    char email[50];
    char password[50];
};


// Global data
struct Restaurant restaurant;
struct Mall mall;
struct User user;


// Function Prototypes
void admin();
void userPanel();
void restaurantOwner();
void mallOwner();

void addRestaurant();
void viewRestaurant();

void addMall();
void viewMall();



// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== District Management System =====\n");

        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Restaurant Owner\n");
        printf("4. Shopping Mall Owner\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1:
                admin();
                break;

            case 2:
                userPanel();
                break;

            case 3:
                restaurantOwner();
                break;

            case 4:
                mallOwner();
                break;

            case 5:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }


    return 0;
}



// Admin Module

void admin()
{
    printf("\n--- Admin Panel ---\n");

    viewRestaurant();
    viewMall();
}



// User Module

void userPanel()
{
    printf("\n--- User Panel ---\n");

    printf("Enter User Name: ");
    scanf("%49s",user.name);

    printf("Enter Email: ");
    scanf("%49s",user.email);

    printf("Enter Password: ");
    scanf("%49s",user.password);

    FILE *userFile = fopen("users.txt", "a");
    if (userFile == NULL)
    {
        printf("Unable to open users file.\n");
    }
    else
    {
        fprintf(userFile, "%s %s %s\n", user.name, user.email, user.password);
        fclose(userFile);
        printf("User information saved to users.txt\n");
    }

    printf("\nWelcome %s\n",user.name);

    viewRestaurant();
    viewMall();

}



// Restaurant Owner Module

void restaurantOwner()
{
    printf("\n--- Restaurant Owner ---\n");

    addRestaurant();

}



// Shopping Mall Owner Module

void mallOwner()
{
    printf("\n--- Shopping Mall Owner ---\n");

    addMall();

}



// Restaurant Functions

void addRestaurant()
{

    printf("Restaurant Name: ");
    scanf("%49s",restaurant.name);

    printf("Owner Name: ");
    scanf("%49s",restaurant.owner);

    printf("Location: ");
    scanf("%49s",restaurant.location);

    FILE *restaurantFile = fopen("restaurants.txt", "a");
    if (restaurantFile == NULL)
    {
        printf("Unable to open restaurants file.\n");
    }
    else
    {
        fprintf(restaurantFile, "%s %s %s\n", restaurant.name, restaurant.owner, restaurant.location);
        fclose(restaurantFile);
        printf("Restaurant data saved to restaurants.txt\n");
    }

    printf("Restaurant Added Successfully!\n");

}



void viewRestaurant()
{
    printf("\n--- Restaurant Information ---\n");

    FILE *restaurantFile = fopen("restaurants.txt", "r");
    if (restaurantFile == NULL)
    {
        printf("No restaurants available yet.\n");
        return;
    }

    char name[50], owner[50], location[50];
    int count = 0;

    while (fscanf(restaurantFile, "%49s %49s %49s", name, owner, location) == 3)
    {
        count++;
        printf("Restaurant %d:\n", count);
        printf("  Name: %s\n", name);
        printf("  Owner: %s\n", owner);
        printf("  Location: %s\n", location);
    }

    fclose(restaurantFile);

    if (count == 0)
    {
        printf("No restaurants available yet.\n");
    }
}



// Mall Functions

void addMall()
{

    printf("Mall Name: ");
    scanf("%49s",mall.name);

    printf("Owner Name: ");
    scanf("%49s",mall.owner);

    printf("Location: ");
    scanf("%49s",mall.location);

    FILE *mallFile = fopen("malls.txt", "a");
    if (mallFile == NULL)
    {
        printf("Unable to open malls file.\n");
    }
    else
    {
        fprintf(mallFile, "%s %s %s\n", mall.name, mall.owner, mall.location);
        fclose(mallFile);
        printf("Mall data saved to malls.txt\n");
    }

    printf("Shopping Mall Added Successfully!\n");

}



void viewMall()
{
    printf("\n--- Shopping Mall Information ---\n");

    FILE *mallFile = fopen("malls.txt", "r");
    if (mallFile == NULL)
    {
        printf("No shopping malls available yet.\n");
        return;
    }

    char name[50], owner[50], location[50];
    int count = 0;

    while (fscanf(mallFile, "%49s %49s %49s", name, owner, location) == 3)
    {
        count++;
        printf("Mall %d:\n", count);
        printf("  Name: %s\n", name);
        printf("  Owner: %s\n", owner);
        printf("  Location: %s\n", location);
    }

    fclose(mallFile);

    if (count == 0)
    {
        printf("No shopping malls available yet.\n");
    }
}


