#ifndef USER_H
#define USER_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <fstream>

class MovieReview;

class User
{
private:
    std::string name;
    std::unordered_map<std::string, float> reviewedMovies;
    std::vector<std::string> moviesReviewed;

public:
    User(std::string name);
    User();
    ~User();

    std::string getName();
    void setName(std::string);
    void printUserDetails();
    void addMovieReview(std::string movieName);
    std::vector<std::string> getMoviesReviewed();
};

class UserManager
{
private:
    std::vector<User> users;
    User *currentUser;

public:
    UserManager();
    User *getUser(std::string name);
    void addUser(User &user);
    User *getCurrentUser();
    void setCurrentUser(User *user);
    void loadUsers();
    void printAllUsers();
};

#endif