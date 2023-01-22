#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H
#include <unordered_map>
#include "Movie.h"

class MovieCollection
{
private:
    std::unordered_map<std::string, Movie *> movies;

public:
    void addMovie(Movie &movie);
    void removeMovie(std::string movieName);
    Movie *getMovie(std::string movieName);
    std::vector<Movie> getAllMovies();
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    bool contains(std::string movieName);
};

#endif