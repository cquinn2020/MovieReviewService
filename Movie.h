#ifndef MOVIE_H
#define MOVIE_H
#include "MovieReview.h"
#include <string>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <fstream>

class Movie
{
private:
    std::string movieName;
    float overallRating;
    std::string releaseDate;
    std::string movieDescription;
    std::vector<float> ratings;
    std::vector<MovieReview> movieReviews;

public:
    Movie(std::string movieName,
          std::string releaseDate,
          std::string movieDescription);

    ~Movie();

    std::string getMovieName();
    void setMovieName(std::string movieName);
    float getMovieRating();
    void addMovieRating(float movieRating);
    std::string getReleaseDate();
    void setReleaseDate(std::string releaseDate);
    std::string getMovieDescription();
    void setMovieDescription(std::string movieDescription);
    void computeOverallRating();
    void addMovieReview(MovieReview &movieReview);
    void deleteMovieReview(MovieReview &movieReview);
};

#endif