#include "Movie.h"
#include "MovieReview.h"
#include "User.h"
#include <iostream>

int main()
{
    UserManager manager;
    std::string name;
    std::cout << "Please enter a name: " << std::endl;
    std::cin >> name;
    User *currentUser = manager.getUser(name);
    if (!currentUser)
    {
        currentUser = new User(name);
        manager.addUser(*currentUser);
    }
    manager.setCurrentUser(currentUser);
    return 0;
}