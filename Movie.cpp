#include "Movie.h"

Movie::Movie(std::string movieName,
             std::string releaseDate,
             std::string movieDescription)
{
    this->movieName = movieName;
    this->releaseDate = releaseDate;
    this->movieDescription = movieDescription;
}

std::string Movie::getMovieName() { return this->movieName; }
void Movie::setMovieName(std::string movieName) { this->movieName = movieName; }
float Movie::getMovieRating() { return this->overallRating; }
void Movie::addMovieRating(float movieRating) { this->ratings.push_back(movieRating); }
std::string Movie::getReleaseDate() { return this->releaseDate; }
void Movie::setReleaseDate(std::string releaseDate) { this->releaseDate = releaseDate; }
std::string Movie::getMovieDescription() { return this->movieDescription; }
void Movie::setMovieDescription(std::string movieDescription) { this->movieDescription = movieDescription; }