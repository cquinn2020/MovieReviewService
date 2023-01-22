#ifndef USER_H
#define USER_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

class MovieReview;

class User
{
private:
    std::string name;
    std::unordered_map<std::string, float> reviewedMovies;
    std::vector<MovieReview> movieReviews;

public:
    User(std::string name);
    User();
    ~User();

    std::string getName();
    void setName(std::string);
    void reviewMovie(const std::string &title, float rating);
    void printUserDetails();
    void addMovieReview(MovieReview &movieReview);
    MovieReview *getMovieReview(std::string movieName);
    void printAllMovieReviews();
    bool hasReviewedMovie(const std::string &title);
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
};

#endif