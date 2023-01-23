#include "Movie.h"
#include "MovieReview.h"
#include "User.h"
#include "MovieCollection.h"
#include <iostream>

int main()
{
    UserManager manager;
    manager.loadUsers();
    manager.printAllUsers();
    std::string name;
    std::cout << "Please enter your name to sign in or make an account: " << std::endl;
    std::getline(std::cin, name);
    User *currentUser = manager.getUser(name);

    if (!currentUser)
    {
        std::cout << "User not found, creating new user" << std::endl;
        currentUser = new User(name);
        manager.addUser(*currentUser);
    }
    std::cout << "Welcome " << currentUser->getName() << std::endl;
    manager.setCurrentUser(currentUser);

    MovieCollection collection;
    collection.setCurrentUser(currentUser);
    collection.loadMoviesFromFile("data/movies.txt");
    collection.displayHomeScreen();

    return 0;
}