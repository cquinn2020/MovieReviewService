#include "User.h"
#include "MovieReview.h"
#include "Movie.h"
User::User(std::string name)
{
    this->name = name;
}

std::string User::getName()
{
    return this->name;
}

void User::setName(std::string name)
{
    this->name = name;
}

void User::printUserDetails()
{
    for (auto it = reviewedMovies.begin(); it != reviewedMovies.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void User::addMovieReview(std::string movieName)
{
    moviesReviewed.push_back(movieName);
}

std::vector<std::string> User::getMoviesReviewed()
{
    return moviesReviewed;
}

User::~User()
{
    // destructor code here
}

UserManager::UserManager() {}

User *UserManager::getUser(std::string name)
{
    for (auto &user : users)
    {
        if (user.getName() == name)
        {
            return &user;
        }
    }
    return nullptr;
}

User *UserManager::getCurrentUser()
{
    return currentUser;
}

void UserManager::setCurrentUser(User *user)
{
    this->currentUser = user;
}

void UserManager::addUser(User &user)
{
    this->users.push_back(user);
}

void UserManager::loadUsers()
{
    std::ifstream file("data/users.txt");
    std::string line;
    while (std::getline(file, line))
    {
        User user(line);
        this->addUser(user);
    }
}

void UserManager::printAllUsers()
{
    for (auto &user : users)
    {
        user.printUserDetails();
    }
}