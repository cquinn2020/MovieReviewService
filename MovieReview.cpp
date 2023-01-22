#include "MovieReview.h"

MovieReview::MovieReview(User *user, float rating, std::string reviewText, std::string movieName)
{
    this->user = user;
    this->rating = rating;
    this->reviewText = reviewText;
    this->movieName = movieName;
}

float MovieReview::getRating()
{
    return this->rating;
}

void MovieReview::setRating(float rating)
{
    this->rating = rating;
}

User *MovieReview::getUser()
{
    return this->user;
}

void MovieReview::setUser(User *user)
{
    this->user = user;
}

void MovieReview::setName(std::string movieName)
{
    this->movieName = movieName;
}

std::string MovieReview::getName()
{
    return this->movieName;
}

std::string MovieReview::getReviewText()
{
    return this->reviewText;
}

void MovieReview::setReviewText(std::string reviewText)
{
    this->reviewText = reviewText;
}

void MovieReview::printReview()
{
    std::cout << "Movie title: " << this->getName() << std::endl;
    std::cout << "Movie rating: " << this->getRating() << std::endl;
    std::cout << "Movie Description: " << this->getReviewText() << std::endl;
}

MovieReview::~MovieReview() {}