#include "MovieReview.h"

MovieReview::MovieReview(std::string reviewerName, float rating, std::string reviewText, std::string movieName)
{
    this->reviewerName = reviewerName;
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

void ::MovieReview::setReviewerName(std::string reviewerName)
{
    this->reviewerName = reviewerName;
}

std::string MovieReview::getReviewerName()
{
    return this->reviewerName;
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