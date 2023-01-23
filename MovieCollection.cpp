#include "MovieCollection.h"

void MovieCollection::addMovie(Movie &newMovie)
{
    for (auto &movie : allMovies)
    {
        if (movie->getMovieName() == newMovie.getMovieName())
        {
            std::cout << "Movie already in collection" << std::endl;
            displayHomeScreen();
        }
    }
    allMovies.push_back(&newMovie);
}

void MovieCollection::removeMovie(std::string movieName)
{
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
    for (auto &movie : allMovies)
    {
        if (movie->getMovieName() == movieName)
        {
            return true;
        }
    }
    return false;
}

std::vector<Movie *> MovieCollection::getMovies()
{
    return allMovies;
}

void MovieCollection::setCurrentUser(User *user)
{
    currentUser = user;
}

void MovieCollection::loadMoviesFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string movieName;
        std::string releaseDate;
        std::string movieDescription;
        std::string movieRating;
        std::string line;
        while (std::getline(file, line))
        {
            movieName = line;
            std::getline(file, line);
            releaseDate = line;
            std::getline(file, line);
            movieDescription = line;
            std::getline(file, line);
            movieRating = line;
            float movieRankingFloat = atof(movieRating.c_str());
            Movie *movie = new Movie(movieName, releaseDate, movieDescription);
            movie->addMovieRating(movieRankingFloat);
            movie->computeOverallRating();
            allMovies.push_back(movie);
        }
    }
    file.close();
}

void MovieCollection::addMovieReview(MovieReview *movieReview)
{
    allMovieReviews.push_back(movieReview);
}

std::vector<MovieReview *> MovieCollection::getMovieReviews()
{
    return allMovieReviews;
}

void MovieCollection::printAllMovies()
{
    for (auto &movie : allMovies)
    {
        std::cout << "Title: " << movie->getMovieName() << std::endl;
        std::cout << "Release Date: " << movie->getReleaseDate() << std::endl;
        std::cout << "Description: " << movie->getMovieDescription() << std::endl;
        std::cout << "Rating: " << movie->getMovieRating() << std::endl;
        std::cout << "\n";
    }
}

void MovieCollection::displayNewMoviePage()
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Welcome to Movie Collection" << std::endl;

    std::cout << "Please enter the movie name" << std::endl;
    std::string movieName;
    std::getline(std::cin, movieName);

    if (contains(movieName))
    {
        std::cout << "Movie already in collection" << std::endl;
        displayHomeScreen();
    }

    std::cout << "Please enter the release date" << std::endl;
    std::string releaseDate;
    std::getline(std::cin, releaseDate);

    std::cout << "Please enter the movie description" << std::endl;
    std::string movieDescription;
    std::getline(std::cin, movieDescription);

    Movie *movie = new Movie(movieName, releaseDate, movieDescription);

    std::cout << "Please enter the movie rating" << std::endl;
    std::string movieRating;
    std::getline(std::cin, movieRating);
    float movieRankingFloat = atof(movieRating.c_str());

    movie->addMovieRating(movieRankingFloat);
    movie->computeOverallRating();
    addMovie(*movie);

    std::cout << "Movie added successfully" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    displayHomeScreen();
}

void MovieCollection::displayHomeScreen()
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Welcome to Movie Collection" << std::endl;
    std::cout << "This is all the movies in the collection\n"
              << std::endl;
    printAllMovies();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Please select an option" << std::endl;
    std::cout << "1. Add Movie" << std::endl;
    std::cout << "2. Remove Movie" << std::endl;
    std::cout << "3. See reviews by specific critic" << std::endl;
    std::cout << "4. Leave a review" << std::endl;
    std::cout << "5. Exit" << std::endl;

    int option;
    std::cin >> option;
    std::cin.ignore();

    switch (option)
    {
    case 1:
        displayNewMoviePage();
        break;

    case 4:
        displayAddReviewPage();
        break;
    }
}

void MovieCollection::displayAddReviewPage()
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Welcome to Movie Collection" << std::endl;

    std::cout << "Please enter the movie name of the movie you wish to review: " << std::endl;
    std::string movieName;
    std::getline(std::cin, movieName);

    if (!contains(movieName))
    {
        std::cout << "Movie not found" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        displayHomeScreen();
    }

    bool alreadyReviewed = false;
    std::vector<std::string> movieReviews = this->currentUser->getMoviesReviewed();
    for (auto &review : movieReviews)
    {
        if (review == movieName)
        {
            std::cout << "You have already reviewed this movie" << std::endl;
            std::cout << "This is your review: " << std::endl;
            std::vector<MovieReview *> movieReviews = getMovieReviews();
            for (auto &review : movieReviews)
            {
                if (review->getName() == movieName && review->getReviewerName() == currentUser->getName())
                {
                    review->printReview();
                }
            }
            alreadyReviewed = true;
        }
    }

    std::vector<MovieReview *> movieReviewObjects = getMovieReviews();
    for (auto &review : movieReviewObjects)
    {
        if (review->getName() == movieName && review->getReviewerName() != currentUser->getName())
        {
            std::cout << "--------------------------------------------" << std::endl;
            review->printReview();
        }
    }

    if (!alreadyReviewed)
    {
        std::cout << "Please enter the review" << std::endl;
        std::string review;
        std::getline(std::cin, review);

        std::cout << "Please enter the rating" << std::endl;
        std::string rating;
        std::getline(std::cin, rating);
        float ratingFloat = atof(rating.c_str());

        std::string criticName = currentUser->getName();

        MovieReview *movieReview = new MovieReview(criticName, ratingFloat, review, movieName);

        addMovieReview(movieReview);
        std::cout << "Review added successfully" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        displayHomeScreen();
    }
    else
    {
        std::cout << "1. Edit review" << std::endl;
        std::cout << "2. Go back" << std::endl;
        int option;
        std::cin >> option;
        std::cin.ignore();
        if (option == 1)
        {
            std::cout << "Please enter the review" << std::endl;
            std::string reviewText;
            std::getline(std::cin, reviewText);

            std::cout << "Please enter the rating" << std::endl;
            std::string rating;
            std::getline(std::cin, rating);
            float ratingFloat = atof(rating.c_str());

            std::string criticName = currentUser->getName();

            for (auto &review : movieReviewObjects)
            {
                if (review->getName() == movieName && review->getReviewerName() == currentUser->getName())
                {
                    review->setReviewText(reviewText);
                    review->setRating(ratingFloat);
                }
            }
            std::cout << "Review edited successfully" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
            displayHomeScreen();
        }
        else if (option == 2)
        {
            std::cout << "--------------------------------------------" << std::endl;
            displayHomeScreen();
        }
    }
}