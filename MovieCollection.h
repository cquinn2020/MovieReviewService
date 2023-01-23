#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H
#include <unordered_map>
#include <cstdlib>
#include "User.h"
#include "Movie.h"

class MovieCollection
{
private:
    std::unordered_map<std::string, Movie *> movies;
    std::vector<Movie *> allMovies;
    std::vector<MovieReview *> allMovieReviews;
    User *currentUser;

public:
    void addMovie(Movie &movie);
    void removeMovie(std::string movieName);
    Movie *getMovie(std::string movieName);
    std::vector<Movie> getAllMovies();
    void saveToFile(const std::string &filename);
    void loadMoviesFromFile(const std::string &filename);
    bool contains(std::string movieName);
    void printAllMovies();
    std::vector<Movie *> getMovies();
    std::vector<MovieReview *> getMovieReviews();
    void addMovieReview(MovieReview *movieReview);
    void setCurrentUser(User *user);
    void displayHomeScreen();
    void displayNewMoviePage();
    void displayAddReviewPage();
};

#endif