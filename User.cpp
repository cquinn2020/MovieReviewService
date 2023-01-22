#include "User.h"
#include "MovieReview.h"

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

void User::reviewMovie(const std::string &title, float rating)
{
    reviewedMovies[title] = rating;
}

void User::printUserDetails()
{
    std::cout << "User Name: " << this->getName() << std::endl;
    for (auto it = reviewedMovies.begin(); it != reviewedMovies.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void User::addMovieReview(MovieReview &movieReview)
{
    this->movieReviews.push_back(movieReview);
}

MovieReview *User::getMovieReview(std::string movieName)
{
    for (auto &movieReview : movieReviews)
    {
        if (movieReview.getName() == movieName)
        {
            return &movieReview;
        }
    }
    return nullptr;
}

void User::printAllMovieReviews()
{
    std::cout << this->getName() << std::endl; // authors name
    for (auto &movieReview : movieReviews)
    {
        movieReview.printReview();
    }
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

bool User::hasReviewedMovie(const std::string &title)
{
    return reviewedMovies.find(title) != reviewedMovies.end();
}
