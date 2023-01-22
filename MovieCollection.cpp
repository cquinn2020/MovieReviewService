#include "MovieCollection.h"

void MovieCollection::addMovie(Movie &movie)
{
    std::string movieName = movie.getMovieName();
    if (contains(movieName))
    {
        std::cout << "Movie already in collection" << std::endl;
        return;
    }
    else
    {
        movies[movieName] = &movie;
    }
}

void MovieCollection::removeMovie(std::string movieName)
{
    // check if movie is in the collection
    if (!contains(movieName))
    {
        std::cout << "Movie not in collection" << std::endl;
        return;
    }
    else
    {
        movies.erase(movieName);
    }
}
Movie *MovieCollection::getMovie(std::string movieName)
{
    if (!contains(movieName))
    {
        std::cout << "Movie not in collection" << std::endl;
        return nullptr;
    }
    else
    {
        return movies[movieName];
    }
}

std::vector<Movie> MovieCollection::getAllMovies()
{
    std::vector<Movie> allMovies;
    for (auto it = movies.begin(); it != movies.end(); ++it)
    {
        allMovies.push_back(*it->second);
    }
    return allMovies;
}

void MovieCollection::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (auto it = movies.begin(); it != movies.end(); ++it)
        {
            file << it->second->getMovieName() << std::endl;
            file << it->second->getReleaseDate() << std::endl;
            file << it->second->getMovieDescription() << std::endl;
            file << it->second->getMovieRating() << std::endl;
        }
    }
    file.close();
}

bool MovieCollection::contains(std::string movieName)
{
    return movies.find(movieName) != movies.end();
}

void MovieCollection::loadFromFile(const std::string &filename)
{
    // std::ifstream file(filename);
    // if (file.is_open())
    // {
    //     std::string movieName;
    //     std::string releaseDate;
    //     std::string movieDescription;
    //     float movieRating;
    //     while (std::getline(file, movieName))
    //     {
    //         std::getline(file, releaseDate);
    //         std::getline(file, movieDescription);
    //         file >> movieRating;
    //         file.ignore();
    //         Movie movie(movieName, releaseDate, movieDescription, movieRating);
    //         addMovie(movie);
    //     }
    // }
    // file.close();
}
